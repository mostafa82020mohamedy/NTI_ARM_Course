#ifndef		RCC_INTERFACE_H
#define		RCC_INTERFACE_H

#define		RCC_AHB				0
#define		RCC_APB1			1
#define		RCC_APB2			2

void		RCC_voidSysClkInt(void);
void		RCC_voidEnablePerClk(u8 BusId , u8 PerId);
void		RCC_voidDisablePerClk(u8 BusId , u8 PerId);


/********************************************************/
/* Control Register Bits */
#define     HSION_BIT           0
#define     HSIRDY_BIT          1
#define     HSEON_BIT           16
#define     HSERDY_BIT          17
#define     HSEBYP_BIT          18
#define     CSSON_BIT           19
#define     PLLON_BIT           24
#define     PLLRDY_BIT          25
/**********************************************************/







#endif
