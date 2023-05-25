
#include	"Std_Types.h"
#include	"Bit_Math.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"

#ifndef		NULL
#define		NULL			((void *)0)
#endif


static	void	(*EXTI0_CallBack)	   (void)	= NULL;
static	void	(*EXTI1_CallBack)	   (void)	= NULL;
static	void	(*EXTI2_CallBack)	   (void)	= NULL;
static	void	(*EXTI3_CallBack)	   (void)	= NULL;
static	void	(*EXTI4_CallBack)	   (void)	= NULL;
static	void	(*EXTI5_CallBack)	   (void)	= NULL;
static	void	(*EXTI6_CallBack)	   (void)	= NULL;
static	void	(*EXTI7_CallBack)	   (void)	= NULL;
static	void	(*EXTI8_CallBack)	   (void)	= NULL;
static	void	(*EXTI9_CallBack)	   (void)	= NULL;
static	void	(*EXTI10_CallBack)	   (void)	= NULL;
static	void	(*EXTI11_CallBack)	   (void)	= NULL;
static	void	(*EXTI12_CallBack)	   (void)	= NULL;
static	void	(*EXTI13_CallBack)	   (void)	= NULL;
static	void	(*EXTI14_CallBack)	   (void)	= NULL;
static	void	(*EXTI15_CallBack)	   (void)	= NULL;

void		EXTI_voidEnableInt(EXT_INT_option option);
void        EXTI_voidInit(EXT_INT_option option,EXT_INT_port port)
{
#ifndef			AFIO_EXTICR
		#define		AFIO_BASE_ADD	     	(0x40010000)
		#define		AFIO_EXTICR1			*((u32 *)(AFIO_BASE_ADD+0x08))
		#define		AFIO_EXTICR2			*((u32 *)(AFIO_BASE_ADD+0x0C))
		#define		AFIO_EXTICR3			*((u32 *)(AFIO_BASE_ADD+0x10))
		#define		AFIO_EXTICR4			*((u32 *)(AFIO_BASE_ADD+0x14))
	#endif
	EXTI_voidEnableInt(option);
	switch(option)
	{
	case EXTI0 :
		    if(port==EXTI_PORTA)
		    {
		    	AFIO_EXTICR1=0X0000;
		    }
		    else if(port==EXTI_PORTB)
		    {
		    	AFIO_EXTICR1=0X0001;
		    }
		    break;
	case EXTI1 :
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR1=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR1=0X0010;
			}
			break;
	case EXTI2 :
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR1=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR1=0X0100;
			}
			break;
	case EXTI3 :
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR1=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR1=0X1000;
			}
			break;
	case EXTI4 :
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR2=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR2=0X0001;
			}
		break;
	case EXTI5:
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR2=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR2=0X0010;
			}
			break;
	case EXTI6:
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR2=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR2=0X0100;
			}
			break;
	case EXTI7:
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR2=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR2=0X1000;
			}
			break;
	case EXTI8:
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR3=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR3=0X0001;
			}
			break;
	case EXTI9:
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR3=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR3=0X0010;
			}
			break;
	case EXTI10:
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR3=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR3=0X0100;
			}
			break;
	case EXTI11:
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR3=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR3=0X1000;
			}
			break;
	case EXTI12:
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR4=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR4=0X0001;
			}
			break;
	case EXTI13:
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR4=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR4=0X0010;
			}
			else if(port==EXTI_PORTC)
			{
				AFIO_EXTICR4=0X0020;
			}
			break;
	case EXTI14:
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR4=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR4=0X0100;
			}
			else if(port==EXTI_PORTC)
			{
				AFIO_EXTICR4=0X0200;
			}
			break;
	case EXTI15:
			if(port==EXTI_PORTA)
			{
				AFIO_EXTICR4=0X0000;
			}
			else if(port==EXTI_PORTB)
			{
				AFIO_EXTICR4=0X1000;
			}
			else if(port==EXTI_PORTC)
			{
				AFIO_EXTICR4=0X2000;
			}
			break;
	}

}
void		EXTI_voidEnableInt(EXT_INT_option option)
{
	SET_BIT(EXTI -> IMR,option);
}
void		EXTI_voidDisableInt(EXT_INT_option option)
{
	CLR_BIT(EXTI -> IMR,option);
}

