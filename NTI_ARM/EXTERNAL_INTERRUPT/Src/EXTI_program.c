#include "Std_Types.h"
#include "Bit_Math.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"




#ifndef		NULL
#define		NULL			((void *)0)
#endif


static	void	(*EXTI0_CallBack)	   (void)	= NULL;
static	void	(*EXTI1_CallBack)	   (void)	= NULL;
static	void	(*EXTI2_CallBack)  	   (void)	= NULL;
static	void	(*EXTI3_CallBack)	   (void)	= NULL;
static	void	(*EXTI4_CallBack)	   (void)	= NULL;
static	void	(*EXTI9_5_CallBack)	   (void)	= NULL;
static	void	(*EXTI15_10_CallBack)  (void)	= NULL;


void		EXTI_voidInit(u8 LineNum , u8 LinePort, u8 Initial_SenseMode)
{
	CLR_BIT(EXTI->IMR,LineNum);

	/* Clear the Flag */
	SET_BIT(EXTI->PR,LineNum);

	/* Select PortA for Line0 for EXT0 */

	#ifndef			AFIO_EXTICR1
		#define		AFIO_BASE_ADD	     	(0x40010000)
		#define		AFIO_EXTICR1			*((u32 *)(AFIO_BASE_ADD+0x08))
	#endif

	#ifndef			AFIO_EXTICR2
		#define		AFIO_BASE_ADD	     	(0x40010000)
		#define		AFIO_EXTICR2			*((u32 *)(AFIO_BASE_ADD+0x0C))
	#endif

	#ifndef			AFIO_EXTICR3
		#define		AFIO_BASE_ADD	     	(0x40010000)
		#define		AFIO_EXTICR3			*((u32 *)(AFIO_BASE_ADD+0x10))
	#endif

	#ifndef			AFIO_EXTICR4
		#define		AFIO_BASE_ADD	     	(0x40010000)
		#define		AFIO_EXTICR4			*((u32 *)(AFIO_BASE_ADD+0x14))
	#endif

	if (LineNum<4)
	{
		AFIO_EXTICR1 &=  ~(1<<4*LineNum);
		AFIO_EXTICR1 |=  (LinePort<<4*LineNum);
	}
	else if (LineNum<8)
	{
		LineNum-=4;
		AFIO_EXTICR2 &=  ~(1<<4*LineNum);
		AFIO_EXTICR2 |=  (LinePort<<4*LineNum);
	}
	else if (LineNum<12)
	{
		LineNum-=8;
		AFIO_EXTICR3 &=  ~(1<<4*LineNum);
		AFIO_EXTICR3 |=  (LinePort<<4*LineNum);
	}
	else if (LineNum<16)
	{
		LineNum-=12;
		AFIO_EXTICR4 &=  ~(1<<4*LineNum);
		AFIO_EXTICR4 |=  (LinePort<<4*LineNum);
	}

	EXTI_voidChangeSenseMode(LineNum, Initial_SenseMode);



}












void		EXTI_voidEnableInt(u8 line_num)
{
	SET_BIT(EXTI -> IMR,line_num);
}


void		EXTI_voidDisableInt(u8 line_num)
{
	CLR_BIT(EXTI -> IMR,line_num);
}


void		EXTI_voidEnableSWI(u8 line_num)
{
	SET_BIT(EXTI -> SWIER,line_num);
}


void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode)
{
	switch(Sense_Mode)
	{
		case	RISING_EDGE		:	SET_BIT(EXTI -> RTSR,line_num);
									CLR_BIT(EXTI -> FTSR,line_num);		break;
		case	FALLING_EDGE	:	SET_BIT(EXTI -> FTSR,line_num);
									CLR_BIT(EXTI -> RTSR,line_num);		break;
		case	IOC				:	SET_BIT(EXTI -> RTSR,line_num);
									SET_BIT(EXTI -> FTSR,line_num);		break;
	}
	SET_BIT(EXTI -> IMR,line_num);
}


/*****************************************************************************/
/*************************** Call Back Functions *****************************/

void		EXTI0_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI0_CallBack=Fptr;
	}
}


void		EXTI1_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI1_CallBack=Fptr;
	}
}


void		EXTI2_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI2_CallBack=Fptr;
	}
}


void		EXTI3_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI3_CallBack=Fptr;
	}
}


void		EXTI4_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI4_CallBack=Fptr;
	}
}


void		EXTI9_5_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI9_5_CallBack=Fptr;
	}
}


void		EXTI15_10_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI15_10_CallBack=Fptr;
	}
}





/*************************** End of the Functions *****************************/



/*****************************************************************************/
/******************************* ISR Functions *******************************/

void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	/*	Clear the Flag			*/
	SET_BIT(EXTI -> PR,0);
}


void	EXTI1_IRQHandler(void)
{
	EXTI1_CallBack();
	/*	Clear the Flag			*/
	SET_BIT(EXTI -> PR,1);
}


void	EXTI2_IRQHandler(void)
{
	EXTI2_CallBack();
	/*	Clear the Flag			*/
	SET_BIT(EXTI -> PR,2);
}


void	EXTI3_IRQHandler(void)
{
	EXTI3_CallBack();
	/*	Clear the Flag			*/
	SET_BIT(EXTI -> PR,3);
}


void	EXTI4_IRQHandler(void)
{
	EXTI4_CallBack();
	/*	Clear the Flag			*/
	SET_BIT(EXTI -> PR,4);
}


void	EXTI9_5_IRQHandler(void)
{
	EXTI9_5_CallBack();
	/*	Clear the Flag			*/
	SET_BIT(EXTI -> PR,5);
	SET_BIT(EXTI -> PR,6);
	SET_BIT(EXTI -> PR,7);
	SET_BIT(EXTI -> PR,8);
	SET_BIT(EXTI -> PR,9);

}


void	EXTI15_10_IRQHandler(void)
{
	EXTI15_10_CallBack();
	/*	Clear the Flag			*/
	SET_BIT(EXTI -> PR,10);
	SET_BIT(EXTI -> PR,11);
	SET_BIT(EXTI -> PR,12);
	SET_BIT(EXTI -> PR,13);
	SET_BIT(EXTI -> PR,14);
	SET_BIT(EXTI -> PR,15);


}
/*************************** End of the Functions *****************************/



