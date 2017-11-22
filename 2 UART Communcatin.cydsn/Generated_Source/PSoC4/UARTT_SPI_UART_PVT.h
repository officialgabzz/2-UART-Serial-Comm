/***************************************************************************//**
* \file UARTT_SPI_UART_PVT.h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_PVT_UARTT_H)
#define CY_SCB_SPI_UART_PVT_UARTT_H

#include "UARTT_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if (UARTT_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  UARTT_rxBufferHead;
    extern volatile uint32  UARTT_rxBufferTail;
    
    /**
    * \addtogroup group_globals
    * @{
    */
    
    /** Sets when internal software receive buffer overflow
     *  was occurred.
    */  
    extern volatile uint8   UARTT_rxBufferOverflow;
    /** @} globals */
#endif /* (UARTT_INTERNAL_RX_SW_BUFFER_CONST) */

#if (UARTT_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  UARTT_txBufferHead;
    extern volatile uint32  UARTT_txBufferTail;
#endif /* (UARTT_INTERNAL_TX_SW_BUFFER_CONST) */

#if (UARTT_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 UARTT_rxBufferInternal[UARTT_INTERNAL_RX_BUFFER_SIZE];
#endif /* (UARTT_INTERNAL_RX_SW_BUFFER) */

#if (UARTT_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 UARTT_txBufferInternal[UARTT_TX_BUFFER_SIZE];
#endif /* (UARTT_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

void UARTT_SpiPostEnable(void);
void UARTT_SpiStop(void);

#if (UARTT_SCB_MODE_SPI_CONST_CFG)
    void UARTT_SpiInit(void);
#endif /* (UARTT_SCB_MODE_SPI_CONST_CFG) */

#if (UARTT_SPI_WAKE_ENABLE_CONST)
    void UARTT_SpiSaveConfig(void);
    void UARTT_SpiRestoreConfig(void);
#endif /* (UARTT_SPI_WAKE_ENABLE_CONST) */

void UARTT_UartPostEnable(void);
void UARTT_UartStop(void);

#if (UARTT_SCB_MODE_UART_CONST_CFG)
    void UARTT_UartInit(void);
#endif /* (UARTT_SCB_MODE_UART_CONST_CFG) */

#if (UARTT_UART_WAKE_ENABLE_CONST)
    void UARTT_UartSaveConfig(void);
    void UARTT_UartRestoreConfig(void);
#endif /* (UARTT_UART_WAKE_ENABLE_CONST) */


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in UARTT_SetPins() */
#define UARTT_UART_RX_PIN_ENABLE    (UARTT_UART_RX)
#define UARTT_UART_TX_PIN_ENABLE    (UARTT_UART_TX)

/* UART RTS and CTS position to be used in  UARTT_SetPins() */
#define UARTT_UART_RTS_PIN_ENABLE    (0x10u)
#define UARTT_UART_CTS_PIN_ENABLE    (0x20u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Interrupt processing */
#define UARTT_SpiUartEnableIntRx(intSourceMask)  UARTT_SetRxInterruptMode(intSourceMask)
#define UARTT_SpiUartEnableIntTx(intSourceMask)  UARTT_SetTxInterruptMode(intSourceMask)
uint32  UARTT_SpiUartDisableIntRx(void);
uint32  UARTT_SpiUartDisableIntTx(void);


#endif /* (CY_SCB_SPI_UART_PVT_UARTT_H) */


/* [] END OF FILE */
