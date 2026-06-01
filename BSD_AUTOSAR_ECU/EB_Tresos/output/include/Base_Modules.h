/**
 * \file
 *
 * \brief AUTOSAR Base
 *
 * This file contains the implementation of the AUTOSAR
 * module Base.
 *
 * \version 5.6.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2025 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO Base.ModuleInfo.HeaderFile,1 */
#ifndef BASE_MODULES_H
#define BASE_MODULES_H

/*==================[macros]=================================================*/

#ifndef BASE_BASE_ENABLED
/** \brief Enable status of the module Base (/Base/Base) (VariantPreCompile) */
#define BASE_BASE_ENABLED STD_ON
#endif

    #ifndef BASE_BASE_HEADER
/** \brief Name of the Base (/Base/Base) module's main header file */
#define BASE_BASE_HEADER <Base.h>
#endif

#ifndef BASE_CAN_ENABLED
/** \brief Enable status of the module Can (/Can/Can) (VariantPostBuild) */
#define BASE_CAN_ENABLED STD_ON
#endif

    #ifndef BASE_CAN_HEADER
/** \brief Name of the Can (/Can/Can) module's main header file */
#define BASE_CAN_HEADER <Can.h>
#endif

#ifndef BASE_CANIF_ENABLED
/** \brief Enable status of the module CanIf (/CanIf/CanIf) (VariantPostBuild) */
#define BASE_CANIF_ENABLED STD_ON
#endif

    
#ifndef BASE_CANIF_CONFIG_PTR
/** \brief Address of the first multiple configuration container for CanIf (/CanIf/CanIf) */
#define BASE_CANIF_CONFIG_PTR (&CanIfInit_Cfg)
#endif

#ifndef BASE_CANIF_HEADER
/** \brief Name of the CanIf (/CanIf/CanIf) module's main header file */
#define BASE_CANIF_HEADER <CanIf.h>
#endif

#ifndef BASE_COM_ENABLED
/** \brief Enable status of the module Com (/Com/Com) (VariantPostBuild) */
#define BASE_COM_ENABLED STD_ON
#endif


#ifndef BASE_COM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for Com (/Com/Com) */
#define BASE_COM_CONFIG_PTR (&ComConfig)
#endif

#ifndef BASE_COM_HEADER
/** \brief Name of the Com (/Com/Com) module's main header file */
#define BASE_COM_HEADER <Com.h>
#endif

#ifndef BASE_ECUC_ENABLED
/** \brief Enable status of the module EcuC (/EcuC/EcuC) (VariantPostBuild) */
#define BASE_ECUC_ENABLED STD_ON
#endif

    #ifndef BASE_ECUC_HEADER
/** \brief Name of the EcuC (/EcuC/EcuC) module's main header file */
#define BASE_ECUC_HEADER <EcuC.h>
#endif

#ifndef BASE_MCU_ENABLED
/** \brief Enable status of the module Mcu (/Mcu/Mcu) (VariantPostBuild) */
#define BASE_MCU_ENABLED STD_ON
#endif

    #ifndef BASE_MCU_HEADER
/** \brief Name of the Mcu (/Mcu/Mcu) module's main header file */
#define BASE_MCU_HEADER <Mcu.h>
#endif

#ifndef BASE_OS_ENABLED
/** \brief Enable status of the module Os (/Os/Os) (VariantPreCompile) */
#define BASE_OS_ENABLED STD_ON
#endif

    #ifndef BASE_OS_HEADER
/** \brief Name of the Os (/Os/Os) module's main header file */
#define BASE_OS_HEADER <Os.h>
#endif

#ifndef BASE_PDUR_ENABLED
/** \brief Enable status of the module PduR (/PduR/PduR) (VariantPostBuild) */
#define BASE_PDUR_ENABLED STD_ON
#endif


#ifndef BASE_PDUR_CONFIG_PTR
/** \brief Address of the first multiple configuration container for PduR (/PduR/PduR) */
#define BASE_PDUR_CONFIG_PTR (&PduRRoutingPaths)
#endif

#ifndef BASE_PDUR_HEADER
/** \brief Name of the PduR (/PduR/PduR) module's main header file */
#define BASE_PDUR_HEADER <PduR.h>
#endif

#endif /* ifndef BASE_MODULES_H */
/*==================[end of file]============================================*/
