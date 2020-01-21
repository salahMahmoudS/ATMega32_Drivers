/*
 * main.c
 *
 *  Created on: Jun 1, 2019
 *      Author: salsa
 */


#include "util/delay.h"
#include "Bit_Math.h"
#include "Std_Types.h"
#include "DIO_int.h"
#include "ADC_Int.h"
#include "LCD_int.h"

u16 static resultOld=0;
u16 static result = 0;
void ADC_ISR(void)
{
	if (result!=resultOld)
			{
				LCD_voidClearScreenReturnHomePosition();
				LCD_voidDisplayInteger(result);
				resultOld = result;
			}

}
int main(void)
{
	GI_voidInitiazlize();
	DIO_voidInitialize();
	LCD_voidInitialize();
	ADC_voidInitialize();
	GI_voidEnableGlobalInterrupt();
ADC_SetCallBack(ADC_ISR);
	//LCD_voidDisplayInteger(1000);
	//LCD_voidDisplayString("Hello world!");
	while(1)
	{
		result=ADC_u16Convert10bits();


	}
	return 0;
}
