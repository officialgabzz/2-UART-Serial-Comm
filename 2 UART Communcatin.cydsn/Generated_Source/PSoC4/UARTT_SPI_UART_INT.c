/***************************************************************************//**
* \file UARTT_SPI_UART_INT.c
* \version 3.20
*
* \brief
*  This file provides the source code to the Interrupt Service Routine for
*  the SCB Component in SPI and UART modes.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UARTT_PVT.h"
#include "UARTT_SPI_UART_PVT.h"
#include "cyapicallbacks.h"

#if (UARTT_SCB_IRQ_INTERNAL)
/*******************************************************************************
* Function Name: UARTT_SPI_UART_ISR
****************************************************************************//**
*
*  Handles the Interrupt Service Routine for the SCB SPI or UART modes.
*
*******************************************************************************/
CY_ISR(UARTT_SPI_UART_ISR)
{
#if (UARTT_INTERNAL_RX_SW_BUFFER_CONST)
    uint32 locHead;
#endif /* (UARTT_INTERNAL_RX_SW_BUFFER_CONST) */

#if (UARTT_INTERNAL_TX_SW_BUFFER_CONST)
    uint32 locTail;
#endif /* (UARTT_INTERNAL_TX_SW_BUFFER_CONST) */

#ifdef UARTT_SPI_UART_ISR_ENTRY_CALLBACK
    UARTT_SPI_UART_ISR_EntryCallback();
#endif /* UARTT_SPI_UART_ISR_ENTRY_CALLBACK */

    if (NULL != UARTT_customIntrHandler)
    {
        UARTT_customIntrHandler();
    }

    #if(UARTT_CHECK_SPI_WAKE_ENABLE)
    {
        /* Clear SPI wakeup source */
        UARTT_ClearSpiExtClkInterruptSource(UARTT_INTR_SPI_EC_WAKE_UP);
    }
    #endif

    #if (UARTT_CHECK_RX_SW_BUFFER)
    {
        if (UARTT_CHECK_INTR_RX_MASKED(UARTT_INTR_RX_NOT_EMPTY))
        {
            do
            {
                /* Move local head index */
                locHead = (UARTT_rxBufferHead + 1u);

                /* Adjust local head index */
                if (UARTT_INTERNAL_RX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                if (locHead == UARTT_rxBufferTail)
                {
                    #if (UARTT_CHECK_UART_RTS_CONTROL_FLOW)
                    {
                        /* There is no space in the software buffer - disable the
                        * RX Not Empty interrupt source. The data elements are
                        * still being received into the RX FIFO until the RTS signal
                        * stops the transmitter. After the data element is read from the
                        * buffer, the RX Not Empty interrupt source is enabled to
                        * move the next data element in the software buffer.
                        */
                        UARTT_INTR_RX_MASK_REG &= ~UARTT_INTR_RX_NOT_EMPTY;
                        break;
                    }
                    #else
                    {
                        /* Overflow: through away received data element */
                        (void) UARTT_RX_FIFO_RD_REG;
                        UARTT_rxBufferOverflow = (uint8) UARTT_INTR_RX_OVERFLOW;
                    }
                    #endif
                }
                else
                {
                    /* Store received data */
                    UARTT_PutWordInRxBuffer(locHead, UARTT_RX_FIFO_RD_REG);

                    /* Move head index */
                    UARTT_rxBufferHead = locHead;
                }
            }
            while(0u != UARTT_GET_RX_FIFO_ENTRIES);

            UARTT_ClearRxInterruptSource(UARTT_INTR_RX_NOT_EMPTY);
        }
    }
    #endif


    #if (UARTT_CHECK_TX_SW_BUFFER)
    {
        if (UARTT_CHECK_INTR_TX_MASKED(UARTT_INTR_TX_NOT_FULL))
        {
            do
            {
                /* Check for room in TX software buffer */
                if (UARTT_txBufferHead != UARTT_txBufferTail)
                {
                    /* Move local tail index */
                    locTail = (UARTT_txBufferTail + 1u);

                    /* Adjust local tail index */
                    if (UARTT_TX_BUFFER_SIZE == locTail)
                    {
                        locTail = 0u;
                    }

                    /* Put data into TX FIFO */
                    UARTT_TX_FIFO_WR_REG = UARTT_GetWordFromTxBuffer(locTail);

                    /* Move tail index */
                    UARTT_txBufferTail = locTail;
                }
                else
                {
                    /* TX software buffer is empty: complete transfer */
                    UARTT_DISABLE_INTR_TX(UARTT_INTR_TX_NOT_FULL);
                    break;
                }
            }
            while (UARTT_SPI_UART_FIFO_SIZE != UARTT_GET_TX_FIFO_ENTRIES);

            UARTT_ClearTxInterruptSource(UARTT_INTR_TX_NOT_FULL);
        }
    }
    #endif

#ifdef UARTT_SPI_UART_ISR_EXIT_CALLBACK
    UARTT_SPI_UART_ISR_ExitCallback();
#endif /* UARTT_SPI_UART_ISR_EXIT_CALLBACK */

}

#endif /* (UARTT_SCB_IRQ_INTERNAL) */


/* [] END OF FILE */
