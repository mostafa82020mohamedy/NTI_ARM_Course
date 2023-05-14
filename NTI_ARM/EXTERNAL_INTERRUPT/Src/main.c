#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"

#include	"NVIC_interface.h"
#include    "EXTI_interface.h"




void	LED(void);
void _delay_ms(u32 Tick);


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

	/*	A1 Direction 	"Output Push Pull @2MHz "	*/
	DIO_voidSetPinDirection(PORTA,PIN1,GPIO_OUTPUT_2MHZ_PP);

	/*	A0 Direction 	"Input Pull UP"	*/
	DIO_voidSetPinDirection(PORTA,PIN0,GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue(PORTA,PIN0,GPIO_HIGH);


	/*	Interrupt Initialization	*/
	NVIC_voidInit();
	/*	NVIC EXTI0 Enable 			*/
	NVIC_voidEnablePerInt(EXTI0);

	EXTI_voidInit(LINE0 , EXTI_PORTA ,FALLING_EDGE);

	EXTI_voidChangeSenseMode(PORTA, FALLING_EDGE);


	/*	Set pending Flag EXTI0		*/
	//NVIC_voidSetPendingFlag(6);


	EXTI9_5_voidSetCallBack(&LED);

	EXTI_voidEnableInt(LINE0);




	while(1)
	{

	}
	return 0;
}


//void	EXTI0_IRQHandler(void)
//{
//	//EXTI0_CallBack();
//	/*		Led On		*/
//			DIO_voidSetPinValue(PORTA,PIN1,GPIO_HIGH);
//			_delay_ms(1000);
//			/*		Led Off		*/
//			DIO_voidSetPinValue(PORTA,PIN1,GPIO_LOW);
//			_delay_ms(1000);
//	/*	Clear EXTI0 Flag	*/
//	//SET_BIT(EXTI -> PR,0);
//}



void	LED(void)
{
	/*		Led On		*/
			DIO_voidSetPinValue(PORTA,PIN1,GPIO_HIGH);
			_delay_ms(1000);
			/*		Led Off		*/
			DIO_voidSetPinValue(PORTA,PIN1,GPIO_LOW);
			_delay_ms(1000);
	/*	Clear EXTI0 Flag	*/


}




void _delay_ms(u32 Tick)
{
	for(u32 i=0 ; i<500*Tick ;i++)
	{
		asm("NOP");
	}
}
