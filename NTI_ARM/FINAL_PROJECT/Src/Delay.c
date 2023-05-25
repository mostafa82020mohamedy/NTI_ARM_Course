/*
 * Delay.c
 *
 *  Created on: May 5, 2023
 *      Author: ahmed saad
 */

#include "Std_Types.h"
#include "Delay.h"

void  _delay_ms(u32 ticks)
{
	u32 i;
	for( i = 0; i < (ticks * 500) ; i++)
	{
		asm("NOP");
	}
}
