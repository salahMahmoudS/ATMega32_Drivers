/*
 * I2C_Prog.c
 *
 *  Created on: Dec 11, 2019
 *      Author: salsa
 */

#include "std_types.h"
#include "Bit_Math.h"
#include "I2C_Reg.h"
#include "I2C_Priv.h"
#include "I2C_Config.h"
#include "I2C_Int.h"
#include "DIO_Reg.h"
#include "DIO_Int.h"
#include "avr/delay.h"
void I2C_voidInitialize(void)
{
TWAR = I2C_MICROCONTROLLER_ADDRESS<<1;

#if (I2C_DIVISION_FACTOR_OF_BIT_GENERATION == BG0)
TWBR = 0b00000000;
#elif (I2C_DIVISION_FACTOR_OF_BIT_GENERATION == BG1)
TWBR = 0b00000001;
#elif (I2C_DIVISION_FACTOR_OF_BIT_GENERATION == BG2)
TWBR = 0b00000010;
#elif (I2C_DIVISION_FACTOR_OF_BIT_GENERATION == BG4)
TWBR = 0b00000100;
#elif (I2C_DIVISION_FACTOR_OF_BIT_GENERATION == BG8)
TWBR = 0b00001000;
#elif (I2C_DIVISION_FACTOR_OF_BIT_GENERATION == BG16)
TWBR = 0b00010000;
#elif (I2C_DIVISION_FACTOR_OF_BIT_GENERATION == BG18)
TWBR=0b00010010;
#elif (I2C_DIVISION_FACTOR_OF_BIT_GENERATION == BG32)
TWBR = 0b00100000;
#elif (I2C_DIVISION_FACTOR_OF_BIT_GENERATION == BG64)
TWBR = 0b01000000;
#elif (I2C_DIVISION_FACTOR_OF_BIT_GENERATION == BG128)
TWBR = 0b10000000;
#else
#error "Please select one of the division factors in configuration file"
#endif

#if (I2C_ENABLE_ACKNOWLEDGE_BIT == ENABLED)
SET_BIT(TWCR,TWEA);
#elif (I2C_ENABLE_ACKNOWLEDGE_BIT == DISABLED)
CLEAR_BIT(TWCR,TWEA);
#else
#error "I2C Acknowledge bit wrong mode selected please select one of modes provided in configuration file"
#endif

#if (I2C_ENABLE == ENABLED)
SET_BIT(TWCR,TWEN);
#elif (I2C_ENABLE == DISABLED)
CLEAR_BIT(TWCR,TWEN);
#else
#error "I2C Enable wrong mode, please select either enable or disable in configuration file"
#endif

#if (I2C_INTERRUPT_ENABLE == ENABLED)
SET_BIT(TWCR,TWIE);
#elif (I2C_INTERRUPT_ENABLE == DISABLED)
CLEAR_BIT(TWCR,TWIE);
#else
#error "Wrong Interrupt mode, please select either enable or disable in configuration file"
#endif



#if (I2C_PRESCALER_FACTOR == PS_1)
CLEAR_BIT(TWSR,TWPS0);
CLEAR_BIT(TWSR,TWPS1);
#elif (I2C_PRESCALER_FACTOR == PS_4)
SET_BIT(TWSR,TWPS0);
CLEAR_BIT(TWSR,TWPS1);
#elif(I2C_PRESCALER_FACTOR == PS_16)
CLEAR_BIT(TWSR,TWPS0);
SET_BIT(TWSR,TWPS1);
#elif(I2C_PRESCALER_FACTOR == PS_64)
SET_BIT(TWSR,TWPS0);
SET_BIT(TWSR,TWPS1);
#else
#error "Wrong prescaler mode selected, please select mode from configuration file"
#endif

CLEAR_BIT(TWSR,7);  //will change their names wo TWS7 ... TWS3
CLEAR_BIT(TWSR,6);
CLEAR_BIT(TWSR,5);
CLEAR_BIT(TWSR,4);
CLEAR_BIT(TWSR,3);
#if (I2C_GENERAL_CALL_RECOGNITION_ENABLE == ENABLED)
SET_BIT(TWAR,TWGCE);
#elif (I2C_GENERAL_CALL_RECOGNITION_ENABLE == DISABLED)
CLEAR_BIT(TWAR,TWGCE);
#else
#error "Wrong general call recognition mode, please select enable or disable from configuration file"
#endif
}
void I2C_voidEnableAcknowledgeBit(void)
{
	SET_BIT(TWCR,TWEA);
}
void I2C_voidDisableAcknowledgeBit(void)
{
	CLEAR_BIT(TWCR,TWEA);
}

