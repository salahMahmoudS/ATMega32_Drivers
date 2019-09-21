/*
 * ExtI_Prog.c
 *
 *  Created on: May 23, 2019
 *      Author: salsa
 */

#include "std_types.h"
#include "Bit_Math.h"
#include "ExtI_Reg.h"
#include "ExtI_Priv.h"
#include "ExtI_Config.h"
#include "ExtI_Int.h"

static volatile void (* Ext_INT0_ptr) (void); //This is the pointer to function

//here we set the modes of the function
void ExtI_voidInitialize(void){
#if (INT0_MODE == LOW_LEVEL)
	CLEAR_BIT(MCUCR,ISC01);
	CLEAR_BIT(MCUCR,ISC00);
#elif (INT0_MODE == ANY_CHANGE)
	CLEAR_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC00);
#elif (INT0_MODE == FALLING_EDGE)
	CLEAR_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC00);
#elif (INT0_MODE == RISING_EDGE)
	SET_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC00);
#else #error "WRONG MODE"
#endif
	CLEAR_BIT(GICR,INT0); //disable INT0 Interrupt
}


void ExtI_voidEnableExtI0(void){
	//set the register to enable global interrupt
	SET_BIT(GICR,INT0);
}

void ExtI_voidDisableExtI0(void){
	CLEAR_BIT(GICR,INT0);
}


void ExtI_voidSetCallBack(void (* I_ptr)(void)){
Ext_INT0_ptr = I_ptr;
}
u8 ExtI_u8ExtInterrupt0FlagStatus(void){
	//Here we know the status of the Interrupt flag if we want to
	if (CHECK_BIT(GIFR,INTF0) == ENABLED){
return ENABLED;
	}
	else
		return DISABLED;
}

void ExtI_voidClearExtInterrupt0Flag(void){
	//We clear the interrupt flag by setting the bit of GIFR register to one
	SET_BIT(GIFR,INTF0);
}


void __vector_1(void)__attribute((signal,used));
void __vector_1(void) {
	Ext_INT0_ptr();
}

//void ExtI_voidEnableExtI1(void);
//void ExtI_voidEnableExtI2(void);
//void ExtI_voidDisableExtI(void);
//void ExtI_voidDisableExtI1(void);
//void ExtI_voidDisableExtI2(void);
//void ExtI_voidDisableExtI(void);
//u8 ExtI_u8ExtInterrupt1FlagStatus(void);
//u8 ExtI_u8ExtInterrupt2FlagStatus(void);
//void ExtI_voidClearExtInterrupt1Flag(void);
//void ExtI_voidClearExtInterrupt2Flag(void);
//void ExtI_voidEnableExtI(void)
