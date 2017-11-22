#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar_trm.inc

/* UART_isr */
UART_isr__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
UART_isr__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
UART_isr__INTC_MASK EQU 0x800
UART_isr__INTC_NUMBER EQU 11
UART_isr__INTC_PRIOR_MASK EQU 0xC0000000
UART_isr__INTC_PRIOR_NUM EQU 3
UART_isr__INTC_PRIOR_REG EQU CYREG_CM0_IPR2
UART_isr__INTC_SET_EN_REG EQU CYREG_CM0_ISER
UART_isr__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

/* UART_rx */
UART_rx__0__DM__MASK EQU 0x07
UART_rx__0__DM__SHIFT EQU 0
UART_rx__0__DR EQU CYREG_PRT3_DR
UART_rx__0__HSIOM EQU CYREG_HSIOM_PORT_SEL3
UART_rx__0__HSIOM_GPIO EQU 0
UART_rx__0__HSIOM_I2C EQU 14
UART_rx__0__HSIOM_I2C_SCL EQU 14
UART_rx__0__HSIOM_MASK EQU 0x0000000F
UART_rx__0__HSIOM_SHIFT EQU 0
UART_rx__0__HSIOM_SPI EQU 15
UART_rx__0__HSIOM_SPI_MOSI EQU 15
UART_rx__0__HSIOM_UART EQU 9
UART_rx__0__HSIOM_UART_RX EQU 9
UART_rx__0__INTCFG EQU CYREG_PRT3_INTCFG
UART_rx__0__INTSTAT EQU CYREG_PRT3_INTSTAT
UART_rx__0__MASK EQU 0x01
UART_rx__0__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
UART_rx__0__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
UART_rx__0__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
UART_rx__0__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
UART_rx__0__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
UART_rx__0__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
UART_rx__0__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
UART_rx__0__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
UART_rx__0__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
UART_rx__0__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
UART_rx__0__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
UART_rx__0__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
UART_rx__0__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
UART_rx__0__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
UART_rx__0__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
UART_rx__0__PC EQU CYREG_PRT3_PC
UART_rx__0__PC2 EQU CYREG_PRT3_PC2
UART_rx__0__PORT EQU 3
UART_rx__0__PS EQU CYREG_PRT3_PS
UART_rx__0__SHIFT EQU 0
UART_rx__DR EQU CYREG_PRT3_DR
UART_rx__INTCFG EQU CYREG_PRT3_INTCFG
UART_rx__INTSTAT EQU CYREG_PRT3_INTSTAT
UART_rx__MASK EQU 0x01
UART_rx__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
UART_rx__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
UART_rx__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
UART_rx__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
UART_rx__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
UART_rx__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
UART_rx__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
UART_rx__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
UART_rx__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
UART_rx__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
UART_rx__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
UART_rx__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
UART_rx__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
UART_rx__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
UART_rx__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
UART_rx__PC EQU CYREG_PRT3_PC
UART_rx__PC2 EQU CYREG_PRT3_PC2
UART_rx__PORT EQU 3
UART_rx__PS EQU CYREG_PRT3_PS
UART_rx__SHIFT EQU 0

