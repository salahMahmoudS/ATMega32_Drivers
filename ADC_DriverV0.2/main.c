/*
 * main.c
 *
 *  Created on: Nov 23, 2019
 *      Author: salsa
 */
#include "std_types.h"
#include "Bit_Math.h"
#include "GI_Int.h"
#include "DIO_Int.h"
#include "ADC_Int.h"

u16 result=0x00;
void ADC_conversionCompleteInterrupt(void);



int main(void)
{

	ADC_voidInitialize();
	DIO_voidInitialize();
	GI_voidInitiazlize();
	GI_voidEnableGlobalInterrupt();
	ADC_SetCallBack(ADC_conversionCompleteInterrupt);



while(1)
	{
	result = ADC_u16Convert10bits();
	//DIO_voidWriteOnPort('C',(result>>8) );
	//DIO_voidWriteOnPort('D', result);


	}
	return 0;
}

void ADC_conversionCompleteInterrupt(void)
{
	DIO_voidWriteOnPort('C',(result>>8) );
	DIO_voidWriteOnPort('D', result);
}
