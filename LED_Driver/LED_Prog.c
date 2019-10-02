/*
 * LED_Prog.c
 *
 *  Created on: May 19, 2019
 *      Author: salsa
 */
#include "std_types.h"
#include "Bit_Math.h"
#include "DIO_priv.h"
#include "DIO_Config.h"
#include "DIO_Int.h"
#include "LED_Priv.h"
#include "LED_Config.h"
#include "LED_Init.h"

void LED_voidInitialize(){

}
void LED_voidTurnONLED(u8 LED){
switch (LED){
case LED_0:
#if (LED_0_MODE == FORWARD)
	DIO_voidWriteOnPin(LED_0_PIN,DIO_HIGH);
#elif(LED_0_MODE == REVERSE)
	DIO_voidWriteOnPin(LED_0_PIN,DIO_LOW);
#else
#error "WRONG_MODE"
#endif

break;

case LED_1:
	#if (LED_1_MODE == FORWARD)
	DIO_voidWriteOnPin(LED_1_PIN,DIO_HIGH);
#elif(LED_1_MODE == REVERSE)
	DIO_voidWriteOnPin(LED_1_PIN,DIO_LOW);
#else
#error "WRONG_MODE"
#endif
	break;
case LED_2:
	#if (LED_2_MODE == FORWARD)
	DIO_voidWriteOnPin(LED_2_PIN,DIO_HIGH);
#elif(LED_2_MODE == REVERSE)
	DIO_voidWriteOnPin(LED_2_PIN,DIO_LOW);
#else
#error "WRONG_MODE"
#endif
}
}
void LED_voidTurnOFFLED(u8 LED){
	switch (LED){
	case LED_0:
	#if (LED_0_MODE == FORWARD)
		DIO_voidWriteOnPin(LED_0_PIN,DIO_LOW);
	#elif(LED_0_MODE == REVERSE)
		DIO_voidWriteOnPin(LED_0_PIN,DIO_HIGH);
	#else
	#error "WRONG_MODE"
	#endif

	break;

	case LED_1:

	#if (LED_1_MODE == FORWARD)
		DIO_voidWriteOnPin(LED_1_PIN,DIO_LOW);
	#elif(LED_1_MODE == REVERSE)
		DIO_voidWriteOnPin(LED_1_PIN,DIO_HIGH);
	#else
	#error "WRONG_MODE"
	#endif
		break;
	case LED_2:

	#if (LED_2_MODE == FORWARD)
		DIO_voidWriteOnPin(LED_2_PIN,DIO_LOW);
	#elif(LED_2_MODE == REVERSE)
		DIO_voidWriteOnPin(LED_2_PIN,DIO_HIGH);
	#else
	#error "WRONG_MODE"
	#endif
		break;
	}
}
void LED_voidTOGGLELED(u8 LED){
switch (LED){
case LED_0:
	DIO_voidTogglePin(LED_0_PIN);
	break;
case LED_1:
DIO_voidTogglePin(LED_1_PIN);
break;

case LED_2:
	DIO_voidTogglePin(LED_2_PIN);
	break;

}
}
