#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_interface.h"

/*
typedef struct
{
	u8 SSD_CommonType,SSD_Port,SSD_EnablePort,SSD_EnablePin;
}SSD;
*/

u8 SSD_SetNumber_ON(u8 Number,SSD* SSD_Struct)
{

	u8 Local_u8ErrorState=0;
	//DIO_u8SetPortDirection(SSD_Struct->SSD_Port,0xff);
	DIO_voidSetPinDirection(SSD_Struct->SSD_EnablePort,SSD_Struct->SSD_EnablePin,GPIO_OUTPUT_2MHZ_PP);
	if((SSD_Struct->SSD_CommonType)==COMMON_Cathode)
	{
		DIO_u8SetPortValue(SSD_Struct->SSD_Port,Number);
		DIO_u8SetPinValue(SSD_Struct->SSD_EnablePort,SSD_Struct->SSD_EnablePin,LOW);
	}
	else if((SSD_Struct->SSD_CommonType)==COMMON_ANODE)
	{
		DIO_u8SetPortValue(SSD_Struct->SSD_Port,~Number);
		DIO_u8SetPinValue(SSD_Struct->SSD_EnablePort,SSD_Struct->SSD_EnablePin,HIGH);
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}

u8 SSD_SetNumber_OFF(SSD * SSD_Struct)
{

	u8 Local_u8ErrorState=0;
	//DIO_u8SetPortDirection(SSD_Struct->SSD_Port,0xff);
	DIO_voidSetPinDirection(SSD_Struct->SSD_EnablePort,SSD_Struct->SSD_EnablePin,GPIO_OUTPUT_2MHZ_PP);
	if(((SSD_Struct->SSD_CommonType)==COMMON_Cathode)||((SSD_Struct->SSD_CommonType)==COMMON_ANODE))
	{
		DIO_u8SetPortValue(SSD_Struct->SSD_Port,0);
		DIO_u8SetPinValue(SSD_Struct->SSD_EnablePort,SSD_Struct->SSD_EnablePin,LOW);
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}
