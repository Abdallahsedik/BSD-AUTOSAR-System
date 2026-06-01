


/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2025 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 1.3 (required)
 *    There shall be no occurrence of undefined or critical unspecified behaviour.
 *
 *    Reason:
 *    The postbuild macro TS_MAKEREF2CFG requires the usage of the
 *    C standard macro 'offsetof'.
 *    According to the C90 standard, the usage of 'offsetof' produces
 *    an undefined behaviour when the member designator parameter
 *    is a bit-field or when it is an invalid right operator of the
 *    '.' operator for the type parameter.
 *    This is not the case here as the parameter of TS_MAKEREF2CFG
 *    is always a member of TS_PB_CFG_LAYOUT_TYPE and bitfields are
 *    never used when defining the postbuild structure members.
 *
 * MISRAC2012-2) Deviated Rule: 11.4 (advisory)
 *    A cast should not be performed between a pointer type and an integral
 *    type.
 *
 *    Reason:
 *    Relocatable postbuild macro requires the cast between pointer and
 *    integral type.
 *
 * MISRAC2012-3) Deviated Rule: 11.9 (required)
 *    The macro NULL shall be the only permitted form of integer null pointer constant.
 *
 *    Reason:
 *    Macros are used in order to check the alignment for different data types.
 *
 * MISRAC2012-4) Deviated Rule: 20.7 (required)
 *    Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses.
 *
 *    Reason:
 *    The macro parameter is used to access a structure member. The expansion of the macro shall produce C compliant code and therefore parentheses can't be used.
 *    The priority and precedence of the used operators were reviewed. The macro substitution will give the desired result.
 *
 */

/*==================[inclusions]=============================================*/

