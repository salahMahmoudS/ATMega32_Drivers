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
	if (DIO_u8PinState(DIO_PIN_26)== DIO_HIGH){
		DIO_voidWriteOnPin(DIO_PIN_30,DIO_HIGH);
	}
	else if (DIO_u8PinState(DIO_PIN_26) == DIO_LOW){
		DIO_voidWriteOnPin(DIO_PIN_30,DIO_LOW);
	}


}


int main(void){

	DIO_voidInitialize();
	GI_voidEnableGlobalInterrupt();
	 ExtI_voidInitialize();
	DIO_voidWriteOnPin(DIO_PIN_24,DIO_HIGH);
	 ExtI_voidSetCallBack(ExtI_voidISR);
	 ExtI_voidEnableExtI0();

	 while (1);
}
