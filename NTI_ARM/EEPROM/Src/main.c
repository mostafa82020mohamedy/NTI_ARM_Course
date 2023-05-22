#include "Std_Types.h"
#include "Bit_Math.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "I2C_interface.h"


int main()
{
	u8 flag=0;

	/* System Clock Init */
	RCC_voidSysClkInt();
	/* Enable RCC for GPIOC */
	RCC_voidEnablePerClk(RCC_APB2,4);
	/* Enable RCC for GPIOB */
	RCC_voidEnablePerClk(RCC_APB2,3);
	/* Enable RCC for GPIOA */
	RCC_voidEnablePerClk(RCC_APB2,2);

	/* Enable RCC for I2C */
	RCC_voidEnablePerClk(RCC_APB1, 21);
	/* Enable RCC for Alternate Function */
	RCC_voidEnablePerClk(RCC_APB2, 0);

	u8 Transmitted_Data[3] = "MOH";
	u8 Received_Data[3]  = {0};
	u8 EEPROM_Address = 0b10100000;

	/* B6 (SCL) Direction "Alternate Function Open Drain" */
	DIO_voidSetPinDirection(PORTB, PIN6,GPIO_OUTPUT_2MHZ_AFOD);
	/* B7 (SDA) Direction "Alternate Function Open Drain" */
	DIO_voidSetPinDirection(PORTB, PIN7,GPIO_OUTPUT_2MHZ_AFOD);

	/* Make Pull Up in Hardware Connections for both SCL and SDA */

	/* Initialise I2C */
	I2C_voidInit();

/*****************************************************************************************/
/******************************* Sending the Data to EEPROM ******************************/
	/* Send Start Condition */
	I2C_voidStartCond();

	/* Send Address */
	I2C_voidSelectAddress(EEPROM_Address);
	I2C_voidWriteByte(0x00);

	/* Send Data */
	for(int i = 0;i < 3; i++)
	{
		I2C_voidWriteByte(Transmitted_Data[i]);
	}

	/* Send Stop Condition */
	I2C_voidStopCond();

/*********************************** END of Sending Data *********************************/
/*****************************************************************************************/


/*****************************************************************************************/
/***************************** Receiving the Data from EEPROM ****************************/
	I2C_voidStartCond();

	I2C_voidSelectAddress(EEPROM_Address);

	I2C_voidWriteByte(0x00);

	I2C_voidStartCond();

	I2C_voidSelectAddress(EEPROM_Address+1);


	for(int i = 1;i < 3; i++)
	{
		I2C_VoidReadByte(&Received_Data[i]);
	}
	I2C_VoidReadByte(&Received_Data[0]);

	I2C_voidStopCond();

/********************************** END of Receiving Data ********************************/
/*****************************************************************************************/

	/* A0 Direction "Push Pull Output" for Led */
	DIO_voidSetPinDirection(PORTA, PIN0,GPIO_OUTPUT_2MHZ_PP);
	while (1)
	{

		/* Comparing between Transmitted Data and Received Data */
		for(int i = 0;i < 3; i++)
		{
			if(Received_Data[i] == Transmitted_Data[i])
			{
				flag=1;
			}
			else
			{
				flag=0;
			}
		}

		if(flag ==1)
		{
			DIO_voidSetPinValue(PORTA, PIN0,GPIO_HIGH);
			_delay_ms(1000);
			DIO_voidSetPinValue(PORTA, PIN0,GPIO_LOW);
			_delay_ms(1000);
		}


		_delay_ms(1000);
	}

		return 0;
}

