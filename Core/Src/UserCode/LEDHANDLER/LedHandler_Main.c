#include "LedHandler.h"
#include "IoHwAb.h"
#include "ButtonHandler.h"

#define LED_MAIN_CALL_CYCLE 10 //10ms
#define LED_DELAY_TIME 1000 //1s = 1000ms

#define LED_DELAY_TIME_MS  (uint32_t)(LED_DELAY_TIME / LED_MAIN_CALL_CYCLE)

static LED_HANDLER_STATEMACHINE states = LED_OFF;

static LedHandler_ProcessState();

void LedHandler_Init()
{

}

/* called every 10 ms */
void LedHandler_MainFunction()
{
	if (ButtonHandler_GetButtonState(IoHwAb_Button0) == POS_PRESSED)
	{
		states = LED_ON;
	}
	else
	{
		states = LED_OFF;
	}

	LedHandler_ProcessState();
}

static LedHandler_ProcessState()
{
	switch (states)
	{
		case LED_OFF:

				IoHwAb_SetPin(LED_BUILTIN, GPIOA, FALSE);

			break;

		case LED_ON:

				IoHwAb_SetPin(LED_BUILTIN, GPIOA, TRUE);

			break;

		default:

			break;
	}

}

