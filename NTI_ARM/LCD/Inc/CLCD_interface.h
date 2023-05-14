/*******************************************************************/
/********************  Author: Mostafa Mohamedy ********************/
/********************        Layer: Hal         ********************/
/********************          SWC:CLCD         ********************/
/********************       Version: 1.00       ********************/
/*******************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidInit(void);
void CLCD_voidSendString(const char *Copy_pcString);
void CLCD_voidGoToXY(u8 Copy_u8XPosition , u8 Copy_u8YPosition);
void CLCD_voidWriteSpecialCharacter(u8 * Copy_pu8Pattern , u8 Copy_u8PatternNumber,u8 Copy_u8XPosition , u8 Copy_u8YPosition);
void CLCD_voidWriteInteger(u16 Copy_u8Number);


#endif /* CLCD_INTERFACE_H_ */



