#ifndef		EXTI_INTERFACE_H
#define		EXTI_INTERFACE_H


typedef enum
{
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	EXTI5,
	EXTI6,
	EXTI7,
	EXTI8,
	EXTI9,
	EXTI10,
	EXTI11,
	EXTI12,
	EXTI13,
	EXTI14,
	EXTI15
}EXT_INT_option;

typedef enum
{
	EXTI_PORTA,
	EXTI_PORTB,
	EXTI_PORTC
}EXT_INT_port;

typedef enum
{
	RISING_EDGE ,
	FALLING_EDGE ,
	IOC
}EXT_INT_sense;



void		EXTI_voidInit(EXT_INT_option option,EXT_INT_port port);
void		EXTI_voidDisableInt(EXT_INT_option option);

void		EXTI_voidEnableSWI(EXT_INT_option option);
void		EXTI_voidChangeSenseMode(EXT_INT_option option, EXT_INT_sense Sense_Mode);


void		EXTI0_voidSetCallBack(void (*Fptr)(void));
void	    EXTI1_voidSetCallBack(void (*Fptr)(void));
void	    EXTI2_voidSetCallBack(void (*Fptr)(void));
void	    EXTI3_voidSetCallBack(void (*Fptr)(void));
void	    EXTI4_voidSetCallBack(void (*Fptr)(void));
void	    EXTI5_voidSetCallBack(void (*Fptr)(void));
void	    EXTI6_voidSetCallBack(void (*Fptr)(void));
void		EXTI7_voidSetCallBack(void (*Fptr)(void));
void	    EXTI8_voidSetCallBack(void (*Fptr)(void));
void	    EXTI9_voidSetCallBack(void (*Fptr)(void));
void	    EXTI10_voidSetCallBack(void (*Fptr)(void));
void	    EXTI11_voidSetCallBack(void (*Fptr)(void));
void	    EXTI12_voidSetCallBack(void (*Fptr)(void));
void	    EXTI13_voidSetCallBack(void (*Fptr)(void));
void		EXTI14_voidSetCallBack(void (*Fptr)(void));
void	    EXTI15_voidSetCallBack(void (*Fptr)(void));


#endif
