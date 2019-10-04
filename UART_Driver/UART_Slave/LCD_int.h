/*
 * LCD_int.h
 *
 *  Created on: Apr 22, 2019
 *      Author: Al-Hussein
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

/*Giving the common commands a name instead of numbers*/
#define CLEAR 				0x01
#define RETURN_HOME		 	0x02
#define BEGEN_SEC_LINE 		0xC0
#define BEGEN_FIR_LINE 		0x80

#define HIGH 1
#define LOW 0

void LCD_voidInit(void); //initializing the LCD
void LCD_voidSendCommand(u8 command); //The user can use this function to send the commands to LCD
void LCD_voidDisplayCharacter(u8 data); //It displays data and it has to be character
void LCD_voidDisplayString(u8 *data); //It displays strings
void LCD_voidClearScreen(void);
void LCD_voidSetCursor(u8 a, u8 b); //a and b are the row and column numbers respectively
void LCD_voidDisplayInteger(u16 data); //This function is used to display an "number"
void LCD_voidShiftRight(void); //Please ignore this function now ^_^

#endif /* LCD_INT_H_ */
