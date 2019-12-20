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
#define I2C_SLAVE_ADDRESS 0x4C

void ERROR (void)
{
DIO_voidWriteOnPort('C', 0xF0);
}
int main(void)
{
DIO_voidInitialize();
//DIO_voidWriteOnPin(DIO_PIN_0, DIO_HIGH);

I2C_voidInitialize();
//I2C_voidEnableAcknowledgeBit();
//TWBR = 0xC8;




/*
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
				status = I2C_u8SendDataToSlave(0xF1);
				DIO_voidWriteOnPin(10, DIO_HIGH);
			}
		}
	}


*/



while (1)
{
u8 status = I2C_u8RecieveData();
DIO_voidWriteOnPort('B', status );
}
	return 0;
}
