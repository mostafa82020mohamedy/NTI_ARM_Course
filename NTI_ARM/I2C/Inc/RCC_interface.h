#ifndef		RCC_INTERFACE_H
#define		RCC_INTERFACE_H

#define		RCC_AHB							0
#define		RCC_APB1						1
#define		RCC_APB2						2

#define 	 RCC_PLL						11
#define 	 RCC_HSI						22
#define 	 RCC_HSE						33
#define 	 SYS_CLK						44
#define 	 HSI_CLK						55
#define 	 HSE_CLK						66
#define 	 PLL_CLK 						77

void RCC_voidSysClkInt(void);
void RCC_voidEnablePerClk(u8 BusId, u8 PerId);
void RCC_voidDisablePerClk(u8 BusId, u8 PerId);

#endif
