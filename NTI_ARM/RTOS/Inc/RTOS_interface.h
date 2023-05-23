/*
 * RTOS_interface.h
 *
 *  Created on: 29 Mar 2023
 *      Author: mosta
 */

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_


void RTOS_voidStart(void);

void RTOS_voisSuspendTask(u8 Copy_u8Priority);

void RTOS_voisResumeTask(u8 Copy_u8Priority);

void RTOS_voidDeleteTask(u8 Copy_u8Priority);

u8 RTOS_u8CreateTask(u8 Copy_u8Priority , u32 Copy_u16Periodicity , void (*Copy_pvTaskFunc)(void)  , u16 Copy_u16FirstDelay);

//void voidScheduler(void);



#endif /* RTOS_INTERFACE_H_ */
