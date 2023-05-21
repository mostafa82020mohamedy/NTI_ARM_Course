#include 	"Bit_Math.h"
#include 	"Std_Types.h"

#include 	"RCC_private.h"
#include	"RCC_interface.h"
#include	"RCC_config.h"

void RCC_voidSysClkInt(void) {
// turning on clocks
	if (RCC_HSI_clk == 1)
		SET_BIT(RCC_CR, HSION);
	while (!(RCC_CR & (1 << HSIRDY)))
		;
	if (RCC_HSE_clk == 1)
		SET_BIT(RCC_CR, HSEON);
	while (!(RCC_CR & (1 << HSERDY)))
		;
// turning on PLL clock
	if (RCC_PLL_clk == 1) {
//setting PLL entry clock source and HSE's entry value to PLL
		if (RCC_PLL_SRC == 1)
			SET_BIT(RCC_CFGR, PLLSRC);
		if (RCC_PLL_XTPRE == 1)
			SET_BIT(RCC_CFGR, PLLXTPRE);
//setting  PLL multiplication factor bits according to desired value
		switch (RCC_PLL_MUL) {
		case 2:
			break;
		case 3:
			SET_BIT(RCC_CFGR, PLLMUL0);
			break;
		case 4:
			SET_BIT(RCC_CFGR, PLLMUL1);
			break;
		case 5:
			SET_BIT(RCC_CFGR, PLLMUL0);
			SET_BIT(RCC_CFGR, PLLMUL1);
			break;
		case 6:
			SET_BIT(RCC_CFGR, PLLMUL2);
			break;
		case 7:
			SET_BIT(RCC_CFGR, PLLMUL0);
			SET_BIT(RCC_CFGR, PLLMUL2);
			break;
		case 8:
			SET_BIT(RCC_CFGR, PLLMUL1);
			SET_BIT(RCC_CFGR, PLLMUL2);
			break;
		case 9:
			SET_BIT(RCC_CFGR, PLLMUL0);
			SET_BIT(RCC_CFGR, PLLMUL1);
			SET_BIT(RCC_CFGR, PLLMUL2);
			break;
		case 10:
			SET_BIT(RCC_CFGR, PLLMUL3);
			break;
		case 11:
			SET_BIT(RCC_CFGR, PLLMUL0);
			SET_BIT(RCC_CFGR, PLLMUL3);
			break;
		case 12:
			SET_BIT(RCC_CFGR, PLLMUL1);
			SET_BIT(RCC_CFGR, PLLMUL3);
			break;
		case 13:
			SET_BIT(RCC_CFGR, PLLMUL0);
			SET_BIT(RCC_CFGR, PLLMUL1);
			SET_BIT(RCC_CFGR, PLLMUL3);
			break;
		case 14:
			SET_BIT(RCC_CFGR, PLLMUL2);
			SET_BIT(RCC_CFGR, PLLMUL3);
			break;
		case 15:
			SET_BIT(RCC_CFGR, PLLMUL0);
			SET_BIT(RCC_CFGR, PLLMUL2);
			SET_BIT(RCC_CFGR, PLLMUL3);
			break;
		case 16:
			SET_BIT(RCC_CFGR, PLLMUL1);
			SET_BIT(RCC_CFGR, PLLMUL2);
			SET_BIT(RCC_CFGR, PLLMUL3);
			break;
		default:
			break;
		}
		SET_BIT(RCC_CR, PLLON);
		while (!(RCC_CR & (1 << PLLRDY)))
			;
	}
//setting AHB prescaler bits according to desired value
	switch (RCC_AHB_PRE) {
	case 2:
		SET_BIT(RCC_CFGR, HPRE3);
		break;
	case 4:
		SET_BIT(RCC_CFGR, HPRE3);
		SET_BIT(RCC_CFGR, HPRE0);
		break;
	case 8:
		SET_BIT(RCC_CFGR, HPRE3);
		SET_BIT(RCC_CFGR, HPRE1);
		break;
	case 16:
		SET_BIT(RCC_CFGR, HPRE3);
		SET_BIT(RCC_CFGR, HPRE0);
		SET_BIT(RCC_CFGR, HPRE1);
		break;
	case 64:
		SET_BIT(RCC_CFGR, HPRE3);
		SET_BIT(RCC_CFGR, HPRE2);
		break;
	case 128:
		SET_BIT(RCC_CFGR, HPRE3);
		SET_BIT(RCC_CFGR, HPRE2);
		SET_BIT(RCC_CFGR, HPRE0);
		break;
	case 256:
		SET_BIT(RCC_CFGR, HPRE3);
		SET_BIT(RCC_CFGR, HPRE2);
		SET_BIT(RCC_CFGR, HPRE1);
		break;
	case 512:
		SET_BIT(RCC_CFGR, HPRE3);
		SET_BIT(RCC_CFGR, HPRE2);
		SET_BIT(RCC_CFGR, HPRE1);
		SET_BIT(RCC_CFGR, HPRE0);
		break;
	default:
		break;
	}

//setting APB low-speed prescaler bits according to desired value
	switch (RCC_APB1_PRE) {
	case 2:
		SET_BIT(RCC_CFGR, PPRE1_2);
		break;
	case 4:
		SET_BIT(RCC_CFGR, PPRE1_2);
		SET_BIT(RCC_CFGR, PPRE1_0);
		break;
	case 8:
		SET_BIT(RCC_CFGR, PPRE1_2);
		SET_BIT(RCC_CFGR, PPRE1_1);
		break;
	case 16:
		SET_BIT(RCC_CFGR, PPRE1_2);
		SET_BIT(RCC_CFGR, PPRE1_1);
		SET_BIT(RCC_CFGR, PPRE1_0);
		break;
	default:
		break;
	}

//setting APB high-speed prescaler bits according to desired value
	switch (RCC_APB2_PRE) {
	case 2:
		SET_BIT(RCC_CFGR, PPRE2_2);
		break;
	case 4:
		SET_BIT(RCC_CFGR, PPRE2_2);
		SET_BIT(RCC_CFGR, PPRE2_0);
		break;
	case 8:
		SET_BIT(RCC_CFGR, PPRE2_2);
		SET_BIT(RCC_CFGR, PPRE2_1);
		break;
	case 16:
		SET_BIT(RCC_CFGR, PPRE2_2);
		SET_BIT(RCC_CFGR, PPRE2_1);
		SET_BIT(RCC_CFGR, PPRE2_0);
		break;
	default:
		break;
	}
//setting Microcontroller clock output bits
	switch (RCC_MCO) {
	case SYS_CLK:
		SET_BIT(RCC_CFGR, MCO2);
		break;
	case HSI_CLK:
		SET_BIT(RCC_CFGR, MCO2);
		SET_BIT(RCC_CFGR, MCO0);
		break;
	case HSE_CLK:
		SET_BIT(RCC_CFGR, MCO2);
		SET_BIT(RCC_CFGR, MCO1);
		break;
	case PLL_CLK:
		SET_BIT(RCC_CFGR, MCO2);
		SET_BIT(RCC_CFGR, MCO1);
		SET_BIT(RCC_CFGR, MCO0);
		break;
	default:
		break;
	}
// turning on clock security and HSE clock bypass
	if (RCC_CSS == 1)
		SET_BIT(RCC_CR, CSSON);
	if (RCC_HSE_BYP == 1)
		SET_BIT(RCC_CR, HSEBYP);
//setting system clock
	if (RCC_SYS_CLK == RCC_PLL)
		SET_BIT(RCC_CFGR, SW1);
	if (RCC_SYS_CLK == RCC_HSE)
		SET_BIT(RCC_CFGR, SW0);

	//choosing USB prescaler
	if (RCC_USB_PRE == 1)
		SET_BIT(RCC_CFGR, USBPRE);

}

void RCC_voidEnablePerClk(u8 BusId, u8 PerId) {
	/*		Range Check							*/
	if (PerId < 32) {
		switch (BusId) {
		case RCC_AHB:
			SET_BIT(RCC_AHBENR, PerId);
			break;
		case RCC_APB1:
			SET_BIT(RCC_APB1ENR, PerId);
			break;
		case RCC_APB2:
			SET_BIT(RCC_APB2ENR, PerId);
			break;
		}

	} else { /*	Return Error "Out Of The Range"		*/
	}

}
void RCC_voidDisablePerClk(u8 BusId, u8 PerId) {
	/*		Range Check							*/
	if (PerId < 32) {
		switch (BusId) {
		case RCC_AHB:
			CLR_BIT(RCC_AHBENR, PerId);
			break;
		case RCC_APB1:
			CLR_BIT(RCC_APB1ENR, PerId);
			break;
		case RCC_APB2:
			CLR_BIT(RCC_APB2ENR, PerId);
			break;
		}

	} else { /*	Return Error "Out Of The Range"		*/
	}
}


