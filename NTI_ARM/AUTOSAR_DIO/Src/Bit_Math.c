#include "Std_Types.h"
#include "Bit_Math.h"

void	_delay_ms(u32 ticks){
	u32 i;
	for( i = 0; i < (ticks * 500) ; i++)
	{
		asm("NOP");
	}
}
