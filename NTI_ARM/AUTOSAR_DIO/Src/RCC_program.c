#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"RCC_interface.h"
#include	"RCC_private.h"
#include	"RCC_config.h"

void		RCC_voidSysClkInt(void)
{
	

/* Set Configuration Register Bits */
	RCC_CFGR |= SW;

	RCC_CFGR |= HPRE;
	RCC_CFGR |= PPRE1;
	RCC_CFGR |= PPRE2;
	RCC_CFGR |= ADCPRE;
	RCC_CFGR |= PLLSRC;
	RCC_CFGR |= PLLXTPRE;
	RCC_CFGR |= PLLMUL;
	RCC_CFGR |= USBPRE;
	RCC_CFGR |= MCO;



/* Select the Source of Clock */
	#if (CLK_SRC == HSI )
		SET_BIT(RCC_CR , HSION_BIT) ;
		while((GET_BIT(RCC_CR,HSIRDY_BIT))==0);

	#elif (CLK_SRC == HSE )
		SET_BIT(RCC_CR , HSEON_BIT) ;
		while((GET_BIT(RCC_CR,HSERDY_BIT))==0);

	#elif (CLK_SRC == PLL_HSI )
		SET_BIT(RCC_CR , HSION_BIT) ;
		while((GET_BIT(RCC_CR,HSIRDY_BIT))==0);
		SET_BIT(RCC_CR , PLLON_BIT) ;
		while((GET_BIT(RCC_CR,PLLRDY_BIT))==0);

	#elif (CLK_SRC == PLL_HSE )
		SET_BIT(RCC_CR , HSEON_BIT) ;
		while((GET_BIT(RCC_CR,HSERDY_BIT))==0);
		SET_BIT(RCC_CR , PLLON_BIT) ;
		while((GET_BIT(RCC_CR,PLLRDY_BIT))==0);

	#endif


}




void		RCC_voidEnablePerClk(u8 BusId , u8 PerId)
{
	/*		Range Check							*/
	if(PerId < 32)
	{
		switch(BusId)
		{
			case	RCC_AHB		:	SET_BIT(RCC_AHBENR,PerId) ;	break;
			case	RCC_APB1	:	SET_BIT(RCC_APB1ENR,PerId);	break;
			case	RCC_APB2	:	SET_BIT(RCC_APB2ENR,PerId);	break;
		}
		
	}
	else{	/*	Return Error "Out Of The Range"		*/	}
	
}



void		RCC_voidDisablePerClk(u8 BusId , u8 PerId)
{
	/*		Range Check							*/
	if(PerId < 32)
	{
		switch(BusId)
		{
			case	RCC_AHB		:	CLR_BIT(RCC_AHBENR,PerId) ;	break;
			case	RCC_APB1	:	CLR_BIT(RCC_APB1ENR,PerId);	break;
			case	RCC_APB2	:	CLR_BIT(RCC_APB2ENR,PerId);	break;
		}
		
	}
	else{	/*	Return Error "Out Of The Range"		*/	}	
}
