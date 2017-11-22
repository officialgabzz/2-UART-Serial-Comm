/***************************************************************************//**
* \file UARTT_SPI_UART.c
* \version 3.20
*
* \brief
*  This file provides the source code to the API for the SCB Component in
*  SPI and UART modes.
*
* Note:
*
*******************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UARTT_PVT.h"
#include "UARTT_SPI_UART_PVT.h"

/***************************************
*        SPI/UART Private Vars
***************************************/

#if(UARTT_INTERNAL_RX_SW_BUFFER_CONST)
    /* Start index to put data into the software receive buffer.*/
    volatile uint32 UARTT_rxBufferHead;
    /* Start index to get data from the software receive buffer.*/
    volatile uint32 UARTT_rxBufferTail;
    /**
    * \addtogroup group_globals
    * \{
    */
    /** Sets when internal software receive buffer overflow
    *  was occurred.
    */
    volatile uint8  UARTT_rxBufferOverflow;
    /** \} globals */
#endif /* (UARTT_INTERNAL_RX_SW_BUFFER_CONST) */

#if(UARTT_INTERNAL_TX_SW_BUFFER_CONST)
    /* Start index to put data into the software transmit buffer.*/
    volatile uint32 UARTT_txBufferHead;
    /* Start index to get data from the software transmit buffer.*/
    volatile uint32 UARTT_txBufferTail;
#endif /* (UARTT_INTERNAL_TX_SW_BUFFER_CONST) */

#if(UARTT_INTERNAL_RX_SW_BUFFER)
    /* Add one element to the buffer to receive full packet. One byte in receive buffer is always empty */
    volatile uint8 UARTT_rxBufferInternal[UARTT_INTERNAL_RX_BUFFER_SIZE];
#endif /* (UARTT_INTERNAL_RX_SW_BUFFER) */

#if(UARTT_INTERNAL_TX_SW_BUFFER)
    volatile uint8 UARTT_txBufferInternal[UARTT_TX_BUFFER_SIZE];
#endif /* (UARTT_INTERNAL_TX_SW_BUFFER) */


