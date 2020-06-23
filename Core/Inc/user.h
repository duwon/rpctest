#ifndef CONTROL_MESSAGE_H__
#define CONTROL_MESSAGE_H__ 1

#include "main.h"
#include <stdbool.h>
/* Message Define -------------------------------*/
#define FIRMWARE_VSERSION           "1.1"
#define UART_BUFFER_SIZE                     400U	/* 통신 버퍼 최대 크기 */
#define MESSAGE_MAX_SIZE                   50U  /* 메시지 최대 크기 */

typedef struct
{
  uint16_t in;
  uint16_t out;
  uint16_t count;
  uint8_t buff[UART_BUFFER_SIZE];
  uint8_t rxCh;
  uint8_t buffCh;
} uartFIFO_TypeDef; /* 수신 패킷 저장 버퍼 구조체 */

typedef enum
{
  S_START = 0,
  S_ID,
  S_COMMAND,
  S_LENGTH,
  S_DATA,
  S_CHECKSUM,
  S_END,
  S_PARSING
} MessageStage;

typedef struct
{
    MessageStage nextStage;
    uint8_t command;
    uint16_t length;
    uint16_t cntData;
    uint8_t checksum;
    uint8_t data[MESSAGE_MAX_SIZE];
    void (*parsing)(void);
} message_TypeDef; /* 수신 메시지 구조체 */

void user_start(void);
void user_while(void);

#endif
