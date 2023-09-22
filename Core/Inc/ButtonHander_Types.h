/*
 * ButtonHander_Types.h
 *
 *  Created on: 17. 9. 2023
 *      Author: vojte
 */

#ifndef INC_BUTTONHANDER_TYPES_H_
#define INC_BUTTONHANDER_TYPES_H_

#include "stdint.h"

typedef struct
{
	uint32_t prevValue;
	uint8_t debounceTime;
}debounceStuct;

typedef struct
{
	uint32_t lower;
	uint32_t upper;
	uint32_t inputMember;
}analogConfLadder;

typedef enum
{
	POS_IDLE = 0,
	POS_PRESSED,
	POS_HOLD
}buttonPossition;

#endif /* INC_BUTTONHANDER_TYPES_H_ */
