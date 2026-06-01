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
#ifndef CANIF_INT_CFG_H
#define CANIF_INT_CFG_H


/*==================[includes]===============================================*/
#define CANIF_NO_PBCFG_REQUIRED
#include <TSAutosar.h>          /* EB specific standard types */
#include <ComStack_Types.h>     /* Autosar standard types */
#include <CanIf.h>            /* CanIf interface */

#include <CanSM_Cbk.h>                /* AUTOSAR CanSM callback definitions */


/* !LINKSTO CanIf.EB.HookOnReception.Header,1 */

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

#if(( CANIF_READTXPDU_NOTIF_STATUS_API == STD_ON ) || ( CANIF_READRXPDU_NOTIF_STATUS_API == STD_ON ))



#define CANIF_START_SEC_VAR_CLEARED_8
#include <CanIf_MemMap.h>

#if( CANIF_READTXPDU_NOTIF_STATUS_API == STD_ON )
/** \brief Bit-array of Tx notification flags (if enabled)
 **
 ** This array contains a Tx notification flag for each Tx L-PDU for which
 ** this feature is enabled.
 */
extern VAR( uint8, CANIF_VAR )
  CanIf_TxLPduNotifyFlags[];
#endif /* CANIF_READTXPDU_NOTIF_STATUS_API == STD_ON */

#if( CANIF_READRXPDU_NOTIF_STATUS_API == STD_ON )
/** \brief Bit-array of Rx notification flags (if enabled)
 **
 ** This array contains a Rx notification flag for each Rx L-PDU for which
 ** this feature is enabled.
 */
extern VAR( uint8, CANIF_VAR )
  CanIf_RxLPduNotifyFlags[];
#endif /* CANIF_READRXPDU_NOTIF_STATUS_API == STD_ON */

#define CANIF_STOP_SEC_VAR_CLEARED_8
#include <CanIf_MemMap.h>

#endif /* ( CANIF_READTXPDU_NOTIF_STATUS_API == STD_ON ) || ( CANIF_READRXPDU_NOTIF_STATUS_API == STD_ON ) */


/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef CANIF_INT_CFG_H */
/*==================[end of file]============================================*/
