#include "Std_Types.h"
#include "Bit_Math.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "UART_interface.h"

#include "LED_interface.h"



int main(){
	u8 RX_Data=0 ;

	/* System Clock Initialisation */
	RCC_voidSysClkInt();

	/* Enable RCC for GPIOC */
	RCC_voidEnablePerClk(RCC_APB2, 4);
	/* Enable RCC for GPIOB */
	RCC_voidEnablePerClk(RCC_APB2, 3);
	/* Enable RCC for GPIOA */
	RCC_voidEnablePerClk(RCC_APB2, 2);
	/* Enable RCC for Alternate Function */
	RCC_voidEnablePerClk(RCC_APB2, 0);
	/* Enable RCC for USART */
	RCC_voidEnablePerClk(RCC_APB2, 14);

	/* A9 Direction " Alternate Function Push Pull Output " */
	DIO_voidSetPinDirection(PORTA, PIN9, GPIO_OUTPUT_2MHZ_AFPP);

	DIO_voidSetPinDirection(PORTA, PIN10, GPIO_INPUT_FLOAT);


	/* A3 Direction "Output @2MHz Push Pull " */
	DIO_voidSetPinDirection(PORTA, PIN3, GPIO_OUTPUT_2MHZ_PP);


	/* USART Initialisation */
	UART_init();
	/* Enable TX */
	UART_enableTX();
	/* Enable RX */
	UART_enableRX();


	while (1)
	{
		/* Send Character */
		UART_TXdata('M');
		/* Receive Character */
		UART_RXdata(&RX_Data);

		if(RX_Data=='M')
		{
			Led_voidON(PORTA, PIN3);
			_delay_ms(1000);
			Led_voidOFF(PORTA, PIN3);
			_delay_ms(1000);
		}
		else
		{
			Led_voidOFF(PORTA, PIN3);
		}
	}

	return 0;
}


