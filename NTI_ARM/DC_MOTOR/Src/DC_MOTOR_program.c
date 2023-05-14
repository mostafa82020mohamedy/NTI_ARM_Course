/*
 * DC_MOTOR_program.c
 *
 *  Created on: 12 Feb 2023
 *      Author: mosta
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DC_MOTOR_config.h"
#include "DC_MOTOR_private.h"
#include "DC_MOTOR_interface.h"


void DC_MOTOR_voidRotateCW(void)
{
	DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOW);
	DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN0,HIGH);
}

void DC_MOTOR_voidRotateCounterCW(void)
{
	DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN0,LOW);
	DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN1,HIGH);
}

void DC_MOTOR_voidBreak(void)
{
	DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN0,LOW);
	DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOW);
}


