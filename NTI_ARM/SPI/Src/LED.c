#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"
#include "LED_interface.h"


/* Turn ON the Led */
 void Led_voidON (u8 LedPort  , u8 LedPin )
 {
	 DIO_voidSetPinValue(LedPort ,LedPin , GPIO_HIGH) ;

 }


 /* Turn OFF the Led */
 void Led_voidOFF (u8 LedPort  , u8 LedPin )
 {
	 DIO_voidSetPinValue(LedPort ,LedPin , GPIO_LOW) ;

 }


 /* Toggle the Led for Specific Duration */
 void Led_voidToggle (u8 LedPort  , u8 LedPin , u8 Duration )
 {
	 DIO_voidSetPinValue(LedPort ,LedPin , GPIO_HIGH) ;
	 _delay_ms(Duration);
	 DIO_voidSetPinValue(LedPort ,LedPin , GPIO_LOW) ;
 }
