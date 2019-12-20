/*
 * I2C_Int.h
 *
 *  Created on: Dec 11, 2019
 *      Author: salsa
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_

#define I2C_Write	0
#define I2C_Read	1

#define I2C_ERROR_STATUS									0xFF
#define I2C_START_CONDITION_TRANSMITTED_ACK_RECIEVED		1
#define I2C_REPEATED_START_CONDITION_TRANSMITTED 			2

#define I2C_SLA_AND_WRITE_TRANSMITTED_ACKNOWLEDGE_RECIEVED  	3
#define I2C_SLA_AND_WRITE_TRANSMITTED_NOT_ACKNOWLEDGE_RECIEVED  4

#define I2C_SLA_AND_READ_TRANSMITTED_ACKNOWLEDGE_RECIEVED		5
#define I2C_SLA_AND_READ_TRANSMITTED_NOT_ACKNOWLEDGE_RECIEVED	6

#define I2C_DATA_TRANSMITTED_ACKNOWLEDGE_RECIEVED				7
#define I2C_DATA_TRANSMITTED_NOT_ACKNOWLEDGE_RECIEVED			8

void I2C_voidInitialize(void);
void I2C_voidEnableAcknowledgeBit(void);
void I2C_voidDisableAcknowledgeBit(void);
u8 I2C_u8SetSlaveAddress(u8 address,u8 readOrWrite);
u8 I2C_u8SendDataToSlave(u8 data);
u8 I2C_u8SendStartBit(void);
u8 I2C_u8SendRepeatedStartBit(void);
void I2C_voidSendStopBit(void);
void I2C_voidClearCollisionFlag(void);
//void I2C_voidSendData(u8 address,u8 data);
u8 I2C_u8RecieveData(void);




#endif /* I2C_INT_H_ */
