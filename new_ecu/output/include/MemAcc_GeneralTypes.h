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



#ifndef MEMACC_GENERALTYPES_H
#define MEMACC_GENERALTYPES_H

/*==[Includes]================================================================*/

#include <Std_Types.h>

/*==[Macros definitions]======================================================*/

/* ------------------ MemAcc_JobResultType R23-11 ------------------ */

#ifndef MEMACC_OK
/** \brief The job has been finished successfully. */
#define MEMACC_OK                           0x00U
#else
#error MEMACC_OK is already defined
#endif

#ifndef MEMACC_FAILED
/** \brief The last MemAcc job resulted in an unspecific failure and the job was not completed. */
#define MEMACC_FAILED                       0x01U
#else
#error MEMACC_FAILED is already defined
#endif

#ifndef MEMACC_INCONSISTENT
/** \brief The results of the last MemAcc job didn’t meet the expected result, e.g. a blank check operation was applied on a non-blank memory area. */
#define MEMACC_INCONSISTENT                 0x02U
#else
#error MEMACC_INCONSISTENT is already defined
#endif

#ifndef MEMACC_CANCELED
/** \brief The last MemAcc job was canceled. */
#define MEMACC_CANCELED                     0x03U
#else
#error MEMACC_CANCELED is already defined
#endif

#ifndef MEMACC_ECC_UNCORRECTED
/** \brief The last memory operation returned an uncorrectable ECC error. */
#define MEMACC_ECC_UNCORRECTED              0x04U
#else
#error MEMACC_ECC_UNCORRECTED is already defined
#endif

#ifndef MEMACC_ECC_CORRECTED
/** \brief The last memory operation returned a correctable ECC error. */
#define MEMACC_ECC_CORRECTED                0x05U
#else
#error MEMACC_ECC_CORRECTED is already defined
#endif

/* ------------------ MemAcc_JobResultType R21-11 ------------------ */

#ifndef MEMACC_MEM_OK
/** \brief The job has been finished successfully. */
#define MEMACC_MEM_OK                       0x00U
#else
#error MEMACC_MEM_OK is already defined
#endif

#ifndef MEMACC_MEM_FAILED
/** \brief The last MemAcc job resulted in an unspecific failure and the job was not completed. */
#define MEMACC_MEM_FAILED                   0x01U
#else
#error MEMACC_MEM_FAILED is already defined
#endif

#ifndef MEMACC_MEM_INCONSISTENT
/** \brief The results of the last MemAcc job didn’t meet the expected result, e.g. a blank check operation was applied on a non-blank memory area. */
#define MEMACC_MEM_INCONSISTENT             0x02U
#else
#error MEMACC_MEM_INCONSISTENT is already defined
#endif

#ifndef MEMACC_MEM_CANCELED
/** \brief The last MemAcc job was canceled. */
#define MEMACC_MEM_CANCELED                 0x03U
#else
#error MEMACC_MEM_CANCELED is already defined
#endif

#ifndef MEMACC_MEM_ECC_UNCORRECTED
/** \brief The last memory operation returned an uncorrectable ECC error. */
#define MEMACC_MEM_ECC_UNCORRECTED          0x04U
#else
#error MEMACC_MEM_ECC_UNCORRECTED is already defined
#endif

#ifndef MEMACC_MEM_ECC_CORRECTED
/** \brief The last memory operation returned a correctable ECC error. */
#define MEMACC_MEM_ECC_CORRECTED            0x05U
#else
#error MEMACC_MEM_ECC_CORRECTED is already defined
#endif

/* ------------------ MemAcc_JobStatusType ------------------ */

#ifndef MEMACC_JOB_IDLE
/** \brief Job processing was completed or no job currently pending. */
#define MEMACC_JOB_IDLE                     0x00U
#else
#error MEMACC_JOB_IDLE is already defined
#endif

#ifndef MEMACC_JOB_PENDING
/** \brief A job is currently being processed. */
#define MEMACC_JOB_PENDING                  0x01U
#else
#error MEMACC_JOB_PENDING is already defined
#endif

/* ------------------ MemAcc_JobType ------------------ */

#ifndef MEMACC_NO_JOB
/** \brief No job currently pending. */
#define MEMACC_NO_JOB                       0x00U
#else
#error MEMACC_NO_JOB is already defined
#endif

#ifndef MEMACC_WRITE_JOB
/** \brief Write job pending. */
#define MEMACC_WRITE_JOB                    0x01U
#else
#error MEMACC_WRITE_JOB is already defined
#endif

#ifndef MEMACC_READ_JOB
/** \brief Read job pending. */
#define MEMACC_READ_JOB                     0x02U
#else
#error MEMACC_READ_JOB is already defined
#endif

#ifndef MEMACC_COMPARE_JOB
/** \brief Compare job pending. */
#define MEMACC_COMPARE_JOB                  0x03U
#else
#error MEMACC_COMPARE_JOB is already defined
#endif

#ifndef MEMACC_ERASE_JOB
/** \brief Erase job pending. */
#define MEMACC_ERASE_JOB                    0x04U
#else
#error MEMACC_ERASE_JOB is already defined
#endif

