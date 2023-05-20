#ifndef		UART_PRIVATE_H
#define		UART_PRIVATE_H


#define		USART1_BASE_ADD			0x40013800

typedef		struct
{
	u32				SR;
	u32				DR;
	u32				BRR;
	u32				CR1;
	u32				CR2;
	u32				CR3;
	u32				GTPR;
}USART1_Type;
#define			USART1				((volatile USART1_Type*)(USART1_BASE_ADD))


#define     BAUDRATE_8_9600              0x341
#define     BAUDRATE_8_115200            0x45


#define     EIGHT_BITS                   0
#define     NINE_BITS                    1


#define     NO_PARITY                    0
#define     ODD_PARITY                   1
#define     EVEN_PARITY                  2


#define     ONE_STOP_BIT                 0x00000000
#define     TWO_STOP_BIT                 0x00003000




#endif
