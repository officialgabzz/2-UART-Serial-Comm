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
#include "fun_defs.h"

//extern char message[30];
extern char rcx[20], rcxx[20];
extern char pbready[];
extern char ok[];
extern int SERIALcase,rxd_cnt,msg_cnt,rxd_cnt2, SERIALcase2;
extern CYBIT PBflag,RXDcmpt,OKflag, MSGflag,NEWmsg;
CY_ISR_PROTO(rx_isr_Handler);
CY_ISR_PROTO(rx_isr_Handler2);

void ISR_int(void)
{
    PBflag = RXDcmpt = rxd_cnt = OKflag = 0;    //Clear all ISR valurable to their defaults.
    SERIALcase = 11;                             //Set switch case to case 1.
    UART_isr_StartEx(rx_isr_Handler);           //Initialize UART ISR and Start.
    UARTT_isr_StartEx(rx_isr_Handler2);
    return;
}


CY_ISR(rx_isr_Handler)
{
    char RXD_VAL;
    RXD_VAL = UART_GetChar;
    msg_cnt = 0;
    switch(SERIALcase)
    {
   /*********************************************************/			
    	case 11:
            if(( RXD_VAL == CR && rxd_cnt == 0 ) || (RXD_VAL == LF && rxd_cnt == 0))
    		    break;
            else
            {
            rxd_cnt = 0;
            rcx[rxd_cnt++] = RXD_VAL;
            SERIALcase = 22;
            }
    	break;
    	/*********************************************************/			
        case 22:	
            if(RXD_VAL == 'C')
            {
//                MSGflag = 1;
                SERIALcase = 44;
                rxd_cnt = 0;
                break;
            }
    		rcx[rxd_cnt++] = RXD_VAL;
            if(RXD_VAL == CR)
                SERIALcase  = 33;  
        break;
     	/*********************************************************/			
    	case 33:	//get the message now.
    	    if(RXD_VAL == LF)
    		{
        	    RXDcmpt = 1;   
        		SERIALcase  = 11;
        		rxd_cnt-=1;
                UART_ClearRxBuffer(); 
    		}	
            else
    		{
        	    rcx[rxd_cnt++] = RXD_VAL;   
        	    SERIALcase = 22;            
            }
    	break;
        case 44:         
            if(RXD_VAL == LF)
            {
                rcx[rxd_cnt] = RXD_VAL;
                SERIALcase =55;
            }
        break;
        case 55:
            //rcx[rxd_cnt++] = RXD_VAL;
            if(RXD_VAL == CR)
            {
                SERIALcase = 11;
                MSGflag = 1;
            } 
            else
                rcx[rxd_cnt++] = RXD_VAL;
        break;
          
    	/*********************************************************/			
    }
}

CY_ISR_PROTO(rx_isr_Handler2)
{
    unsigned char RXDval;
    RXDval = UARTT_UartGetChar();
    switch(SERIALcase2)
    {
    case 1:
        if(RXDval == CR || RXDval == LF)
        break;
        rxd_cnt2 = 0;
        rcxx[rxd_cnt2++] = RXDval;
        SERIALcase2 = 2;
    break;    
    case 2:
        if(RXDval == CR)
            SERIALcase2 = 3;
        rcxx[rxd_cnt2++] = RXDval;
    break;
    case 3:
        if(RXDval == LF)
        {
            rxd_cnt2 = 0;
            SERIALcase2 = NEWmsg= 1;
            rxd_cnt2-=1;
            break;
        }
        else
        {
        rcxx[rxd_cnt2++] = RXDval;
        break;
        } 
    }
    


}

/* [] END OF FILE */
