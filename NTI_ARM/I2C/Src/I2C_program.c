#include "Std_Types.h"
#include "Bit_Math.h"

#include "I2C_private.h"
#include "I2C_interface.h"
#include "I2C_config.h"


void I2C_voidInit(void)
{
	u8 Local_Clear=0;
	Local_Clear = I2C1->SR1;

	/* Reset I2C */
	I2C_voidReset();

	SET_BIT(I2C1->CR2 , 3);
	I2C1->CCR |= 0x28;
	I2C1->TRISE |= 9;

	/* I2C Enable */
	SET_BIT(I2C1->CR1,0);

}
void I2C_voidStartCond(void)
{
	/* Enable Acknowledge */
	SET_BIT(I2C1->CR1,10);
	/* Generate Start Condition */
	SET_BIT(I2C1->CR1,8);

	/* Wait until Generating Start Condition */
	while ((GET_BIT(I2C1->SR1 , 0))==0)
	{
		asm ("NOP");
	}

}


void I2C_voidSelectAddress(u8 address)
{
	u8 Local_Clear=0;
	I2C1->DR = address;
	while (GET_BIT(I2C1->SR1 , 1) ==0)
	{
		asm ("NOP");
	}

	/* Clear the Address Sent Flag */
	Local_Clear = I2C1->SR1 | I2C1->SR2;
}


void I2C_voidWriteByte(u8 data)
{
	/* Wait until Data Register be Empty (Transmitter) */
	while (GET_BIT(I2C1->SR1 , 7) ==0)
	{
		asm ("NOP");
	}

	/* Send Data */
	I2C1->DR = data;

	/* Wait until Bit Transfer is Finished */
	while (GET_BIT(I2C1->SR1 , 2) ==0)
	{
		asm ("NOP");
	}
}


void I2C_VoidReadByte(u8 *data)
{

	/* Wait until Data Register be Empty (Receiver) */
	while (GET_BIT(I2C1->SR1 , 6) ==0)
	{
		asm ("NOP");
	}

	/* Receive Data */
	*data = I2C1->DR;
}


void I2C_voidStopCond(void)
{
	SET_BIT(I2C1->CR1,9);

	/* Wait until Generating Stop Condition */
	while ((GET_BIT(I2C1->SR1 , 4))==0)
	{
		asm ("NOP");
	}
}



void I2C_voidDisable(void)
{
	CLR_BIT(I2C1->CR1,0);
}


void I2C_voidReset(void)
{
	SET_BIT(I2C1->CR1,15);
	CLR_BIT(I2C1->CR1,15);
}


void I2C_voidEnable(void)
{
	SET_BIT(I2C1->CR1,0);
}
