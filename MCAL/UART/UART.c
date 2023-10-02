
#include "STD_Types.h"
#include "BIT_Math.h"

#include "UART.h"
#include "UART_cfg.h"
#include "UART_priv.h"



void UART_voidInit(void)
{
	/*Set URSEL to write to UCSRC*/
	SET_BIT(UCSRC,URSEL);
	
	#if UART_MODE == UART_ASYNC
	
	/*Selecting Async mode*/
	CLR_BIT(UCSRC,UMSEL);
	/*Clear polarity control bit*/
	CLR_BIT(UCSRC,UCPOL);
	#elif UART_MODE == UART_SYNC
	
	/*Selecting Sync mode*/
	SET_BIT(UCSRC,UMSEL);
	/*Polarity Control*/
	#if UART_SYNC_POL == 0
	CLR_BIT(UCSRC,UCPOL);
	#elif UART_SYNC_POL == 1
	SET_BIT(UCSRC,UCPOL);
	#endif
	
	#endif 
	
	/*Enables Tx,Rx pins*/
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
	/*Set size of Data*/
	#if UART_DATA_SIZE == UART_SIZE_5_BITS
	
	CLR_BIT(UCSRC,UCSZ0);
	CLR_BIT(UCSRC,UCSZ1);
	
	CLR_BIT(UCSRB,UCSZ2);
	

	#elif UART_DATA_SIZE == UART_SIZE_6_BITS
	
	SET_BIT(UCSRC,UCSZ0);
	CLR_BIT(UCSRC,UCSZ1);
	
	CLR_BIT(UCSRB,UCSZ2);
	
	#elif UART_DATA_SIZE == UART_SIZE_7_BITS
	
	CLR_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	
	CLR_BIT(UCSRB,UCSZ2);
	
	#elif UART_DATA_SIZE == UART_SIZE_8_BITS
	
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	
	CLR_BIT(UCSRB,UCSZ2);
	
	#elif UART_DATA_SIZE == UART_SIZE_9_BITS
	
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	
	SET_BIT(UCSRB,UCSZ2);
	
	
	#endif 
	
	
	/*Set number of Stop bits*/
	#if UART_STOP_BITS == 1
	
	CLR_BIT(UCSRC,USBS);
	
	#elif UART_STOP_BITS == 2
	
	SET_BIT(UCSRC,USBS);
	
	#endif 
	
	
	
	/*Disable Parity*/
	CLR_BIT(UCSRC,UPM0);
	CLR_BIT(UCSRC,UPM1);
	
	#if UART_MODE == UART_ASYNC
	
	
	
	/*Double UART*/
	#if UART_BAUD_Double == 0
	CLR_BIT(UCSRA,U2X);
	#elif UART_BAUD_Double == 1
	SET_BIT(UCSRA,U2X);
	#endif
	/*CLR URSEL to write to UBRRH.*/
	CLR_BIT(UBRRH,URSEL);
	/*Set Baud Rate*/
	UBRRH = UART_BAUD_RATE>>8;
	UBRRL = UART_BAUD_RATE;
	#endif
	

	/*Interface Mode*/
	#if UART_INTERFACE_RX == UART_POLLING
	CLR_BIT(UCSRB,RXCIE);
	
	
	#elif UART_INTERFACE_RX == UART_INTERR
	
	SET_BIT(UCSRB,RXCIE);

	#endif
	
	#if UART_INTERFACE_TX == UART_POLLING
	CLR_BIT(UCSRB,TXCIE);
	
	
	#elif UART_INTERFACE_TX == UART_INTERR
	
	SET_BIT(UCSRB,TXCIE);

	#endif
	
	/**/
	CLR_BIT(UCSRA,MPCM);
	
	CLR_BIT(UCSRB,UDREIE);
	
}


void UART_voidSend(uint16 u16transmit_dataCpy)
{
	while(GET_BIT(UCSRA_REG,UDRE_BIT)==0);//Check Busy
	
	#if UART_DATA_SIZE == UART_SIZE_9_BITS
	uint8 u8nineth_bit = (u16transmit_dataCpy>>8);
	if(u8nine_bit == 0)
	{
		CLR_BIT(UCSRB,TXB8);
	}
	else
	{
		SET_BIT(UCSRB,TXB8);
	}
	
	UDR = (uint8) u16transmit_dataCpy;
	#else 
	UDR = (uint8) u16transmit_dataCpy;
	#endif
	
	
}

uint16 UART_u16Rec(void)
{
	
	
	while(GET_BIT(UCSRA,RXC)==0);//Check Busy
	
	#if UART_DATA_SIZE == UART_SIZE_9_BITS
	uint16 u16Rec_data = 0 ;
	uint8 u8nineth_bit = GET_BIT(UCSRB,RXB8);
	
	u16Rec_data = UDR ;
	u16Rec_data = u16Rec_data && ((uint16)(u8nineth_bit)<<8) ;
	return u16Rec_data ;
	
	#else 
	return ((uint16) UDR) ;
	#endif
	
}