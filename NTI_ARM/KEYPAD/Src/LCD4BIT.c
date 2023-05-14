/*
 * LCD4BIT.c
 *
 * Created: 3/13/2023 1:54:54 AM
 *  Author: ahmed
 */ 

//INCLUDEING PART 
#include "LCD4BIT.h"
#include "LCDEXTRA.h"

void	_delay_ms(u32 ticks);

// initialize function
void LCD_init( ){
	DIO_voidSetPinDirection(CONTROL_PORT ,RS , GPIO_OUTPUT_2MHZ_PP) ;
	DIO_voidSetPinDirection(CONTROL_PORT ,RW , GPIO_OUTPUT_2MHZ_PP) ;
	DIO_voidSetPinDirection(CONTROL_PORT ,EN , GPIO_OUTPUT_2MHZ_PP) ;

	DIO_voidSetPinDirection(DATA_PORT ,PIN12 , GPIO_OUTPUT_2MHZ_PP) ;
	DIO_voidSetPinDirection(DATA_PORT ,PIN13 , GPIO_OUTPUT_2MHZ_PP) ;
	DIO_voidSetPinDirection(DATA_PORT ,PIN14 , GPIO_OUTPUT_2MHZ_PP) ;
	DIO_voidSetPinDirection(DATA_PORT ,PIN15 , GPIO_OUTPUT_2MHZ_PP) ;
	_delay_ms(1000) ;
	LCD_writecmd(0X33) ;
	LCD_writecmd(0X32) ;
	LCD_writecmd(0x28) ;
	_delay_ms(10) ;
	LCD_writecmd(0x0C) ;
	_delay_ms(10) ;
	LCD_writecmd(0x01) ;
	_delay_ms(10) ;
	_delay_ms(10) ;
	LCD_writecmd(0x06) ;
	_delay_ms(1000) ;
}
//write data
void LCD_writechar(u8 data) {
		//INTITIALIZE PORT DATA & CONTROL

		//WRITE ON PORTS
		DIO_voidSetPinValue(CONTROL_PORT,RS , GPIO_HIGH) ;
		
		DIO_voidSetPinValue(CONTROL_PORT,RW , GPIO_LOW) ;
		DIO_voidSethlafPortvalV2(DATA_PORT,PORT_HIGH, upp_nibb(0x00 ,data)    ) ;
		DIO_voidSetPinValue(CONTROL_PORT,EN , GPIO_HIGH);
		_delay_ms(10) ;
		DIO_voidSetPinValue(CONTROL_PORT,EN ,GPIO_LOW) ;
		_delay_ms(10) ;
		DIO_voidSethlafPortvalV2(DATA_PORT,PORT_HIGH, low_nibb(0x00 ,data)    ) ;
		DIO_voidSetPinValue(CONTROL_PORT,EN , GPIO_HIGH);
		_delay_ms(10) ;
		DIO_voidSetPinValue(CONTROL_PORT,EN ,GPIO_LOW) ;
		_delay_ms(10) ;
		
}
//write command
void LCD_writecmd(u8 cmd)  {

	//WRITE ON PORTS
	DIO_voidSetPinValue(CONTROL_PORT,RS , GPIO_LOW) ;
	DIO_voidSetPinValue(CONTROL_PORT,RW , GPIO_LOW) ;

	DIO_voidSethlafPortvalV2(DATA_PORT,PORT_HIGH,upp_nibb(0x00,cmd)     ) ;
	DIO_voidSetPinValue(CONTROL_PORT,EN , GPIO_HIGH);
	_delay_ms(10) ;
	
	DIO_voidSetPinValue(CONTROL_PORT,EN ,GPIO_LOW) ;
	_delay_ms(10) ;
	
	DIO_voidSethlafPortvalV2(DATA_PORT,PORT_HIGH,low_nibb(0x00,cmd)     ) ;
	DIO_voidSetPinValue(CONTROL_PORT,EN , GPIO_HIGH);
	_delay_ms(10) ;
	DIO_voidSetPinValue(CONTROL_PORT,EN ,GPIO_LOW) ;
	_delay_ms(10) ;

}
//function to write string on LCD
void LCD_writestring(u8 *str){
	while(*str != '\0')
	{
		LCD_writechar(*str) ;
		str++ ;
	}
}
//select the position you need to display on lcd
void LCD_goto(u8 row, u8 col){
	if (row<2 &&col<16)
	{
		switch(row){
			case 0 : LCD_writecmd(0X80+col) ;
			break;
			case 1: LCD_writecmd(0XC0+col)  ;
			break;
		}
		}else {
		
	}
}
//function to writer number on LCD
void LCD_writernumber(u16 number) {
 u16 sum=0   ; u8 num = 0 ;
	while(number != 0){
		sum = (number%10) + sum*10  ;
		number=number/10    ;
	}
	while(sum!=0){
		num = sum%10;
		LCD_writechar(0x30+num) ;
		sum = sum/10  ;
	}
}
//function to customize  char

void LCD_customchar(u8 x , u8 y ){
	u8 i    ;
	u8 j   ;
	LCD_writecmd(0x40) ;
	for (i=0 ; i<64 ; i++)
	{
		LCD_writechar(make[i]) ;
	}
	//LCD_writecmd(0X80) ;
	LCD_goto(x,y) ;
	for (j=0 ; j<8 ; j ++)
	{
		LCD_writechar(j) ;
	}
}
