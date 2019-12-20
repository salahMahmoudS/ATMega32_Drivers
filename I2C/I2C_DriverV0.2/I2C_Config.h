/*
 * I2C_Config.h
 *
 *  Created on: Dec 11, 2019
 *      Author: salsa
 */

#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_
//The following configuration lets you choose the address of your slave. you can choose any using the most significant 7 bits
//last bit defines if the controller will be part of the broadcast or not and it is defined later in the configurations
#define I2C_MICROCONTROLLER_ADDRESS 0b00000111
//the following configures the bit generator division factor. the Serial clock (SCL) speed is governed by the following equation
//SCLfrequency = CPU frequency/(16+2*I2C_DIVISON_FACTOR_OF_BIT_GENERATION*4^(I2C_PRESCALER_FACTOR))
//Note that SCL frequency must be < CPU frequency by 16 times. you can choose from the following
/*
 * BG0
 * BG1
 * BG2
 * BG4
 * BG8
 * BG16
 * BG18
 * BG32
 * BG64
 * BG128
 */
#define I2C_DIVISION_FACTOR_OF_BIT_GENERATION BG128

//the following configuration controls the generation of the acknowledge pulse. If the TWEA bit is ENABLED
// the ACK pulse is generated on the TWI bus when its conditions are met. Disabling it will disconnect circuit automatically
//from circuit until it is ENABLED again. choose between the modes
/*
 * ENABLED
 * DISABLED
 */
#define I2C_ENABLE_ACKNOWLEDGE_BIT ENABLED

//the following configuration allows you to ENABLE or DISABLE I2C you can choose from the following
/*
 * ENABLED
 * DISABLED
 */
#define I2C_ENABLE ENABLED

//the following configuration allows you to ENABLE or DISABLE Interrupts when I2C interrupt flag is raised
//you can choose between the following
/*
 * ENABLED
 * DSABLED
 */
#define I2C_INTERRUPT_ENABLE DISABLED
//the following configuration lets you determine the prescaler factor that will be used in
//Serial clock pulse frequency that is governed by the equation written in first configuration
//you can choose from the following values

/*
 * PS_1
 * PS_4
 * PS_16
 * PS_64
 */
#define I2C_PRESCALER_FACTOR PS_1

//The following configuration allows you to enable recognition of broadcasts sent over the I2C bus
//you can choose between
/*
 * ENABLED
 * DISABLED
 */
#define I2C_GENERAL_CALL_RECOGNITION_ENABLE ENABLED
#endif /* I2C_CONFIG_H_ */