void		EXTI_voidEnableSWI(EXT_INT_option option)
{
	SET_BIT(EXTI -> SWIER,option);
}
void		EXTI_voidChangeSenseMode(EXT_INT_option option, EXT_INT_sense Sense_Mode)
{
	switch(Sense_Mode)
	{
		case	RISING_EDGE		:	SET_BIT(EXTI -> RTSR,option);
									CLR_BIT(EXTI -> FTSR,option);		break;
		case	FALLING_EDGE	:	SET_BIT(EXTI -> FTSR,option);
									CLR_BIT(EXTI -> RTSR,option);		break;
		case	IOC				:	SET_BIT(EXTI -> RTSR,option);
									SET_BIT(EXTI -> FTSR,option);		break;
	}
	SET_BIT(EXTI -> IMR,option);
}

void		  EXTI0_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI0_CallBack= Fptr  ;
	}
}
void		  EXTI1_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI1_CallBack= Fptr  ;
	}
}
void		  EXTI2_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI2_CallBack= Fptr  ;
	}
}
void		  EXTI3_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI3_CallBack= Fptr  ;
	}
}
void		  EXTI4_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI4_CallBack= Fptr  ;
	}
}
void		  EXTI5_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI5_CallBack= Fptr  ;
	}
}
void		  EXTI6_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI6_CallBack= Fptr  ;
	}
}
void		  EXTI7_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI7_CallBack= Fptr  ;
	}
}
void		  EXTI8_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI8_CallBack= Fptr  ;
	}
}
void		  EXTI9_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI9_CallBack= Fptr  ;
	}
}
void		  EXTI10_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI10_CallBack= Fptr  ;
	}
}
void		  EXTI11_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI11_CallBack= Fptr  ;
	}
}
void		  EXTI12_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI12_CallBack= Fptr  ;
	}
}
void		  EXTI13_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI13_CallBack= Fptr  ;
	}
}
void		  EXTI14_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI14_CallBack= Fptr  ;
	}
}
void		  EXTI15_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI15_CallBack= Fptr  ;
	}
}


void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	SET_BIT(EXTI -> PR,0);
	//	Clear the Flag
}
void	EXTI1_IRQHandler(void)
{
	EXTI1_CallBack();
	SET_BIT(EXTI -> PR,1);
	/*	Clear the Flag			*/
}
void	EXTI2_IRQHandler(void)
{
	EXTI2_CallBack();
	SET_BIT(EXTI -> PR,2);
	/*	Clear the Flag			*/
}
void	EXTI3_IRQHandler(void)
{
	EXTI3_CallBack();
	SET_BIT(EXTI -> PR,3);
	/*	Clear the Flag			*/
}
void	EXTI4_IRQHandler(void)
{
	EXTI4_CallBack();
	SET_BIT(EXTI -> PR,4);
	/*	Clear the Flag			*/
}
void	EXTI9_5_IRQHandler(void)
{
	if(GET_BIT(EXTI -> PR,5) == 1)
	{
		EXTI5_CallBack();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,5);
	}
	if(GET_BIT(EXTI -> PR,6) == 1)
	{
		EXTI6_CallBack();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,6);
	}
	if(GET_BIT(EXTI -> PR,7) == 1)
	{
		EXTI7_CallBack();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,7);
	}
	if(GET_BIT(EXTI -> PR,8) == 1)
	{
		EXTI8_CallBack();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,8);
	}
	if(GET_BIT(EXTI -> PR,9) == 1)
	{
		EXTI9_CallBack();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,9);
	}
}
void	EXTI15_10_IRQHandler(void)
{
	if(GET_BIT(EXTI -> PR,10) == 1)
	{
		EXTI10_CallBack();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,10);
	}
	if(GET_BIT(EXTI -> PR,11) == 1)
	{
		EXTI11_CallBack();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,11);
	}
	if(GET_BIT(EXTI -> PR,12) == 1)
	{
		EXTI12_CallBack();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,12);
	}
	if(GET_BIT(EXTI -> PR,13) == 1)
	{
		EXTI13_CallBack();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,13);
	}
	if(GET_BIT(EXTI -> PR,14) == 1)
	{
		EXTI14_CallBack();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,14);
	}
	if(GET_BIT(EXTI -> PR,15) == 1)
	{
		EXTI15_CallBack();
		/*	Clear the Flag			*/
		SET_BIT(EXTI -> PR,15);
	}
}


