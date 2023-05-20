#ifndef		SPI_PRIVATE_H
#define		SPI_PRIVATE_H


#define		SPI1_BASE_ADD			0x40013000

typedef		struct
{
	u32				CR1;
	u32				CR2;
	u32				SR;
	u32				DR;
	u32				CRCPR;
	u32				RXCRCR;
	u32				TXCRCR;
	u32				I2SCFGR;
	u32				I2SPR;

}SPI1_Type;
#define			SPI1				((volatile SPI1_Type*)(SPI1_BASE_ADD))


#define FPCLK_BY_2                  0x00000000
#define FPCLK_BY_4                  0x00000008
#define FPCLK_BY_8                  0x00000010
#define FPCLK_BY_16                 0x00000018
#define FPCLK_BY_32                 0x00000020
#define FPCLK_BY_64                 0x00000028
#define FPCLK_BY_128                0x00000030
#define FPCLK_BY_256                0x00000038


#define SLAVE                       1
#define MASTER                      2


#define LSB                         1
#define MSB                         2


#define HALF_DUPLEX                 1
#define FULL_DUPLEX                 2



#endif
