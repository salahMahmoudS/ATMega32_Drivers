/*
 * ADC_Priv.h
 *
 *  Created on: Nov 23, 2019
 *      Author: salsa
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

#define AREF 0
#define AVCC_CAPACITOR_AT_AREF 1
#define INTERNAL_2_56_VOLTAGE_REFERENCE 3

#define LEFT_ADJUSTED 1
#define RIGHT_ADJUSTED 0

#define SEI_ADC0 0
#define SEI_ADC1 1
#define SEI_ADC2 2
#define SEI_ADC3 3
#define SEI_ADC4 4
#define SEI_ADC5 5
#define SEI_ADC6 6
#define SEI_ADC7 7
#define DI_PADC0_NADC0_G10 8
#define DI_PADC1_NADC0_G10 9
#define DI_PADC0_NADC0_G200 10
#define DI_PADC1_NADC0_G200 11
#define DI_PADC2_NADC2_G10 12
#define DI_PADC3_NADC2_G10 13
#define DI_PADC2_NADC2_G200 14
#define DI_PADC3_NADC2_G200 15
#define DI_PADC0_NADC1_G1 16
#define DI_PADC1_NADC1_G1 17
#define DI_PADC2_NADC1_G1 18
#define DI_PADC3_NADC1_G1 19
#define DI_PADC4_NADC1_G1 20
#define DI_PADC5_NADC1_G1 21
#define DI_PADC6_NADC1_G1 22
#define DI_PADC7_NADC1_G1 23
#define DI_PADC0_NADC2_G1 24
#define DI_PADC1_NADC2_G1 25
#define DI_PADC2_NADC2_G1 26
#define DI_PADC3_NADC2_G1 27
#define DI_PADC4_NADC2_G1 28
#define DI_PADC5_NADC2_G1 29
#define SEI_1_22V 30
#define SEI_0V 31

#define ENABLED 1
#define DISABLED 0

#define DIVISION_FACTOR_2 1
#define DIVISION_FACTOR_4 2
#define DIVISION_FACTOR_8 3
#define DIVISION_FACTOR_16 4
#define DIVISION_FACTOR_32 5
#define DIVISION_FACTOR_64 6
#define DIVISION_FACTOR_128 7


#define FREE_RUNNING_MODE 0
#define ANALOG_COMAPARTOR 1
#define EXTERNAL_INTERRUPT_REQUEST_0 2
#define TIMER_OR_COUNTER0_COMPARE_MATCH 3
#define TIMER_OR_COUNTER0_OVERFLOW 4
#define TIMER_OR_COUNTER1_COMPARE_MATCH_B 5
#define TIMER_OR_COUNTER1_OVERFLOW 6
#define TIMER_OR_COUNTER1_CAPTURE_EVENT 7
void ADCI_SetCallBack(void (* ADC_Complete_Interrupt_ptr)(void));
void __vector_18(void)__attribute((signal,used));
static void ADC_voidStartConversion(void);

//void ADCI_SetCallBack(void (* ADC_Complete_Interrupt_ptr)(void));
#endif /* ADC_PRIV_H_ */
