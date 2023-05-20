#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_interface.h"



void SPI1_init(void)
{
	/* Enable SPI1 Clock "RISING EDGE,SETUP FIRST THEN SAMPLE" */
	SET_BIT(SPI1 ->CR1 , 0);
	SET_BIT(SPI1 ->CR1 , 1);

	/* Master Mode : Baud Rate */
	SPI1->CR1 &=0xFFFFFFC7;
	SPI1->CR1 |=BAUDRATE;

	/* Select Master Slave */
	#if(MASTER_SLAVE_SELECT==SLAVE)
	{
		CLR_BIT(SPI1->CR1 , 2);
	}
	#elif(MASTER_SLAVE_SELECT==MASTER)
	{
		SET_BIT(SPI1->CR1 , 2);
	}
	#else
	{
		/* Error */
	}
	#endif


	/* Select LSB_FIRST */
	#if(LSB_FIRST==LSB)
	{
		SET_BIT(SPI1->CR1 , 7);
	}
	#elif(LSB_FIRST==MSB)
	{
		CLR_BIT(SPI1->CR1 , 7);
	}
	#else
	{
		/* Error */
	}
	#endif

	/* Select Data Direction */
	#if(DATA_DIRECTION==HALF_DUPLEX)
	{
		SET_BIT(SPI1->CR1,15);
		SET_BIT(SPI1->CR1,10);
	}
	#elif(DATA_DIRECTION==FULL_DUPLEX)
	{
		CLR_BIT(SPI1->CR1,15);
		CLR_BIT(SPI1->CR1,10);
	}
	#else
	{
		/* Error */
	}
	#endif

	/* Software Slave Management Enable */
	SET_BIT(SPI1->CR1 , 9);
	SET_BIT(SPI1->CR1,8);

	/* 8-BIT DATA FRAME */
	CLR_BIT(SPI1->CR1,11);

	/* DISABLE ALL INTERRUPT */
	SPI1->CR2=0;

	/* Enable SPI */
	SET_BIT(SPI1->CR1,6);

}




u8 SPI1_TX_RX_Char(u8 data)
{
	u8 rx_data=0;
	/* SET SS PIN TO LOW */
	DIO_voidSetPinValue(PORTA, PIN4, GPIO_LOW);

	SPI1->DR = data ;

	/* Wait until Finishing Transmission */
    while((GET_BIT(SPI1->SR,7))==1)
    {
		asm("NOP");
    }

	rx_data = SPI1->DR;

	/* SET SS PIN TO HIGH */
	DIO_voidSetPinValue(PORTA, PIN4, GPIO_HIGH);
	return rx_data;

}



