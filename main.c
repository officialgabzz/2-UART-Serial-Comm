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

char msg[20];
char rcx[20], rcxx[20];
int SERIALcase,rxd_cnt, msg_cnt, rxd_cnt2, SERIALcase2 = 1; //srl = 2, i = 0;
CYBIT PBflag,RXDcmpt,OKflag, MSGflag = 0, NEWmsg = 0;

//Function Prototypes 
//******************************************

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    ISR_int();
    UART_Start();
    //UARTT_Start();
    //UARTT_UartPutString("Started 2 UART");
    /* Place your application code here. */
    	while(!PBflag)
    	{
    		if(RXDcmpt)   																							 //Check if MCU recieved a value
    		{
    		    confirmPBready();																					 //Check if its PBready.
                if(!PBflag)
    			{ 
    				rxd_cnt = 0;
                    memset(rcx, '\000', 20);
    				RXDcmpt = 0;
                }
            }
        }
            //UARTT_UartPutString("PB rcxd");
            rxd_cnt=PBflag=RXDcmpt=OKflag= 0;
            memset(rcx, '\000', 20);
            UART_PutString("ATE0\r");
            CyDelay(1000);
            memset(rcx, '\000', 20);
            rxd_cnt = PBflag = RXDcmpt =OKflag= 0;

            UART_PutString("AT+CMGF=1\r");
            CyDelay(1500);
           while(!OKflag)
    	    {
    		    if(RXDcmpt)  					
    			    confirmOK();    	
            }            
            //CyDelay(6000);  
            rxd_cnt = PBflag = RXDcmpt =OKflag= 0;
	        memset(rcx, '\000', 20);
            // Configure modem to GSM mode
            UART_PutString("AT+CSCS=\"GSM\"\r");
            CyDelay(1000);            
            while(!OKflag)
    	    {
    		    if(RXDcmpt)  					
    			    confirmOK();    																						//Check if its OK.
            }
            rxd_cnt = PBflag = RXDcmpt = OKflag = 0;
	        memset(rcx, '\000', 20);
            UART_PutString("AT+CNMI=2,2,0,0,0\r");
            CyDelay(1000); 
            while(!OKflag)
    	    {
    		    if(RXDcmpt)  					
    			    confirmOK();    																						//Check if its OK.
            }
            rxd_cnt = PBflag = RXDcmpt = 0;
	        memset(rcx, '\000', 20);
            CyDelay(2500);
            
    for(;;)
    {
        if(MSGflag)
        {
            //while(rxd_cnt < 19);
            strncpy(msg,rcx, rxd_cnt);
            UART_PutString(msg);
            CyDelay(1500);
            UARTT_Start();
            CyDelay(1500);
            UARTT_UartPutString(msg);
            CyDelay(1000);
            rxd_cnt = 0;
            MSGflag = 0;
            memset(rcx, '\000', 20);
            memset(msg, '\000', 20);
        }  
        //if(UART_ReadRxStatus() & UART_RX_STS_FIFO_NOTEMPTY)
        if(NEWmsg)
        {
            UART_Start();
            UART_PutString("AT+CMGS = \"08030734800\"");
            CyDelay(1500);
            UART_PutString(rcxx);
            CyDelay(1500);
            UART_PutChar(0x1A); 
            memset(rcx, '\000', 20);
            NEWmsg = 0;
        }
    }
    return 0;
}





void confirmOK()
{
	if( COMP_buff2buff(rcx ,"OK", 2))							
		OKflag = 1;                     									 
  return;
}



CYBIT COMP_buff2buff( char *BUFF1, char *BUFF2, char LEN)
{
	while(LEN)
	{
	    if(*BUFF1++ != *BUFF2++)	
		{
			RXDcmpt = 0;
            return 0;     		
        }
       LEN--;                		
    }
																												//all values are the same in both buffers.
	return 1;
}


void confirmPBready()
{
	if(COMP_buff2buff(rcx,"+PBREADY", rxd_cnt)) 
	{
		PBflag = 1;       
  }	
    
	return;
    
    
}

/*
*********************************************************
**********************GPRS AT CMD************************
*********************************************************
AT+XISP=0 //Select the internal protocol stack of the modem
OK
 AT+CGDCONT=1,”IP”,”web.gprs.mtnnigeria.net” 
 //Set GPRS context
OK

AT+XGAUTH=1,1,”web”,”web” 
 
OK

AT+XIIC=1 //Establish PPP link
OK
 AT+XIIC?   == <\r><\n>+XIIC:    1, 10.80.48.126<\r><\n><\r><\n>OK<\r><\n>
How the reply would look like, the others would get reply with ok if 
successful
if( strstr((char *)gRecieveBuffer,"+PBREADY")>0 )
*/

/* [] END OF FILE */
