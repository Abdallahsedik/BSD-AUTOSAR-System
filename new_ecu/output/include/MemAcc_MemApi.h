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



#ifndef MEMACC_MEMAPI_H
#define MEMACC_MEMAPI_H

/*==[Includes]================================================================*/

/*==[Macros definitions]======================================================*/

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_91011,1 */
/** \brief Memory driver instance identifier type. */
typedef uint32 MemAcc_MemInstanceIdType;

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_10008,1 */
/** \brief Index type for Mem driver hardware specific service table. */
typedef uint32 MemAcc_MemHwServiceIdType;

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_91012,1 */
/** \brief Memory driver configuration structure type */
typedef struct
{
  uint8 Dummy;
} MemAcc_MemConfigType;

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_91013,1 */
/** \brief Physical memory device address type. */
typedef MemAcc_AddressType MemAcc_MemAddressType;

/* !LINKSTO Base.EB_Ref.SWS_MemAcc_91014.64bit.Support,1 */
/** \brief Physical memory device length type. */
typedef MemAcc_LengthType MemAcc_MemLengthType;

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_91020,1 */
/** \brief General data type. */
typedef uint8 MemAcc_MemDataType;

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_91000,1 */
/** \brief Function pointer for the Mem_Init service for the invocation of the Mem driver API via function pointer interface. */
typedef P2FUNC(void, BASE_APPL_CODE, MemAcc_MemInitFuncType) (MemAcc_MemConfigType* configPtr);

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_91018,1 */
/** \brief Function pointer for the Mem_DeInit service for the invocation of the Mem driver API via function pointer interface. */
typedef P2FUNC(void, BASE_APPL_CODE, MemAcc_MemDeInitFuncType) (void);

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_91002,1 */
/** \brief Function pointer for the Mem_JobResultType service for the invocation of the Mem driver API via function pointer interface. */
typedef P2FUNC(MemAcc_MemJobResultType, BASE_APPL_CODE, MemAcc_MemGetJobResultFuncType) (MemAcc_MemInstanceIdType instanceId);

/* !LINKSTO Base.EB_Ref.SWS_MemAcc_91003.Parameter.Order,1 */
/** \brief Function pointer for the Mem_Read service for the invocation of the Mem driver API via function pointer interface. */
typedef P2FUNC(Std_ReturnType, BASE_APPL_CODE, MemAcc_MemReadFuncType) (MemAcc_MemInstanceIdType instanceId,
                                                                        MemAcc_MemAddressType sourceAddress,
                                                                        MemAcc_MemDataType* destinationDataPtr,
                                                                        MemAcc_MemLengthType length);

/* !LINKSTO Base.EB_Ref.SWS_MemAcc_91004.Return.Type,1 */
/** \brief Function pointer for the Mem_Write service for the invocation of the Mem driver API via function pointer interface. */
typedef P2FUNC(Std_ReturnType, BASE_APPL_CODE, MemAcc_MemWriteFuncType) (MemAcc_MemInstanceIdType instanceId,
                                                                         MemAcc_MemAddressType targetAddress,
                                                                         const MemAcc_MemDataType* sourceDataPtr,
                                                                         MemAcc_MemLengthType length);

/* !LINKSTO Base.EB_Ref.SWS_MemAcc_91005.Return.Type,1 */
/** \brief Function pointer for the Mem_Erase service for the invocation of the Mem driver API via function pointer interface. */
typedef P2FUNC(Std_ReturnType, BASE_APPL_CODE, MemAcc_MemEraseFuncType) (MemAcc_MemInstanceIdType instanceId,
                                                                         MemAcc_MemAddressType targetAddress,
                                                                         MemAcc_MemLengthType length);

/* !LINKSTO Base.EB_Ref.SWS_MemAcc_91007.Return.Type,1 */
/** \brief Function pointer for the Mem_BlankCheck service for the invocation of the Mem driver API via function pointer interface. */
typedef P2FUNC(Std_ReturnType, BASE_APPL_CODE, MemAcc_MemBlankCheckFuncType) (MemAcc_MemInstanceIdType instanceId,
                                                                              MemAcc_MemAddressType targetAddress,
                                                                              MemAcc_MemLengthType length);

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_91001,1 */
/** \brief Function pointer for the Mem_MainFunction service for the invocation of the Mem driver API via function pointer interface. */
typedef P2FUNC(void, BASE_APPL_CODE, MemAcc_MemMainFuncType) (void);

/*==[Types declarations]======================================================*/

/*==[Declaration of constants with external linkage]==========================*/

/*==[Declaration of variables with external linkage]==========================*/

/*==[Declaration of functions with external linkage]==========================*/

/*==[Declaration of constants with internal linkage]==========================*/

/*==[Declaration of variables with internal linkage]==========================*/

/*==[Declaration of functions with internal linkage]==========================*/

#endif /* MEMACC_MEMAPI_H */

