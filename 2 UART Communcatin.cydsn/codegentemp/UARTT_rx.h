/*******************************************************************************
* File Name: UARTT_rx.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_UARTT_rx_H) /* Pins UARTT_rx_H */
#define CY_PINS_UARTT_rx_H

#include "cytypes.h"
#include "cyfitter.h"
#include "UARTT_rx_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} UARTT_rx_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   UARTT_rx_Read(void);
void    UARTT_rx_Write(uint8 value);
uint8   UARTT_rx_ReadDataReg(void);
#if defined(UARTT_rx__PC) || (CY_PSOC4_4200L) 
    void    UARTT_rx_SetDriveMode(uint8 mode);
#endif
void    UARTT_rx_SetInterruptMode(uint16 position, uint16 mode);
uint8   UARTT_rx_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void UARTT_rx_Sleep(void); 
void UARTT_rx_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(UARTT_rx__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define UARTT_rx_DRIVE_MODE_BITS        (3)
    #define UARTT_rx_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - UARTT_rx_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the UARTT_rx_SetDriveMode() function.
         *  @{
         */
        #define UARTT_rx_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define UARTT_rx_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define UARTT_rx_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define UARTT_rx_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define UARTT_rx_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define UARTT_rx_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define UARTT_rx_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define UARTT_rx_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define UARTT_rx_MASK               UARTT_rx__MASK
#define UARTT_rx_SHIFT              UARTT_rx__SHIFT
#define UARTT_rx_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in UARTT_rx_SetInterruptMode() function.
     *  @{
     */
        #define UARTT_rx_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define UARTT_rx_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define UARTT_rx_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define UARTT_rx_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(UARTT_rx__SIO)
    #define UARTT_rx_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(UARTT_rx__PC) && (CY_PSOC4_4200L)
    #define UARTT_rx_USBIO_ENABLE               ((uint32)0x80000000u)
    #define UARTT_rx_USBIO_DISABLE              ((uint32)(~UARTT_rx_USBIO_ENABLE))
    #define UARTT_rx_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define UARTT_rx_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define UARTT_rx_USBIO_ENTER_SLEEP          ((uint32)((1u << UARTT_rx_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << UARTT_rx_USBIO_SUSPEND_DEL_SHIFT)))
    #define UARTT_rx_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << UARTT_rx_USBIO_SUSPEND_SHIFT)))
    #define UARTT_rx_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << UARTT_rx_USBIO_SUSPEND_DEL_SHIFT)))
    #define UARTT_rx_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(UARTT_rx__PC)
    /* Port Configuration */
    #define UARTT_rx_PC                 (* (reg32 *) UARTT_rx__PC)
#endif
/* Pin State */
#define UARTT_rx_PS                     (* (reg32 *) UARTT_rx__PS)
/* Data Register */
#define UARTT_rx_DR                     (* (reg32 *) UARTT_rx__DR)
/* Input Buffer Disable Override */
#define UARTT_rx_INP_DIS                (* (reg32 *) UARTT_rx__PC2)

/* Interrupt configuration Registers */
#define UARTT_rx_INTCFG                 (* (reg32 *) UARTT_rx__INTCFG)
#define UARTT_rx_INTSTAT                (* (reg32 *) UARTT_rx__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define UARTT_rx_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(UARTT_rx__SIO)
    #define UARTT_rx_SIO_REG            (* (reg32 *) UARTT_rx__SIO)
#endif /* (UARTT_rx__SIO_CFG) */

/* USBIO registers */
#if !defined(UARTT_rx__PC) && (CY_PSOC4_4200L)
    #define UARTT_rx_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define UARTT_rx_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define UARTT_rx_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define UARTT_rx_DRIVE_MODE_SHIFT       (0x00u)
#define UARTT_rx_DRIVE_MODE_MASK        (0x07u << UARTT_rx_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins UARTT_rx_H */


/* [] END OF FILE */
