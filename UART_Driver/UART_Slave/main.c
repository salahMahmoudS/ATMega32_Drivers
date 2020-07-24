/*slave main file
 * main.c
 *
 *  Created on: Jun 1, 2019
 *      Author: salsa
 */


#include "util/delay.h"
#include "Bit_Math.h"
#include "Std_Types.h"
#include "DIO_int.h"
#include "GI_Int.h"
#include "LCD_int.h"
#include "UART_init.h"

void UARTRxComplete_ISR(void)
{
	u8 data= UART_voidReceive();
	DIO_voidWriteOnPort('C', data);
	LCD_voidClearScreenReturnHomePosition();
	LCD_voidSetCursor(0,0);
	LCD_voidDisplayInteger(data);
}


int main(void)
{
	u8 data= 0x00;

	DIO_voidInitialize();
	GI_voidInitiazlize();
	GI_voidEnableGlobalInterrupt();
	LCD_voidInitialize();
	UART_voidInit();
	voidUARTRxComplete_SetCallBack(UARTRxComplete_ISR);
	LCD_voidSetCursor(0,0);
	LCD_voidDisplayInteger(data);



//void voidUARTRxComplete_SetCallBack(UARTRxComplete_ISR);



	while(1)
	{
		/*
		u8 data= UART_voidReceive();
			LCD_voidClearScreenReturnHomePosition();
			LCD_voidSetCursor(0,0);
			LCD_voidDisplayInteger(data);
		 */

	}
		/**/

	return 0;
}
