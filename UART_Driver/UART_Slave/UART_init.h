#ifndef _UART_INT_H
#define _UART_INT_H

#include "STD_TYPES.h"

void UART_voidInit(void);
void UART_voidSend(u8 Data);
u8 UART_voidReceive(void);
void voidUARTTxComplete_SetCallBack(void (*TxCompleteInterrupt_ptr)(void));
void voidUARTRxComplete_SetCallBack(void (*RxCompleteInterrupt_ptr)(void));
void voidUARDataRegisterEmpty_SetCallBack(void (*DataRegisterEmptyInterrupt_ptr)(void));
#endif
