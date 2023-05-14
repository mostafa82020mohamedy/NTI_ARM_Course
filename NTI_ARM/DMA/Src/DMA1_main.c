#include "Std_Types.h"
#include "Bit_Math.h"

#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "DMA_interface.h"




u32	Processor_Arr1[1000];
u32	Processor_Arr2[1000];

u32	DMA_Arr3[1000];
u32	DMA_Arr4[1000];


int main()
{
	for(u16 i = 0 ; i < 1000 ; i++)
	{
		Processor_Arr1[i]	=	i;
		DMA_Arr3[i]			=	i;
	}
	
	/*	System init			*/
	RCC_voidSysClkInt();
	RCC_voidEnablePerClk(RCC_AHB, 0);

	NVIC_voidEnablePerInt(11);

	DMA1_voidChannelInit();
	/*	DMA1 Channel Transfere Round	*/
	DMA1_voidStartChannel(DMA_Arr3, DMA_Arr4, 1000);
	

	/*	Processor Transfere Round	*/
	for(u16 i = 0 ; i < 1000 ; i++)
	{
		Processor_Arr2[i]	=	Processor_Arr1[i];
	}
	
	

while(1)
{

}

return 0;
}

void	DMA1_Channel1_IRQHandler()
{
	/*		Toggle led		*/
	u8 x=100;
	GET_BIT(x , 1);
}
