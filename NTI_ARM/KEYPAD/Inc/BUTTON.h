/*
 * BUTTON.h
 *
 * Created: 3/4/2023 4:16:42 PM
 *  Author: ahmed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
//INCLUDE PART 
#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include    "DIO_interface.h"
#include    "delay.h"
//prototype PART 

//initialized function 

void BUTTON_init (u8 buttonport , u8 buttonpin ) ;

//read value from button function 

u8 BUTTON_read(u8 buttonport , u8 buttonpin );



#endif /* BUTTON_H_ */
