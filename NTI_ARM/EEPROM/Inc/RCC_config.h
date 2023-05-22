#ifndef		RCC_CONFIG_H
#define		RCC_CONFIG_H

//enable or disable clocks , clock security and HSE clock bypass {0 = OFF, 1 = ON}
#define		RCC_HSI_clk								1
#define		RCC_HSE_clk								1
#define		RCC_PLL_clk								1
#define		RCC_CSS									0
#define		RCC_HSE_BYP								0

/* choose system clock
 * options are :
 *RCC_PLL
 *RCC_HSI
 *RCC_HSE
 */
#define		RCC_SYS_CLK			  			RCC_HSI
/* choose AHB prescaler
 * options are {NO_PRE, 2, 8, 16, 64, 128, 256, 512}
 * */
#define		NO_PRE			   				111
#define		RCC_AHB_PRE						NO_PRE
/* choose APB low-speed prescaler
 * options are {NO_PRE, 2, 4, 8, 16}
 * */
#define		RCC_APB1_PRE					NO_PRE
/* choose APB high-speed prescaler
 * options are {NO_PRE, 2, 4, 8, 16}
 * */
#define		RCC_APB2_PRE					NO_PRE
/* choose  PLL entry clock source
 * options are :
 * 0 => HSI / 2
 * 1 => HSE
 * */
#define		RCC_PLL_SRC						0
/* choose   HSE divider for PLL entry
 * options are :
 * 0 =>  HSE
 * 1 =>  HSE / 2
 * */
#define		RCC_PLL_XTPRE					0
/* choose   PLL multiplication factor
 * options are {2 : 16}
 * */
#define		RCC_PLL_MUL						2

/* choose   Microcontroller clock output
 * options are  :
 *  0 => OFF
 *	SYS_CLK
 *	HSI_CLK
 *	HSE_CLK
 *	PLL_CLK {divided by 2}
 */
#define		 RCC_MCO						0

/* choose  USB prescaler
 * options are 2 :
 *  0 => PLL_clk / 1.5
 *  1 => PLL
 **/
#define		RCC_USB_PRE						0
#endif
