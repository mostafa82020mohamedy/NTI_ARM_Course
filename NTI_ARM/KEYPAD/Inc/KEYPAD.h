/*
 * KEYPAD.h
 *
 * Created: 3/13/2023 10:47:58 PM
 *  Author: ahmed
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_
//include part
#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include    "DIO_interface.h"
//initialize function  
void KEYPAD_init(void );
//read function  
u8 KEYPAD_getpresskey();

#define KEY_PORT     PORTA


#endif /* KEYPAD_H_ */
