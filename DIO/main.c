
#include "Bit_Math.h"
#include "std_types.h"
#include "util/delay.h"
#include "DIO_Int.h"

int main(void){
DIO_voidInitialize();
while (1){
	/*DIO_voidWriteOnPin(DIO_PIN_1,DIO_HIGH);
	_delay_ms(500);
	DIO_voidWriteOnPin(DIO_PIN_1,DIO_LOW);
	_delay_ms(500);
	*/
	//DIO_voidWriteOnPin(5, DIO_HIGH);
	u8 count=0x00;
u8 pin0 =24;
u8 pin1 =25;
u8 pin2 =26;
u8 pin3 =27;
u8 pin4 =28;
u8 pin5 =29;
u8 pin6 =30;
u8 pin7 =31;
DIO_voidSetPort('D');
if (DIO_uint8PinState(pin0) == DIO_LOW)
{
	DIO_voidSetPin(pin0-8);
}
else
{
	DIO_voidClearPin(pin0-8);
}
if (DIO_uint8PinState(pin1) == DIO_LOW)
{
	DIO_voidSetPin(pin1-8);
}
else
{
	DIO_voidClearPin(pin1-8);
}
if (DIO_uint8PinState(pin2) == DIO_LOW)
{
	DIO_voidSetPin(pin2-8);
}
else
{
	DIO_voidClearPin(pin2-8);
}
if (DIO_uint8PinState(pin3) == DIO_LOW)
{
	DIO_voidSetPin(pin3-8);
}
else
{
	DIO_voidClearPin(pin3-8);
}
if (DIO_uint8PinState(pin4) == DIO_LOW)
{
	DIO_voidSetPin(pin4-8);
}
else
{
	DIO_voidClearPin(pin4-8);
}
if (DIO_uint8PinState(pin5) == DIO_LOW)
{
	DIO_voidSetPin(pin5-8);
}
else
{
	DIO_voidClearPin(pin5-8);
}
if (DIO_uint8PinState(pin6) == DIO_LOW)
{
	DIO_voidSetPin(pin6-8);
}
else
{
	DIO_voidClearPin(pin6-8);
}
if (DIO_uint8PinState(pin7) == DIO_LOW)
{
	DIO_voidSetPin(pin7-8);
}
else
{
	DIO_voidClearPin(pin7-8);
}
}
	return 0;
}
