/*
 * ButtonHandler_Main.h
 *
 *  Created on: 17. 9. 2023
 *      Author: vojte
 */

#ifndef INC_BUTTONHANDLER_H_
#define INC_BUTTONHANDLER_H_

#include "ButtonHander_Types.h"
#include "GlobalDefines.h"
#include "IoHwAb_Types.h"
#include <stdbool.h>

void ButtonHandler_Init();

void ButtonHandler_MainFunction();


buttonPossition ButtonHandler_GetButtonState(IoHwAb_InputMembers member);
#endif /* INC_BUTTONHANDLER_H_ */
