


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

#ifndef COM_TYPES_H
#define COM_TYPES_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS COM_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/

typedef VAR( uint16, TYPEDEF ) ComSignalGroupRefType;

typedef VAR( uint16, TYPEDEF ) ComFilterRefType;

typedef VAR( uint16, TYPEDEF ) ComSignalRefType;

typedef VAR( uint16, TYPEDEF ) ComIPduRefType;

typedef VAR( uint16, TYPEDEF ) Com_CbkRxTOutIdxType;

typedef struct /* ComGWDestinationType */ {
    TS_REF2CFG( uint8 )  ComGWDestinationRef;
    VAR( uint8, TYPEDEF ) ComGWDestinationSelect;
} ComGWDestinationType;

typedef VAR( uint16, TYPEDEF ) ComGWDestinationRefType;

typedef VAR( uint16, TYPEDEF ) Com_CbkTxAckIdxType;

typedef VAR( uint16, TYPEDEF ) Com_CbkTxTOutIdxType;

typedef VAR( uint8, TYPEDEF ) ComMainIDType;

typedef VAR( uint16, TYPEDEF ) ComTMSFlagsRefType;

typedef VAR( uint16, TYPEDEF ) ComSignalDescBitType;

typedef VAR( uint16, TYPEDEF ) ComSignalBufferRefType;

typedef VAR( uint16, TYPEDEF ) ComSignalBitSizeType;

typedef VAR( uint32, TYPEDEF ) ComRAMIdxType;

typedef VAR( uint16, TYPEDEF ) ComRxFirstTimeoutFactorType;

typedef VAR( uint16, TYPEDEF ) ComRxTimeoutFactorType;

typedef VAR( uint16, TYPEDEF ) Com_CbkRxAckIdxType;

typedef VAR( uint16, TYPEDEF ) ComFilterOneEveryNSizeType;

typedef struct /* ComFilter32BitMaskXMinMaxType */ {
    VAR( uint32, TYPEDEF ) ComFilterMaskOrMin;
    VAR( uint32, TYPEDEF ) ComFilterXOrMax;
} ComFilter32BitMaskXMinMaxType;

typedef struct /* ComFilter16BitMaskXMinMaxType */ {
    VAR( uint16, TYPEDEF ) ComFilterMaskOrMin;
    VAR( uint16, TYPEDEF ) ComFilterXOrMax;
} ComFilter16BitMaskXMinMaxType;

typedef struct /* ComFilter8BitMaskXMinMaxType */ {
    VAR( uint8, TYPEDEF ) ComFilterMaskOrMin;
    VAR( uint8, TYPEDEF ) ComFilterXOrMax;
} ComFilter8BitMaskXMinMaxType;

typedef VAR( uint32, TYPEDEF ) ComFilter32BitMaskType;

typedef VAR( uint16, TYPEDEF ) ComFilter16BitMaskType;

typedef VAR( uint8, TYPEDEF ) ComFilter8BitMaskType;

typedef VAR( uint16, TYPEDEF ) ComRxGroupSignalRefType;

typedef VAR( uint16, TYPEDEF ) ComSignalDescByteType;

typedef VAR( uint16, TYPEDEF ) ComIPduGroupFlagType;

typedef VAR( uint16, TYPEDEF ) ComTxModeTimePeriodFactorType;

typedef VAR( uint16, TYPEDEF ) ComTxModeTimeOffsetFactorType;

typedef VAR( uint16, TYPEDEF ) ComTxModeRepetitionPeriodFactorType;

typedef VAR( uint16, TYPEDEF ) ComTxTimeoutFactorType;

typedef VAR( uint16, TYPEDEF ) ComTxModeIdxType;

typedef VAR( uint16, TYPEDEF ) ComTxIPduMinimumDelayTimeFactorType;

typedef VAR( uint16, TYPEDEF ) Com_CallOutFuncPtrRefType;

typedef VAR( uint16, TYPEDEF ) ComIPduSizeType;

typedef VAR( uint32, TYPEDEF ) ComIPduGroupMaskType;

typedef VAR( uint16, TYPEDEF ) ComGWSourceRefType;

typedef struct /* ComMainfunctionTxType */ {
    TS_REF2CFG( ComIPduRefType )  ComMainPduIDListRef;
    VAR( ComIPduRefType, TYPEDEF ) ComMainPduIDListSize;
} ComMainfunctionTxType;

