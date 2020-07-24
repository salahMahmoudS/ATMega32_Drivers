#ifndef _UART_CONFIG_H
#define _UART_CONFIG_H

/*
 * Enabling the below mode will allow transmitting the data at double rate. This only works for asynchronous mode and but should be disabled in synchronous mode
 * Choose between
 * ENABLE
 * DISABLE
 */
#define DOUBLE_UART_RATE					DISABLE

/*
 * The below mode controls generating an interrupt when receiving is complete., choose between
 * ENABLE
 * DISABLE
 */
#define RX_INTERRUPT_ENABLE					DISABLE

/*
 * The below mode controls generating an interrupt when transmitting is complete., choose between
 * ENABLE
 * DISABLE
 */
#define TX_INTERRUPT_ENABLE					ENABLE

/*
 * The below mode controls generating an interrupt when data register is empty., choose between
 * ENABLE
 * DISABLE
 */
#define DATA_REG_EMPTY_INTERRUPT_ENABLE		ENABLE

/*
 * The below mode allows the UART to enable transmitting bits. choose between
 * ENABLE
 * DISABLE
 */
#define TX_ENABLE							ENABLE

/*
 * The below mode allows the UART to enable receiving bits. choose between
 * ENABLE
 * DISABLE
 */
#define RX_ENABLE							ENABLE
/*
 * The below mode allows you to choose the number of data bits, choose between the following
 * CHAR_SIZE_5
 * CHAR_SIZE_6
 * CHAR_SIZE_7
 * CHAR_SIZE_8
 * CHAR_SIZE_9
 */
#define CHAR_SIZE							CHAR_SIZE_8

/*
 * The below mode allows you to operate is synchronous or asynchronous operation, choose between
 * ASYNCHRONOUS_OPERATION
 * SYNCHRONOUS_OPERATION
 */
#define OP_MODE								ASYNCHRONOUS_OPERATION

/*The following allows you to select parity type, select between
 *PARITY_DISABLED
 *PARITY_EVEN
 *PARITY_ODD
 */
#define PARITY_SELECT						PARITY_DISABLED

/*
 * The following allows you to select number of stop bits to be sent to the slave, select between
 * STOP_1
 * STOP_2
 */
#define NUM_OF_STOP_BITS					STOP_1
/*
 * The below was configured providing that oscillator is 16MHz, any change in the frequency requires a change on the below values. choose between the following
 * BR_2400
 * BR_4800
 * BR_9600
 * BR_14_4K
 * BR_115_2K
 * BR_250K
 * BR_2400X2
 * BR_4800X2
 * BR_9600X2
 */
#define BR									BR_9600


#endif
