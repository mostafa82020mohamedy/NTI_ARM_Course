/*
 * led.h
 *
 * Created: 12/12/2022 9:06:31 PM
 *  Author: ahmed saad
 */ 


#ifndef LED_H_
#define LED_H_

#include "DIO_interface.h"
void LED_init(u8 portName,u8 pinNumber);
void LED_on(u8 portName,u8 pinNumber);
void LED_off(u8 portName,u8 pinNumber);
void LED_toggle(u8 portName,u8 pinNumber);



#endif /* LED_H_ */
