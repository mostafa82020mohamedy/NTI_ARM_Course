#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "DC_MOTOR_interface.h"


int main(void)
{
	/* System Clock Init */
	RCC_voidSysClkInt();

	/* Enable RCC for GPIOB */
	RCC_voidEnablePerClk(RCC_APB2, 3);

	/* Enable RCC for GPIOA */
	RCC_voidEnablePerClk(RCC_APB2, 2);


	/* Port A Direction "Output @2MHz Push Pull " */
	DIO_voidSetPinDirection(PORTA, PIN0, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN1, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN2, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN3, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN4, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN5, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN6, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN7, GPIO_OUTPUT_2MHZ_PP);
	while(1)
	{
		DC_MOTOR_voidRotateCW();
		_delay_ms(1000);
		DC_MOTOR_voidBreak();
		_delay_ms(1000);
		DC_MOTOR_voidRotateCounterCW();
		_delay_ms(1000);
		DC_MOTOR_voidBreak();
		_delay_ms(1000);
	}


	return 0;
}





