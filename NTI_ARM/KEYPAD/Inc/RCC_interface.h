#ifndef		RCC_INTERFACE_H
#define		RCC_INTERFACE_H

#define		RCC_AHB				0
#define		RCC_APB1			1
#define		RCC_APB2			2

void		RCC_voidSysClkInt(void);
void		RCC_voidEnablePerClk(u8 BusId , u8 PerId);
void		RCC_voidDisablePerClk(u8 BusId , u8 PerId);

#endif