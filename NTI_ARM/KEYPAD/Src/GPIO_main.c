#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include    "DIO_interface.h"
#include    "delay.h"
#include    "LED.h"
#include    "BUTTON.h"
#include 	"LCD4BIT.h"
#include 	"KEYPAD.h"



/*	C13 ==> Built in led (Toggle Led)		*/
int main()
{
	u8 local = 0xff ;
	/*	System Clock Init			*/
	RCC_voidSysClkInt();
	/*	Enable RCC for GPIOC 		*/
	RCC_voidEnablePerClk(RCC_APB2,2);
	RCC_voidEnablePerClk(RCC_APB2,3);
	RCC_voidEnablePerClk(RCC_APB2,4);
	
	/*	C13 Direction 	"Output @ 2MHz Push Pull"	*/
	LCD_init() ;
	KEYPAD_init() ;



	while(1)
	{
		/*		Led On		*/
		if(local == 0xff)
		{
			local= KEYPAD_getpresskey() ;
			if(local != 0xff)
			{
				LCD_writechar(local) ;
			}
		}else{local = 0xff;}

	}
	return 0;
}



