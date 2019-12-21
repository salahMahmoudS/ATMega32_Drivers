/*
 * main.c
 *
 *  Created on: Nov 23, 2019
 *      Author: salsa
 */
#include "std_types.h"
#include "Bit_Math.h"
#include "GI_Int.h"
#include "ADC_Int.h"
#include "avr/io.h"
int main(void)
{
	DDRD = 0xFF;
	DDRC= 0xFF;
	ADC_voidInitialize();
	ADC_voidStartConversion();
	u16 result=0x00;


while(1)
	{
	result = ADC_u16Convert10bits();
	PORTC = (result>>8);
	PORTD = result;


	}
	return 0;
}
