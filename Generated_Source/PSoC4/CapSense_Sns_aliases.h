/*******************************************************************************
* File Name: CapSense_Sns.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_CapSense_Sns_ALIASES_H) /* Pins CapSense_Sns_ALIASES_H */
#define CY_PINS_CapSense_Sns_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define CapSense_Sns_0			(CapSense_Sns__0__PC)
#define CapSense_Sns_0_PS		(CapSense_Sns__0__PS)
#define CapSense_Sns_0_PC		(CapSense_Sns__0__PC)
#define CapSense_Sns_0_DR		(CapSense_Sns__0__DR)
#define CapSense_Sns_0_SHIFT	(CapSense_Sns__0__SHIFT)
#define CapSense_Sns_0_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__0__SHIFT*2u)))

#define CapSense_Sns_1			(CapSense_Sns__1__PC)
#define CapSense_Sns_1_PS		(CapSense_Sns__1__PS)
#define CapSense_Sns_1_PC		(CapSense_Sns__1__PC)
#define CapSense_Sns_1_DR		(CapSense_Sns__1__DR)
#define CapSense_Sns_1_SHIFT	(CapSense_Sns__1__SHIFT)
#define CapSense_Sns_1_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__1__SHIFT*2u)))

#define CapSense_Sns_2			(CapSense_Sns__2__PC)
#define CapSense_Sns_2_PS		(CapSense_Sns__2__PS)
#define CapSense_Sns_2_PC		(CapSense_Sns__2__PC)
#define CapSense_Sns_2_DR		(CapSense_Sns__2__DR)
#define CapSense_Sns_2_SHIFT	(CapSense_Sns__2__SHIFT)
#define CapSense_Sns_2_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__2__SHIFT*2u)))

#define CapSense_Sns_3			(CapSense_Sns__3__PC)
#define CapSense_Sns_3_PS		(CapSense_Sns__3__PS)
#define CapSense_Sns_3_PC		(CapSense_Sns__3__PC)
#define CapSense_Sns_3_DR		(CapSense_Sns__3__DR)
#define CapSense_Sns_3_SHIFT	(CapSense_Sns__3__SHIFT)
#define CapSense_Sns_3_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__3__SHIFT*2u)))

#define CapSense_Sns_4			(CapSense_Sns__4__PC)
#define CapSense_Sns_4_PS		(CapSense_Sns__4__PS)
#define CapSense_Sns_4_PC		(CapSense_Sns__4__PC)
#define CapSense_Sns_4_DR		(CapSense_Sns__4__DR)
#define CapSense_Sns_4_SHIFT	(CapSense_Sns__4__SHIFT)
#define CapSense_Sns_4_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__4__SHIFT*2u)))

#define CapSense_Sns_5			(CapSense_Sns__5__PC)
#define CapSense_Sns_5_PS		(CapSense_Sns__5__PS)
#define CapSense_Sns_5_PC		(CapSense_Sns__5__PC)
#define CapSense_Sns_5_DR		(CapSense_Sns__5__DR)
#define CapSense_Sns_5_SHIFT	(CapSense_Sns__5__SHIFT)
#define CapSense_Sns_5_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__5__SHIFT*2u)))

#define CapSense_Sns_6			(CapSense_Sns__6__PC)
#define CapSense_Sns_6_PS		(CapSense_Sns__6__PS)
#define CapSense_Sns_6_PC		(CapSense_Sns__6__PC)
#define CapSense_Sns_6_DR		(CapSense_Sns__6__DR)
#define CapSense_Sns_6_SHIFT	(CapSense_Sns__6__SHIFT)
#define CapSense_Sns_6_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__6__SHIFT*2u)))

#define CapSense_Sns_7			(CapSense_Sns__7__PC)
#define CapSense_Sns_7_PS		(CapSense_Sns__7__PS)
#define CapSense_Sns_7_PC		(CapSense_Sns__7__PC)
#define CapSense_Sns_7_DR		(CapSense_Sns__7__DR)
#define CapSense_Sns_7_SHIFT	(CapSense_Sns__7__SHIFT)
#define CapSense_Sns_7_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__7__SHIFT*2u)))

#define CapSense_Sns_INTR_ALL	 ((uint16)(CapSense_Sns_0_INTR| CapSense_Sns_1_INTR| CapSense_Sns_2_INTR| CapSense_Sns_3_INTR| CapSense_Sns_4_INTR| CapSense_Sns_5_INTR| CapSense_Sns_6_INTR| CapSense_Sns_7_INTR))
#define CapSense_Sns_MatrixButton_Col0__MB			(CapSense_Sns__MatrixButton_Col0__MB__PC)
#define CapSense_Sns_MatrixButton_Col0__MB_PS		(CapSense_Sns__MatrixButton_Col0__MB__PS)
#define CapSense_Sns_MatrixButton_Col0__MB_PC		(CapSense_Sns__MatrixButton_Col0__MB__PC)
#define CapSense_Sns_MatrixButton_Col0__MB_DR		(CapSense_Sns__MatrixButton_Col0__MB__DR)
#define CapSense_Sns_MatrixButton_Col0__MB_SHIFT	(CapSense_Sns__MatrixButton_Col0__MB__SHIFT)
#define CapSense_Sns_MatrixButton_Col0__MB_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__0__SHIFT*2u)))

