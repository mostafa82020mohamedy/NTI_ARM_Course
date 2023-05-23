
#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include	"STK_interface.h"
#include    "LED_interface.h"
//#include    "RTOS_interface.h"


void process1(void);
void process2(void);
void process3(void);
















#define MAX_PROCESSES 30

typedef struct
{
  u8 processID;
  void *func ;
  u32 periodisty ;
  u32 priority;

}Task_t;



#define MAX_PROCESSES 30
u32 ProssNO =0;
u32 curentProcessNo=0;
u8 finish=0;
Task_t processlist[MAX_PROCESSES];
void RTOS_voidCreateTask ( u8 processID ,void *function,u32 periodisty,u32 priority);
void Schedualr_start(void);



void RTOS_voidCreateTask ( u8 processID ,void *function,u32 periodisty,u32 priority)
{

	if (ProssNO < MAX_PROCESSES)
	{
		processlist[ProssNO].processID = processID;
		processlist[ProssNO].func = function;
		processlist[ProssNO].periodisty = periodisty;
		processlist[ProssNO].priority = priority;
		ProssNO ++;
	}
}



void Schedualr_start(void)
{
	finish=1;
	STK_voidSetIntervalSingle(processlist[curentProcessNo].periodisty,processlist[curentProcessNo].func);

}


int main (){
	RCC_voidSysClkInt();

	RCC_voidEnablePerClk(RCC_APB2,2);

	/*	A5 Direction 	"Output @ 2MHz Push Pull"	*/
	DIO_voidSetPinDirection(PORTA,PIN5,GPIO_OUTPUT_2MHZ_PP);
	/*	A6 Direction 	"Output @ 2MHz Push Pull"	*/
	DIO_voidSetPinDirection(PORTA,PIN6,GPIO_OUTPUT_2MHZ_PP);
	/*	A7 Direction 	"Output @ 2MHz Push Pull"	*/
	DIO_voidSetPinDirection(PORTA,PIN7,GPIO_OUTPUT_2MHZ_PP);

	STK_voidInit();

	RTOS_voidCreateTask ( 1 ,process1 ,100000  , 0);
	RTOS_voidCreateTask ( 2 ,process2 ,200000  , 1);
	RTOS_voidCreateTask ( 3 ,process3 ,300000  , 2);
//	Schedualr();

	while(1)
	{
		if(curentProcessNo==ProssNO)
		{
				curentProcessNo=0;
		}
		if (finish==0)
		{
			Schedualr_start();
		}
	}
}



void process1(void)
{
	static u8 Local_u8LedState=0;
	TOG_BIT(Local_u8LedState , 0);
	DIO_voidSetPinValue(PORTA,PIN5,Local_u8LedState);

	curentProcessNo++;
	finish=0;
}
void process2(void)
{
	static u8 Local_u8LedState=0;
	TOG_BIT(Local_u8LedState , 0);
	DIO_voidSetPinValue(PORTA,PIN6,Local_u8LedState);

	curentProcessNo++;
	finish=0;
}
void process3(void)
{
	static u8 Local_u8LedState=0;
	TOG_BIT(Local_u8LedState , 0);
	DIO_voidSetPinValue(PORTA,PIN7,Local_u8LedState);

	curentProcessNo++;
	finish=0;
}









//
//int main (void)
//{
//		/*	System Clock Init			*/
//		RCC_voidSysClkInt();
//		/*	Enable RCC for GPIOC 		*/
//		RCC_voidEnablePerClk(RCC_APB2,4);
//		/*	Enable RCC for GPIOB 		*/
//		RCC_voidEnablePerClk(RCC_APB2,3);
//		/*	Enable RCC for GPIOA 		*/
//		RCC_voidEnablePerClk(RCC_APB2,2);
//
//
//		/*	A0 Direction 	"Output @ 2MHz Push Pull"	*/
//		DIO_voidSetPinDirection(PORTA,PIN0,GPIO_OUTPUT_2MHZ_PP);
//
//		/*	A1 Direction 	"Output @ 2MHz Push Pull"	*/
//		DIO_voidSetPinDirection(PORTA,PIN1,GPIO_OUTPUT_2MHZ_PP);
//
//		/*	A2 Direction 	"Output @ 2MHz Push Pull"	*/
//		DIO_voidSetPinDirection(PORTA,PIN2,GPIO_OUTPUT_2MHZ_PP);
//
////		/*	SysTick	Init				*/
////		STK_voidInit();
////
////		/*	Call Single Periodic 		*/
////		STK_voidSetIntervalPeriodic(1000000, ToggleLed);
//
//
//		RTOS_u8CreateTask(0 , 1000000 , &LED1 );
//		RTOS_u8CreateTask(1 , 2000000 , &LED2 );
//		RTOS_u8CreateTask(2 , 3000000 , &LED3 );
//
//		RTOS_voidStart();
//
//		while(1)
//		{
//			RTOS_voidStart();
//			asm("NOP");
//		}
//		return 0;
//
//
//}
//
//
//
//void LED1 (void)
//{
//	static u8 Local_u8LedState=0;
//	TOG_BIT(Local_u8LedState , 0);
//	DIO_voidSetPinValue(PORTA,PIN0,Local_u8LedState);
//
////	DIO_u8SetPinValue(DIO_u8PORTA , DIO_u8PIN0 , Local_u8LedState);
//}
//
//void LED2 (void)
//{
//	static u8 Local_u8LedState=0;
//	TOG_BIT(Local_u8LedState , 0);
//	DIO_voidSetPinValue(PORTA,PIN1,Local_u8LedState);
//
////	DIO_u8SetPinValue(DIO_u8PORTA , DIO_u8PIN1 , Local_u8LedState);
//}
//void LED3 (void)
//{
//	static u8 Local_u8LedState=0;
//	TOG_BIT(Local_u8LedState , 0);
//	DIO_voidSetPinValue(PORTA,PIN2,Local_u8LedState);
//
////	DIO_u8SetPinValue(DIO_u8PORTA , DIO_u8PIN2 , Local_u8LedState);
//}
//
//
//
//
//
//
//
//
//
