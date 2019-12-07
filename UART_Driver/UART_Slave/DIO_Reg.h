/*
 * DIO_Reg.h
 *
 *  Created on: Dec 7, 2019
 *      Author: salsa
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

#define DDRA *((u8 volatile *) 0x3A)
#define DDA7 7
#define DDA6 6
#define DDA5 5
#define DDA4 4
#define DDA3 3
#define DDA2 2
#define DDA1 1
#define DDA0 0

#define DDRB *((u8 volatile *) 0x37)
#define DDB7 7
#define DDB6 6
#define DDB5 5
#define DDB4 4
#define DDB3 3
#define DDB2 2
#define DDB1 1
#define DDB0 0

#define DDRC *((u8 volatile *) 0x34)
#define DDC7 7
#define DDC6 6
#define DDC5 5
#define DDC4 4
#define DDC3 3
#define DDC2 2
#define DDC1 1
#define DDC0 0

#define DDRD *((u8 volatile *) 0x31)
#define DDD7 7
#define DDD6 6
#define DDD5 5
#define DDD4 4
#define DDD3 3
#define DDD2 2
#define DDD1 1
#define DDD0 0

#define PORTA *((u8 volatile *) 0x3B )
#define PORTA7 7
#define PORTA6 6
#define PORTA5 5
#define PORTA4 4
#define PORTA3 3
#define PORTA2 2
#define PORTA1 1
#define PORTA0 0

#define PORTB *((u8 volatile *) 0x38)
#define PORTB7 7
#define PORTB6 6
#define PORTB5 5
#define PORTB4 4
#define PORTB3 3
#define PORTB2 2
#define PORTB1 1
#define PORTB0 0

#define PORTC *((u8 volatile *) 0x35)
#define PORTC7 7
#define PORTC6 6
#define PORTC5 5
#define PORTC4 4
#define PORTC3 3
#define PORTC2 2
#define PORTC1 1
#define PORTC0 0

#define PORTD *((u8 volatile *) 0x32)
#define PORTD7 7
#define PORTD6 6
#define PORTD5 5
#define PORTD4 4
#define PORTD3 3
#define PORTD2 2
#define PORTD1 1
#define PORTD0 0

#define PINA *((u8 volatile *) 0x39)
#define PINA7 7
#define PINA6 6
#define PINA5 5
#define PINA4 4
#define PINA3 3
#define PINA2 2
#define PINA1 1
#define PINA0 0

#define PINB *((u8 volatile *) 0x36)
#define PINB7 7
#define PINB6 6
#define PINB5 5
#define PINB4 4
#define PINB3 3
#define PINB2 2
#define PINB1 1
#define PINB0 0

#define PINC *((u8 volatile *) 0x33)
#define PINC7 7
#define PINC6 6
#define PINC5 5
#define PINC4 4
#define PINC3 3
#define PINC2 2
#define PINC1 1
#define PINC0 0

#define PIND *((u8 volatile *) 0x30)
#define PIND7 7
#define PIND6 6
#define PIND5 5
#define PIND4 4
#define PIND3 3
#define PIND2 2
#define PIND1 1
#define PIND0 0


#endif /* DIO_REG_H_ */
