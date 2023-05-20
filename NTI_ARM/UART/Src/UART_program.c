/*
in the main:
1- Enable UART(1,2,3) RCC
2- GPIO => Alternate Function A9 (Tx) Direction OUTPUT AF_PP
3- GPIO A10 (Rx) Direction INPUT_FLOAT
*/

#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"
#include "UART_config.h"
#include "UART_private.h"
#include "UART_interface.h"


void UART_init(void)
{

	/* Select Baud rate */
	USART1 ->BRR =BAUDRATE;

	/* Select Word Length */
	#if(WORD_LENTH==EIGHT_BITS)
	{
		CLR_BIT(USART1->CR1 , 12);
	}
	#elif(WORD_LENTH==NINE_BITS)
	{
		SET_BIT(USART1->CR1 , 12);
	}
	#else
	{
		/* Error */
	}
	#endif

	/* Select Parity */
	#if(PARITY==NO_PARITY)
	{
		CLR_BIT(USART1->CR1 , 10);
	}
	#elif(PARITY==ODD_PARITY)
	{
		SET_BIT(USART1->CR1 , 10);
		CLR_BIT(USART1->CR1 , 9 );
	}
	#elif(PARITY==ODD_PARITY)
	{
		SET_BIT(USART1->CR1 , 10);
		SET_BIT(USART1->CR1 , 9 );
	}
	#else
	{
		/* Error */
	}
	#endif

	/* Select Number of Stop Bits */
	USART1 ->BRR =BAUDRATE;

	/* Select Word Length */
	USART1->CR2 &=0xffffcfff;
	USART1->CR2 |=STOP_BIT;

	/* Enable USART */
	SET_BIT(USART1->CR1 , 13);

}


/* Enable Transmitter */
void UART_enableTX(void)
{
	SET_BIT(USART1->CR1 , 3 );
}


/* Enable Receiver */
void UART_enableRX(void)
{
	SET_BIT(USART1->CR1 , 2 );
}


/* Transmit Data */
void UART_TXdata(u8 data)
{
	USART1->DR=data;
	while (GET_BIT(USART1->SR,6)==0);
}

/* Receive Data */
void UART_RXdata (u8 *data )
{
	while (GET_BIT(USART1->SR,5)==0);
	*data=USART1->DR;
}




void UART1_voidSendString(u8 * const str)
{
	u16 buffer = 0;
	while (str[buffer] != '\0')
	{
		UART_TXdata(str[buffer]);
		buffer++;
	}
}

u8 * const UART1_StrReceiveString(void)
{
	u16 buffer = 0;
	static u8 data[30];
	while (data[buffer] != '\0')
	{
		UART_RXdata(&data[buffer]);
		buffer++;
	}
	return data;
}



/* Transmitter Disable */
void UART_disableTX(void)
{
	CLR_BIT(USART1->CR1 , 13);
	CLR_BIT(USART1->CR1 , 3 );
}

/* Receiver Disable */
void UART_disableRX(void)
{
	CLR_BIT(USART1->CR1 , 13);
	CLR_BIT(USART1->CR1 , 2 );
}






