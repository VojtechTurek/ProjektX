#include "LedHandler.h"
#include "stdint.h"
#include "stm32f0xx_ll_gpio.h"
#include "stm32f0xx_hal.h"
#include "stm32f030x6.h"

#include "../GlobalDefines.h"

#define LED_DELAY_TIME 1000 //1s = 1000ms

static uint32_t timeMS;
static uint32_t prevTimeMS;

static uint8_t ledSwapFlag = FALSE;

static void LedHandler_TurnOnLED();

static void LedHandler_TurnOffLED();

void LedHandler_Init()
{
	timeMS = 0;
	prevTimeMS = 0;
}

void LedHandler_MainFunction()
{
	/* get time in ms */
	timeMS = HAL_GetTick();

	/* delay 1 s */
	if (timeMS > LED_DELAY_TIME + prevTimeMS)
	{
		if (ledSwapFlag == TRUE)
		{
			LedHandler_TurnOffLED();
			ledSwapFlag = FALSE;
		}
		else
		{
			LedHandler_TurnOnLED();
			ledSwapFlag = TRUE;
		}
		prevTimeMS = HAL_GetTick();
	}
}

static void LedHandler_TurnOnLED()
{
	LL_GPIO_TogglePin(GPIOA, TRUE);
}

static void LedHandler_TurnOffLED()
{
	LL_GPIO_TogglePin(GPIOA, FALSE);
}

