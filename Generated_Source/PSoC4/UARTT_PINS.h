/***************************************************************************//**
* \file UARTT_PINS.h
* \version 3.20
*
* \brief
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
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

#if !defined(CY_SCB_PINS_UARTT_H)
#define CY_SCB_PINS_UARTT_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define UARTT_REMOVE_RX_WAKE_SCL_MOSI_PIN  (1u)
#define UARTT_REMOVE_RX_SCL_MOSI_PIN      (1u)
#define UARTT_REMOVE_TX_SDA_MISO_PIN      (1u)
#define UARTT_REMOVE_SCLK_PIN      (1u)
#define UARTT_REMOVE_SS0_PIN      (1u)
#define UARTT_REMOVE_SS1_PIN                 (1u)
#define UARTT_REMOVE_SS2_PIN                 (1u)
#define UARTT_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define UARTT_REMOVE_I2C_PINS                (1u)
#define UARTT_REMOVE_SPI_MASTER_PINS         (1u)
#define UARTT_REMOVE_SPI_MASTER_SCLK_PIN     (1u)
#define UARTT_REMOVE_SPI_MASTER_MOSI_PIN     (1u)
#define UARTT_REMOVE_SPI_MASTER_MISO_PIN     (1u)
#define UARTT_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define UARTT_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define UARTT_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define UARTT_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define UARTT_REMOVE_SPI_SLAVE_PINS          (1u)
#define UARTT_REMOVE_SPI_SLAVE_MOSI_PIN      (1u)
#define UARTT_REMOVE_SPI_SLAVE_MISO_PIN      (1u)
#define UARTT_REMOVE_UART_TX_PIN             (0u)
#define UARTT_REMOVE_UART_RX_TX_PIN          (1u)
#define UARTT_REMOVE_UART_RX_PIN             (0u)
#define UARTT_REMOVE_UART_RX_WAKE_PIN        (1u)
#define UARTT_REMOVE_UART_RTS_PIN            (1u)
#define UARTT_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define UARTT_RX_WAKE_SCL_MOSI_PIN (0u == UARTT_REMOVE_RX_WAKE_SCL_MOSI_PIN)
#define UARTT_RX_SCL_MOSI_PIN     (0u == UARTT_REMOVE_RX_SCL_MOSI_PIN)
#define UARTT_TX_SDA_MISO_PIN     (0u == UARTT_REMOVE_TX_SDA_MISO_PIN)
#define UARTT_SCLK_PIN     (0u == UARTT_REMOVE_SCLK_PIN)
#define UARTT_SS0_PIN     (0u == UARTT_REMOVE_SS0_PIN)
#define UARTT_SS1_PIN                (0u == UARTT_REMOVE_SS1_PIN)
#define UARTT_SS2_PIN                (0u == UARTT_REMOVE_SS2_PIN)
#define UARTT_SS3_PIN                (0u == UARTT_REMOVE_SS3_PIN)

/* Mode defined pins */
#define UARTT_I2C_PINS               (0u == UARTT_REMOVE_I2C_PINS)
#define UARTT_SPI_MASTER_PINS        (0u == UARTT_REMOVE_SPI_MASTER_PINS)
#define UARTT_SPI_MASTER_SCLK_PIN    (0u == UARTT_REMOVE_SPI_MASTER_SCLK_PIN)
#define UARTT_SPI_MASTER_MOSI_PIN    (0u == UARTT_REMOVE_SPI_MASTER_MOSI_PIN)
#define UARTT_SPI_MASTER_MISO_PIN    (0u == UARTT_REMOVE_SPI_MASTER_MISO_PIN)
#define UARTT_SPI_MASTER_SS0_PIN     (0u == UARTT_REMOVE_SPI_MASTER_SS0_PIN)
#define UARTT_SPI_MASTER_SS1_PIN     (0u == UARTT_REMOVE_SPI_MASTER_SS1_PIN)
#define UARTT_SPI_MASTER_SS2_PIN     (0u == UARTT_REMOVE_SPI_MASTER_SS2_PIN)
#define UARTT_SPI_MASTER_SS3_PIN     (0u == UARTT_REMOVE_SPI_MASTER_SS3_PIN)
#define UARTT_SPI_SLAVE_PINS         (0u == UARTT_REMOVE_SPI_SLAVE_PINS)
#define UARTT_SPI_SLAVE_MOSI_PIN     (0u == UARTT_REMOVE_SPI_SLAVE_MOSI_PIN)
#define UARTT_SPI_SLAVE_MISO_PIN     (0u == UARTT_REMOVE_SPI_SLAVE_MISO_PIN)
#define UARTT_UART_TX_PIN            (0u == UARTT_REMOVE_UART_TX_PIN)
#define UARTT_UART_RX_TX_PIN         (0u == UARTT_REMOVE_UART_RX_TX_PIN)
#define UARTT_UART_RX_PIN            (0u == UARTT_REMOVE_UART_RX_PIN)
#define UARTT_UART_RX_WAKE_PIN       (0u == UARTT_REMOVE_UART_RX_WAKE_PIN)
#define UARTT_UART_RTS_PIN           (0u == UARTT_REMOVE_UART_RTS_PIN)
#define UARTT_UART_CTS_PIN           (0u == UARTT_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (UARTT_RX_WAKE_SCL_MOSI_PIN)
    #include "UARTT_uart_rx_wake_i2c_scl_spi_mosi.h"
#endif /* (UARTT_RX_SCL_MOSI) */

#if (UARTT_RX_SCL_MOSI_PIN)
    #include "UARTT_uart_rx_i2c_scl_spi_mosi.h"
#endif /* (UARTT_RX_SCL_MOSI) */

#if (UARTT_TX_SDA_MISO_PIN)
    #include "UARTT_uart_tx_i2c_sda_spi_miso.h"
#endif /* (UARTT_TX_SDA_MISO) */

#if (UARTT_SCLK_PIN)
    #include "UARTT_spi_sclk.h"
#endif /* (UARTT_SCLK) */

#if (UARTT_SS0_PIN)
    #include "UARTT_spi_ss0.h"
#endif /* (UARTT_SS0_PIN) */

#if (UARTT_SS1_PIN)
    #include "UARTT_spi_ss1.h"
#endif /* (UARTT_SS1_PIN) */

#if (UARTT_SS2_PIN)
    #include "UARTT_spi_ss2.h"
#endif /* (UARTT_SS2_PIN) */

