/*
 * IoHwAb_Main.c
 *
 *  Created on: 17. 9. 2023
 *      Author: vojte
 */
#include <IoHwAb.h>

/* Buffer where all RAW data will be stored */
static uint32_t Buffer[IoHwAb_InputSizeOf];

/* Table where we are connect all inputs. Every 10 ms will be measured. */
static const IoHwAb_DigitRefernce tableOfInputsReferences[] =
{
	{ IoHwAb_Button0, Button, GPIOA, IoHwAb_Digital },
};

static void IoHwAb_GetDigitalData();

static void IoHwAb_GetAnalogData();

/* called every 10 ms from OS */
void IoHwAb_MainFunction()
{
	Buffer[IoHwAb_Button0] = (LL_GPIO_ReadInputPort(GPIOA) & Button);
}

/* interface for other components */
uint32_t IoHwAb_GetInput(IoHwAb_InputMembers member)
{
	uint32_t retValue = 0;

	/* check if we are in the range of the buffer */
	if (member < IoHwAb_InputSizeOf)
	{
		retValue = Buffer[IoHwAb_Button0] ;
	}

	return retValue;
}

static void IoHwAb_GetDigitalData()
{

	for (uint8_t index = 0; index < (sizeof(tableOfInputsReferences) / sizeof(IoHwAb_DigitRefernce)); index++)
	{
		if (tableOfInputsReferences[index].typeOfInput == IoHwAb_Digital)
		{
			Buffer[tableOfInputsReferences[index].input] = (LL_GPIO_ReadInputPort(tableOfInputsReferences[index].portId) & tableOfInputsReferences[index].bitMask);
		}
		else
		{
			continue;
		}
	}
}

