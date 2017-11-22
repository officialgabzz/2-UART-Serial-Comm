/***************************************************************************//**
* \file UARTT.c
* \version 3.20
*
* \brief
*  This file provides the source code to the API for the SCB Component.
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

#if (UARTT_SCB_MODE_I2C_INC)
    #include "UARTT_I2C_PVT.h"
#endif /* (UARTT_SCB_MODE_I2C_INC) */

#if (UARTT_SCB_MODE_EZI2C_INC)
    #include "UARTT_EZI2C_PVT.h"
#endif /* (UARTT_SCB_MODE_EZI2C_INC) */

#if (UARTT_SCB_MODE_SPI_INC || UARTT_SCB_MODE_UART_INC)
    #include "UARTT_SPI_UART_PVT.h"
#endif /* (UARTT_SCB_MODE_SPI_INC || UARTT_SCB_MODE_UART_INC) */


/***************************************
*    Run Time Configuration Vars
***************************************/

/* Stores internal component configuration for Unconfigured mode */
#if (UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    uint8 UARTT_scbMode = UARTT_SCB_MODE_UNCONFIG;
    uint8 UARTT_scbEnableWake;
    uint8 UARTT_scbEnableIntr;

    /* I2C configuration variables */
    uint8 UARTT_mode;
    uint8 UARTT_acceptAddr;

    /* SPI/UART configuration variables */
    volatile uint8 * UARTT_rxBuffer;
    uint8  UARTT_rxDataBits;
    uint32 UARTT_rxBufferSize;

    volatile uint8 * UARTT_txBuffer;
    uint8  UARTT_txDataBits;
    uint32 UARTT_txBufferSize;

    /* EZI2C configuration variables */
    uint8 UARTT_numberOfAddr;
    uint8 UARTT_subAddrSize;
#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Common SCB Vars
***************************************/
/**
* \addtogroup group_general
* \{
*/

/** UARTT_initVar indicates whether the UARTT 
*  component has been initialized. The variable is initialized to 0 
*  and set to 1 the first time SCB_Start() is called. This allows 
*  the component to restart without reinitialization after the first 
*  call to the UARTT_Start() routine.
*
*  If re-initialization of the component is required, then the 
*  UARTT_Init() function can be called before the 
*  UARTT_Start() or UARTT_Enable() function.
*/
uint8 UARTT_initVar = 0u;


#if (! (UARTT_SCB_MODE_I2C_CONST_CFG || \
        UARTT_SCB_MODE_EZI2C_CONST_CFG))
    /** This global variable stores TX interrupt sources after 
    * UARTT_Stop() is called. Only these TX interrupt sources 
    * will be restored on a subsequent UARTT_Enable() call.
    */
    uint16 UARTT_IntrTxMask = 0u;
#endif /* (! (UARTT_SCB_MODE_I2C_CONST_CFG || \
              UARTT_SCB_MODE_EZI2C_CONST_CFG)) */
/** \} globals */

#if (UARTT_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_UARTT_CUSTOM_INTR_HANDLER)
    void (*UARTT_customIntrHandler)(void) = NULL;
#endif /* !defined (CY_REMOVE_UARTT_CUSTOM_INTR_HANDLER) */
#endif /* (UARTT_SCB_IRQ_INTERNAL) */


/***************************************
*    Private Function Prototypes
***************************************/

static void UARTT_ScbEnableIntr(void);
static void UARTT_ScbModeStop(void);
static void UARTT_ScbModePostEnable(void);