/* UART_SCB */
UART_SCB__BIST_CONTROL EQU CYREG_SCB1_BIST_CONTROL
UART_SCB__BIST_DATA EQU CYREG_SCB1_BIST_DATA
UART_SCB__CTRL EQU CYREG_SCB1_CTRL
UART_SCB__EZ_DATA00 EQU CYREG_SCB1_EZ_DATA00
UART_SCB__EZ_DATA01 EQU CYREG_SCB1_EZ_DATA01
UART_SCB__EZ_DATA02 EQU CYREG_SCB1_EZ_DATA02
UART_SCB__EZ_DATA03 EQU CYREG_SCB1_EZ_DATA03
UART_SCB__EZ_DATA04 EQU CYREG_SCB1_EZ_DATA04
UART_SCB__EZ_DATA05 EQU CYREG_SCB1_EZ_DATA05
UART_SCB__EZ_DATA06 EQU CYREG_SCB1_EZ_DATA06
UART_SCB__EZ_DATA07 EQU CYREG_SCB1_EZ_DATA07
UART_SCB__EZ_DATA08 EQU CYREG_SCB1_EZ_DATA08
UART_SCB__EZ_DATA09 EQU CYREG_SCB1_EZ_DATA09
UART_SCB__EZ_DATA10 EQU CYREG_SCB1_EZ_DATA10
UART_SCB__EZ_DATA11 EQU CYREG_SCB1_EZ_DATA11
UART_SCB__EZ_DATA12 EQU CYREG_SCB1_EZ_DATA12
UART_SCB__EZ_DATA13 EQU CYREG_SCB1_EZ_DATA13
UART_SCB__EZ_DATA14 EQU CYREG_SCB1_EZ_DATA14
UART_SCB__EZ_DATA15 EQU CYREG_SCB1_EZ_DATA15
UART_SCB__EZ_DATA16 EQU CYREG_SCB1_EZ_DATA16
UART_SCB__EZ_DATA17 EQU CYREG_SCB1_EZ_DATA17
UART_SCB__EZ_DATA18 EQU CYREG_SCB1_EZ_DATA18
UART_SCB__EZ_DATA19 EQU CYREG_SCB1_EZ_DATA19
UART_SCB__EZ_DATA20 EQU CYREG_SCB1_EZ_DATA20
UART_SCB__EZ_DATA21 EQU CYREG_SCB1_EZ_DATA21
UART_SCB__EZ_DATA22 EQU CYREG_SCB1_EZ_DATA22
UART_SCB__EZ_DATA23 EQU CYREG_SCB1_EZ_DATA23
UART_SCB__EZ_DATA24 EQU CYREG_SCB1_EZ_DATA24
UART_SCB__EZ_DATA25 EQU CYREG_SCB1_EZ_DATA25
UART_SCB__EZ_DATA26 EQU CYREG_SCB1_EZ_DATA26
UART_SCB__EZ_DATA27 EQU CYREG_SCB1_EZ_DATA27
UART_SCB__EZ_DATA28 EQU CYREG_SCB1_EZ_DATA28
UART_SCB__EZ_DATA29 EQU CYREG_SCB1_EZ_DATA29
UART_SCB__EZ_DATA30 EQU CYREG_SCB1_EZ_DATA30
UART_SCB__EZ_DATA31 EQU CYREG_SCB1_EZ_DATA31
UART_SCB__I2C_CFG EQU CYREG_SCB1_I2C_CFG
UART_SCB__I2C_CTRL EQU CYREG_SCB1_I2C_CTRL
UART_SCB__I2C_M_CMD EQU CYREG_SCB1_I2C_M_CMD
UART_SCB__I2C_S_CMD EQU CYREG_SCB1_I2C_S_CMD
UART_SCB__I2C_STATUS EQU CYREG_SCB1_I2C_STATUS
UART_SCB__INTR_CAUSE EQU CYREG_SCB1_INTR_CAUSE
UART_SCB__INTR_I2C_EC EQU CYREG_SCB1_INTR_I2C_EC
UART_SCB__INTR_I2C_EC_MASK EQU CYREG_SCB1_INTR_I2C_EC_MASK
UART_SCB__INTR_I2C_EC_MASKED EQU CYREG_SCB1_INTR_I2C_EC_MASKED
UART_SCB__INTR_M EQU CYREG_SCB1_INTR_M
UART_SCB__INTR_M_MASK EQU CYREG_SCB1_INTR_M_MASK
UART_SCB__INTR_M_MASKED EQU CYREG_SCB1_INTR_M_MASKED
UART_SCB__INTR_M_SET EQU CYREG_SCB1_INTR_M_SET
UART_SCB__INTR_RX EQU CYREG_SCB1_INTR_RX
UART_SCB__INTR_RX_MASK EQU CYREG_SCB1_INTR_RX_MASK
UART_SCB__INTR_RX_MASKED EQU CYREG_SCB1_INTR_RX_MASKED
UART_SCB__INTR_RX_SET EQU CYREG_SCB1_INTR_RX_SET
UART_SCB__INTR_S EQU CYREG_SCB1_INTR_S
UART_SCB__INTR_S_MASK EQU CYREG_SCB1_INTR_S_MASK
UART_SCB__INTR_S_MASKED EQU CYREG_SCB1_INTR_S_MASKED
UART_SCB__INTR_S_SET EQU CYREG_SCB1_INTR_S_SET
UART_SCB__INTR_SPI_EC EQU CYREG_SCB1_INTR_SPI_EC
UART_SCB__INTR_SPI_EC_MASK EQU CYREG_SCB1_INTR_SPI_EC_MASK
UART_SCB__INTR_SPI_EC_MASKED EQU CYREG_SCB1_INTR_SPI_EC_MASKED
UART_SCB__INTR_TX EQU CYREG_SCB1_INTR_TX
UART_SCB__INTR_TX_MASK EQU CYREG_SCB1_INTR_TX_MASK
UART_SCB__INTR_TX_MASKED EQU CYREG_SCB1_INTR_TX_MASKED
UART_SCB__INTR_TX_SET EQU CYREG_SCB1_INTR_TX_SET
UART_SCB__RX_CTRL EQU CYREG_SCB1_RX_CTRL
UART_SCB__RX_FIFO_CTRL EQU CYREG_SCB1_RX_FIFO_CTRL
UART_SCB__RX_FIFO_RD EQU CYREG_SCB1_RX_FIFO_RD
UART_SCB__RX_FIFO_RD_SILENT EQU CYREG_SCB1_RX_FIFO_RD_SILENT
UART_SCB__RX_FIFO_STATUS EQU CYREG_SCB1_RX_FIFO_STATUS
UART_SCB__RX_MATCH EQU CYREG_SCB1_RX_MATCH
UART_SCB__SPI_CTRL EQU CYREG_SCB1_SPI_CTRL
UART_SCB__SPI_STATUS EQU CYREG_SCB1_SPI_STATUS
UART_SCB__SS0_POSISTION EQU 0
UART_SCB__SS1_POSISTION EQU 1
UART_SCB__SS2_POSISTION EQU 2
UART_SCB__SS3_POSISTION EQU 3
UART_SCB__STATUS EQU CYREG_SCB1_STATUS
UART_SCB__TX_CTRL EQU CYREG_SCB1_TX_CTRL
UART_SCB__TX_FIFO_CTRL EQU CYREG_SCB1_TX_FIFO_CTRL
UART_SCB__TX_FIFO_STATUS EQU CYREG_SCB1_TX_FIFO_STATUS
UART_SCB__TX_FIFO_WR EQU CYREG_SCB1_TX_FIFO_WR
UART_SCB__UART_CTRL EQU CYREG_SCB1_UART_CTRL
UART_SCB__UART_RX_CTRL EQU CYREG_SCB1_UART_RX_CTRL
UART_SCB__UART_RX_STATUS EQU CYREG_SCB1_UART_RX_STATUS
UART_SCB__UART_TX_CTRL EQU CYREG_SCB1_UART_TX_CTRL

