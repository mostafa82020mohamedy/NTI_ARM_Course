/*
 * LED.c
 *
 * Created: 3/3/2023 3:09:58 PM
 *  Author: ahmed
 */

//including part  
#include "LED.h"

 //initialize function

 void LED_init(u8 ledport  , u8 ledpin) {
	 DIO_voidSetPinDirection(ledport , ledpin, GPIO_OUTPUT_2MHZ_PP) ;
 }

 //function to on led

 void LED_on (u8 ledport  , u8 ledpin ) {
	 DIO_voidSetPinValue(ledport ,ledpin , GPIO_HIGH) ;
	 
 }

 //function to led off

void LED_off (u8 ledport , u8 ledpin ) {
	DIO_voidSetPinValue(ledport , ledpin ,GPIO_LOW) ;
}

 //toggle led function

/* void LED_togg (u8 ledport , u8 ledpin ){
	 DIO_togglepin(ledport ,ledpin ) ; 
 }*/