u8 I2C_u8SendStartBit(void)
{

	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWSTA); //to send start condition
	SET_BIT(TWCR,TWINT); //to clear TWINT and transmit the start condition to the bus
	while (!(CHECK_BIT(TWCR,TWINT)));

	if((TWSR & 0xF8) == 0x08)
	{

		return I2C_START_CONDITION_TRANSMITTED_ACK_RECIEVED;
	}
	else if ((TWSR & 0xF8) == 0x10)
	{
		return I2C_REPEATED_START_CONDITION_TRANSMITTED;
	}
	else
	{
		return I2C_ERROR_STATUS;
	}
}


u8 I2C_u8SetSlaveAddress(u8 address,u8 readOrWrite)
{
	TWDR = (address<<1)|(0x01&readOrWrite);
	//TWDR = 0x9A;
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	while (!(CHECK_BIT(TWCR,TWINT)));
	if ((TWSR & 0xF8) == 0x18)
	{
		return I2C_SLA_AND_WRITE_TRANSMITTED_ACKNOWLEDGE_RECIEVED;
	}
	else if ((TWSR & 0xF8) == 0x20)
	{
		return I2C_SLA_AND_WRITE_TRANSMITTED_NOT_ACKNOWLEDGE_RECIEVED;
	}
	else
	{
		return I2C_ERROR_STATUS;
	}
}

void I2C_voidSendRepeatedStartBit(void);

u8 I2C_u8SendDataToSlave(u8 data)
{


TWDR = data;

TWCR = (1<<TWINT | (1<<TWEN));

while (!(TWCR & (1<<TWINT)));

if ((TWSR&0xF8) == 0x28)
{
	return I2C_DATA_TRANSMITTED_ACKNOWLEDGE_RECIEVED;
}
else if ((TWSR&0xF8) == 0x30)
{
	return I2C_DATA_TRANSMITTED_NOT_ACKNOWLEDGE_RECIEVED;
}
else
{
	return I2C_ERROR_STATUS;
}
return 7;
}



