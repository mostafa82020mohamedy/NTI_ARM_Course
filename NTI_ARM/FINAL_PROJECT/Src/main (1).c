/*
 ***************This Project is a Traffic Light******************
 Components:
 	 	 	 1-STM32F103C8T6
 	 	 	 2-LCD
 	 	 	 3-7SEGMENTS
 	 	 	 4-IR SENSOR
 	 	 	 5-LEDS
/* Skeleton
	1- we initialise Leds for both vehicles and pedestrians
	2- we initialise external interrupt 0 for pedestrian cross walk
	3- we initialise Systick for making delay 2 seconds
	4- we initialise 7 Segment for counting down every 2 seconds
	5- we initialise LCD for Displaying
 * */



#include "Std_Types.h"
#include "Bit_Math.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include"NVIC_interface.h"
#include"EXTI_interface.h"
#include "Delay.h"
#include "led.h"
#include "sev_seg.h"
#include "lcd.h"

u8 *Sent="CROSS THE STREET";
u8 count=0,tick=10;
void fun_Stk_Handler(void);
void fun_EXTI0_Handler(void);
int main()
{
	/* INTERNAL SYSTEM CLOCK --> 8MHZ */
	RCC_PARAMETER_t par;
	par.HSI_Activation=HSI_ON;
	par.Clk_Source=CLK_HSI;
	RCC_voidSysClkInt(par);
	/* ENABLE CLOCK FOR GPIOA */
	RCC_voidEnablePerClk(RCC_APB2,2);
	/* ENABLE CLOCK FOR GPIOB */
	RCC_voidEnablePerClk(RCC_APB2,3);
	/* ENABLE CLOCK FOR GPIOC */
	RCC_voidEnablePerClk(RCC_APB2,4);
	/* ENABLE CLOCK FOR Alternate Function "External Interrupt" */
	RCC_voidEnablePerClk(RCC_APB2,0);

	/* LCD Init */
	LCD_Init();

	/* LED INTIALIZATION FOR VEHICLES */
	LED_init(PORTB, PIN12);  //LED GREEN
	LED_init(PORTB, PIN13);  //LED YELLOW
	LED_init(PORTA, PIN3);  //LED RED
	/* LED INTIALIZATION FOR PEDSTRIAN */
	LED_init(PORTC, PIN13);  //LED RED
	LED_init(PORTC, PIN14);  //LED YELLOW
	LED_init(PORTC, PIN15);  //LED GREEN
	/* LED OFF */
	LED_off(PORTB, PIN12);
	LED_off(PORTB, PIN13);
	LED_off(PORTA, PIN3);
	LED_off(PORTC, PIN13);
	LED_off(PORTC, PIN14);
	LED_off(PORTC, PIN15);

	/* SEVEN SEGMENT INTIALIZATION */
	SEV_SEG_Init();
	/* SEVEN SEGMENT OFF */
	SEV_SEG_Display(10);

	/* INTIALIZE SYSTEM TICK */
	STK_voidInit();
	STK_voidSetIntervalPeriodic(2000000, fun_Stk_Handler);

	/* EXTI0 ON PORTA" Falling Edge" */
	DIO_voidSetPinValue(PORTA, PIN0,GPIO_HIGH);
	NVIC_voidInit();
	EXTI_voidInit(EXTI0,EXTI_PORTA);
	EXTI_voidChangeSenseMode(EXTI0,FALLING_EDGE);
	NVIC_voidEnablePerInt(6);
	EXTI0_voidSetCallBack(fun_EXTI0_Handler);

	while(1)
	{
		if(count>=1 && count<=10) /* GREEN LED ON FOR CARS  - Red LED ON FOR PEDSTRIAN*/
		{
			LED_on(PORTB, PIN12);
			LED_off(PORTB, PIN13);
			LED_off(PORTA, PIN3);
			LED_on(PORTC, PIN13);
			LED_off(PORTC, PIN14);
			LED_off(PORTC, PIN15);

			SEV_SEG_Display(tick);
		}
		else if(count>=11 && count<=16) /* YELLOW LED ON FOR CARS and PEDSTRIAN */
		{

			LED_off(PORTB, PIN12);
			LED_on(PORTB, PIN13);
			LED_off(PORTA, PIN3);
			LED_off(PORTC, PIN13);
			LED_on(PORTC, PIN14);
			LED_off(PORTC, PIN15);

			SEV_SEG_Display(tick);
		}
		else if(count>=17 && count<=26) /* RED LED ON FOR CARS  - GREEN LED ON FOR PEDSTRIAN*/
		{
			LED_off(PORTB, PIN12);
			LED_off(PORTB, PIN13);
			LED_on(PORTA, PIN3);
			LED_off(PORTC, PIN13);
			LED_off(PORTC, PIN14);
			LED_on(PORTC, PIN15);

			SEV_SEG_Display(tick);
			_delay_ms(2000);


		}
		else if(count>=27 && count<=32)  /* YELLOW LED ON FOR CARS and PEDSTRIAN */
		{
			LED_off(PORTB, PIN12);
			LED_on(PORTB, PIN13);
			LED_off(PORTA, PIN3);
			LED_off(PORTC, PIN13);
			LED_on(PORTC, PIN14);
			LED_off(PORTC, PIN15);
			SEV_SEG_Display(tick);

			_delay_ms(2000);

		}

		if (count==17)
		{
			LCD_Clear();
			LCD_Write_AtPosition(1,0);
			LCD_Write_String(Sent);
		}
		if(count==27)
			LCD_Clear();
	}
	return 1;
}

/* System tick handler function */
void fun_Stk_Handler()
{
	if(count>=1 && count<=10 && tick==0)
		tick=6;
	else if(count>=11 && count<=16 && tick==0)
		tick=10;
	else if(count>=17 && count<=26 && tick==0)
		tick=6;
	else if(count>=27 && count<=32 && tick==0)
		tick=10;
	if(count==32)
	{
		count=0;
	}
	count++;
	tick--;
}

/* External Interrupt0 handler function */
void fun_EXTI0_Handler(void)
{
	if(count>=1 && count<=10 )
	{
		count=11;
		tick=5;
	}

}
