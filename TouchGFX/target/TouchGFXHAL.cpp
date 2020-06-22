/**
  ******************************************************************************
  * File Name          : TouchGFXHAL.cpp
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
#include <TouchGFXHAL.hpp>

/* USER CODE BEGIN TouchGFXHAL.cpp */

#include "stm32f7xx_hal.h"
#include <touchgfx/hal/OSWrappers.hpp>
#include "main.h"

/* USER CODE BEGIN Includes */
#include <CortexMMCUInstrumentation.hpp>
#include <touchgfx/hal/GPIO.hpp>
#include "FreeRTOS.h"
#include "task.h"
/* USER CODE END Includes */

/* USER CODE BEGIN private defines */

/* USER CODE END private defines */

/* USER CODE BEGIN private variables */

/* USER CODE END private variables */

/* USER CODE BEGIN private functions */
static portBASE_TYPE IdleTaskHook(void* p)
{
    if ((int)p) //idle task sched out
    {
        touchgfx::HAL::getInstance()->setMCUActive(true);
    }
    else //idle task sched in
    {
        touchgfx::HAL::getInstance()->setMCUActive(false);
    }
    return pdTRUE;
}
/* USER CODE END private functions */

/* USER CODE BEGIN extern C prototypes */

/* USER CODE END extern C prototypes */

using namespace touchgfx;

/* USER CODE BEGIN private class objects */
static CortexMMCUInstrumentation mcuInstr;
/* USER CODE END private class objects */

TouchGFXHAL::TouchGFXHAL(touchgfx::DMA_Interface& dma, touchgfx::LCD& display, touchgfx::TouchController& tc, uint16_t width, uint16_t height)
/* USER CODE BEGIN TouchGFXHAL Constructor */
    : TouchGFXGeneratedHAL(dma, display, tc, width, height)
      /* USER CODE END TouchGFXHAL Constructor */
{
    /* USER CODE BEGIN TouchGFXHAL Constructor Code */

    /* USER CODE END TouchGFXHAL Constructor Code */
}

void TouchGFXHAL::initialize()
{
    /* USER CODE BEGIN initialize step 1 */
    GPIO::init();
    /* USER CODE END initialize step 1 */

    // Calling parent implementation of initialize().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
    // Please note, HAL::initialize() must be called to initialize the framework.

    TouchGFXGeneratedHAL::initialize();

    /* USER CODE BEGIN initialize step 2 */
    mcuInstr.init();

    //Set MCU instrumentation and Load calculation
    setMCUInstrumentation(&mcuInstr);
    enableMCULoadCalculation(true);
    /* USER CODE END initialize step 2 */
}

void TouchGFXHAL::taskEntry()
{
    /* USER CODE BEGIN taskEntry step 1 */

    /* USER CODE END taskEntry step 1 */

    enableLCDControllerInterrupt();
    enableInterrupts();

    OSWrappers::waitForVSync();
    backPorchExited();

#if defined(LCD_DISP_GPIO_Port) && defined(LCD_DISP_Pin)
    /* Display Enable */
    HAL_GPIO_TogglePin(LCD_DISP_GPIO_Port, LCD_DISP_Pin);
#endif
#if defined(LCD_RESET_GPIO_Port) && defined(LCD_RESET_Pin)
    /* Display Enable */
    HAL_GPIO_TogglePin(LCD_RESET_GPIO_Port, LCD_RESET_Pin);
#endif
#if defined(LCD_DE_GPIO_Port) && defined(LCD_DE_Pin)
    /* Data Enable */
    HAL_GPIO_TogglePin(LCD_DE_GPIO_Port, LCD_DE_Pin);
#endif
#if defined(LCD_BL_CTRL_GPIO_Port) && defined(LCD_BL_CTRL_Pin)
    /* Backlight Enable */
    HAL_GPIO_TogglePin(LCD_BL_CTRL_GPIO_Port, LCD_BL_CTRL_Pin);
#endif

    /* USER CODE BEGIN taskEntry step 2 */

    /* USER CODE END taskEntry step 2 */

    for (;;)
    {
        OSWrappers::waitForVSync();
        backPorchExited();
    }
}

/**
 * Gets the frame buffer address used by the TFT controller.
 *
 * @return The address of the frame buffer currently being displayed on the TFT.
 */
