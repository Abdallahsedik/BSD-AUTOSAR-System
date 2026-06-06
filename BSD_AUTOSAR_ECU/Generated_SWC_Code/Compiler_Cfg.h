/*************************************************************************************************************************************
@file Std Types.h
@version 1.0.0
@brief AUTOSAR Base - SWS Compiler configuration abstraction
@details AUTOSAR file Compiler configuration  header file.
@author abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project : AUTOSAR 4.4.0 MCAL
Platform  : ARM
Peripheral : STM32F407
Autosar Version : 4.4.0
Autosar Revision : ASR_REL_4_0_REV_0000
Sw Version : 1.0.0
*************************************************************************************************************************************/


#ifndef COMPILER__CFG_H
#define COMPILER__CFG_H

/*ID for the Company in AUTOSAR
 * Ex: ID = 43*/
#define COMPILER_CFG_VENDOR_ID                      43

/* AUTOSAR Version 4.4.0*/

#define COMPILER_CFG_AR_RELEASE_MAJOR_VERSION       4
#define COMPILER_CFG_AR_RELEASE_MINOR_VERSION       4
#define COMPILER_CFG_AR_RELEASE_REVISION_VERSION    0
/* Module Version 1.0.0 */
#define COMPILER_CFG_SW_MAJOR_VERSION               1
#define COMPILER_CFG_SW_MINOR_VERSION               0
#define COMPILER_CFG_SW_PATCH_VERSION               0
/**
 * @brief DIO Memory and pointer classes
 * 
 */
#define DIO_CODE
#define DIO_CONST
#define DIO_APPL_DATA
#define DIO_APPL_CONST
#define DIO_APPL_CODE
#define DIO_CALLOUT_CODE
#define DIO_VAR_NOINT
#define DIO_VAR_POWER_ON_INIT
#define DIO_VAR_FAST
#define DIO_VAR

/**
 * @brief PORT Memory and pointer classes
 * 
 */
#define PORT_CODE
#define PORT_CONST
#define PORT_APPL_DATA
#define PORT_APPL_CONST
#define PORT_APPL_CODE
#define PORT_CALLOUT_CODE
#define PORT_VAR_NOINT
#define PORT_VAR_POWER_ON_INIT
#define PORT_VAR_FAST
#define PORT_VAR

#endif /* #ifndef COMPILER_CFG_H */
