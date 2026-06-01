/**
 * \file
 *
 * \brief AUTOSAR PduR
 *
 * This file contains the implementation of the AUTOSAR
 * module PduR.
 *
 * \version 6.0.5
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2025 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef PDUR_LCFG_H
#define PDUR_LCFG_H

/*==================[includes]==============================================*/

#include <PduR_Cfg.h>
#include <PduR_Types.h>
#include <PduR_Lcfg_Static.h>

/*==================[macros]================================================*/

/* Size of internal PduR data in units of bytes (static memory allocation).
 * Memory required by post-build configuration must be smaller than this constant.
 */
#define PDUR_MEM_SIZE 0

#if (PDUR_MEM_SIZE_MAX < PDUR_MEM_SIZE)
#error (PDUR_MEM_SIZE_MAX < PDUR_MEM_SIZE)
#endif /* #if (PDUR_MEM_SIZE_MAX < PDUR_MEM_SIZE) */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/* start const section declaration */
#define PDUR_START_SEC_CONST_8
#include <PduR_MemMap.h>

/* Index referring to the configuration of a module */
extern CONST(uint8, PDUR_CONST) PduR_CanIfRTabLoIfConfigIdx;
extern CONST(uint8, PDUR_CONST) PduR_ComRTabUpTxConfigIdx;

/* stop const section declaration */
#define PDUR_STOP_SEC_CONST_8
#include <PduR_MemMap.h>

/* start data section declaration */
#define PDUR_START_SEC_CONST_16
#include <PduR_MemMap.h>

/* Target module API reference */

/* stop const section declaration */
#define PDUR_STOP_SEC_CONST_16
#include <PduR_MemMap.h>

/* start data section declaration */
#define PDUR_START_SEC_CONST_32
#include <PduR_MemMap.h>

/* value used to validate post build configuration against link time configuration */
extern CONST(uint32, PDUR_CONST) PduRLcfgSignature;

/* stop data section declaration */
#define PDUR_STOP_SEC_CONST_32
#include <PduR_MemMap.h>

/* start const section declaration */
#define PDUR_START_SEC_CONST_UNSPECIFIED
#include <PduR_MemMap.h>

/**
 * API function pointer table for modules with interface and TP archetype
 */
extern CONST(PduR_ModuleAPIType, PDUR_CONST) PduR_ModuleAPI[5];
/**
 * API function pointer table for modules with interface archetype
 */
extern CONST(PduR_IfModuleAPIType, PDUR_CONST) PduR_IfModuleAPI[5];

/* stop const section declaration */
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include <PduR_MemMap.h>

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef PDUR_LCFG_H  */
/*==================[end of file]===========================================*/
