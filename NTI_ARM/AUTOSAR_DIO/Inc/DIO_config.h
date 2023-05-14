#ifndef		DIO_CONFIG_H
#define		DIO_CONFIG_H





#define		GPIO_INPUT_ANALOG				0000
#define		GPIO_INPUT_FLOAT				0100
#define		GPIO_INPUT_PULL_UP_DOWN			1000

#define		GPIO_OUTPUT_10MHZ_PP			0001
#define		GPIO_OUTPUT_10MHZ_OD			0101
#define		GPIO_OUTPUT_10MHZ_AFPP			1001
#define		GPIO_OUTPUT_10MHZ_AFOD			1101

#define		GPIO_OUTPUT_2MHZ_PP				0010
#define		GPIO_OUTPUT_2MHZ_OD				0110
#define		GPIO_OUTPUT_2MHZ_AFPP			1010
#define		GPIO_OUTPUT_2MHZ_AFOD			1110

#define		GPIO_OUTPUT_50MHZ_PP			0011
#define		GPIO_OUTPUT_50MHZ_OD			0111
#define		GPIO_OUTPUT_50MHZ_AFPP			1011
#define		GPIO_OUTPUT_50MHZ_AFOD			1111

/*
 Choose :
 	 	  GPIO_INPUT_ANALOG              for    Analog Input
          GPIO_INPUT_FLOAT               for    Float Input
          GPIO_INPUT_PULL_UP_DOWN        for    PULL Up / PULL Down Input
          GPIO_OUTPUT_10MHZ_PP           for    PUSH-PULL Output                     @ 10MHz
 	 	  GPIO_OUTPUT_10MHZ_OD           for    Open Drain Output                    @ 10MHz
          GPIO_OUTPUT_10MHZ_AFPP         for    Alternate Function PUSH-PULL Output  @ 10MHz
          GPIO_OUTPUT_10MHZ_AFOD         for    Alternate Function Open Drain Output @ 10MHz
          GPIO_OUTPUT_2MHZ_PP            for    PUSH-PULL Output                     @ 2MHz
 	 	  GPIO_OUTPUT_2MHZ_OD            for    Open Drain Output                    @ 2MHz
          GPIO_OUTPUT_2MHZ_AFPP          for    Alternate Function PUSH-PULL Output  @ 2MHz
          GPIO_OUTPUT_2MHZ_AFOD          for    Alternate Function Open Drain Output @ 2MHz
          GPIO_OUTPUT_50MHZ_PP           for    PUSH-PULL Output                     @ 50MHz
 	 	  GPIO_OUTPUT_50MHZ_OD           for    Open Drain Output                    @ 50MHz
          GPIO_OUTPUT_50MHZ_AFPP         for    Alternate Function PUSH-PULL Output  @ 50MHz
          GPIO_OUTPUT_50MHZ_AFOD         for    Alternate Function Open Drain Output @ 50MHz

*/
#define PIN0_DIR                  GPIO_INPUT_PULL_UP_DOWN
#define PIN1_DIR                  GPIO_INPUT_PULL_UP_DOWN
#define PIN2_DIR                  GPIO_INPUT_PULL_UP_DOWN
#define PIN3_DIR                  GPIO_OUTPUT_2MHZ_PP
#define PIN4_DIR                  GPIO_OUTPUT_2MHZ_PP
#define PIN5_DIR                  GPIO_OUTPUT_2MHZ_PP
#define PIN6_DIR                  GPIO_INPUT_PULL_UP_DOWN
#define PIN7_DIR                  GPIO_INPUT_PULL_UP_DOWN
#define PIN8_DIR                  GPIO_INPUT_PULL_UP_DOWN
#define PIN9_DIR                  GPIO_INPUT_PULL_UP_DOWN
#define PIN10_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN11_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN12_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN13_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN14_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN15_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN16_DIR                 GPIO_OUTPUT_2MHZ_PP


#define PIN17_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN18_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN19_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN20_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN21_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN22_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN23_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN24_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN25_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN26_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN27_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN28_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN29_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN30_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN31_DIR                 GPIO_OUTPUT_2MHZ_PP


#define PIN32_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN33_DIR                 GPIO_OUTPUT_2MHZ_PP
#define PIN34_DIR                 GPIO_OUTPUT_2MHZ_PP



/*
 Choose :
 	 	  GPIO_LOW  for low if output
          GPIO_HIGH for High if output
*/
#define PIN0_INITIAL_VALUE             GPIO_LOW
#define PIN1_INITIAL_VALUE             GPIO_LOW
#define PIN2_INITIAL_VALUE             GPIO_LOW
#define PIN3_INITIAL_VALUE             GPIO_LOW
#define PIN4_INITIAL_VALUE             GPIO_LOW
#define PIN5_INITIAL_VALUE             GPIO_LOW
#define PIN6_INITIAL_VALUE             GPIO_LOW
#define PIN7_INITIAL_VALUE             GPIO_LOW
#define PIN8_INITIAL_VALUE             GPIO_LOW
#define PIN9_INITIAL_VALUE             GPIO_LOW
#define PIN10_INITIAL_VALUE            GPIO_LOW
#define PIN11_INITIAL_VALUE            GPIO_LOW
#define PIN12_INITIAL_VALUE            GPIO_LOW
#define PIN13_INITIAL_VALUE            GPIO_LOW
#define PIN14_INITIAL_VALUE            GPIO_LOW
#define PIN15_INITIAL_VALUE            GPIO_LOW

#define PIN16_INITIAL_VALUE            GPIO_LOW
#define PIN17_INITIAL_VALUE            GPIO_LOW
#define PIN18_INITIAL_VALUE            GPIO_LOW
#define PIN19_INITIAL_VALUE            GPIO_LOW
#define PIN20_INITIAL_VALUE            GPIO_LOW
#define PIN21_INITIAL_VALUE            GPIO_LOW
#define PIN22_INITIAL_VALUE            GPIO_LOW
#define PIN23_INITIAL_VALUE            GPIO_LOW
#define PIN24_INITIAL_VALUE            GPIO_LOW
#define PIN25_INITIAL_VALUE            GPIO_LOW
#define PIN26_INITIAL_VALUE            GPIO_LOW
#define PIN27_INITIAL_VALUE            GPIO_LOW
#define PIN28_INITIAL_VALUE            GPIO_LOW
#define PIN29_INITIAL_VALUE            GPIO_LOW
#define PIN30_INITIAL_VALUE            GPIO_LOW
#define PIN31_INITIAL_VALUE            GPIO_HIGH


#define PIN32_INITIAL_VALUE            GPIO_LOW
#define PIN33_INITIAL_VALUE            GPIO_HIGH
#define PIN34_INITIAL_VALUE            GPIO_HIGH





#endif
