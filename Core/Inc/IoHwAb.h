/*
 * IoHwAb_Main.h
 *
 *  Created on: 17. 9. 2023
 *      Author: vojte
 */

#ifndef INC_IOHWAB_H_
#define INC_IOHWAB_H_

#include "stdint.h"
#include "main.h"
#include "stm32f0xx_ll_gpio.h"
#include "IoHwAb_Types.h"
#include "GlobalDefines.h"

void IoHwAb_MainFunction();

uint32_t IoHwAb_GetInput(IoHwAb_InputMembers member);


#endif /* INC_IOHWAB_H_ */
