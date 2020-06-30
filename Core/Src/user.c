#include <stdbool.h>
#include <string.h>
#include "user.h"
#include "cmsis_os.h"

uartFIFO_TypeDef rxBufferUart1; /* Debug Port */
uartFIFO_TypeDef rxBufferUart6; /* RS-422 Port */
uartFIFO_TypeDef rxBufferUart7; /* Raspberry Pi Port */
message_TypeDef rxMsgFrame1;
message_TypeDef rxMsgFrame6;
message_TypeDef rxMsgFrame7;

bool statusLED[27] = {0,};
int controlSceinario = 0;

extern UART_HandleTypeDef huart7;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart6;

extern osSemaphoreId binaryUartRxMsgHandle;

static void initBuffer(volatile uartFIFO_TypeDef *buffer);
static void putByteToBuffer(volatile uartFIFO_TypeDef *buffer, uint8_t ch);
static ErrorStatus getByteFromBuffer(volatile uartFIFO_TypeDef *buffer, uint8_t *ch);


static void initBuffer(volatile uartFIFO_TypeDef *buffer)
{
/**
UART 수신 버퍼를 초기화
**/    
  buffer->count = 0;/* 버퍼에 저장된 데이터 갯수 초기화 */
  buffer->in = 0;   /* 버퍼 시작 인덱스 초기화*/
  buffer->out = 0;  /* 버퍼 끝 인덱스 초기화 */
}

static void putByteToBuffer(volatile uartFIFO_TypeDef *buffer, uint8_t ch)
{
/**
1. 데이터가 버퍼에 가득 찬 경우 
  1.1 ERROR 리턴. 종료
2. 버퍼에 1byte 저장 후 버퍼의 저장된 데이터 개수 1 증가
3. 버퍼의 시작 인덱스가 버퍼크기보다 큰 경우
  3.1 시작 인덱스를 0부터 다시 시작
4. SUCCESS 리턴
**/

  if (buffer->count != UART_BUFFER_SIZE) /* 데이터가 버퍼에 가득 찼으면 ERROR 리턴 */
  {
    buffer->buff[buffer->in] = ch;    /* 버퍼에 1Byte 저장 */
    buffer->in++;
    buffer->count++;                    /* 버퍼에 저장된 갯수 1 증가 */
    if (buffer->in == UART_BUFFER_SIZE) /* 시작 인덱스가 버퍼의 끝이면 */
    {
      buffer->in = 0U; /* 시작 인덱스를 0부터 다시 시작 */
    }
  }
}

static ErrorStatus getByteFromBuffer(volatile uartFIFO_TypeDef *buffer, uint8_t *ch)
{
  /**
1. 버퍼에 데이터가 없는 경우
  1.1 ERROR 리턴. 종료
2. 버퍼에서 1byte 읽은 후 버퍼의 저장된 데이터 개수 1 감소
3. 버퍼의 끝 인덱스가 버퍼크기보다 큰 경우
  3.1 끝 인덱스를 0부터 다시 시작
4. SUCCESS 리턴
**/
  ErrorStatus error;
  if (buffer->count != 0U) /* 버퍼에 데이터가 있으면 */
  {
    *ch = buffer->buff[buffer->out]; /* 버퍼에서 1Byte 읽음 */
    buffer->buff[buffer->out] = 0;
    buffer->out++;
    buffer->count--;                     /* 버퍼에 저장된 데이터 갯수 1 감소 */
    if (buffer->out == UART_BUFFER_SIZE) /* 끝 인덱스가 버퍼의 끝이면 */
    {
      buffer->out = 0U; /* 끝 인덱스를 0부터 다시 시작 */
    }
    error = SUCCESS;
  }
  else
  {
    error = ERROR;
  }
  return error;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART6)
	{
		putByteToBuffer(&rxBufferUart6, rxBufferUart6.rxCh);
		HAL_UART_Receive_DMA(huart, &rxBufferUart6.rxCh, 1);
	}
	else if(huart->Instance == UART7)
	{
		putByteToBuffer(&rxBufferUart7, rxBufferUart7.rxCh);
		HAL_UART_Receive_DMA(huart, &rxBufferUart7.rxCh, 1);
	}
	else if(huart->Instance == USART1)
	{
		putByteToBuffer(&rxBufferUart1, rxBufferUart1.rxCh);
		HAL_UART_Receive_DMA(huart, &rxBufferUart1.rxCh, 1);
	}
}

