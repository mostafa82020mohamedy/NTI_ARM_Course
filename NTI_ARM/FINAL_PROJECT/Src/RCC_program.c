//#include	"Std_Types.h"
//#include	"Bit_Math.h"

#include	"RCC_interface.h"
//#include	"RCC_private.h"
//#include	"RCC_config.h"

void		RCC_voidSysClkInt(RCC_PARAMETER_t  parameter)
{
     switch(parameter.HSE_Activation)
      {
	 case HSE_ON:  SET_BIT(RCC_CR,HSEON); break;
         case HSE_OFF: CLR_BIT(RCC_CR,HSEON); break;
      }
      switch(parameter.HSI_Activation)
      {
	 case HSI_ON:  SET_BIT(RCC_CR,HSION); break;
         case HSI_OFF: CLR_BIT(RCC_CR,HSION); break;
      }
      switch(parameter.PLL_Activation)
      {
	 case PLL_ON:  SET_BIT(RCC_CR,PLLON); break;
         case PLL_OFF: CLR_BIT(RCC_CR,PLLON); break;
      }
      switch(parameter.Clk_Source)
      {
	     case CLK_HSI: CLR_BIT(RCC_CFGR,SW0); CLR_BIT(RCC_CFGR,SW1); break;
         case CLK_HSE: CLR_BIT(RCC_CFGR,SW0); SET_BIT(RCC_CFGR,SW1); break;
         case CLK_PLL: SET_BIT(RCC_CFGR,SW0); CLR_BIT(RCC_CFGR,SW1); break;
      }
      switch(parameter.AHB_Prescaler)
      {
	     case AHB_NO_PRESCALE: CLR_BIT(RCC_CFGR,HPRE0); CLR_BIT(RCC_CFGR,HPRE1);
                           CLR_BIT(RCC_CFGR,HPRE2); CLR_BIT(RCC_CFGR,HPRE3);                            break;
         case AHB_PRESCALE_2: CLR_BIT(RCC_CFGR,HPRE0); CLR_BIT(RCC_CFGR,HPRE1);
                          CLR_BIT(RCC_CFGR,HPRE2); SET_BIT(RCC_CFGR,HPRE3);                                  break;
         case AHB_PRESCALE_4: SET_BIT(RCC_CFGR,HPRE0); CLR_BIT(RCC_CFGR,HPRE1);
                          CLR_BIT(RCC_CFGR,HPRE2); SET_BIT(RCC_CFGR,HPRE3);                                  break;
         case AHB_PRESCALE_8: CLR_BIT(RCC_CFGR,HPRE0); SET_BIT(RCC_CFGR,HPRE1);
                          CLR_BIT(RCC_CFGR,HPRE2); SET_BIT(RCC_CFGR,HPRE3);                                  break;
         case AHB_PRESCALE_16: SET_BIT(RCC_CFGR,HPRE0); SET_BIT(RCC_CFGR,HPRE1);
                           CLR_BIT(RCC_CFGR,HPRE2); SET_BIT(RCC_CFGR,HPRE3);                                  break;
         case AHB_PRESCALE_64: CLR_BIT(RCC_CFGR,HPRE0); CLR_BIT(RCC_CFGR,HPRE1);
                           SET_BIT(RCC_CFGR,HPRE2); SET_BIT(RCC_CFGR,HPRE3);                                  break;
         case AHB_PRESCALE_128: SET_BIT(RCC_CFGR,HPRE0); CLR_BIT(RCC_CFGR,HPRE1);
                            SET_BIT(RCC_CFGR,HPRE2); SET_BIT(RCC_CFGR,HPRE3);                                  break;
         case AHB_PRESCALE_256: CLR_BIT(RCC_CFGR,HPRE0); SET_BIT(RCC_CFGR,HPRE1);
                            SET_BIT(RCC_CFGR,HPRE2); SET_BIT(RCC_CFGR,HPRE3);                                  break;
         case AHB_PRESCALE_512: SET_BIT(RCC_CFGR,HPRE0); SET_BIT(RCC_CFGR,HPRE1);
                            SET_BIT(RCC_CFGR,HPRE2); SET_BIT(RCC_CFGR,HPRE3);                                  break;
      }
      switch(parameter.APB1_Prescaler)
      {
	     case APB1_NO_PRESCALE:CLR_BIT(RCC_CFGR,PPRE10); CLR_BIT(RCC_CFGR,PPRE11);
                          CLR_BIT(RCC_CFGR,PPRE12);  break;
         case APB1_PRESCALE_2: CLR_BIT(RCC_CFGR,PPRE10); CLR_BIT(RCC_CFGR,PPRE11);
                          SET_BIT(RCC_CFGR,PPRE12);  break;
         case APB1_PRESCALE_4: SET_BIT(RCC_CFGR,PPRE10); CLR_BIT(RCC_CFGR,PPRE11);
                          SET_BIT(RCC_CFGR,PPRE12);  break;
         case APB1_PRESCALE_8: CLR_BIT(RCC_CFGR,PPRE10); SET_BIT(RCC_CFGR,PPRE11);
                          SET_BIT(RCC_CFGR,PPRE12);  break;
         case APB1_PRESCALE_16:SET_BIT(RCC_CFGR,PPRE10); SET_BIT(RCC_CFGR,PPRE11);
                          SET_BIT(RCC_CFGR,PPRE12);  break;
      }
      switch(parameter.APB2_Prescaler)
      {
	 case APB2_NO_PRESCALE:CLR_BIT(RCC_CFGR,PPRE20); CLR_BIT(RCC_CFGR,PPRE21);
                          CLR_BIT(RCC_CFGR,PPRE22);  break;
         case APB2_PRESCALE_2: CLR_BIT(RCC_CFGR,PPRE20); CLR_BIT(RCC_CFGR,PPRE21);
                          SET_BIT(RCC_CFGR,PPRE22);  break;
         case APB2_PRESCALE_4: SET_BIT(RCC_CFGR,PPRE20); CLR_BIT(RCC_CFGR,PPRE21);
                          SET_BIT(RCC_CFGR,PPRE22);  break;
         case APB2_PRESCALE_8: CLR_BIT(RCC_CFGR,PPRE20); SET_BIT(RCC_CFGR,PPRE21);
                          SET_BIT(RCC_CFGR,PPRE22);  break;
         case APB2_PRESCALE_16:SET_BIT(RCC_CFGR,PPRE20); SET_BIT(RCC_CFGR,PPRE21);
                          SET_BIT(RCC_CFGR,PPRE22);  break;
      }
      if(parameter.PLL_Clk_Src == PLL_HSI_2)
      {
         CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
         CLR_BIT(RCC_CFGR,PLLSRC);
         SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
      }
      else if(parameter.PLL_Clk_Src == PLL_HSE)
      {
         CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
         SET_BIT(RCC_CFGR,PLLSRC);
         SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
      }
      if(parameter.PLL_For_HSE_Clk_Src == HSE)
      {
         CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
         CLR_BIT(RCC_CFGR, PLLXTPRE);
         SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
      }
      else if(parameter.PLL_For_HSE_Clk_Src == HSE_2)
      {
         CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
         SET_BIT(RCC_CFGR,PLLXTPRE);
         SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
      }
      switch(parameter.PLL_Factor)
      {
         
	 case MULTIPLY_BY_2: CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
                             CLR_BIT(RCC_CFGR,PLLMUL0); CLR_BIT(RCC_CFGR,PLLMUL1);
                             CLR_BIT(RCC_CFGR,PLLMUL2); CLR_BIT(RCC_CFGR,PLLMUL3);
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON                                                break;
         case MULTIPLY_BY_3: CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
                             SET_BIT(RCC_CFGR,PLLMUL0); CLR_BIT(RCC_CFGR,PLLMUL1);
                             CLR_BIT(RCC_CFGR,PLLMUL2); CLR_BIT(RCC_CFGR,PLLMUL3);
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
                                   break;
         case MULTIPLY_BY_4: CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
                             CLR_BIT(RCC_CFGR,PLLMUL0); SET_BIT(RCC_CFGR,PLLMUL1);
                             CLR_BIT(RCC_CFGR,PLLMUL2); CLR_BIT(RCC_CFGR,PLLMUL3);
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
                                   break;
         case MULTIPLY_BY_5: CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
                             SET_BIT(RCC_CFGR,PLLMUL0); SET_BIT(RCC_CFGR,PLLMUL1);
                             CLR_BIT(RCC_CFGR,PLLMUL2); CLR_BIT(RCC_CFGR,PLLMUL3);                              
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
                                 break;
         case MULTIPLY_BY_6: CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
                             CLR_BIT(RCC_CFGR,PLLMUL0); CLR_BIT(RCC_CFGR,PLLMUL1);
                             SET_BIT(RCC_CFGR,PLLMUL2); CLR_BIT(RCC_CFGR,PLLMUL3);
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
                                   break;
         case MULTIPLY_BY_7: CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
                             SET_BIT(RCC_CFGR,PLLMUL0); CLR_BIT(RCC_CFGR,PLLMUL1);
                             SET_BIT(RCC_CFGR,PLLMUL2); CLR_BIT(RCC_CFGR,PLLMUL3);
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
                                   break;
         case MULTIPLY_BY_8: CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
                             CLR_BIT(RCC_CFGR,PLLMUL0); SET_BIT(RCC_CFGR,PLLMUL1);
                             SET_BIT(RCC_CFGR,PLLMUL2); CLR_BIT(RCC_CFGR,PLLMUL3); 
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
                                  break;
          case MULTIPLY_BY_9:CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF 
                             SET_BIT(RCC_CFGR,PLLMUL0);SET_BIT(RCC_CFGR,PLLMUL1);
                             SET_BIT(RCC_CFGR,PLLMUL2); CLR_BIT(RCC_CFGR,PLLMUL3);
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
                                   break;
          case MULTIPLY_BY_10: CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
                               CLR_BIT(RCC_CFGR,PLLMUL0);CLR_BIT(RCC_CFGR,PLLMUL1);
                             CLR_BIT(RCC_CFGR,PLLMUL2); SET_BIT(RCC_CFGR,PLLMUL3);                              
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
                                    break;
         case MULTIPLY_BY_11: CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
                              SET_BIT(RCC_CFGR,PLLMUL0);CLR_BIT(RCC_CFGR,PLLMUL1);
                             CLR_BIT(RCC_CFGR,PLLMUL2); SET_BIT(RCC_CFGR,PLLMUL3);                              
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
                                    break;
         case MULTIPLY_BY_12: CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
                              CLR_BIT(RCC_CFGR,PLLMUL0);SET_BIT(RCC_CFGR,PLLMUL1);
                             CLR_BIT(RCC_CFGR,PLLMUL2); SET_BIT(RCC_CFGR,PLLMUL3);                               
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
                                       break;
         case MULTIPLY_BY_13: CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
                             SET_BIT(RCC_CFGR,PLLMUL0);SET_BIT(RCC_CFGR,PLLMUL1);
                             CLR_BIT(RCC_CFGR,PLLMUL2); SET_BIT(RCC_CFGR,PLLMUL3);                             
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
                                       break;
         case MULTIPLY_BY_14:CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
                             CLR_BIT(RCC_CFGR,PLLMUL0); CLR_BIT(RCC_CFGR,PLLMUL1);
                             SET_BIT(RCC_CFGR,PLLMUL2); SET_BIT(RCC_CFGR,PLLMUL3);                             
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
                                        break;
         case MULTIPLY_BY_15:CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
                             SET_BIT(RCC_CFGR,PLLMUL0); CLR_BIT(RCC_CFGR,PLLMUL1);
                             SET_BIT(RCC_CFGR,PLLMUL2); SET_BIT(RCC_CFGR,PLLMUL3);                              
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
                                        break;
         case MULTIPLY_BY_16:CLR_BIT(RCC_CR,PLLON);  // SWITCH PLL OFF
                             CLR_BIT(RCC_CFGR,PLLMUL0); SET_BIT(RCC_CFGR,PLLMUL1);
                             SET_BIT(RCC_CFGR,PLLMUL2); SET_BIT(RCC_CFGR,PLLMUL3);                              
                             SET_BIT(RCC_CR,PLLON);  // SWITCH PLL ON
                                         break;
      }
     switch(parameter.MC_Clk_Output)
      {
	 case MC_NO_CLK: CLR_BIT(RCC_CFGR,MCO0); CLR_BIT(RCC_CFGR,MCO1);
                      CLR_BIT(RCC_CFGR,MCO2);  break;
         case MC_SYSCLK: CLR_BIT(RCC_CFGR,MCO0); CLR_BIT(RCC_CFGR,MCO1);
                      SET_BIT(RCC_CFGR,MCO2);  break;
         case MC_HSI:    SET_BIT(RCC_CFGR,MCO0); CLR_BIT(RCC_CFGR,MCO1);
                      SET_BIT(RCC_CFGR,MCO2);  break;
         case MC_HSE:    CLR_BIT(RCC_CFGR,MCO0); SET_BIT(RCC_CFGR,MCO1);
                      SET_BIT(RCC_CFGR,MCO2);  break;
         case MC_PLL:    SET_BIT(RCC_CFGR,MCO0); SET_BIT(RCC_CFGR,MCO1);
                      SET_BIT(RCC_CFGR,MCO2);  break;
      }
 }
void		RCC_voidEnablePerClk(u8 BusId , u8 PerId)
{
	/*		Range Check							*/
	if(PerId < 32)
	{
		switch(BusId)
		{
			case	RCC_AHB		:	SET_BIT(RCC_AHBENR,PerId) ;	break;
			case	RCC_APB1	:	SET_BIT(RCC_APB1ENR,PerId);	break;
			case	RCC_APB2	:	SET_BIT(RCC_APB2ENR,PerId);	break;
		}
		
	}
	else{	/*	Return Error "Out Of The Range"		*/	}
	
}
void		RCC_voidDisablePerClk(u8 BusId , u8 PerId)
{
	/*		Range Check							*/
	if(PerId < 32)
	{
		switch(BusId)
		{
			case	RCC_AHB		:	CLR_BIT(RCC_AHBENR,PerId) ;	break;
			case	RCC_APB1	:	CLR_BIT(RCC_APB1ENR,PerId);	break;
			case	RCC_APB2	:	CLR_BIT(RCC_APB2ENR,PerId);	break;
		}
		
	}
	else{	/*	Return Error "Out Of The Range"		*/	}	
}
