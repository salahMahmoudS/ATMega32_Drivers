/*
 * ADC_Int.h
 *
 *  Created on: Nov 23, 2019
 *      Author: salsa
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

void ADC_voidInitialize(void);
void ADC_voidClearInterruptFlag(void);
void ADC_voidChangeReference(u8 reference);
void ADCI_SetCallBack(void (* ADC_Complete_Interrupt_ptr)(void));
u8 ADC_u8Convert8bits(void);
u16 ADC_u16Convert10bits(void);
void ADC_SetCallBack(void (* ADC_Complete_Interrupt_ptr)(void));


#endif /* ADC_INT_H_ */
