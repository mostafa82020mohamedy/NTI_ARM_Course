#ifndef		RCC_CONFIG_H
#define		RCC_CONFIG_H

// bits of Clock control register (RCC_CR)
#define         HSION         0
#define         HSIRDY        1
#define         HSEON	      16
#define         HSERDY        17
#define         HSEBYP        18
#define         CSSON         19
#define         PLLON         24
#define         PLLRDY        25
// bits of Clock configuration register (RCC_CFGR)
#define         SW0           0
#define         SW1           1
#define         HPRE0         4
#define         HPRE1         5
#define         HPRE2         6
#define         HPRE3         7
#define         PPRE10        8
#define         PPRE11        9
#define         PPRE12        10
#define         PPRE20        11
#define         PPRE21        12
#define         PPRE22        13
#define         PLLSRC        16
#define         PLLXTPRE      17
#define         PLLMUL0       18
#define         PLLMUL1       19
#define         PLLMUL2       20
#define         PLLMUL3       21
#define         MCO0          24
#define         MCO1          25
#define         MCO2          26


#endif
