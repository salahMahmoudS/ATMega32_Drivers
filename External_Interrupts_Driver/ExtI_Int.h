/*
 * ExtI_Int.h
 *
 *  Created on: May 23, 2019
 *      Author: salsa
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_


#define ENABLED 1
#define DISABLED 0


void ExtI_voidInitialize(void);
void ExtI_voidEnableExtI(void);
void ExtI_voidEnableExtI0(void);
void ExtI_voidEnableExtI1(void);
void ExtI_voidEnableExtI2(void);
void ExtI_voidDisableExtI(void);
void ExtI_voidDisableExtI0(void);
void ExtI_voidDisableExtI1(void);
void ExtI_voidDisableExtI2(void);
void ExtI_voidDisableExtI(void);
void ExtI_voidSetCallBack(void (* I_ptr)(void));
u8 ExtI_u8ExtInterrupt0FlagStatus(void);
u8 ExtI_u8ExtInterrupt1FlagStatus(void);
u8 ExtI_u8ExtInterrupt2FlagStatus(void);
void ExtI_voidClearExtInterrupt0Flag(void);
void ExtI_voidClearExtInterrupt1Flag(void);
void ExtI_voidClearExtInterrupt2Flag(void);




#endif /* EXTI_INT_H_ */