#if(UARTT_RX_DIRECTION)
    /*******************************************************************************
    * Function Name: UARTT_SpiUartReadRxData
    ****************************************************************************//**
    *
    *  Retrieves the next data element from the receive buffer.
    *   - RX software buffer is disabled: Returns data element retrieved from
    *     RX FIFO. Undefined data will be returned if the RX FIFO is empty.
    *   - RX software buffer is enabled: Returns data element from the software
    *     receive buffer. Zero value is returned if the software receive buffer
    *     is empty.
    *
    * \return
    *  Next data element from the receive buffer. 
    *  The amount of data bits to be received depends on RX data bits selection 
    *  (the data bit counting starts from LSB of return value).
    *
    * \globalvars
    *  UARTT_rxBufferHead - the start index to put data into the 
    *  software receive buffer.
    *  UARTT_rxBufferTail - the start index to get data from the 
    *  software receive buffer.
    *
    *******************************************************************************/
    uint32 UARTT_SpiUartReadRxData(void)
    {
        uint32 rxData = 0u;

    #if (UARTT_INTERNAL_RX_SW_BUFFER_CONST)
        uint32 locTail;
    #endif /* (UARTT_INTERNAL_RX_SW_BUFFER_CONST) */

        #if (UARTT_CHECK_RX_SW_BUFFER)
        {
            if (UARTT_rxBufferHead != UARTT_rxBufferTail)
            {
                /* There is data in RX software buffer */

                /* Calculate index to read from */
                locTail = (UARTT_rxBufferTail + 1u);

                if (UARTT_INTERNAL_RX_BUFFER_SIZE == locTail)
                {
                    locTail = 0u;
                }

                /* Get data from RX software buffer */
                rxData = UARTT_GetWordFromRxBuffer(locTail);

                /* Change index in the buffer */
                UARTT_rxBufferTail = locTail;

                #if (UARTT_CHECK_UART_RTS_CONTROL_FLOW)
                {
                    /* Check if RX Not Empty is disabled in the interrupt */
                    if (0u == (UARTT_INTR_RX_MASK_REG & UARTT_INTR_RX_NOT_EMPTY))
                    {
                        /* Enable RX Not Empty interrupt source to continue
                        * receiving data into software buffer.
                        */
                        UARTT_INTR_RX_MASK_REG |= UARTT_INTR_RX_NOT_EMPTY;
                    }
                }
                #endif

            }
        }
        #else
        {
            /* Read data from RX FIFO */
            rxData = UARTT_RX_FIFO_RD_REG;
        }
        #endif

        return (rxData);
    }


    /*******************************************************************************
    * Function Name: UARTT_SpiUartGetRxBufferSize
    ****************************************************************************//**
    *
    *  Returns the number of received data elements in the receive buffer.
    *   - RX software buffer disabled: returns the number of used entries in
    *     RX FIFO.
    *   - RX software buffer enabled: returns the number of elements which were
    *     placed in the receive buffer. This does not include the hardware RX FIFO.
    *
    * \return
    *  Number of received data elements.
    *
    * \globalvars
    *  UARTT_rxBufferHead - the start index to put data into the 
    *  software receive buffer.
    *  UARTT_rxBufferTail - the start index to get data from the 
    *  software receive buffer.
    *
    *******************************************************************************/
    uint32 UARTT_SpiUartGetRxBufferSize(void)
    {
        uint32 size;
    #if (UARTT_INTERNAL_RX_SW_BUFFER_CONST)
        uint32 locHead;
    #endif /* (UARTT_INTERNAL_RX_SW_BUFFER_CONST) */

        #if (UARTT_CHECK_RX_SW_BUFFER)
        {
            locHead = UARTT_rxBufferHead;

            if(locHead >= UARTT_rxBufferTail)
            {
                size = (locHead - UARTT_rxBufferTail);
            }
            else
            {
                size = (locHead + (UARTT_INTERNAL_RX_BUFFER_SIZE - UARTT_rxBufferTail));
            }
        }
        #else
        {
            size = UARTT_GET_RX_FIFO_ENTRIES;
        }
        #endif

        return (size);
    }


    /*******************************************************************************
    * Function Name: UARTT_SpiUartClearRxBuffer
    ****************************************************************************//**
    *
    *  Clears the receive buffer and RX FIFO.
    *
    * \globalvars
    *  UARTT_rxBufferHead - the start index to put data into the 
    *  software receive buffer.
    *  UARTT_rxBufferTail - the start index to get data from the 
    *  software receive buffer.
    *
    *******************************************************************************/
    void UARTT_SpiUartClearRxBuffer(void)
    {
        #if (UARTT_CHECK_RX_SW_BUFFER)
        {
            /* Lock from component interruption */
            UARTT_DisableInt();

            /* Flush RX software buffer */
            UARTT_rxBufferHead = UARTT_rxBufferTail;
            UARTT_rxBufferOverflow = 0u;

            UARTT_CLEAR_RX_FIFO;
            UARTT_ClearRxInterruptSource(UARTT_INTR_RX_ALL);

            #if (UARTT_CHECK_UART_RTS_CONTROL_FLOW)
            {
                /* Enable RX Not Empty interrupt source to continue receiving
                * data into software buffer.
                */
                UARTT_INTR_RX_MASK_REG |= UARTT_INTR_RX_NOT_EMPTY;
            }
            #endif
            
            /* Release lock */
            UARTT_EnableInt();
        }
        #else
        {
            UARTT_CLEAR_RX_FIFO;
        }
        #endif
    }

#endif /* (UARTT_RX_DIRECTION) */


