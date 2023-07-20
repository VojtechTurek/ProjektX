#include "LedHandler.h"
#include "stdint.h"
#include "stm32f0xx_ll_gpio.h"
#include "stm32f0xx_hal.h"
#include "stm32f030x6.h"
#include "main.h"

#include "../GlobalDefines.h"

#define LED_DELAY_TIME 1000 //1s = 1000ms

static uint32_t timeMS;
static uint32_t prevTimeMS;

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

		prevTimeMS = HAL_GetTick();

		LL_GPIO_TogglePin(GPIOA, LED_Pin);
	}
}

static void LedHandler_TurnOnLED()
{
	LL_GPIO_TogglePin(GPIOA, TRUE);
}

static void LedHandler_TurnOffLED()
{

}

