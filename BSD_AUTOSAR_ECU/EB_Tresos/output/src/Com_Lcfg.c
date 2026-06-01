
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

/* MISRA-C:2012 Deviation List
 *
 *
 * MISRAC2012-1) Deviated Rule: 11.5 (advisory)
 * A conversion should not be performed from pointer to
 * void into pointer to object.
 *
 * Reason:
 * The memory routines are optimized for dealing with aligned
 * memory sections.
 *
 *
 * MISRAC2012-2) Deviated Rule: 8.5 (Required)
 * An external object or function shall be declared once in one and only one file.
 *
 * Reason:
 * The callout and callback functions are declared within the file since
 * the header files which declare the functions are in general not known.
 *
 */

/*==================[inclusions]============================================*/

#include <Com_Lcfg.h>
#include <Com_Lcfg_Static.h>
#include <TSAutosar.h>

/* start data section declaration */
#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <Com_MemMap.h>

/**
 * Internal memory statically allocated upon link-time. Size depends on
 * post build configuration. Memory requirements of post build configuration
 * must be smaller than COM_RAM_SIZE_MAX in order to avoid buffer
 * overflows. Memory is aligned to the most stringent alignment requirement
 * of any simple data type available on the respective platform, e.g. uint32.
 */
STATIC TS_DefMaxAlignedByteArray(Com_DataMem, COM, VAR_CLEARED, COM_DATA_MEM_SIZE);

/* stop data section declaration */
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <Com_MemMap.h>



/* start data section declaration */
#define COM_START_SEC_CONST_UNSPECIFIED
#include <Com_MemMap.h>

/**
 * Pointer to statically allocated RAM.
 */
/* Deviation MISRAC2012-1 <+3> */
CONSTP2VAR(uint8, COM_CONST, COM_VAR_CLEARED) Com_gDataMemPtr =
  (P2VAR(uint8, COM_CONST, COM_VAR_CLEARED))
  ((P2VAR(void, COM_CONST, COM_VAR_CLEARED)) Com_DataMem);

/* stop data section declaration */
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include <Com_MemMap.h>



#define COM_START_SEC_CALLOUT_CODE
#include <Com_MemMap.h>

/* receive callouts */

/* send callouts */

/* TX acknowledge callbacks */

/* TX timeout callbacks */
/* extern FUNC(void, COM_APPL_CODE) Com_EB_TxDMDummyCbk(void); (extern declaration already generated)*/

/* TX error callbacks */
/* extern FUNC(void, COM_APPL_CODE) Com_EB_TxDMDummyCbk(void); (extern declaration already generated)*/

/* RX timeout callbacks */

/* RX acknowledge callbacks */

/* Tx Prep callbacks */

/* extern FUNC(void, COM_APPL_CODE) Com_EB_CbkTxPrepDummyCbk(void);  (extern declaration already generated)*/
#define COM_STOP_SEC_CALLOUT_CODE
#include <Com_MemMap.h>


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
FUNC(void, COM_CODE) Com_Init_ComMainFunctionRx(void)
{

    Com_Init_MainFunctionRx_Generic(Com_gDataMemPtr,ComConf_ComMainFunctionRx_ComMainFunctionRx);

}


/*------------------[Com_Main_Funcs_Rx]-----------------------------------*/

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
FUNC(void, COM_CODE) Com_MainFunctionRx_ComMainFunctionRx(void)
{

    Com_MainFunctionRx_Generic(ComConf_ComMainFunctionRx_ComMainFunctionRx);

}

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
FUNC(void, COM_CODE) Com_Init_ComMainFunctionTx(void)
{

    Com_Init_MainFunctionTx_Generic(Com_gDataMemPtr,ComConf_ComMainFunctionTx_ComMainFunctionTx);

}


/*------------------[Com_Main_Funcs_Tx]-----------------------------------*/

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
FUNC(void, COM_CODE) Com_MainFunctionTx_ComMainFunctionTx(void)
{

    Com_MainFunctionTx_Generic(ComConf_ComMainFunctionTx_ComMainFunctionTx);

}

