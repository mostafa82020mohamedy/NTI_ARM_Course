#include "Std_Types.h"
#include "Bit_Math.h"

#include "DMA_interface.h"
#include "DMA_private.h"





void	DMA1_voidChannelInit()
{
	/*
	Memory to Memory
	priority very high
	Size (Source & Destination) u32
	MINC, PINC enabled
	Direction read from Peripheral
	Transfere Complete Interrupt
	Channel Disable
	*/
	DMA1 ->	Channel[0].CCR = 0x00007AC2;
}



void	DMA1_voidStartChannel(u32 * SrcAdd,u32 * DestAdd,u16 BlockLength)
{
	/*		Make Sure that the channel is  disabled */
	CLR_BIT(DMA1 -> Channel[0].CCR,0);
	
	DMA1 -> Channel[0].CPAR	=	SrcAdd;
	DMA1 -> Channel[0].CMAR	=	DestAdd;
	
	/*	Load the Block Length				*/
	DMA1 -> Channel[0].CNDTR	=	BlockLength;

	/*		Make Sure that the channel is  Enabled to start transfer*/
	SET_BIT(DMA1 -> Channel[0].CCR,0);	
}








