#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


#define ADC_CONVERSION_MODE              ADC_CONTINUOUS_CONVERSION_MODE
#define ADC_EXTERNAL_EVENT               ADC_SWSTART
#define ADC_DATA_ALIGNMENT               ADC_RIGHT_ALIGNMENT
#define ADC_DMA_ENABLE                   DISABLE
#define ADC_CHANNEL                      CHANNEL1



/*Options:
			CYCLES1             For 1.5   Cycles
			CYCLES2             For 7.5   Cycles
			CYCLES3             For 13.5  Cycles
			CYCLES4             For 28.5  Cycles
			CYCLES5             For 41.5  Cycles
			CYCLES6             For 55.5  Cycles
			CYCLES7             For 71.5  Cycles
			CYCLES8             For 239.5 Cycles
*/
#define ADC_CHANNEL_TIME_SELECTION       CYCLES1


#endif
