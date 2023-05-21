#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H


void I2C_voidInit(void);
void I2C_voidStartCond(void);
void I2C_voidSelectAddress(u8 address);
void I2C_voidWriteByte(u8 data);
void I2C_VoidReadByte(u8 *data);
void I2C_voidStopCond(void);
void I2C_voidDisable(void);
void I2C_voidReset(void);
void I2C_voidEnable(void);


#define		READ							0
#define		WRITE							1

#define		ENABLED							0
#define		DISABLED						1


#endif
