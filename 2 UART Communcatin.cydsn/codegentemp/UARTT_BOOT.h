/***************************************************************************//**
* \file UARTT_BOOT.h
* \version 3.20
*
* \brief
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2014-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_UARTT_H)
#define CY_SCB_BOOT_UARTT_H

#include "UARTT_PVT.h"

#if (UARTT_SCB_MODE_I2C_INC)
    #include "UARTT_I2C.h"
#endif /* (UARTT_SCB_MODE_I2C_INC) */

#if (UARTT_SCB_MODE_EZI2C_INC)
    #include "UARTT_EZI2C.h"
#endif /* (UARTT_SCB_MODE_EZI2C_INC) */

#if (UARTT_SCB_MODE_SPI_INC || UARTT_SCB_MODE_UART_INC)
    #include "UARTT_SPI_UART.h"
#endif /* (UARTT_SCB_MODE_SPI_INC || UARTT_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define UARTT_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UARTT) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (UARTT_SCB_MODE_I2C_INC)
    #define UARTT_I2C_BTLDR_COMM_ENABLED     (UARTT_BTLDR_COMM_ENABLED && \
                                                            (UARTT_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             UARTT_I2C_SLAVE_CONST))
#else
     #define UARTT_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (UARTT_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (UARTT_SCB_MODE_EZI2C_INC)
    #define UARTT_EZI2C_BTLDR_COMM_ENABLED   (UARTT_BTLDR_COMM_ENABLED && \
                                                         UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define UARTT_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (UARTT_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (UARTT_SCB_MODE_SPI_INC)
    #define UARTT_SPI_BTLDR_COMM_ENABLED     (UARTT_BTLDR_COMM_ENABLED && \
                                                            (UARTT_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             UARTT_SPI_SLAVE_CONST))
#else
        #define UARTT_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (UARTT_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (UARTT_SCB_MODE_UART_INC)
       #define UARTT_UART_BTLDR_COMM_ENABLED    (UARTT_BTLDR_COMM_ENABLED && \
                                                            (UARTT_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (UARTT_UART_RX_DIRECTION && \
                                                              UARTT_UART_TX_DIRECTION)))
#else
     #define UARTT_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (UARTT_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define UARTT_BTLDR_COMM_MODE_ENABLED    (UARTT_I2C_BTLDR_COMM_ENABLED   || \
                                                     UARTT_SPI_BTLDR_COMM_ENABLED   || \
                                                     UARTT_EZI2C_BTLDR_COMM_ENABLED || \
                                                     UARTT_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (UARTT_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void UARTT_I2CCyBtldrCommStart(void);
    void UARTT_I2CCyBtldrCommStop (void);
    void UARTT_I2CCyBtldrCommReset(void);
    cystatus UARTT_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus UARTT_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (UARTT_SCB_MODE_I2C_CONST_CFG)
        #define UARTT_CyBtldrCommStart   UARTT_I2CCyBtldrCommStart
        #define UARTT_CyBtldrCommStop    UARTT_I2CCyBtldrCommStop
        #define UARTT_CyBtldrCommReset   UARTT_I2CCyBtldrCommReset
        #define UARTT_CyBtldrCommRead    UARTT_I2CCyBtldrCommRead
        #define UARTT_CyBtldrCommWrite   UARTT_I2CCyBtldrCommWrite
    #endif /* (UARTT_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (UARTT_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (UARTT_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void UARTT_EzI2CCyBtldrCommStart(void);
    void UARTT_EzI2CCyBtldrCommStop (void);
    void UARTT_EzI2CCyBtldrCommReset(void);
    cystatus UARTT_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus UARTT_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (UARTT_SCB_MODE_EZI2C_CONST_CFG)
        #define UARTT_CyBtldrCommStart   UARTT_EzI2CCyBtldrCommStart
        #define UARTT_CyBtldrCommStop    UARTT_EzI2CCyBtldrCommStop
        #define UARTT_CyBtldrCommReset   UARTT_EzI2CCyBtldrCommReset
        #define UARTT_CyBtldrCommRead    UARTT_EzI2CCyBtldrCommRead
        #define UARTT_CyBtldrCommWrite   UARTT_EzI2CCyBtldrCommWrite
    #endif /* (UARTT_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (UARTT_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (UARTT_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void UARTT_SpiCyBtldrCommStart(void);
    void UARTT_SpiCyBtldrCommStop (void);
    void UARTT_SpiCyBtldrCommReset(void);
    cystatus UARTT_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus UARTT_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (UARTT_SCB_MODE_SPI_CONST_CFG)
        #define UARTT_CyBtldrCommStart   UARTT_SpiCyBtldrCommStart
        #define UARTT_CyBtldrCommStop    UARTT_SpiCyBtldrCommStop
        #define UARTT_CyBtldrCommReset   UARTT_SpiCyBtldrCommReset
        #define UARTT_CyBtldrCommRead    UARTT_SpiCyBtldrCommRead
        #define UARTT_CyBtldrCommWrite   UARTT_SpiCyBtldrCommWrite
    #endif /* (UARTT_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (UARTT_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (UARTT_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void UARTT_UartCyBtldrCommStart(void);
    void UARTT_UartCyBtldrCommStop (void);
    void UARTT_UartCyBtldrCommReset(void);
    cystatus UARTT_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus UARTT_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (UARTT_SCB_MODE_UART_CONST_CFG)
        #define UARTT_CyBtldrCommStart   UARTT_UartCyBtldrCommStart
        #define UARTT_CyBtldrCommStop    UARTT_UartCyBtldrCommStop
        #define UARTT_CyBtldrCommReset   UARTT_UartCyBtldrCommReset
        #define UARTT_CyBtldrCommRead    UARTT_UartCyBtldrCommRead
        #define UARTT_CyBtldrCommWrite   UARTT_UartCyBtldrCommWrite
    #endif /* (UARTT_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (UARTT_UART_BTLDR_COMM_ENABLED) */

/**
* \addtogroup group_bootloader
* @{
*/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (UARTT_BTLDR_COMM_ENABLED)
    #if (UARTT_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void UARTT_CyBtldrCommStart(void);
        void UARTT_CyBtldrCommStop (void);
        void UARTT_CyBtldrCommReset(void);
        cystatus UARTT_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus UARTT_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (UARTT_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UARTT)
        #define CyBtldrCommStart    UARTT_CyBtldrCommStart
        #define CyBtldrCommStop     UARTT_CyBtldrCommStop
        #define CyBtldrCommReset    UARTT_CyBtldrCommReset
        #define CyBtldrCommWrite    UARTT_CyBtldrCommWrite
        #define CyBtldrCommRead     UARTT_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UARTT) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (UARTT_BTLDR_COMM_ENABLED) */

/** @} group_bootloader */

/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define UARTT_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define UARTT_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define UARTT_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define UARTT_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef UARTT_SPI_BYTE_TO_BYTE
    #define UARTT_SPI_BYTE_TO_BYTE   (160u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef UARTT_UART_BYTE_TO_BYTE
    #define UARTT_UART_BYTE_TO_BYTE  (4171u)
#endif /* UARTT_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_UARTT_H) */


/* [] END OF FILE */
