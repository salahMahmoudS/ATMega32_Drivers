/*
 * GI_Prog.c
 *
 *  Created on: May 23, 2019
 *      Author: salsa
 */


#include "std_types.h"
#include "Bit_Math.h"
#include "GI_Reg.h"
#include "GI_Priv.h"
#include "GI_Config.h"
#include "GI_Int.h"

GI_voidInitiazlize(void){

}
GI_voidEnableGlobalInterrupt(void){
	SET_BIT(SREG,I);
}
GI_voidDisableGlobalInterrupt(void){
	CLEAR_BIT(SREG,I);
}
