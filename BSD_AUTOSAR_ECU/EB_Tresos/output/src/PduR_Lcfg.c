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


/*==================[includes]==============================================*/

#include <PduR_Cfg.h> /* Pre compile time configuration header */
#include <PduR_Lcfg.h> /* Link time configuration header  */
#include <CanIf.h> /* Adjacent layer header */
#include <Com_Cbk.h> /* Adjacent layer header */

#if ((PDUR_TPGATEWAY_SUPPORT == STD_ON) \
    || (PDUR_IFGATEWAY_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_TOIF_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_FROMIF_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_UPTOLOTP_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_LOTPTOUP_SUPPORT == STD_ON))

#include <PduR_Internal_Static.h>

#endif /* ((PDUR_TPGATEWAY_SUPPORT == STD_ON) \
    || (PDUR_IFGATEWAY_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_TOIF_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_FROMIF_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_UPTOLOTP_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_LOTPTOUP_SUPPORT == STD_ON)) */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/* start data section declaration */
#define PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <PduR_MemMap.h>

/* Internal memory statically allocated upon link-time. Size depends on
 * post build configuration. Memory requirements of post build configuration
 * must be smaller than PDUR_MEM_SIZE_MAX in order to avoid buffer
 * overflows. Memory is aligned to the most stringent alignment requirement
 * of any simple data type available on the respective platform, e.g. uint32.
 */
#if (PDUR_MEM_SIZE > 0) /* To prevent empty arrays */
STATIC TS_DefMaxAlignedByteArray(PduR_Mem, PDUR, VAR_CLEARED, PDUR_MEM_SIZE);
#endif /* (PDUR_MEM_SIZE > 0) */

/* stop data section declaration */
#define PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <PduR_MemMap.h>


/* start const section declaration */
#define PDUR_START_SEC_CONST_UNSPECIFIED
#include <PduR_MemMap.h>

/**
 * Pointer to internal memory
 */
#if (PDUR_MEM_SIZE > 0) /* To prevent empty arrays */
CONSTP2VAR(uint8, PDUR_CONST, PDUR_VAR_CLEARED) PduR_GMemPtr =
  (P2VAR(uint8, PDUR_CONST, PDUR_VAR_CLEARED))
  ((P2VAR(void, PDUR_CONST, PDUR_VAR_CLEARED)) PduR_Mem);
#else /* (PDUR_MEM_SIZE > 0) */
CONSTP2VAR(uint8, PDUR_CONST, PDUR_VAR_CLEARED) PduR_GMemPtr = NULL_PTR;
#endif /* (PDUR_MEM_SIZE > 0) */

/* stop const section declaration */
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include <PduR_MemMap.h>

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/* start const section declaration */
#define PDUR_START_SEC_CONST_8
#include <PduR_MemMap.h>

/* Index referring to the configuration of a module */
CONST(uint8, PDUR_CONST) PduR_CanIfRTabLoIfConfigIdx = 0U;
CONST(uint8, PDUR_CONST) PduR_ComRTabUpTxConfigIdx = 0U;

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
CONST(uint32, PDUR_CONST) PduRLcfgSignature = 3958107115U;

/* stop data section declaration */
#define PDUR_STOP_SEC_CONST_32
#include <PduR_MemMap.h>

/* start const section declaration */
#define PDUR_START_SEC_CONST_UNSPECIFIED
#include <PduR_MemMap.h>

/**
 * API function pointer table for modules
 */
CONST(PduR_ModuleAPIType, PDUR_CONST) PduR_ModuleAPI[] =
{
    { /* [0] Com */
        NULL_PTR /* Transmit */
    }
    , { /* [1] CanIf */
        &CanIf_Transmit /* Transmit */
    }
    , { /* [2] Multi */
        NULL_PTR /* Transmit */
    }
    , { /* [3] MultiUp */
        &PduR_MultiUpIfTransmit /* Transmit */
    }
    , { /* [4] Gate (Nb) */
        NULL_PTR /* Transmit */
    }
};



/**
 * API function pointer table for modules with interface communication module archetype
 */
CONST(PduR_IfModuleAPIType, PDUR_CONST) PduR_IfModuleAPI[] =
{
    { /* [0] Com */
        NULL_PTR /* Transmit */
        , &Com_TriggerTransmit /* TriggerTransmit */
        , &Com_TxConfirmation /* TxConfirmation */
        , &Com_RxIndication /* RxIndication */
    }
    , { /* [1] CanIf */
        &CanIf_Transmit /* Transmit */
        , NULL_PTR /* TriggerTransmit */
        , NULL_PTR /* TxConfirmation */
        , NULL_PTR /* RxIndication */
    }
    , { /* [2] Multi */
        NULL_PTR /* Transmit */
        , NULL_PTR /* TriggerTransmit */
        , NULL_PTR /* TxConfirmation */
        , &PduR_MultiIfRxIndication /* RxIndication */
    }
    , { /* [3] MultiUp */
        &PduR_MultiUpIfTransmit /* Transmit */
        , NULL_PTR /* TriggerTransmit */
        , &PduR_MultiIfTxConfirmation /* TxConfirmation */
        , NULL_PTR /* RxIndication */
    }
    , { /* [4] Gate (Nb) */
        NULL_PTR /* Transmit */
        , NULL_PTR /* TriggerTransmit */
        , NULL_PTR /* TxConfirmation */
        , &PduR_GateIfRxIndicationNb /* RxIndication */
    }
};


/* stop const section declaration */
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include <PduR_MemMap.h>

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
