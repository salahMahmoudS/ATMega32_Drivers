/*
 * Timer_Priv.h
 *
 *  Created on: May 25, 2019
 *      Author: salsa
 */

#ifndef TIMER0_PRIV_H_
#define TIMER0_PRIV_H_

#define NORMAL_MODE 0
#define PWM_PHASE_CORRECT_MODE 1
#define CTC_MODE 2//capture compare
#define FAST_PWM_MODE 3

#define NORMAL_COMPARE_OUTPUT 0
#define SET_OC0_ON_COMPARE_MATCH 1
#define CLEAR_OC0_ON_COMPARE_MATCH 2

#define NORMAL_OUTPUT 0
#define SET_OC0_DOWNCOUNT_CLEAR_UPCOUNT 1
#define CLEAR_OC0_DOWNCOUNT_SET_UPCOUNT 2

#define NO_CLK 0
#define CLK_1 1
#define CLK_8 2
#define CLK_64 3
#define CLK_256 4
#define CLK_1024 5
#define EXTERNAL_ON_T0_COUNT_ON_FALLING_EDGE 6
#define EXTERNAL_ON_T0_COUNT_ON_RISING_EDGE 7


#endif /* TIMER0_PRIV_H_ */
