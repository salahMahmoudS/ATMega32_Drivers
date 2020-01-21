	#include "std_types.h"
#include "Bit_Math.h"
#include "DIO_Int.h"
#include "Switch_Init.h"

int main(void){
	DIO_voidInitialize();
	Switch_voidInitialize();
DIO_voidWriteOnPin(DIO_PIN_6,DIO_HIGH); //Activate pullup resistor in pin6 the microcontroller that is connected to switch
	while (1){
		if (Switch_u8IsPressed(SWITCH_0) == SWITCH_IS_PRESSED){
			DIO_voidWriteOnPin(DIO_PIN_1,DIO_HIGH); //light led if switch is pressed
		}
		else {
			DIO_voidWriteOnPin(DIO_PIN_1,DIO_LOW); //turn off led
		}
	}
	return 0;
}
