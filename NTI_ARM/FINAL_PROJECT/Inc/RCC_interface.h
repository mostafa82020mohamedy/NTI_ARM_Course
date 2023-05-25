#ifndef		RCC_INTERFACE_H
#define		RCC_INTERFACE_H

#include "RCC_config.h"
#include "Std_Types.h"
#include "Bit_Math.h"
#include	"RCC_private.h"

#define		RCC_AHB				0
#define		RCC_APB1			1
#define		RCC_APB2			2

// enum for activation of HSE source
typedef enum
{
  HSE_ON,
  HSE_OFF
}RCC_HSE_ACTIVATION;
// enum for activation of HSI source
typedef enum
{
  HSI_ON,
  HSI_OFF
}RCC_HSI_ACTIVATION;
// enum for activation of PLL source
typedef enum
{
  PLL_ON,
  PLL_OFF
}RCC_PLL_ACTIVATION;
// enum for activation of system clock source
typedef enum
{
  CLK_HSI,
  CLK_HSE,
  CLK_PLL
}RCC_CLK_SRC;
// enum for AHB prescaler
typedef enum
{
	AHB_NO_PRESCALE,
	AHB_PRESCALE_2,
	AHB_PRESCALE_4,
	AHB_PRESCALE_8,
	AHB_PRESCALE_16,
	AHB_PRESCALE_64,
	AHB_PRESCALE_128,
	AHB_PRESCALE_256,
	AHB_PRESCALE_512
}RCC_AHB_PRESCALER;
// enum for APB1 prescaler
typedef enum
{
	APB1_NO_PRESCALE,
	APB1_PRESCALE_2,
	APB1_PRESCALE_4,
	APB1_PRESCALE_8,
	APB1_PRESCALE_16
}RCC_APB1_PRESCALER;
// enum for APB2 prescaler
typedef enum
{
	APB2_NO_PRESCALE,
	APB2_PRESCALE_2,
	APB2_PRESCALE_4,
	APB2_PRESCALE_8,
	APB2_PRESCALE_16
}RCC_APB2_PRESCALER;
// enum for choose PLL entry clock source
typedef enum
{
  PLL_HSI_2,
  PLL_HSE
}RCC_PLL_ENTRY_CLK_SRC;
// enum for choose HSE divider for PLL entry clock source
typedef enum
{
  HSE,
  HSE_2
}RCC_HSE_DIVIDER_FOR_PLL_ENTRY;
// enum for PLL multiplication factor
typedef enum
{
  MULTIPLY_BY_2,
  MULTIPLY_BY_3,
  MULTIPLY_BY_4,
  MULTIPLY_BY_5,
  MULTIPLY_BY_6,
  MULTIPLY_BY_7,
  MULTIPLY_BY_8,
  MULTIPLY_BY_9,
  MULTIPLY_BY_10,
  MULTIPLY_BY_11,
  MULTIPLY_BY_12,
  MULTIPLY_BY_13,
  MULTIPLY_BY_14,
  MULTIPLY_BY_15,
  MULTIPLY_BY_16  
}RCC_PLL_MULTIPLICATION_FACTOR;
// enum for Microcontroller clock output
typedef enum
{ 
	MC_NO_CLK,
	MC_SYSCLK,
	MC_HSI,
	MC_HSE,
	MC_PLL
}RCC_MC_CLK_OUTPUT;
// struct to collect all RCC enums
typedef struct
{
  RCC_HSE_ACTIVATION               HSE_Activation;    
  RCC_HSI_ACTIVATION               HSI_Activation;
  RCC_PLL_ACTIVATION               PLL_Activation; 
  RCC_CLK_SRC                      Clk_Source;
  RCC_AHB_PRESCALER                AHB_Prescaler;         
  RCC_APB1_PRESCALER               APB1_Prescaler;
  RCC_APB2_PRESCALER               APB2_Prescaler;
  RCC_PLL_ENTRY_CLK_SRC            PLL_Clk_Src;
  RCC_HSE_DIVIDER_FOR_PLL_ENTRY    PLL_For_HSE_Clk_Src;
  RCC_PLL_MULTIPLICATION_FACTOR    PLL_Factor;
  RCC_MC_CLK_OUTPUT                MC_Clk_Output;
}RCC_PARAMETER_t;

void		RCC_voidSysClkInt(RCC_PARAMETER_t  parameter);
void		RCC_voidEnablePerClk(u8 BusId , u8 PerId);
void		RCC_voidDisablePerClk(u8 BusId , u8 PerId);

#endif