/* UART_SCBCLK */
UART_SCBCLK__DIVIDER_MASK EQU 0x0000FFFF
UART_SCBCLK__ENABLE EQU CYREG_CLK_DIVIDER_A00
UART_SCBCLK__ENABLE_MASK EQU 0x80000000
UART_SCBCLK__MASK EQU 0x80000000
UART_SCBCLK__REGISTER EQU CYREG_CLK_DIVIDER_A00

/* UART_tx */
UART_tx__0__DM__MASK EQU 0x38
UART_tx__0__DM__SHIFT EQU 3
UART_tx__0__DR EQU CYREG_PRT3_DR
UART_tx__0__HSIOM EQU CYREG_HSIOM_PORT_SEL3
UART_tx__0__HSIOM_GPIO EQU 0
UART_tx__0__HSIOM_I2C EQU 14
UART_tx__0__HSIOM_I2C_SDA EQU 14
UART_tx__0__HSIOM_MASK EQU 0x000000F0
UART_tx__0__HSIOM_SHIFT EQU 4
UART_tx__0__HSIOM_SPI EQU 15
UART_tx__0__HSIOM_SPI_MISO EQU 15
UART_tx__0__HSIOM_UART EQU 9
UART_tx__0__HSIOM_UART_TX EQU 9
UART_tx__0__INTCFG EQU CYREG_PRT3_INTCFG
UART_tx__0__INTSTAT EQU CYREG_PRT3_INTSTAT
UART_tx__0__MASK EQU 0x02
UART_tx__0__OUT_SEL EQU CYREG_UDB_PA3_CFG10
UART_tx__0__OUT_SEL_SHIFT EQU 2
UART_tx__0__OUT_SEL_VAL EQU -1
UART_tx__0__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
UART_tx__0__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
UART_tx__0__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
UART_tx__0__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
UART_tx__0__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
UART_tx__0__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
UART_tx__0__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
UART_tx__0__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
UART_tx__0__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
UART_tx__0__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
UART_tx__0__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
UART_tx__0__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
UART_tx__0__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
UART_tx__0__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
UART_tx__0__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
UART_tx__0__PC EQU CYREG_PRT3_PC
UART_tx__0__PC2 EQU CYREG_PRT3_PC2
UART_tx__0__PORT EQU 3
UART_tx__0__PS EQU CYREG_PRT3_PS
UART_tx__0__SHIFT EQU 1
UART_tx__DR EQU CYREG_PRT3_DR
UART_tx__INTCFG EQU CYREG_PRT3_INTCFG
UART_tx__INTSTAT EQU CYREG_PRT3_INTSTAT
UART_tx__MASK EQU 0x02
UART_tx__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
UART_tx__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
UART_tx__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
UART_tx__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
UART_tx__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
UART_tx__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
UART_tx__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
UART_tx__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
UART_tx__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
UART_tx__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
UART_tx__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
UART_tx__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
UART_tx__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
UART_tx__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
UART_tx__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
UART_tx__PC EQU CYREG_PRT3_PC
UART_tx__PC2 EQU CYREG_PRT3_PC2
UART_tx__PORT EQU 3
UART_tx__PS EQU CYREG_PRT3_PS
UART_tx__SHIFT EQU 1

