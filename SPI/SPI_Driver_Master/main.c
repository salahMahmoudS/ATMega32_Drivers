/*
 * main.c
 *
 *  Created on: Oct 5, 2019
 *      Author: salsa
 */

//#include <avr/io.h>
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

DIO_voidInitialize();
SPI_voidInitialize();
/* Enable SPI, Master, set clock rate fck/16 */
//SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);

DIO_voidWriteOnPin(DIO_PIN_0,DIO_HIGH);
DIO_voidWriteOnPin(DIO_PIN_16,DIO_HIGH);
DIO_voidWriteOnPin(DIO_PIN_17,DIO_HIGH);
DIO_voidWriteOnPin(DIO_PIN_18,DIO_HIGH);
DIO_voidWriteOnPin(DIO_PIN_19,DIO_HIGH);
DIO_voidWriteOnPin(DIO_PIN_20,DIO_HIGH);
DIO_voidWriteOnPin(DIO_PIN_21,DIO_HIGH);
DIO_voidWriteOnPin(DIO_PIN_22,DIO_HIGH);
DIO_voidWriteOnPin(DIO_PIN_23,DIO_HIGH);


data |=(DIO_uint8PinState(DIO_PIN_16)<<0);
data |=(DIO_uint8PinState(DIO_PIN_17)<<1);
data |=(DIO_uint8PinState(DIO_PIN_18)<<2);
data |=(DIO_uint8PinState(DIO_PIN_19)<<3);
data |=(DIO_uint8PinState(DIO_PIN_20)<<4);
data |=(DIO_uint8PinState(DIO_PIN_21)<<5);
data |=(DIO_uint8PinState(DIO_PIN_22)<<6);
data |=(DIO_uint8PinState(DIO_PIN_23)<<7);

	/* Set MOSI and SCK output, all others input */
//DIO_voidInitialize();




	if (DIO_uint8PinState(DIO_PIN_0) == PRESSED_PULL_UP)
	{
#if (ENABLE_INITIAL_PRESS == 1)
		SPI_u8SendData(SS0,PINC);
#endif
		SWITCH_OLD_status = PRESSED_PULL_UP;

	}
	else
	{
		SWITCH_OLD_status = RELEASED_PULL_UP;
	}
	while (1)
	{

		if (DIO_uint8PinState(DIO_PIN_16) == PRESSED_PULL_UP)
		{
			data &=~(1<<0);

		}
		else
		{
			data |= (1<<0);
		}

		if (DIO_uint8PinState(DIO_PIN_17) == PRESSED_PULL_UP)
		{
			data &=~(1<<1);
		}
		else
		{
			data |= (1<<1);

		}

		if (DIO_uint8PinState(DIO_PIN_18) == PRESSED_PULL_UP)
		{
			data &=~(1<<2);
		}
		else
		{
			data |= (1<<2);

		}
		if (DIO_uint8PinState(DIO_PIN_19) == PRESSED_PULL_UP)
		{
			data &=~(1<<3);
		}
		else
		{
			data |= (1<<3);

		}
		if (DIO_uint8PinState(DIO_PIN_20) == PRESSED_PULL_UP)
		{
			data &=~(1<<4);
		}
		else
		{
			data |= (1<<4);

		}
		if (DIO_uint8PinState(DIO_PIN_21) == PRESSED_PULL_UP)
		{
			data &=~(1<<5);
		}
		else
		{
			data |= (1<<5);

		}
		if (DIO_uint8PinState(DIO_PIN_22) == PRESSED_PULL_UP)
		{
			data &=~(1<<6);
		}
		else
		{
			data |= (1<<6);

		}
		if (DIO_uint8PinState(DIO_PIN_23) == PRESSED_PULL_UP)
		{
			data &=~(1<<7);
		}
		else
		{
			data |= (1<<7);

		}

//DIO_voidWriteOnPin(24,DIO_uint8PinState(DIO_PIN_16));
//DIO_voidWriteOnPin(25,DIO_uint8PinState(DIO_PIN_17));
//DIO_voidWriteOnPin(26,DIO_uint8PinState(DIO_PIN_18));
//DIO_voidWriteOnPin(27,DIO_uint8PinState(DIO_PIN_19));
//DIO_voidWriteOnPin(28,DIO_uint8PinState(DIO_PIN_20));
//DIO_voidWriteOnPin(29,DIO_uint8PinState(DIO_PIN_21));
//DIO_voidWriteOnPin(30,DIO_uint8PinState(DIO_PIN_22));
//DIO_voidWriteOnPin(31,DIO_uint8PinState(DIO_PIN_23));

		DIO_voidWriteOnPin(24,data>>0);
		DIO_voidWriteOnPin(25,data>>1);
		DIO_voidWriteOnPin(26,data>>2);
		DIO_voidWriteOnPin(27,data>>3);
		DIO_voidWriteOnPin(28,data>>4);
		DIO_voidWriteOnPin(29,data>>5);
		DIO_voidWriteOnPin(30,data>>6);
		DIO_voidWriteOnPin(31,data>>7);

	if (DIO_uint8PinState(DIO_PIN_0)==PRESSED_PULL_UP && SWITCH_OLD_status ==RELEASED_PULL_UP)
	{


	SPI_u8SendData(SS0,data);


	SWITCH_OLD_status =0;

	}
	else if (DIO_uint8PinState(DIO_PIN_0) == RELEASED_PULL_UP && SWITCH_OLD_status ==PRESSED_PULL_UP)
	{
		SWITCH_OLD_status =RELEASED_PULL_UP;
	}
	else
	{

	}

	}
}





//u8 SPI_u8SendDataV2(u8 data)
//	{
//
//
//					SPDR = data;
//					/* Wait for transmission complete */
//					while(!(SPSR & (1<<SPIF)))
//					;
//		return SPDR;
//	}

