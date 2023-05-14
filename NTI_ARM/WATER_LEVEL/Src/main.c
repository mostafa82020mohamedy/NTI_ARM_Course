#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"







int main(void)
{

	/*	System Clock Init			*/
	RCC_voidSysClkInt();

	/*	Enable RCC for GPIOC 		*/
	RCC_voidEnablePerClk(RCC_APB2,4);
	/*	Enable RCC for GPIOA 		*/
	RCC_voidEnablePerClk(RCC_APB2,2);
	/*	Enable RCC for EXTI0 		*/
	RCC_voidEnablePerClk(RCC_APB2,0);

	/*	A3 Direction 	"Output Push Pull @2MHz "	*/
	DIO_voidSetPinDirection(PORTA,PIN3,GPIO_OUTPUT_2MHZ_PP);
	/*	A4 Direction 	"Output Push Pull @2MHz "	*/
	DIO_voidSetPinDirection(PORTA,PIN4,GPIO_OUTPUT_2MHZ_PP);
	/*	A5 Direction 	"Output Push Pull @2MHz "	*/
	DIO_voidSetPinDirection(PORTA,PIN5,GPIO_OUTPUT_2MHZ_PP);
	/*	A6 Direction 	"Output Push Pull @2MHz "	*/
	DIO_voidSetPinDirection(PORTA,PIN6,GPIO_OUTPUT_2MHZ_PP);

	/*	A0 Direction 	"Input Pull Down"	*/
	DIO_voidSetPinDirection(PORTA,PIN0,GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue(PORTA,PIN0,GPIO_LOW);
	/*	A1 Direction 	"Input Pull Down"	*/
	DIO_voidSetPinDirection(PORTA,PIN1,GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue(PORTA,PIN1,GPIO_LOW);
	/*	A2 Direction 	"Input Pull Down"	*/
	DIO_voidSetPinDirection(PORTA,PIN2,GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue(PORTA,PIN2,GPIO_LOW);


	while(1)
	{
		if((DIO_u8GetPinValue(PORTA,0))==1)
		{
			DIO_voidSetPinValue(PORTA,PIN3,GPIO_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(PORTA,PIN3,GPIO_LOW);
		}

		if((DIO_u8GetPinValue(PORTA,1))==1)
		{
			DIO_voidSetPinValue(PORTA,PIN4,GPIO_HIGH);

		}
		else
		{
			DIO_voidSetPinValue(PORTA,PIN4,GPIO_LOW);
		}

		if((DIO_u8GetPinValue(PORTA,2))==1)
		{
			DIO_voidSetPinValue(PORTA,PIN5,GPIO_HIGH);
			DIO_voidSetPinValue(PORTA, PIN6, GPIO_HIGH);

		}
		else
		{
			DIO_voidSetPinValue(PORTA,PIN5,GPIO_LOW);
			DIO_voidSetPinValue(PORTA, PIN6, GPIO_LOW);
		}

	}
	return 0;
}


