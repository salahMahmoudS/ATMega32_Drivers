/*
 * SPI_Config.h
 *
 *  Created on: Oct 5, 2019
 *      Author: salsa
 */

/*************************IMPORTANT TO NOTICE THE FOLLOWING  *******************/
//please configure the following from DIO config

// MOSI, SCK as output in case of master
// MISO as input in case of master
// SS_ as output in case of single master, in case of multi master configure SS_ as input and use other pins as output for SS

// MOSI as output in case of slave
// MISO,SCK and SS_ as input in case of slave
/******************************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*In this configuration you enable SPI interrupt based communication
 * ENABLE
 * DISABLE
 */
#define SPI_INTERRUPT_ENABLE DISABLE

/*In this configuration you enable SPI mode or disable it (PLEASE MAKE THIS LAST LINE IN INITIALIZATION
 * ENABLE
 * DISABLE
 */
#define SPI_ENABLE ENABLE

/* In this configuration you choose to send first the Most significant bit first (MSB) or the least significant bit (LSB) first
 * MSB_FIRST
 * LSB_FIRST
 */
#define DATA_ORDER_MODE MSB_FIRST

/* In this you choose microcontroller mode to be a master or slave
 * SLAVE
 * MASTER
 */
#define MASTER_MODE SLAVE

/* In this you choose the clock polarity from the options below
/*LEAD_RISING_TRAILING_FALLING
LEAD_FALLING_TRAILING_RISING*/
#define CLOCK_POLARITY_MODE LEAD_RISING_TRAILING_FALLING
#define CLOCK_PHASE_MODE LEAD_SAMPLE_TRAILING_SETUP
#define SCK_FREQUENCY FOSC_16

#define SPI2X_MODE DISABLE

#endif /* SPI_CONFIG_H_ */
