/*
 * main.c
 *
 *  Created on: May 19, 2019
 *      Author: salsa
 */
#include<stdio.h>
#include <stdlib.h>
#include "std_types.h"
#include "Bit_Math.h"
#include "DIO_Int.h"
#include "LED_Init.h"


int main(void){
DIO_voidInitialize();
	LED_voidInitialize();

	while(1)
	{
		LED_voidTurnONLED(LED_0);
		LED_voidTurnONLED(LED_1);

	}

	return 0;
}
