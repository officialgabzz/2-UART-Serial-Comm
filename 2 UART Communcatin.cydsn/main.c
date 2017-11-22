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


char RCX_BUFF1[10];
char RCX_BUFF2[10];
int rxd_cnt;
CYBIT rf=0, rf2 =0;
int main(void)
{
    ISR_int();
    CyGlobalIntEnable; /* Enable global interrupts. */
    rxd_cnt=0;
    UART_Start();
    UARTT_Start();
    
   
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if(rf)
        {
        UARTT_UartPutString(RCX_BUFF1);
        rxd_cnt=rf=0;
        }
        if(rf2)
        {
        UART_UartPutString(RCX_BUFF2);
        rxd_cnt=rf2=0;
        }
        
            
         
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
