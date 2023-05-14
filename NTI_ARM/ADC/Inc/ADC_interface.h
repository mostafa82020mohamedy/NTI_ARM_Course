#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/************************************************************************/
/* You must Set the Direction of Pin0, Pin1 and Pin2 in PORTA to GPIO_INPUT_ANALOG */
/* and 	RCC_voidEnablePerClk(RCC_APB2, 9) at the First of Main */
/************************************************************************/

void	ADC_void_Init(void);
void 	ADC_Enable(void);
void 	ADC_Start(void);
u16		ADC_u16_ReadChannel	(u8 Channel_ID);



#endif