static void procPacketAnalysis(message_TypeDef *messageFrame, volatile uartFIFO_TypeDef *buffer)
{
  uint8_t checksum = 0;
  while ((getByteFromBuffer(buffer, (uint8_t *)&buffer->buffCh) == SUCCESS) || (messageFrame->nextStage == S_PARSING))
  {
		HAL_UART_Transmit(&huart1, (uint8_t *)&buffer->buffCh, 1, 0xFFFF);
    switch (messageFrame->nextStage)
    {
    case S_START:
      if (buffer->buffCh == 0x30)
      {
        messageFrame->nextStage = S_ID;
        messageFrame->cntData = 0;
        messageFrame->data[0] = buffer->buffCh;
      }
      break;

    case S_ID:
      if (buffer->buffCh == 0x31)
      {
        messageFrame->data[1] = buffer->buffCh;
        messageFrame->nextStage = S_COMMAND;
      }
      else
      {
        messageFrame->nextStage = S_START;
      }
      break;

    case S_COMMAND:
      messageFrame->command = buffer->buffCh;
      messageFrame->data[2] = buffer->buffCh;
      messageFrame->nextStage = S_LENGTH;
      break;

    case S_LENGTH:
      messageFrame->length = buffer->buffCh;
      messageFrame->data[3] = buffer->buffCh;

      if (messageFrame->length == 6)
      {
        messageFrame->nextStage = S_CHECKSUM;
      }
      else
      {
        messageFrame->nextStage = S_DATA;
      }
      break;

    case S_DATA:
      messageFrame->data[messageFrame->cntData + 4] = buffer->buffCh;
      messageFrame->cntData++;
      if (messageFrame->cntData == (messageFrame->length - 6))
      {
        messageFrame->nextStage = S_CHECKSUM;
      }
      break;

    case S_CHECKSUM:
      messageFrame->checksum = buffer->buffCh;
      checksum = 0;
      for (int i = 2; i < (messageFrame->length - 2); i++)
      {
        checksum ^= messageFrame->data[i];
      }

      if (messageFrame->checksum == checksum)
      {
        messageFrame->nextStage = S_END;
      }
      else
      {
        messageFrame->nextStage = S_START;
      }
      messageFrame->nextStage = S_END; //임시 테스트용, 체크섬 확인 안함
      break;

    case S_END:
      if (buffer->buffCh == 0x32)
      {
        initBuffer(buffer);
        messageFrame->nextStage = S_PARSING;
      }
      else
      {
        messageFrame->nextStage = S_START;
      }
      break;

    case S_PARSING:
      messageFrame->parsing();
      messageFrame->nextStage = S_START;
      break;

    default:
      break;
    }
  }
}

void parsingDefault(message_TypeDef *rxMsgFrame)
{
  uint32_t tmpStatusLED;
  switch (rxMsgFrame->command)
  {
  case 0xA0:
    if (rxMsgFrame->data[4] < 27)
    {
      statusLED[rxMsgFrame->data[4]] = (bool)rxMsgFrame->data[5];
    }
    xSemaphoreGive(binaryUartRxMsgHandle);
    break;

  case 0xB0:
    tmpStatusLED = (uint32_t)rxMsgFrame->data[4] + ((uint32_t)rxMsgFrame->data[5] << 8) + ((uint32_t)rxMsgFrame->data[6] << 16) + ((uint32_t)rxMsgFrame->data[7] << 24);
    for (int i = 0; i < 27; i++)
    {
      if (((tmpStatusLED >> i) & 0x01) == 0x01)
      {
        statusLED[i] = true;
      }
      else
      {
        statusLED[i] = false;
      }
    }
    xSemaphoreGive(binaryUartRxMsgHandle);
    break;

  case 0xC0:
    for (int i = 0; i < 27; i++)
    {
      statusLED[i] = false;
    }
    xSemaphoreGive(binaryUartRxMsgHandle);
    break;

  case 0xC1:
    for (int i = 0; i < 27; i++)
    {
      statusLED[i] = true;
    }
    xSemaphoreGive(binaryUartRxMsgHandle);
    break;

  default:
    break;
  }
  
}

