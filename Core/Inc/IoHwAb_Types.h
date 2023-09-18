/*
 * IoHwAb_Types.h
 *
 *  Created on: 17. 9. 2023
 *      Author: vojte
 */

#ifndef INC_IOHWAB_TYPES_H_
#define INC_IOHWAB_TYPES_H_

#include "stdint.h"

typedef enum
{
	IoHwAb_Button0,
	IoHwAb_Button1,
	IoHwAb_InputSizeOf,
} IoHwAb_InputMembers;

typedef enum
{
	IoHwAb_Digital,
	IoHwAb_Analog
} IoHwAb_InputType;

typedef struct
{
	IoHwAb_InputMembers input;
	uint32_t bitMask;
	uint32_t portId;
	IoHwAb_InputType typeOfInput;
} IoHwAb_DigitRefernce;


#endif /* INC_IOHWAB_TYPES_H_ */