/*------------------[Com_Main_Funcs_Route]--------------------------------*/
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

FUNC(void, COM_CODE) Com_MainFunctionRouteSignals_ComMainFunctionRouteSignals(void)
{

  Com_MainFunctionRouteSignals();

}

/* stop data section declaration */
#define COM_STOP_SEC_CODE
#include <Com_MemMap.h>



#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <Com_MemMap.h>


#if (COM_CALL_OUT_FUNC_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE)
#if (COM_TX_CALL_OUT_FUNC_PTR_ARRAY_SIZE > 0)
/* send callouts */
CONSTP2VAR(Com_TxCalloutType, AUTOMATIC, COM_APPL_CODE) Com_TxCallouts[COM_TX_CALL_OUT_FUNC_PTR_ARRAY_SIZE] =
{
};
#else /* (COM_CALL_OUT_FUNC_PTR_ARRAY_SIZE > 0) */
CONSTP2VAR(Com_TxCalloutType, AUTOMATIC, COM_APPL_CODE) Com_TxCallouts[1] =
{
    NULL_PTR
};
#endif /* (COM_CALL_OUT_FUNC_PTR_ARRAY_SIZE > 0) */


#if (COM_RX_CALL_OUT_FUNC_PTR_ARRAY_SIZE > 0)
/* receive callouts */
CONSTP2VAR(Com_RxCalloutType, AUTOMATIC, COM_APPL_CODE) Com_RxCallouts[COM_RX_CALL_OUT_FUNC_PTR_ARRAY_SIZE] =
{
};
#else /* (COM_RX_CALL_OUT_FUNC_PTR_ARRAY_SIZE > 0) */
CONSTP2VAR(Com_RxCalloutType, AUTOMATIC, COM_APPL_CODE) Com_RxCallouts[1] =
{
    NULL_PTR
};
#endif /* (COM_RX_CALL_OUT_FUNC_PTR_ARRAY_SIZE > 0) */
#endif /* (COM_CALL_OUT_FUNC_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE) */


