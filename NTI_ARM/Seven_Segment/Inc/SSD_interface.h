#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define ZERO 0b00111111
#define ONE 0b00000110
#define TWO 0b01011011
#define THREE 0b01001111
#define FOUR 0b01100110
#define FIVE 0b01101101
#define SIX 0b01111101
#define SEVEN 0b00000111
#define EIGHT 0b01111111
#define NINE 0b01101111

typedef struct
{
	u8 SSD_CommonType,SSD_Port,SSD_EnablePort,SSD_EnablePin;
}SSD;

u8 SSD_SetNumber_ON(u8 Number,SSD* SSD_Struct);
u8 SSD_SetNumber_OFF (SSD * SSD_Struct);

#define  COMMON_ANODE 1
#define  COMMON_Cathode 0

#endif
