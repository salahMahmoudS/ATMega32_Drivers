/*
 * main.c
 *
 *  Created on: Dec 11, 2019
 *      Author: salsa
 */

#include "std_types.h"
#include "Bit_Math.h"
#include "I2C_Reg.h"
#include "DIO_Int.h"
#include "I2C_Int.h"
#include "avr/delay.h"

//0x4C defined on proteus 0x98
#define I2C_SLAVE_ADDRESS 0x08

void ERROR (void)
{
DIO_voidWriteOnPort('C', 0xF0);
}
int main(void)
{
DIO_voidInitialize();
DIO_voidWriteOnPin(DIO_PIN_0, DIO_HIGH);
I2C_voidInitialize();
//I2C_voidEnableAcknowledgeBit();
//TWBR = 0xC8;



u8 status = -1;







while (1)
{
	if (DIO_uint8PinState(DIO_PIN_0) == DIO_LOW)
		{
			status =I2C_u8SendStartBit();
			DIO_voidWriteOnPin(8, DIO_HIGH);
			if (status == I2C_START_CONDITION_TRANSMITTED_ACK_RECIEVED)
			{
				status = I2C_u8SetSlaveAddress(I2C_SLAVE_ADDRESS, I2C_Write);
				DIO_voidWriteOnPin(9, DIO_HIGH);

				if (status == I2C_SLA_AND_WRITE_TRANSMITTED_ACKNOWLEDGE_RECIEVED)
				{
					status = I2C_u8SendDataToSlave(0xF0);
					DIO_voidWriteOnPin(10, DIO_HIGH);
					if (status == I2C_DATA_TRANSMITTED_ACKNOWLEDGE_RECIEVED)
					{
						I2C_voidSendStopBit();
						DIO_voidWriteOnPin(11, DIO_HIGH);

					}
				}
			}
		}
	DIO_voidTogglePin(25);
	_delay_ms(500);

}
	return 0;
}
