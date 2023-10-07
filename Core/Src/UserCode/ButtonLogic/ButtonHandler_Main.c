/*
 * ButtonHandler_Main.c
 *
 *  Created on: 17. 9. 2023
 *      Author: vojte
 */
#include <ButtonHandler.h>
#include <IoHwAb.h>
#include "LedHandler.h"
#include <string.h>

#define CALLTIME 10u

#define DEBOUNCE_MS 40u
#define HOLD_TIME_MS 250u

#define DEBOUNCE_TIMER DEBOUNCE_MS / CALLTIME
#define HOLD_TIMER HOLD_TIME_MS / CALLTIME

static buttonPossition buttonsPosition[IoHwAb_InputSizeOf];

static bool ButtonHandler_Debounce(debounceStuct* data, uint32_t actualValue);

static void ButtonHandler_CheckHold();

void ButtonHandler_Init()
{
	/* set buttons to idle position */
	memset(&buttonsPosition, POS_IDLE, sizeof(buttonsPosition));
}

void ButtonHandler_MainFunction()
{
	static debounceStuct buttons = {0};

	static uint32_t value = 0;

	value = IoHwAb_GetInput(IoHwAb_Button0);

	/* is the value debounced */
	if (ButtonHandler_Debounce(&buttons, value))
	{
		if (value == 0)
		{
			buttonsPosition[IoHwAb_Button0] = POS_PRESSED;
			//ButtonHandler_CheckHold();
		}
		else
		{
			buttonsPosition[IoHwAb_Button0] = POS_IDLE;
		}
	}
}

static bool ButtonHandler_Debounce(debounceStuct* data, uint32_t actualValue)
{
	bool retValue = false;

	/* values are the same check if the timer for debounce was passed */
	if (data->prevValue == actualValue)
	{
		/* not yet debounced */
		if (data->debounceTime < DEBOUNCE_TIMER)
		{
			data->debounceTime--;
			retValue = false;

		}
		else
		{
			retValue = true;
		}
	}
	else
	{
		/* values are different, reset debounce counter */
		data->debounceTime = DEBOUNCE_TIMER;
		retValue = false;
	}

	data->prevValue = actualValue;

	return retValue;
}

static void ButtonHandler_CheckHold()
{
	static uint32_t holdtime = 0;

	if (buttonsPosition[IoHwAb_Button0] == POS_PRESSED)
	{
		if (holdtime < HOLD_TIMER)
		{
			holdtime++;
		}
		else
		{
			buttonsPosition[IoHwAb_Button0] = POS_HOLD;
		}
	}
	else
	{
		holdtime = 0;
	}
}

buttonPossition ButtonHandler_GetButtonState(IoHwAb_InputMembers member)
{
	return buttonsPosition[member];
}
