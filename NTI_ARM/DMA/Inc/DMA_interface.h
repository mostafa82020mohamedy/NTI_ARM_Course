#ifndef		DMA_INTERFACE_H
#define		DMA_INTERFACE_H



void	DMA1_voidChannelInit();
void	DMA1_voidStartChannel(u32 * SrcAdd,u32 * DestAdd,u16 BlockLength);



#endif
