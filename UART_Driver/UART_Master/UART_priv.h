#ifndef _UART_PRIV_H
#define _UART_PRIV_H

#define ENABLE					1
#define DISABLE					0

/*Baud rate*/

#define BR_2400					416
#define BR_4800					207
#define BR_9600					103
#define BR_14_4K				68
#define BR_115_2K				8
#define BR_250K					3
#define BR_1M					0
#define BR_2400X2				146
#define BR_4800X2				416
#define BR_9600X2				207

/*character size */
#define CHAR_SIZE_5				0
#define CHAR_SIZE_6				1
#define CHAR_SIZE_7				2
#define CHAR_SIZE_8				3
#define CHAR_SIZE_9				4

/*UART MODE*/
#define ASYNCHRONOUS_OPERATION				0
#define SYNCHRONOUS_OPERATION				1

/*stop bit*/
#define STOP_1					0
#define STOP_2					1

/*parity*/
#define PARITY_Disabled			0
#define PARITY_EVEN 			2
#define PARITY_ODD 				3





#endif
