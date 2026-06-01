#ifndef COM_LCFG_H
#define COM_LCFG_H

/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \version 7.0.4
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2025 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */



/*==================[includes]==============================================*/

#include <TSAutosar.h>         /* EB specific standard types */
#include <Com_Api.h>           /* Module interface */
#include <Com_Callout.h>
#include <Com_Cbk.h>
#include <Com_Cfg.h>
/* Exclude post-build-time configuration include file if requested to do so */
#if (!defined COM_NO_PBCFG_REQUIRED) && (!defined COM_NO_CFG_REQUIRED)
#include <Com_SymbolicNames_PBcfg.h>
#endif /* (!defined COM_NO_PBCFG_REQUIRED) && (!defined COM_NO_CFG_REQUIRED) */


/*==================[macros]================================================*/

/**
 * Size of internal Com data in units of bytes (static memory allocation).
 * Memory required by post-build configuration must be smaller than this constant.
 */
#define COM_DATA_MEM_SIZE 54

#if (COM_RAM_SIZE_MAX < COM_DATA_MEM_SIZE)
#error (COM_RAM_SIZE_MAX < COM_DATA_MEM_SIZE)
#endif /* #if (COM_RAM_SIZE_MAX < COM_DATA_MEM_SIZE) */


#if (defined COM_TX_CALL_OUT_FUNC_PTR_ARRAY_SIZE) /* To prevent double declaration */
#error COM_TX_CALL_OUT_FUNC_PTR_ARRAY_SIZE already defined
#endif /* if (defined COM_TX_CALL_OUT_FUNC_PTR_ARRAY_SIZE) */

/** \brief Define COM_TX_CALL_OUT_FUNC_PTR_ARRAY_SIZE */
#define COM_TX_CALL_OUT_FUNC_PTR_ARRAY_SIZE 0U

#if (defined COM_RX_CALL_OUT_FUNC_PTR_ARRAY_SIZE) /* To prevent double declaration */
#error COM_RX_CALL_OUT_FUNC_PTR_ARRAY_SIZE already defined
#endif /* if (defined COM_RX_CALL_OUT_FUNC_PTR_ARRAY_SIZE) */

/** \brief Define COM_RX_CALL_OUT_FUNC_PTR_ARRAY_SIZE */
#define COM_RX_CALL_OUT_FUNC_PTR_ARRAY_SIZE 0U


#if (defined COM_CBK_TX_ACK_PTR_ARRAY_SIZE) /* To prevent double declaration */
#error COM_CBK_TX_ACK_PTR_ARRAY_SIZE already defined
#endif /* if (defined COM_CBK_TX_ACK_PTR_ARRAY_SIZE) */

/** \brief Define COM_CBK_TX_ACK_PTR_ARRAY_SIZE */
#define COM_CBK_TX_ACK_PTR_ARRAY_SIZE 0U


#if (defined COM_CBK_RX_ACK_PTR_ARRAY_SIZE) /* To prevent double declaration */
#error COM_CBK_RX_ACK_PTR_ARRAY_SIZE already defined
#endif /* if (defined COM_CBK_RX_ACK_PTR_ARRAY_SIZE) */

/** \brief Define COM_CBK_RX_ACK_PTR_ARRAY_SIZE */
#define COM_CBK_RX_ACK_PTR_ARRAY_SIZE 0U


#if (defined COM_CBK_TX_T_OUT_ARRAY_SIZE) /* To prevent double declaration */
#error COM_CBK_TX_T_OUT_ARRAY_SIZE already defined
#endif /* if (defined COM_CBK_TX_T_OUT_ARRAY_SIZE) */

/** \brief Define COM_CBK_TX_T_OUT_ARRAY_SIZE */
#define COM_CBK_TX_T_OUT_ARRAY_SIZE 1U


#if (defined COM_CBK_RX_T_OUT_ARRAY_SIZE) /* To prevent double declaration */
#error COM_CBK_RX_T_OUT_ARRAY_SIZE already defined
#endif /* if (defined COM_CBK_RX_T_OUT_ARRAY_SIZE) */

/** \brief Define COM_CBK_RX_T_OUT_ARRAY_SIZE */
#define COM_CBK_RX_T_OUT_ARRAY_SIZE 0U


#if (defined COM_CBK_TX_ERR_PTR_ARRAY_SIZE) /* To prevent double declaration */
#error COM_CBK_TX_ERR_PTR_ARRAY_SIZE already defined
#endif /* if (defined COM_CBK_TX_ERR_PTR_ARRAY_SIZE) */

/** \brief Define COM_CBK_TX_ERR_PTR_ARRAY_SIZE */
#define COM_CBK_TX_ERR_PTR_ARRAY_SIZE 1U

/* Internal indices of EcucPartitions */

#if (defined ComConf_EB_EcucPartition_) /* To prevent double declaration */
#error ComConf_EB_EcucPartition_ already defined
#endif /* #if (defined ComConf_EB_EcucPartition_) */

#define ComConf_EB_EcucPartition_ 0U


/* Internal IDs of ComMainFunctions */