/* UARTT_isr */
UARTT_isr__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
UARTT_isr__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
UARTT_isr__INTC_MASK EQU 0x400
UARTT_isr__INTC_NUMBER EQU 10
UARTT_isr__INTC_PRIOR_MASK EQU 0xC00000
UARTT_isr__INTC_PRIOR_NUM EQU 3
UARTT_isr__INTC_PRIOR_REG EQU CYREG_CM0_IPR2
UARTT_isr__INTC_SET_EN_REG EQU CYREG_CM0_ISER
UARTT_isr__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

/* UARTT_rx */
UARTT_rx__0__DM__MASK EQU 0x07
UARTT_rx__0__DM__SHIFT EQU 0
UARTT_rx__0__DR EQU CYREG_PRT4_DR
UARTT_rx__0__HSIOM EQU CYREG_HSIOM_PORT_SEL4
UARTT_rx__0__HSIOM_GPIO EQU 0
UARTT_rx__0__HSIOM_I2C EQU 14
UARTT_rx__0__HSIOM_I2C_SCL EQU 14
UARTT_rx__0__HSIOM_MASK EQU 0x0000000F
UARTT_rx__0__HSIOM_SHIFT EQU 0
UARTT_rx__0__HSIOM_SPI EQU 15
UARTT_rx__0__HSIOM_SPI_MOSI EQU 15
UARTT_rx__0__HSIOM_UART EQU 9
UARTT_rx__0__HSIOM_UART_RX EQU 9
UARTT_rx__0__INTCFG EQU CYREG_PRT4_INTCFG
UARTT_rx__0__INTSTAT EQU CYREG_PRT4_INTSTAT
UARTT_rx__0__MASK EQU 0x01
UARTT_rx__0__PC EQU CYREG_PRT4_PC
UARTT_rx__0__PC2 EQU CYREG_PRT4_PC2
UARTT_rx__0__PORT EQU 4
UARTT_rx__0__PS EQU CYREG_PRT4_PS
UARTT_rx__0__SHIFT EQU 0
UARTT_rx__DR EQU CYREG_PRT4_DR
UARTT_rx__INTCFG EQU CYREG_PRT4_INTCFG
UARTT_rx__INTSTAT EQU CYREG_PRT4_INTSTAT
UARTT_rx__MASK EQU 0x01
UARTT_rx__PC EQU CYREG_PRT4_PC
UARTT_rx__PC2 EQU CYREG_PRT4_PC2
UARTT_rx__PORT EQU 4
UARTT_rx__PS EQU CYREG_PRT4_PS
UARTT_rx__SHIFT EQU 0

