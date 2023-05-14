/*
 * KEYPAD.c
 *
 * Created: 3/13/2023 10:48:13 PM
 *  Author: ahmed
 */ 

//include part 
#include "KEYPAD.h"
#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include    "DIO_interface.h"
#include    "delay.h"
//initialize function
void KEYPAD_init(void){
	DIO_voidSetPinDirection(KEY_PORT , PIN0 , GPIO_OUTPUT_2MHZ_PP ) ;
	DIO_voidSetPinDirection(KEY_PORT, PIN1 , GPIO_OUTPUT_2MHZ_PP ) ;
	DIO_voidSetPinDirection(KEY_PORT , PIN2 , GPIO_OUTPUT_2MHZ_PP ) ;
	DIO_voidSetPinDirection(KEY_PORT , PIN3 , GPIO_OUTPUT_2MHZ_PP ) ;
	DIO_voidSetPinDirection(KEY_PORT, PIN4 , GPIO_INPUT_PULL_UP_DOWN ) ;
	DIO_voidSetPinDirection(KEY_PORT , PIN5 , GPIO_INPUT_PULL_UP_DOWN ) ;
	DIO_voidSetPinDirection(KEY_PORT, PIN6 , GPIO_INPUT_PULL_UP_DOWN ) ;
	DIO_voidSetPinDirection(KEY_PORT , PIN7 , GPIO_INPUT_PULL_UP_DOWN ) ;
	//TURN PULL UP RESISTANCE 
	DIO_voidSethlafPortval(KEY_PORT, 0xFF) ;
}

const u8 keypad[4][4] ={
	{'D','#','0','*'},
	{'C','9','8','7'},
	{'B','6','5','4'},
	{'A','3','2','1'},
	};
//read function
u8 KEYPAD_getpresskey(void){
	 u8 row = 4 ;
  	 u8 colm=0  ;
 	volatile u8 Local_preeskey = 0XFF;
	for (colm=0 ;colm<4 ; colm++)
	{
		DIO_voidSetPinValue(KEY_PORT, colm ,GPIO_LOW) ;
		for (row=4;row<8;row++)
		{
		 if (DIO_u8GetPinValue(KEY_PORT,row)==0)
		 {
			 Local_preeskey = keypad[row-4][colm] ;
             _delay_ms(500) ;
		 }
		}
		DIO_voidSetPinValue(KEY_PORT, colm , GPIO_HIGH) ;
		
	}
	return Local_preeskey  ;
}