#ifndef MEMACC_MEMHWSPECIFIC_JOB
/** \brief Erase job pending. */
#define MEMACC_MEMHWSPECIFIC_JOB            0x05U
#else
#error MEMACC_MEMHWSPECIFIC_JOB is already defined
#endif

#ifndef MEMACC_BLANKCHECK_JOB
/** \brief Blank check job pending. */
#define MEMACC_BLANKCHECK_JOB               0x06U
#else
#error MEMACC_BLANKCHECK_JOB is already defined
#endif

#ifndef MEMACC_REQUESTLOCK_JOB
/** \brief Request lock job pending. */
#define MEMACC_REQUESTLOCK_JOB              0x07U
#else
#error MEMACC_REQUESTLOCK_JOB is already defined
#endif

/* ------------------ MemAcc_MemJobResultType ------------------ */

#ifndef MEM_JOB_OK
/** \brief The last job has been finished successfully. */
#define MEM_JOB_OK                          0x00U
#endif

#ifndef MEM_JOB_PENDING
/** \brief A job is currently being processed. */
#define MEM_JOB_PENDING                     0x01U
#endif

#ifndef MEM_JOB_FAILED
/** \brief Job failed for some unspecific reason. */
#define MEM_JOB_FAILED                      0x02U
#endif

#ifndef MEM_INCONSISTENT
/** \brief The checked page is not blank. */
#define MEM_INCONSISTENT                    0x03U
#endif

#ifndef MEM_ECC_UNCORRECTED
/** \brief Uncorrectable ECC errors occurred during memory access. */
#define MEM_ECC_UNCORRECTED                 0x04U
#endif

#ifndef MEM_ECC_CORRECTED
/** \brief Correctable ECC errors occurred during memory access. */
#define MEM_ECC_CORRECTED                   0x05U
#endif

/* ------------------ MemAcc Return Value ------------------ */

#ifndef E_MEM_SERVICE_NOT_AVAIL
/** \brief The underlying Mem driver service function is not available. */
#define E_MEM_SERVICE_NOT_AVAIL             0x02U
#endif

/*==[Types declarations]======================================================*/

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_10000,1 */
/** \brief Unique address area ID type. */
typedef uint16 MemAcc_AddressAreaIdType;

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_10002,1 */
/** \brief Postbuild configuration structure type. */
typedef struct
{
  uint8 Dummy;
} MemAcc_ConfigType;

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_10004,1 */
/** \brief General data type. */
typedef uint8 MemAcc_DataType;

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_10039,1 */
/** \brief Asynchronous job result type. */
typedef uint8 MemAcc_JobResultType;

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_10009,1 */
/** \brief Asynchronous job status type. */
typedef uint8 MemAcc_JobStatusType;

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_10011,1 */
 /** \brief Type for asynchronous jobs. */
typedef uint8 MemAcc_JobType;

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_91016,1 */
/** \brief Asynchronous job result type. */
typedef uint8 MemAcc_MemJobResultType;

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_10010,1 */
/** \brief Type for the unique numeric identifiers of all Mem hardware instances used for hardware specific requests. */
typedef uint32 MemAcc_HwIdType;

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_10001,1 */
/** \brief Logical memory address type */
typedef uint32 MemAcc_AddressType;

/* !LINKSTO Base.ASR23-11.SWS_MemAcc_10007,1 */
/** \brief Job length type */
typedef uint32 MemAcc_LengthType;

/* !LINKSTO Base.EB_Ref.SWS_MemAcc_10012.HwId,1 */
/** \brief This structure contains information of Mem device characteristics. It can be accessed via the MemAcc_GetMemoryInfo() service. */
typedef struct
{
   MemAcc_AddressType LogicalStartAddress;
   MemAcc_AddressType PhysicalStartAddress;
   MemAcc_LengthType MaxOffset;
   uint32 EraseSectorSize;
   uint32 EraseSectorBurstSize;
   uint32 MinReadSize;
   uint32 WritePageSize;
   uint32 MaxReadSize;
   uint32 WritePageBurstSize;
   MemAcc_HwIdType HwId;
} MemAcc_MemoryInfoType;

/* !LINKSTO Base.EB_Ref.SWS_MemAcc_10013.MemAddress.MemLength,1 */
/** \brief This structure contains information the current processing state of the MemAcc module. */
typedef struct
{
   MemAcc_AddressType LogicalAddress;
   MemAcc_LengthType Length;
   MemAcc_HwIdType HwId;
   uint32 MemInstanceId;
   MemAcc_AddressType MemAddress;
   MemAcc_LengthType MemLength;
   MemAcc_JobType CurrentJob;
   MemAcc_MemJobResultType MemResult;
} MemAcc_JobInfoType;

/*==[Declaration of constants with external linkage]==========================*/

/*==[Declaration of variables with external linkage]==========================*/

/*==[Declaration of functions with external linkage]==========================*/

/*==[Declaration of constants with internal linkage]==========================*/

/*==[Declaration of variables with internal linkage]==========================*/

/*==[Declaration of functions with internal linkage]==========================*/

#endif /* MEMACC_GENERALTYPES_H */