/* UARTT_SCB */
UARTT_SCB__BIST_CONTROL EQU CYREG_SCB0_BIST_CONTROL
UARTT_SCB__BIST_DATA EQU CYREG_SCB0_BIST_DATA
UARTT_SCB__CTRL EQU CYREG_SCB0_CTRL
UARTT_SCB__EZ_DATA00 EQU CYREG_SCB0_EZ_DATA00
UARTT_SCB__EZ_DATA01 EQU CYREG_SCB0_EZ_DATA01
UARTT_SCB__EZ_DATA02 EQU CYREG_SCB0_EZ_DATA02
UARTT_SCB__EZ_DATA03 EQU CYREG_SCB0_EZ_DATA03
UARTT_SCB__EZ_DATA04 EQU CYREG_SCB0_EZ_DATA04
UARTT_SCB__EZ_DATA05 EQU CYREG_SCB0_EZ_DATA05
UARTT_SCB__EZ_DATA06 EQU CYREG_SCB0_EZ_DATA06
UARTT_SCB__EZ_DATA07 EQU CYREG_SCB0_EZ_DATA07
UARTT_SCB__EZ_DATA08 EQU CYREG_SCB0_EZ_DATA08
UARTT_SCB__EZ_DATA09 EQU CYREG_SCB0_EZ_DATA09
UARTT_SCB__EZ_DATA10 EQU CYREG_SCB0_EZ_DATA10
UARTT_SCB__EZ_DATA11 EQU CYREG_SCB0_EZ_DATA11
UARTT_SCB__EZ_DATA12 EQU CYREG_SCB0_EZ_DATA12
UARTT_SCB__EZ_DATA13 EQU CYREG_SCB0_EZ_DATA13
UARTT_SCB__EZ_DATA14 EQU CYREG_SCB0_EZ_DATA14
UARTT_SCB__EZ_DATA15 EQU CYREG_SCB0_EZ_DATA15
UARTT_SCB__EZ_DATA16 EQU CYREG_SCB0_EZ_DATA16
UARTT_SCB__EZ_DATA17 EQU CYREG_SCB0_EZ_DATA17
UARTT_SCB__EZ_DATA18 EQU CYREG_SCB0_EZ_DATA18
UARTT_SCB__EZ_DATA19 EQU CYREG_SCB0_EZ_DATA19
UARTT_SCB__EZ_DATA20 EQU CYREG_SCB0_EZ_DATA20
UARTT_SCB__EZ_DATA21 EQU CYREG_SCB0_EZ_DATA21
UARTT_SCB__EZ_DATA22 EQU CYREG_SCB0_EZ_DATA22
UARTT_SCB__EZ_DATA23 EQU CYREG_SCB0_EZ_DATA23
UARTT_SCB__EZ_DATA24 EQU CYREG_SCB0_EZ_DATA24
UARTT_SCB__EZ_DATA25 EQU CYREG_SCB0_EZ_DATA25
UARTT_SCB__EZ_DATA26 EQU CYREG_SCB0_EZ_DATA26
UARTT_SCB__EZ_DATA27 EQU CYREG_SCB0_EZ_DATA27
UARTT_SCB__EZ_DATA28 EQU CYREG_SCB0_EZ_DATA28
UARTT_SCB__EZ_DATA29 EQU CYREG_SCB0_EZ_DATA29
UARTT_SCB__EZ_DATA30 EQU CYREG_SCB0_EZ_DATA30
UARTT_SCB__EZ_DATA31 EQU CYREG_SCB0_EZ_DATA31
UARTT_SCB__I2C_CFG EQU CYREG_SCB0_I2C_CFG
UARTT_SCB__I2C_CTRL EQU CYREG_SCB0_I2C_CTRL
UARTT_SCB__I2C_M_CMD EQU CYREG_SCB0_I2C_M_CMD
UARTT_SCB__I2C_S_CMD EQU CYREG_SCB0_I2C_S_CMD
UARTT_SCB__I2C_STATUS EQU CYREG_SCB0_I2C_STATUS
UARTT_SCB__INTR_CAUSE EQU CYREG_SCB0_INTR_CAUSE
UARTT_SCB__INTR_I2C_EC EQU CYREG_SCB0_INTR_I2C_EC
UARTT_SCB__INTR_I2C_EC_MASK EQU CYREG_SCB0_INTR_I2C_EC_MASK
UARTT_SCB__INTR_I2C_EC_MASKED EQU CYREG_SCB0_INTR_I2C_EC_MASKED
UARTT_SCB__INTR_M EQU CYREG_SCB0_INTR_M
UARTT_SCB__INTR_M_MASK EQU CYREG_SCB0_INTR_M_MASK
UARTT_SCB__INTR_M_MASKED EQU CYREG_SCB0_INTR_M_MASKED
UARTT_SCB__INTR_M_SET EQU CYREG_SCB0_INTR_M_SET
UARTT_SCB__INTR_RX EQU CYREG_SCB0_INTR_RX
UARTT_SCB__INTR_RX_MASK EQU CYREG_SCB0_INTR_RX_MASK
UARTT_SCB__INTR_RX_MASKED EQU CYREG_SCB0_INTR_RX_MASKED
UARTT_SCB__INTR_RX_SET EQU CYREG_SCB0_INTR_RX_SET
UARTT_SCB__INTR_S EQU CYREG_SCB0_INTR_S
UARTT_SCB__INTR_S_MASK EQU CYREG_SCB0_INTR_S_MASK
UARTT_SCB__INTR_S_MASKED EQU CYREG_SCB0_INTR_S_MASKED
UARTT_SCB__INTR_S_SET EQU CYREG_SCB0_INTR_S_SET
UARTT_SCB__INTR_SPI_EC EQU CYREG_SCB0_INTR_SPI_EC
UARTT_SCB__INTR_SPI_EC_MASK EQU CYREG_SCB0_INTR_SPI_EC_MASK
UARTT_SCB__INTR_SPI_EC_MASKED EQU CYREG_SCB0_INTR_SPI_EC_MASKED
UARTT_SCB__INTR_TX EQU CYREG_SCB0_INTR_TX
UARTT_SCB__INTR_TX_MASK EQU CYREG_SCB0_INTR_TX_MASK
UARTT_SCB__INTR_TX_MASKED EQU CYREG_SCB0_INTR_TX_MASKED
UARTT_SCB__INTR_TX_SET EQU CYREG_SCB0_INTR_TX_SET
UARTT_SCB__RX_CTRL EQU CYREG_SCB0_RX_CTRL
UARTT_SCB__RX_FIFO_CTRL EQU CYREG_SCB0_RX_FIFO_CTRL
UARTT_SCB__RX_FIFO_RD EQU CYREG_SCB0_RX_FIFO_RD
UARTT_SCB__RX_FIFO_RD_SILENT EQU CYREG_SCB0_RX_FIFO_RD_SILENT
UARTT_SCB__RX_FIFO_STATUS EQU CYREG_SCB0_RX_FIFO_STATUS
UARTT_SCB__RX_MATCH EQU CYREG_SCB0_RX_MATCH
UARTT_SCB__SPI_CTRL EQU CYREG_SCB0_SPI_CTRL
UARTT_SCB__SPI_STATUS EQU CYREG_SCB0_SPI_STATUS
UARTT_SCB__SS0_POSISTION EQU 0
UARTT_SCB__SS1_POSISTION EQU 1
UARTT_SCB__SS2_POSISTION EQU 2
UARTT_SCB__SS3_POSISTION EQU 3
UARTT_SCB__STATUS EQU CYREG_SCB0_STATUS
UARTT_SCB__TX_CTRL EQU CYREG_SCB0_TX_CTRL
UARTT_SCB__TX_FIFO_CTRL EQU CYREG_SCB0_TX_FIFO_CTRL
UARTT_SCB__TX_FIFO_STATUS EQU CYREG_SCB0_TX_FIFO_STATUS
UARTT_SCB__TX_FIFO_WR EQU CYREG_SCB0_TX_FIFO_WR
UARTT_SCB__UART_CTRL EQU CYREG_SCB0_UART_CTRL
UARTT_SCB__UART_RX_CTRL EQU CYREG_SCB0_UART_RX_CTRL
UARTT_SCB__UART_RX_STATUS EQU CYREG_SCB0_UART_RX_STATUS
UARTT_SCB__UART_TX_CTRL EQU CYREG_SCB0_UART_TX_CTRL

