/*
 * BOTTUN.c
 *
 * Created: 3/4/2023 4:17:21 PM
 *  Author: ahmed
 */ 

//INCLUDE PART   

#include "BUTTON.h"

//initialized function

void BUTTON_init (u8 buttonport , u8 buttonpin ) {
	DIO_voidSetPinDirection(buttonport ,buttonpin , GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue(buttonport,buttonpin ,GPIO_HIGH);
}

//read value from button function

u8 BUTTON_read(u8 buttonport , u8 buttonpin ){
	return DIO_u8GetPinValue(buttonport , buttonpin) ;
}

