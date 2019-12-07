/*
 * DIO_Prog.c
 *
 *  Created on: Apr 24, 2019
 *      Author: salsa
 */

#include <util/delay.h>
#include "Bit_Math.h"
#include "std_types.h"
#include "DIO_Reg.h"
#include "DIO_priv.h"
#include "DIO_Config.h"
#include "DIO_Int.h"

void DIO_voidInitialize(void){
DDRA=CONCAT(DIO_PIN7_DIR,DIO_PIN6_DIR,DIO_PIN5_DIR,DIO_PIN4_DIR,DIO_PIN3_DIR,DIO_PIN2_DIR,DIO_PIN1_DIR,DIO_PIN0_DIR);
DDRB=CONCAT(DIO_PIN15_DIR,DIO_PIN14_DIR,DIO_PIN13_DIR,DIO_PIN12_DIR,DIO_PIN11_DIR,DIO_PIN10_DIR,DIO_PIN9_DIR,DIO_PIN8_DIR);
DDRC=CONCAT(DIO_PIN23_DIR,DIO_PIN22_DIR,DIO_PIN21_DIR,DIO_PIN20_DIR,DIO_PIN19_DIR,DIO_PIN18_DIR,DIO_PIN17_DIR,DIO_PIN16_DIR);
DDRD=CONCAT(DIO_PIN31_DIR,DIO_PIN30_DIR,DIO_PIN29_DIR,DIO_PIN28_DIR,DIO_PIN27_DIR,DIO_PIN26_DIR,DIO_PIN25_DIR, DIO_PIN24_DIR);

}

void DIO_voidSetPin(u8 pin){
	if (pin>=0&&pin<=7){

SET_BIT(PORTA,pin);
	}
	else if (pin >=8 && pin<=15){
SET_BIT(PORTB,pin-8);
	}
	else if (pin >=16 && pin<=23){
 SET_BIT(PORTC,pin-16);
			}
	else if (pin >=24 && pin<=31){
SET_BIT(PORTD,pin-24);
		}

	else {
		printf("Non-existing pin to set\n");
		return;
	}

}

void DIO_voidClearPin(u8 pin){
	if (pin>=0&&pin<=7){

CLEAR_BIT(PORTA,pin);
	}
	else if (pin >=8 && pin<=15){
 CLEAR_BIT(PORTB,pin-8);
	}
	else if (pin >=16 && pin<=23){
 CLEAR_BIT(PORTC,pin-16);
			}
	else if (pin >=24 && pin<=31){
 CLEAR_BIT(PORTD,pin-24);
		}

	else {
		printf("Non-existing pin to set\n");
		return;
	}

}

void DIO_voidWriteOnPin(u8 pin,u8 value){
if (value == HIGH){
	DIO_voidSetPin(pin);
}
else if (value == LOW){
	DIO_voidClearPin(pin);

}
else {
	return;
}

}

void DIO_voidTogglePin(u8 pin){
	if (pin>=0&&pin<=7){

TOGGLE_BIT(PORTA,pin);
	}
	else if (pin >=8 && pin<=15){
TOGGLE_BIT(PORTB,pin-8);
	}
	else if (pin >=16 && pin<=23){
TOGGLE_BIT(PORTC,pin-16);
			}
	else if (pin >=24 && pin<=31){
TOGGLE_BIT(PORTD,pin-24);
		}

	else {
		printf("Non-existing pin to set\n");
		return;
	}

}

void DIO_voidBlinkPin(u8 pin, u16 time){
	_delay_ms(time);
	DIO_voidTogglePin(pin);
}

void DIO_voidSetPort(s8 PORT){
	switch (PORT){
	case 'a':case 'A':
		PORTA = 0xFF;
		break;
	case 'b':case 'B':
			PORTB = 0xFF;
			break;
	case 'c':case 'C':
			PORTC = 0xFF;
			break;
	case 'd':case 'D':
			PORTD = 0xFF;
			break;
	default:
		printf("PORT NOT FOUND!");
		return;
	}
}

void DIO_voidClearPort(s8 PORT){
	switch (PORT){
		case 'a':case 'A':
			PORTA = 0x00;
			break;
		case 'b':case 'B':
				PORTB = 0x00;
				break;
		case 'c':case 'C':
				PORTC = 0x00;
				break;
		case 'd':case 'D':
				PORTD = 0x00;
				break;
		default:
			printf("PORT NOT FOUND!");
			return;
		}
}

void DIO_voidTogglePort(s8 PORT){
	switch (PORT){
		case 'a':case 'A':
			PORTA = PORTA^0xFF;
			break;
		case 'b':case 'B':
				PORTB = PORTB^0xFF;
				break;
		case 'c':case 'C':
				PORTC = PORTC^0xFF;
				break;
		case 'd':case 'D':
				PORTD = PORTD^0xFF;
				break;
		default:
			printf("PORT NOT FOUND!");
			return;
		}
}

u8 DIO_uint8PinState(u8 pin){
	if (pin>=0&&pin<=7){

return CHECK_BIT(PINA,pin);
	}
	else if (pin >=8 && pin<=15){

return CHECK_BIT(PINB,pin-8);
	}
	else if (pin >=16 && pin<=23){
return CHECK_BIT(PINC,pin-16);
			}
	else if (pin >=24 && pin<=32){
return CHECK_BIT(PIND,pin-24);
		}

	else {
		printf("Non-existing pin to set\n");
		return 0;
	}

}

void DIO_voidWriteOnPort(s8 PORT,u8 data)
{
	switch (PORT){
			case 'a':case 'A':
				DIO_voidWriteOnPin(DIO_PIN_0, ((data>>0)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_1, ((data>>1)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_2, ((data>>2)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_3, ((data>>3)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_4, ((data>>4)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_5, ((data>>5)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_6, ((data>>6)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_7, ((data>>7)&(0x01)));


				break;
			case 'b':case 'B':
				DIO_voidWriteOnPin(DIO_PIN_8, ((data>>0)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_9, ((data>>1)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_10, ((data>>2)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_11, ((data>>3)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_12, ((data>>4)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_13, ((data>>5)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_14, ((data>>6)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_15, ((data>>7)&(0x01)));
					break;
			case 'c':case 'C':
				DIO_voidWriteOnPin(DIO_PIN_16, ((data>>0)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_17, ((data>>1)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_18, ((data>>2)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_19, ((data>>3)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_20, ((data>>4)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_21, ((data>>5)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_22, ((data>>6)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_23, ((data>>7)&(0x01)));
					break;
			case 'd':case 'D':
				DIO_voidWriteOnPin(DIO_PIN_24, ((data>>0)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_25, ((data>>1)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_26, ((data>>2)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_27, ((data>>3)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_28, ((data>>4)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_29, ((data>>5)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_30, ((data>>6)&(0x01)));
				DIO_voidWriteOnPin(DIO_PIN_31, ((data>>7)&(0x01)));
					break;
			default:
				printf("PORT NOT FOUND!");
				return;
			}
}


