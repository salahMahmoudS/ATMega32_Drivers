#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_Reg.h"
#include "UART_priv.h"
#include "UART_config.h"
#include "UART_init.h"

void UART_voidInit(void)
{

	u8 Local_u8UCSRC = 0x80; //there is a hardware limitation on this register because we it shares the address
	//with another register, we cannot access this reg. bit by bit and we can only write on it. so we made a
	//local variabe above to modify its data then write it on the actual UCSRC (it is initially 0x80 to indicate
	//that we want to write on this current UCSRC (bit 7 in this indicates that we use UCSRC)
	UBRRL=BR;
	UCSRA=0;
	UCSRB=0;

	#if DOUBLE_UART_RATE==ENABLE
		SET_BIT(UCSRA,U2X);
#elif(DOUBLE_UART_RATE==DISABLE)
		CLEAR_BIT(UCSRA,U2X);
#else
#error "Wrong mode for double UART rate, please select either enable or disable "
	#endif

	/*choose UCSRC to write on it*/

	SET_BIT(Local_u8UCSRC,URSEL);
	Local_u8UCSRC |= (PARITY_SELECT<<UPM1);

#if (NUM_OF_STOP_BITS == STOP_1)
	CLEAR_BIT(Local_u8UCSRC,USBS);
	#elif NUM_OF_STOP_BITS==STOP_2
		SET_BIT(Local_u8UCSRC,USBS);
#else
#error "Wrong number of stop bits selected, please select either STOP_1 for one stop bit or STOP_2 for two stop bits"
	#endif

#if (OP_MODE == SYNCHRONOUS_OPERATION)
		SET_BIT(Local_u8UCSRC,UMSEL);
#elif (OP_MODE == ASYNCHRONOUS_OPERATION)
CLEAR_BIT(Local_u8UCSRC,UMSEL);
#else
#error "Wrong operation mode selected, please either select SYNCHRONOUS_OPERATION or ASYNCHRONOUS_OPERATION"
#endif

#if(CHAR_SIZE == CHAR_SIZE_5)
CLEAR_BIT(Local_u8UCSRC,UCSZ0);
CLEAR_BIT(Local_u8UCSRC,UCSZ1);
CLEAR_BIT(UCSRB,UCSZ2);
	#elif CHAR_SIZE==CHAR_SIZE_6
SET_BIT(Local_u8UCSRC,UCSZ0);
CLEAR_BIT(Local_u8UCSRC,UCSZ1);
CLEAR_BIT(UCSRB,UCSZ2);

	#elif CHAR_SIZE==CHAR_SIZE_7
CLEAR_BIT(Local_u8UCSRC,UCSZ0);
SET_BIT(Local_u8UCSRC,UCSZ1);
CLEAR_BIT(UCSRB,UCSZ2);

	#elif CHAR_SIZE==CHAR_SIZE_8
SET_BIT(Local_u8UCSRC,UCSZ0);
SET_BIT(Local_u8UCSRC,UCSZ1);
CLEAR_BIT(UCSRB,UCSZ2);

	#elif CHAR_SIZE==CHAR_SIZE_9
		SET_BIT(Local_u8UCSRC,UCSZ1);
		SET_BIT(Local_u8UCSRC,UCSZ0);
		SET_BIT(UCSRB,UCSZ2);
#else
#error "Wrong char size selected, please refer to config file and select the right character bits size"
	#endif

	#if	TX_ENABLE==ENABLE
		SET_BIT(UCSRB,TXEN);
#elif (TX_ENABLE == DISABLE)
		CLEAR_BIT(UCSRB,TXEN);
#else
#error "Wrong transmit enable mode, please select either ENABLE or DISABLE"
	#endif

	#if RX_ENABLE==ENABLE
		SET_BIT(UCSRB,RXEN);
#elif RX_ENABLE == DISABLE
		CLEAR_BIT(UCSRB,RXEN);
#error "Wrong recieve enable mode, please select either ENABLE or DISABLE"
	#endif

	UCSRC=Local_u8UCSRC;
}
 
void UART_voidSend(u8 Data)
{
	UDR=Data;
	/*wait until transmission complete*/
	while((CHECK_BIT(UCSRA,6))==0);
	/*clear flag as it isn't cleared by HW*/
	SET_BIT(UCSRA,6);
	return;
}

u8 UART_voidReceive(void)
{
	while((CHECK_BIT(UCSRA,7))==0);
	return UDR;
}
