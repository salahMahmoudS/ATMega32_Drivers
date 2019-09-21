#include "Bit_Math.h"
#include "std_types.h"
#include "util/delay.h"
#include <avr/io.h>
#include "DIO_Int.h"

int main(void){
DIO_voidInitialize();
while (1){
	DIO_voidWriteOnPin(DIO_PIN_1,DIO_HIGH);
	_delay_ms(500);
	DIO_voidWriteOnPin(DIO_PIN_1,DIO_LOW);
	_delay_ms(500);
}
	return 0;
}