void I2C_voidSendStopBit(void)
{
	SET_BIT(TWCR,TWSTO); //to send stop condition
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT); //to clear TWINT and transmit the start condition to the bus


}
void I2C_voidClearCollisionFlag(void);
void I2C_voidSendData(u8 address,u8 data)
{
	I2C_u8SendStartBit();
	//while (!(CHECK_BIT(TWCR,TWINT)));

}
u8 I2C_u8RecieveData(void)
{
	while (!(TWCR & (1 <<TWINT)));
	TWCR = (1<<TWINT )| (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	return TWDR;
}
/*
#include "Std_Types.h"
#include "Bit_Math.h"
#include "I2C_Reg.h"
#include "I2C_Priv.h"
#include "I2C_Config.h"
#include "I2C_Int.h"
#include "DIO_Int.h"

#define ADDRESS 0x11
#define READ  		   1
#define WRITE 		   0
#define REPEATED_START 1

void I2C_voidInitialize(void){
	//Prescale
#if (PRE_SCALER_VALUE == PRE_SCALER_1)
	CLEAR_BIT(TWSR,TWPS0);
	CLEAR_BIT(TWSR,TWPS1);
#elif (PRE_SCALER_VALUE == PRE_SCALER_4)
	SET_BIT(TWSR,TWPS0);
	CLEAR_BIT(TWSR,TWPS1);
#elif (PRE_SCALER_VALUE == PRE_SCALER_16)
	CLEAR_BIT(TWSR,TWPS0);
	SET_BIT(TWSR,TWPS1);
#elif (PRE_SCALER_VALUE == PRE_SCALER_64)
	SET_BIT(TWSR,TWPS0);
	SET_BIT(TWSR,TWPS1);

#else
#error "Pre scaler value error"
#endif
#if MODE == SLAVE
	TWAR = (ADDRESS << 1);
#endif
	TWBR = 0b10000000; //Baud Rate
	SET_BIT(TWCR,TWEN); //to enable I2C
	CLEAR_BIT(TWCR,TWIE); //to disable interrupt
}

static void I2C_voidTransmitAddress(u8 address,u8 RorW)
{
	if(RorW == WRITE){
		TWDR = (address << 1)|0x00; //Load the address and send W signal
	}else
	{
		TWDR = (address << 1)|0x01; //Load the address and send R signal
	}
	CLEAR_BIT(TWCR,TWSTA); //Disable Start Condition
	CLEAR_BIT(TWCR,TWSTO); //Disable Stop Condition "for safety"
	SET_BIT(TWCR,TWEN); //Make sure I2C is working
	SET_BIT(TWCR,TWINT); //Clear the Flag to start transmitting
	while(!CHECK_BIT(TWCR,TWINT)); //wait until transmitting it
}

static void I2C_voidTransmitData(u8 data)
{
	TWDR = data;
	SET_BIT(TWCR,TWEN); //Make sure I2C is working
	SET_BIT(TWCR,TWINT); //Clear the Flag to start transmitting
	while(!CHECK_BIT(TWCR,TWINT));
}

static u8 I2C_u8ReceiveData()
{
	SET_BIT(TWCR,TWEN); //Make sure I2C is working
	CLEAR_BIT(TWCR,TWSTO);
	SET_BIT(TWCR,TWINT); //Clear the Flag to start transmitting
	while(!CHECK_BIT(TWCR,TWINT));
	return TWDR;
}

static void I2C_voidStartCondition(void)
{
	SET_BIT(TWCR,TWSTA); //Start Condition
	SET_BIT(TWCR,TWEN);  //Enable I2C
	SET_BIT(TWCR,TWINT); //Clear the Flag to start transmitting
	while(!CHECK_BIT(TWCR,TWINT));
}

static void I2C_voidStopCondition(void)
{
	SET_BIT(TWCR,TWSTO); //Enable Stop Condition
	SET_BIT(TWCR,TWEN);  //Enable I2C
	SET_BIT(TWCR,TWINT); //Clear the Flag to start transmitting Stop Condition
}

u8 I2C_u8MasterTransmit_RepeatedStart(u8 data,u8 address,u8 repeatedStart)
{

	if(TWSR != 0x08 && TWSR != 0x10)
	{
		return 0;
	}
	I2C_voidTransmitAddress(address, WRITE); //Send the address+W
	if(TWSR == 20 || TWSR == 0x38)
	{
		I2C_voidStartCondition();
		return 0;
	}
	if(TWSR != 0x18)
	{
		return 0;
	}
	I2C_voidTransmitData(data); //Send the data
	if(TWSR == 0x30 || TWSR == 0x38)
	{
		I2C_voidStartCondition();
		return 0;
	}
	if(TWSR != 0x28)
	{
		DIO_voidWriteOnPin(DIO_PIN_11, DIO_HIGH);
		return 0;
	}
	//if(repeatedStart == ENABLE_REPEATED_START)
	//{
	//	I2C_voidStartCondition(); //Repeated Start
	//}
	else
	{
		I2C_voidStopCondition(); //Send stop condition
	}
	return 1;
}

u8 I2C_u8MasterTransmit(u8 data,u8 address,u8 repeatedStart){
	I2C_voidStartCondition(); //Send start condition
	if(TWSR != 0x08)
	{
		return 0;
	}
	I2C_voidTransmitAddress(address, WRITE); //Send the address+W
	if(TWSR != 0x18)
	{
		return 0;
	}
	I2C_voidTransmitData(data); //Send the data
	if(TWSR != 0x28)
	{
		return 0;
	}
//	if(repeatedStart == ENABLE_REPEATED_START)
//	{
//		I2C_voidStartCondition(); //Repeated Start
//	}
	else
	{
		I2C_voidStopCondition(); //Send stop condition
	}
	return 1;
}

u8 I2C_u8SlaveRecieve(void){
	CLEAR_BIT(TWCR,TWSTO);
	CLEAR_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	while(!CHECK_BIT(TWCR,TWINT));
	return I2C_u8ReceiveData();
}
*/
