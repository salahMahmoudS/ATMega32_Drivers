/*
 * SPI_Int.h
 *
 *  Created on: Oct 5, 2019
 *      Author: salsa
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_
//Uncomment in case of master by removing first two slashes in next line
///*
//Based on number of slaves uncomment the pins

#define SS0 0
#define SS1 1
#define SS2 2
#define SS3 3

#define SS3_PIN DIO_PIN_9
#define SS2_PIN DIO_PIN_10
#define SS1_PIN DIO_PIN_11
#define SS0_PIN DIO_PIN_12



/***************************/
//Uncomment in case of slave by removing first two slashes in next line
/*
#define SS_ DIO_PIN_12
// In case of sslave you have to configure SS_ pin to INPUT
/*******************/
void SPI_voidInitialize(void);
void SPI_voidReEnableMasterMode(void);
u8 SPI_u8ClearSPIF(void);
u8 SPI_u8ClearWCOL (void);
u8 SPI_u8SendData(u8 slaveNo, u8 data);
u8 SPI_u8RecieveData();



#endif /* SPI_INT_H_ */