#if(UARTT_TX_DIRECTION)
    /*******************************************************************************
    * Function Name: UARTT_SpiUartWriteTxData
    ****************************************************************************//**
    *
    *  Places a data entry into the transmit buffer to be sent at the next available
    *  bus time.
    *  This function is blocking and waits until there is space available to put the
    *  requested data in the transmit buffer.
    *
    *  \param txDataByte: the data to be transmitted.
    *   The amount of data bits to be transmitted depends on TX data bits selection 
    *   (the data bit counting starts from LSB of txDataByte).
    *
    * \globalvars
    *  UARTT_txBufferHead - the start index to put data into the 
    *  software transmit buffer.
    *  UARTT_txBufferTail - start index to get data from the software
    *  transmit buffer.
    *
    *******************************************************************************/
    void UARTT_SpiUartWriteTxData(uint32 txData)
    {
    #if (UARTT_INTERNAL_TX_SW_BUFFER_CONST)
        uint32 locHead;
    #endif /* (UARTT_INTERNAL_TX_SW_BUFFER_CONST) */

        #if (UARTT_CHECK_TX_SW_BUFFER)
        {
            /* Put data directly into the TX FIFO */
            if ((UARTT_txBufferHead == UARTT_txBufferTail) &&
                (UARTT_SPI_UART_FIFO_SIZE != UARTT_GET_TX_FIFO_ENTRIES))
            {
                /* TX software buffer is empty: put data directly in TX FIFO */
                UARTT_TX_FIFO_WR_REG = txData;
            }
            /* Put data into TX software buffer */
            else
            {
                /* Head index to put data */
                locHead = (UARTT_txBufferHead + 1u);

                /* Adjust TX software buffer index */
                if (UARTT_TX_BUFFER_SIZE == locHead)
                {
                    locHead = 0u;
                }

                /* Wait for space in TX software buffer */
                while (locHead == UARTT_txBufferTail)
                {
                }

                /* TX software buffer has at least one room */

                /* Clear old status of INTR_TX_NOT_FULL. It sets at the end of transfer when TX FIFO is empty. */
                UARTT_ClearTxInterruptSource(UARTT_INTR_TX_NOT_FULL);

                UARTT_PutWordInTxBuffer(locHead, txData);

                UARTT_txBufferHead = locHead;

                /* Check if TX Not Full is disabled in interrupt */
                if (0u == (UARTT_INTR_TX_MASK_REG & UARTT_INTR_TX_NOT_FULL))
                {
                    /* Enable TX Not Full interrupt source to transmit from software buffer */
                    UARTT_INTR_TX_MASK_REG |= (uint32) UARTT_INTR_TX_NOT_FULL;
                }
            }
        }
        #else
        {
            /* Wait until TX FIFO has space to put data element */
            while (UARTT_SPI_UART_FIFO_SIZE == UARTT_GET_TX_FIFO_ENTRIES)
            {
            }

            UARTT_TX_FIFO_WR_REG = txData;
        }
        #endif
    }


    /*******************************************************************************
    * Function Name: UARTT_SpiUartPutArray
    ****************************************************************************//**
    *
    *  Places an array of data into the transmit buffer to be sent.
    *  This function is blocking and waits until there is a space available to put
    *  all the requested data in the transmit buffer. The array size can be greater
    *  than transmit buffer size.
    *
    * \param wrBuf: pointer to an array of data to be placed in transmit buffer. 
    *  The width of the data to be transmitted depends on TX data width selection 
    *  (the data bit counting starts from LSB for each array element).
    * \param count: number of data elements to be placed in the transmit buffer.
    *
    * \globalvars
    *  UARTT_txBufferHead - the start index to put data into the 
    *  software transmit buffer.
    *  UARTT_txBufferTail - start index to get data from the software
    *  transmit buffer.
    *
    *******************************************************************************/
    void UARTT_SpiUartPutArray(const uint8 wrBuf[], uint32 count)
    {
        uint32 i;

        for (i=0u; i < count; i++)
        {
            UARTT_SpiUartWriteTxData((uint32) wrBuf[i]);
        }
    }


    /*******************************************************************************
    * Function Name: UARTT_SpiUartGetTxBufferSize
    ****************************************************************************//**
    *
    *  Returns the number of elements currently in the transmit buffer.
    *   - TX software buffer is disabled: returns the number of used entries in
    *     TX FIFO.
    *   - TX software buffer is enabled: returns the number of elements currently
    *     used in the transmit buffer. This number does not include used entries in
    *     the TX FIFO. The transmit buffer size is zero until the TX FIFO is
    *     not full.
    *
    * \return
    *  Number of data elements ready to transmit.
    *
    * \globalvars
    *  UARTT_txBufferHead - the start index to put data into the 
    *  software transmit buffer.
    *  UARTT_txBufferTail - start index to get data from the software
    *  transmit buffer.
    *
    *******************************************************************************/
    uint32 UARTT_SpiUartGetTxBufferSize(void)
    {
        uint32 size;
    #if (UARTT_INTERNAL_TX_SW_BUFFER_CONST)
        uint32 locTail;
    #endif /* (UARTT_INTERNAL_TX_SW_BUFFER_CONST) */

        #if (UARTT_CHECK_TX_SW_BUFFER)
        {
            /* Get current Tail index */
            locTail = UARTT_txBufferTail;

            if (UARTT_txBufferHead >= locTail)
            {
                size = (UARTT_txBufferHead - locTail);
            }
            else
            {
                size = (UARTT_txBufferHead + (UARTT_TX_BUFFER_SIZE - locTail));
            }
        }
        #else
        {
            size = UARTT_GET_TX_FIFO_ENTRIES;
        }
        #endif

        return (size);
    }


    /*******************************************************************************
    * Function Name: UARTT_SpiUartClearTxBuffer
    ****************************************************************************//**
    *
    *  Clears the transmit buffer and TX FIFO.
    *
    * \globalvars
    *  UARTT_txBufferHead - the start index to put data into the 
    *  software transmit buffer.
    *  UARTT_txBufferTail - start index to get data from the software
    *  transmit buffer.
    *
    *******************************************************************************/
    void UARTT_SpiUartClearTxBuffer(void)
    {
        #if (UARTT_CHECK_TX_SW_BUFFER)
        {
            /* Lock from component interruption */
            UARTT_DisableInt();

            /* Flush TX software buffer */
            UARTT_txBufferHead = UARTT_txBufferTail;

            UARTT_INTR_TX_MASK_REG &= (uint32) ~UARTT_INTR_TX_NOT_FULL;
            UARTT_CLEAR_TX_FIFO;
            UARTT_ClearTxInterruptSource(UARTT_INTR_TX_ALL);

            /* Release lock */
            UARTT_EnableInt();
        }
        #else
        {
            UARTT_CLEAR_TX_FIFO;
        }
        #endif
    }