#if (COM_CBK_TX_ACK_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE)
#if (COM_CBK_TX_ACK_PTR_ARRAY_SIZE > 0)
CONSTP2VAR(Com_CbkTxAck_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkTxAck_Array[COM_CBK_TX_ACK_PTR_ARRAY_SIZE] =
{
};
#else /* (COM_CBK_TX_ACK_PTR_ARRAY_SIZE > 0) */
CONSTP2VAR(Com_CbkTxAck_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkTxAck_Array[1] =
{
    NULL_PTR
};
#endif /* (COM_CBK_TX_ACK_PTR_ARRAY_SIZE > 0) */
#endif /* (COM_CBK_TX_ACK_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE) */


#if (COM_CBK_TX_T_OUT_ARRAY_SIZE_MAX != COM_INDEX_NONE)
#if (COM_CBK_TX_T_OUT_ARRAY_SIZE > 0)
CONSTP2VAR(Com_CbkTxTOut_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkTxTOut_Array[COM_CBK_TX_T_OUT_ARRAY_SIZE] =
{
     &Com_EB_TxDMDummyCbk
};
#else /* (COM_CBK_TX_T_OUT_ARRAY_SIZE > 0) */
CONSTP2VAR(Com_CbkTxTOut_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkTxTOut_Array[1] =
{
    NULL_PTR
};
#endif /* (COM_CBK_TX_T_OUT_ARRAY_SIZE > 0) */
#endif /* (COM_CBK_TX_T_OUT_ARRAY_SIZE_MAX != COM_INDEX_NONE) */


#if (COM_CBK_TX_ERR_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE)
#if (COM_CBK_TX_ERR_PTR_ARRAY_SIZE > 0)
CONSTP2VAR(Com_CbkTxErr_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkTxErr_Array[COM_CBK_TX_ERR_PTR_ARRAY_SIZE] =
{
     &Com_EB_TxDMDummyCbk
};
#else /* (COM_CBK_TX_ERR_PTR_ARRAY_SIZE > 0) */
CONSTP2VAR(Com_CbkTxErr_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkTxErr_Array[1] =
{
    NULL_PTR
};
#endif /* (COM_CBK_TX_ERR_PTR_ARRAY_SIZE > 0) */
#endif /* (COM_CBK_TX_ERR_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE) */


#if (COM_CBK_RX_ACK_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE)
#if (COM_CBK_RX_ACK_PTR_ARRAY_SIZE > 0)
CONSTP2VAR(Com_CbkRxAck_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkRxAck_Array[COM_CBK_RX_ACK_PTR_ARRAY_SIZE] =
{
};
#else /* (COM_CBK_RX_ACK_PTR_ARRAY_SIZE > 0)) */
CONSTP2VAR(Com_CbkRxAck_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkRxAck_Array[1] =
{
    NULL_PTR
};
#endif /* (COM_CBK_RX_ACK_PTR_ARRAY_SIZE > 0)) */
#endif /* (COM_CBK_RX_ACK_PTR_ARRAY_SIZE_MAX != COM_INDEX_NONE) */


#if (COM_CBK_RX_T_OUT_ARRAY_SIZE_MAX != COM_INDEX_NONE)
#if (COM_CBK_RX_T_OUT_ARRAY_SIZE > 0)
CONSTP2VAR(Com_CbkRxTOut_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkRxTOut_Array[COM_CBK_RX_T_OUT_ARRAY_SIZE] =
{
};
#else /* (COM_CBK_RX_T_OUT_ARRAY_SIZE > 0) */
CONSTP2VAR(Com_CbkRxTOut_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkRxTOut_Array[1] =
{
    NULL_PTR
};
#endif /* (COM_CBK_RX_T_OUT_ARRAY_SIZE > 0) */
#endif /* (COM_CBK_RX_T_OUT_ARRAY_SIZE_MAX != COM_INDEX_NONE) */

CONSTP2VAR(Com_CbkTxPrep_Type, AUTOMATIC, COM_RTE_CODE) Com_CbkTxPrep_Array[COM_MAIN_ID_MAX_LENGTH] =
{
    &Com_EB_CbkTxPrepDummyCbk,
    &Com_EB_CbkTxPrepDummyCbk,
    &Com_EB_CbkTxPrepDummyCbk,
    &Com_EB_CbkTxPrepDummyCbk
};

CONST(Com_Main_ArrayType, AUTOMATIC) Com_Main_Array[COM_MAIN_ID_MAX_LENGTH] =
{
    {
        &Com_Init_ComMainFunctionTx,
        &Com_Init_ComMainFunctionRx,
        &Com_EB_Main_ArrayDummyCbk,
        &Com_EB_Main_ArrayDummyCbk
    },
    {
        &Com_EB_Main_ArrayDummyCbk,
        &Com_EB_Main_ArrayDummyCbk,
        &Com_EB_Main_ArrayDummyCbk,
        &Com_EB_Main_ArrayDummyCbk
    },
    {
        &Com_EB_Main_ArrayDummyCbk,
        &Com_EB_Main_ArrayDummyCbk,
        &Com_EB_Main_ArrayDummyCbk,
        &Com_EB_Main_ArrayDummyCbk
    },
    {
        &Com_EB_Main_ArrayDummyCbk,
        &Com_EB_Main_ArrayDummyCbk,
        &Com_EB_Main_ArrayDummyCbk,
        &Com_EB_Main_ArrayDummyCbk
    }
};

#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <Com_MemMap.h>


/* start data section declaration */
#define COM_START_SEC_CONST_32
#include <Com_MemMap.h>

/**
 * Variable holding link-time configuration
 */
CONST(uint32, COM_CONST) Com_LcfgSignature = COM_LCFG_SIGNATURE;

/* stop data section declaration */
#define COM_STOP_SEC_CONST_32
#include <Com_MemMap.h>

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
