#include "Std_Types.h"
#include "Bit_Math.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "LED_interface.h"

int main(){

	/* System Clock Initialisation */
	RCC_voidSysClkInt();

	/* Enable RCC for GPIOC */
	RCC_voidEnablePerClk(RCC_APB2, 4);
	/* Enable RCC for GPIOB */
	RCC_voidEnablePerClk(RCC_APB2, 3);
	/* Enable RCC for GPIOA */
	RCC_voidEnablePerClk(RCC_APB2, 2);

	DIO_voidPinsInit();


		while (1)
		{

			Led_voidON(PORTA, PIN0 );
			Led_voidOFF(PORTA, PIN1);
			Led_voidOFF(PORTA, PIN2);
			_delay_ms(1000);
			Led_voidON(PORTA, PIN0 );
			Led_voidON(PORTA, PIN1 );
			Led_voidOFF(PORTA, PIN2);
			_delay_ms(1000);
			Led_voidON(PORTA, PIN0 );
			Led_voidON(PORTA, PIN1 );
			Led_voidON(PORTA, PIN2 );
			_delay_ms(1000);
		}

	return 0;
}

