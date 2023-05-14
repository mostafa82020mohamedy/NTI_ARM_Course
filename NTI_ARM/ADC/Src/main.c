#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "ADC_interface.h"
#include "LED_interface.h"


int main(){
	f32 ADC_Reading ;

	/* System Clock Initialisation */
	RCC_voidSysClkInt();

	/* Enable RCC for GPIOC */
	RCC_voidEnablePerClk(RCC_APB2, 4);
	/* Enable RCC for GPIOB */
	RCC_voidEnablePerClk(RCC_APB2, 3);
	/* Enable RCC for GPIOA */
	RCC_voidEnablePerClk(RCC_APB2, 2);
	/* Enable RCC for ADC */
	RCC_voidEnablePerClk(RCC_APB2, 9);


	/* A0, A1 and A2 Direction " Analog Input " */
	DIO_voidSetPinDirection(PORTA, PIN0, GPIO_INPUT_ANALOG);
	DIO_voidSetPinDirection(PORTA, PIN1, GPIO_INPUT_ANALOG);
	DIO_voidSetPinDirection(PORTA, PIN2, GPIO_INPUT_ANALOG);

	/* A3, A4 and A5 Direction "Output @2MHz Push Pull " */
	DIO_voidSetPinDirection(PORTA, PIN3, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN4, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN5, GPIO_OUTPUT_2MHZ_PP);

	/* ADC Initialisation */
	ADC_void_Init();
	/* Enable ADC */
	ADC_Enable();
	/* Start ADC Conversion */
	ADC_Start();

	Led_voidOFF(PORTA, PIN3);
	Led_voidOFF(PORTA, PIN4);
	Led_voidOFF(PORTA, PIN5);

		while (1)
		{


			ADC_Reading=ADC_u16_ReadChannel(0);
					if(ADC_Reading <100)
					{
						Led_voidOFF(PORTA, PIN3);
						Led_voidOFF(PORTA, PIN4);
						Led_voidOFF(PORTA, PIN5);
					}
					else if(ADC_Reading < 700)
					{
						Led_voidON(PORTA, PIN3 );
						Led_voidOFF(PORTA, PIN4);
						Led_voidOFF(PORTA, PIN5);
					}
					else if(ADC_Reading < 3000)
					{
						Led_voidON(PORTA, PIN3 );
						Led_voidON(PORTA, PIN4 );
						Led_voidOFF(PORTA, PIN5);

					}
					else
					{
						Led_voidON(PORTA, PIN3 );
						Led_voidON(PORTA, PIN4 );
						Led_voidON(PORTA, PIN5);
					}
				_delay_ms(1000);
		}

	return 0;
}
