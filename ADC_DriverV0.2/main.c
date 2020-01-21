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
int main(void)
{

	ADC_voidInitialize();
	DIO_voidInitialize();
	u16 result=0x00;


while(1)
	{
	result = ADC_u16Convert10bits();
	DIO_voidWriteOnPort('C',(result>>8) );
	DIO_voidWriteOnPort('D', result);


	}
	return 0;
}
