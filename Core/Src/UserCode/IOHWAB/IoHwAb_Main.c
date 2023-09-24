/*
 * IoHwAb_Main.c
 *
 *  Created on: 17. 9. 2023
 *      Author: vojte
 */
#include <IoHwAb.h>
#include <string.h>


/* Buffer where all RAW data will be stored */
static uint32_t Buffer[IoHwAb_InputSizeOf];

/* Table where we are connect all inputs. Every 10 ms will be measured. */
static const IoHwAb_DigitRefernce tableOfInputsReferences[] =
{
	{ IoHwAb_Button0, BUTTON_ON_OFF, GPIOA, IoHwAb_Digital },
};

static void IoHwAb_GetDigitalData();

//static void IoHwAb_GetAnalogData();

static void IoHwAb_InitTimers();

static void IoHwAb_InitPorts();

void IoHwAb_Init()
{
	memset(&Buffer,0, sizeof(Buffer));

	IoHwAb_InitPorts();
	IoHwAb_InitTimers();
}

/* called every 10 ms from OS */
void IoHwAb_MainFunction()
{
	IoHwAb_GetDigitalData();
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


static void IoHwAb_InitPorts()
{
	LL_GPIO_InitTypeDef GPIO_InitStruct;

	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);

	/* BuildIn LED initialization */
	LL_GPIO_StructInit(&GPIO_InitStruct);
	GPIO_InitStruct.Pin = LED_BUILTIN;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/* Button initialization */
	LL_GPIO_StructInit(&GPIO_InitStruct);
	GPIO_InitStruct.Pin = BUTTON_ON_OFF;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/* EXTERNAL_LED initialization */
	LL_GPIO_StructInit(&GPIO_InitStruct);
	GPIO_InitStruct.Pin = EXTERNAL_LED;
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

static void IoHwAb_InitTimers()
{
	LL_TIM_InitTypeDef TIM_Init_Struct;

	LL_AHB1_GRP1_EnableClock(LL_APB1_GRP2_PERIPH_TIM1);

	LL_TIM_StructInit(&TIM_Init_Struct);

	TIM_Init_Struct.Prescaler         = (uint16_t)0x0000;
	TIM_Init_Struct.Autoreload        = 0x5U;
	TIM_Init_Struct.CounterMode       = LL_TIM_COUNTERMODE_DOWN;

	LL_TIM_Init(TIM1, &TIM_Init_Struct);

}

void IoHwAb_SetPin(uint32_t pin, GPIO_TypeDef * port, boolean value)
{
	if (value == TRUE)
	{
		LL_GPIO_SetOutputPin(port, pin);
	}
	else
	{
		LL_GPIO_ResetOutputPin(port, pin);
	}
}

void TIM1_IRQHandler()
{
	static uint32_t count = 0;
	count++;
}

