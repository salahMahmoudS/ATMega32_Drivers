/*
 * main.c
 *
 *  Created on: May 23, 2019
 *      Author: salsa
 */

#include "std_types.h"
#include "Bit_Math.h"
#include "util/delay.h"
#include "DIO_Int.h"
#include "GI_Int.h"
#include "ExtI_Int.h"

u8 is_pressed=0;
void ExtI_voidISR(void){
	if (DIO_uint8PinState(26)== DIO_HIGH){
		DIO_voidSetPin(30);
	}
	else if (DIO_uint8PinState(26) == DIO_LOW){
		DIO_voidClearPin(30);
	}


}


int main(void){

	DIO_voidInitialize();
	GI_voidEnableGlobalInterrupt();
	 ExtI_voidInitialize();
	DIO_voidSetPin(24);
	 ExtI_voidSetCallBack(ExtI_voidISR);
	 ExtI_voidEnableExtI0();

	 while (1);
}
