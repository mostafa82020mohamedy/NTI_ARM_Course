/*
 * RTOS_program.c
 *
 *  Created on: 29 Mar 2023
 *      Author: mosta
 */
#include "Std_Types.h"
#include "Bit_Math.h"

#include "STK_interface.h"
#include "RTOS_private.h"
#include "RTOS_interface.h"
#include "RTOS_config.h"

	//static u16 Local_u16TickCounter=0;


static Task_t System_Tasks[TASK_NUM]={{NULL}};

void RTOS_voidStart(void)
{
//	Timer0_u8CompMatchSetCallBack(& voidScheduler);
//	GIE_voidEnable();
//	Timer0_voidInit();

	STK_voidInit();
	STK_voidSetIntervalPeriodic(1000,  voidScheduler);




}



u8 RTOS_u8CreateTask(u8 Copy_u8Priority , u32 Copy_u16Periodicity , void (*Copy_pvTaskFunc)(void)  , u16 Copy_u16FirstDelay)
{
	u8 Local_u8ErrorState=OK;

	/* Check if the Required Priority is Empty or Used Before for Another Task */
	if((System_Tasks[Copy_u8Priority].TaskFunc)==NULL)
	{
		System_Tasks[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
		System_Tasks[Copy_u8Priority].TaskFunc=Copy_pvTaskFunc;
		System_Tasks[Copy_u8Priority].State=TASK_RESUMED;        /* Initialise Task State */
		System_Tasks[Copy_u8Priority].FirstDelay=Copy_u16FirstDelay;
	}
	else
	{
		/* Priority is Reserved Before for Another Task, Don't Create the Task */
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}



void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	System_Tasks[Copy_u8Priority].TaskFunc=NULL;
}


void RTOS_voisSuspendTask(u8 Copy_u8Priority)
{
	System_Tasks[Copy_u8Priority].State =TASK_SUSPENDED;
}



void RTOS_voisResumeTask(u8 Copy_u8Priority)
{
	System_Tasks[Copy_u8Priority].State =TASK_RESUMED;
}






static void voidScheduler(void)
{
	/* for loop to check on every TCB */
	u8 counter;
	for(counter = 0; counter < TASK_NUM ; counter++)
	{


		if((System_Tasks[counter].FirstDelay) == 0)
		{
			//Call function
			System_Tasks[counter].TaskFunc();

			System_Tasks[counter].FirstDelay =System_Tasks[counter].Periodicity-1;
		}
		else
		{
			System_Tasks[counter].FirstDelay--;
		}
	}

}
