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
#ifndef PDUR_TYPES_H
#define PDUR_TYPES_H

/*
 * MISRA-C:2004 Deviations:
 *
 * MISRA-1) Deviated Rule: 19.6 (required)
 *   '#undef' shall not be used.
 *
 *   Reason:
 *   The macros TS_RELOCATABLE_CFG_ENABLE and TS_PB_CFG_PTR_CLASS might be used by more
 *   modules than the PduR modules. To avoid that this macro is used by other modules
 *   accidentally an undef is used here.
 */

#include <PduR_CfgTypes.h>  /* Generated types                   */
#include <TSAutosar.h>      /* EB specific standard types        */
#include <ComStack_Types.h> /* AUTOSAR Communication Stack types */
#include <PduR_Cfg.h>       /* Pre-compile time configuration    */

#define TS_RELOCATABLE_CFG_ENABLE PDUR_RELOCATABLE_CFG_ENABLE
#define TS_PB_CFG_PTR_CLASS PDUR_APPL_CONST
#include <TSPBConfig_Types.h> /* Post Build Config Types Helpers */

/*==================[type definitions]======================================*/

/**
 * PduR_StateType
 */
#define PDUR_UNINIT  0U
#define PDUR_ONLINE  1U
typedef uint8 PduR_StateType;

/**
 * PduR_PBConfigIdType
 */
typedef uint16 PduR_PBConfigIdType;
/**
 * PduR_GateTpSessionInfoType
 */
typedef struct {
    PduR_PduLengthType RxWriteIndex; /* RxWriteIndex */
    PduR_PduLengthType TpSduLength; /* TpSduLength */
    PduR_PduLengthType AvailableBufferSize; /* AvailableBufferSize */
    uint8 PendTxConfCount; /* PendTxConfCount */
    uint8 Status; /* Status */
} PduR_GateTpSessionInfoType;

/**
 * PduR_GateTpQueueInfoType
 */
typedef struct {
    PduR_GateTpQueueIndexType HeadIdx; /* HeadIdx */
    PduR_GateTpQueueIndexType TailIdx; /* TailIdx */
} PduR_GateTpQueueInfoType;

/**
 * PduR_BufDfInfoType
 */
typedef struct {
    uint8 ConfP; /* ConfP */
    uint8 Count; /* Count */
    uint8 HeadPos; /* HeadPos */
    uint8 InTransmission; /* InTransmission */
} PduR_BufDfInfoType;

/**
 * PduR_BufTfInfoType
 */
typedef struct {
    uint8 ConfP; /* ConfP */
    uint8 Count; /* Count */
    uint8 HeadPos; /* HeadPos */
} PduR_BufTfInfoType;

/**
 * PduR_BufSbDynPyldInfoType
 */
typedef struct {
    uint8 UsedSduLength; /* UsedSduLength */
} PduR_BufSbDynPyldInfoType;

/**
 * PduR_MultiTpTxSessionInfoType
 */
typedef struct {
    PduR_PduIdType MTpTxPduId; /* MTpTxPduId */
    PduR_PduLengthType SduLength; /* SduLength */
    Std_ReturnType ResultTxConf; /* ResultTxConf */
    uint8 Status; /* Status */
} PduR_MultiTpTxSessionInfoType;



/*------------------[function pointer types]--------------------------------*/

/** \brief Function pointer type used for indication functions of interface
 ** modules **/
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfRxIndFpType)
(
  PduIdType RxPduId,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);

/** \brief Function pointer type used for confirmation functions of interface
 ** modules **/
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfTxConfFpType)
(
  PduIdType TxPduId,
  Std_ReturnType Result
);

/** \brief Function pointer type used for trigger transmit functions of
 ** interface modules **/
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_IfTrTxFpType)
(
  PduIdType TxPduId,
  P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);

/** \brief Function pointer type used by the transport protocol module at the start of receiving
 ** an I-PDU. **/
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_StrtOfRcptnFpType)
(
  PduIdType RxPduId,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
  PduLengthType TpSduLength,
  P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr
);

/** \brief Function pointer type used when a transport protocol module has data to copy for the
 ** receiving module. **/
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyRxDataFpType)
(
  PduIdType RxPduId,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
  P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr
);

/** \brief Function pointer type used by the transport protocol module after an I-PDU has been received
 ** successfully or when an error occurred. **/
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpRxIndFpType)
(
  PduIdType RxPduId,
  Std_ReturnType Result
);

/** \brief Function pointer type used by the transport protocol module to query the transmit data
 ** of an I-PDU segment. **/
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyTxDataFpType )
(
  PduIdType TxPduId,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
  P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) RetryInfoPtr,
  P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) AvailableDataPtr
);

/** \brief Function pointer type used by a transport protocol module after the I-PDU has been
 ** transmitted on its network. **/
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpTxConfFpType)
(
  PduIdType TxPduId,
  Std_ReturnType Result
);

/** \brief Function pointer type used for transmit functions provided to
 ** upper layer modules **/
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TransmitFpType)
(
  PduIdType TxPduId,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);



/*------------------[Module API table type]---------------------------------*/

/**
 * type for If module API
 */
typedef struct
{
  PduR_TransmitFpType UpTransmit; /**< pointer to x_Transmit() */
} PduR_ModuleAPIType;

/**
 * type for If module API
 */
typedef struct
{
  PduR_TransmitFpType IfTransmit; /**< pointer to xIf_Transmit() */
  PduR_IfTrTxFpType IfTriggerTransmit; /**< pointer to x_TriggerTransmit() */
  PduR_IfTxConfFpType IfTxConfirmation; /**< pointer to x_TxConfirmation() */
  PduR_IfRxIndFpType IfRxIndication; /**< pointer to x_RxIndication() */
} PduR_IfModuleAPIType;

/**
 * type for Tp module API
 */
typedef struct
{
  PduR_TransmitFpType TpTransmit; /**< pointer to xTp_Transmit() */
  PduR_CopyTxDataFpType TpCopyTxData; /**< pointer to x_CopyTxData() */
  PduR_TpTxConfFpType TpTxConfirmation; /**< pointer to x_TxConfirmation() */
  PduR_CopyRxDataFpType TpCopyRxData; /**< pointer to x_CopyRxData() */
  PduR_StrtOfRcptnFpType TpStartOfReception; /**< pointer to x_StartOfReception() */
  PduR_TpRxIndFpType TpRxIndication; /**< pointer to x_RxIndication() */
} PduR_TpModuleAPIType;

/* Deviation MISRA-1 */
#undef TS_RELOCATABLE_CFG_ENABLE

/* Deviation MISRA-1 */
#undef TS_PB_CFG_PTR_CLASS

#endif /* ifndef PDUR_TYPES_H  */
/*==================[end of file]===========================================*/

