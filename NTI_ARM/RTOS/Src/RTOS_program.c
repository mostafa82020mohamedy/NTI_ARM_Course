///*
// * RTOS_program.c
// *
// *  Created on: 29 Mar 2023
// *      Author: mosta
// */
#include "Std_Types.h"
#include "Bit_Math.h"

#include "STK_interface.h"
#include "RTOS_private.h"
#include "RTOS_interface.h"
#include "RTOS_config.h"
//
//Task_t System_Tasks[TASK_NUM]={{NULL}};
//
//void RTOS_voidStart(void)
//{
////	Timer0_u8CompMatchSetCallBack(& voidScheduler);
////	GIE_voidEnable();
////	Timer0_voidInit();
//
////	STK_voidSetIntervalPeriodic(1000000, & voidScheduler);
//	STK_voidInit();
//	STK_voidSetIntervalPeriodic(1000000,  voidScheduler);
//
//
//
//
//}
//
//
//
//u8 RTOS_u8CreateTask(u8 Copy_u8Priority , u32 Copy_u16Periodicity , void (*Copy_pvTaskFunc)(void)  )
//{
//	u8 Local_u8ErrorState=OK;
//
//	/* Check if the Required Priority is Empty or Used Before for Another Task */
//	if((System_Tasks[Copy_u8Priority].TaskFunc)==NULL)
//	{
//		System_Tasks[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
//		System_Tasks[Copy_u8Priority].TaskFunc=Copy_pvTaskFunc;
//		System_Tasks[Copy_u8Priority].State=TASK_RESUMED;        /* Initialise Task State */
//	}
//	else
//	{
//		/* Priority is Reserved Before for Another Task, Don't Create the Task */
//		Local_u8ErrorState=NOK;
//	}
//
//	return Local_u8ErrorState;
//}
//
//
//
//void RTOS_voidDeleteTask(u8 Copy_u8Priority)
//{
//	System_Tasks[Copy_u8Priority].TaskFunc=NULL;
//}
//
//
//void RTOS_voisSuspendTask(u8 Copy_u8Priority)
//{
//	System_Tasks[Copy_u8Priority].State =TASK_SUSPENDED;
//}
//
//
//
//void RTOS_voisResumeTask(u8 Copy_u8Priority)
//{
//	System_Tasks[Copy_u8Priority].State =TASK_RESUMED;
//}
//
//
//
//void voidScheduler(void)
//{
//	static u16 Local_u16TickCounter=0;
//	u8 Local_u8TaskCounter;
//
//	Local_u16TickCounter++;
//
//	/* Loop on all tasks to check Periodicity */
//	for(Local_u8TaskCounter=0 ;Local_u8TaskCounter<TASK_NUM  ; Local_u8TaskCounter++ )
//	{
//		if ((Local_u16TickCounter%System_Tasks[Local_u8TaskCounter].Periodicity)==0)
//		{
//			/* Invoke the Task Function */
//			if(System_Tasks[Local_u8TaskCounter].TaskFunc !=NULL)
//			{
//				System_Tasks[Local_u8TaskCounter].TaskFunc();
//
//			}
//		}
//	}
//}
