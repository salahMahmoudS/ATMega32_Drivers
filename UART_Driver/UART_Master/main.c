/*
 * main.c
 *
 *  Created on: May 18, 2019
 *      Author: salsa
 */

#include "std_types.h"
#include "Bit_Math.h"
#include "DIO_Int.h"
#include "UART_init.h"

int main(void){
	DIO_void_Initialize();
	UART_voidInit();
	DIO_void_Set_Pin(0); //to enable pull up resistor
	DIO_void_Set_Pin(1); //to enable pull up resistor
	u8 data;
	/*DIO_Write_On_Pin(DIO_PIN_24,DIO_HIGH);
	DIO_Write_On_Pin(DIO_PIN_26,DIO_HIGH);
	DIO_Write_On_Pin(DIO_PIN_25,DIO_HIGH);
*/
	while(1)
	{

if (DIO_u8_Pin_State(DIO_PIN_1)==0 &&DIO_u8_Pin_State(DIO_PIN_0)==0 )
{
	data= 0b00000011;
}

else if(DIO_u8_Pin_State(DIO_PIN_1)==0&&DIO_u8_Pin_State(DIO_PIN_0)==1)
{
	data= 0b00000010;
}

else if(DIO_u8_Pin_State(DIO_PIN_1)==1 &&DIO_u8_Pin_State(DIO_PIN_0)==0)
{
	data= 0b00000001;
}

else if(DIO_u8_Pin_State(DIO_PIN_1)==1 && DIO_u8_Pin_State(DIO_PIN_0)==1)
{
	data= 0b00000000;
}

UART_voidSend(data);
	}


}