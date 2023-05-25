/*
 * led.c
 *
 * Created: 12/12/2022 9:06:40 PM
 *  Author: ahmed saad
 */ 
#include "led.h"
void LED_init(u8 portName,u8 pinNumber)
{
	DIO_voidSetPinDirection(portName,pinNumber,GPIO_OUTPUT_2MHZ_PP);
}
void LED_on(u8 portName,u8 pinNumber)
{
	DIO_voidSetPinValue(portName,pinNumber,GPIO_HIGH);
}
void LED_off(u8 portName,u8 pinNumber)
{
	DIO_voidSetPinValue(portName,pinNumber,GPIO_LOW);
}
/*void LED_toggle(u8 portName,u8 pinNumber)
{
	DIO_toggle(pinNumber,portName);
}*/
