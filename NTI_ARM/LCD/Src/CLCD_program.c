/*******************************************************************/
/********************  Author: Mostafa Mohamedy ********************/
/********************        Layer: Hal         ********************/
/********************          SWC:CLCD         ********************/
/********************       Version: 1.00       ********************/
/*******************************************************************/

#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include "DIO_interface.h"

#include"CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set RS pin to Low for Command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,LOW);
	/*Set R/W pin to Low for Writing*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,LOW);
	/*Putting Command*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	/*Generate Enable pulse to get the command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,LOW);

}
void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS pin to Low for Command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,HIGH);
	/*Set R/W pin to Low for Writing*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,LOW);
	/*Putting Command*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	/*Generate Enable pulse to get the command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,LOW);
}

void CLCD_voidInit(void)
{
	/* Wait for more than 30 ms*/
	_delay_ms(40);
	/*Function Set Command: 2 Lines, 8*5 Font Size*/
	CLCD_voidSendCommand(0b00111000);
	/*Display ON/OFF Command: Display ON, Disable Cursor, Disable Blink Cursor*/
	CLCD_voidSendCommand(0b00001100);
	/*Display Clear Command*/
	CLCD_voidSendCommand(0b00000001);

}

void CLCD_voidSendString(const char *Copy_pcString)
{
	u8 Local_u8Counter=0;
	while((Copy_pcString[Local_u8Counter])!='\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}


void CLCD_voidGoToXY(u8 Copy_u8XPosition , u8 Copy_u8YPosition)
{
	u8 Local_u8Address;
	if (Copy_u8XPosition==0)
	{
		Local_u8Address=Copy_u8YPosition;
	}
	else if (Copy_u8XPosition==1)
	{
		Local_u8Address=Copy_u8YPosition+0x40;
	}
	CLCD_voidSendCommand(Local_u8Address+128);

}


void CLCD_voidWriteSpecialCharacter(u8 * Copy_pu8Pattern , u8 Copy_u8PatternNumber,u8 Copy_u8XPosition , u8 Copy_u8YPosition)
{

	u8 Local_u8CGRAMAddress=0;
	u8 Local_u8Iterator;

	/* Calculate CGRAM address where each block has 8 bytes */
	Local_u8CGRAMAddress=Copy_u8PatternNumber*8;

	/* Send CGRAM address to LCD, with setting bit 6 and clearing bit 7 */
	CLCD_voidSendCommand(Local_u8CGRAMAddress+64);

	/* Write the pattern in CGRAM */
	for (Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}

	/* Go back to DDRAM to display the pattern */
	CLCD_voidGoToXY(Copy_u8XPosition,Copy_u8YPosition);

	/* Display the pattern written in CGRAM */
	CLCD_voidSendData(Copy_u8PatternNumber);

}


void CLCD_voidWriteInteger(u16 Copy_u16Number)
{
	char Local_u8NumberStringArr[10];
	u8 Local_u8Temp , Local_u8ReverseIndex , Local_u8Iterator;
	u8 Local_u8StringIndex=0;

    /* Saving the Ascii of the integer number in string */
	while(Copy_u16Number>=10)
	{
		Local_u8NumberStringArr[Local_u8StringIndex]=Copy_u16Number%10 + 48;
		Local_u8StringIndex++;
		Copy_u16Number=Copy_u16Number/10;
	}
	Local_u8NumberStringArr[Local_u8StringIndex]=Copy_u16Number+48;
	Local_u8StringIndex++;

	/* To be String, not Array of characters */
	Local_u8NumberStringArr[Local_u8StringIndex]='\0';

    /* Reverse String */
	for (Local_u8ReverseIndex = 0, Local_u8Iterator = Local_u8StringIndex-1; Local_u8ReverseIndex < Local_u8Iterator; Local_u8ReverseIndex++, Local_u8Iterator--)
	{
		Local_u8Temp=Local_u8NumberStringArr[Local_u8ReverseIndex];
	    Local_u8NumberStringArr[Local_u8ReverseIndex]=Local_u8NumberStringArr[Local_u8Iterator];
	    Local_u8NumberStringArr[Local_u8Iterator]=Local_u8Temp;
	}

	/* Display the Integer */
	CLCD_voidSendString(Local_u8NumberStringArr);
}