void parsingRxMsg1(void) /* 디버그 포트 */
{
  uint32_t tmpStatusLED;
  switch (rxMsgFrame1.command)
  {
  case 0x00:
    tmpStatusLED = (uint32_t)rxMsgFrame1.data[4] + ((uint32_t)rxMsgFrame1.data[5] << 8) + ((uint32_t)rxMsgFrame1.data[6] << 16) + ((uint32_t)rxMsgFrame1.data[7] << 24);
    for (int i = 0; i < 27; i++)
    {
      if (((tmpStatusLED >> i) & 0x01) == 0x01)
      {
        statusLED[i] = true;
      }
      else
      {
        statusLED[i] = false;
      }
    }
    xSemaphoreGive(binaryUartRxMsgHandle);
    break;

  default:
    parsingDefault(&rxMsgFrame1);
    break;
  }
}

void parsingRxMsg6(void) /* FPGA 연결 포트 */
{
  uint32_t tmpStatusLED;
  switch (rxMsgFrame6.command)
  {
  case 0x00:
    tmpStatusLED = (uint32_t)rxMsgFrame6.data[4] + ((uint32_t)rxMsgFrame6.data[5] << 8) + ((uint32_t)rxMsgFrame6.data[6] << 16);
    for (int i = 0; i < 23; i++)
    {
      if (((tmpStatusLED >> i) & 0x01) == 0x01)
      {
        statusLED[i] = true;
      }
      else
      {
        statusLED[i] = false;
      }
    }
    xSemaphoreGive(binaryUartRxMsgHandle);
    break;

  default:
    parsingDefault(&rxMsgFrame6);
    break;
  }
}

void parsingRxMsg7(void) /* 라즈베리파이 연결 포트 */
{
  uint32_t tmpStatusLED;
  switch (rxMsgFrame7.command)
  {
  case 0x01:
    tmpStatusLED = (uint32_t)rxMsgFrame7.data[4];
    for (int i = 0; i < 4; i++)
    {
      if (((tmpStatusLED >> i) & 0x01) == 0x01)
      {
        statusLED[i + 23] = true;
      }
      else
      {
        statusLED[i + 23] = false;
      }
    }
    xSemaphoreGive(binaryUartRxMsgHandle);
    break;
  default:
    parsingDefault(&rxMsgFrame7);
    break;
  }
}

void user_start(void)
{
  initBuffer(&rxBufferUart1);
  initBuffer(&rxBufferUart6);
  initBuffer(&rxBufferUart7);
  HAL_UART_Receive_DMA(&huart1, &rxBufferUart1.rxCh, 1);
  HAL_UART_Receive_DMA(&huart6, &rxBufferUart6.rxCh, 1);
  HAL_UART_Receive_DMA(&huart7, &rxBufferUart7.rxCh, 1);
  rxMsgFrame1.parsing = parsingRxMsg1;
  rxMsgFrame6.parsing = parsingRxMsg6;
  rxMsgFrame7.parsing = parsingRxMsg7;
}

void user_while(void)
{
  procPacketAnalysis(&rxMsgFrame1, &rxBufferUart1);
  procPacketAnalysis(&rxMsgFrame6, &rxBufferUart6);
  procPacketAnalysis(&rxMsgFrame7, &rxBufferUart7);

  char tmpCtrlBtn;
  switch (controlSceinario)
  {
  case 1:
    HAL_UART_Transmit(&huart1, (uint8_t *)&"CTL01", 5, 0xFFFF);
    break;
  default:
    if (controlSceinario != 0)
    {
      tmpCtrlBtn = controlSceinario + 0x30;
      HAL_UART_Transmit(&huart1, (uint8_t *)&tmpCtrlBtn, 1, 0xFFFF);
    }
    break;
  }
  controlSceinario = 0;
}
