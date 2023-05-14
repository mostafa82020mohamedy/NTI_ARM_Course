#ifndef		RCC_CONFIG_H
#define		RCC_CONFIG_H
/* choose the system clock : 
							  1- RCC_PPL 
							  2- RCC_HSE 
							  3- RCC_HSI   									 
*/

#define		RCC_SYS_CLK			RCC_PLL

/*choose this if only you work on HSE CLK 

  ByPassfilter: 1- ON
                2- OFF
				*/
#define    HSE_BYP         ON 

/*choose this if only you work on PLL CLK 
 PLL_CLK  :  1- PLL_HSE 
			 2- PLL_HSI */ 
			 
#define   PLL_CLK        PLL_HSE 
/*choose prescaler factor if you work on PLL CLK 
 PLL_PRE :  1- x1
			2- x2
			3- x3 
			4- x4
			5- x5  
			*/
#define PLL_PRE      x1 
/* choose if you want to  open M.C CLK output 
 MCO :  1- NO_CLk
		2- SYS_CLK 
		3- HSE_CLK
		4- HSI_CLK
		5- PLL_CLK_DEV2 
		*/ 
#define   MCO     NO_CLk 
/*choose  prescaler for CLK   AHB    
AHB_CLK : DEV on /1 ,2 ,4 ,8 ,16 ,64 ,128 ,256 ,512 */

#define  AHB_CLK     1

#endif