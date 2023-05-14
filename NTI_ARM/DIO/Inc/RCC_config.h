#ifndef		RCC_CONFIG_H
#define		RCC_CONFIG_H

#define		RCC_SYS_CLK			RCC_PLL

#define     RCC_AHB_PRE         RCC_SYSCLK
#define     RCC_APB1_PRE        RCC_HCLK
#define     RCC_APB2_PRE        RCC_HCLK
#define     RCC_ADC_PRE         RCC_PLCLK_2
#define     RCC_PLL_CLK_SRC     RCC_SRC_HSI_D2
#define     RCC_PLL_ENTRY       RCC_HSE_E
#define     RCC_PLL_MUL         RCC_CLK_MUL_17
#define     RCC_USB_PRE         RCC_USB_PLL
#define     RCC_MCO_CLK         RCC_MCO_0

#define     CLK_SRC             HSI


#define     SW                  (RCC_PLL            <<0)
#define     HPRE                (RCC_SYSCLK         <<4)
#define     PPRE1               (RCC_HCLK           <<8)
#define     PPRE2               (RCC_HCLK           <<11)
#define     ADCPRE              (RCC_PCLK_2         <<14)
#define     PLLSRC              (RCC_SRC_HSI_D2     <<16)
#define     PLLXTPRE            (RCC_HSE_E          <<17)
#define     PLLMUL              (RCC_PLL_MUL_16     <<18)
#define     USBPRE              (RCC_USB_PLL        <<22)
#define     MCO                 (RCC_MOC_0          <<26)


#endif
