#ifndef		EXTI_INTERFACE_H
#define		EXTI_INTERFACE_H


void		EXTI_voidInit(u8 LineNum , u8 LinePort, u8 Initial_SenseMode);
void		EXTI_voidEnableInt(u8 line_num);
void		EXTI_voidDisableInt(u8 line_num);

void		EXTI_voidEnableSWI(u8 line_num);
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode);


void		EXTI0_voidSetCallBack(void (*Fptr)(void));
void		EXTI1_voidSetCallBack(void (*Fptr)(void));
void		EXTI2_voidSetCallBack(void (*Fptr)(void));
void		EXTI3_voidSetCallBack(void (*Fptr)(void));
void		EXTI4_voidSetCallBack(void (*Fptr)(void));
void		EXTI9_5_voidSetCallBack(void (*Fptr)(void));
void		EXTI15_10_voidSetCallBack(void (*Fptr)(void));





#define LINE0                             0
#define LINE1                             1
#define LINE2                             2
#define LINE3                             3
#define LINE4                             4
#define LINE5                             5
#define LINE6                             6
#define LINE7                             7
#define LINE8                             8
#define LINE9                             9
#define LINE10                            10
#define LINE11                            11
#define LINE12                            12
#define LINE13                            13
#define LINE14                            14
#define LINE15                            15

#define EXTI0                             6
#define EXTI1                             7
#define EXTI2                             8
#define EXTI3                             9
#define EXTI4                             23
#define EXTI5                             23
#define EXTI6                             23
#define EXTI7                             23
#define EXTI8                             23
#define EXTI9                             23


#define EXTI10                            40
#define EXTI11                            40
#define EXTI12                            40
#define EXTI13                            40
#define EXTI14                            40
#define EXTI15                            40




#define    EXTI_PORTA        0b0000
#define    EXTI_PORTB        0b0001
#define    EXTI_PORTC        0b0010

#define RISING_EDGE                       1
#define FALLING_EDGE                      2
#define IOC                               3


#endif
