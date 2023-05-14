#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SSD_interface.h"


int main(void)
{

	u8 x;
	u8 arr[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

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


	/* Control Pin */
	DIO_voidSetPinDirection(PORTB, PIN0, GPIO_OUTPUT_2MHZ_PP);



	SSD SS1={COMMON_ANODE,PORTA,PORTB,PIN0};

	while(1)
	{
		for(u8 i=0;i<10;i++)
		{
			x=SSD_SetNumber_ON(arr[i],&SS1);
			_delay_ms(1000);
			x=SSD_SetNumber_OFF(&SS1);
			_delay_ms(1000);
		}
	}

	return 0;
}


