#ifndef		DIO_INTERFACE_H
#define		DIO_INTERFACE_H

#define		PORTA			0
#define		PORTB			1
#define		PORTC			2

#define		PIN0			0
#define		PIN1			1
#define		PIN2			2
#define		PIN3			3
#define		PIN4			4
#define		PIN5			5
#define		PIN6			6
#define		PIN7			7
#define		PIN8			8
#define		PIN9			9
#define		PIN10			10
#define		PIN11			11
#define		PIN12			12
#define		PIN13			13
#define		PIN14			14
#define		PIN15			15


void	DIO_voidSetPinDirection(u8 port, u8 pin, u8 Direction);
void	DIO_voidSetPinValue(u8 port, u8 pin, u8 Value);
void    DIO_voidSethalfPortdir(u8 port ,u8 choosehalfport, u8 direction ) ;
void    DIO_voidSethlafPortval(u8 port , u8 Value ) ;
u8		DIO_u8GetPinValue(u8 port, u8 pin);
void    DIO_voidSethlafPortvalV2(u8 port ,u8 portType, u8 Value );
#define		GPIO_HIGH		1
#define		GPIO_LOW		0



#define		GPIO_INPUT_ANALOG				0b0000
#define		GPIO_INPUT_FLOAT				0b0100
#define		GPIO_INPUT_PULL_UP_DOWN			0b1000

#define		GPIO_OUTPUT_10MHZ_PP			0b0001
#define		GPIO_OUTPUT_10MHZ_OD			0b0101
#define		GPIO_OUTPUT_10MHZ_AFPP			0b1001
#define		GPIO_OUTPUT_10MHZ_AFOD			0b1101

#define		GPIO_OUTPUT_2MHZ_PP				0b0010
#define		GPIO_OUTPUT_2MHZ_OD				0b0110
#define		GPIO_OUTPUT_2MHZ_AFPP			0b1010
#define		GPIO_OUTPUT_2MHZ_AFOD			0b1110

#define		GPIO_OUTPUT_50MHZ_PP			0b0011
#define		GPIO_OUTPUT_50MHZ_OD			0b0111
#define		GPIO_OUTPUT_50MHZ_AFPP			0b1011
#define		GPIO_OUTPUT_50MHZ_AFOD			0b1111

#define     UPPER_half               1
#define     LOWER_half               2

#define		PORT_LOW						0
#define		PORT_HIGH						1

#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0
#endif
