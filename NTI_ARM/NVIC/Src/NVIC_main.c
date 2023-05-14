#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"

#include	"NVIC_interface.h"

void _delay_ms(u32 Tick)
{
	for(u32 i=0 ; i<500*Tick ;i++)
	{
		asm("NOP");
	}
}


void	EXTI0_IRQHandler(void);

void	EXTI1_IRQHandler(void);



int main(void)
{
	/*	System Clock Init			*/
	RCC_voidSysClkInt();
	
	/*	Enable RCC for GPIOC 		*/
	RCC_voidEnablePerClk(RCC_APB2,4);
	
	/*	C13 Direction 	"Output @ 2MHz Push Pull"	*/
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);
	
	/*	Interrupt Initialization	*/
	NVIC_voidInit();
	

	NVIC_voidSetSwIntPriority(6, 0b1100);
	NVIC_voidSetSwIntPriority(7, 0b0000);

	/*	Set pending Flag EXTI0		*/
	NVIC_voidSetPendingFlag(6);

	
	/*	Set pending Flag EXTI1		*/
	NVIC_voidSetPendingFlag(7);

	/*	NVIC EXTI0 Enable 			*/
	NVIC_voidEnablePerInt(6);

	/*	NVIC EXTI0 Enable 			*/
	//NVIC_voidEnablePerInt(7);


	while(1)
	{
		
	}
	return 0;
}


//void 	__vector_1(void)
void	EXTI0_IRQHandler(void)
{
		/*		Led On		*/
		DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
		_delay_ms(1000);
		/*		Led Off		*/
		/*	NVIC EXTI0 Enable 			*/
		NVIC_voidEnablePerInt(7);

		while(1);
		NVIC_voidEnablePerInt(7);

		DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
		_delay_ms(1000);
	/*	Clear EXTI0 Flag	*/
}



void	EXTI1_IRQHandler(void)
{
		/*		Led On		*/
		DIO_voidSetPinValue(PORTC,PIN14,GPIO_HIGH);
		_delay_ms(1000);
		/*		Led Off		*/
		while(1);

		DIO_voidSetPinValue(PORTC,PIN14,GPIO_LOW);
		_delay_ms(1000);
	/*	Clear EXTI0 Flag	*/
}