typedef struct /* ComMainfunctionRxType */ {
    TS_REF2CFG( ComIPduRefType )  ComMainPduIDListRef;
    VAR( ComIPduRefType, TYPEDEF ) ComMainPduIDListSize;
} ComMainfunctionRxType;

typedef struct /* ComGWSourceType */ {
    TS_REF2CFG( uint8 )  ComGWSourceRef;
    VAR( ComGWDestinationRefType, TYPEDEF ) ComGWDestinationNumRef;
    VAR( ComGWDestinationRefType, TYPEDEF ) ComGWDestinationFirstRef;
    VAR( uint8, TYPEDEF ) ComGWSourceSelect;
} ComGWSourceType;

typedef struct /* ComFilterConfType */ {
    VAR( ComFilterRefType, TYPEDEF ) ComFilterRef;
    VAR( ComSignalBufferRefType, TYPEDEF ) ComFilterSignalValueRef;
    VAR( uint8, TYPEDEF ) ComFilterType;
} ComFilterConfType;

typedef struct /* ComRxSignalExtType */ {
    VAR( Com_CbkRxAckIdxType, TYPEDEF ) ComNotification;
    VAR( ComRxTimeoutFactorType, TYPEDEF ) ComRxTimeoutFactorValue;
    VAR( ComRxFirstTimeoutFactorType, TYPEDEF ) ComRxFirstTimeoutFactorValue;
    VAR( ComSignalRefType, TYPEDEF ) RxSigDMQueueRef;
    VAR( Com_CbkRxTOutIdxType, TYPEDEF ) ComRxTimeoutNotification;
    VAR( ComSignalDescBitType, TYPEDEF ) ComUpdateBitPositionInBit;
    VAR( uint8, TYPEDEF ) ComRxSignalExtFlags;
} ComRxSignalExtType;

typedef struct /* ComFilterOneEveryNType */ {
    VAR( ComFilterOneEveryNSizeType, TYPEDEF ) ComFilterPeriodFactor;
    VAR( ComFilterOneEveryNSizeType, TYPEDEF ) ComFilterOffset;
    VAR( ComFilterRefType, TYPEDEF ) ComFilterOccurrence;
} ComFilterOneEveryNType;

typedef VAR( ComRxGroupSignalRefType, TYPEDEF ) ComTxGroupSignalRefType;

typedef struct /* ComRxSignalGroupType */ {
    VAR( ComRAMIdxType, TYPEDEF ) ComSignalGroupValueRef;
    VAR( ComIPduRefType, TYPEDEF ) ComIPduRef;
    VAR( ComSignalDescByteType, TYPEDEF ) ComSignalPositionInByte;
    VAR( ComSignalDescByteType, TYPEDEF ) ComByteSize;
    VAR( ComSignalRefType, TYPEDEF ) ComSignalExtRef;
    VAR( ComMainIDType, TYPEDEF ) Com_MainID_Rx;
} ComRxSignalGroupType;

typedef struct /* ComIPduGroupType */ {
    TS_REF2CFG( ComIPduRefType )  ComMainPduIDListRef;
    VAR( ComIPduRefType, TYPEDEF ) ComMainPduIDListSize;
    VAR( ComIPduGroupFlagType, TYPEDEF ) ComIPduGroupFlags;
} ComIPduGroupType;

typedef struct /* ComTxModeMixedNTimesType */ {
    VAR( ComTxModeRepetitionPeriodFactorType, TYPEDEF ) ComTxModeRepetitionPeriodFactor;
    VAR( ComTxModeTimeOffsetFactorType, TYPEDEF ) ComTxModeTimeOffsetFactor;
    VAR( ComTxModeTimePeriodFactorType, TYPEDEF ) ComTxModeTimePeriodFactor;
    VAR( uint8, TYPEDEF ) ComTxModeNumberOfRepetitions;
} ComTxModeMixedNTimesType;

typedef struct /* ComTxModePeriodicType */ {
    VAR( ComTxModeTimeOffsetFactorType, TYPEDEF ) ComTxModeTimeOffsetFactor;
    VAR( ComTxModeTimePeriodFactorType, TYPEDEF ) ComTxModeTimePeriodFactor;
} ComTxModePeriodicType;

typedef struct /* ComTxModeNTimesType */ {
    VAR( ComTxModeRepetitionPeriodFactorType, TYPEDEF ) ComTxModeRepetitionPeriodFactor;
    VAR( uint8, TYPEDEF ) ComTxModeNumberOfRepetitions;
} ComTxModeNTimesType;

