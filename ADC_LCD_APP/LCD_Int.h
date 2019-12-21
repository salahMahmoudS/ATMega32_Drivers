/*
 * LCD_IntV0.2.h
 *
 *  Created on: Dec 20, 2019
 *      Author: salsa
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_


#define LCD_COMMAND_SET_CURSOR_MOTION_LEFT				0X04
#define LCD_COMMAND_OVERRIDE_AND_MOVE_DISPLAY_RIGHT		0X05
#define LCD_COMMAND_SET_CURSOR_MOTION_RIGHT				0x06
#define LCD_COMMAND_OVERRIDE_AND_MOVE_DISPLAY_LEFT		0X07
#define LCD_COMMAND_SET_DISPLAY_OFF						0x08
#define LCD_COMMAND_SET_DISPLAY_ON_CURSOR_OFF			0x0C
#define LCD_COMMAND_SET_DISPLAY_ON_CURSOR_ON			0x0E
#define LCD_COMMAND_SET_DISPLAY_ON_CURSOR_OFF_BLINK_ON	0x0D
#define LCD_COMMAND_SET_DISPLAY_ON_CURSOR_ON_BLINK_ON	0x0F
#define LCD_COMMAND_BEGIN_FIRST_LINE 					0x80
#define LCD_COMMAND_BEGIN_SEC_LINE 						0xC0
#define LCD_COMMAND_SHIFT_DISPLAY_RIGHT					0x1D
#define LCD_COMMAND_SHIFT_DISPLAY_LEFT					0x18
#define LCD_COMMAND_MOVE_CURSOR_RIGHT					0x14
#define LCD_COMMAND_MOVE_CURSOR_LEFT					0x10
#define LCD_HIGH 1
#define LCD_LOW 0

void LCD_voidInitialize(void); //initializing the LCD
void LCD_voidSendCommand(u8 command); //The user can use this function to send the commands to LCD
void LCD_voidDisplayCharacter(u8 data); //It displays data and it has to be character
void LCD_voidDisplayString(s8 *data); //It displays strings
void LCD_voidClearScreenReturnHomePosition(void);
void LCD_voidReturnHomePosition(void);
void LCD_voidSetCursor(u8 Row, u8 Column); //Set cursor position
void LCD_voidDisplayInteger(u16 data); //This function is used to display a "number"
void LCD_voidShiftRight(void);

#endif /* LCD_INT_H_ */