#if (UARTT_SS3_PIN)
    #include "UARTT_spi_ss3.h"
#endif /* (UARTT_SS3_PIN) */

#if (UARTT_I2C_PINS)
    #include "UARTT_scl.h"
    #include "UARTT_sda.h"
#endif /* (UARTT_I2C_PINS) */

#if (UARTT_SPI_MASTER_PINS)
#if (UARTT_SPI_MASTER_SCLK_PIN)
    #include "UARTT_sclk_m.h"
#endif /* (UARTT_SPI_MASTER_SCLK_PIN) */

#if (UARTT_SPI_MASTER_MOSI_PIN)
    #include "UARTT_mosi_m.h"
#endif /* (UARTT_SPI_MASTER_MOSI_PIN) */

#if (UARTT_SPI_MASTER_MISO_PIN)
    #include "UARTT_miso_m.h"
#endif /*(UARTT_SPI_MASTER_MISO_PIN) */
#endif /* (UARTT_SPI_MASTER_PINS) */

#if (UARTT_SPI_SLAVE_PINS)
    #include "UARTT_sclk_s.h"
    #include "UARTT_ss_s.h"

#if (UARTT_SPI_SLAVE_MOSI_PIN)
    #include "UARTT_mosi_s.h"
#endif /* (UARTT_SPI_SLAVE_MOSI_PIN) */

#if (UARTT_SPI_SLAVE_MISO_PIN)
    #include "UARTT_miso_s.h"
#endif /*(UARTT_SPI_SLAVE_MISO_PIN) */
#endif /* (UARTT_SPI_SLAVE_PINS) */

#if (UARTT_SPI_MASTER_SS0_PIN)
    #include "UARTT_ss0_m.h"
#endif /* (UARTT_SPI_MASTER_SS0_PIN) */

#if (UARTT_SPI_MASTER_SS1_PIN)
    #include "UARTT_ss1_m.h"
#endif /* (UARTT_SPI_MASTER_SS1_PIN) */

#if (UARTT_SPI_MASTER_SS2_PIN)
    #include "UARTT_ss2_m.h"
#endif /* (UARTT_SPI_MASTER_SS2_PIN) */

#if (UARTT_SPI_MASTER_SS3_PIN)
    #include "UARTT_ss3_m.h"
#endif /* (UARTT_SPI_MASTER_SS3_PIN) */

#if (UARTT_UART_TX_PIN)
    #include "UARTT_tx.h"
#endif /* (UARTT_UART_TX_PIN) */

#if (UARTT_UART_RX_TX_PIN)
    #include "UARTT_rx_tx.h"
#endif /* (UARTT_UART_RX_TX_PIN) */

#if (UARTT_UART_RX_PIN)
    #include "UARTT_rx.h"
#endif /* (UARTT_UART_RX_PIN) */

#if (UARTT_UART_RX_WAKE_PIN)
    #include "UARTT_rx_wake.h"
#endif /* (UARTT_UART_RX_WAKE_PIN) */

#if (UARTT_UART_RTS_PIN)
    #include "UARTT_rts.h"
#endif /* (UARTT_UART_RTS_PIN) */

#if (UARTT_UART_CTS_PIN)
    #include "UARTT_cts.h"
#endif /* (UARTT_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (UARTT_RX_SCL_MOSI_PIN)
    #define UARTT_RX_SCL_MOSI_HSIOM_REG   (*(reg32 *) UARTT_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    #define UARTT_RX_SCL_MOSI_HSIOM_PTR   ( (reg32 *) UARTT_uart_rx_i2c_scl_spi_mosi__0__HSIOM)
    
    #define UARTT_RX_SCL_MOSI_HSIOM_MASK      (UARTT_uart_rx_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define UARTT_RX_SCL_MOSI_HSIOM_POS       (UARTT_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define UARTT_RX_SCL_MOSI_HSIOM_SEL_GPIO  (UARTT_uart_rx_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define UARTT_RX_SCL_MOSI_HSIOM_SEL_I2C   (UARTT_uart_rx_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define UARTT_RX_SCL_MOSI_HSIOM_SEL_SPI   (UARTT_uart_rx_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define UARTT_RX_SCL_MOSI_HSIOM_SEL_UART  (UARTT_uart_rx_i2c_scl_spi_mosi__0__HSIOM_UART)
    
#elif (UARTT_RX_WAKE_SCL_MOSI_PIN)
    #define UARTT_RX_WAKE_SCL_MOSI_HSIOM_REG   (*(reg32 *) UARTT_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    #define UARTT_RX_WAKE_SCL_MOSI_HSIOM_PTR   ( (reg32 *) UARTT_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM)
    
    #define UARTT_RX_WAKE_SCL_MOSI_HSIOM_MASK      (UARTT_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_MASK)
    #define UARTT_RX_WAKE_SCL_MOSI_HSIOM_POS       (UARTT_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SHIFT)
    #define UARTT_RX_WAKE_SCL_MOSI_HSIOM_SEL_GPIO  (UARTT_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_GPIO)
    #define UARTT_RX_WAKE_SCL_MOSI_HSIOM_SEL_I2C   (UARTT_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_I2C)
    #define UARTT_RX_WAKE_SCL_MOSI_HSIOM_SEL_SPI   (UARTT_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_SPI)
    #define UARTT_RX_WAKE_SCL_MOSI_HSIOM_SEL_UART  (UARTT_uart_rx_wake_i2c_scl_spi_mosi__0__HSIOM_UART)    
   
    #define UARTT_RX_WAKE_SCL_MOSI_INTCFG_REG (*(reg32 *) UARTT_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define UARTT_RX_WAKE_SCL_MOSI_INTCFG_PTR ( (reg32 *) UARTT_uart_rx_wake_i2c_scl_spi_mosi__0__INTCFG)
    #define UARTT_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS  (UARTT_uart_rx_wake_i2c_scl_spi_mosi__SHIFT)
    #define UARTT_RX_WAKE_SCL_MOSI_INTCFG_TYPE_MASK ((uint32) UARTT_INTCFG_TYPE_MASK << \
                                                                           UARTT_RX_WAKE_SCL_MOSI_INTCFG_TYPE_POS)
#else
    /* None of pins UARTT_RX_SCL_MOSI_PIN or UARTT_RX_WAKE_SCL_MOSI_PIN present.*/
#endif /* (UARTT_RX_SCL_MOSI_PIN) */