typedef struct /* AbstractIPduType */ {
    VAR( ComIPduGroupMaskType, TYPEDEF ) ComIPduGroupMask;
    TS_REF2CFG( uint8 )  ComInitValueRef;
    VAR( ComIPduSizeType, TYPEDEF ) ComIPduInitSize;
    VAR( ComIPduSizeType, TYPEDEF ) ComIPduSizeMax;
} AbstractIPduType;

typedef struct /* ComTxIPduType */ {
    VAR( ComIPduGroupMaskType, TYPEDEF ) ComIPduGroupMask;
    TS_REF2CFG( uint8 )  ComInitValueRef;
    VAR( ComRAMIdxType, TYPEDEF ) ComIPduValueRef;
    VAR( ComRAMIdxType, TYPEDEF ) ComIPduTMSFlagsRef;
    TS_REF2CFG( uint8 )  ComIPduTMSFlagsInitValueRef;
    VAR( ComIPduSizeType, TYPEDEF ) ComIPduInitSize;
    VAR( ComIPduSizeType, TYPEDEF ) ComIPduSizeMax;
    VAR( ComIPduRefType, TYPEDEF ) PduRTxPduId;
    VAR( ComSignalGroupRefType, TYPEDEF ) ComIPduSignalGroupRefNum;
    VAR( ComSignalGroupRefType, TYPEDEF ) ComIPduSignalGroupRefFirst;
    VAR( ComSignalRefType, TYPEDEF ) ComIPduSignalRefNum;
    VAR( ComTMSFlagsRefType, TYPEDEF ) ComIPduSignalWithFilterRefNum;
    VAR( ComTMSFlagsRefType, TYPEDEF ) ComIPduSignalGroupWithFilterRefNum;
    VAR( ComSignalRefType, TYPEDEF ) ComIPduSignalRefFirst;
    VAR( Com_CallOutFuncPtrRefType, TYPEDEF ) ComIPduCallOutFuncPtrRef;
    VAR( Com_CallOutFuncPtrRefType, TYPEDEF ) ComIPduTrigTxCallOutFuncPtrRef;
    VAR( ComTxIPduMinimumDelayTimeFactorType, TYPEDEF ) ComTxIPduMinimumDelayTimeFactorValue;
    VAR( ComIPduRefType, TYPEDEF ) MDTQueueRef;
    VAR( ComTxModeIdxType, TYPEDEF ) ComTxModeTrueRef;
    VAR( ComTxModeIdxType, TYPEDEF ) ComTxModeFalseRef;
    VAR( ComIPduRefType, TYPEDEF ) PeriodicQueueRef;
    VAR( ComIPduRefType, TYPEDEF ) NTimesQueueRef;
    VAR( Com_CbkTxTOutIdxType, TYPEDEF ) ComTxTimeoutNotificationFirst;
    VAR( Com_CbkTxTOutIdxType, TYPEDEF ) ComTxTimeoutNotificationNum;
    VAR( ComTxTimeoutFactorType, TYPEDEF ) ComTxTimeoutFactorValue;
    VAR( ComIPduRefType, TYPEDEF ) TxDMQueueRef;
    VAR( Com_CbkTxAckIdxType, TYPEDEF ) ComNotificationFirst;
    VAR( Com_CbkTxAckIdxType, TYPEDEF ) ComNotificationNum;
    VAR( ComIPduRefType, TYPEDEF ) ComNotificationDeferredQueueRef;
    VAR( uint8, TYPEDEF ) ComTxIPduFlags;
    VAR( uint8, TYPEDEF ) ComTxModeModes;
    VAR( ComMainIDType, TYPEDEF ) Com_MainID_Tx;
} ComTxIPduType;

