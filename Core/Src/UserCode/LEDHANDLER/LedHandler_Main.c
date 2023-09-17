#include "LedHandler.h"

#define LED_MAIN_CALL_CYCLE 10 //10ms
#define LED_DELAY_TIME 1000 //1s = 1000ms

#define LED_DELAY_TIME_MS  (uint32_t)(LED_DELAY_TIME / LED_MAIN_CALL_CYCLE)

void LedHandler_Init()
{

}

/* called every 10 ms */
void LedHandler_MainFunction()
{/*
	static uint32_t timer = 0;

	if (timer == LED_DELAY_TIME_MS)
	{
		LL_GPIO_TogglePin(GPIOA, LED_Pin);
		timer = 0;
	}

	timer++;*/
}

void LedHandler_TurnOnLED()
{
	LL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

void LedHandler_TurnOffLED()
{
	LL_GPIO_WriteOutputPort(LED_GPIO_Port, FALSE);
}

