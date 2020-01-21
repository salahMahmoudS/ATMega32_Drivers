
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
if (DIO_u8PinState(pin0) == DIO_LOW)
{
	DIO_voidWriteOnPin(pin0-8,DIO_HIGH);
}
else
{
	DIO_voidWriteOnPin(pin0-8,DIO_LOW);
}
if (DIO_u8PinState(pin1) == DIO_LOW)
{
	DIO_voidWriteOnPin(pin1-8,DIO_HIGH);
}
else
{
	DIO_voidWriteOnPin(pin1-8,DIO_LOW);
}
if (DIO_u8PinState(pin2) == DIO_LOW)
{
	DIO_voidWriteOnPin(pin2-8,DIO_HIGH);
}
else
{
	DIO_voidWriteOnPin(pin2-8,DIO_LOW);
}
if (DIO_u8PinState(pin3) == DIO_LOW)
{
	DIO_voidWriteOnPin(pin3-8,DIO_HIGH);
}
else
{
	DIO_voidWriteOnPin(pin3-8,DIO_LOW);
}
if (DIO_u8PinState(pin4) == DIO_LOW)
{
	DIO_voidWriteOnPin(pin4-8,DIO_HIGH);
}
else
{
	DIO_voidWriteOnPin(pin4-8,DIO_LOW);
}
if (DIO_u8PinState(pin5) == DIO_LOW)
{
	DIO_voidWriteOnPin(pin5-8,DIO_HIGH);
}
else
{
	DIO_voidWriteOnPin(pin5-8,DIO_LOW);
}
if (DIO_u8PinState(pin6) == DIO_LOW)
{
	DIO_voidWriteOnPin(pin6-8,DIO_HIGH);
}
else
{
	DIO_voidWriteOnPin(pin6-8,DIO_LOW);
}
if (DIO_u8PinState(pin7) == DIO_LOW)
{
	DIO_voidWriteOnPin(pin7-8,DIO_HIGH);
}
else
{
	DIO_voidWriteOnPin(pin7-8,DIO_LOW);
}
}
	return 0;
}
