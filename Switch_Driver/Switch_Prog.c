/*
 * Switch_Init.h
 *
 *  Created on: May 19, 2019
 *      Author: salsa
 */



#include "std_types.h"
#include "Bit_Math.h"
#include "DIO_Int.h"
#include "Switch_Priv.h"
#include "Switch_Config.h"
#include "Switch_Init.h"

void Switch_voidInitialize(void){
	return;
}
u8 Switch_u8IsPressed(u8 Switch_number){

switch(Switch_number){
case SWITCH_0 :
#if(SWITCH_0_MODE == PULL_UP)
	if (DIO_uint8PinState(SWITCH_0_PIN) == DIO_LOW){
		return IS_PRESSED;
	}
	else {
		return IS_NOT_PRESSED;
	}

#elif (SWITCH_0_MODE == PULL_DOWN)
	if (DIO_uint8PinState(SWITCH_0_PIN) == DIO_LOW){
			return IS_NOT_PRESSED;
		}
		else {
			return IS_PRESSED;
		}
#else
#error "WRONG MODE"
#endif
break;
case SWITCH_1:
#if(SWITCH_1_MODE == PULL_UP)
	if (DIO_uint8PinState(SWITCH_1_PIN) == DIO_LOW){
		return IS_PRESSED;
	}
	else {
		return IS_NOT_PRESSED;
	}
#elif(SWITCH_1_MODE == PULL_DOWN)
	if (DIO_uint8PinState(SWITCH_1_PIN) == DIO_LOW){
			return IS_NOT_PRESSED;
		}
		else {
			return IS_PRESSED;
		}

#else
#error "WRONG MODE"
#endif
break;

}
}




