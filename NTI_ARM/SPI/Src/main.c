#include "Std_Types.h"
#include "Bit_Math.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SPI_interface.h"

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
	/* Enable RCC for SPI1 */
	RCC_voidEnablePerClk(RCC_APB2, 12);


	/* "MOSI" A7 Direction " Alternate Function Push Pull Output " */
	DIO_voidSetPinDirection(PORTA, PIN7, GPIO_OUTPUT_2MHZ_AFPP);
	/* "MISO" A6 Direction " Float Input " */
	DIO_voidSetPinDirection(PORTA, PIN6, GPIO_INPUT_FLOAT);

	/* "CLK" A7 Direction " Alternate Function Push Pull Output " */
	DIO_voidSetPinDirection(PORTA, PIN5, GPIO_OUTPUT_2MHZ_AFPP);

	/* "SS" A7 Direction " Alternate Function Push Pull Output " */
	DIO_voidSetPinDirection(PORTA, PIN4, GPIO_OUTPUT_2MHZ_AFPP);


	/* A3 Direction "Output @2MHz Push Pull " */
	DIO_voidSetPinDirection(PORTA, PIN3, GPIO_OUTPUT_2MHZ_PP);


	/* SPI Initialisation */
	SPI1_init();

	Led_voidOFF(PORTA, PIN3);

	while (1)
	{
		/* Send Character */
		RX_Data=SPI1_TX_RX_Char('M');


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


