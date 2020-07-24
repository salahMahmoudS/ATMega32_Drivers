/*Master main file
 * main.c
 *
 *  Created on: May 18, 2019
 *      Author: salsa
 */

#include "std_types.h"
#include "Bit_Math.h"
#include "GI_Int.h"
#include "DIO_Int.h"
#include "LCD_Int.h"
#include "UART_init.h"
#include "avr/delay.h"


u8 data=0x00;

void UARTDataRegisterEmpty_ISR(void)
{
	//UART_voidSendInterrupt(data);
	UART_voidDisableDataEmptyInterrupt();
}
void UARTTxComplete_ISR(void)
{
DIO_voidWriteOnPin(DIO_PIN_31, DIO_HIGH);
_delay_ms(2000);
}


int main(void){
	DIO_voidInitialize();
	GI_voidInitiazlize();
	GI_voidEnableGlobalInterrupt();
	UART_voidInit();
	void voidUARTTxComplete_SetCallBack(UARTTxComplete_ISR);
	//void voidUARTRxComplete_SetCallBack(void (*RxCompleteInterrupt_ptr)(void));
	//void voidUARDataRegisterEmpty_SetCallBack(void (*DataRegisterEmptyInterrupt_ptr)(void));
	DIO_voidWriteOnPin(DIO_PIN_0, DIO_HIGH); //to enable pull up resistor
	DIO_voidWriteOnPin(DIO_PIN_1, DIO_HIGH); //to enable pull up resistor
	DIO_voidWriteOnPin(DIO_PIN_2, DIO_HIGH);
	u8 isPressedOld = DIO_u8PinState(DIO_PIN_2);
	u8 isPressedNew = DIO_u8PinState(DIO_PIN_2);
	/*DIO_Write_On_Pin(DIO_PIN_24,DIO_HIGH);
	DIO_Write_On_Pin(DIO_PIN_26,DIO_HIGH);
	DIO_Write_On_Pin(DIO_PIN_25,DIO_HIGH);
*/
	while(1)
	{
isPressedNew = DIO_u8PinState(DIO_PIN_2);
DIO_voidWriteOnPin(DIO_PIN_10, DIO_u8PinState(DIO_PIN_2));


if (DIO_u8PinState(DIO_PIN_2)== DIO_LOW&&isPressedNew !=isPressedOld)
{

	if (DIO_u8PinState(DIO_PIN_1)==0 &&DIO_u8PinState(DIO_PIN_0)==0 )
	{
		data= 0b11110000;
	}

	else if(DIO_u8PinState(DIO_PIN_1)==0&&DIO_u8PinState(DIO_PIN_0)==1)
	{
		data= 0b11110001;
	}

	else if(DIO_u8PinState(DIO_PIN_1)==1 &&DIO_u8PinState(DIO_PIN_0)==0)
	{
		data= 0b11110010;
	}

	else if(DIO_u8PinState(DIO_PIN_1)==1 && DIO_u8PinState(DIO_PIN_0)==1)
	{
		data= 0b11110011;
	}

	UART_voidSend(data);
	DIO_voidWriteOnPin(DIO_PIN_8, DIO_u8PinState(DIO_PIN_0));
	DIO_voidWriteOnPin(DIO_PIN_9, DIO_u8PinState(DIO_PIN_1));

	isPressedOld = isPressedNew;

}
else
{
isPressedOld = isPressedNew;
}

	}


}