#include <Com_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_NAME Com_ConfigLayout
#define TS_PB_CFG_LAYOUT_TYPE Com_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <Com_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3, MISRAC2012-4 <START> */
Com_ConstConfigLayoutType Com_ConfigLayout = {
    { /* Com_RootConfig */
        UINT32_C( 2147485970 ), /* ComPlatformSignature */
        UINT32_C( 3917916659 ), /* ComPublicInfoSignature */
        UINT32_C( 2284817146 ), /* ComCfgSignature */
        UINT32_C( 3701134979 ), /* ComLcfgSignature */
        UINT32_C( 46 ), /* ComRxIPduStatusBase */
        UINT32_C( 52 ), /* ComTxIPduStatusBase */
        UINT32_C( 4 ), /* ComRxIPduLengthBase */
        UINT32_C( 16 ), /* ComTxIPduLengthBase */
        UINT32_C( 0 ), /* ComTxSignalGroupStatusBase */
        UINT32_C( 0 ), /* ComBufferBaseUInt32 */
        UINT32_C( 0 ), /* ComBufferBaseSInt32 */
        UINT32_C( 0 ), /* ComBufferBaseUInt16 */
        UINT32_C( 0 ), /* ComBufferBaseSInt16 */
        UINT32_C( 0 ), /* ComBufferBaseUInt8 */
        UINT32_C( 0 ), /* ComBufferBaseSInt8 */
        UINT32_C( 0 ), /* ComBufferBaseBool */
        UINT32_C( 0 ), /* ComFilterOneEveryNBase */
        UINT32_C( 0 ), /* ComSigGWRxPduFlagBase */
        UINT32_C( 0 ), /* ComSigGWTxSignalGroupQueueBase */
        UINT32_C( 0 ), /* ComMDTQueueBase */
        UINT32_C( 0 ), /* ComPeriodicQueueBase */
        UINT32_C( 0 ), /* ComNTimesQueueBaseNextTime */
        UINT32_C( 0 ), /* ComNTimesQueueBaseRemaining */
        UINT32_C( 0 ), /* ComRxTimeoutQueueBase */
        TS_MAKENULLREF2CFG, /* ComRxTimeoutQueueListRef */
        UINT32_C( 0 ), /* ComRxTimeoutSignalStatusQueueBase */
        TS_MAKENULLREF2CFG, /* ComRxTimeoutSignalQueueListRef */
        UINT32_C( 0 ), /* ComRxDMInvSignalGroupStatusQueueBase */
        UINT32_C( 0 ), /* ComRxTimeoutSignalGroupQueueBase */
        TS_MAKENULLREF2CFG, /* ComRxTimeoutSignalGroupQueueListRef */
        UINT32_C( 0 ), /* ComTxTimeoutQueueBase */
        UINT32_C( 0 ), /* ComCbkTxAckDeferredStatusBase */
        TS_MAKEREF2CFG( ComRxIPdu[0] ), /* ComRxIPduRef */
        TS_MAKEREF2CFG( ComTxIPdu[0] ), /* ComTxIPduRef */
        TS_MAKENULLREF2CFG, /* ComTxModeNTimesRef */
        TS_MAKEREF2CFG( ComTxModePeriodic[0] ), /* ComTxModePeriodicRef */
        TS_MAKENULLREF2CFG, /* ComTxModeMixedNTimesRef */
        TS_MAKEREF2CFG( ComIPduGroup[0] ), /* ComIPduGroupRef */
        TS_MAKENULLREF2CFG, /* ComSigGWRxIPduListRef */
        TS_MAKENULLREF2CFG, /* ComRxIPduSignalGroupListRef */
        TS_MAKENULLREF2CFG, /* ComTxIPduSignalGroupListRef */
        TS_MAKEREF2CFG( ComRxIPduSignalList[0] ), /* ComRxIPduSignalListRef */
        TS_MAKEREF2CFG( ComTxIPduSignalList[0] ), /* ComTxIPduSignalListRef */
        TS_MAKENULLREF2CFG, /* ComRxSignalGroupRef */
        TS_MAKENULLREF2CFG, /* ComTxSignalGroupRef */
        TS_MAKENULLREF2CFG, /* ComTxSignalGroupGroupSignalListRef */
        TS_MAKENULLREF2CFG, /* ComFilter8BitMaskRef */
        TS_MAKENULLREF2CFG, /* ComFilter16BitMaskRef */
        TS_MAKENULLREF2CFG, /* ComFilter32BitMaskRef */
        TS_MAKENULLREF2CFG, /* ComFilter8BitMaskXMinMaxRef */
        TS_MAKENULLREF2CFG, /* ComFilter16BitMaskXMinMaxRef */
        TS_MAKENULLREF2CFG, /* ComFilter32BitMaskXMinMaxRef */
        TS_MAKENULLREF2CFG, /* ComFilterOneEveryNRef */
        TS_MAKEREF2CFG( ComRxSignal[0] ), /* ComRxSignalRef */
        TS_MAKEREF2CFG( ComRxSignalExt[0] ), /* ComRxSignalExtRef */
        TS_MAKEREF2CFG( ComTxSignal[0] ), /* ComTxSignalRef */
        TS_MAKENULLREF2CFG, /* ComRxTimeoutNotificationRef */
        TS_MAKENULLREF2CFG, /* ComTxTimeoutNotificationRef */
        TS_MAKENULLREF2CFG, /* ComTxErrorNotificationRef */
        TS_MAKENULLREF2CFG, /* ComTxNotificationRef */
        TS_MAKENULLREF2CFG, /* ComGWSourceRef */
        TS_MAKENULLREF2CFG, /* ComGWDestinationRef */
        TS_MAKEREF2CFG( ComMainfunctionsRx[0] ), /* ComMainfunctionRxRef */
        TS_MAKEREF2CFG( ComMainfunctionsTx[0] ), /* ComMainfunctionTxRef */
        UINT16_C( 0 ), /* ComSigGWTxSignalGroupQueueMax */
        UINT16_C( 0 ), /* ComMDTQueueMax */
        UINT16_C( 2 ), /* ComPeriodicQueueMax */
        UINT16_C( 0 ), /* ComNTimesQueueMax */
        UINT16_C( 0 ), /* ComRxTimeoutQueueMax */
        UINT16_C( 0 ), /* ComRxTimeoutSignalQueueBase */
        UINT16_C( 0 ), /* ComRxTimeoutSignalQueueMax */
        UINT16_C( 0 ), /* ComRxTimeoutSignalGroupQueueMax */
        UINT16_C( 0 ), /* ComTxTimeoutQueueMax */
        UINT16_C( 0 ), /* ComCbkTxAckDeferredListMax */
        UINT16_C( 6 ), /* ComRxIPduArraySize */
        UINT16_C( 2 ), /* ComTxIPduArraySize */
        UINT16_C( 8 ), /* ComRxSignalArraySize */
        UINT16_C( 3 ), /* ComTxSignalArraySize */
        UINT16_C( 0 ), /* ComFilterOneEveryNArraySize */
        UINT16_C( 0 ), /* ComIPduGroupsNum */
        UINT16_C( 0 ), /* ComSigGWRxIPduArraySize */
        UINT16_C( 0 ), /* ComTxSignalGroupArraySize */
        UINT16_C( 0 ) /* ComRxSignalGroupArraySize */
    },
    { /* ComRxIPdu */
        { /* ComRxIPdu[0] -- ComIPdu_Radar_Left */
            UINT32_C( 2147483648 ), /* ComIPduGroupMask */
            TS_MAKEREF2CFG( ComIPduInit[0] ), /* ComInitValueRef */
            UINT32_C( 20 ), /* ComIPduValueRef */
            TS_MAKEREF2CFG( ComIPduInit[0] ), /* ComTimeoutValueRef */
            UINT16_C( 8 ), /* ComIPduInitSize */
            UINT16_C( 8 ), /* ComIPduSizeMax */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 2 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithBufferRefNum */
            UINT16_C( 0 ), /* ComIPduSignalW_F_A_NotiRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithDMOnly */
            UINT16_C( 0 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 0 ), /* ComRxTimeoutNotificationFirst */
            UINT16_C( 0 ), /* ComRxTimeoutNotificationNum */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxDMQueueRef */
            UINT16_C( 65535 ), /* ComIPduSigGWFlagBit */
            UINT16_C( 0 ), /* ComIPduGWSourceRefNum */
            UINT16_C( 0 ), /* ComIPduGWSourceRefFirst */
            UINT16_C( 8 ), /* ComIPduTimeoutSize */
            UINT8_C( 1 ), /* ComRxIPduFlags -- COM_DYN_IPDU_OFF | COM_RX_DM_OFF | IMMEDIATE */
            UINT8_C( 0 ) /* Com_MainID_Rx */
        },
        { /* ComRxIPdu[1] -- ComIPdu_Radar_Right */
            UINT32_C( 2147483648 ), /* ComIPduGroupMask */
            TS_MAKEREF2CFG( ComIPduInit[0] ), /* ComInitValueRef */
            UINT32_C( 28 ), /* ComIPduValueRef */
            TS_MAKEREF2CFG( ComIPduInit[0] ), /* ComTimeoutValueRef */
            UINT16_C( 8 ), /* ComIPduInitSize */
            UINT16_C( 8 ), /* ComIPduSizeMax */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 2 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithBufferRefNum */
            UINT16_C( 0 ), /* ComIPduSignalW_F_A_NotiRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithDMOnly */
            UINT16_C( 2 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 0 ), /* ComRxTimeoutNotificationFirst */
            UINT16_C( 0 ), /* ComRxTimeoutNotificationNum */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxDMQueueRef */
            UINT16_C( 65535 ), /* ComIPduSigGWFlagBit */
            UINT16_C( 0 ), /* ComIPduGWSourceRefNum */
            UINT16_C( 0 ), /* ComIPduGWSourceRefFirst */
            UINT16_C( 8 ), /* ComIPduTimeoutSize */
            UINT8_C( 1 ), /* ComRxIPduFlags -- COM_DYN_IPDU_OFF | COM_RX_DM_OFF | IMMEDIATE */
            UINT8_C( 0 ) /* Com_MainID_Rx */
        },
        { /* ComRxIPdu[2] -- ComIPdu_Speed */
            UINT32_C( 2147483648 ), /* ComIPduGroupMask */
            TS_MAKEREF2CFG( ComIPduInit[6] ), /* ComInitValueRef */
            UINT32_C( 36 ), /* ComIPduValueRef */
            TS_MAKEREF2CFG( ComIPduInit[6] ), /* ComTimeoutValueRef */
            UINT16_C( 2 ), /* ComIPduInitSize */
            UINT16_C( 2 ), /* ComIPduSizeMax */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 1 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithBufferRefNum */
            UINT16_C( 0 ), /* ComIPduSignalW_F_A_NotiRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithDMOnly */
            UINT16_C( 4 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 0 ), /* ComRxTimeoutNotificationFirst */
            UINT16_C( 0 ), /* ComRxTimeoutNotificationNum */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxDMQueueRef */
            UINT16_C( 65535 ), /* ComIPduSigGWFlagBit */
            UINT16_C( 0 ), /* ComIPduGWSourceRefNum */
            UINT16_C( 0 ), /* ComIPduGWSourceRefFirst */
            UINT16_C( 2 ), /* ComIPduTimeoutSize */
            UINT8_C( 1 ), /* ComRxIPduFlags -- COM_DYN_IPDU_OFF | COM_RX_DM_OFF | IMMEDIATE */
            UINT8_C( 0 ) /* Com_MainID_Rx */
        },
        { /* ComRxIPdu[3] -- ComIPdu_TurnSignal */
            UINT32_C( 2147483648 ), /* ComIPduGroupMask */
            TS_MAKEREF2CFG( ComIPduInit[7] ), /* ComInitValueRef */
            UINT32_C( 38 ), /* ComIPduValueRef */
            TS_MAKEREF2CFG( ComIPduInit[7] ), /* ComTimeoutValueRef */
            UINT16_C( 1 ), /* ComIPduInitSize */
            UINT16_C( 1 ), /* ComIPduSizeMax */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 1 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithBufferRefNum */
            UINT16_C( 0 ), /* ComIPduSignalW_F_A_NotiRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithDMOnly */
            UINT16_C( 5 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 0 ), /* ComRxTimeoutNotificationFirst */
            UINT16_C( 0 ), /* ComRxTimeoutNotificationNum */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxDMQueueRef */
            UINT16_C( 65535 ), /* ComIPduSigGWFlagBit */
            UINT16_C( 0 ), /* ComIPduGWSourceRefNum */
            UINT16_C( 0 ), /* ComIPduGWSourceRefFirst */
            UINT16_C( 1 ), /* ComIPduTimeoutSize */
            UINT8_C( 1 ), /* ComRxIPduFlags -- COM_DYN_IPDU_OFF | COM_RX_DM_OFF | IMMEDIATE */
            UINT8_C( 0 ) /* Com_MainID_Rx */
        },
        { /* ComRxIPdu[4] -- ComIPdu_Steering */
            UINT32_C( 2147483648 ), /* ComIPduGroupMask */
            TS_MAKEREF2CFG( ComIPduInit[6] ), /* ComInitValueRef */
            UINT32_C( 39 ), /* ComIPduValueRef */
            TS_MAKEREF2CFG( ComIPduInit[6] ), /* ComTimeoutValueRef */
            UINT16_C( 2 ), /* ComIPduInitSize */
            UINT16_C( 2 ), /* ComIPduSizeMax */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 1 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithBufferRefNum */
            UINT16_C( 0 ), /* ComIPduSignalW_F_A_NotiRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithDMOnly */
            UINT16_C( 6 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 0 ), /* ComRxTimeoutNotificationFirst */
            UINT16_C( 0 ), /* ComRxTimeoutNotificationNum */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxDMQueueRef */
            UINT16_C( 65535 ), /* ComIPduSigGWFlagBit */
            UINT16_C( 0 ), /* ComIPduGWSourceRefNum */
            UINT16_C( 0 ), /* ComIPduGWSourceRefFirst */
            UINT16_C( 2 ), /* ComIPduTimeoutSize */
            UINT8_C( 1 ), /* ComRxIPduFlags -- COM_DYN_IPDU_OFF | COM_RX_DM_OFF | IMMEDIATE */
            UINT8_C( 0 ) /* Com_MainID_Rx */
        },
        { /* ComRxIPdu[5] -- ComIPdu_Gear */
            UINT32_C( 2147483648 ), /* ComIPduGroupMask */
            TS_MAKEREF2CFG( ComIPduInit[7] ), /* ComInitValueRef */
            UINT32_C( 41 ), /* ComIPduValueRef */
            TS_MAKEREF2CFG( ComIPduInit[7] ), /* ComTimeoutValueRef */
            UINT16_C( 1 ), /* ComIPduInitSize */
            UINT16_C( 1 ), /* ComIPduSizeMax */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 1 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithBufferRefNum */
            UINT16_C( 0 ), /* ComIPduSignalW_F_A_NotiRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithDMOnly */
            UINT16_C( 7 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 0 ), /* ComRxTimeoutNotificationFirst */
            UINT16_C( 0 ), /* ComRxTimeoutNotificationNum */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxDMQueueRef */
            UINT16_C( 65535 ), /* ComIPduSigGWFlagBit */
            UINT16_C( 0 ), /* ComIPduGWSourceRefNum */
            UINT16_C( 0 ), /* ComIPduGWSourceRefFirst */
            UINT16_C( 1 ), /* ComIPduTimeoutSize */
            UINT8_C( 1 ), /* ComRxIPduFlags -- COM_DYN_IPDU_OFF | COM_RX_DM_OFF | IMMEDIATE */
            UINT8_C( 0 ) /* Com_MainID_Rx */
        }
    },
    { /* ComTxIPdu */
        { /* ComTxIPdu[0] -- ComIPdu_LED_Tx */
            UINT32_C( 2147483648 ), /* ComIPduGroupMask */
            TS_MAKEREF2CFG( ComIPduInit[6] ), /* ComInitValueRef */
            UINT32_C( 42 ), /* ComIPduValueRef */
            UINT32_C( 0 ), /* ComIPduTMSFlagsRef */
            TS_MAKENULLREF2CFG, /* ComIPduTMSFlagsInitValueRef */
            UINT16_C( 2 ), /* ComIPduInitSize */
            UINT16_C( 2 ), /* ComIPduSizeMax */
            UINT16_C( 1 ), /* PduRTxPduId */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 1 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithFilterRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupWithFilterRefNum */
            UINT16_C( 0 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 65535 ), /* ComIPduTrigTxCallOutFuncPtrRef */
            UINT16_C( 0 ), /* ComTxIPduMinimumDelayTimeFactorValue */
            UINT16_C( 65535 ), /* MDTQueueRef */
            UINT16_C( 0 ), /* ComTxModeTrueRef */
            UINT16_C( 65535 ), /* ComTxModeFalseRef */
            UINT16_C( 0 ), /* PeriodicQueueRef */
            UINT16_C( 0 ), /* NTimesQueueRef */
            UINT16_C( 0 ), /* ComTxTimeoutNotificationFirst */
            UINT16_C( 0 ), /* ComTxTimeoutNotificationNum */
            UINT16_C( 0 ), /* ComTxTimeoutFactorValue */
            UINT16_C( 65535 ), /* TxDMQueueRef */
            UINT16_C( 0 ), /* ComNotificationFirst */
            UINT16_C( 0 ), /* ComNotificationNum */
            UINT16_C( 0 ), /* ComNotificationDeferredQueueRef */
            UINT8_C( 29 ), /* ComTxIPduFlags -- COM_DYN_IPDU_OFF | COM_CL_UB_NEVER | TM_TRUE | COM_TX_DM_OFF | IMMEDIATE */
            UINT8_C( 1 ), /* ComTxModeModes -- True=PERIODIC,False=<undef> */
            UINT8_C( 0 ) /* Com_MainID_Tx */
        },
        { /* ComTxIPdu[1] -- ComIPdu_Warning_Tx */
            UINT32_C( 2147483648 ), /* ComIPduGroupMask */
            TS_MAKEREF2CFG( ComIPduInit[6] ), /* ComInitValueRef */
            UINT32_C( 44 ), /* ComIPduValueRef */
            UINT32_C( 0 ), /* ComIPduTMSFlagsRef */
            TS_MAKENULLREF2CFG, /* ComIPduTMSFlagsInitValueRef */
            UINT16_C( 2 ), /* ComIPduInitSize */
            UINT16_C( 2 ), /* ComIPduSizeMax */
            UINT16_C( 0 ), /* PduRTxPduId */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 2 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithFilterRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupWithFilterRefNum */
            UINT16_C( 1 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 65535 ), /* ComIPduTrigTxCallOutFuncPtrRef */
            UINT16_C( 0 ), /* ComTxIPduMinimumDelayTimeFactorValue */
            UINT16_C( 65535 ), /* MDTQueueRef */
            UINT16_C( 0 ), /* ComTxModeTrueRef */
            UINT16_C( 65535 ), /* ComTxModeFalseRef */
            UINT16_C( 1 ), /* PeriodicQueueRef */
            UINT16_C( 0 ), /* NTimesQueueRef */
            UINT16_C( 0 ), /* ComTxTimeoutNotificationFirst */
            UINT16_C( 0 ), /* ComTxTimeoutNotificationNum */
            UINT16_C( 0 ), /* ComTxTimeoutFactorValue */
            UINT16_C( 65535 ), /* TxDMQueueRef */
            UINT16_C( 0 ), /* ComNotificationFirst */
            UINT16_C( 0 ), /* ComNotificationNum */
            UINT16_C( 0 ), /* ComNotificationDeferredQueueRef */
            UINT8_C( 29 ), /* ComTxIPduFlags -- COM_DYN_IPDU_OFF | COM_CL_UB_NEVER | TM_TRUE | COM_TX_DM_OFF | IMMEDIATE */
            UINT8_C( 1 ), /* ComTxModeModes -- True=PERIODIC,False=<undef> */
            UINT8_C( 0 ) /* Com_MainID_Tx */
        }
    },
    { /* ComIPduGroup */
        { /* ComIPduGroup[0] -- COM_DUMMY */
            TS_MAKEREF2CFG( ComMainfunctionTxPduIDs[0] ), /* ComMainPduIDListRef */
            UINT16_C( 0 ), /* ComMainPduIDListSize */
            UINT16_C( 0 ) /* ComIPduGroupFlags -- Binary: 0000 0000 0000 0000 | ComMainID | SEND | IPdu Loops | Not used bit | ComIPduGroupVectorBitPos */
        }
    },
    { /* ComRxSignal */
        { /* ComRxSignal[0] -- S_Radar_Left_Distance */
            { /* ComSignalBase */
                UINT32_C( 20 ), /* ComBufferRef */
                UINT16_C( 523 ), /* ComRxSignalFlags -- UINT16 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 0 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 0 ), /* ComSignalExtRef */
            UINT16_C( 0 ), /* ComIPduRef */
            UINT8_C( 0 ) /* Com_MainID_Rx */
        },
        { /* ComRxSignal[1] -- S_Radar_Left_ObjectDetected */
            { /* ComSignalBase */
                UINT32_C( 20 ), /* ComBufferRef */
                UINT16_C( 809 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_EL */
                UINT16_C( 2 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 1 ), /* ComSignalExtRef */
            UINT16_C( 0 ), /* ComIPduRef */
            UINT8_C( 0 ) /* Com_MainID_Rx */
        },
        { /* ComRxSignal[2] -- S_Radar_Right_Distance */
            { /* ComSignalBase */
                UINT32_C( 28 ), /* ComBufferRef */
                UINT16_C( 523 ), /* ComRxSignalFlags -- UINT16 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 0 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 2 ), /* ComSignalExtRef */
            UINT16_C( 1 ), /* ComIPduRef */
            UINT8_C( 0 ) /* Com_MainID_Rx */
        },
        { /* ComRxSignal[3] -- S_Radar_Right_ObjectDetected */
            { /* ComSignalBase */
                UINT32_C( 28 ), /* ComBufferRef */
                UINT16_C( 809 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_EL */
                UINT16_C( 2 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 3 ), /* ComSignalExtRef */
            UINT16_C( 1 ), /* ComIPduRef */
            UINT8_C( 0 ) /* Com_MainID_Rx */
        },
        { /* ComRxSignal[4] -- S_Vehicle_Speed */
            { /* ComSignalBase */
                UINT32_C( 36 ), /* ComBufferRef */
                UINT16_C( 523 ), /* ComRxSignalFlags -- UINT16 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 0 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 4 ), /* ComSignalExtRef */
            UINT16_C( 2 ), /* ComIPduRef */
            UINT8_C( 0 ) /* Com_MainID_Rx */
        },
        { /* ComRxSignal[5] -- S_TurnSignal_State */
            { /* ComSignalBase */
                UINT32_C( 38 ), /* ComBufferRef */
                UINT16_C( 809 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_EL */
                UINT16_C( 0 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 5 ), /* ComSignalExtRef */
            UINT16_C( 3 ), /* ComIPduRef */
            UINT8_C( 0 ) /* Com_MainID_Rx */
        },
        { /* ComRxSignal[6] -- S_Steering_Angle */
            { /* ComSignalBase */
                UINT32_C( 39 ), /* ComBufferRef */
                UINT16_C( 139 ), /* ComRxSignalFlags -- SINT16 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 0 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 6 ), /* ComSignalExtRef */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT8_C( 0 ) /* Com_MainID_Rx */
        },
        { /* ComRxSignal[7] -- S_Current_Gear */
            { /* ComSignalBase */
                UINT32_C( 41 ), /* ComBufferRef */
                UINT16_C( 809 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_EL */
                UINT16_C( 0 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 7 ), /* ComSignalExtRef */
            UINT16_C( 5 ), /* ComIPduRef */
            UINT8_C( 0 ) /* Com_MainID_Rx */
        }
    },
    { /* ComTxSignal */
        { /* ComTxSignal[0] -- S_Warning_State */
            { /* ComSignalBase */
                UINT32_C( 44 ), /* ComBufferRef */
                UINT16_C( 809 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_EL */
                UINT16_C( 0 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 26049 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Write_A1_EL_DUB_DOC */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 0 ), /* ComSignalPositionInBit */
            UINT16_C( 1 ), /* ComIPduRef */
            UINT16_C( 0 ), /* ComPositionOfTMSFlag */
            UINT8_C( 0 ) /* Com_MainID_Tx */
        },
        { /* ComTxSignal[1] -- S_Buzzer_Frequency */
            { /* ComSignalBase */
                UINT32_C( 44 ), /* ComBufferRef */
                UINT16_C( 809 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_EL */
                UINT16_C( 1 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 26049 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Write_A1_EL_DUB_DOC */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 1 ), /* ComSignalPositionInBit */
            UINT16_C( 1 ), /* ComIPduRef */
            UINT16_C( 0 ), /* ComPositionOfTMSFlag */
            UINT8_C( 0 ) /* Com_MainID_Tx */
        },
        { /* ComTxSignal[2] -- S_LED_Intensity */
            { /* ComSignalBase */
                UINT32_C( 42 ), /* ComBufferRef */
                UINT16_C( 809 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_EL */
                UINT16_C( 0 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 26049 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Write_A1_EL_DUB_DOC */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 0 ), /* ComSignalPositionInBit */
            UINT16_C( 0 ), /* ComIPduRef */
            UINT16_C( 0 ), /* ComPositionOfTMSFlag */
            UINT8_C( 0 ) /* Com_MainID_Tx */
        }
    },
    { /* ComMainfunctionsRx */
        { /* ComMainfunctionsRx[0] -- ComMainFunctionRx */
            TS_MAKEREF2CFG( ComMainfunctionRxPduIDs[0] ), /* ComMainPduIDListRef */
            UINT16_C( 6 ) /* ComMainPduIDListSize */
        },
        { /* ComMainfunctionsRx[1] -- COM_DUMMY */
            TS_MAKENULLREF2CFG, /* ComMainPduIDListRef */
            UINT16_C( 0 ) /* ComMainPduIDListSize */
        },
        { /* ComMainfunctionsRx[2] -- COM_DUMMY */
            TS_MAKENULLREF2CFG, /* ComMainPduIDListRef */
            UINT16_C( 0 ) /* ComMainPduIDListSize */
        },
        { /* ComMainfunctionsRx[3] -- COM_DUMMY */
            TS_MAKENULLREF2CFG, /* ComMainPduIDListRef */
            UINT16_C( 0 ) /* ComMainPduIDListSize */
        }
    },
    { /* ComMainfunctionsTx */
        { /* ComMainfunctionsTx[0] -- ComMainFunctionTx */
            TS_MAKEREF2CFG( ComMainfunctionTxPduIDs[0] ), /* ComMainPduIDListRef */
            UINT16_C( 2 ) /* ComMainPduIDListSize */
        },
        { /* ComMainfunctionsTx[1] -- COM_DUMMY */
            TS_MAKENULLREF2CFG, /* ComMainPduIDListRef */
            UINT16_C( 0 ) /* ComMainPduIDListSize */
        },
        { /* ComMainfunctionsTx[2] -- COM_DUMMY */
            TS_MAKENULLREF2CFG, /* ComMainPduIDListRef */
            UINT16_C( 0 ) /* ComMainPduIDListSize */
        },
        { /* ComMainfunctionsTx[3] -- COM_DUMMY */
            TS_MAKENULLREF2CFG, /* ComMainPduIDListRef */
            UINT16_C( 0 ) /* ComMainPduIDListSize */
        }
    },
    { /* ComTxModePeriodic */
        { /* ComTxModePeriodic[0] */
            UINT16_C( 20 ), /* ComTxModeTimeOffsetFactor */
            UINT16_C( 20 ) /* ComTxModeTimePeriodFactor */
        }
    },
    { /* ComRxIPduSignalList */
        UINT16_C( 0 ), /* ComRxIPduSignalList[0] */
        UINT16_C( 1 ), /* ComRxIPduSignalList[1] */
        UINT16_C( 2 ), /* ComRxIPduSignalList[2] */
        UINT16_C( 3 ), /* ComRxIPduSignalList[3] */
        UINT16_C( 4 ), /* ComRxIPduSignalList[4] */
        UINT16_C( 5 ), /* ComRxIPduSignalList[5] */
        UINT16_C( 6 ), /* ComRxIPduSignalList[6] */
        UINT16_C( 7 ) /* ComRxIPduSignalList[7] */
    },
    { /* ComTxIPduSignalList */
        UINT16_C( 2 ), /* ComTxIPduSignalList[0] */
        UINT16_C( 0 ), /* ComTxIPduSignalList[1] */
        UINT16_C( 1 ) /* ComTxIPduSignalList[2] */
    },
    { /* ComRxSignalExt */
        { /* ComRxSignalExt[0] -- S_Radar_Left_Distance */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 0 ) /* ComRxSignalExtFlags -- COM_RX_DM_OFF | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[1] -- S_Radar_Left_ObjectDetected */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 0 ) /* ComRxSignalExtFlags -- COM_RX_DM_OFF | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[2] -- S_Radar_Right_Distance */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 0 ) /* ComRxSignalExtFlags -- COM_RX_DM_OFF | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[3] -- S_Radar_Right_ObjectDetected */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 0 ) /* ComRxSignalExtFlags -- COM_RX_DM_OFF | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[4] -- S_Vehicle_Speed */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 0 ) /* ComRxSignalExtFlags -- COM_RX_DM_OFF | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[5] -- S_TurnSignal_State */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 0 ) /* ComRxSignalExtFlags -- COM_RX_DM_OFF | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[6] -- S_Steering_Angle */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 0 ) /* ComRxSignalExtFlags -- COM_RX_DM_OFF | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[7] -- S_Current_Gear */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 0 ) /* ComRxSignalExtFlags -- COM_RX_DM_OFF | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        }
    },
    { /* ComPeriodicQueueList */
        UINT16_C( 0 ), /* ComPeriodicQueueList[0] */
        UINT16_C( 1 ) /* ComPeriodicQueueList[1] */
    },
    { /* ComMainfunctionRxPduIDs */
        UINT16_C( 0 ), /* ComMainfunctionRxPduIDs[0] -- ComMainFunctionRx */
        UINT16_C( 1 ), /* ComMainfunctionRxPduIDs[1] */
        UINT16_C( 2 ), /* ComMainfunctionRxPduIDs[2] */
        UINT16_C( 3 ), /* ComMainfunctionRxPduIDs[3] */
        UINT16_C( 4 ), /* ComMainfunctionRxPduIDs[4] */
        UINT16_C( 5 ) /* ComMainfunctionRxPduIDs[5] */
    },
    { /* ComMainfunctionTxPduIDs */
        UINT16_C( 0 ), /* ComMainfunctionTxPduIDs[0] -- ComMainFunctionTx */
        UINT16_C( 1 ) /* ComMainfunctionTxPduIDs[1] */
    },
    { /* ComIPduInit */
        UINT8_C( 0 ), /* ComIPduInit[0] */
        UINT8_C( 0 ), /* ComIPduInit[1] */
        UINT8_C( 0 ), /* ComIPduInit[2] */
        UINT8_C( 0 ), /* ComIPduInit[3] */
        UINT8_C( 0 ), /* ComIPduInit[4] */
        UINT8_C( 0 ), /* ComIPduInit[5] */
        UINT8_C( 0 ), /* ComIPduInit[6] */
        UINT8_C( 0 ) /* ComIPduInit[7] */
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3, MISRAC2012-4 <STOP> */

#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <Com_MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