/*******************************************************************************
* Function Name: UARTT_Init
****************************************************************************//**
*
*  Initializes the UARTT component to operate in one of the selected
*  configurations: I2C, SPI, UART or EZI2C.
*  When the configuration is set to "Unconfigured SCB", this function does
*  not do any initialization. Use mode-specific initialization APIs instead:
*  UARTT_I2CInit, UARTT_SpiInit, 
*  UARTT_UartInit or UARTT_EzI2CInit.
*
*******************************************************************************/
void UARTT_Init(void)
{
#if (UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
    if (UARTT_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        UARTT_initVar = 0u;
    }
    else
    {
        /* Initialization was done before this function call */
    }

#elif (UARTT_SCB_MODE_I2C_CONST_CFG)
    UARTT_I2CInit();

#elif (UARTT_SCB_MODE_SPI_CONST_CFG)
    UARTT_SpiInit();

#elif (UARTT_SCB_MODE_UART_CONST_CFG)
    UARTT_UartInit();

#elif (UARTT_SCB_MODE_EZI2C_CONST_CFG)
    UARTT_EzI2CInit();

#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UARTT_Enable
****************************************************************************//**
*
*  Enables UARTT component operation: activates the hardware and 
*  internal interrupt. It also restores TX interrupt sources disabled after the 
*  UARTT_Stop() function was called (note that level-triggered TX 
*  interrupt sources remain disabled to not cause code lock-up).
*  For I2C and EZI2C modes the interrupt is internal and mandatory for 
*  operation. For SPI and UART modes the interrupt can be configured as none, 
*  internal or external.
*  The UARTT configuration should be not changed when the component
*  is enabled. Any configuration changes should be made after disabling the 
*  component.
*  When configuration is set to “Unconfigured UARTT”, the component 
*  must first be initialized to operate in one of the following configurations: 
*  I2C, SPI, UART or EZ I2C, using the mode-specific initialization API. 
*  Otherwise this function does not enable the component.
*
*******************************************************************************/
void UARTT_Enable(void)
{
#if (UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Enable SCB block, only if it is already configured */
    if (!UARTT_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        UARTT_CTRL_REG |= UARTT_CTRL_ENABLED;

        UARTT_ScbEnableIntr();

        /* Call PostEnable function specific to current operation mode */
        UARTT_ScbModePostEnable();
    }
#else
    UARTT_CTRL_REG |= UARTT_CTRL_ENABLED;

    UARTT_ScbEnableIntr();

    /* Call PostEnable function specific to current operation mode */
    UARTT_ScbModePostEnable();
#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UARTT_Start
****************************************************************************//**
*
*  Invokes UARTT_Init() and UARTT_Enable().
*  After this function call, the component is enabled and ready for operation.
*  When configuration is set to "Unconfigured SCB", the component must first be
*  initialized to operate in one of the following configurations: I2C, SPI, UART
*  or EZI2C. Otherwise this function does not enable the component.
*
* \globalvars
*  UARTT_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void UARTT_Start(void)
{
    if (0u == UARTT_initVar)
    {
        UARTT_Init();
        UARTT_initVar = 1u; /* Component was initialized */
    }

    UARTT_Enable();
}


/*******************************************************************************
* Function Name: UARTT_Stop
****************************************************************************//**
*
*  Disables the UARTT component: disable the hardware and internal 
*  interrupt. It also disables all TX interrupt sources so as not to cause an 
*  unexpected interrupt trigger because after the component is enabled, the 
*  TX FIFO is empty.
*  Refer to the function UARTT_Enable() for the interrupt 
*  configuration details.
*  This function disables the SCB component without checking to see if 
*  communication is in progress. Before calling this function it may be 
*  necessary to check the status of communication to make sure communication 
*  is complete. If this is not done then communication could be stopped mid 
*  byte and corrupted data could result.
*
*******************************************************************************/
void UARTT_Stop(void)
{
#if (UARTT_SCB_IRQ_INTERNAL)
    UARTT_DisableInt();
#endif /* (UARTT_SCB_IRQ_INTERNAL) */

    /* Call Stop function specific to current operation mode */
    UARTT_ScbModeStop();

    /* Disable SCB IP */
    UARTT_CTRL_REG &= (uint32) ~UARTT_CTRL_ENABLED;

    /* Disable all TX interrupt sources so as not to cause an unexpected
    * interrupt trigger after the component will be enabled because the 
    * TX FIFO is empty.
    * For SCB IP v0, it is critical as it does not mask-out interrupt
    * sources when it is disabled. This can cause a code lock-up in the
    * interrupt handler because TX FIFO cannot be loaded after the block
    * is disabled.
    */
    UARTT_SetTxInterruptMode(UARTT_NO_INTR_SOURCES);

#if (UARTT_SCB_IRQ_INTERNAL)
    UARTT_ClearPendingInt();
#endif /* (UARTT_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: UARTT_SetRxFifoLevel
****************************************************************************//**
*
*  Sets level in the RX FIFO to generate a RX level interrupt.
*  When the RX FIFO has more entries than the RX FIFO level an RX level
*  interrupt request is generated.
*
*  \param level: Level in the RX FIFO to generate RX level interrupt.
*   The range of valid level values is between 0 and RX FIFO depth - 1.
*
*******************************************************************************/
void UARTT_SetRxFifoLevel(uint32 level)
{
    uint32 rxFifoCtrl;

    rxFifoCtrl = UARTT_RX_FIFO_CTRL_REG;

    rxFifoCtrl &= ((uint32) ~UARTT_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    rxFifoCtrl |= ((uint32) (UARTT_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    UARTT_RX_FIFO_CTRL_REG = rxFifoCtrl;
}


/*******************************************************************************
* Function Name: UARTT_SetTxFifoLevel
****************************************************************************//**
*
*  Sets level in the TX FIFO to generate a TX level interrupt.
*  When the TX FIFO has less entries than the TX FIFO level an TX level
*  interrupt request is generated.
*
*  \param level: Level in the TX FIFO to generate TX level interrupt.
*   The range of valid level values is between 0 and TX FIFO depth - 1.
*
*******************************************************************************/
void UARTT_SetTxFifoLevel(uint32 level)
{
    uint32 txFifoCtrl;

    txFifoCtrl = UARTT_TX_FIFO_CTRL_REG;

    txFifoCtrl &= ((uint32) ~UARTT_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    txFifoCtrl |= ((uint32) (UARTT_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    UARTT_TX_FIFO_CTRL_REG = txFifoCtrl;
}


#if (UARTT_SCB_IRQ_INTERNAL)
    /*******************************************************************************
    * Function Name: UARTT_SetCustomInterruptHandler
    ****************************************************************************//**
    *
    *  Registers a function to be called by the internal interrupt handler.
    *  First the function that is registered is called, then the internal interrupt
    *  handler performs any operation such as software buffer management functions
    *  before the interrupt returns.  It is the user's responsibility not to break
    *  the software buffer operations. Only one custom handler is supported, which
    *  is the function provided by the most recent call.
    *  At the initialization time no custom handler is registered.
    *
    *  \param func: Pointer to the function to register.
    *        The value NULL indicates to remove the current custom interrupt
    *        handler.
    *
    *******************************************************************************/
    void UARTT_SetCustomInterruptHandler(void (*func)(void))
    {
    #if !defined (CY_REMOVE_UARTT_CUSTOM_INTR_HANDLER)
        UARTT_customIntrHandler = func; /* Register interrupt handler */
    #else
        if (NULL != func)
        {
            /* Suppress compiler warning */
        }
    #endif /* !defined (CY_REMOVE_UARTT_CUSTOM_INTR_HANDLER) */
    }
#endif /* (UARTT_SCB_IRQ_INTERNAL) */


/*******************************************************************************
* Function Name: UARTT_ScbModeEnableIntr
****************************************************************************//**
*
*  Enables an interrupt for a specific mode.
*
*******************************************************************************/
static void UARTT_ScbEnableIntr(void)
{
#if (UARTT_SCB_IRQ_INTERNAL)
    /* Enable interrupt in NVIC */
    #if (UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
        if (0u != UARTT_scbEnableIntr)
        {
            UARTT_EnableInt();
        }

    #else
        UARTT_EnableInt();

    #endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (UARTT_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: UARTT_ScbModePostEnable
****************************************************************************//**
*
*  Calls the PostEnable function for a specific operation mode.
*
*******************************************************************************/
static void UARTT_ScbModePostEnable(void)
{
#if (UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
#if (!UARTT_CY_SCBIP_V1)
    if (UARTT_SCB_MODE_SPI_RUNTM_CFG)
    {
        UARTT_SpiPostEnable();
    }
    else if (UARTT_SCB_MODE_UART_RUNTM_CFG)
    {
        UARTT_UartPostEnable();
    }
    else
    {
        /* Unknown mode: do nothing */
    }
#endif /* (!UARTT_CY_SCBIP_V1) */

#elif (UARTT_SCB_MODE_SPI_CONST_CFG)
    UARTT_SpiPostEnable();

#elif (UARTT_SCB_MODE_UART_CONST_CFG)
    UARTT_UartPostEnable();

#else
    /* Unknown mode: do nothing */
#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UARTT_ScbModeStop
****************************************************************************//**
*
*  Calls the Stop function for a specific operation mode.
*
*******************************************************************************/
static void UARTT_ScbModeStop(void)
{
#if (UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
    if (UARTT_SCB_MODE_I2C_RUNTM_CFG)
    {
        UARTT_I2CStop();
    }
    else if (UARTT_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        UARTT_EzI2CStop();
    }
#if (!UARTT_CY_SCBIP_V1)
    else if (UARTT_SCB_MODE_SPI_RUNTM_CFG)
    {
        UARTT_SpiStop();
    }
    else if (UARTT_SCB_MODE_UART_RUNTM_CFG)
    {
        UARTT_UartStop();
    }
#endif /* (!UARTT_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
#elif (UARTT_SCB_MODE_I2C_CONST_CFG)
    UARTT_I2CStop();

#elif (UARTT_SCB_MODE_EZI2C_CONST_CFG)
    UARTT_EzI2CStop();

#elif (UARTT_SCB_MODE_SPI_CONST_CFG)
    UARTT_SpiStop();

#elif (UARTT_SCB_MODE_UART_CONST_CFG)
    UARTT_UartStop();

#else
    /* Unknown mode: do nothing */
#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if (UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: UARTT_SetPins
    ****************************************************************************//**
    *
    *  Sets the pins settings accordingly to the selected operation mode.
    *  Only available in the Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when a specific mode of operation
    *  is selected in design time.
    *
    *  \param mode:      Mode of SCB operation.
    *  \param subMode:   Sub-mode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  \param uartEnableMask: enables TX or RX direction and RTS and CTS signals.
    *
    *******************************************************************************/
    void UARTT_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask)
    {
        uint32 pinsDm[UARTT_SCB_PINS_NUMBER];
        uint32 i;
        
    #if (!UARTT_CY_SCBIP_V1)
        uint32 pinsInBuf = 0u;
    #endif /* (!UARTT_CY_SCBIP_V1) */
        
        uint32 hsiomSel[UARTT_SCB_PINS_NUMBER] = 
        {
            UARTT_RX_SCL_MOSI_HSIOM_SEL_GPIO,
            UARTT_TX_SDA_MISO_HSIOM_SEL_GPIO,
            0u,
            0u,
            0u,
            0u,
            0u,
        };

    #if (UARTT_CY_SCBIP_V1)
        /* Supress compiler warning. */
        if ((0u == subMode) || (0u == uartEnableMask))
        {
        }
    #endif /* (UARTT_CY_SCBIP_V1) */

        /* Set default HSIOM to GPIO and Drive Mode to Analog Hi-Z */
        for (i = 0u; i < UARTT_SCB_PINS_NUMBER; i++)
        {
            pinsDm[i] = UARTT_PIN_DM_ALG_HIZ;
        }

        if ((UARTT_SCB_MODE_I2C   == mode) ||
            (UARTT_SCB_MODE_EZI2C == mode))
        {
        #if (UARTT_RX_SCL_MOSI_PIN)
            hsiomSel[UARTT_RX_SCL_MOSI_PIN_INDEX] = UARTT_RX_SCL_MOSI_HSIOM_SEL_I2C;
            pinsDm  [UARTT_RX_SCL_MOSI_PIN_INDEX] = UARTT_PIN_DM_OD_LO;
        #elif (UARTT_RX_WAKE_SCL_MOSI_PIN)
            hsiomSel[UARTT_RX_WAKE_SCL_MOSI_PIN_INDEX] = UARTT_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C;
            pinsDm  [UARTT_RX_WAKE_SCL_MOSI_PIN_INDEX] = UARTT_PIN_DM_OD_LO;
        #else
        #endif /* (UARTT_RX_SCL_MOSI_PIN) */
        
        #if (UARTT_TX_SDA_MISO_PIN)
            hsiomSel[UARTT_TX_SDA_MISO_PIN_INDEX] = UARTT_TX_SDA_MISO_HSIOM_SEL_I2C;
            pinsDm  [UARTT_TX_SDA_MISO_PIN_INDEX] = UARTT_PIN_DM_OD_LO;
        #endif /* (UARTT_TX_SDA_MISO_PIN) */
        }
    #if (!UARTT_CY_SCBIP_V1)
        else if (UARTT_SCB_MODE_SPI == mode)
        {
        #if (UARTT_RX_SCL_MOSI_PIN)
            hsiomSel[UARTT_RX_SCL_MOSI_PIN_INDEX] = UARTT_RX_SCL_MOSI_HSIOM_SEL_SPI;
        #elif (UARTT_RX_WAKE_SCL_MOSI_PIN)
            hsiomSel[UARTT_RX_WAKE_SCL_MOSI_PIN_INDEX] = UARTT_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI;
        #else
        #endif /* (UARTT_RX_SCL_MOSI_PIN) */
        
        #if (UARTT_TX_SDA_MISO_PIN)
            hsiomSel[UARTT_TX_SDA_MISO_PIN_INDEX] = UARTT_TX_SDA_MISO_HSIOM_SEL_SPI;
        #endif /* (UARTT_TX_SDA_MISO_PIN) */
        
        #if (UARTT_SCLK_PIN)
            hsiomSel[UARTT_SCLK_PIN_INDEX] = UARTT_SCLK_HSIOM_SEL_SPI;
        #endif /* (UARTT_SCLK_PIN) */

            if (UARTT_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[UARTT_RX_SCL_MOSI_PIN_INDEX] = UARTT_PIN_DM_DIG_HIZ;
                pinsDm[UARTT_TX_SDA_MISO_PIN_INDEX] = UARTT_PIN_DM_STRONG;
                pinsDm[UARTT_SCLK_PIN_INDEX] = UARTT_PIN_DM_DIG_HIZ;

            #if (UARTT_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[UARTT_SS0_PIN_INDEX] = UARTT_SS0_HSIOM_SEL_SPI;
                pinsDm  [UARTT_SS0_PIN_INDEX] = UARTT_PIN_DM_DIG_HIZ;
            #endif /* (UARTT_SS0_PIN) */

            #if (UARTT_TX_SDA_MISO_PIN)
                /* Disable input buffer */
                 pinsInBuf |= UARTT_TX_SDA_MISO_PIN_MASK;
            #endif /* (UARTT_TX_SDA_MISO_PIN) */
            }
            else 
            {
                /* (Master) */
                pinsDm[UARTT_RX_SCL_MOSI_PIN_INDEX] = UARTT_PIN_DM_STRONG;
                pinsDm[UARTT_TX_SDA_MISO_PIN_INDEX] = UARTT_PIN_DM_DIG_HIZ;
                pinsDm[UARTT_SCLK_PIN_INDEX] = UARTT_PIN_DM_STRONG;

            #if (UARTT_SS0_PIN)
                hsiomSel [UARTT_SS0_PIN_INDEX] = UARTT_SS0_HSIOM_SEL_SPI;
                pinsDm   [UARTT_SS0_PIN_INDEX] = UARTT_PIN_DM_STRONG;
                pinsInBuf |= UARTT_SS0_PIN_MASK;
            #endif /* (UARTT_SS0_PIN) */

            #if (UARTT_SS1_PIN)
                hsiomSel [UARTT_SS1_PIN_INDEX] = UARTT_SS1_HSIOM_SEL_SPI;
                pinsDm   [UARTT_SS1_PIN_INDEX] = UARTT_PIN_DM_STRONG;
                pinsInBuf |= UARTT_SS1_PIN_MASK;
            #endif /* (UARTT_SS1_PIN) */

            #if (UARTT_SS2_PIN)
                hsiomSel [UARTT_SS2_PIN_INDEX] = UARTT_SS2_HSIOM_SEL_SPI;
                pinsDm   [UARTT_SS2_PIN_INDEX] = UARTT_PIN_DM_STRONG;
                pinsInBuf |= UARTT_SS2_PIN_MASK;
            #endif /* (UARTT_SS2_PIN) */

            #if (UARTT_SS3_PIN)
                hsiomSel [UARTT_SS3_PIN_INDEX] = UARTT_SS3_HSIOM_SEL_SPI;
                pinsDm   [UARTT_SS3_PIN_INDEX] = UARTT_PIN_DM_STRONG;
                pinsInBuf |= UARTT_SS3_PIN_MASK;
            #endif /* (UARTT_SS3_PIN) */

                /* Disable input buffers */
            #if (UARTT_RX_SCL_MOSI_PIN)
                pinsInBuf |= UARTT_RX_SCL_MOSI_PIN_MASK;
            #elif (UARTT_RX_WAKE_SCL_MOSI_PIN)
                pinsInBuf |= UARTT_RX_WAKE_SCL_MOSI_PIN_MASK;
            #else
            #endif /* (UARTT_RX_SCL_MOSI_PIN) */

            #if (UARTT_SCLK_PIN)
                pinsInBuf |= UARTT_SCLK_PIN_MASK;
            #endif /* (UARTT_SCLK_PIN) */
            }
        }
        else /* UART */
        {
            if (UARTT_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
            #if (UARTT_TX_SDA_MISO_PIN)
                hsiomSel[UARTT_TX_SDA_MISO_PIN_INDEX] = UARTT_TX_SDA_MISO_HSIOM_SEL_UART;
                pinsDm  [UARTT_TX_SDA_MISO_PIN_INDEX] = UARTT_PIN_DM_OD_LO;
            #endif /* (UARTT_TX_SDA_MISO_PIN) */
            }
            else /* Standard or IrDA */
            {
                if (0u != (UARTT_UART_RX_PIN_ENABLE & uartEnableMask))
                {
                #if (UARTT_RX_SCL_MOSI_PIN)
                    hsiomSel[UARTT_RX_SCL_MOSI_PIN_INDEX] = UARTT_RX_SCL_MOSI_HSIOM_SEL_UART;
                    pinsDm  [UARTT_RX_SCL_MOSI_PIN_INDEX] = UARTT_PIN_DM_DIG_HIZ;
                #elif (UARTT_RX_WAKE_SCL_MOSI_PIN)
                    hsiomSel[UARTT_RX_WAKE_SCL_MOSI_PIN_INDEX] = UARTT_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART;
                    pinsDm  [UARTT_RX_WAKE_SCL_MOSI_PIN_INDEX] = UARTT_PIN_DM_DIG_HIZ;
                #else
                #endif /* (UARTT_RX_SCL_MOSI_PIN) */
                }

                if (0u != (UARTT_UART_TX_PIN_ENABLE & uartEnableMask))
                {
                #if (UARTT_TX_SDA_MISO_PIN)
                    hsiomSel[UARTT_TX_SDA_MISO_PIN_INDEX] = UARTT_TX_SDA_MISO_HSIOM_SEL_UART;
                    pinsDm  [UARTT_TX_SDA_MISO_PIN_INDEX] = UARTT_PIN_DM_STRONG;
                    
                    /* Disable input buffer */
                    pinsInBuf |= UARTT_TX_SDA_MISO_PIN_MASK;
                #endif /* (UARTT_TX_SDA_MISO_PIN) */
                }

            #if !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1)
                if (UARTT_UART_MODE_STD == subMode)
                {
                    if (0u != (UARTT_UART_CTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* CTS input is multiplexed with SCLK */
                    #if (UARTT_SCLK_PIN)
                        hsiomSel[UARTT_SCLK_PIN_INDEX] = UARTT_SCLK_HSIOM_SEL_UART;
                        pinsDm  [UARTT_SCLK_PIN_INDEX] = UARTT_PIN_DM_DIG_HIZ;
                    #endif /* (UARTT_SCLK_PIN) */
                    }

                    if (0u != (UARTT_UART_RTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* RTS output is multiplexed with SS0 */
                    #if (UARTT_SS0_PIN)
                        hsiomSel[UARTT_SS0_PIN_INDEX] = UARTT_SS0_HSIOM_SEL_UART;
                        pinsDm  [UARTT_SS0_PIN_INDEX] = UARTT_PIN_DM_STRONG;
                        
                        /* Disable input buffer */
                        pinsInBuf |= UARTT_SS0_PIN_MASK;
                    #endif /* (UARTT_SS0_PIN) */
                    }
                }
            #endif /* !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1) */
            }
        }
    #endif /* (!UARTT_CY_SCBIP_V1) */

    /* Configure pins: set HSIOM, DM and InputBufEnable */
    /* Note: the DR register settings do not effect the pin output if HSIOM is other than GPIO */

    #if (UARTT_RX_SCL_MOSI_PIN)
        UARTT_SET_HSIOM_SEL(UARTT_RX_SCL_MOSI_HSIOM_REG,
                                       UARTT_RX_SCL_MOSI_HSIOM_MASK,
                                       UARTT_RX_SCL_MOSI_HSIOM_POS,
                                        hsiomSel[UARTT_RX_SCL_MOSI_PIN_INDEX]);

        UARTT_uart_rx_i2c_scl_spi_mosi_SetDriveMode((uint8) pinsDm[UARTT_RX_SCL_MOSI_PIN_INDEX]);

        #if (!UARTT_CY_SCBIP_V1)
            UARTT_SET_INP_DIS(UARTT_uart_rx_i2c_scl_spi_mosi_INP_DIS,
                                         UARTT_uart_rx_i2c_scl_spi_mosi_MASK,
                                         (0u != (pinsInBuf & UARTT_RX_SCL_MOSI_PIN_MASK)));
        #endif /* (!UARTT_CY_SCBIP_V1) */
    
    #elif (UARTT_RX_WAKE_SCL_MOSI_PIN)
        UARTT_SET_HSIOM_SEL(UARTT_RX_WAKE_SCL_MOSI_HSIOM_REG,
                                       UARTT_RX_WAKE_SCL_MOSI_HSIOM_MASK,
                                       UARTT_RX_WAKE_SCL_MOSI_HSIOM_POS,
                                       hsiomSel[UARTT_RX_WAKE_SCL_MOSI_PIN_INDEX]);

        UARTT_uart_rx_wake_i2c_scl_spi_mosi_SetDriveMode((uint8)
                                                               pinsDm[UARTT_RX_WAKE_SCL_MOSI_PIN_INDEX]);

        UARTT_SET_INP_DIS(UARTT_uart_rx_wake_i2c_scl_spi_mosi_INP_DIS,
                                     UARTT_uart_rx_wake_i2c_scl_spi_mosi_MASK,
                                     (0u != (pinsInBuf & UARTT_RX_WAKE_SCL_MOSI_PIN_MASK)));

         /* Set interrupt on falling edge */
        UARTT_SET_INCFG_TYPE(UARTT_RX_WAKE_SCL_MOSI_INTCFG_REG,
                                        UARTT_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK,
                                        UARTT_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS,
                                        UARTT_INTCFG_TYPE_FALLING_EDGE);
    #else
    #endif /* (UARTT_RX_WAKE_SCL_MOSI_PIN) */

    #if (UARTT_TX_SDA_MISO_PIN)
        UARTT_SET_HSIOM_SEL(UARTT_TX_SDA_MISO_HSIOM_REG,
                                       UARTT_TX_SDA_MISO_HSIOM_MASK,
                                       UARTT_TX_SDA_MISO_HSIOM_POS,
                                        hsiomSel[UARTT_TX_SDA_MISO_PIN_INDEX]);

        UARTT_uart_tx_i2c_sda_spi_miso_SetDriveMode((uint8) pinsDm[UARTT_TX_SDA_MISO_PIN_INDEX]);

    #if (!UARTT_CY_SCBIP_V1)
        UARTT_SET_INP_DIS(UARTT_uart_tx_i2c_sda_spi_miso_INP_DIS,
                                     UARTT_uart_tx_i2c_sda_spi_miso_MASK,
                                    (0u != (pinsInBuf & UARTT_TX_SDA_MISO_PIN_MASK)));
    #endif /* (!UARTT_CY_SCBIP_V1) */
    #endif /* (UARTT_RX_SCL_MOSI_PIN) */

    #if (UARTT_SCLK_PIN)
        UARTT_SET_HSIOM_SEL(UARTT_SCLK_HSIOM_REG,
                                       UARTT_SCLK_HSIOM_MASK,
                                       UARTT_SCLK_HSIOM_POS,
                                       hsiomSel[UARTT_SCLK_PIN_INDEX]);

        UARTT_spi_sclk_SetDriveMode((uint8) pinsDm[UARTT_SCLK_PIN_INDEX]);

        UARTT_SET_INP_DIS(UARTT_spi_sclk_INP_DIS,
                                     UARTT_spi_sclk_MASK,
                                     (0u != (pinsInBuf & UARTT_SCLK_PIN_MASK)));
    #endif /* (UARTT_SCLK_PIN) */

    #if (UARTT_SS0_PIN)
        UARTT_SET_HSIOM_SEL(UARTT_SS0_HSIOM_REG,
                                       UARTT_SS0_HSIOM_MASK,
                                       UARTT_SS0_HSIOM_POS,
                                       hsiomSel[UARTT_SS0_PIN_INDEX]);

        UARTT_spi_ss0_SetDriveMode((uint8) pinsDm[UARTT_SS0_PIN_INDEX]);

        UARTT_SET_INP_DIS(UARTT_spi_ss0_INP_DIS,
                                     UARTT_spi_ss0_MASK,
                                     (0u != (pinsInBuf & UARTT_SS0_PIN_MASK)));
    #endif /* (UARTT_SS0_PIN) */

    #if (UARTT_SS1_PIN)
        UARTT_SET_HSIOM_SEL(UARTT_SS1_HSIOM_REG,
                                       UARTT_SS1_HSIOM_MASK,
                                       UARTT_SS1_HSIOM_POS,
                                       hsiomSel[UARTT_SS1_PIN_INDEX]);

        UARTT_spi_ss1_SetDriveMode((uint8) pinsDm[UARTT_SS1_PIN_INDEX]);

        UARTT_SET_INP_DIS(UARTT_spi_ss1_INP_DIS,
                                     UARTT_spi_ss1_MASK,
                                     (0u != (pinsInBuf & UARTT_SS1_PIN_MASK)));
    #endif /* (UARTT_SS1_PIN) */

    #if (UARTT_SS2_PIN)
        UARTT_SET_HSIOM_SEL(UARTT_SS2_HSIOM_REG,
                                       UARTT_SS2_HSIOM_MASK,
                                       UARTT_SS2_HSIOM_POS,
                                       hsiomSel[UARTT_SS2_PIN_INDEX]);

        UARTT_spi_ss2_SetDriveMode((uint8) pinsDm[UARTT_SS2_PIN_INDEX]);

        UARTT_SET_INP_DIS(UARTT_spi_ss2_INP_DIS,
                                     UARTT_spi_ss2_MASK,
                                     (0u != (pinsInBuf & UARTT_SS2_PIN_MASK)));
    #endif /* (UARTT_SS2_PIN) */

    #if (UARTT_SS3_PIN)
        UARTT_SET_HSIOM_SEL(UARTT_SS3_HSIOM_REG,
                                       UARTT_SS3_HSIOM_MASK,
                                       UARTT_SS3_HSIOM_POS,
                                       hsiomSel[UARTT_SS3_PIN_INDEX]);

        UARTT_spi_ss3_SetDriveMode((uint8) pinsDm[UARTT_SS3_PIN_INDEX]);

        UARTT_SET_INP_DIS(UARTT_spi_ss3_INP_DIS,
                                     UARTT_spi_ss3_MASK,
                                     (0u != (pinsInBuf & UARTT_SS3_PIN_MASK)));
    #endif /* (UARTT_SS3_PIN) */
    }

#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */


#if (UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: UARTT_I2CSlaveNackGeneration
    ****************************************************************************//**
    *
    *  Sets command to generate NACK to the address or data.
    *
    *******************************************************************************/
    void UARTT_I2CSlaveNackGeneration(void)
    {
        /* Check for EC_AM toggle condition: EC_AM and clock stretching for address are enabled */
        if ((0u != (UARTT_CTRL_REG & UARTT_CTRL_EC_AM_MODE)) &&
            (0u == (UARTT_I2C_CTRL_REG & UARTT_I2C_CTRL_S_NOT_READY_ADDR_NACK)))
        {
            /* Toggle EC_AM before NACK generation */
            UARTT_CTRL_REG &= ~UARTT_CTRL_EC_AM_MODE;
            UARTT_CTRL_REG |=  UARTT_CTRL_EC_AM_MODE;
        }

        UARTT_I2C_SLAVE_CMD_REG = UARTT_I2C_SLAVE_CMD_S_NACK;
    }
#endif /* (UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1) */


/* [] END OF FILE */
