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


void 	DIO_voidPinsInit(void);
void	DIO_voidSetPinValue(u8 port, u8 pin, u8 Value);
u8		DIO_u8GetPinValue(u8 port, u8 pin);
void 	DIO_voidSetPortValue(u8 Copy_u8Port , u32 Copy_u8Value);


#define		GPIO_HIGH		1
#define		GPIO_LOW		0



#define		GPIO_INPUT_ANALOG				0000
#define		GPIO_INPUT_FLOAT				0100
#define		GPIO_INPUT_PULL_UP_DOWN			1000

#define		GPIO_OUTPUT_10MHZ_PP			0001
#define		GPIO_OUTPUT_10MHZ_OD			0101
#define		GPIO_OUTPUT_10MHZ_AFPP			1001
#define		GPIO_OUTPUT_10MHZ_AFOD			1101

#define		GPIO_OUTPUT_2MHZ_PP				0010
#define		GPIO_OUTPUT_2MHZ_OD				0110
#define		GPIO_OUTPUT_2MHZ_AFPP			1010
#define		GPIO_OUTPUT_2MHZ_AFOD			1110

#define		GPIO_OUTPUT_50MHZ_PP			0011
#define		GPIO_OUTPUT_50MHZ_OD			0111
#define		GPIO_OUTPUT_50MHZ_AFPP			1011
#define		GPIO_OUTPUT_50MHZ_AFOD			1111




#endif
