#ifndef		SPI_CONFIG_H
#define		SPI_CONFIG_H



#define BAUDRATE                        FPCLK_BY_8
#define MASTER_SLAVE_SELECT             MASTER
#define LSB_FIRST                       MSB

/*Options:
 	 	 FULL_DUPLEX         for Full Duplex mode
 	 	 HALF_DUPLEX         for Receive only mode
 * */
#define DATA_DIRECTION                  FULL_DUPLEX



#endif
