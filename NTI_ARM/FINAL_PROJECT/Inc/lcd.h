/*
 * lcd.h
 *
 * Created: 1/10/2023 3:25:42 PM
 *  Author: ahmed saad
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "lcd_config.h"
#include "DIO_interface.h"

void LCD_Init();
void LCD_Write_Char(u8 data);
void LCD_Write_String(u8* string);
void LCD_Write_Number(u32 number);
void LCD_Clear(void);
void LCD_Write_AtPosition(u8 lineNumber , u8 digitNumber);
void LCD_Create_Custom_Character(u8* pattern,u8 location);

#endif /* LCD_H_ */