uint16_t* TouchGFXHAL::getTFTFrameBuffer() const
{
    // Calling parent implementation of getTFTFrameBuffer().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    /* USER CODE BEGIN getTFTFrameBuffer */
    return TouchGFXGeneratedHAL::getTFTFrameBuffer();
    /* USER CODE END getTFTFrameBuffer */
}

/**
 * Sets the frame buffer address used by the TFT controller.
 *
 * @param [in] address New frame buffer address.
 */
void TouchGFXHAL::setTFTFrameBuffer(uint16_t* address)
{
    // Calling parent implementation of setTFTFrameBuffer(uint16_t* address).
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    /* USER CODE BEGIN setTFTFrameBuffer */
    TouchGFXGeneratedHAL::setTFTFrameBuffer(address);
    /* USER CODE END setTFTFrameBuffer */
}

/**
 * This function is called whenever the framework has performed a partial draw.
 *
 * @param rect The area of the screen that has been drawn, expressed in absolute coordinates.
 *
 * @see flushFrameBuffer().
 */
void TouchGFXHAL::flushFrameBuffer(const touchgfx::Rect& rect)
{
    // Calling parent implementation of flushFrameBuffer(const touchgfx::Rect& rect).
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
    // Please note, HAL::flushFrameBuffer(const touchgfx::Rect& rect) must
    // be called to notify the touchgfx framework that flush has been performed.

    /* USER CODE BEGIN flushFrameBuffer step 1 */
    TouchGFXGeneratedHAL::flushFrameBuffer(rect);
    /* USER CODE END flushFrameBuffer step 1 */

    /* USER CODE BEGIN flushFrameBuffer step 2 */
    // If the framebuffer is placed in Write Through cached memory (e.g. SRAM) then we need
    // to flush the Dcache to make sure framebuffer is correct in RAM. That's done
    // using SCB_CleanInvalidateDCache().

    SCB_CleanInvalidateDCache();
    /* USER CODE END flushFrameBuffer step 2 */
}

/**
 * Configures the interrupts relevant for TouchGFX. This primarily entails setting
 * the interrupt priorities for the DMA and LCD interrupts.
 */
void TouchGFXHAL::configureInterrupts()
{
    // Calling parent implementation of configureInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    /* USER CODE BEGIN configureInterrupts */
    TouchGFXGeneratedHAL::configureInterrupts();
    /* USER CODE END configureInterrupts */
}

/**
 * Used for enabling interrupts set in configureInterrupts()
 */
void TouchGFXHAL::enableInterrupts()
{
    // Calling parent implementation of enableInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    /* USER CODE BEGIN enableInterrupts */
    TouchGFXGeneratedHAL::enableInterrupts();
    /* USER CODE END enableInterrupts */
}

/**
 * Used for disabling interrupts set in configureInterrupts()
 */
void TouchGFXHAL::disableInterrupts()
{
    // Calling parent implementation of disableInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    /* USER CODE BEGIN disableInterrupts */
    TouchGFXGeneratedHAL::disableInterrupts();
    /* USER CODE END disableInterrupts */
}

/**
 * Configure the LCD controller to fire interrupts at VSYNC. Called automatically
 * once TouchGFX initialization has completed.
 */
void TouchGFXHAL::enableLCDControllerInterrupt()
{
    // Calling parent implementation of enableLCDControllerInterrupt().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

    /* USER CODE BEGIN enableLCDControllerInterrupt */
    TouchGFXGeneratedHAL::enableLCDControllerInterrupt();
    /* USER CODE END enableLCDControllerInterrupt */
}

/* USER CODE BEGIN virtual overloaded methods */

/* USER CODE END virtual overloaded methods */

/* USER CODE BEGIN extern C functions */
// FreeRTOS specific handlers
extern "C"
{
    void vApplicationIdleHook(void)
    {
        // Set task tag in order to have the "IdleTaskHook" function called when the idle task is
        // switched in/out. Used solely for measuring MCU load, and can be removed if MCU load
        // readout is not needed.
        vTaskSetApplicationTaskTag(NULL, IdleTaskHook);
    }
}
/* USER CODE END extern C functions */

/* USER CODE END TouchGFXHAL.cpp */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
