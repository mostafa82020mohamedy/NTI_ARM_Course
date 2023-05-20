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

//define macro for choose system clock 

#define  RCC_PLL        1
#define  RCC_HSE        2
#define  RCC_HSI        3
//define on off for  by pass filter 
#define ON 		1  

#define OFF		2 

//define PLL CLOCK select  
#define PLL_HSE    1
#define PLL_HSI    2 

//define value of prescaler 
#define  x1      1
#define  x2      2
#define  x3      3
#define  x4      4
#define  x5      5
//define M.C CLK  output  
#define  NO_CLk	   		1
#define SYS_CLK    		2
#define HSE_CLK			3
#define HSI_CLK   		4
#define PLL_CLK_DEV2	5
//define bit of RCC_CR 

#define RCC_CR_HSION       0
#define RCC_CR_HSIRDY      1		
#define RCC_CR_HSEON	   16
#define RCC_CR_HSERDY      17
#define RCC_CR_HSEBYP      18
#define RCC_CR_CSS         19
#define RCC_CR_PLLON       24
#define RCC_CR_PLLRDY	   25

//define bit of RCC_CFGR
 #define  RCC_CFGR_SW0			0
 #define  RCC_CFGR_SW1			1
 #define  RCC_CFGR_SWS0			2
 #define  RCC_CFGR_SWS1 		3
 #define  RCC_CFGR_HPRE0		4
 #define  RCC_CFGR_HPRE1		5
 #define  RCC_CFGR_HPRE2		6
 #define  RCC_CFGR_HPRE3		7
 #define  RCC_CFGR_PPRE1_0		8
 #define  RCC_CFGR_PPRE1_1		9
 #define  RCC_CFGR_PPRE1_2		10
 #define  RCC_CFGR_PPRE2_0		11
 #define  RCC_CFGR_PPRE2_1		12
 #define  RCC_CFGR_PPRE2_2		13
 #define  RCC_CFGR_PLLSRC		16
 #define  RCC_CFGR_PLLXTPRE		17
 #define  RCC_CFGR_PLLMUL0		18
 #define  RCC_CFGR_PLLMUL1		19
 #define  RCC_CFGR_PLLMUL2		20
 #define  RCC_CFGR_PLLMUL3		21
 #define  RCC_CFGR_MCO0		 	24
 #define  RCC_CFGR_MCO1			25
 #define  RCC_CFGR_MCO2			26
#endif