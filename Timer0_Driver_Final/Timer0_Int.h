/*
 * Timer0_Int.h
 *
 *  Created on: May 25, 2019
 *      Author: salsa
 */


void Timer0_voidInitialize(void);
void Timer0_voidTimerBegin(void);
void Timer0_voidForceOutPutCompareMode(void);
void Timer0_voidEnableOutputCompareInterrupt(void);
void Timer0_voidEnableOverFlowInterrupt(void);
void Timer0_WriteInTCNT0(u8 time);
void Timer0_WriteInOCR0(u8 value);
void Timer0_SetCallBack(void (* TimerInterrupt_ptr)(void));
