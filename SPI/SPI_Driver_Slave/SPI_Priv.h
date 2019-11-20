/*
 * SPI_priv.h
 *
 *  Created on: Oct 5, 2019
 *      Author: Salah Mahmoud
 */

#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_



#define FOSC_4   0
#define FOSC_16  1
#define FOSC_64_0  2
#define FOSC_128 3
#define FOSC_2   4
#define FOSC_8   5
#define FOSC_32  6
#define FOSC_64_1  7

#define LEAD_RISING_TRAILING_FALLING 0
#define LEAD_FALLING_TRAILING_RISING 1

#define LEAD_SAMPLE_TRAILING_SETUP 0
#define LEAD_SETUP_TRAILING_SAMPLE 1

#define ENABLE  1
#define DISABLE 0

#define LSB_FIRST 1
#define MSB_FIRST 0

#define MASTER 1
#define SLAVE 0

#define PRESSED 1
#define RELEASED 0
#endif /* SPI_PRIV_H_ */