#if (UARTT_TX_SDA_MISO_PIN)
    #define UARTT_TX_SDA_MISO_HSIOM_REG   (*(reg32 *) UARTT_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    #define UARTT_TX_SDA_MISO_HSIOM_PTR   ( (reg32 *) UARTT_uart_tx_i2c_sda_spi_miso__0__HSIOM)
    
    #define UARTT_TX_SDA_MISO_HSIOM_MASK      (UARTT_uart_tx_i2c_sda_spi_miso__0__HSIOM_MASK)
    #define UARTT_TX_SDA_MISO_HSIOM_POS       (UARTT_uart_tx_i2c_sda_spi_miso__0__HSIOM_SHIFT)
    #define UARTT_TX_SDA_MISO_HSIOM_SEL_GPIO  (UARTT_uart_tx_i2c_sda_spi_miso__0__HSIOM_GPIO)
    #define UARTT_TX_SDA_MISO_HSIOM_SEL_I2C   (UARTT_uart_tx_i2c_sda_spi_miso__0__HSIOM_I2C)
    #define UARTT_TX_SDA_MISO_HSIOM_SEL_SPI   (UARTT_uart_tx_i2c_sda_spi_miso__0__HSIOM_SPI)
    #define UARTT_TX_SDA_MISO_HSIOM_SEL_UART  (UARTT_uart_tx_i2c_sda_spi_miso__0__HSIOM_UART)
#endif /* (UARTT_TX_SDA_MISO_PIN) */

#if (UARTT_SCLK_PIN)
    #define UARTT_SCLK_HSIOM_REG   (*(reg32 *) UARTT_spi_sclk__0__HSIOM)
    #define UARTT_SCLK_HSIOM_PTR   ( (reg32 *) UARTT_spi_sclk__0__HSIOM)
    
    #define UARTT_SCLK_HSIOM_MASK      (UARTT_spi_sclk__0__HSIOM_MASK)
    #define UARTT_SCLK_HSIOM_POS       (UARTT_spi_sclk__0__HSIOM_SHIFT)
    #define UARTT_SCLK_HSIOM_SEL_GPIO  (UARTT_spi_sclk__0__HSIOM_GPIO)
    #define UARTT_SCLK_HSIOM_SEL_I2C   (UARTT_spi_sclk__0__HSIOM_I2C)
    #define UARTT_SCLK_HSIOM_SEL_SPI   (UARTT_spi_sclk__0__HSIOM_SPI)
    #define UARTT_SCLK_HSIOM_SEL_UART  (UARTT_spi_sclk__0__HSIOM_UART)
#endif /* (UARTT_SCLK_PIN) */

#if (UARTT_SS0_PIN)
    #define UARTT_SS0_HSIOM_REG   (*(reg32 *) UARTT_spi_ss0__0__HSIOM)
    #define UARTT_SS0_HSIOM_PTR   ( (reg32 *) UARTT_spi_ss0__0__HSIOM)
    
    #define UARTT_SS0_HSIOM_MASK      (UARTT_spi_ss0__0__HSIOM_MASK)
    #define UARTT_SS0_HSIOM_POS       (UARTT_spi_ss0__0__HSIOM_SHIFT)
    #define UARTT_SS0_HSIOM_SEL_GPIO  (UARTT_spi_ss0__0__HSIOM_GPIO)
    #define UARTT_SS0_HSIOM_SEL_I2C   (UARTT_spi_ss0__0__HSIOM_I2C)
    #define UARTT_SS0_HSIOM_SEL_SPI   (UARTT_spi_ss0__0__HSIOM_SPI)
#if !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1)
    #define UARTT_SS0_HSIOM_SEL_UART  (UARTT_spi_ss0__0__HSIOM_UART)
#endif /* !(UARTT_CY_SCBIP_V0 || UARTT_CY_SCBIP_V1) */
#endif /* (UARTT_SS0_PIN) */

#if (UARTT_SS1_PIN)
    #define UARTT_SS1_HSIOM_REG  (*(reg32 *) UARTT_spi_ss1__0__HSIOM)
    #define UARTT_SS1_HSIOM_PTR  ( (reg32 *) UARTT_spi_ss1__0__HSIOM)
    
    #define UARTT_SS1_HSIOM_MASK     (UARTT_spi_ss1__0__HSIOM_MASK)
    #define UARTT_SS1_HSIOM_POS      (UARTT_spi_ss1__0__HSIOM_SHIFT)
    #define UARTT_SS1_HSIOM_SEL_GPIO (UARTT_spi_ss1__0__HSIOM_GPIO)
    #define UARTT_SS1_HSIOM_SEL_I2C  (UARTT_spi_ss1__0__HSIOM_I2C)
    #define UARTT_SS1_HSIOM_SEL_SPI  (UARTT_spi_ss1__0__HSIOM_SPI)
#endif /* (UARTT_SS1_PIN) */

#if (UARTT_SS2_PIN)
    #define UARTT_SS2_HSIOM_REG     (*(reg32 *) UARTT_spi_ss2__0__HSIOM)
    #define UARTT_SS2_HSIOM_PTR     ( (reg32 *) UARTT_spi_ss2__0__HSIOM)
    
    #define UARTT_SS2_HSIOM_MASK     (UARTT_spi_ss2__0__HSIOM_MASK)
    #define UARTT_SS2_HSIOM_POS      (UARTT_spi_ss2__0__HSIOM_SHIFT)
    #define UARTT_SS2_HSIOM_SEL_GPIO (UARTT_spi_ss2__0__HSIOM_GPIO)
    #define UARTT_SS2_HSIOM_SEL_I2C  (UARTT_spi_ss2__0__HSIOM_I2C)
    #define UARTT_SS2_HSIOM_SEL_SPI  (UARTT_spi_ss2__0__HSIOM_SPI)
#endif /* (UARTT_SS2_PIN) */

#if (UARTT_SS3_PIN)
    #define UARTT_SS3_HSIOM_REG     (*(reg32 *) UARTT_spi_ss3__0__HSIOM)
    #define UARTT_SS3_HSIOM_PTR     ( (reg32 *) UARTT_spi_ss3__0__HSIOM)
    
    #define UARTT_SS3_HSIOM_MASK     (UARTT_spi_ss3__0__HSIOM_MASK)
    #define UARTT_SS3_HSIOM_POS      (UARTT_spi_ss3__0__HSIOM_SHIFT)
    #define UARTT_SS3_HSIOM_SEL_GPIO (UARTT_spi_ss3__0__HSIOM_GPIO)
    #define UARTT_SS3_HSIOM_SEL_I2C  (UARTT_spi_ss3__0__HSIOM_I2C)
    #define UARTT_SS3_HSIOM_SEL_SPI  (UARTT_spi_ss3__0__HSIOM_SPI)
