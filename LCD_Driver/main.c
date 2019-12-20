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

int main(void)
{
	DIO_voidInitialize();
	LCD_voidInitialize();
	LCD_voidSetCursor(0,0);
	LCD_voidDisplayString("Hello World!!");


	while(1)
	{
//LCD_voidSendCommand(LCD_COMMAND_SHIFT_DISPLAY_RIGHT);
//_delay_ms(150);
	}
	return 0;
}
