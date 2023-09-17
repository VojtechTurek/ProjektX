/*
 * ButtonHandler_Main.c
 *
 *  Created on: 17. 9. 2023
 *      Author: vojte
 */
#include "ButtonHandler_Main.h"
#include "IoHwAb_Main.h"
#include "LedHandler.h"


#define NOTYETMEASUREMENT 10

uint32_t debouncedValue = 0;

uint32_t prevDebouncedValue = 0;

uint32_t prevValue = 0;

uint32_t actualValue = 0;

uint32_t ButtonHandler_Debounce();

void ButtonHandler_MainFunction()
{
	actualValue = IoHwAb_GetInput(IoHwAb_Button0);

	if (ButtonHandler_Debounce())
	{
		if(prevDebouncedValue != debouncedValue)
		{
			LedHandler_TurnOnLED();
			prevDebouncedValue = debouncedValue;
		}
	}
}

uint32_t ButtonHandler_Debounce()
{
	static uint32_t retValue = 0;
	static uint32_t counter = 0;

	if(prevValue == actualValue)
	{
		counter++;
		if (counter == 4)
		{
			retValue = TRUE;
			debouncedValue = actualValue;
		}
	}
	else
	{
		counter = 0;
	}

	prevValue = actualValue;

	return retValue;
}
