/***************************************************************************//**
* \file UARTT_PM.c
* \version 3.20
*
* \brief
*  This file provides the source code to the Power Management support for
*  the SCB Component.
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

#include "UARTT.h"
#include "UARTT_PVT.h"

#if(UARTT_SCB_MODE_I2C_INC)
    #include "UARTT_I2C_PVT.h"
#endif /* (UARTT_SCB_MODE_I2C_INC) */

#if(UARTT_SCB_MODE_EZI2C_INC)
    #include "UARTT_EZI2C_PVT.h"
#endif /* (UARTT_SCB_MODE_EZI2C_INC) */

#if(UARTT_SCB_MODE_SPI_INC || UARTT_SCB_MODE_UART_INC)
    #include "UARTT_SPI_UART_PVT.h"
#endif /* (UARTT_SCB_MODE_SPI_INC || UARTT_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(UARTT_SCB_MODE_UNCONFIG_CONST_CFG || \
   (UARTT_SCB_MODE_I2C_CONST_CFG   && (!UARTT_I2C_WAKE_ENABLE_CONST))   || \
   (UARTT_SCB_MODE_EZI2C_CONST_CFG && (!UARTT_EZI2C_WAKE_ENABLE_CONST)) || \
   (UARTT_SCB_MODE_SPI_CONST_CFG   && (!UARTT_SPI_WAKE_ENABLE_CONST))   || \
   (UARTT_SCB_MODE_UART_CONST_CFG  && (!UARTT_UART_WAKE_ENABLE_CONST)))

    UARTT_BACKUP_STRUCT UARTT_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: UARTT_Sleep
****************************************************************************//**
*
*  Prepares the UARTT component to enter Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has an influence on this 
*  function implementation:
*  - Checked: configures the component to be wakeup source from Deep Sleep.
*  - Unchecked: stores the current component state (enabled or disabled) and 
*    disables the component. See SCB_Stop() function for details about component 
*    disabling.
*
*  Call the UARTT_Sleep() function before calling the 
*  CyPmSysDeepSleep() function. 
*  Refer to the PSoC Creator System Reference Guide for more information about 
*  power management functions and Low power section of this document for the 
*  selected mode.
*
*  This function should not be called before entering Sleep.
*
*******************************************************************************/
void UARTT_Sleep(void)
{
#if(UARTT_SCB_MODE_UNCONFIG_CONST_CFG)

    if(UARTT_SCB_WAKE_ENABLE_CHECK)
    {
        if(UARTT_SCB_MODE_I2C_RUNTM_CFG)
        {
            UARTT_I2CSaveConfig();
        }
        else if(UARTT_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            UARTT_EzI2CSaveConfig();
        }
    #if(!UARTT_CY_SCBIP_V1)
        else if(UARTT_SCB_MODE_SPI_RUNTM_CFG)
        {
            UARTT_SpiSaveConfig();
        }
        else if(UARTT_SCB_MODE_UART_RUNTM_CFG)
        {
            UARTT_UartSaveConfig();
        }
    #endif /* (!UARTT_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        UARTT_backup.enableState = (uint8) UARTT_GET_CTRL_ENABLED;

        if(0u != UARTT_backup.enableState)
        {
            UARTT_Stop();
        }
    }

#else

    #if (UARTT_SCB_MODE_I2C_CONST_CFG && UARTT_I2C_WAKE_ENABLE_CONST)
        UARTT_I2CSaveConfig();

    #elif (UARTT_SCB_MODE_EZI2C_CONST_CFG && UARTT_EZI2C_WAKE_ENABLE_CONST)
        UARTT_EzI2CSaveConfig();

    #elif (UARTT_SCB_MODE_SPI_CONST_CFG && UARTT_SPI_WAKE_ENABLE_CONST)
        UARTT_SpiSaveConfig();

    #elif (UARTT_SCB_MODE_UART_CONST_CFG && UARTT_UART_WAKE_ENABLE_CONST)
        UARTT_UartSaveConfig();

    #else

        UARTT_backup.enableState = (uint8) UARTT_GET_CTRL_ENABLED;

        if(0u != UARTT_backup.enableState)
        {
            UARTT_Stop();
        }

    #endif /* defined (UARTT_SCB_MODE_I2C_CONST_CFG) && (UARTT_I2C_WAKE_ENABLE_CONST) */

#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UARTT_Wakeup
****************************************************************************//**
*
*  Prepares the UARTT component for Active mode operation after 
*  Deep Sleep.
*  The “Enable wakeup from Deep Sleep Mode” selection has influence on this 
*  function implementation:
*  - Checked: restores the component Active mode configuration.
*  - Unchecked: enables the component if it was enabled before enter Deep Sleep.
*
*  This function should not be called after exiting Sleep.
*
*  \sideeffect
*   Calling the UARTT_Wakeup() function without first calling the 
*   UARTT_Sleep() function may produce unexpected behavior.
*
*******************************************************************************/
void UARTT_Wakeup(void)
{
#if(UARTT_SCB_MODE_UNCONFIG_CONST_CFG)

    if(UARTT_SCB_WAKE_ENABLE_CHECK)
    {
        if(UARTT_SCB_MODE_I2C_RUNTM_CFG)
        {
            UARTT_I2CRestoreConfig();
        }
        else if(UARTT_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            UARTT_EzI2CRestoreConfig();
        }
    #if(!UARTT_CY_SCBIP_V1)
        else if(UARTT_SCB_MODE_SPI_RUNTM_CFG)
        {
            UARTT_SpiRestoreConfig();
        }
        else if(UARTT_SCB_MODE_UART_RUNTM_CFG)
        {
            UARTT_UartRestoreConfig();
        }
    #endif /* (!UARTT_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != UARTT_backup.enableState)
        {
            UARTT_Enable();
        }
    }

#else

    #if (UARTT_SCB_MODE_I2C_CONST_CFG  && UARTT_I2C_WAKE_ENABLE_CONST)
        UARTT_I2CRestoreConfig();

    #elif (UARTT_SCB_MODE_EZI2C_CONST_CFG && UARTT_EZI2C_WAKE_ENABLE_CONST)
        UARTT_EzI2CRestoreConfig();

    #elif (UARTT_SCB_MODE_SPI_CONST_CFG && UARTT_SPI_WAKE_ENABLE_CONST)
        UARTT_SpiRestoreConfig();

    #elif (UARTT_SCB_MODE_UART_CONST_CFG && UARTT_UART_WAKE_ENABLE_CONST)
        UARTT_UartRestoreConfig();

    #else

        if(0u != UARTT_backup.enableState)
        {
            UARTT_Enable();
        }

    #endif /* (UARTT_I2C_WAKE_ENABLE_CONST) */

#endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
