/*
 * LCD_prog.c
 *
 *  Created on: Apr 22, 2019
 *      Author: Al-Hussein & salsa
 */

#include "util/delay.h"
#include "Bit_Math.h"
#include "Std_Types.h"
#include "DIO_int.h"
#include "LCD_priv.h"
#include "LCD_Config.h"
#include "LCD_Int.h"


void LCD_voidInitialize(void)
{


#if (LCD_MODE == MODE_8_BITS)

	DIO_voidWriteOnPin(LCD_PIN_ENABLE, LCD_LOW); //send command
	_delay_ms(2);
	LCD_voidSendCommand(0x38); //set 8bit mode

	LCD_voidSendCommand(LCD_COMMAND_MOVE_CURSOR_RIGHT);
	LCD_voidClearScreenReturnHomePosition();
	_delay_ms(2); //wait 2ms the designed time to execute this command
	LCD_voidSendCommand(LCD_COMMAND_SET_DISPLAY_ON_CURSOR_ON);






#elif (LCD_MODE == MODE_4_BITS)
	//The following comments are as designed in data sheet, written to decrease
	//the waiting time between instructions
	_delay_ms(15); //wait 15ms after initialization (as designed)
	LCD_voidSendCommand(0x30);	//this command initializes internal operations
	_delay_ms(5); //wait 5ms (as designed)
	LCD_voidSendCommand(0x30); //as designed
	_delay_us(150); //as designed
	LCD_voidSendCommand(0x30); //as desgined
	LCD_voidSendCommand(0x32);	//Initialize 4 bit mode
#if(LCD_FONT_TYPE == FIVE_TEN_DOTS_FONT)
	LCD_voidSendCommand(0x2C); //2 lines 5x10 font matrix
#else
	LCD_voidSendCommand(0x28); //2 lines 5x7 font matrix
#endif
	LCD_voidSendCommand(LCD_COMMAND_SET_DISPLAY_ON_CURSOR_ON);
	_delay_us(100);
	LCD_voidClearScreenReturnHomePosition();

	LCD_voidSendCommand(LCD_COMMAND_SET_CURSOR_MOTION_RIGHT);
	_delay_us(100);
	#else
#error "Wrong mode selected please select either MODE_4_BITS mode or MODE_8_BITS "
#endif
}


void LCD_voidSendCommand(u8 command)
{
#if (LCD_MODE == MODE_8_BITS)
DIO_voidWriteOnPin(LCD_PIN_7,CHECK_BIT(command,7));
DIO_voidWriteOnPin(LCD_PIN_6,CHECK_BIT(command,6));
DIO_voidWriteOnPin(LCD_PIN_5,CHECK_BIT(command,5));
DIO_voidWriteOnPin(LCD_PIN_4,CHECK_BIT(command,4));
DIO_voidWriteOnPin(LCD_PIN_3,CHECK_BIT(command,3));
DIO_voidWriteOnPin(LCD_PIN_2,CHECK_BIT(command,2));
DIO_voidWriteOnPin(LCD_PIN_1,CHECK_BIT(command,1));
DIO_voidWriteOnPin(LCD_PIN_0,CHECK_BIT(command,0));
DIO_voidWriteOnPin(LCD_PIN_RS, LCD_LOW);
DIO_voidWriteOnPin(LCD_PIN_RW, LCD_LOW);
DIO_voidWriteOnPin(LCD_PIN_ENABLE, LCD_HIGH);
_delay_us(1);
DIO_voidWriteOnPin(LCD_PIN_ENABLE,DIO_LOW);
_delay_us(100);
#elif(LCD_MODE == MODE_4_BITS)
	//Send the 1st 4 bits on the left
	DIO_voidWriteOnPin(LCD_PIN_7, CHECK_BIT(command,7));

	DIO_voidWriteOnPin(LCD_PIN_6, CHECK_BIT(command,6));
	DIO_voidWriteOnPin(LCD_PIN_5, CHECK_BIT(command,5));
	DIO_voidWriteOnPin(LCD_PIN_4, CHECK_BIT(command,4));
	DIO_voidWriteOnPin(LCD_PIN_WR, LCD_LOW); //Writing mode
	DIO_voidWriteOnPin(LCD_PIN_RS, LCD_LOW); //LOW to write commands
	//Give a pulse
	DIO_voidWriteOnPin(LCD_PIN_ENABLE, LCD_HIGH);
	_delay_us(1);
	DIO_voidWriteOnPin(LCD_PIN_ENABLE, LCD_LOW);
	//Send the 2nd 4 bits on the right
	DIO_voidWriteOnPin(LCD_PIN_7, CHECK_BIT(command,3));
	DIO_voidWriteOnPin(LCD_PIN_6, CHECK_BIT(command,2));
	DIO_voidWriteOnPin(LCD_PIN_5, CHECK_BIT(command,1));
	DIO_voidWriteOnPin(LCD_PIN_4, CHECK_BIT(command,0));
	DIO_voidWriteOnPin(LCD_PIN_ENABLE, LCD_HIGH);
	_delay_us(1);
	DIO_voidWriteOnPin(LCD_PIN_ENABLE, LCD_LOW);
#else
#error
	"Wrong mode selected"
#endif
}