#endif /* (UARTT_SS3_PIN) */

#if (UARTT_I2C_PINS)
    #define UARTT_SCL_HSIOM_REG  (*(reg32 *) UARTT_scl__0__HSIOM)
    #define UARTT_SCL_HSIOM_PTR  ( (reg32 *) UARTT_scl__0__HSIOM)
    
    #define UARTT_SCL_HSIOM_MASK     (UARTT_scl__0__HSIOM_MASK)
    #define UARTT_SCL_HSIOM_POS      (UARTT_scl__0__HSIOM_SHIFT)
    #define UARTT_SCL_HSIOM_SEL_GPIO (UARTT_sda__0__HSIOM_GPIO)
    #define UARTT_SCL_HSIOM_SEL_I2C  (UARTT_sda__0__HSIOM_I2C)
    
    #define UARTT_SDA_HSIOM_REG  (*(reg32 *) UARTT_sda__0__HSIOM)
    #define UARTT_SDA_HSIOM_PTR  ( (reg32 *) UARTT_sda__0__HSIOM)
    
    #define UARTT_SDA_HSIOM_MASK     (UARTT_sda__0__HSIOM_MASK)
    #define UARTT_SDA_HSIOM_POS      (UARTT_sda__0__HSIOM_SHIFT)
    #define UARTT_SDA_HSIOM_SEL_GPIO (UARTT_sda__0__HSIOM_GPIO)
    #define UARTT_SDA_HSIOM_SEL_I2C  (UARTT_sda__0__HSIOM_I2C)
#endif /* (UARTT_I2C_PINS) */

#if (UARTT_SPI_SLAVE_PINS)
    #define UARTT_SCLK_S_HSIOM_REG   (*(reg32 *) UARTT_sclk_s__0__HSIOM)
    #define UARTT_SCLK_S_HSIOM_PTR   ( (reg32 *) UARTT_sclk_s__0__HSIOM)
    
    #define UARTT_SCLK_S_HSIOM_MASK      (UARTT_sclk_s__0__HSIOM_MASK)
    #define UARTT_SCLK_S_HSIOM_POS       (UARTT_sclk_s__0__HSIOM_SHIFT)
    #define UARTT_SCLK_S_HSIOM_SEL_GPIO  (UARTT_sclk_s__0__HSIOM_GPIO)
    #define UARTT_SCLK_S_HSIOM_SEL_SPI   (UARTT_sclk_s__0__HSIOM_SPI)
    
    #define UARTT_SS0_S_HSIOM_REG    (*(reg32 *) UARTT_ss0_s__0__HSIOM)
    #define UARTT_SS0_S_HSIOM_PTR    ( (reg32 *) UARTT_ss0_s__0__HSIOM)
    
    #define UARTT_SS0_S_HSIOM_MASK       (UARTT_ss0_s__0__HSIOM_MASK)
    #define UARTT_SS0_S_HSIOM_POS        (UARTT_ss0_s__0__HSIOM_SHIFT)
    #define UARTT_SS0_S_HSIOM_SEL_GPIO   (UARTT_ss0_s__0__HSIOM_GPIO)  
    #define UARTT_SS0_S_HSIOM_SEL_SPI    (UARTT_ss0_s__0__HSIOM_SPI)
#endif /* (UARTT_SPI_SLAVE_PINS) */

#if (UARTT_SPI_SLAVE_MOSI_PIN)
    #define UARTT_MOSI_S_HSIOM_REG   (*(reg32 *) UARTT_mosi_s__0__HSIOM)
    #define UARTT_MOSI_S_HSIOM_PTR   ( (reg32 *) UARTT_mosi_s__0__HSIOM)
    
    #define UARTT_MOSI_S_HSIOM_MASK      (UARTT_mosi_s__0__HSIOM_MASK)
    #define UARTT_MOSI_S_HSIOM_POS       (UARTT_mosi_s__0__HSIOM_SHIFT)
    #define UARTT_MOSI_S_HSIOM_SEL_GPIO  (UARTT_mosi_s__0__HSIOM_GPIO)
    #define UARTT_MOSI_S_HSIOM_SEL_SPI   (UARTT_mosi_s__0__HSIOM_SPI)
#endif /* (UARTT_SPI_SLAVE_MOSI_PIN) */

#if (UARTT_SPI_SLAVE_MISO_PIN)
    #define UARTT_MISO_S_HSIOM_REG   (*(reg32 *) UARTT_miso_s__0__HSIOM)
    #define UARTT_MISO_S_HSIOM_PTR   ( (reg32 *) UARTT_miso_s__0__HSIOM)
    
    #define UARTT_MISO_S_HSIOM_MASK      (UARTT_miso_s__0__HSIOM_MASK)
    #define UARTT_MISO_S_HSIOM_POS       (UARTT_miso_s__0__HSIOM_SHIFT)
    #define UARTT_MISO_S_HSIOM_SEL_GPIO  (UARTT_miso_s__0__HSIOM_GPIO)
    #define UARTT_MISO_S_HSIOM_SEL_SPI   (UARTT_miso_s__0__HSIOM_SPI)
#endif /* (UARTT_SPI_SLAVE_MISO_PIN) */

#if (UARTT_SPI_MASTER_MISO_PIN)
    #define UARTT_MISO_M_HSIOM_REG   (*(reg32 *) UARTT_miso_m__0__HSIOM)
    #define UARTT_MISO_M_HSIOM_PTR   ( (reg32 *) UARTT_miso_m__0__HSIOM)
    
    #define UARTT_MISO_M_HSIOM_MASK      (UARTT_miso_m__0__HSIOM_MASK)
    #define UARTT_MISO_M_HSIOM_POS       (UARTT_miso_m__0__HSIOM_SHIFT)
    #define UARTT_MISO_M_HSIOM_SEL_GPIO  (UARTT_miso_m__0__HSIOM_GPIO)
    #define UARTT_MISO_M_HSIOM_SEL_SPI   (UARTT_miso_m__0__HSIOM_SPI)
#endif /* (UARTT_SPI_MASTER_MISO_PIN) */

