#ifndef		UART_INTERFACE_H
#define		UART_INTERFACE_H

/*
in the main:
1- Enable UART(1,2,3) RCC
2- GPIO => Alternate Function A9 (Tx) Direction OUTPUT AF_PP
3- GPIO A10 (Rx) Direction INPUT_FLOAT
*/


void UART_init(void);
void UART_enableTX(void);
void UART_enableRX(void);
void UART_TXdata(u8 data);
void UART_RXdata (u8 *data );
void UART1_voidSendString(u8 * const str);
u8 * const UART1_StrReceiveString(void);
void UART_disableTX(void);
void UART_disableRX(void);


#endif





