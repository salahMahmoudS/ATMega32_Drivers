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
	LCD_voidInit();
	LCD_voidSetCursor(0,0);
	LCD_voidDisplayString("EHH BA2A");

	while(1);
	return 0;
}
