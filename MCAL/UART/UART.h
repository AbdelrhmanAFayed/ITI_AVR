#ifndef UART_H_
#define UART_H_

void UART_voidInit(void);

void UART_voidSend(uint16 u16transmit_dataCpy);

uint16 UART_u16Rec(void);

#endif