/* UARTT_SCBCLK */
UARTT_SCBCLK__DIVIDER_MASK EQU 0x0000FFFF
UARTT_SCBCLK__ENABLE EQU CYREG_CLK_DIVIDER_B00
UARTT_SCBCLK__ENABLE_MASK EQU 0x80000000
UARTT_SCBCLK__MASK EQU 0x80000000
UARTT_SCBCLK__REGISTER EQU CYREG_CLK_DIVIDER_B00

/* UARTT_tx */
UARTT_tx__0__DM__MASK EQU 0x38
UARTT_tx__0__DM__SHIFT EQU 3
UARTT_tx__0__DR EQU CYREG_PRT4_DR
UARTT_tx__0__HSIOM EQU CYREG_HSIOM_PORT_SEL4
UARTT_tx__0__HSIOM_GPIO EQU 0
UARTT_tx__0__HSIOM_I2C EQU 14
UARTT_tx__0__HSIOM_I2C_SDA EQU 14
UARTT_tx__0__HSIOM_MASK EQU 0x000000F0
UARTT_tx__0__HSIOM_SHIFT EQU 4
UARTT_tx__0__HSIOM_SPI EQU 15
UARTT_tx__0__HSIOM_SPI_MISO EQU 15
UARTT_tx__0__HSIOM_UART EQU 9
UARTT_tx__0__HSIOM_UART_TX EQU 9
UARTT_tx__0__INTCFG EQU CYREG_PRT4_INTCFG
UARTT_tx__0__INTSTAT EQU CYREG_PRT4_INTSTAT
UARTT_tx__0__MASK EQU 0x02
UARTT_tx__0__PC EQU CYREG_PRT4_PC
UARTT_tx__0__PC2 EQU CYREG_PRT4_PC2
UARTT_tx__0__PORT EQU 4
UARTT_tx__0__PS EQU CYREG_PRT4_PS
UARTT_tx__0__SHIFT EQU 1
UARTT_tx__DR EQU CYREG_PRT4_DR
UARTT_tx__INTCFG EQU CYREG_PRT4_INTCFG
UARTT_tx__INTSTAT EQU CYREG_PRT4_INTSTAT
UARTT_tx__MASK EQU 0x02
UARTT_tx__PC EQU CYREG_PRT4_PC
UARTT_tx__PC2 EQU CYREG_PRT4_PC2
UARTT_tx__PORT EQU 4
UARTT_tx__PS EQU CYREG_PRT4_PS
UARTT_tx__SHIFT EQU 1

