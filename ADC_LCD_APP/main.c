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

int main(void)
{
	DIO_voidInitialize();
	LCD_voidInitialize();
	ADC_voidInitialize();

	//LCD_voidDisplayInteger(1000);
u16 resultOld=0;
	while(1)
	{
		u16 result=ADC_u16Convert10bits();
		if (result!=resultOld)
		{
			LCD_voidClearScreenReturnHomePosition();
			LCD_voidDisplayInteger(result);
			resultOld = result;
		}


	}
	return 0;
}