void LCD_voidDisplayCharacter(u8 data)
{
#if (LCD_MODE == MODE_8_BITS)

	DIO_voidWriteOnPin(LCD_PIN_7,CHECK_BIT(data,7));
	DIO_voidWriteOnPin(LCD_PIN_6,CHECK_BIT(data,6));
	DIO_voidWriteOnPin(LCD_PIN_5,CHECK_BIT(data,5));
	DIO_voidWriteOnPin(LCD_PIN_4,CHECK_BIT(data,4));
	DIO_voidWriteOnPin(LCD_PIN_3,CHECK_BIT(data,3));
	DIO_voidWriteOnPin(LCD_PIN_2,CHECK_BIT(data,2));
	DIO_voidWriteOnPin(LCD_PIN_1,CHECK_BIT(data,1));
	DIO_voidWriteOnPin(LCD_PIN_0,CHECK_BIT(data,0));
	DIO_voidWriteOnPin(LCD_PIN_RS, LCD_HIGH);
	DIO_voidWriteOnPin(LCD_PIN_RW, LCD_LOW);
	DIO_voidWriteOnPin(LCD_PIN_ENABLE, LCD_HIGH);
	_delay_us(1);
	DIO_voidWriteOnPin(LCD_PIN_ENABLE,DIO_LOW);
	_delay_us(100);

#elif (LCD_MODE == MODE_4_BITS)
	//Send the 1st 4 bits on the left
	DIO_voidWriteOnPin(LCD_PIN_RS, LCD_HIGH);
	DIO_voidWriteOnPin(LCD_PIN_7, CHECK_BIT(data,7));
	DIO_voidWriteOnPin(LCD_PIN_6, CHECK_BIT(data,6));
	DIO_voidWriteOnPin(LCD_PIN_5, CHECK_BIT(data,5));
	DIO_voidWriteOnPin(LCD_PIN_4, CHECK_BIT(data,4));
	DIO_voidWriteOnPin(LCD_PIN_WR, LCD_LOW); // Write mode
	DIO_voidWriteOnPin(LCD_PIN_RS, LCD_HIGH);// To write data
	//Give a pulse
	DIO_voidWriteOnPin(LCD_PIN_ENABLE, LCD_HIGH);
	_delay_us(1);
	DIO_voidWriteOnPin(LCD_PIN_ENABLE, LCD_LOW);
	//Send the 2nd 4 bits on the right
	DIO_voidWriteOnPin(LCD_PIN_7, CHECK_BIT(data,3));
	DIO_voidWriteOnPin(LCD_PIN_6, CHECK_BIT(data,2));
	DIO_voidWriteOnPin(LCD_PIN_5, CHECK_BIT(data,1));
	DIO_voidWriteOnPin(LCD_PIN_4, CHECK_BIT(data,0));
	//Give a pulse
	DIO_voidWriteOnPin(LCD_PIN_ENABLE, LCD_HIGH);
	_delay_us(1);
	DIO_voidWriteOnPin(LCD_PIN_ENABLE, LCD_LOW);
	_delay_ms(100);
#else
#error "Wrong mode selected"
#endif
}

/*Function Description: it takes a string and loops on each character inside it
 ******************************and displays it*******************************/
void LCD_voidDisplayString(s8 *data)
{
	u8 i = 0;
	while(data[i] != '\0')
	{
		LCD_voidDisplayCharacter(data[i]);
		++i;
	}
}


void LCD_voidClearScreenReturnHomePosition()
{
	LCD_voidSendCommand(0x01);
	_delay_ms(2);
}

void LCD_voidReturnHomePosition()
{
	LCD_voidSendCommand(0x02);
	_delay_ms(2);
}
void LCD_voidSetCursor(u8 Row, u8 Column)
{

#if (LCD_TYPE == LCD_16_2)
u8 firstAddressPositionsTable[] = {0x80,0xC0};
#elif (LCD_TYPE == LCD_20_1)
u8 firstAddressPositionsTable[] = {0x80};
#elif (LCD_TYPE == LCD_20_2)
u8 firstAddressPositionsTable[] = {0x80,0xC0};
#elif (LCD_TYPE == LCD_20_4)
u8 firstAddressPositionsTable[] = {0x80,0xC0,0x94,0xD4};
#elif (LCD_TYPE == LCD_40_2)
u8 firstAddressPositionsTable[] = {0x80,0xC0};
#else
#error
	"wrong type of LCD entered, please enter correct LCD type"
#endif



	u8 position = firstAddressPositionsTable[Row - 1] + Column-1;
	if (position <=0xE7)
	{
		LCD_voidSendCommand(position);
	}
	else
	{

	}

}

/*Function Description: it extracts each numbers from the data*
*************and sending the equivalent ASCI code*************/

void LCD_voidDisplayInteger(u16 data)
{
	for(u16 i = 1000; i >= 1; i/=10)
	{
		LCD_voidDisplayCharacter(48+(data/i));
		data = data % i;
	}
}




