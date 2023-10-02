#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


/*Registers*/
#define UDR			*((volatile uint8 *)0x2C)
#define UCSRA 		*((volatile uint8 *)0x2B)
#define UCSRB 		*((volatile uint8 *)0x2A)
#define UCSRC 		*((volatile uint8 *)0x40)
#define UBRRH		*((volatile uint8 *)0x40)
#define UBRRL		*((volatile uint8 *)0x29)

/*Registers Breakdown*/
/*UCSRA*/
#define RXC					7 
#define TXC					6 
#define UDRE				5 
#define FE					4 
#define DOR					3 
#define PE					2 
#define U2X					1 
#define MPCM				0

/*UCSRB*/
#define RXCIE				7 
#define TXCIE				6 
#define UDREIE				5 
#define RXEN				4 
#define TXEN				3 
#define UCSZ2				2 
#define RXB8				1 
#define TXB8				0

/*UCSRC*/
#define URSEL				7 
#define UMSEL				6 
#define UPM1				5 
#define UPM0				4 
#define USBS				3 
#define UCSZ1				2 
#define UCSZ0				1 
#define UCPOL				0

/*UART Modes*/

#define UART_SYNC	0 
#define UART_ASYNC	1 

/*DATA Size*/
#define UART_SIZE_5_BITS	0 
#define UART_SIZE_6_BITS	1 
#define UART_SIZE_7_BITS	2 
#define UART_SIZE_8_BITS	3 
#define UART_SIZE_9_BITS	4 

/*Interface mode*/

#define UART_POLLING		0
#define UART_INTERR			1



#endif