/* Miscellaneous */
CYDEV_BCLK__HFCLK__HZ EQU 24000000
CYDEV_BCLK__HFCLK__KHZ EQU 24000
CYDEV_BCLK__HFCLK__MHZ EQU 24
CYDEV_BCLK__SYSCLK__HZ EQU 24000000
CYDEV_BCLK__SYSCLK__KHZ EQU 24000
CYDEV_BCLK__SYSCLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 12
CYDEV_CHIP_DIE_PSOC5LP EQU 19
CYDEV_CHIP_DIE_PSOC5TM EQU 20
CYDEV_CHIP_DIE_TMA4 EQU 2
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 4
CYDEV_CHIP_FAMILY_FM3 EQU 5
CYDEV_CHIP_FAMILY_FM4 EQU 6
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x04C81193
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 12
CYDEV_CHIP_MEMBER_4C EQU 18
CYDEV_CHIP_MEMBER_4D EQU 8
CYDEV_CHIP_MEMBER_4E EQU 4
CYDEV_CHIP_MEMBER_4F EQU 13
CYDEV_CHIP_MEMBER_4G EQU 2
CYDEV_CHIP_MEMBER_4H EQU 11
CYDEV_CHIP_MEMBER_4I EQU 17
CYDEV_CHIP_MEMBER_4J EQU 9
CYDEV_CHIP_MEMBER_4K EQU 10
CYDEV_CHIP_MEMBER_4L EQU 16
CYDEV_CHIP_MEMBER_4M EQU 15
CYDEV_CHIP_MEMBER_4N EQU 6
CYDEV_CHIP_MEMBER_4O EQU 5
CYDEV_CHIP_MEMBER_4P EQU 14
CYDEV_CHIP_MEMBER_4Q EQU 7
CYDEV_CHIP_MEMBER_4U EQU 3
CYDEV_CHIP_MEMBER_5A EQU 20
CYDEV_CHIP_MEMBER_5B EQU 19
CYDEV_CHIP_MEMBER_FM3 EQU 24
CYDEV_CHIP_MEMBER_FM4 EQU 25
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 21
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 22
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 23
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4A
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4C_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4A_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_Disallowed
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DFT_SELECT_CLK0 EQU 1
CYDEV_DFT_SELECT_CLK1 EQU 2
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_IMO_TRIMMED_BY_USB EQU 0
CYDEV_IMO_TRIMMED_BY_WCO EQU 0
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0400
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 1
CYDEV_VDDA_MV EQU 3300
CYDEV_VDDD_MV EQU 3300
CYDEV_WDT_GENERATE_ISR EQU 1
CYIPBLOCK_M0S8_CTBM_VERSION EQU 0
CYIPBLOCK_m0s8cpuss_VERSION EQU 0
CYIPBLOCK_m0s8csd_VERSION EQU 0
CYIPBLOCK_m0s8gpio2_VERSION EQU 0
CYIPBLOCK_m0s8hsiom4a_VERSION EQU 0
CYIPBLOCK_m0s8lcd_VERSION EQU 0
CYIPBLOCK_m0s8lpcomp_VERSION EQU 0
CYIPBLOCK_m0s8pclk_VERSION EQU 0
CYIPBLOCK_m0s8sar_VERSION EQU 0
CYIPBLOCK_m0s8scb_VERSION EQU 0
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 0
CYIPBLOCK_m0s8udbif_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 2
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */