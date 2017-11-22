/***************************************************************************//**
* \file UARTT_UART.c
* \version 3.20
*
* \brief
*  This file provides the source code to the API for the SCB Component in
*  UART mode.
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
#include "cyapicallbacks.h"

#if (UARTT_UART_WAKE_ENABLE_CONST && UARTT_UART_RX_WAKEUP_IRQ)
    /**
    * \addtogroup group_globals
    * \{
    */
    /** This global variable determines whether to enable Skip Start
    * functionality when UARTT_Sleep() function is called:
    * 0 – disable, other values – enable. Default value is 1.
    * It is only available when Enable wakeup from Deep Sleep Mode is enabled.
    */
    uint8 UARTT_skipStart = 1u;
    /** \} globals */
#endif /* (UARTT_UART_WAKE_ENABLE_CONST && UARTT_UART_RX_WAKEUP_IRQ) */

#if(UARTT_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Configuration Structure Initialization
    ***************************************/

    const UARTT_UART_INIT_STRUCT UARTT_configUart =
    {
        UARTT_UART_SUB_MODE,
        UARTT_UART_DIRECTION,
        UARTT_UART_DATA_BITS_NUM,
        UARTT_UART_PARITY_TYPE,
        UARTT_UART_STOP_BITS_NUM,
        UARTT_UART_OVS_FACTOR,
        UARTT_UART_IRDA_LOW_POWER,
        UARTT_UART_MEDIAN_FILTER_ENABLE,
        UARTT_UART_RETRY_ON_NACK,
        UARTT_UART_IRDA_POLARITY,
        UARTT_UART_DROP_ON_PARITY_ERR,
        UARTT_UART_DROP_ON_FRAME_ERR,
        UARTT_UART_WAKE_ENABLE,
        0u,
        NULL,
        0u,
        NULL,
        UARTT_UART_MP_MODE_ENABLE,
        UARTT_UART_MP_ACCEPT_ADDRESS,
        UARTT_UART_MP_RX_ADDRESS,
        UARTT_UART_MP_RX_ADDRESS_MASK,
        (uint32) UARTT_SCB_IRQ_INTERNAL,
        UARTT_UART_INTR_RX_MASK,
        UARTT_UART_RX_TRIGGER_LEVEL,
        UARTT_UART_INTR_TX_MASK,
        UARTT_UART_TX_TRIGGER_LEVEL,
        (uint8) UARTT_UART_BYTE_MODE_ENABLE,
        (uint8) UARTT_UART_CTS_ENABLE,
        (uint8) UARTT_UART_CTS_POLARITY,
        (uint8) UARTT_UART_RTS_POLARITY,
        (uint8) UARTT_UART_RTS_FIFO_LEVEL
    };


    /*******************************************************************************
    * Function Name: UARTT_UartInit
    ****************************************************************************//**
    *
    *  Configures the UARTT for UART operation.
    *
    *  This function is intended specifically to be used when the UARTT
    *  configuration is set to “Unconfigured UARTT” in the customizer.
    *  After initializing the UARTT in UART mode using this function,
    *  the component can be enabled using the UARTT_Start() or
    * UARTT_Enable() function.
    *  This function uses a pointer to a structure that provides the configuration
    *  settings. This structure contains the same information that would otherwise
    *  be provided by the customizer settings.
    *
    *  \param config: pointer to a structure that contains the following list of
    *   fields. These fields match the selections available in the customizer.
    *   Refer to the customizer for further description of the settings.
    *
    *******************************************************************************/
    void UARTT_UartInit(const UARTT_UART_INIT_STRUCT *config)
    {
        uint32 pinsConfig;

        if (NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due to bad function parameter */
        }
        else
        {
            /* Get direction to configure UART pins: TX, RX or TX+RX */
            pinsConfig  = config->direction;

        #if !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1)
            /* Add RTS and CTS pins to configure */
            pinsConfig |= (0u != config->rtsRxFifoLevel) ? (UARTT_UART_RTS_PIN_ENABLE) : (0u);
            pinsConfig |= (0u != config->enableCts)      ? (UARTT_UART_CTS_PIN_ENABLE) : (0u);
        #endif /* !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1) */

            /* Configure pins */
            UARTT_SetPins(UARTT_SCB_MODE_UART, config->mode, pinsConfig);

            /* Store internal configuration */
            UARTT_scbMode       = (uint8) UARTT_SCB_MODE_UART;
            UARTT_scbEnableWake = (uint8) config->enableWake;
            UARTT_scbEnableIntr = (uint8) config->enableInterrupt;

            /* Set RX direction internal variables */
            UARTT_rxBuffer      =         config->rxBuffer;
            UARTT_rxDataBits    = (uint8) config->dataBits;
            UARTT_rxBufferSize  = (uint8) config->rxBufferSize;

            /* Set TX direction internal variables */
            UARTT_txBuffer      =         config->txBuffer;
            UARTT_txDataBits    = (uint8) config->dataBits;
            UARTT_txBufferSize  = (uint8) config->txBufferSize;

            /* Configure UART interface */
            if(UARTT_UART_MODE_IRDA == config->mode)
            {
                /* OVS settings: IrDA */
                UARTT_CTRL_REG  = ((0u != config->enableIrdaLowPower) ?
                                                (UARTT_UART_GET_CTRL_OVS_IRDA_LP(config->oversample)) :
                                                (UARTT_CTRL_OVS_IRDA_OVS16));
            }
            else
            {
                /* OVS settings: UART and SmartCard */
                UARTT_CTRL_REG  = UARTT_GET_CTRL_OVS(config->oversample);
            }

            UARTT_CTRL_REG     |= UARTT_GET_CTRL_BYTE_MODE  (config->enableByteMode)      |
                                             UARTT_GET_CTRL_ADDR_ACCEPT(config->multiprocAcceptAddr) |
                                             UARTT_CTRL_UART;

            /* Configure sub-mode: UART, SmartCard or IrDA */
            UARTT_UART_CTRL_REG = UARTT_GET_UART_CTRL_MODE(config->mode);

            /* Configure RX direction */
            UARTT_UART_RX_CTRL_REG = UARTT_GET_UART_RX_CTRL_MODE(config->stopBits)              |
                                        UARTT_GET_UART_RX_CTRL_POLARITY(config->enableInvertedRx)          |
                                        UARTT_GET_UART_RX_CTRL_MP_MODE(config->enableMultiproc)            |
                                        UARTT_GET_UART_RX_CTRL_DROP_ON_PARITY_ERR(config->dropOnParityErr) |
                                        UARTT_GET_UART_RX_CTRL_DROP_ON_FRAME_ERR(config->dropOnFrameErr);

            if(UARTT_UART_PARITY_NONE != config->parity)
            {
               UARTT_UART_RX_CTRL_REG |= UARTT_GET_UART_RX_CTRL_PARITY(config->parity) |
                                                    UARTT_UART_RX_CTRL_PARITY_ENABLED;
            }

            UARTT_RX_CTRL_REG      = UARTT_GET_RX_CTRL_DATA_WIDTH(config->dataBits)       |
                                                UARTT_GET_RX_CTRL_MEDIAN(config->enableMedianFilter) |
                                                UARTT_GET_UART_RX_CTRL_ENABLED(config->direction);

            UARTT_RX_FIFO_CTRL_REG = UARTT_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(config->rxTriggerLevel);

            /* Configure MP address */
            UARTT_RX_MATCH_REG     = UARTT_GET_RX_MATCH_ADDR(config->multiprocAddr) |
                                                UARTT_GET_RX_MATCH_MASK(config->multiprocAddrMask);

            /* Configure RX direction */
            UARTT_UART_TX_CTRL_REG = UARTT_GET_UART_TX_CTRL_MODE(config->stopBits) |
                                                UARTT_GET_UART_TX_CTRL_RETRY_NACK(config->enableRetryNack);

            if(UARTT_UART_PARITY_NONE != config->parity)
            {
               UARTT_UART_TX_CTRL_REG |= UARTT_GET_UART_TX_CTRL_PARITY(config->parity) |
                                                    UARTT_UART_TX_CTRL_PARITY_ENABLED;
            }

            UARTT_TX_CTRL_REG      = UARTT_GET_TX_CTRL_DATA_WIDTH(config->dataBits)    |
                                                UARTT_GET_UART_TX_CTRL_ENABLED(config->direction);

            UARTT_TX_FIFO_CTRL_REG = UARTT_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(config->txTriggerLevel);

        #if !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1)
            UARTT_UART_FLOW_CTRL_REG = UARTT_GET_UART_FLOW_CTRL_CTS_ENABLE(config->enableCts) | \
                                            UARTT_GET_UART_FLOW_CTRL_CTS_POLARITY (config->ctsPolarity)  | \
                                            UARTT_GET_UART_FLOW_CTRL_RTS_POLARITY (config->rtsPolarity)  | \
                                            UARTT_GET_UART_FLOW_CTRL_TRIGGER_LEVEL(config->rtsRxFifoLevel);
        #endif /* !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1) */

            /* Configure interrupt with UART handler but do not enable it */
            CyIntDisable    (UARTT_ISR_NUMBER);
            CyIntSetPriority(UARTT_ISR_NUMBER, UARTT_ISR_PRIORITY);
            (void) CyIntSetVector(UARTT_ISR_NUMBER, &UARTT_SPI_UART_ISR);

            /* Configure WAKE interrupt */
        #if(UARTT_UART_RX_WAKEUP_IRQ)
            CyIntDisable    (UARTT_RX_WAKE_ISR_NUMBER);
            CyIntSetPriority(UARTT_RX_WAKE_ISR_NUMBER, UARTT_RX_WAKE_ISR_PRIORITY);
            (void) CyIntSetVector(UARTT_RX_WAKE_ISR_NUMBER, &UARTT_UART_WAKEUP_ISR);
        #endif /* (UARTT_UART_RX_WAKEUP_IRQ) */

            /* Configure interrupt sources */
            UARTT_INTR_I2C_EC_MASK_REG = UARTT_NO_INTR_SOURCES;
            UARTT_INTR_SPI_EC_MASK_REG = UARTT_NO_INTR_SOURCES;
            UARTT_INTR_SLAVE_MASK_REG  = UARTT_NO_INTR_SOURCES;
            UARTT_INTR_MASTER_MASK_REG = UARTT_NO_INTR_SOURCES;
            UARTT_INTR_RX_MASK_REG     = config->rxInterruptMask;
            UARTT_INTR_TX_MASK_REG     = config->txInterruptMask;
        
            /* Configure TX interrupt sources to restore. */
            UARTT_IntrTxMask = LO16(UARTT_INTR_TX_MASK_REG);

            /* Clear RX buffer indexes */
            UARTT_rxBufferHead     = 0u;
            UARTT_rxBufferTail     = 0u;
            UARTT_rxBufferOverflow = 0u;

            /* Clear TX buffer indexes */
            UARTT_txBufferHead = 0u;
            UARTT_txBufferTail = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: UARTT_UartInit
    ****************************************************************************//**
    *
    *  Configures the SCB for the UART operation.
    *
    *******************************************************************************/
    void UARTT_UartInit(void)
    {
        /* Configure UART interface */
        UARTT_CTRL_REG = UARTT_UART_DEFAULT_CTRL;

        /* Configure sub-mode: UART, SmartCard or IrDA */
        UARTT_UART_CTRL_REG = UARTT_UART_DEFAULT_UART_CTRL;

        /* Configure RX direction */
        UARTT_UART_RX_CTRL_REG = UARTT_UART_DEFAULT_UART_RX_CTRL;
        UARTT_RX_CTRL_REG      = UARTT_UART_DEFAULT_RX_CTRL;
        UARTT_RX_FIFO_CTRL_REG = UARTT_UART_DEFAULT_RX_FIFO_CTRL;
        UARTT_RX_MATCH_REG     = UARTT_UART_DEFAULT_RX_MATCH_REG;

        /* Configure TX direction */
        UARTT_UART_TX_CTRL_REG = UARTT_UART_DEFAULT_UART_TX_CTRL;
        UARTT_TX_CTRL_REG      = UARTT_UART_DEFAULT_TX_CTRL;
        UARTT_TX_FIFO_CTRL_REG = UARTT_UART_DEFAULT_TX_FIFO_CTRL;

    #if !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1)
        UARTT_UART_FLOW_CTRL_REG = UARTT_UART_DEFAULT_FLOW_CTRL;
    #endif /* !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1) */

        /* Configure interrupt with UART handler but do not enable it */
    #if(UARTT_SCB_IRQ_INTERNAL)
        CyIntDisable    (UARTT_ISR_NUMBER);
        CyIntSetPriority(UARTT_ISR_NUMBER, UARTT_ISR_PRIORITY);
        (void) CyIntSetVector(UARTT_ISR_NUMBER, &UARTT_SPI_UART_ISR);
    #endif /* (UARTT_SCB_IRQ_INTERNAL) */

        /* Configure WAKE interrupt */
    #if(UARTT_UART_RX_WAKEUP_IRQ)
        CyIntDisable    (UARTT_RX_WAKE_ISR_NUMBER);
        CyIntSetPriority(UARTT_RX_WAKE_ISR_NUMBER, UARTT_RX_WAKE_ISR_PRIORITY);
        (void) CyIntSetVector(UARTT_RX_WAKE_ISR_NUMBER, &UARTT_UART_WAKEUP_ISR);
    #endif /* (UARTT_UART_RX_WAKEUP_IRQ) */

        /* Configure interrupt sources */
        UARTT_INTR_I2C_EC_MASK_REG = UARTT_UART_DEFAULT_INTR_I2C_EC_MASK;
        UARTT_INTR_SPI_EC_MASK_REG = UARTT_UART_DEFAULT_INTR_SPI_EC_MASK;
        UARTT_INTR_SLAVE_MASK_REG  = UARTT_UART_DEFAULT_INTR_SLAVE_MASK;
        UARTT_INTR_MASTER_MASK_REG = UARTT_UART_DEFAULT_INTR_MASTER_MASK;
        UARTT_INTR_RX_MASK_REG     = UARTT_UART_DEFAULT_INTR_RX_MASK;
        UARTT_INTR_TX_MASK_REG     = UARTT_UART_DEFAULT_INTR_TX_MASK;
    
        /* Configure TX interrupt sources to restore. */
        UARTT_IntrTxMask = LO16(UARTT_INTR_TX_MASK_REG);

    #if(UARTT_INTERNAL_RX_SW_BUFFER_CONST)
        UARTT_rxBufferHead     = 0u;
        UARTT_rxBufferTail     = 0u;
        UARTT_rxBufferOverflow = 0u;
    #endif /* (UARTT_INTERNAL_RX_SW_BUFFER_CONST) */

    #if(UARTT_INTERNAL_TX_SW_BUFFER_CONST)
        UARTT_txBufferHead = 0u;
        UARTT_txBufferTail = 0u;
    #endif /* (UARTT_INTERNAL_TX_SW_BUFFER_CONST) */
    }
#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */


/*******************************************************************************
* Function Name: UARTT_UartPostEnable
****************************************************************************//**
*
*  Restores HSIOM settings for the UART output pins (TX and/or RTS) to be
*  controlled by the SCB UART.
*
*******************************************************************************/
void UARTT_UartPostEnable(void)
{
#if (UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
    #if (UARTT_TX_SDA_MISO_PIN)
        if (UARTT_CHECK_TX_SDA_MISO_PIN_USED)
        {
            /* Set SCB UART to drive the output pin */
            UARTT_SET_HSIOM_SEL(UARTT_TX_SDA_MISO_HSIOM_REG, UARTT_TX_SDA_MISO_HSIOM_MASK,
                                           UARTT_TX_SDA_MISO_HSIOM_POS, UARTT_TX_SDA_MISO_HSIOM_SEL_UART);
        }
    #endif /* (UARTT_TX_SDA_MISO_PIN_PIN) */

    #if !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1)
        #if (UARTT_SS0_PIN)
            if (UARTT_CHECK_SS0_PIN_USED)
            {
                /* Set SCB UART to drive the output pin */
                UARTT_SET_HSIOM_SEL(UARTT_SS0_HSIOM_REG, UARTT_SS0_HSIOM_MASK,
                                               UARTT_SS0_HSIOM_POS, UARTT_SS0_HSIOM_SEL_UART);
            }
        #endif /* (UARTT_SS0_PIN) */
    #endif /* !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1) */

#else
    #if (UARTT_UART_TX_PIN)
         /* Set SCB UART to drive the output pin */
        UARTT_SET_HSIOM_SEL(UARTT_TX_HSIOM_REG, UARTT_TX_HSIOM_MASK,
                                       UARTT_TX_HSIOM_POS, UARTT_TX_HSIOM_SEL_UART);
    #endif /* (UARTT_UART_TX_PIN) */

    #if (UARTT_UART_RTS_PIN)
        /* Set SCB UART to drive the output pin */
        UARTT_SET_HSIOM_SEL(UARTT_RTS_HSIOM_REG, UARTT_RTS_HSIOM_MASK,
                                       UARTT_RTS_HSIOM_POS, UARTT_RTS_HSIOM_SEL_UART);
    #endif /* (UARTT_UART_RTS_PIN) */
#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Restore TX interrupt sources. */
    UARTT_SetTxInterruptMode(UARTT_IntrTxMask);
}


/*******************************************************************************
* Function Name: UARTT_UartStop
****************************************************************************//**
*
*  Changes the HSIOM settings for the UART output pins (TX and/or RTS) to keep
*  them inactive after the block is disabled. The output pins are controlled by
*  the GPIO data register. Also, the function disables the skip start feature
*  to not cause it to trigger after the component is enabled.
*
*******************************************************************************/
void UARTT_UartStop(void)
{
#if(UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
    #if (UARTT_TX_SDA_MISO_PIN)
        if (UARTT_CHECK_TX_SDA_MISO_PIN_USED)
        {
            /* Set GPIO to drive output pin */
            UARTT_SET_HSIOM_SEL(UARTT_TX_SDA_MISO_HSIOM_REG, UARTT_TX_SDA_MISO_HSIOM_MASK,
                                           UARTT_TX_SDA_MISO_HSIOM_POS, UARTT_TX_SDA_MISO_HSIOM_SEL_GPIO);
        }
    #endif /* (UARTT_TX_SDA_MISO_PIN_PIN) */

    #if !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1)
        #if (UARTT_SS0_PIN)
            if (UARTT_CHECK_SS0_PIN_USED)
            {
                /* Set output pin state after block is disabled */
                UARTT_spi_ss0_Write(UARTT_GET_UART_RTS_INACTIVE);

                /* Set GPIO to drive output pin */
                UARTT_SET_HSIOM_SEL(UARTT_SS0_HSIOM_REG, UARTT_SS0_HSIOM_MASK,
                                               UARTT_SS0_HSIOM_POS, UARTT_SS0_HSIOM_SEL_GPIO);
            }
        #endif /* (UARTT_SS0_PIN) */
    #endif /* !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1) */

#else
    #if (UARTT_UART_TX_PIN)
        /* Set GPIO to drive output pin */
        UARTT_SET_HSIOM_SEL(UARTT_TX_HSIOM_REG, UARTT_TX_HSIOM_MASK,
                                       UARTT_TX_HSIOM_POS, UARTT_TX_HSIOM_SEL_GPIO);
    #endif /* (UARTT_UART_TX_PIN) */

    #if (UARTT_UART_RTS_PIN)
        /* Set output pin state after block is disabled */
        UARTT_rts_Write(UARTT_GET_UART_RTS_INACTIVE);

        /* Set GPIO to drive output pin */
        UARTT_SET_HSIOM_SEL(UARTT_RTS_HSIOM_REG, UARTT_RTS_HSIOM_MASK,
                                       UARTT_RTS_HSIOM_POS, UARTT_RTS_HSIOM_SEL_GPIO);
    #endif /* (UARTT_UART_RTS_PIN) */

#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (UARTT_UART_WAKE_ENABLE_CONST)
    /* Disable skip start feature used for wakeup */
    UARTT_UART_RX_CTRL_REG &= (uint32) ~UARTT_UART_RX_CTRL_SKIP_START;
#endif /* (UARTT_UART_WAKE_ENABLE_CONST) */

    /* Store TX interrupt sources (exclude level triggered). */
    UARTT_IntrTxMask = LO16(UARTT_GetTxInterruptMode() & UARTT_INTR_UART_TX_RESTORE);
}


/*******************************************************************************
* Function Name: UARTT_UartSetRxAddress
****************************************************************************//**
*
*  Sets the hardware detectable receiver address for the UART in the
*  Multiprocessor mode.
*
*  \param address: Address for hardware address detection.
*
*******************************************************************************/
void UARTT_UartSetRxAddress(uint32 address)
{
     uint32 matchReg;

    matchReg = UARTT_RX_MATCH_REG;

    matchReg &= ((uint32) ~UARTT_RX_MATCH_ADDR_MASK); /* Clear address bits */
    matchReg |= ((uint32)  (address & UARTT_RX_MATCH_ADDR_MASK)); /* Set address  */

    UARTT_RX_MATCH_REG = matchReg;
}


/*******************************************************************************
* Function Name: UARTT_UartSetRxAddressMask
****************************************************************************//**
*
*  Sets the hardware address mask for the UART in the Multiprocessor mode.
*
*  \param addressMask: Address mask.
*   - Bit value 0 – excludes bit from address comparison.
*   - Bit value 1 – the bit needs to match with the corresponding bit
*     of the address.
*
*******************************************************************************/
void UARTT_UartSetRxAddressMask(uint32 addressMask)
{
    uint32 matchReg;

    matchReg = UARTT_RX_MATCH_REG;

    matchReg &= ((uint32) ~UARTT_RX_MATCH_MASK_MASK); /* Clear address mask bits */
    matchReg |= ((uint32) (addressMask << UARTT_RX_MATCH_MASK_POS));

    UARTT_RX_MATCH_REG = matchReg;
}


#if(UARTT_UART_RX_DIRECTION)
    /*******************************************************************************
    * Function Name: UARTT_UartGetChar
    ****************************************************************************//**
    *
    *  Retrieves next data element from receive buffer.
    *  This function is designed for ASCII characters and returns a char where
    *  1 to 255 are valid characters and 0 indicates an error occurred or no data
    *  is present.
    *  - RX software buffer is disabled: Returns data element retrieved from RX
    *    FIFO.
    *  - RX software buffer is enabled: Returns data element from the software
    *    receive buffer.
    *
    *  \return
    *   Next data element from the receive buffer. ASCII character values from
    *   1 to 255 are valid. A returned zero signifies an error condition or no
    *   data available.
    *
    *  \sideeffect
    *   The errors bits may not correspond with reading characters due to
    *   RX FIFO and software buffer usage.
    *   RX software buffer is enabled: The internal software buffer overflow
    *   is not treated as an error condition.
    *   Check UARTT_rxBufferOverflow to capture that error condition.
    *
    *******************************************************************************/
    uint32 UARTT_UartGetChar(void)
    {
        uint32 rxData = 0u;

        /* Reads data only if there is data to read */
        if (0u != UARTT_SpiUartGetRxBufferSize())
        {
            rxData = UARTT_SpiUartReadRxData();
        }

        if (UARTT_CHECK_INTR_RX(UARTT_INTR_RX_ERR))
        {
            rxData = 0u; /* Error occurred: returns zero */
            UARTT_ClearRxInterruptSource(UARTT_INTR_RX_ERR);
        }

        return (rxData);
    }


    /*******************************************************************************
    * Function Name: UARTT_UartGetByte
    ****************************************************************************//**
    *
    *  Retrieves the next data element from the receive buffer, returns the
    *  received byte and error condition.
    *   - The RX software buffer is disabled: returns the data element retrieved
    *     from the RX FIFO. Undefined data will be returned if the RX FIFO is
    *     empty.
    *   - The RX software buffer is enabled: returns data element from the
    *     software receive buffer.
    *
    *  \return
    *   Bits 7-0 contain the next data element from the receive buffer and
    *   other bits contain the error condition.
    *   - UARTT_UART_RX_OVERFLOW - Attempt to write to a full
    *     receiver FIFO.
    *   - UARTT_UART_RX_UNDERFLOW	Attempt to read from an empty
    *     receiver FIFO.
    *   - UARTT_UART_RX_FRAME_ERROR - UART framing error detected.
    *   - UARTT_UART_RX_PARITY_ERROR - UART parity error detected.
    *
    *  \sideeffect
    *   The errors bits may not correspond with reading characters due to
    *   RX FIFO and software buffer usage.
    *   RX software buffer is enabled: The internal software buffer overflow
    *   is not treated as an error condition.
    *   Check UARTT_rxBufferOverflow to capture that error condition.
    *
    *******************************************************************************/
    uint32 UARTT_UartGetByte(void)
    {
        uint32 rxData;
        uint32 tmpStatus;

        #if (UARTT_CHECK_RX_SW_BUFFER)
        {
            UARTT_DisableInt();
        }
        #endif

        if (0u != UARTT_SpiUartGetRxBufferSize())
        {
            /* Enables interrupt to receive more bytes: at least one byte is in
            * buffer.
            */
            #if (UARTT_CHECK_RX_SW_BUFFER)
            {
                UARTT_EnableInt();
            }
            #endif

            /* Get received byte */
            rxData = UARTT_SpiUartReadRxData();
        }
        else
        {
            /* Reads a byte directly from RX FIFO: underflow is raised in the
            * case of empty. Otherwise the first received byte will be read.
            */
            rxData = UARTT_RX_FIFO_RD_REG;


            /* Enables interrupt to receive more bytes. */
            #if (UARTT_CHECK_RX_SW_BUFFER)
            {

                /* The byte has been read from RX FIFO. Clear RX interrupt to
                * not involve interrupt handler when RX FIFO is empty.
                */
                UARTT_ClearRxInterruptSource(UARTT_INTR_RX_NOT_EMPTY);

                UARTT_EnableInt();
            }
            #endif
        }

        /* Get and clear RX error mask */
        tmpStatus = (UARTT_GetRxInterruptSource() & UARTT_INTR_RX_ERR);
        UARTT_ClearRxInterruptSource(UARTT_INTR_RX_ERR);

        /* Puts together data and error status:
        * MP mode and accept address: 9th bit is set to notify mark.
        */
        rxData |= ((uint32) (tmpStatus << 8u));

        return (rxData);
    }


    #if !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1)
        /*******************************************************************************
        * Function Name: UARTT_UartSetRtsPolarity
        ****************************************************************************//**
        *
        *  Sets active polarity of RTS output signal.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        *  \param polarity: Active polarity of RTS output signal.
        *   - UARTT_UART_RTS_ACTIVE_LOW  - RTS signal is active low.
        *   - UARTT_UART_RTS_ACTIVE_HIGH - RTS signal is active high.
        *
        *******************************************************************************/
        void UARTT_UartSetRtsPolarity(uint32 polarity)
        {
            if(0u != polarity)
            {
                UARTT_UART_FLOW_CTRL_REG |= (uint32)  UARTT_UART_FLOW_CTRL_RTS_POLARITY;
            }
            else
            {
                UARTT_UART_FLOW_CTRL_REG &= (uint32) ~UARTT_UART_FLOW_CTRL_RTS_POLARITY;
            }
        }


        /*******************************************************************************
        * Function Name: UARTT_UartSetRtsFifoLevel
        ****************************************************************************//**
        *
        *  Sets level in the RX FIFO for RTS signal activation.
        *  While the RX FIFO has fewer entries than the RX FIFO level the RTS signal
        *  remains active, otherwise the RTS signal becomes inactive.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        *  \param level: Level in the RX FIFO for RTS signal activation.
        *   The range of valid level values is between 0 and RX FIFO depth - 1.
        *   Setting level value to 0 disables RTS signal activation.
        *
        *******************************************************************************/
        void UARTT_UartSetRtsFifoLevel(uint32 level)
        {
            uint32 uartFlowCtrl;

            uartFlowCtrl = UARTT_UART_FLOW_CTRL_REG;

            uartFlowCtrl &= ((uint32) ~UARTT_UART_FLOW_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
            uartFlowCtrl |= ((uint32) (UARTT_UART_FLOW_CTRL_TRIGGER_LEVEL_MASK & level));

            UARTT_UART_FLOW_CTRL_REG = uartFlowCtrl;
        }
    #endif /* !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1) */

#endif /* (UARTT_UART_RX_DIRECTION) */


#if(UARTT_UART_TX_DIRECTION)
    /*******************************************************************************
    * Function Name: UARTT_UartPutString
    ****************************************************************************//**
    *
    *  Places a NULL terminated string in the transmit buffer to be sent at the
    *  next available bus time.
    *  This function is blocking and waits until there is a space available to put
    *  requested data in transmit buffer.
    *
    *  \param string: pointer to the null terminated string array to be placed in the
    *   transmit buffer.
    *
    *******************************************************************************/
    void UARTT_UartPutString(const char8 string[])
    {
        uint32 bufIndex;

        bufIndex = 0u;

        /* Blocks the control flow until all data has been sent */
        while(string[bufIndex] != ((char8) 0))
        {
            UARTT_UartPutChar((uint32) string[bufIndex]);
            bufIndex++;
        }
    }


    /*******************************************************************************
    * Function Name: UARTT_UartPutCRLF
    ****************************************************************************//**
    *
    *  Places byte of data followed by a carriage return (0x0D) and line feed
    *  (0x0A) in the transmit buffer.
    *  This function is blocking and waits until there is a space available to put
    *  all requested data in transmit buffer.
    *
    *  \param txDataByte: the data to be transmitted.
    *
    *******************************************************************************/
    void UARTT_UartPutCRLF(uint32 txDataByte)
    {
        UARTT_UartPutChar(txDataByte);  /* Blocks control flow until all data has been sent */
        UARTT_UartPutChar(0x0Du);       /* Blocks control flow until all data has been sent */
        UARTT_UartPutChar(0x0Au);       /* Blocks control flow until all data has been sent */
    }


    #if !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1)
        /*******************************************************************************
        * Function Name: UARTTSCB_UartEnableCts
        ****************************************************************************//**
        *
        *  Enables usage of CTS input signal by the UART transmitter.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        *******************************************************************************/
        void UARTT_UartEnableCts(void)
        {
            UARTT_UART_FLOW_CTRL_REG |= (uint32)  UARTT_UART_FLOW_CTRL_CTS_ENABLE;
        }


        /*******************************************************************************
        * Function Name: UARTT_UartDisableCts
        ****************************************************************************//**
        *
        *  Disables usage of CTS input signal by the UART transmitter.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        *******************************************************************************/
        void UARTT_UartDisableCts(void)
        {
            UARTT_UART_FLOW_CTRL_REG &= (uint32) ~UARTT_UART_FLOW_CTRL_CTS_ENABLE;
        }


        /*******************************************************************************
        * Function Name: UARTT_UartSetCtsPolarity
        ****************************************************************************//**
        *
        *  Sets active polarity of CTS input signal.
        *  Only available for PSoC 4100 BLE / PSoC 4200 BLE / PSoC 4100M / PSoC 4200M /
        *  PSoC 4200L / PSoC 4000S / PSoC 4100S / PSoC Analog Coprocessor devices.
        *
        *  \param polarity: Active polarity of CTS output signal.
        *   - UARTT_UART_CTS_ACTIVE_LOW  - CTS signal is active low.
        *   - UARTT_UART_CTS_ACTIVE_HIGH - CTS signal is active high.
        *
        *******************************************************************************/
        void UARTT_UartSetCtsPolarity(uint32 polarity)
        {
            if (0u != polarity)
            {
                UARTT_UART_FLOW_CTRL_REG |= (uint32)  UARTT_UART_FLOW_CTRL_CTS_POLARITY;
            }
            else
            {
                UARTT_UART_FLOW_CTRL_REG &= (uint32) ~UARTT_UART_FLOW_CTRL_CTS_POLARITY;
            }
        }
    #endif /* !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1) */

#endif /* (UARTT_UART_TX_DIRECTION) */


#if (UARTT_UART_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: UARTT_UartSaveConfig
    ****************************************************************************//**
    *
    *  Clears and enables an interrupt on a falling edge of the Rx input. The GPIO
    *  interrupt does not track in the active mode, therefore requires to be 
    *  cleared by this API.
    *
    *******************************************************************************/
    void UARTT_UartSaveConfig(void)
    {
    #if (UARTT_UART_RX_WAKEUP_IRQ)
        /* Set SKIP_START if requested (set by default). */
        if (0u != UARTT_skipStart)
        {
            UARTT_UART_RX_CTRL_REG |= (uint32)  UARTT_UART_RX_CTRL_SKIP_START;
        }
        else
        {
            UARTT_UART_RX_CTRL_REG &= (uint32) ~UARTT_UART_RX_CTRL_SKIP_START;
        }
        
        /* Clear RX GPIO interrupt status and pending interrupt in NVIC because
        * falling edge on RX line occurs while UART communication in active mode.
        * Enable interrupt: next interrupt trigger should wakeup device.
        */
        UARTT_CLEAR_UART_RX_WAKE_INTR;
        UARTT_RxWakeClearPendingInt();
        UARTT_RxWakeEnableInt();
    #endif /* (UARTT_UART_RX_WAKEUP_IRQ) */
    }


    /*******************************************************************************
    * Function Name: UARTT_UartRestoreConfig
    ****************************************************************************//**
    *
    *  Disables the RX GPIO interrupt. Until this function is called the interrupt
    *  remains active and triggers on every falling edge of the UART RX line.
    *
    *******************************************************************************/
    void UARTT_UartRestoreConfig(void)
    {
    #if (UARTT_UART_RX_WAKEUP_IRQ)
        /* Disable interrupt: no more triggers in active mode */
        UARTT_RxWakeDisableInt();
    #endif /* (UARTT_UART_RX_WAKEUP_IRQ) */
    }


    #if (UARTT_UART_RX_WAKEUP_IRQ)
        /*******************************************************************************
        * Function Name: UARTT_UART_WAKEUP_ISR
        ****************************************************************************//**
        *
        *  Handles the Interrupt Service Routine for the SCB UART mode GPIO wakeup
        *  event. This event is configured to trigger on a falling edge of the RX line.
        *
        *******************************************************************************/
        CY_ISR(UARTT_UART_WAKEUP_ISR)
        {
        #ifdef UARTT_UART_WAKEUP_ISR_ENTRY_CALLBACK
            UARTT_UART_WAKEUP_ISR_EntryCallback();
        #endif /* UARTT_UART_WAKEUP_ISR_ENTRY_CALLBACK */

            UARTT_CLEAR_UART_RX_WAKE_INTR;

        #ifdef UARTT_UART_WAKEUP_ISR_EXIT_CALLBACK
            UARTT_UART_WAKEUP_ISR_ExitCallback();
        #endif /* UARTT_UART_WAKEUP_ISR_EXIT_CALLBACK */
        }
    #endif /* (UARTT_UART_RX_WAKEUP_IRQ) */
#endif /* (UARTT_UART_RX_WAKEUP_IRQ) */


/* [] END OF FILE */