#define CapSense_Sns_MatrixButton_Col1__MB			(CapSense_Sns__MatrixButton_Col1__MB__PC)
#define CapSense_Sns_MatrixButton_Col1__MB_PS		(CapSense_Sns__MatrixButton_Col1__MB__PS)
#define CapSense_Sns_MatrixButton_Col1__MB_PC		(CapSense_Sns__MatrixButton_Col1__MB__PC)
#define CapSense_Sns_MatrixButton_Col1__MB_DR		(CapSense_Sns__MatrixButton_Col1__MB__DR)
#define CapSense_Sns_MatrixButton_Col1__MB_SHIFT	(CapSense_Sns__MatrixButton_Col1__MB__SHIFT)
#define CapSense_Sns_MatrixButton_Col1__MB_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__1__SHIFT*2u)))

#define CapSense_Sns_MatrixButton_Col2__MB			(CapSense_Sns__MatrixButton_Col2__MB__PC)
#define CapSense_Sns_MatrixButton_Col2__MB_PS		(CapSense_Sns__MatrixButton_Col2__MB__PS)
#define CapSense_Sns_MatrixButton_Col2__MB_PC		(CapSense_Sns__MatrixButton_Col2__MB__PC)
#define CapSense_Sns_MatrixButton_Col2__MB_DR		(CapSense_Sns__MatrixButton_Col2__MB__DR)
#define CapSense_Sns_MatrixButton_Col2__MB_SHIFT	(CapSense_Sns__MatrixButton_Col2__MB__SHIFT)
#define CapSense_Sns_MatrixButton_Col2__MB_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__2__SHIFT*2u)))

#define CapSense_Sns_MatrixButton_Col3__MB			(CapSense_Sns__MatrixButton_Col3__MB__PC)
#define CapSense_Sns_MatrixButton_Col3__MB_PS		(CapSense_Sns__MatrixButton_Col3__MB__PS)
#define CapSense_Sns_MatrixButton_Col3__MB_PC		(CapSense_Sns__MatrixButton_Col3__MB__PC)
#define CapSense_Sns_MatrixButton_Col3__MB_DR		(CapSense_Sns__MatrixButton_Col3__MB__DR)
#define CapSense_Sns_MatrixButton_Col3__MB_SHIFT	(CapSense_Sns__MatrixButton_Col3__MB__SHIFT)
#define CapSense_Sns_MatrixButton_Col3__MB_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__3__SHIFT*2u)))

#define CapSense_Sns_MatrixButton_Row0__MB			(CapSense_Sns__MatrixButton_Row0__MB__PC)
#define CapSense_Sns_MatrixButton_Row0__MB_PS		(CapSense_Sns__MatrixButton_Row0__MB__PS)
#define CapSense_Sns_MatrixButton_Row0__MB_PC		(CapSense_Sns__MatrixButton_Row0__MB__PC)
#define CapSense_Sns_MatrixButton_Row0__MB_DR		(CapSense_Sns__MatrixButton_Row0__MB__DR)
#define CapSense_Sns_MatrixButton_Row0__MB_SHIFT	(CapSense_Sns__MatrixButton_Row0__MB__SHIFT)
#define CapSense_Sns_MatrixButton_Row0__MB_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__4__SHIFT*2u)))

#define CapSense_Sns_MatrixButton_Row1__MB			(CapSense_Sns__MatrixButton_Row1__MB__PC)
#define CapSense_Sns_MatrixButton_Row1__MB_PS		(CapSense_Sns__MatrixButton_Row1__MB__PS)
#define CapSense_Sns_MatrixButton_Row1__MB_PC		(CapSense_Sns__MatrixButton_Row1__MB__PC)
#define CapSense_Sns_MatrixButton_Row1__MB_DR		(CapSense_Sns__MatrixButton_Row1__MB__DR)
#define CapSense_Sns_MatrixButton_Row1__MB_SHIFT	(CapSense_Sns__MatrixButton_Row1__MB__SHIFT)
#define CapSense_Sns_MatrixButton_Row1__MB_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__5__SHIFT*2u)))

#define CapSense_Sns_MatrixButton_Row2__MB			(CapSense_Sns__MatrixButton_Row2__MB__PC)
#define CapSense_Sns_MatrixButton_Row2__MB_PS		(CapSense_Sns__MatrixButton_Row2__MB__PS)
#define CapSense_Sns_MatrixButton_Row2__MB_PC		(CapSense_Sns__MatrixButton_Row2__MB__PC)
#define CapSense_Sns_MatrixButton_Row2__MB_DR		(CapSense_Sns__MatrixButton_Row2__MB__DR)
#define CapSense_Sns_MatrixButton_Row2__MB_SHIFT	(CapSense_Sns__MatrixButton_Row2__MB__SHIFT)
#define CapSense_Sns_MatrixButton_Row2__MB_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__6__SHIFT*2u)))

#define CapSense_Sns_MatrixButton_Row3__MB			(CapSense_Sns__MatrixButton_Row3__MB__PC)
#define CapSense_Sns_MatrixButton_Row3__MB_PS		(CapSense_Sns__MatrixButton_Row3__MB__PS)
#define CapSense_Sns_MatrixButton_Row3__MB_PC		(CapSense_Sns__MatrixButton_Row3__MB__PC)
#define CapSense_Sns_MatrixButton_Row3__MB_DR		(CapSense_Sns__MatrixButton_Row3__MB__DR)
#define CapSense_Sns_MatrixButton_Row3__MB_SHIFT	(CapSense_Sns__MatrixButton_Row3__MB__SHIFT)
#define CapSense_Sns_MatrixButton_Row3__MB_INTR	((uint16)((uint16)0x0003u << (CapSense_Sns__7__SHIFT*2u)))


#endif /* End Pins CapSense_Sns_ALIASES_H */


/* [] END OF FILE */