#endif /* (UARTT_TX_DIRECTION) */


/*******************************************************************************
* Function Name: UARTT_SpiUartDisableIntRx
****************************************************************************//**
*
*  Disables the RX interrupt sources.
*
*  \return
*   Returns the RX interrupt sources enabled before the function call.
*
*******************************************************************************/
uint32 UARTT_SpiUartDisableIntRx(void)
{
    uint32 intSource;

    intSource = UARTT_GetRxInterruptMode();

    UARTT_SetRxInterruptMode(UARTT_NO_INTR_SOURCES);

    return (intSource);
}


/*******************************************************************************
* Function Name: UARTT_SpiUartDisableIntTx
****************************************************************************//**
*
*  Disables TX interrupt sources.
*
*  \return
*   Returns TX interrupt sources enabled before function call.
*
*******************************************************************************/
uint32 UARTT_SpiUartDisableIntTx(void)
{
    uint32 intSourceMask;

    intSourceMask = UARTT_GetTxInterruptMode();

    UARTT_SetTxInterruptMode(UARTT_NO_INTR_SOURCES);

    return (intSourceMask);
}


#if(UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: UARTT_PutWordInRxBuffer
    ****************************************************************************//**
    *
    *  Stores a byte/word into the RX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    *  \param index:      index to store data byte/word in the RX buffer.
    *  \param rxDataByte: byte/word to store.
    *
    *******************************************************************************/
    void UARTT_PutWordInRxBuffer(uint32 idx, uint32 rxDataByte)
    {
        /* Put data in buffer */
        if (UARTT_ONE_BYTE_WIDTH == UARTT_rxDataBits)
        {
            UARTT_rxBuffer[idx] = ((uint8) rxDataByte);
        }
        else
        {
            UARTT_rxBuffer[(uint32)(idx << 1u)]      = LO8(LO16(rxDataByte));
            UARTT_rxBuffer[(uint32)(idx << 1u) + 1u] = HI8(LO16(rxDataByte));
        }
    }


    /*******************************************************************************
    * Function Name: UARTT_GetWordFromRxBuffer
    ****************************************************************************//**
    *
    *  Reads byte/word from RX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    *  \return
    *   Returns byte/word read from RX buffer.
    *
    *******************************************************************************/
    uint32 UARTT_GetWordFromRxBuffer(uint32 idx)
    {
        uint32 value;

        if (UARTT_ONE_BYTE_WIDTH == UARTT_rxDataBits)
        {
            value = UARTT_rxBuffer[idx];
        }
        else
        {
            value  = (uint32) UARTT_rxBuffer[(uint32)(idx << 1u)];
            value |= (uint32) ((uint32)UARTT_rxBuffer[(uint32)(idx << 1u) + 1u] << 8u);
        }

        return (value);
    }


    /*******************************************************************************
    * Function Name: UARTT_PutWordInTxBuffer
    ****************************************************************************//**
    *
    *  Stores byte/word into the TX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    *  \param idx:        index to store data byte/word in the TX buffer.
    *  \param txDataByte: byte/word to store.
    *
    *******************************************************************************/
    void UARTT_PutWordInTxBuffer(uint32 idx, uint32 txDataByte)
    {
        /* Put data in buffer */
        if (UARTT_ONE_BYTE_WIDTH == UARTT_txDataBits)
        {
            UARTT_txBuffer[idx] = ((uint8) txDataByte);
        }
        else
        {
            UARTT_txBuffer[(uint32)(idx << 1u)]      = LO8(LO16(txDataByte));
            UARTT_txBuffer[(uint32)(idx << 1u) + 1u] = HI8(LO16(txDataByte));
        }
    }


    /*******************************************************************************
    * Function Name: UARTT_GetWordFromTxBuffer
    ****************************************************************************//**
    *
    *  Reads byte/word from the TX buffer.
    *  Only available in the Unconfigured operation mode.
    *
    *  \param idx: index to get data byte/word from the TX buffer.
    *
    *  \return
    *   Returns byte/word read from the TX buffer.
    *
    *******************************************************************************/
    uint32 UARTT_GetWordFromTxBuffer(uint32 idx)
    {
        uint32 value;

        if (UARTT_ONE_BYTE_WIDTH == UARTT_txDataBits)
        {
            value = (uint32) UARTT_txBuffer[idx];
        }
        else
        {
            value  = (uint32) UARTT_txBuffer[(uint32)(idx << 1u)];
            value |= (uint32) ((uint32) UARTT_txBuffer[(uint32)(idx << 1u) + 1u] << 8u);
        }

        return (value);
    }

#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */


/* [] END OF FILE */
