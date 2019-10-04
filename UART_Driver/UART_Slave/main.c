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
#include "LCD_int.h"
#include "UART_init.h"

int main(void)
{
	u8 data= 0x00;
	DIO_voidInitialize();
	LCD_voidInit();
	UART_voidInit();
LCD_voidSetCursor(0,0);
LCD_voidDisplayInteger(data);
	while(1)
	{

		//DIO_voidSetPin(0);
		u8 dataNew= UART_voidReceive();
		if (dataNew !=data)
		{
		LCD_voidClearScreen();
		data=dataNew;
		LCD_voidSetCursor(0,0);
		LCD_voidDisplayInteger(data);
		}
		/**/
	}
	return 0;
}
