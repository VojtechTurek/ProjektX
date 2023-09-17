/*
 * IoHwAb_Main.c
 *
 *  Created on: 17. 9. 2023
 *      Author: vojte
 */
#include "IoHwAb_Main.h"

static uint32_t Buffer[IoHwAb_InputSizeOf];

void IoHwAb_MainFunction()
{
	Buffer[IoHwAb_Button0] = LL_GPIO_ReadInputPort(BUTTON_GPIO_Port);
}

uint32_t IoHwAb_GetInput(IoHwAb_InputMembers member)
{
	uint32_t retValue = 0;
	if (member < IoHwAb_InputSizeOf)
	{
		retValue = Buffer[IoHwAb_Button0];
	}

	return retValue;
}
