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

//RCC_CR bits
#define HSION					0
#define HSIRDY					1
#define HSEON					16
#define HSERDY					17
#define HSEBYP					18
#define CSSON					19
#define PLLON					24
#define PLLRDY					25

//RCC_CFGR bits
#define SW0						0
#define SW1						1
#define SWS0					2
#define SWS1					3
#define HPRE0					4
#define HPRE1					5
#define HPRE2					6
#define HPRE3					7
#define PPRE1_0					8
#define PPRE1_1					9
#define PPRE1_2					10
#define PPRE2_0					11
#define PPRE2_1					12
#define PPRE2_2					13
#define ADCPRE0					14
#define ADCPRE1					15
#define PLLSRC					16
#define PLLXTPRE				17
#define PLLMUL0					18
#define PLLMUL1					19
#define PLLMUL2					20
#define PLLMUL3					21
#define USBPRE					22
#define MCO0					24
#define MCO1					25
#define MCO2					26

#endif
