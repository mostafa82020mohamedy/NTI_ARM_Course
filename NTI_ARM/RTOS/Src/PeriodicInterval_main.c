
#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include	"STK_interface.h"
#include    "RTOS_interface.h"


void LED1 (void);
void LED2 (void);
void LED3 (void);


int main (void)
{
		/*	System Clock Init			*/
		RCC_voidSysClkInt();
		/*	Enable RCC for GPIOC 		*/
		RCC_voidEnablePerClk(RCC_APB2,4);
		/*	Enable RCC for GPIOB 		*/
		RCC_voidEnablePerClk(RCC_APB2,3);
		/*	Enable RCC for GPIOA 		*/
		RCC_voidEnablePerClk(RCC_APB2,2);


		/*	A0 Direction 	"Output @ 2MHz Push Pull"	*/
		DIO_voidSetPinDirection(PORTA,PIN0,GPIO_OUTPUT_2MHZ_PP);

		/*	A1 Direction 	"Output @ 2MHz Push Pull"	*/
		DIO_voidSetPinDirection(PORTA,PIN1,GPIO_OUTPUT_2MHZ_PP);

		/*	A2 Direction 	"Output @ 2MHz Push Pull"	*/
		DIO_voidSetPinDirection(PORTA,PIN2,GPIO_OUTPUT_2MHZ_PP);


		RTOS_u8CreateTask(0 , 1000 , LED1 ,0 );
		RTOS_u8CreateTask(1 , 2000 , LED2 ,1000 );
		RTOS_u8CreateTask(2 , 3000 , LED3 ,3000 );

		RTOS_voidStart();

		while(1)
		{


		}
		return 0;


}



void LED1 (void)
{
	static u8 Local_u8LedState=0;
	TOG_BIT(Local_u8LedState , 0);
	DIO_voidSetPinValue(PORTA,PIN0,Local_u8LedState);
}

void LED2 (void)
{
	static u8 Local_u8LedState2=0;
	TOG_BIT(Local_u8LedState2 , 0);
	DIO_voidSetPinValue(PORTA,PIN1,Local_u8LedState2);
}
void LED3 (void)
{
	static u8 Local_u8LedState3=0;
	TOG_BIT(Local_u8LedState3 , 0);
	DIO_voidSetPinValue(PORTA,PIN2,Local_u8LedState3);
}

