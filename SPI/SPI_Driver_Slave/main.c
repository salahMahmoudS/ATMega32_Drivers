/*
 * main.c
 *
 *  Created on: Oct 5, 2019
 *      Author: salsa
 */

#include "std_types.h"
#include "Bit_Math.h"
#include "DIO_Int.h"
#include "SPI_Int.h"

#define PRESSED_PULL_UP 0
#define RELEASED_PULL_UP 1
#define ENABLE_INITIAL_PRESS 0
u8 SWITCH_OLD_status;
u8 data=0x00;

int main(void)
{

DIO_voidInitialize(); //Initialization for I/O pins
SPI_voidInitialize(); //Initialize SPI mode

while (1)
{

	data = SPI_u8RecieveData(); //recieve data from master controller

	//Write data recieved from SPI on PORTD
	DIO_voidWriteOnPin(24,CHECK_BIT(data,0));
	DIO_voidWriteOnPin(25,CHECK_BIT(data,1));
	DIO_voidWriteOnPin(26,CHECK_BIT(data,2));
	DIO_voidWriteOnPin(27,CHECK_BIT(data,3));
	DIO_voidWriteOnPin(28,CHECK_BIT(data,4));
	DIO_voidWriteOnPin(29,CHECK_BIT(data,5));
	DIO_voidWriteOnPin(30,CHECK_BIT(data,6));
	DIO_voidWriteOnPin(31,CHECK_BIT(data,7));

}







}





