/*******************************************************************************
* File Name: UARTT_SCBCLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_UARTT_SCBCLK_H)
#define CY_CLOCK_UARTT_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void UARTT_SCBCLK_StartEx(uint32 alignClkDiv);
#define UARTT_SCBCLK_Start() \
    UARTT_SCBCLK_StartEx(UARTT_SCBCLK__PA_DIV_ID)

#else

void UARTT_SCBCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void UARTT_SCBCLK_Stop(void);

void UARTT_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 UARTT_SCBCLK_GetDividerRegister(void);
uint8  UARTT_SCBCLK_GetFractionalDividerRegister(void);

#define UARTT_SCBCLK_Enable()                         UARTT_SCBCLK_Start()
#define UARTT_SCBCLK_Disable()                        UARTT_SCBCLK_Stop()
#define UARTT_SCBCLK_SetDividerRegister(clkDivider, reset)  \
    UARTT_SCBCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define UARTT_SCBCLK_SetDivider(clkDivider)           UARTT_SCBCLK_SetDividerRegister((clkDivider), 1u)
#define UARTT_SCBCLK_SetDividerValue(clkDivider)      UARTT_SCBCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define UARTT_SCBCLK_DIV_ID     UARTT_SCBCLK__DIV_ID

#define UARTT_SCBCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define UARTT_SCBCLK_CTRL_REG   (*(reg32 *)UARTT_SCBCLK__CTRL_REGISTER)
#define UARTT_SCBCLK_DIV_REG    (*(reg32 *)UARTT_SCBCLK__DIV_REGISTER)

#define UARTT_SCBCLK_CMD_DIV_SHIFT          (0u)
#define UARTT_SCBCLK_CMD_PA_DIV_SHIFT       (8u)
#define UARTT_SCBCLK_CMD_DISABLE_SHIFT      (30u)
#define UARTT_SCBCLK_CMD_ENABLE_SHIFT       (31u)

#define UARTT_SCBCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << UARTT_SCBCLK_CMD_DISABLE_SHIFT))
#define UARTT_SCBCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << UARTT_SCBCLK_CMD_ENABLE_SHIFT))

#define UARTT_SCBCLK_DIV_FRAC_MASK  (0x000000F8u)
#define UARTT_SCBCLK_DIV_FRAC_SHIFT (3u)
#define UARTT_SCBCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define UARTT_SCBCLK_DIV_INT_SHIFT  (8u)

#else 

#define UARTT_SCBCLK_DIV_REG        (*(reg32 *)UARTT_SCBCLK__REGISTER)
#define UARTT_SCBCLK_ENABLE_REG     UARTT_SCBCLK_DIV_REG
#define UARTT_SCBCLK_DIV_FRAC_MASK  UARTT_SCBCLK__FRAC_MASK
#define UARTT_SCBCLK_DIV_FRAC_SHIFT (16u)
#define UARTT_SCBCLK_DIV_INT_MASK   UARTT_SCBCLK__DIVIDER_MASK
#define UARTT_SCBCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_UARTT_SCBCLK_H) */

/* [] END OF FILE */