#if (UARTT_SPI_MASTER_MOSI_PIN)
    #define UARTT_MOSI_M_HSIOM_REG   (*(reg32 *) UARTT_mosi_m__0__HSIOM)
    #define UARTT_MOSI_M_HSIOM_PTR   ( (reg32 *) UARTT_mosi_m__0__HSIOM)
    
    #define UARTT_MOSI_M_HSIOM_MASK      (UARTT_mosi_m__0__HSIOM_MASK)
    #define UARTT_MOSI_M_HSIOM_POS       (UARTT_mosi_m__0__HSIOM_SHIFT)
    #define UARTT_MOSI_M_HSIOM_SEL_GPIO  (UARTT_mosi_m__0__HSIOM_GPIO)
    #define UARTT_MOSI_M_HSIOM_SEL_SPI   (UARTT_mosi_m__0__HSIOM_SPI)
#endif /* (UARTT_SPI_MASTER_MOSI_PIN) */

#if (UARTT_SPI_MASTER_SCLK_PIN)
    #define UARTT_SCLK_M_HSIOM_REG   (*(reg32 *) UARTT_sclk_m__0__HSIOM)
    #define UARTT_SCLK_M_HSIOM_PTR   ( (reg32 *) UARTT_sclk_m__0__HSIOM)
    
    #define UARTT_SCLK_M_HSIOM_MASK      (UARTT_sclk_m__0__HSIOM_MASK)
    #define UARTT_SCLK_M_HSIOM_POS       (UARTT_sclk_m__0__HSIOM_SHIFT)
    #define UARTT_SCLK_M_HSIOM_SEL_GPIO  (UARTT_sclk_m__0__HSIOM_GPIO)
    #define UARTT_SCLK_M_HSIOM_SEL_SPI   (UARTT_sclk_m__0__HSIOM_SPI)
#endif /* (UARTT_SPI_MASTER_SCLK_PIN) */

#if (UARTT_SPI_MASTER_SS0_PIN)
    #define UARTT_SS0_M_HSIOM_REG    (*(reg32 *) UARTT_ss0_m__0__HSIOM)
    #define UARTT_SS0_M_HSIOM_PTR    ( (reg32 *) UARTT_ss0_m__0__HSIOM)
    
    #define UARTT_SS0_M_HSIOM_MASK       (UARTT_ss0_m__0__HSIOM_MASK)
    #define UARTT_SS0_M_HSIOM_POS        (UARTT_ss0_m__0__HSIOM_SHIFT)
    #define UARTT_SS0_M_HSIOM_SEL_GPIO   (UARTT_ss0_m__0__HSIOM_GPIO)
    #define UARTT_SS0_M_HSIOM_SEL_SPI    (UARTT_ss0_m__0__HSIOM_SPI)
#endif /* (UARTT_SPI_MASTER_SS0_PIN) */

#if (UARTT_SPI_MASTER_SS1_PIN)
    #define UARTT_SS1_M_HSIOM_REG    (*(reg32 *) UARTT_ss1_m__0__HSIOM)
    #define UARTT_SS1_M_HSIOM_PTR    ( (reg32 *) UARTT_ss1_m__0__HSIOM)
    
    #define UARTT_SS1_M_HSIOM_MASK       (UARTT_ss1_m__0__HSIOM_MASK)
    #define UARTT_SS1_M_HSIOM_POS        (UARTT_ss1_m__0__HSIOM_SHIFT)
    #define UARTT_SS1_M_HSIOM_SEL_GPIO   (UARTT_ss1_m__0__HSIOM_GPIO)
    #define UARTT_SS1_M_HSIOM_SEL_SPI    (UARTT_ss1_m__0__HSIOM_SPI)
#endif /* (UARTT_SPI_MASTER_SS1_PIN) */

#if (UARTT_SPI_MASTER_SS2_PIN)
    #define UARTT_SS2_M_HSIOM_REG    (*(reg32 *) UARTT_ss2_m__0__HSIOM)
    #define UARTT_SS2_M_HSIOM_PTR    ( (reg32 *) UARTT_ss2_m__0__HSIOM)
    
    #define UARTT_SS2_M_HSIOM_MASK       (UARTT_ss2_m__0__HSIOM_MASK)
    #define UARTT_SS2_M_HSIOM_POS        (UARTT_ss2_m__0__HSIOM_SHIFT)
    #define UARTT_SS2_M_HSIOM_SEL_GPIO   (UARTT_ss2_m__0__HSIOM_GPIO)
    #define UARTT_SS2_M_HSIOM_SEL_SPI    (UARTT_ss2_m__0__HSIOM_SPI)
#endif /* (UARTT_SPI_MASTER_SS2_PIN) */

#if (UARTT_SPI_MASTER_SS3_PIN)
    #define UARTT_SS3_M_HSIOM_REG    (*(reg32 *) UARTT_ss3_m__0__HSIOM)
    #define UARTT_SS3_M_HSIOM_PTR    ( (reg32 *) UARTT_ss3_m__0__HSIOM)
    
    #define UARTT_SS3_M_HSIOM_MASK      (UARTT_ss3_m__0__HSIOM_MASK)
    #define UARTT_SS3_M_HSIOM_POS       (UARTT_ss3_m__0__HSIOM_SHIFT)
    #define UARTT_SS3_M_HSIOM_SEL_GPIO  (UARTT_ss3_m__0__HSIOM_GPIO)
    #define UARTT_SS3_M_HSIOM_SEL_SPI   (UARTT_ss3_m__0__HSIOM_SPI)
#endif /* (UARTT_SPI_MASTER_SS3_PIN) */

#if (UARTT_UART_RX_PIN)
    #define UARTT_RX_HSIOM_REG   (*(reg32 *) UARTT_rx__0__HSIOM)
    #define UARTT_RX_HSIOM_PTR   ( (reg32 *) UARTT_rx__0__HSIOM)
    
    #define UARTT_RX_HSIOM_MASK      (UARTT_rx__0__HSIOM_MASK)
    #define UARTT_RX_HSIOM_POS       (UARTT_rx__0__HSIOM_SHIFT)
    #define UARTT_RX_HSIOM_SEL_GPIO  (UARTT_rx__0__HSIOM_GPIO)
    #define UARTT_RX_HSIOM_SEL_UART  (UARTT_rx__0__HSIOM_UART)
#endif /* (UARTT_UART_RX_PIN) */

#if (UARTT_UART_RX_WAKE_PIN)
    #define UARTT_RX_WAKE_HSIOM_REG   (*(reg32 *) UARTT_rx_wake__0__HSIOM)
    #define UARTT_RX_WAKE_HSIOM_PTR   ( (reg32 *) UARTT_rx_wake__0__HSIOM)
    
    #define UARTT_RX_WAKE_HSIOM_MASK      (UARTT_rx_wake__0__HSIOM_MASK)
    #define UARTT_RX_WAKE_HSIOM_POS       (UARTT_rx_wake__0__HSIOM_SHIFT)
    #define UARTT_RX_WAKE_HSIOM_SEL_GPIO  (UARTT_rx_wake__0__HSIOM_GPIO)
    #define UARTT_RX_WAKE_HSIOM_SEL_UART  (UARTT_rx_wake__0__HSIOM_UART)
#endif /* (UARTT_UART_WAKE_RX_PIN) */

#if (UARTT_UART_CTS_PIN)
    #define UARTT_CTS_HSIOM_REG   (*(reg32 *) UARTT_cts__0__HSIOM)
    #define UARTT_CTS_HSIOM_PTR   ( (reg32 *) UARTT_cts__0__HSIOM)
    
    #define UARTT_CTS_HSIOM_MASK      (UARTT_cts__0__HSIOM_MASK)
    #define UARTT_CTS_HSIOM_POS       (UARTT_cts__0__HSIOM_SHIFT)
    #define UARTT_CTS_HSIOM_SEL_GPIO  (UARTT_cts__0__HSIOM_GPIO)
    #define UARTT_CTS_HSIOM_SEL_UART  (UARTT_cts__0__HSIOM_UART)
#endif /* (UARTT_UART_CTS_PIN) */

#if (UARTT_UART_TX_PIN)
    #define UARTT_TX_HSIOM_REG   (*(reg32 *) UARTT_tx__0__HSIOM)
    #define UARTT_TX_HSIOM_PTR   ( (reg32 *) UARTT_tx__0__HSIOM)
    
    #define UARTT_TX_HSIOM_MASK      (UARTT_tx__0__HSIOM_MASK)
    #define UARTT_TX_HSIOM_POS       (UARTT_tx__0__HSIOM_SHIFT)
    #define UARTT_TX_HSIOM_SEL_GPIO  (UARTT_tx__0__HSIOM_GPIO)
    #define UARTT_TX_HSIOM_SEL_UART  (UARTT_tx__0__HSIOM_UART)
#endif /* (UARTT_UART_TX_PIN) */

#if (UARTT_UART_RX_TX_PIN)
    #define UARTT_RX_TX_HSIOM_REG   (*(reg32 *) UARTT_rx_tx__0__HSIOM)
    #define UARTT_RX_TX_HSIOM_PTR   ( (reg32 *) UARTT_rx_tx__0__HSIOM)
    
    #define UARTT_RX_TX_HSIOM_MASK      (UARTT_rx_tx__0__HSIOM_MASK)
    #define UARTT_RX_TX_HSIOM_POS       (UARTT_rx_tx__0__HSIOM_SHIFT)
    #define UARTT_RX_TX_HSIOM_SEL_GPIO  (UARTT_rx_tx__0__HSIOM_GPIO)
    #define UARTT_RX_TX_HSIOM_SEL_UART  (UARTT_rx_tx__0__HSIOM_UART)
#endif /* (UARTT_UART_RX_TX_PIN) */

#if (UARTT_UART_RTS_PIN)
    #define UARTT_RTS_HSIOM_REG      (*(reg32 *) UARTT_rts__0__HSIOM)
    #define UARTT_RTS_HSIOM_PTR      ( (reg32 *) UARTT_rts__0__HSIOM)
    
    #define UARTT_RTS_HSIOM_MASK     (UARTT_rts__0__HSIOM_MASK)
    #define UARTT_RTS_HSIOM_POS      (UARTT_rts__0__HSIOM_SHIFT)    
    #define UARTT_RTS_HSIOM_SEL_GPIO (UARTT_rts__0__HSIOM_GPIO)
    #define UARTT_RTS_HSIOM_SEL_UART (UARTT_rts__0__HSIOM_UART)    
#endif /* (UARTT_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* HSIOM switch values. */ 
#define UARTT_HSIOM_DEF_SEL      (0x00u)
#define UARTT_HSIOM_GPIO_SEL     (0x00u)
/* The HSIOM values provided below are valid only for UARTT_CY_SCBIP_V0 
* and UARTT_CY_SCBIP_V1. It is not recommended to use them for 
* UARTT_CY_SCBIP_V2. Use pin name specific HSIOM constants provided 
* above instead for any SCB IP block version.
*/
#define UARTT_HSIOM_UART_SEL     (0x09u)
#define UARTT_HSIOM_I2C_SEL      (0x0Eu)
#define UARTT_HSIOM_SPI_SEL      (0x0Fu)

/* Pins settings index. */
#define UARTT_RX_WAKE_SCL_MOSI_PIN_INDEX   (0u)
#define UARTT_RX_SCL_MOSI_PIN_INDEX       (0u)
#define UARTT_TX_SDA_MISO_PIN_INDEX       (1u)
#define UARTT_SCLK_PIN_INDEX       (2u)
#define UARTT_SS0_PIN_INDEX       (3u)
#define UARTT_SS1_PIN_INDEX                  (4u)
#define UARTT_SS2_PIN_INDEX                  (5u)
#define UARTT_SS3_PIN_INDEX                  (6u)

/* Pins settings mask. */
#define UARTT_RX_WAKE_SCL_MOSI_PIN_MASK ((uint32) 0x01u << UARTT_RX_WAKE_SCL_MOSI_PIN_INDEX)
#define UARTT_RX_SCL_MOSI_PIN_MASK     ((uint32) 0x01u << UARTT_RX_SCL_MOSI_PIN_INDEX)
#define UARTT_TX_SDA_MISO_PIN_MASK     ((uint32) 0x01u << UARTT_TX_SDA_MISO_PIN_INDEX)
#define UARTT_SCLK_PIN_MASK     ((uint32) 0x01u << UARTT_SCLK_PIN_INDEX)
#define UARTT_SS0_PIN_MASK     ((uint32) 0x01u << UARTT_SS0_PIN_INDEX)
#define UARTT_SS1_PIN_MASK                ((uint32) 0x01u << UARTT_SS1_PIN_INDEX)
#define UARTT_SS2_PIN_MASK                ((uint32) 0x01u << UARTT_SS2_PIN_INDEX)
#define UARTT_SS3_PIN_MASK                ((uint32) 0x01u << UARTT_SS3_PIN_INDEX)

/* Pin interrupt constants. */
#define UARTT_INTCFG_TYPE_MASK           (0x03u)
#define UARTT_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants. */
#define UARTT_PIN_DM_ALG_HIZ  (0u)
#define UARTT_PIN_DM_DIG_HIZ  (1u)
#define UARTT_PIN_DM_OD_LO    (4u)
#define UARTT_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define UARTT_DM_MASK    (0x7u)
#define UARTT_DM_SIZE    (3u)
#define UARTT_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) UARTT_DM_MASK << (UARTT_DM_SIZE * (pos)))) >> \
                                                              (UARTT_DM_SIZE * (pos)) )

#if (UARTT_TX_SDA_MISO_PIN)
    #define UARTT_CHECK_TX_SDA_MISO_PIN_USED \
                (UARTT_PIN_DM_ALG_HIZ != \
                    UARTT_GET_P4_PIN_DM(UARTT_uart_tx_i2c_sda_spi_miso_PC, \
                                                   UARTT_uart_tx_i2c_sda_spi_miso_SHIFT))
#endif /* (UARTT_TX_SDA_MISO_PIN) */

#if (UARTT_SS0_PIN)
    #define UARTT_CHECK_SS0_PIN_USED \
                (UARTT_PIN_DM_ALG_HIZ != \
                    UARTT_GET_P4_PIN_DM(UARTT_spi_ss0_PC, \
                                                   UARTT_spi_ss0_SHIFT))
#endif /* (UARTT_SS0_PIN) */

/* Set bits-mask in register */
#define UARTT_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define UARTT_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define UARTT_SET_HSIOM_SEL(reg, mask, pos, sel) UARTT_SET_REGISTER_BITS(reg, mask, pos, sel)
#define UARTT_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        UARTT_SET_REGISTER_BITS(reg, mask, pos, intType)
#define UARTT_SET_INP_DIS(reg, mask, val) UARTT_SET_REGISTER_BIT(reg, mask, val)

/* UARTT_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  UARTT_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (UARTT_CY_SCBIP_V0)
#if (UARTT_I2C_PINS)
    #define UARTT_SET_I2C_SCL_DR(val) UARTT_scl_Write(val)

    #define UARTT_SET_I2C_SCL_HSIOM_SEL(sel) \
                          UARTT_SET_HSIOM_SEL(UARTT_SCL_HSIOM_REG,  \
                                                         UARTT_SCL_HSIOM_MASK, \
                                                         UARTT_SCL_HSIOM_POS,  \
                                                         (sel))
    #define UARTT_WAIT_SCL_SET_HIGH  (0u == UARTT_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (UARTT_RX_WAKE_SCL_MOSI_PIN)
    #define UARTT_SET_I2C_SCL_DR(val) \
                            UARTT_uart_rx_wake_i2c_scl_spi_mosi_Write(val)

    #define UARTT_SET_I2C_SCL_HSIOM_SEL(sel) \
                    UARTT_SET_HSIOM_SEL(UARTT_RX_WAKE_SCL_MOSI_HSIOM_REG,  \
                                                   UARTT_RX_WAKE_SCL_MOSI_HSIOM_MASK, \
                                                   UARTT_RX_WAKE_SCL_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define UARTT_WAIT_SCL_SET_HIGH  (0u == UARTT_uart_rx_wake_i2c_scl_spi_mosi_Read())

#elif (UARTT_RX_SCL_MOSI_PIN)
    #define UARTT_SET_I2C_SCL_DR(val) \
                            UARTT_uart_rx_i2c_scl_spi_mosi_Write(val)


    #define UARTT_SET_I2C_SCL_HSIOM_SEL(sel) \
                            UARTT_SET_HSIOM_SEL(UARTT_RX_SCL_MOSI_HSIOM_REG,  \
                                                           UARTT_RX_SCL_MOSI_HSIOM_MASK, \
                                                           UARTT_RX_SCL_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define UARTT_WAIT_SCL_SET_HIGH  (0u == UARTT_uart_rx_i2c_scl_spi_mosi_Read())

#else
    #define UARTT_SET_I2C_SCL_DR(val)        do{ /* Does nothing */ }while(0)
    #define UARTT_SET_I2C_SCL_HSIOM_SEL(sel) do{ /* Does nothing */ }while(0)

    #define UARTT_WAIT_SCL_SET_HIGH  (0u)
#endif /* (UARTT_I2C_PINS) */

/* SCB I2C: sda signal */
#if (UARTT_I2C_PINS)
    #define UARTT_WAIT_SDA_SET_HIGH  (0u == UARTT_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (UARTT_TX_SDA_MISO_PIN)
    #define UARTT_WAIT_SDA_SET_HIGH  (0u == UARTT_uart_tx_i2c_sda_spi_miso_Read())
#else
    #define UARTT_WAIT_SDA_SET_HIGH  (0u)
#endif /* (UARTT_MOSI_SCL_RX_PIN) */
#endif /* (UARTT_CY_SCBIP_V0) */

/* Clear UART wakeup source */
#if (UARTT_RX_SCL_MOSI_PIN)
    #define UARTT_CLEAR_UART_RX_WAKE_INTR        do{ /* Does nothing */ }while(0)
    
#elif (UARTT_RX_WAKE_SCL_MOSI_PIN)
    #define UARTT_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) UARTT_uart_rx_wake_i2c_scl_spi_mosi_ClearInterrupt(); \
            }while(0)

#elif(UARTT_UART_RX_WAKE_PIN)
    #define UARTT_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) UARTT_rx_wake_ClearInterrupt(); \
            }while(0)
#else
#endif /* (UARTT_RX_SCL_MOSI_PIN) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define UARTT_REMOVE_MOSI_SCL_RX_WAKE_PIN    UARTT_REMOVE_RX_WAKE_SCL_MOSI_PIN
#define UARTT_REMOVE_MOSI_SCL_RX_PIN         UARTT_REMOVE_RX_SCL_MOSI_PIN
#define UARTT_REMOVE_MISO_SDA_TX_PIN         UARTT_REMOVE_TX_SDA_MISO_PIN
#ifndef UARTT_REMOVE_SCLK_PIN
#define UARTT_REMOVE_SCLK_PIN                UARTT_REMOVE_SCLK_PIN
#endif /* UARTT_REMOVE_SCLK_PIN */
#ifndef UARTT_REMOVE_SS0_PIN
#define UARTT_REMOVE_SS0_PIN                 UARTT_REMOVE_SS0_PIN
#endif /* UARTT_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define UARTT_MOSI_SCL_RX_WAKE_PIN   UARTT_RX_WAKE_SCL_MOSI_PIN
#define UARTT_MOSI_SCL_RX_PIN        UARTT_RX_SCL_MOSI_PIN
#define UARTT_MISO_SDA_TX_PIN        UARTT_TX_SDA_MISO_PIN
#ifndef UARTT_SCLK_PIN
#define UARTT_SCLK_PIN               UARTT_SCLK_PIN
#endif /* UARTT_SCLK_PIN */
#ifndef UARTT_SS0_PIN
#define UARTT_SS0_PIN                UARTT_SS0_PIN
#endif /* UARTT_SS0_PIN */

#if (UARTT_MOSI_SCL_RX_WAKE_PIN)
    #define UARTT_MOSI_SCL_RX_WAKE_HSIOM_REG     UARTT_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define UARTT_MOSI_SCL_RX_WAKE_HSIOM_PTR     UARTT_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define UARTT_MOSI_SCL_RX_WAKE_HSIOM_MASK    UARTT_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define UARTT_MOSI_SCL_RX_WAKE_HSIOM_POS     UARTT_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define UARTT_MOSI_SCL_RX_WAKE_INTCFG_REG    UARTT_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define UARTT_MOSI_SCL_RX_WAKE_INTCFG_PTR    UARTT_RX_WAKE_SCL_MOSI_HSIOM_REG

    #define UARTT_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   UARTT_RX_WAKE_SCL_MOSI_HSIOM_REG
    #define UARTT_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  UARTT_RX_WAKE_SCL_MOSI_HSIOM_REG
#endif /* (UARTT_RX_WAKE_SCL_MOSI_PIN) */

#if (UARTT_MOSI_SCL_RX_PIN)
    #define UARTT_MOSI_SCL_RX_HSIOM_REG      UARTT_RX_SCL_MOSI_HSIOM_REG
    #define UARTT_MOSI_SCL_RX_HSIOM_PTR      UARTT_RX_SCL_MOSI_HSIOM_PTR
    #define UARTT_MOSI_SCL_RX_HSIOM_MASK     UARTT_RX_SCL_MOSI_HSIOM_MASK
    #define UARTT_MOSI_SCL_RX_HSIOM_POS      UARTT_RX_SCL_MOSI_HSIOM_POS
#endif /* (UARTT_MOSI_SCL_RX_PIN) */

#if (UARTT_MISO_SDA_TX_PIN)
    #define UARTT_MISO_SDA_TX_HSIOM_REG      UARTT_TX_SDA_MISO_HSIOM_REG
    #define UARTT_MISO_SDA_TX_HSIOM_PTR      UARTT_TX_SDA_MISO_HSIOM_REG
    #define UARTT_MISO_SDA_TX_HSIOM_MASK     UARTT_TX_SDA_MISO_HSIOM_REG
    #define UARTT_MISO_SDA_TX_HSIOM_POS      UARTT_TX_SDA_MISO_HSIOM_REG
#endif /* (UARTT_MISO_SDA_TX_PIN_PIN) */

#if (UARTT_SCLK_PIN)
    #ifndef UARTT_SCLK_HSIOM_REG
    #define UARTT_SCLK_HSIOM_REG     UARTT_SCLK_HSIOM_REG
    #define UARTT_SCLK_HSIOM_PTR     UARTT_SCLK_HSIOM_PTR
    #define UARTT_SCLK_HSIOM_MASK    UARTT_SCLK_HSIOM_MASK
    #define UARTT_SCLK_HSIOM_POS     UARTT_SCLK_HSIOM_POS
    #endif /* UARTT_SCLK_HSIOM_REG */
#endif /* (UARTT_SCLK_PIN) */

#if (UARTT_SS0_PIN)
    #ifndef UARTT_SS0_HSIOM_REG
    #define UARTT_SS0_HSIOM_REG      UARTT_SS0_HSIOM_REG
    #define UARTT_SS0_HSIOM_PTR      UARTT_SS0_HSIOM_PTR
    #define UARTT_SS0_HSIOM_MASK     UARTT_SS0_HSIOM_MASK
    #define UARTT_SS0_HSIOM_POS      UARTT_SS0_HSIOM_POS
    #endif /* UARTT_SS0_HSIOM_REG */
#endif /* (UARTT_SS0_PIN) */

#define UARTT_MOSI_SCL_RX_WAKE_PIN_INDEX UARTT_RX_WAKE_SCL_MOSI_PIN_INDEX
#define UARTT_MOSI_SCL_RX_PIN_INDEX      UARTT_RX_SCL_MOSI_PIN_INDEX
#define UARTT_MISO_SDA_TX_PIN_INDEX      UARTT_TX_SDA_MISO_PIN_INDEX
#ifndef UARTT_SCLK_PIN_INDEX
#define UARTT_SCLK_PIN_INDEX             UARTT_SCLK_PIN_INDEX
#endif /* UARTT_SCLK_PIN_INDEX */
#ifndef UARTT_SS0_PIN_INDEX
#define UARTT_SS0_PIN_INDEX              UARTT_SS0_PIN_INDEX
#endif /* UARTT_SS0_PIN_INDEX */

#define UARTT_MOSI_SCL_RX_WAKE_PIN_MASK UARTT_RX_WAKE_SCL_MOSI_PIN_MASK
#define UARTT_MOSI_SCL_RX_PIN_MASK      UARTT_RX_SCL_MOSI_PIN_MASK
#define UARTT_MISO_SDA_TX_PIN_MASK      UARTT_TX_SDA_MISO_PIN_MASK
#ifndef UARTT_SCLK_PIN_MASK
#define UARTT_SCLK_PIN_MASK             UARTT_SCLK_PIN_MASK
#endif /* UARTT_SCLK_PIN_MASK */
#ifndef UARTT_SS0_PIN_MASK
#define UARTT_SS0_PIN_MASK              UARTT_SS0_PIN_MASK
#endif /* UARTT_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_UARTT_H) */


/* [] END OF FILE */
