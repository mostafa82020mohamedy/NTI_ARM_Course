#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"




int main(void)
{
	//u8 pattern[8]={0,0,0b00000110,0b00011001,0b00000110,0,0,0};

	/* System Clock Init */
	RCC_voidSysClkInt();
	/* Enable RCC for GPIOC */
	RCC_voidEnablePerClk(RCC_APB2, 4);
	/* Enable RCC for GPIOA */
	RCC_voidEnablePerClk(RCC_APB2, 3);

	/* Enable RCC for GPIOA */
	RCC_voidEnablePerClk(RCC_APB2, 2);


	/* C13 Direction "Output @2MHz Push Pull " */
	DIO_voidSetPinDirection(PORTA, PIN0, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN1, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN2, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN3, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN4, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN5, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN6, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN7, GPIO_OUTPUT_2MHZ_PP);



	DIO_voidSetPinDirection(PORTB, PIN7, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTB, PIN8, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTB, PIN9, GPIO_OUTPUT_2MHZ_PP);



	CLCD_voidInit();

	CLCD_voidSendString("Mohamedy");
	//CLCD_voidWriteSpecialCharacter(pattern,0,1,15);

	//CLCD_voidWriteInteger(8594);

	while(1)
	{

	}

	return 0;


}