#if (defined ComConf_ComMainFunctionRx_ComMainFunctionRx) /* To prevent double declaration */
#error ComConf_ComMainFunctionRx_ComMainFunctionRx already defined
#endif /* #if (defined ComConf_ComMainFunctionRx_ComMainFunctionRx) */

#define ComConf_ComMainFunctionRx_ComMainFunctionRx 0U


#if (defined ComConf_ComMainFunctionTx_ComMainFunctionTx) /* To prevent double declaration */
#error ComConf_ComMainFunctionTx_ComMainFunctionTx already defined
#endif /* #if (defined ComConf_ComMainFunctionTx_ComMainFunctionTx) */

#define ComConf_ComMainFunctionTx_ComMainFunctionTx 0U


#if (defined COM_LCFG_SIGNATURE) /* To prevent double declaration */
#error COM_LCFG_SIGNATURE already defined
#endif /* if (defined COM_LCFG_SIGNATURE) */

/** \brief Define COM_LCFG_SIGNATURE */
#define COM_LCFG_SIGNATURE 0xdc9ad683U

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/* start data section declaration */
#define COM_START_SEC_CODE
#include <Com_MemMap.h>


/*------------------[Com_Init_ComMainFunctionRx]------------------------- */

/**
 * \brief Com_Init_ComMainFunctionRx - initialize context information of the
 * Rx instance.
 *
 * This function calls Com_Init_MainFunctionRx_Generic() in order to initialize
 * Rx instance related context information.
 *
 * \Reentrancy{Non re-entrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, COM_CODE) Com_Init_ComMainFunctionRx(void);

/*------------------[Com_Main_Funcs_Rx]-----------------------------------*/

#ifndef RTE_SCHM_SWCBSW_COM_MAINFUNCTIONRX_COMMAINFUNCTIONRX
#define RTE_SCHM_SWCBSW_COM_MAINFUNCTIONRX_COMMAINFUNCTIONRX
/**
 * \brief Com_MainFunctionRx_ComMainFunctionRx
 * - handles Rx I-Pdus and the related signals and signal groups which are
 * mapped to the function.
 *
 * This function implements the functionality of Com_MainFunctionRx() for the mapped I-Pdus only.
 * Preconditions:
 * - COM must be initialized
 *
 * \param[in] None
 *
 *
 * \ServiceID{0x18}
 * \Reentrancy{Non re-entrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, COM_CODE) Com_MainFunctionRx_ComMainFunctionRx(void);
#endif /* RTE_SCHM_SWCBSW_COM_MAINFUNCTIONRX_COMMAINFUNCTIONRX */

/*------------------[Com_Init_ComMainFunctionTx]------------------------- */

/**
 * \brief Com_Init_ComMainFunctionTx - initialize context information of the
 * Tx instance.
 *
 * This function calls Com_Init_MainFunctionTx_Generic() in order to initialize
 * Tx instance related context information.
 *
 * \Reentrancy{Non re-entrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, COM_CODE) Com_Init_ComMainFunctionTx(void);

/*------------------[Com_Main_Funcs_Tx]-----------------------------------*/

#ifndef RTE_SCHM_SWCBSW_COM_MAINFUNCTIONTX_COMMAINFUNCTIONTX
#define RTE_SCHM_SWCBSW_COM_MAINFUNCTIONTX_COMMAINFUNCTIONTX
/**
 * \brief Com_MainFunctionTx_ComMainFunctionTx
 * - handles Tx I-Pdus and the related signals and signal groups which are
 * mapped to the function.
 *
 * This function implements the functionality of Com_MainFunctionTx() for the mapped I-Pdus only.
 * Preconditions:
 * - COM must be initialized
 *
 * \param[in] None
 *
 *
 * \ServiceID{0x19}
 * \Reentrancy{Non re-entrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, COM_CODE) Com_MainFunctionTx_ComMainFunctionTx(void);
#endif /* RTE_SCHM_SWCBSW_COM_MAINFUNCTIONTX_COMMAINFUNCTIONTX */

/*------------------[Com_Main_Funcs_Route]--------------------------------*/
#ifndef RTE_SCHM_SWCBSW_COM_MAINFUNCTIONROUTESIGNALS_COMMAINFUNCTIONROUTESIGNALS
#define RTE_SCHM_SWCBSW_COM_MAINFUNCTIONROUTESIGNALS_COMMAINFUNCTIONROUTESIGNALS
/**
 * \brief Com_MainFunctionRouteSignals_ComMainFunctionRouteSignals - handle cyclic Signal Gateway tasks
 *
 * This function handles cyclic receiving and sending (group)signals(group)
 * for the Signal Gateway functionality (SigGW).
 * Preconditions:
 * - COM must be initialized
 *
 *
 * \ServiceID{0x1A}
 * \Reentrancy{Non re-entrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, COM_CODE) Com_MainFunctionRouteSignals_ComMainFunctionRouteSignals(void);
#endif /* RTE_SCHM_SWCBSW_COM_MAINFUNCTIONROUTESIGNALS_COMMAINFUNCTIONROUTESIGNALS */


/* stop data section declaration */
#define COM_STOP_SEC_CODE
#include <Com_MemMap.h>
/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef COM_LCFG_H  */
/*==================[end of file]===========================================*/
