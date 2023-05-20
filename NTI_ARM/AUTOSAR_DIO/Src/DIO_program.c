#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"DIO_interface.h"
#include	"DIO_private.h"
#include	"DIO_config.h"




void	DIO_voidSetPinValue(u8 port, u8 pin, u8 Value)
{
	/*		Range Check 		*/
	if(port < 3 && pin < 16)
	{
		if(Value == GPIO_HIGH)
		{
			switch(port)
			{
				case	PORTA	:   GPIOA_BSRR = (1<<pin);	break;
				case	PORTB	:   GPIOB_BSRR = (1<<pin);	break;
				case	PORTC	:   GPIOC_BSRR = (1<<pin);	break;
			}
		}
		else if(Value == GPIO_LOW)
		{
			switch(port)
			{
				case	PORTA	:   GPIOA_BRR = (1<<pin);	break;
				case	PORTB	:   GPIOB_BRR = (1<<pin);	break;
				case	PORTC	:   GPIOC_BRR = (1<<pin);	break;
			}			
		}
		
	}
	else
	{
		/* ERROR*/
	}
	
}
/************************** The  Function End *********************************/
/******************************************************************************/



u8		DIO_u8GetPinValue(u8 port, u8 pin)
{
	u8	Local_u8Val = 0x99;
	/*		Range Check 		*/
	if(port < 3 && pin < 16)
	{

			switch(port)
			{
				case	PORTA	:	Local_u8Val	=	GET_BIT(GPIOA_IDR,pin);	break;
				case	PORTB	:	Local_u8Val	=	GET_BIT(GPIOB_IDR,pin);	break;
				case	PORTC	:	Local_u8Val	=	GET_BIT(GPIOC_IDR,pin);	break;
			}
	}
	else
	{
		Local_u8Val = 0;
	/*	Return Error	*/
	}
	return Local_u8Val;
}
/************************** The  Function End *********************************/
/******************************************************************************/



/* ************************************************************** */
void DIO_voidSetPortValue(u8 Copy_u8Port , u32 Copy_u8Value)
{
	switch (Copy_u8Port)
		{
			case PORTA : GPIOA_ODR = Copy_u8Value; break;
			case PORTB : GPIOB_ODR = Copy_u8Value; break;
			case PORTC : GPIOC_ODR = Copy_u8Value; break;
		}
}
/************************** The  Function End *********************************/
/******************************************************************************/



/******************************************************************************/
/* This Function is to Set The Direction of All Pins and Their Initial Values */

void DIO_voidPinsInit(void)
{

	/* Set Directions  for All Pins */
	GPIOA_CRL=PORTA_CRL_DIR;
	GPIOA_CRH=PORTA_CRH_DIR;

	GPIOB_CRL=PORTB_CRL_DIR;
	GPIOB_CRH=PORTB_CRH_DIR;

	GPIOC_CRH=PORTC_CRH_DIR;


	/* Set Initial Value  for All Pins */
	GPIOA_ODR=PORTA_INITIAL_VALUE;
	GPIOB_ODR=PORTB_INITIAL_VALUE;
	GPIOC_ODR=PORTC_INITIAL_VALUE;


}
/************************** The  Function End *********************************/
/******************************************************************************/
