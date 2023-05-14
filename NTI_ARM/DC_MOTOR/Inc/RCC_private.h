#ifndef		RCC_PRIVATE_H
#define		RCC_PRIVATE_H

#define		RCC_BASE_ADD		(0x40021000)

#define		RCC_CR				*((u32 *)(RCC_BASE_ADD+0x00))
#define		RCC_CFGR			*((u32 *)(RCC_BASE_ADD+0x04))
#define		RCC_CIR				*((u32 *)(RCC_BASE_ADD+0x08))
#define		RCC_APB2RSTR		*((u32 *)(RCC_BASE_ADD+0x0C))
#define		RCC_APB1RSTR		*((u32 *)(RCC_BASE_ADD+0x10))
#define		RCC_AHBENR			*((u32 *)(RCC_BASE_ADD+0x14))
#define		RCC_APB2ENR			*((u32 *)(RCC_BASE_ADD+0x18))
#define		RCC_APB1ENR			*((u32 *)(RCC_BASE_ADD+0x1C))
#define		RCC_BDCR			*((u32 *)(RCC_BASE_ADD+0x20))
#define		RCC_CSR				*((u32 *)(RCC_BASE_ADD+0x24))

/*

#define     HSION               0
#define     HSEON               1
#define     PLLON               2


#define     ON                  1
#define     OFF                 0

#define     NO_CLOCK            0
#define     SYSCLK              0b0000010000000000000000000000000
#define     HSI                 0b0000010100000000000000000000000
#define     HSE                 0b0000011000000000000000000000000
#define     PLL                 0b0000011100000000000000000000000


#define     PLL_DIVIDED         0
#define     PLL_NOT_DIVIDED     0b0000000001000000000000000000000


#define     PLL_BY_2            0

#define     PLL_BY_2            0
#define     PLL_BY_2            0
#define     PLL_BY_2            0
#define     PLL_BY_2            0
#define     PLL_BY_2            0
#define     PLL_BY_2            0
#define     PLL_BY_2            0
#define     PLL_BY_2            0
#define     PLL_BY_2            0
#define     PLL_BY_2            0
#define     PLL_BY_2            0
#define     PLL_BY_2            0
#define     PLL_BY_2            0
#define     PLL_BY_2            0
#define     PLL_BY_2            0

*/


#define HSI                     0
#define HSE                     1
#define PLL_HSI                 2
#define PLL_HSE                 3


#define RCC_HSI                 0b0
#define RCC_HSE                 0b01
#define RCC_PLL                 0b10


#define RCC_SYSCLK              0b0
#define RCC_SYSCLK_2            0b1000
#define RCC_SYSCLK_4            0b1001
#define RCC_SYSCLK_8            0b1010
#define RCC_SYSCLK_16           0b1011
#define RCC_SYSCLK_64           0b1100
#define RCC_SYSCLK_128          0b1101
#define RCC_SYSCLK_256          0b1110
#define RCC_SYSCLK_512          0b1111


#define RCC_HCLK                0b0
#define RCC_HCLK_2              0b100
#define RCC_HCLK_4              0b101
#define RCC_HCLK_8              0b110
#define RCC_HCLK_16             0b111

#define RCC_PCLK_2              0b00
#define RCC_PCLK_4              0b01
#define RCC_PCLK_6              0b10
#define RCC_PCLK_8              0b11


#define RCC_SRC_HSI_D2          0b0
#define RCC_SRC_HSE             0b1


#define RCC_HSE_E               0b0
#define RCC_HSE_E_D2            0b1


#define RCC_PLL_MUL_2           0b0000
#define RCC_PLL_MUL_3           0b0001
#define RCC_PLL_MUL_4           0b0010
#define RCC_PLL_MUL_5           0b0011
#define RCC_PLL_MUL_6           0b0100
#define RCC_PLL_MUL_7           0b0101
#define RCC_PLL_MUL_8           0b0110
#define RCC_PLL_MUL_9           0b0111
#define RCC_PLL_MUL_10          0b1000
#define RCC_PLL_MUL_11          0b1001
#define RCC_PLL_MUL_12          0b1010
#define RCC_PLL_MUL_13          0b1011
#define RCC_PLL_MUL_14          0b1100
#define RCC_PLL_MUL_15          0b1101
#define RCC_PLL_MUL_16          0b1110


#define RCC_USB_PLL_D           0b0
#define RCC_USB_PLL             0b1


#define RCC_MOC_0               0b000
#define RCC_MOC_SYSCLK          0b100
#define RCC_MOC_HSICLK          0b101
#define RCC_MOC_HSECLK          0b110
#define RCC_MOC_PLLCLK          0b111







#endif
