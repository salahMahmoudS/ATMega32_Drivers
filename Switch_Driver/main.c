#include "std_types.h"
#include "Bit_Math.h"
#include "DIO_Int.h"
#include "Switch_Init.h"

int main(void){
	DIO_voidInitialize();
	Switch_voidInitialize();
DIO_voidWriteOnPin(DIO_PIN_1,DIO_HIGH);
	while (1){
		if (Switch_u8IsPressed(SWITCH_0) == IS_PRESSED){
			DIO_voidWriteOnPin(DIO_PIN_1,DIO_HIGH);
		}
		else {
			DIO_voidWriteOnPin(DIO_PIN_1,DIO_LOW);
		}
	}
	return 0;
}
