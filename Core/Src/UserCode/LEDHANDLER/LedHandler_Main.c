#include "LedHandler.h"
#include "stdint.h"
#include "main.h"
#include "stm32f0xx_ll_gpio.h"
#include "GlobalDefines.h"


#define LED_MAIN_CALL_CYCLE 10 //10ms
#define LED_DELAY_TIME 1000 //1s = 1000ms

#define LED_DELAY_TIME_MS  (uint32_t)(LED_DELAY_TIME / LED_MAIN_CALL_CYCLE)

static void LedHandler_TurnOnLED();

static void LedHandler_TurnOffLED();

void LedHandler_Init()
{

}

/* called every 10 ms */
void LedHandler_MainFunction()
{
	static uint32_t timer = 0;

	if (timer == LED_DELAY_TIME_MS)
	{
		LL_GPIO_TogglePin(GPIOA, LED_Pin);
		timer = 0;
	}

	timer++;
}

static void LedHandler_TurnOnLED()
{
	LL_GPIO_TogglePin(GPIOA, TRUE);
}

static void LedHandler_TurnOffLED()
{

}

