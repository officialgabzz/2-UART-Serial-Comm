/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "funDeclare.h"

CY_ISR_PROTO(rx_isr_Handler);
CY_ISR_PROTO(rx_isr_Handler2);
extern char RCX_BUFF1[10],RCX_BUFF2[10];
extern int rxd_cnt;
extern CYBIT rf, rf2;
void ISR_int(void)
{
    UART_isr_StartEx(rx_isr_Handler);           //Initialize UART ISR and Start.
    UARTT_isr_StartEx(rx_isr_Handler2);
    return;
}

CY_ISR(rx_isr_Handler)
{
    char value, RXD_VAL = UART_UartGetChar();
        RCX_BUFF1[rxd_cnt++] = RXD_VAL;
        value = UART_GetRxInterruptSource();
        if(RXD_VAL =='!')
            rf=1;
    
    UART_CLEAR_RX_FIFO;    
    UART_ClearRxInterruptSource(value); 
}

CY_ISR(rx_isr_Handler2)
{
    char value, RXD_VAL = UARTT_UartGetChar();
        RCX_BUFF2[rxd_cnt++] = RXD_VAL;
        value = UARTT_GetRxInterruptSource();
        if(RXD_VAL =='!')
            rf2=1;
    
    UARTT_CLEAR_RX_FIFO;
    UARTT_ClearRxInterruptSource(value); 
}

/* [] END OF FILE */
