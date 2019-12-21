/*
 * LCD_ConfigV0.2.h
 *
 *  Created on: Dec 20, 2019
 *      Author: salsa
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


//Please determine the number of rows and columns of the LCD in the following
/*
 * LCD_16_2 //16x2 LCD
 * LCD_20_1 //20x1 LCD
 * LCD_20_2 //20x2 LCD
 * LCD_20_4 //20x4 LCD
 * LCD_40_2 //40x2 LCD
 */
#define LCD_TYPE LCD_16_2
/*If the LCD is connected through 4 pins only then choose MODE_4_BITS
 ***and if it is connected through 8 pins then choose MODE_8_BITS***/
#define LCD_MODE 		MODE_4_BITS
/*Asigning each pin in the LCD to a pin in the uC*/
#if (LCD_MODE == MODE_8_BITS)
#define LCD_PIN_0 		DIO_PIN_0
#define LCD_PIN_1 		DIO_PIN_1
#define LCD_PIN_2 		DIO_PIN_2
#define LCD_PIN_3 		DIO_PIN_3
#else

#endif

#define LCD_PIN_4 		DIO_PIN_4
#define LCD_PIN_5 		DIO_PIN_5
#define LCD_PIN_6		DIO_PIN_6
#define LCD_PIN_7 		DIO_PIN_7
#define LCD_PIN_ENABLE  DIO_PIN_8
#define LCD_PIN_RW		DIO_PIN_9
#define LCD_PIN_RS 		DIO_PIN_10



//The following configuration lets you choose the font to be 5x7 dots or 5x10 dots
//choose between the following
/*
 * FIVE_TEN_DOTS_FONT
 * FIVE_SEVEN_DOTS_FONT
 *
 */
#define LCD_FONT_TYPE  FIVE_SEVEN_DOTS_FONT

#endif /* LCD_CONFIG_H_ */
