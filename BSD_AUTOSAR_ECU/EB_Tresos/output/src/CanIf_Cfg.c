/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
 *
 * \version 7.0.11
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2025 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*
 *  MISRA-C:2012 Deviations:
 *
 *  MISRAC2012-1) Deviated Rule: 9.5 (Required)
 *    Where designated initializers are used to initialize an array object the
 *    size of the array shall be specified explicitly.
 *
 *    Reason:
 *    Array size and initialization are depending on configuration whereas the
 *    array declaration is used by configuration-independent library code.
 */

/*==================[inclusions]=============================================*/

#define CANIF_NO_CFGCLASSMIX_REQUIRED
#ifndef CANIF_NO_PBCFG_REQUIRED
#define CANIF_NO_PBCFG_REQUIRED
#endif
#include <CanIf.h>                /* CanIf Types */
#include <CanIf_Int.h>
#include <CanIf_Int_Cfg.h>




#include <Can.h>              /* AUTOSAR Can driver header file inclusion */



/* do not indirectly include PduR_SymbolicNames_PBcfg.h via PduR_CanIf.h */
#define PDUR_NO_PBCFG_REQUIRED

#include <CanNm_Cbk.h>             /* CanNm callback function declarations */
#include <CanTp_Cbk.h>             /* CanTp callback function declarations */
#include <CanTSyn.h>               /* CanTSyn callback function declarations */
#include <PduR_CanIf.h>            /* PduR callback function declarations */
#include <J1939Nm_Cbk.h>           /* J1939Nm callback function declarations */
#include <J1939Tp_Cbk.h>           /* J1939Tp callback function declarations */
#include <Xcp_Cbk.h>               /* Xcp callback function declarations */


/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[internal constants]=====================================*/

/*==================[external constants]=====================================*/


#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>

/** \brief Configuration of CAN driver(s) function pointers */
CONST( CanIf_CanDrvFctConfigType, CANIF_APPL_CONST )
  CanIf_CanDrvFctConfig[1] =
{
  {
    &Can_Write,
    &Can_SetControllerMode,
    0u,
  },
};

/* !LINKSTO CanIf.EB.MultipleTrcv,1 */


/** \brief Configuration of upper layer callback function pointers */
/* Deviation MISRAC2012-1 <START> */
CONST( CanIf_CbkFctPtrTblType, CANIF_APPL_CONST ) CanIf_CbkFctPtrTbl[] =
{
  {
     /* CAN_NM */
    &CanNm_RxIndication,
    NULL_PTR,
    &CanNm_TxConfirmation,
  },
  {
     /* CAN_TP */
    &CanTp_RxIndication,
    &CanTp_TxConfirmation,
    NULL_PTR,
  },
  {
     /* CAN_TSYN */
    &CanTSyn_RxIndication,
    NULL_PTR,
    &CanTSyn_TxConfirmation,
  },
  {
     /* PDUR */
    &PduR_CanIfRxIndication,
    NULL_PTR,
    &PduR_CanIfTxConfirmation,
  },
  {
     /* J1939NM */
    &J1939Nm_RxIndication,
    NULL_PTR,
    &J1939Nm_TxConfirmation,
  },
  {
     /* J1939TP */
    &J1939Tp_RxIndication,
    NULL_PTR,
    &J1939Tp_TxConfirmation,
  },
  {
     /* XCP */
    &Xcp_CanIfRxIndication,
    NULL_PTR,
    &Xcp_CanIfTxConfirmation,
  },
};
/* Deviation MISRAC2012-1 <STOP> */







#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>

/*==================[external data]==========================================*/


#define CANIF_START_SEC_VAR_CLEARED_8
#include <CanIf_MemMap.h>

#if( ( CANIF_WAKEUP_VALIDATION_API == STD_ON ) || \
     ( CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT == STD_ON )  || \
     ( CANIF_PUBLIC_PN_SUPPORT == STD_ON) || \
     ( CANIF_BUS_MIRRORING_SUPPORT == STD_ON ) )

/** \brief Controller flags
 **
 ** This array contains the wakeup flags of all configured
 ** controllers. If a bit/flag has the value 1 it is set.
 ** Bit masks are:
 ** CANIF_WAKEUP_MASK             Wakeup flag
 ** CANIF_WAKEUP_VALIDATION_MASK  Wakeup validation flag
 ** CANIF_TX_CONFIRMATION_MASK    Tx confirmation flag
 ** CANIF_PN_FILTER_ACTIVE_MASK   Partial networking filter flag
 ** CANIF_BUS_MIRRORING_MASK      Mirroring flag
 */
VAR( uint8, CANIF_VAR )
  CanIf_CanControllerFlags[1U];

#endif /* ( CANIF_WAKEUP_VALIDATION_API == STD_ON ) || \
          ( CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT == STD_ON )  || \
          ( CANIF_PUBLIC_PN_SUPPORT == STD_ON) || \
          ( CANIF_BUS_MIRRORING_SUPPORT == STD_ON ) ) */









/** \brief Array for marking Tx pdus in expectation of confirmation
 **
 ** This is used to temporarily mark the Tx pdus that have yet to receive
 ** a TxConfirmation. Each bit represents a Tx pdu (where pduID = bitPosition+8*arrayIndex).
 */
VAR( uint8, CANIF_VAR )
  CanIf_TxPduNoConf[1U];

#define CANIF_STOP_SEC_VAR_CLEARED_8
#include <CanIf_MemMap.h>

#define CANIF_START_SEC_VAR_CLEARED_16
#include <CanIf_MemMap.h>







#define CANIF_STOP_SEC_VAR_CLEARED_16
#include <CanIf_MemMap.h>

#define CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanIf_MemMap.h>

VAR( CanIf_ControllerModeType, CANIF_VAR )
  CanIf_CanControllerMode[1U];

VAR( CanIf_PduModeType, CANIF_VAR )
  CanIf_PduMode[1U];






#define CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanIf_MemMap.h>


/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/

/*==================[end of file]============================================*/
