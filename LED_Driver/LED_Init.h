/*
 * LED_Init.h
 *
 *  Created on: May 19, 2019
 *      Author: salsa
 */

#ifndef LED_INIT_H_
#define LED_INIT_H_

#define LED_0 0
#define LED_1 1
#define LED_2 2

void LED_voidInitialize();
void LED_voidTurnONLED(u8 LED);
void LED_voidTurnOFFLED(u8 LED);
void LED_voidTOGGLELED(u8 LED);


#endif /* LED_INIT_H_ */
