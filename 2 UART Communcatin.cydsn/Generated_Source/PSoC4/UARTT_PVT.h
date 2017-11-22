/***************************************************************************//**
* \file .h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
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

#if !defined(CY_SCB_PVT_UARTT_H)
#define CY_SCB_PVT_UARTT_H

#include "UARTT.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define UARTT_SetI2CExtClkInterruptMode(interruptMask) UARTT_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define UARTT_ClearI2CExtClkInterruptSource(interruptMask) UARTT_CLEAR_INTR_I2C_EC(interruptMask)
#define UARTT_GetI2CExtClkInterruptSource()                (UARTT_INTR_I2C_EC_REG)
#define UARTT_GetI2CExtClkInterruptMode()                  (UARTT_INTR_I2C_EC_MASK_REG)
#define UARTT_GetI2CExtClkInterruptSourceMasked()          (UARTT_INTR_I2C_EC_MASKED_REG)

#if (!UARTT_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define UARTT_SetSpiExtClkInterruptMode(interruptMask) \
                                                                UARTT_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define UARTT_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                UARTT_CLEAR_INTR_SPI_EC(interruptMask)
    #define UARTT_GetExtSpiClkInterruptSource()                 (UARTT_INTR_SPI_EC_REG)
    #define UARTT_GetExtSpiClkInterruptMode()                   (UARTT_INTR_SPI_EC_MASK_REG)
    #define UARTT_GetExtSpiClkInterruptSourceMasked()           (UARTT_INTR_SPI_EC_MASKED_REG)
#endif /* (!UARTT_CY_SCBIP_V1) */

#if(UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void UARTT_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (UARTT_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_UARTT_CUSTOM_INTR_HANDLER)
    extern cyisraddress UARTT_customIntrHandler;
#endif /* !defined (CY_REMOVE_UARTT_CUSTOM_INTR_HANDLER) */
#endif /* (UARTT_SCB_IRQ_INTERNAL) */

extern UARTT_BACKUP_STRUCT UARTT_backup;

#if(UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 UARTT_scbMode;
    extern uint8 UARTT_scbEnableWake;
    extern uint8 UARTT_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 UARTT_mode;
    extern uint8 UARTT_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * UARTT_rxBuffer;
    extern uint8   UARTT_rxDataBits;
    extern uint32  UARTT_rxBufferSize;

    extern volatile uint8 * UARTT_txBuffer;
    extern uint8   UARTT_txDataBits;
    extern uint32  UARTT_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 UARTT_numberOfAddr;
    extern uint8 UARTT_subAddrSize;
#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (UARTT_SCB_MODE_I2C_CONST_CFG || \
        UARTT_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 UARTT_IntrTxMask;
#endif /* (! (UARTT_SCB_MODE_I2C_CONST_CFG || \
              UARTT_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define UARTT_SCB_MODE_I2C_RUNTM_CFG     (UARTT_SCB_MODE_I2C      == UARTT_scbMode)
    #define UARTT_SCB_MODE_SPI_RUNTM_CFG     (UARTT_SCB_MODE_SPI      == UARTT_scbMode)
    #define UARTT_SCB_MODE_UART_RUNTM_CFG    (UARTT_SCB_MODE_UART     == UARTT_scbMode)
    #define UARTT_SCB_MODE_EZI2C_RUNTM_CFG   (UARTT_SCB_MODE_EZI2C    == UARTT_scbMode)
    #define UARTT_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (UARTT_SCB_MODE_UNCONFIG == UARTT_scbMode)

    /* Defines wakeup enable */
    #define UARTT_SCB_WAKE_ENABLE_CHECK       (0u != UARTT_scbEnableWake)
#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!UARTT_CY_SCBIP_V1)
    #define UARTT_SCB_PINS_NUMBER    (7u)
#else
    #define UARTT_SCB_PINS_NUMBER    (2u)
#endif /* (!UARTT_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_UARTT_H) */


/* [] END OF FILE */
