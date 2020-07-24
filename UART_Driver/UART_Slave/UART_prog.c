#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_Reg.h"
#include "UART_priv.h"
#include "UART_config.h"
#include "UART_init.h"
#include "DIO_Int.h"
#include "avr/delay.h"

static volatile void (*RxComplete_INT_ptr)(void);
static volatile void (*TxComplete_INT_ptr)(void);
static volatile void (*DataRegisterEmpty_INT_ptr)(void);

void UART_voidInit(void) {

	u8 Local_u8UCSRC = 0x80; //there is a hardware limitation on this register because we it shares the address
	//with UBRRH register, we cannot access this reg. bit by bit and we can only write on it. so we made a
	//local variabe above to modify its data then write it on the actual UCSRC (it is initially 0x80 to indicate
	//that we want to write on this current UCSRC (bit 7 in this indicates that we use UCSRC)

	u16 baudRate = BR; //the variable that contains the baudrate value from the configuration file
	UBRRL = baudRate;  //since it is a u8 it will only contain the lower 8 bits of the baud rate
	UCSRA = 0;
	UCSRB = 0;
CLEAR_BIT(UCSRC,URSEL);  //to access the UBRRH and assign the baud rate
UCSRC = baudRate>>8;
#if DOUBLE_UART_RATE==ENABLE
	SET_BIT(UCSRA,U2X);
		#elif(DOUBLE_UART_RATE==DISABLE)
			CLEAR_BIT(UCSRA, U2X);
#else
					#error "Wrong mode for double UART rate, please select either enable or disable "
#endif

	/*choose UCSRC to write on it*/

	SET_BIT(Local_u8UCSRC, URSEL);
#if (PARITY_SELECT == PARITY_DISABLED)
	CLEAR_BIT(Local_u8UCSRC,UPM0);
	CLEAR_BIT(Local_u8UCSRC,UPM1);
		#elif(PARITY_SELECT== PARITY_EVEN)
			CLEAR_BIT(Local_u8UCSRC,UPM0);
			SET_BIT(Local_u8UCSRC,UPM1);
				#elif(PARITY_SELECT == PARITY_ODD)
					SET_BIT(Local_u8UCSRC,UPM0);
					SET_BIT(Local_u8UCSRC,UPM1);
						#else
							#error "Wrong mode for parity check bits selected,please either select PARITY_DISABLED, PARITY_EVEN or PARITY_ODD "
#endif

#if (NUM_OF_STOP_BITS == STOP_1)
	CLEAR_BIT(Local_u8UCSRC, USBS);
#elif NUM_OF_STOP_BITS==STOP_2
			SET_BIT(Local_u8UCSRC,USBS);
				#else
					#error "Wrong number of stop bits selected, please select either STOP_1 for one stop bit or STOP_2 for two stop bits"
#endif

#if (OP_MODE == SYNCHRONOUS_OPERATION)
	SET_BIT(Local_u8UCSRC,UMSEL);
		#elif (OP_MODE == ASYNCHRONOUS_OPERATION)
	CLEAR_BIT(Local_u8UCSRC, UMSEL);
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
								SET_BIT(Local_u8UCSRC, UCSZ0);
								SET_BIT(Local_u8UCSRC, UCSZ1);
								CLEAR_BIT(UCSRB, UCSZ2);

									#elif CHAR_SIZE==CHAR_SIZE_9
										SET_BIT(Local_u8UCSRC,UCSZ1);
										SET_BIT(Local_u8UCSRC,UCSZ0);
										SET_BIT(UCSRB,UCSZ2);
											#else
												#error "Wrong char size selected, please refer to config file and select the right character bits size"
#endif

#if (RX_INTERRUPT_ENABLE ==ENABLE)
		SET_BIT(UCSRB,RXCIE);

			#elif (RX_INTERRUPT_ENABLE==DISABLE)
				CLEAR_BIT(UCSRB, RXCIE);

					#else
						#error "Wrong mode for Rx interrupt enable, please select either ENABLE or DISABLE"

#endif

#if (TX_INTERRUPT_ENABLE ==ENABLE)
	SET_BIT(UCSRB,TXCIE);

		#elif (TX_INTERRUPT_ENABLE==DISABLE)
			CLEAR_BIT(UCSRB, TXCIE);

				#else
					#error "Wrong mode for Tx interrupt enable, please select either ENABLE or DISABLE"
#endif

#if (DATA_REG_EMPTY_INTERRUPT_ENABLE==ENABLE)
		SET_BIT(UCSRB,UDRIE);

			#elif (DATA_REG_EMPTY_INTERRUPT_ENABLE==DISABLE)
	CLEAR_BIT(UCSRB, UDRIE);

#else
						#error "Wrong mode for data register empty interrupt enable, please select either ENABLE or DISABLE"
#endif



#if	TX_ENABLE==ENABLE
	SET_BIT(UCSRB, TXEN);
#elif (TX_ENABLE == DISABLE)
				CLEAR_BIT(UCSRB,TXEN);
					#else
						#error "Wrong transmit enable mode, please select either ENABLE or DISABLE"
#endif

#if RX_ENABLE==ENABLE
	SET_BIT(UCSRB, RXEN);

#elif RX_ENABLE == DISABLE
				CLEAR_BIT(UCSRB,RXEN);
					#error "Wrong recieve enable mode, please select either ENABLE or DISABLE"
#endif

				CLEAR_BIT(UCSRA,UDRE);
	UCSRC = Local_u8UCSRC;
}

void UART_voidSend(u8 Data) {

	while ((CHECK_BIT(UCSRA, UDRE)) == 0)
			;

	UDR = Data;


#if (TX_INTERRUPT_ENABLE ==	DISABLE)
	SET_BIT(UCSRA,TXC);
#endif

	return;

}


void UART_voidEnableDataEmptyInterrupt()
{
	SET_BIT(UCSRB,UDRIE);
}

void UART_voidDisableDataEmptyInterrupt()
{
	CLEAR_BIT(UCSRB,UDRIE);
}
u8 UART_voidReceive(void) {
	while ((CHECK_BIT(UCSRA, RXC)) == 0)
		;


	return UDR;
}


void voidUARTRxComplete_SetCallBack(void (*RxCompleteInterrupt_ptr)(void)) {
	RxComplete_INT_ptr = RxCompleteInterrupt_ptr;
}

void __vector_13(void)__attribute((signal,used));
void __vector_13(void) {
	RxComplete_INT_ptr();
}

void voidUARDataRegisterEmpty_SetCallBack(void (*DataRegisterEmptyInterrupt_ptr)(void)) {
	DataRegisterEmpty_INT_ptr = DataRegisterEmptyInterrupt_ptr;
}

void __vector_14(void)__attribute((signal,used));
void __vector_14(void) {
	DataRegisterEmpty_INT_ptr();
}



void voidUARTTxComplete_SetCallBack(void (*TxCompleteInterrupt_ptr)(void)) {
	TxComplete_INT_ptr = TxCompleteInterrupt_ptr;

}

void __vector_15(void)__attribute((signal,used));
void __vector_15(void) {
	DIO_voidTogglePin(DIO_PIN_31);
	TxComplete_INT_ptr();
}