typedef struct /* ComRxIPduType */ {
    VAR( ComIPduGroupMaskType, TYPEDEF ) ComIPduGroupMask;
    TS_REF2CFG( uint8 )  ComInitValueRef;
    VAR( ComRAMIdxType, TYPEDEF ) ComIPduValueRef;
    TS_REF2CFG( uint8 )  ComTimeoutValueRef;
    VAR( ComIPduSizeType, TYPEDEF ) ComIPduInitSize;
    VAR( ComIPduSizeType, TYPEDEF ) ComIPduSizeMax;
    VAR( ComSignalGroupRefType, TYPEDEF ) ComIPduSignalGroupRefNum;
    VAR( ComSignalGroupRefType, TYPEDEF ) ComIPduSignalGroupRefFirst;
    VAR( ComSignalRefType, TYPEDEF ) ComIPduSignalRefNum;
    VAR( ComSignalRefType, TYPEDEF ) ComIPduSignalWithBufferRefNum;
    VAR( ComSignalRefType, TYPEDEF ) ComIPduSignalW_F_A_NotiRefNum;
    VAR( ComSignalRefType, TYPEDEF ) ComIPduSignalWithDMOnly;
    VAR( ComSignalRefType, TYPEDEF ) ComIPduSignalRefFirst;
    VAR( Com_CallOutFuncPtrRefType, TYPEDEF ) ComIPduCallOutFuncPtrRef;
    VAR( Com_CbkRxTOutIdxType, TYPEDEF ) ComRxTimeoutNotificationFirst;
    VAR( Com_CbkRxTOutIdxType, TYPEDEF ) ComRxTimeoutNotificationNum;
    VAR( ComRxTimeoutFactorType, TYPEDEF ) ComRxTimeoutFactorValue;
    VAR( ComRxFirstTimeoutFactorType, TYPEDEF ) ComRxFirstTimeoutFactorValue;
    VAR( ComIPduRefType, TYPEDEF ) RxDMQueueRef;
    VAR( ComIPduRefType, TYPEDEF ) ComIPduSigGWFlagBit;
    VAR( ComGWSourceRefType, TYPEDEF ) ComIPduGWSourceRefNum;
    VAR( ComGWSourceRefType, TYPEDEF ) ComIPduGWSourceRefFirst;
    VAR( ComIPduSizeType, TYPEDEF ) ComIPduTimeoutSize;
    VAR( uint8, TYPEDEF ) ComRxIPduFlags;
    VAR( ComMainIDType, TYPEDEF ) Com_MainID_Rx;
} ComRxIPduType;

typedef struct /* ComSignalBaseType */ {
    VAR( ComRAMIdxType, TYPEDEF ) ComBufferRef;
    VAR( uint16, TYPEDEF ) ComRxSignalFlags;
    VAR( ComSignalDescBitType, TYPEDEF ) ComSignalPositionInBit;
    VAR( ComSignalBitSizeType, TYPEDEF ) ComBitSize;
    VAR( ComSignalGroupRefType, TYPEDEF ) ComSignalGroupRef;
    VAR( ComFilterConfType, TYPEDEF ) ComFilterConf;
} ComSignalBaseType;

typedef struct /* ComTxSignalGroupType */ {
    VAR( ComRAMIdxType, TYPEDEF ) ComSignalGroupValueRef;
    VAR( ComRAMIdxType, TYPEDEF ) ComSignalGTMSFlagsRef;
    TS_REF2CFG( uint8 )  ComSignalGTMSFlagsInitValueRef;
    TS_REF2CFG( uint8 )  ComTOCMaskRef;
    TS_REF2CFG( uint8 )  ComWriteMaskRef;
    VAR( ComIPduRefType, TYPEDEF ) ComIPduRef;
    VAR( ComSignalDescByteType, TYPEDEF ) ComSignalPositionInByte;
    VAR( ComSignalDescByteType, TYPEDEF ) ComByteSize;
    VAR( ComSignalDescBitType, TYPEDEF ) ComUpdateBitPositionInBit;
    VAR( ComTxGroupSignalRefType, TYPEDEF ) ComGroupSignalWithFilterRefNum;
    VAR( ComTMSFlagsRefType, TYPEDEF ) ComPositionOfTMSFlag;
    VAR( ComTxGroupSignalRefType, TYPEDEF ) ComGroupSignalRefFirst;
    VAR( uint8, TYPEDEF ) ComTxSignalGroupFlags;
    VAR( ComMainIDType, TYPEDEF ) Com_MainID_Tx;
} ComTxSignalGroupType;

typedef struct /* ComTxSignalType */ {
    VAR( ComSignalBaseType, TYPEDEF ) ComSignalBase;
    VAR( uint16, TYPEDEF ) ComTxSignalFlags;
    VAR( ComSignalDescBitType, TYPEDEF ) ComUpdateBitPositionInBit;
    VAR( ComSignalDescBitType, TYPEDEF ) ComSignalPositionInBit;
    VAR( ComIPduRefType, TYPEDEF ) ComIPduRef;
    VAR( ComTMSFlagsRefType, TYPEDEF ) ComPositionOfTMSFlag;
    VAR( ComMainIDType, TYPEDEF ) Com_MainID_Tx;
} ComTxSignalType;

