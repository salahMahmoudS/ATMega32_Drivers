/*
 * main.c
 *
 *  Created on: May 25, 2019
 *      Author: salsa
 */

//This application is supposed to blink led every 0.5 seconds. every 0.5 seconds the led will light
//and next 0.5 will be turned off
#include "std_types.h"
#include "Bit_Math.h"
#include "GI_Priv.h"
#include "DIO_Int.h"
#include "Timer0_Int.h"
u16 counter =0;
void Timer_overFlow(void){
	counter++;
	if (counter ==489){
DIO_voidTogglePin(31);
		counter =0;
Timer0_WriteInTCNT0(184);
	}
}

int main(void){
GI_voidInitiazlize();
DIO_voidInitialize();
GI_voidEnableGlobalInterrupt();
TIMER_init();
TIMER_voidEnableOverFlowInterrupt();
TIMER_start();
TIMER_SetCallBack(Timer_overFlow);
while(1);
return 0;
}
