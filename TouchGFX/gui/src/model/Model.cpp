#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "cmsis_os.h"

extern osSemaphoreId binaryUartRxMsgHandle;
extern bool statusLED[27];

Model::Model() : modelListener(0)
{
}

void Model::tick()
{
	if(binaryUartRxMsgHandle != NULL)
	{
		if(xSemaphoreTake(binaryUartRxMsgHandle, (TickType_t) 10) == pdTRUE)
		{
			modelListener->updateLEDState(statusLED);
		}
	}
}