typedef struct /* ComRxSignalType */ {
    VAR( ComSignalBaseType, TYPEDEF ) ComSignalBase;
    VAR( ComSignalRefType, TYPEDEF ) ComSignalExtRef;
    VAR( ComIPduRefType, TYPEDEF ) ComIPduRef;
    VAR( ComMainIDType, TYPEDEF ) Com_MainID_Rx;
} ComRxSignalType;

typedef struct /* Com_ConfigType */ {
    VAR( uint32, TYPEDEF ) ComPlatformSignature;
    VAR( uint32, TYPEDEF ) ComPublicInfoSignature;
    VAR( uint32, TYPEDEF ) ComCfgSignature;
    VAR( uint32, TYPEDEF ) ComLcfgSignature;
    VAR( ComRAMIdxType, TYPEDEF ) ComRxIPduStatusBase;
    VAR( ComRAMIdxType, TYPEDEF ) ComTxIPduStatusBase;
    VAR( ComRAMIdxType, TYPEDEF ) ComRxIPduLengthBase;
    VAR( ComRAMIdxType, TYPEDEF ) ComTxIPduLengthBase;
    VAR( ComRAMIdxType, TYPEDEF ) ComTxSignalGroupStatusBase;
    VAR( ComRAMIdxType, TYPEDEF ) ComBufferBaseUInt32;
    VAR( ComRAMIdxType, TYPEDEF ) ComBufferBaseSInt32;
    VAR( ComRAMIdxType, TYPEDEF ) ComBufferBaseUInt16;
    VAR( ComRAMIdxType, TYPEDEF ) ComBufferBaseSInt16;
    VAR( ComRAMIdxType, TYPEDEF ) ComBufferBaseUInt8;
    VAR( ComRAMIdxType, TYPEDEF ) ComBufferBaseSInt8;
    VAR( ComRAMIdxType, TYPEDEF ) ComBufferBaseBool;
    VAR( ComRAMIdxType, TYPEDEF ) ComFilterOneEveryNBase;
    VAR( ComRAMIdxType, TYPEDEF ) ComSigGWRxPduFlagBase;
    VAR( ComRAMIdxType, TYPEDEF ) ComSigGWTxSignalGroupQueueBase;
    VAR( ComRAMIdxType, TYPEDEF ) ComMDTQueueBase;
    VAR( ComRAMIdxType, TYPEDEF ) ComPeriodicQueueBase;
    VAR( ComRAMIdxType, TYPEDEF ) ComNTimesQueueBaseNextTime;
    VAR( ComRAMIdxType, TYPEDEF ) ComNTimesQueueBaseRemaining;
    VAR( ComRAMIdxType, TYPEDEF ) ComRxTimeoutQueueBase;
    TS_REF2CFG( ComIPduRefType )  ComRxTimeoutQueueListRef;
    VAR( ComRAMIdxType, TYPEDEF ) ComRxTimeoutSignalStatusQueueBase;
    TS_REF2CFG( ComSignalRefType )  ComRxTimeoutSignalQueueListRef;
    VAR( ComRAMIdxType, TYPEDEF ) ComRxDMInvSignalGroupStatusQueueBase;
    VAR( ComRAMIdxType, TYPEDEF ) ComRxTimeoutSignalGroupQueueBase;
    TS_REF2CFG( ComSignalGroupRefType )  ComRxTimeoutSignalGroupQueueListRef;
    VAR( ComRAMIdxType, TYPEDEF ) ComTxTimeoutQueueBase;
    VAR( ComRAMIdxType, TYPEDEF ) ComCbkTxAckDeferredStatusBase;
    TS_REF2CFG( ComRxIPduType )  ComRxIPduRef;
    TS_REF2CFG( ComTxIPduType )  ComTxIPduRef;
    TS_REF2CFG( ComTxModeNTimesType )  ComTxModeNTimesRef;
    TS_REF2CFG( ComTxModePeriodicType )  ComTxModePeriodicRef;
    TS_REF2CFG( ComTxModeMixedNTimesType )  ComTxModeMixedNTimesRef;
    TS_REF2CFG( ComIPduGroupType )  ComIPduGroupRef;
    TS_REF2CFG( ComIPduRefType )  ComSigGWRxIPduListRef;
    TS_REF2CFG( ComSignalGroupRefType )  ComRxIPduSignalGroupListRef;
    TS_REF2CFG( ComSignalGroupRefType )  ComTxIPduSignalGroupListRef;
    TS_REF2CFG( ComSignalRefType )  ComRxIPduSignalListRef;
    TS_REF2CFG( ComSignalRefType )  ComTxIPduSignalListRef;
    TS_REF2CFG( ComRxSignalGroupType )  ComRxSignalGroupRef;
    TS_REF2CFG( ComTxSignalGroupType )  ComTxSignalGroupRef;
    TS_REF2CFG( ComTxGroupSignalRefType )  ComTxSignalGroupGroupSignalListRef;
    TS_REF2CFG( ComFilter8BitMaskType )  ComFilter8BitMaskRef;
    TS_REF2CFG( ComFilter16BitMaskType )  ComFilter16BitMaskRef;
    TS_REF2CFG( ComFilter32BitMaskType )  ComFilter32BitMaskRef;
    TS_REF2CFG( ComFilter8BitMaskXMinMaxType )  ComFilter8BitMaskXMinMaxRef;
    TS_REF2CFG( ComFilter16BitMaskXMinMaxType )  ComFilter16BitMaskXMinMaxRef;
    TS_REF2CFG( ComFilter32BitMaskXMinMaxType )  ComFilter32BitMaskXMinMaxRef;
    TS_REF2CFG( ComFilterOneEveryNType )  ComFilterOneEveryNRef;
    TS_REF2CFG( ComRxSignalType )  ComRxSignalRef;
    TS_REF2CFG( ComRxSignalExtType )  ComRxSignalExtRef;
    TS_REF2CFG( ComTxSignalType )  ComTxSignalRef;
    TS_REF2CFG( Com_CbkRxTOutIdxType )  ComRxTimeoutNotificationRef;
    TS_REF2CFG( Com_CbkTxTOutIdxType )  ComTxTimeoutNotificationRef;
    TS_REF2CFG( Com_CbkTxTOutIdxType )  ComTxErrorNotificationRef;
    TS_REF2CFG( Com_CbkTxAckIdxType )  ComTxNotificationRef;
    TS_REF2CFG( ComGWSourceType )  ComGWSourceRef;
    TS_REF2CFG( ComGWDestinationType )  ComGWDestinationRef;
    TS_REF2CFG( ComMainfunctionRxType )  ComMainfunctionRxRef;
    TS_REF2CFG( ComMainfunctionTxType )  ComMainfunctionTxRef;
    VAR( ComSignalGroupRefType, TYPEDEF ) ComSigGWTxSignalGroupQueueMax;
    VAR( ComIPduRefType, TYPEDEF ) ComMDTQueueMax;
    VAR( ComIPduRefType, TYPEDEF ) ComPeriodicQueueMax;
    VAR( ComIPduRefType, TYPEDEF ) ComNTimesQueueMax;
    VAR( ComIPduRefType, TYPEDEF ) ComRxTimeoutQueueMax;
    VAR( Com_CbkRxTOutIdxType, TYPEDEF ) ComRxTimeoutSignalQueueBase;
    VAR( ComSignalRefType, TYPEDEF ) ComRxTimeoutSignalQueueMax;
    VAR( ComSignalGroupRefType, TYPEDEF ) ComRxTimeoutSignalGroupQueueMax;
    VAR( ComIPduRefType, TYPEDEF ) ComTxTimeoutQueueMax;
    VAR( ComIPduRefType, TYPEDEF ) ComCbkTxAckDeferredListMax;
    VAR( ComIPduRefType, TYPEDEF ) ComRxIPduArraySize;
    VAR( ComIPduRefType, TYPEDEF ) ComTxIPduArraySize;
    VAR( ComSignalRefType, TYPEDEF ) ComRxSignalArraySize;
    VAR( ComSignalRefType, TYPEDEF ) ComTxSignalArraySize;
    VAR( ComFilterRefType, TYPEDEF ) ComFilterOneEveryNArraySize;
    VAR( uint16, TYPEDEF ) ComIPduGroupsNum;
    VAR( uint16, TYPEDEF ) ComSigGWRxIPduArraySize;
    VAR( ComSignalGroupRefType, TYPEDEF ) ComTxSignalGroupArraySize;
    VAR( ComSignalGroupRefType, TYPEDEF ) ComRxSignalGroupArraySize;
} Com_ConfigType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* COM_TYPES_H */

/*==================[end of file]============================================*/

