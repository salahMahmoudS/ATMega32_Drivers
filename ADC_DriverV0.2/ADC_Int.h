/*
 * ADC_Int.h
 *
 *  Created on: Nov 23, 2019
 *      Author: salsa
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

void ADC_voidInitialize(void);
void ADC_voidStartConversion(void);
void ADC_voidClearInterruptFlag(void);
void ADC_voidChangeReference(u8 reference);
u8 ADC_u8Convert8bits(void);
u16 ADC_u16Convert16bits(void);
#endif /* ADC_INT_H_ */
