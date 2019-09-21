/*
 * GIE_Driver_program.c
 *
 *  Created on: May 11, 2019
 *      Author: salsa
 */
#include "std_types.h"
#include "Bit_Math.h"

#include "GIE_Driver_priv.h"
#include "GIE_Driver_Config.h"
#include "GIE_Driver_Int.h"

void GIE_void_Enable_Global_Interrupt(){
SET_BIT(SREG,I);

}
void GIE_void_Disable_Global_Interrupt(){
CLEAR_BIT(SREG,I);
}
