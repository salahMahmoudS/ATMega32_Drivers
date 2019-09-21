/*
 * GIE_Driver_priv.h
 *
 *  Created on: May 11, 2019
 *      Author: salsa
 */
#include "std_types.h"

#ifndef GIE_DRIVER_PRIV_H_
#define GIE_DRIVER_PRIV_H_

#define SREG *((volatile u8*) 0x5F) //adress of SREG that can be determined from ATmega32 Data sheet
#define I 7 // number of interrupt pin in the register, setting it will enable global interrupt



#endif /* GIE_DRIVER_PRIV_H_ */
