/*
 * lcd.c
 *
 * Created: 1/10/2023 3:25:28 PM
 *  Author: ahmed saad
 */ 
#include "lcd.h"

#define  LCD_CURSOR_RETURN        0x02  // return cursor to first position on first line
#define  SHIFT_CURSOR_RIGHT       0x06  // make you write from left to right
#define  LCD_CLEAR_CMD  		  0x01  
#define  SHIFT_CURSOR_TO_1_LINE   0x80  // to write in first line
#define  SHIFT_CURSOR_TO_2_LINE   0xC0  // to write in second line
////////////////////////////////////////////////////////////////////
#define  LCD_FONT_BOLD            0x04         // 5 x 10 font
#define  LCD_FONT_NOT_BOLD        0x00         // 5 x 8 font
#define  LCD_2_LINE               0x08         // 2-line display  
#define  LCD_1_LINE               0x00         // 1-line display
#define  FOUR_BIT_MODE            0x20    // 1 line, 4-bit mode
#define  EIGHT_BIT_MODE           0x30    // 1 line, 4-bit mode
#define  CONTROL_MODE   (LCD_FONT_NOT_BOLD | LCD_2_LINE | FOUR_BIT_MODE) // 2 lines, 5x8 matrix,4-bit mode (you can make your own mode)
/////////////////////////////////////////////////////////////////////
#define  DISPLAY_ON_CURSOR_OFF    0x0C  
#define  DISPLAY_ON_CURSOR_ON     0x0E 
////////////////////////////////////////////////////////////////////////
#define  CGRAM_ADDRESS     0x40

void LCD_Write_CMD(u8 command);
void  _delay2_ms(u32 ticks)
{
	u32 i;
	for( i = 0; i < (ticks * 500) ; i++)
	{
		asm("NOP");
	}
}

void LCD_Init()
{
	//Define direction for command pins
	DIO_voidSetPinDirection(LCD_CMD_PORT,LCD_RS,GPIO_OUTPUT_2MHZ_PP	);
	DIO_voidSetPinDirection(LCD_CMD_PORT,LCD_EN,GPIO_OUTPUT_2MHZ_PP	);
	DIO_voidSetPinDirection(LCD_CMD_PORT,LCD_RW,GPIO_OUTPUT_2MHZ_PP	);
	//Define direction for data pins
	DIO_voidSetPinDirection(LCD_DTA_PORT,LCD_D4,GPIO_OUTPUT_2MHZ_PP	);
	DIO_voidSetPinDirection(LCD_DTA_PORT,LCD_D5,GPIO_OUTPUT_2MHZ_PP	);
	DIO_voidSetPinDirection(LCD_DTA_PORT,LCD_D6,GPIO_OUTPUT_2MHZ_PP	);
	DIO_voidSetPinDirection(LCD_DTA_PORT,LCD_D7,GPIO_OUTPUT_2MHZ_PP	);
	_delay2_ms(20);
	// return cursor to first position on first line
	LCD_Write_CMD(LCD_CURSOR_RETURN);
	_delay2_ms(2);
	// 2 lines, 5x8 matrix,4-bit mode
	LCD_Write_CMD(CONTROL_MODE);
	_delay2_ms(1);
	LCD_Write_CMD(DISPLAY_ON_CURSOR_OFF);
	_delay2_ms(1);
	LCD_Write_CMD(SHIFT_CURSOR_RIGHT);
	_delay2_ms(1);
	LCD_Write_CMD(LCD_CLEAR_CMD);
	_delay2_ms(2);
}
void LCD_Write_CMD(u8 command)
{
	DIO_voidSetPinValue(LCD_CMD_PORT,LCD_RS,LCD_LOW); // (0)-> choose command register
	DIO_voidSetPinValue(LCD_CMD_PORT,LCD_RW,LCD_LOW); // (0)-> write inside register
	DIO_voidSetPinValue(LCD_CMD_PORT,LCD_EN,LCD_LOW); // for make sure that enable in initialize is low
	GPIOA_ODR = (GPIOA_ODR & 0x0F) |(command & 0xF0); //sending high nibbles
	DIO_voidSetPinValue(LCD_CMD_PORT,LCD_EN,LCD_HIGH);
	_delay2_ms(1);
	DIO_voidSetPinValue(LCD_CMD_PORT,LCD_EN,LCD_LOW);
	GPIOA_ODR = (GPIOA_ODR & 0x0F) |(command << 4); //sending low nibbles
	DIO_voidSetPinValue(LCD_CMD_PORT,LCD_EN,LCD_HIGH);
	_delay2_ms(1);
	DIO_voidSetPinValue(LCD_CMD_PORT,LCD_EN,LCD_LOW);
	_delay2_ms(2);
}
void LCD_Write_Char(u8 data)
{
	DIO_voidSetPinValue(LCD_CMD_PORT,LCD_RS,LCD_HIGH); // (1)-> choose data register
	DIO_voidSetPinValue(LCD_CMD_PORT,LCD_RW,LCD_LOW); // (0)-> write inside register
	DIO_voidSetPinValue(LCD_CMD_PORT,LCD_EN,LCD_LOW); // for make sure that enable in initialize is low
	GPIOA_ODR = (GPIOA_ODR & 0x0F) |(data & 0xF0); //sending high nibbles
	DIO_voidSetPinValue(LCD_CMD_PORT,LCD_EN,LCD_HIGH);
	_delay2_ms(1);
	DIO_voidSetPinValue(LCD_CMD_PORT,LCD_EN,LCD_LOW);
	GPIOA_ODR = (GPIOA_ODR & 0x0F) | (data << 4); //sending low nibbles
	DIO_voidSetPinValue(LCD_CMD_PORT,LCD_EN,LCD_HIGH);
	_delay2_ms(1);
	DIO_voidSetPinValue(LCD_CMD_PORT,LCD_EN,LCD_LOW);
	_delay2_ms(2);
}
void LCD_Write_String(u8* string)
{
	u8 i;
	for(i=0;string[i] != NULL_char;i++)
	{
		LCD_Write_Char(string[i]);
	}
}
void LCD_Write_Number(u32 number)
{
	u8 num[10];
	itoa(number, num, 10);  //convert Long int to string
	LCD_Write_String(num);
}
void LCD_Clear(void)
{
	LCD_Write_CMD(LCD_CLEAR_CMD);
}
void LCD_Write_AtPosition(u8 lineNumber , u8 digitNumber)
{
	if((lineNumber>=1 && lineNumber<=2)  && (digitNumber>=1 && digitNumber<=16))
	{
		switch(lineNumber)
		{
			case 1:
				LCD_Write_CMD(SHIFT_CURSOR_TO_1_LINE+digitNumber); //offset addresses of LCD
				break;
			case 2: 
				LCD_Write_CMD(SHIFT_CURSOR_TO_2_LINE+digitNumber);
				break;
		}
	}
}
void LCD_Create_Custom_Character(u8* pattern,u8 location)
{
	u8 i;
	LCD_Write_CMD(CGRAM_ADDRESS + (location*8)); //send address of CGRAM
	for(i=0;i<8;i++)
	{
		LCD_Write_Char(pattern[i]); // pass the bytes of pattern to LCD
	}
}

