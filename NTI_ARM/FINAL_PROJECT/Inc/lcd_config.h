/*
 * lcd_config.h
 *
 * Created: 1/10/2023 3:43:20 PM
 *  Author: ahmed saad
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "DIO_interface.h"

/*Command Port*/
#define LCD_CMD_PORT  PORTB
/*Data Port*/
#define LCD_DTA_PORT  PORTA
/*Control Pins*/
#define LCD_RS        PIN8
#define LCD_RW        PIN7
#define LCD_EN        PIN6
/*Data Pins*/
#define LCD_D4        PIN4
#define LCD_D5        PIN5
#define LCD_D6        PIN6
#define LCD_D7        PIN7
/*State*/

#define LCD_HIGH      1
#define LCD_LOW       0


#endif /* LCD_CONFIG_H_ */
