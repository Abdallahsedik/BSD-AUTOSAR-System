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

/*
 * gcc Deviation List
 *
 * GCC-1) Deviated Rule: pointer-to-int-cast (Required)
 * warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
 *
 * Reason:
 * A compiler warning is only reported when simulating a 64 bit environment
 * on a 32 bit Windows environment.
 *
 */

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 18.4 (advisory)
 * The +, -, += and -= operators should not be applied to an expression of pointer type.
 *
 * Reason:
 * Pointer arithmetic is used for classical functions like memcpy() to
 * make them more readable and maintainable.
 *
 * MISRAC2012-2) Deviated Rule: 11.3 (required)
 * A cast shall not be performed between a pointer to object type
 * and a pointer to a different object type.
 *
 * Reason:
 * The memory routines are optimized for dealing with aligned memory
 * and the correct alignment has been checked before converting
 * to different object types (see MISRAC2012-3).
 *
 * MISRAC2012-3) Deviated Rule: 11.4 (advisory)
 * A conversion should not be performed between a pointer to object
 * and an integer type.
 *
 * Reason:
 * The memory routines are optimized for dealing with aligned memory
 * sections and need to check the correct alignment before the operation.
 *
 * MISRAC2012-4) Deviated Rule: 11.5 (advisory)
 * A conversion should not be performed from pointer to void into pointer to object.
 *
 * Reason:
 * The memory routines are optimized for dealing with aligned memory
 * sections.
 *
 * MISRAC2012-5) Deviated Rule: 10.8 (required)
 * The value of a composite expression shall not be cast to a different essential type
 * category or a wider essential type.
 *
 * Reason:
 * The source and destination pointers of the macros to copy, set, or compare memory
 * are incremented, and a cast is required based on the platform's specific pointer size.
 *
 * MISRAC2012-6) Deviated Rule: 11.6 (required)
 * A cast shall not be performed between pointer to void and an arithmetic type.
 *
 * Reason:
 * In order to determine the address alignments casts to usize are required.
 */

/* CERT-C Deviation List
 *
 * CERTC-1) Deviated Rule: INT.36
 * Converting a pointer to integer or integer to pointer
 *
 * Reason:
 * The memory routines are optimized for dealing with aligned memory
 * sections and need to check the correct alignment before the operation.
 */

#include <TSMem.h>
#include <TSMemS.h>
#include <TSAutosar.h>


  
  

/*==================[macros]=================================================*/

#if (defined TS_MEMCPY_NOCHECK)
#error TS_MEMCPY_NOCHECK is already defined
#endif

/** \brief Copies \p len bytes of memory from \p dst to \p src using
 * type information passed in \p type
 *
 * \param[in] dst Pointer to the destination address
 * \param[in] src Pointer to the source address
 * \param[in] len Amount of bytes to copy
 * \param[in] type The type to perform the copying with
 */
/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
#define TS_MEMCPY_NOCHECK(dst, src, len, type)              \
  do {                                                      \
    /* loop and copy */                                     \
    while ((len) >= (usize)sizeof(type))                    \
    {                                                       \
      *(P2VAR(type, AUTOMATIC, BASE_APPL_DATA))(dst) =      \
         *(P2CONST(type, AUTOMATIC, BASE_APPL_DATA))(src);  \
      (src) += sizeof(type);                                \
      (dst) += sizeof(type);                                \
      (len) -= sizeof(type);                                \
    }                                                       \
  } while (0)

/** \brief Assigns \p len times the value \p val to \p dst using
 * type information passed in  \p type
 *
 * \param[in] dst Pointer to the destination address
 * \param[in] val Value to be assigned
 * \param[in] len Amount of bytes to assign
 * \param[in] type The type to perform the assignment with
 */
/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
#define TS_MEMSET_NOCHECK(dst, val, len, type)                \
  do                                                          \
  {                                                           \
    while ((len) >= (usize)sizeof(type))                      \
    {                                                         \
      *(P2VAR(type, AUTOMATIC, BASE_APPL_DATA))(dst) = (val); \
      (dst) += sizeof(type);                                  \
      (len) -= sizeof(type);                                  \
    }                                                         \
  }                                                           \
  while (0)

/** \brief Assigns \p len times the value \p val to \p dst using
 * type information passed in  \p type
 *
 * \param[in] dst Pointer to the destination address
 * \param[in] val Value to be assigned
 * \param[in] len Amount of bytes to assign
 * \param[in] type The type to perform the assignment with
 */
/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
#define TS_MEMSETS_NOCHECK(dst, val, len, type)                \
  do                                                          \
  {                                                           \
    while ((len) >= (usize)sizeof(type))                      \
    {                                                         \
      *(volatile P2VAR(type, AUTOMATIC, BASE_APPL_DATA))(dst) = (val); \
      (dst) += sizeof(type);                                  \
      (len) -= sizeof(type);                                  \
    }                                                         \
  }                                                           \
  while (0)


#if (defined TS_MEMCMP_NOCHECK)
#error TS_MEMCMP_NOCHECK is already defined
#endif

/** \brief Compares \p len bytes of memory from \p dst to \p src using
 * type information passed in \p type.
 *
 * \pre RetVal should by of type Std_ReturnType
 *
 * \param[in] a Pointer to the first memory block to compare
 * \param[in] b Pointer to the second memory block to compare
 * \param[in] len Amount of bytes to compare
 * \param[in] RetVal The return value to pass result information
 * \param[in] type The type to perform the comparison with
 */
/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
#define TS_MEMCMP_NOCHECK(a, b, len, RetVal, type)                \
   do {                                                           \
    (RetVal) = E_OK;                                              \
    /* loop and compare */                                        \
     while ((len) >= (usize)sizeof(type))                         \
    {                                                             \
       if ((*(P2CONST(type, AUTOMATIC, BASE_APPL_DATA))(a)) !=    \
           *(P2CONST(type, AUTOMATIC, BASE_APPL_DATA))(b))        \
      {                                                           \
        (RetVal) = E_NOT_OK;                                      \
        break;                                                    \
      }                                                           \
      else                                                        \
      {                                                           \
        (a) += sizeof(type);                                      \
        (b) += sizeof(type);                                      \
        (len) -= sizeof(type);                                    \
      }                                                           \
    }                                                             \
  } while (0)

#if (defined TS_MEMCMPS_NOCHECK)
#error TS_MEMCMPS_NOCHECK is already defined
#endif

/** \brief Compares \p len bytes of memory from \p dst to \p src using
 * type information passed in \p type.
 * If a mismatch is found the search is not immediately stopped but 
 * continues until all bytes have been verified.
 *
 * \pre RetVal should by of type Std_ReturnType
 *
 * \param[in] a Pointer to the first memory block to compare
 * \param[in] b Pointer to the second memory block to compare
 * \param[in] len Amount of bytes to compare
 * \param[in] RetVal The return value to pass result information
 * \param[in] type The type to perform the comparison with
 */
/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
#define TS_MEMCMPS_NOCHECK(a, b, len, RetVal, type)                \
  do                                                               \
  {                                                                \
    type cmp = 0U;                                                 \
    (RetVal) = E_NOT_OK;                                           \
    while ((len) >= (usize)sizeof(type))                           \
    {                                                              \
      cmp   |=   (*(P2CONST(type, AUTOMATIC, BASE_APPL_DATA))(a))  \
               ^ (*(P2CONST(type, AUTOMATIC, BASE_APPL_DATA))(b)); \
      (a)   += sizeof(type);                                       \
      (b)   += sizeof(type);                                       \
      (len) -= sizeof(type);                                       \
    }                                                              \
    if (0U == cmp)                                                 \
    {                                                              \
      (RetVal) = E_OK;                                             \
    }                                                              \
  }                                                                \
  while (0)

/*==================[external function definitions]==========================*/

#define BASE_START_SEC_CODE
#include <Base_MemMap.h>



STATIC FUNC(void, BASE_CODE) TS_GetOptimization
(
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) a,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) b,
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) optimization,
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) bytesUntilAligned
)
{
  /* Deviation MISRAC2012-6, GCC-1 */
  usize aNum = (usize)a;
  usize bNum = (usize)b;
  *optimization = sizeof(usize);

  while (*optimization > 1U)
  {
    if ((aNum % *optimization) == (bNum % *optimization))
    {
      break;
    }
    *optimization /= 2U;
  }
  if (*optimization > 1U)
  {
    *bytesUntilAligned = (*optimization - (aNum % *optimization)) % *optimization;
  }
  else
  {
    *bytesUntilAligned = 0U;
  }

  *optimization *= 8U;
}

FUNC(void, BASE_CODE) TS_MemCpy32
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) src,
  const usize len
)
{
  /* define pointers for access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) src2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) src;
  /* Deviation MISRAC2012-4 */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  usize len2 = len;

  if (len >= 2U * sizeof(usize) - 1U)
  {
    uint8 optimization, bytesUntilAligned;
    TS_GetOptimization(dst, src, &optimization, &bytesUntilAligned);
    if (optimization != 8U)
    {
      len2 -= bytesUntilAligned;
      /* Deviation MISRAC2012-1 */
      TS_MEMCPY_NOCHECK(dst2, src2, bytesUntilAligned, uint8);
      switch(optimization)
      {
        case 16U:
          /* Deviation MISRAC2012-2 */
          TS_MEMCPY_NOCHECK(dst2, src2, len2, uint16);
          break;
        case 32U:
          /* Deviation MISRAC2012-2 */
          TS_MEMCPY_NOCHECK(dst2, src2, len2, uint32);
          break;
        default:
          break;
      }
    }
  }

  /* Deviation MISRAC2012-1 */
  TS_MEMCPY_NOCHECK(dst2, src2, len2, uint8);
}

FUNC(void, BASE_CODE) TS_MemSet32
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint8 val,
  const usize len
)
{
  /* define pointer for access */
  /* Deviation MISRAC2012-4 */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  usize len2 = len;

  if (len >= 2U * sizeof(usize) - 1U)
  {
    const usize val2 = (usize)val
                       | ((usize)val << 8U)
                       | ((usize)val << 16U)
                       | ((usize)val << 24U)
    ;
    /* Deviation MISRAC2012-6, GCC-1 */
    usize dstNum = (usize)dst;
    uint8 bytesUntilAligned = (sizeof(usize) - (dstNum % sizeof(usize))) % sizeof(usize);
    len2 -= bytesUntilAligned;
    TS_MEMSET_NOCHECK(dst2, val, bytesUntilAligned, uint8);
    /* Deviation MISRAC2012-2 */
    TS_MEMSET_NOCHECK(dst2, val2, len2, uint32);
  }

  /* Deviation MISRAC2012-1, MISRAC2012-5 */
  TS_MEMSET_NOCHECK(dst2, val, len2, uint8);
}

FUNC(void, BASE_CODE) TS_MemBZero32
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const usize len
)
{
  TS_MemSet32(dst, 0U, len);
}

FUNC(Std_ReturnType, BASE_CODE) TS_MemCmp32
(
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) a,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) b,
  const usize len
)
{
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) a2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) a;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) b2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) b;
  usize len2 = len;
  Std_ReturnType RetVal = E_OK;
  uint8 optimization, bytesUntilAligned;
  TS_GetOptimization(a, b, &optimization, &bytesUntilAligned);

  if ((len >= 2U * sizeof(usize) - 1U) && (optimization != 8U))
  {
    {
      len2 -= bytesUntilAligned;
      TS_MEMCMP_NOCHECK(a2, b2, bytesUntilAligned, RetVal, uint8);
      if (RetVal == E_OK)
      {
        switch(optimization)
        {
          case 16U:
            /* Deviation MISRAC2012-2 */
            TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint16);
            break;
          case 32U:
            /* Deviation MISRAC2012-2 */
            TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint32);
            break;
          default:
            break;
        }
      }
    }
  }
  if (RetVal == E_OK)
  {
    TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint8);
  }
  return RetVal;
}

FUNC(void, BASE_CODE) TS_MemSetS32
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint8 val,
  const usize len
)
{
  /* define pointer for access */
  /* Deviation MISRAC2012-4 */
  volatile P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  usize len2 = len;

  if (len >= 2U * sizeof(usize) - 1U)
  {
    const usize val2 = (usize)val
                       | ((usize)val << 8U)
                       | ((usize)val << 16U)
                       | ((usize)val << 24U)
    ;
    /* Deviation MISRAC2012-6, GCC-1 */
    usize dstNum = (usize)dst;
    uint8 bytesUntilAligned = (sizeof(usize) - (dstNum % sizeof(usize))) % sizeof(usize);
    len2 -= bytesUntilAligned;
    TS_MEMSETS_NOCHECK(dst2, val, bytesUntilAligned, uint8);
    /* Deviation MISRAC2012-2 */
    TS_MEMSETS_NOCHECK(dst2, val2, len2, uint32);
  }

  /* Deviation MISRAC2012-1, MISRAC2012-5 */
  TS_MEMSETS_NOCHECK(dst2, val, len2, uint8);
}

FUNC(void, BASE_CODE) TS_MemBZeroS32
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const usize len
)
{
  TS_MemSetS32(dst, 0U, len);
}

FUNC(Std_ReturnType, BASE_CODE) TS_MemCmpS32
(
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) a,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) b,
  const usize len
)
{
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) a2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) a;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) b2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) b;
  usize len2 = len;
  Std_ReturnType RetVal = E_OK;
  uint8 optimization, bytesUntilAligned;
  TS_GetOptimization(a, b, &optimization, &bytesUntilAligned);

  if ((len >= 2U * sizeof(usize) - 1U) && (optimization != 8U))
  {
    {
      len2 -= bytesUntilAligned;
      TS_MEMCMPS_NOCHECK(a2, b2, bytesUntilAligned, RetVal, uint8);
      if (RetVal == E_OK)
      {
        switch(optimization)
        {
          case 16U:
            /* Deviation MISRAC2012-2 */
            TS_MEMCMPS_NOCHECK(a2, b2, len2, RetVal, uint16);
            break;
          case 32U:
            /* Deviation MISRAC2012-2 */
            TS_MEMCMPS_NOCHECK(a2, b2, len2, RetVal, uint32);
            break;
          default:
            break;
        }
      }
    }
  }
  if (RetVal == E_OK)
  {
    TS_MEMCMPS_NOCHECK(a2, b2, len2, RetVal, uint8);
  }
  return RetVal;
}


FUNC(void, BASE_CODE) TS_MemCpy16_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) src,
  const usize len
)
{
  /* define pointers for access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) src2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) src;
  /* Deviation MISRAC2012-4 */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  usize len2 = len;

  /* copy as much data as possible in 16-bit mode */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5  */
  TS_MEMCPY_NOCHECK(dst2, src2, len2, uint16);

  /* copy the remaining elements byte-wise */
  /* Deviation MISRAC2012-1, MISRAC2012-5 */
  TS_MEMCPY_NOCHECK(dst2, src2, len2, uint8);
}

FUNC(void, BASE_CODE) TS_MemSet16_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint8 val,
  const usize len
)
{
  /* define pointer for access */
  /* Deviation MISRAC2012-4 */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  usize len2 = len;

  /* construct a unsafe-bit value from the 8-bit input */
  const uint16 val2 = (uint16)val
                           | ((uint16)val << 8U)
  ;

  /* assign data in unsafe-bit mode */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
  TS_MEMSET_NOCHECK(dst2, val2, len2, uint16);

  /* fill the rest byte-wise */
  /* Deviation MISRAC2012-1, MISRAC2012-5 */
  TS_MEMSET_NOCHECK(dst2, val, len2, uint8);
}

FUNC(void, BASE_CODE) TS_MemBZero16_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const usize len
)
{
  TS_MemSet16_NoCheck(dst, 0U, len);
}

FUNC(Std_ReturnType, BASE_CODE) TS_MemCmp16_NoCheck
(
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) a,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) b,
  const usize len
)
{
  /* define type specific pointers for suitable access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) a2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) a;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) b2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) b;
  usize len2 = len;
  Std_ReturnType RetVal;

  /* compare as much data in unsafe-bit mode as possible */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
  TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint16);

  /* the optimized compare macros may have already found a
   * difference, so we have to compare again */
  if (RetVal == E_OK)
  {
    /* compare the rest byte-wise */
    /* Deviation MISRAC2012-1, MISRAC2012-5 */
    TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint8);
  }

  return RetVal;
}

FUNC(void, BASE_CODE) TS_MemSetS16_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint8 val,
  const usize len
)
{
  /* define pointer for access */
  /* Deviation MISRAC2012-4 */
  volatile P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  usize len2 = len;

  /* construct a safe-bit value from the 8-bit input */
  const uint16 val2 = (uint16)val
                           | ((uint16)val << 8U)
  ;

  /* assign data in safe-bit mode */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
  TS_MEMSETS_NOCHECK(dst2, val2, len2, uint16);

  /* fill the rest byte-wise */
  /* Deviation MISRAC2012-1, MISRAC2012-5 */
  TS_MEMSETS_NOCHECK(dst2, val, len2, uint8);
}

FUNC(void, BASE_CODE) TS_MemBZeroS16_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const usize len
)
{
  TS_MemSetS16_NoCheck(dst, 0U, len);
}

FUNC(Std_ReturnType, BASE_CODE) TS_MemCmpS16_NoCheck
(
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) a,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) b,
  const usize len
)
{
  /* define type specific pointers for suitable access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) a2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) a;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) b2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) b;
  usize len2 = len;
  Std_ReturnType RetVal;

  /* compare as much data in safe-bit mode as possible */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
  TS_MEMCMPS_NOCHECK(a2, b2, len2, RetVal, uint16);

  /* the optimized compare macros may have already found a
   * difference, so we have to compare again */
  if (RetVal == E_OK)
  {
    /* compare the rest byte-wise */
    /* Deviation MISRAC2012-1, MISRAC2012-5 */
    TS_MEMCMPS_NOCHECK(a2, b2, len2, RetVal, uint8);
  }

  return RetVal;
}

FUNC(void, BASE_CODE) TS_MemCpy32_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) src,
  const usize len
)
{
  /* define pointers for access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) src2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) src;
  /* Deviation MISRAC2012-4 */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  usize len2 = len;

  /* copy as much data as possible in 32-bit mode */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5  */
  TS_MEMCPY_NOCHECK(dst2, src2, len2, uint32);

  /* copy the remaining elements byte-wise */
  /* Deviation MISRAC2012-1, MISRAC2012-5 */
  TS_MEMCPY_NOCHECK(dst2, src2, len2, uint8);
}

FUNC(void, BASE_CODE) TS_MemSet32_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint8 val,
  const usize len
)
{
  /* define pointer for access */
  /* Deviation MISRAC2012-4 */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  usize len2 = len;

  /* construct a unsafe-bit value from the 8-bit input */
  const uint32 val2 = (uint32)val
                           | ((uint32)val << 8U)
                           | ((uint32)val << 16U)
                           | ((uint32)val << 24U)
  ;

  /* assign data in unsafe-bit mode */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
  TS_MEMSET_NOCHECK(dst2, val2, len2, uint32);

  /* fill the rest byte-wise */
  /* Deviation MISRAC2012-1, MISRAC2012-5 */
  TS_MEMSET_NOCHECK(dst2, val, len2, uint8);
}

FUNC(void, BASE_CODE) TS_MemBZero32_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const usize len
)
{
  TS_MemSet32_NoCheck(dst, 0U, len);
}

FUNC(Std_ReturnType, BASE_CODE) TS_MemCmp32_NoCheck
(
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) a,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) b,
  const usize len
)
{
  /* define type specific pointers for suitable access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) a2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) a;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) b2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) b;
  usize len2 = len;
  Std_ReturnType RetVal;

  /* compare as much data in unsafe-bit mode as possible */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
  TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint32);

  /* the optimized compare macros may have already found a
   * difference, so we have to compare again */
  if (RetVal == E_OK)
  {
    /* compare the rest byte-wise */
    /* Deviation MISRAC2012-1, MISRAC2012-5 */
    TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint8);
  }

  return RetVal;
}

FUNC(void, BASE_CODE) TS_MemSetS32_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint8 val,
  const usize len
)
{
  /* define pointer for access */
  /* Deviation MISRAC2012-4 */
  volatile P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  usize len2 = len;

  /* construct a safe-bit value from the 8-bit input */
  const uint32 val2 = (uint32)val
                           | ((uint32)val << 8U)
                           | ((uint32)val << 16U)
                           | ((uint32)val << 24U)
  ;

  /* assign data in safe-bit mode */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
  TS_MEMSETS_NOCHECK(dst2, val2, len2, uint32);

  /* fill the rest byte-wise */
  /* Deviation MISRAC2012-1, MISRAC2012-5 */
  TS_MEMSETS_NOCHECK(dst2, val, len2, uint8);
}

FUNC(void, BASE_CODE) TS_MemBZeroS32_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const usize len
)
{
  TS_MemSetS32_NoCheck(dst, 0U, len);
}

FUNC(Std_ReturnType, BASE_CODE) TS_MemCmpS32_NoCheck
(
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) a,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) b,
  const usize len
)
{
  /* define type specific pointers for suitable access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) a2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) a;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) b2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) b;
  usize len2 = len;
  Std_ReturnType RetVal;

  /* compare as much data in safe-bit mode as possible */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
  TS_MEMCMPS_NOCHECK(a2, b2, len2, RetVal, uint32);

  /* the optimized compare macros may have already found a
   * difference, so we have to compare again */
  if (RetVal == E_OK)
  {
    /* compare the rest byte-wise */
    /* Deviation MISRAC2012-1, MISRAC2012-5 */
    TS_MEMCMPS_NOCHECK(a2, b2, len2, RetVal, uint8);
  }

  return RetVal;
}

FUNC(void, BASE_CODE) TS_MemCpy64_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) src,
  const usize len
)
{
  /* define pointers for access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) src2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) src;
  /* Deviation MISRAC2012-4 */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  usize len2 = len;

  /* copy as much data as possible in 64-bit mode */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5  */
  TS_MEMCPY_NOCHECK(dst2, src2, len2, uint64);

  /* copy the remaining elements byte-wise */
  /* Deviation MISRAC2012-1, MISRAC2012-5 */
  TS_MEMCPY_NOCHECK(dst2, src2, len2, uint8);
}

FUNC(void, BASE_CODE) TS_MemSet64_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint8 val,
  const usize len
)
{
  /* define pointer for access */
  /* Deviation MISRAC2012-4 */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  usize len2 = len;

  /* construct a unsafe-bit value from the 8-bit input */
  const uint64 val2 = (uint64)val
                           | ((uint64)val << 8U)
                           | ((uint64)val << 16U)
                           | ((uint64)val << 24U)
                           | ((uint64)val << 32U)
                           | ((uint64)val << 40U)
                           | ((uint64)val << 48U)
                           | ((uint64)val << 56U)
  ;

  /* assign data in unsafe-bit mode */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
  TS_MEMSET_NOCHECK(dst2, val2, len2, uint64);

  /* fill the rest byte-wise */
  /* Deviation MISRAC2012-1, MISRAC2012-5 */
  TS_MEMSET_NOCHECK(dst2, val, len2, uint8);
}

FUNC(void, BASE_CODE) TS_MemBZero64_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const usize len
)
{
  TS_MemSet64_NoCheck(dst, 0U, len);
}

FUNC(Std_ReturnType, BASE_CODE) TS_MemCmp64_NoCheck
(
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) a,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) b,
  const usize len
)
{
  /* define type specific pointers for suitable access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) a2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) a;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) b2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) b;
  usize len2 = len;
  Std_ReturnType RetVal;

  /* compare as much data in unsafe-bit mode as possible */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
  TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint64);

  /* the optimized compare macros may have already found a
   * difference, so we have to compare again */
  if (RetVal == E_OK)
  {
    /* compare the rest byte-wise */
    /* Deviation MISRAC2012-1, MISRAC2012-5 */
    TS_MEMCMP_NOCHECK(a2, b2, len2, RetVal, uint8);
  }

  return RetVal;
}

FUNC(void, BASE_CODE) TS_MemSetS64_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const uint8 val,
  const usize len
)
{
  /* define pointer for access */
  /* Deviation MISRAC2012-4 */
  volatile P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  usize len2 = len;

  /* construct a safe-bit value from the 8-bit input */
  const uint64 val2 = (uint64)val
                           | ((uint64)val << 8U)
                           | ((uint64)val << 16U)
                           | ((uint64)val << 24U)
                           | ((uint64)val << 32U)
                           | ((uint64)val << 40U)
                           | ((uint64)val << 48U)
                           | ((uint64)val << 56U)
  ;

  /* assign data in safe-bit mode */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
  TS_MEMSETS_NOCHECK(dst2, val2, len2, uint64);

  /* fill the rest byte-wise */
  /* Deviation MISRAC2012-1, MISRAC2012-5 */
  TS_MEMSETS_NOCHECK(dst2, val, len2, uint8);
}

FUNC(void, BASE_CODE) TS_MemBZeroS64_NoCheck
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  const usize len
)
{
  TS_MemSetS64_NoCheck(dst, 0U, len);
}

FUNC(Std_ReturnType, BASE_CODE) TS_MemCmpS64_NoCheck
(
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) a,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) b,
  const usize len
)
{
  /* define type specific pointers for suitable access */
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) a2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) a;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) b2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) b;
  usize len2 = len;
  Std_ReturnType RetVal;

  /* compare as much data in safe-bit mode as possible */
  /* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-5 */
  TS_MEMCMPS_NOCHECK(a2, b2, len2, RetVal, uint64);

  /* the optimized compare macros may have already found a
   * difference, so we have to compare again */
  if (RetVal == E_OK)
  {
    /* compare the rest byte-wise */
    /* Deviation MISRAC2012-1, MISRAC2012-5 */
    TS_MEMCMPS_NOCHECK(a2, b2, len2, RetVal, uint8);
  }

  return RetVal;
}


FUNC(void, BASE_CODE) TS_MemMove
(
  CONSTP2VAR(void, AUTOMATIC, BASE_APPL_DATA) dst,
  CONSTP2CONST(void, AUTOMATIC, BASE_APPL_DATA) src,
  const usize len
)
{
  /* define uint8 pointers for byte-wise access */
  /* Deviation MISRAC2012-4 */
  P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA) dst2 =
    (P2VAR(uint8, AUTOMATIC, BASE_APPL_DATA)) dst;
  P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA) src2 =
    (P2CONST(uint8, AUTOMATIC, BASE_APPL_DATA)) src;
  usize len2 = len;

  /* if the start of the source block is "behind" the start of the destination
   * block, it is safe to copy 'forewards' ... */
  if (src2 > dst2)
  {
    for (len2 = len; len2 != USIZE_C(0); len2--)
    {
      *dst2 = *src2;
      dst2++;
      src2++;
    }
  }

  /* ... and if the start of the source block is "before" the start of the destination
   * block, it is safe to copy 'backwards' ... */
  else if (src2 < dst2)
  {
    /* After incrementing by length, dest and src pointers potentially point to one element
     * PAST the last element of the array. This is defined(!) behavior as listed in C99 6.5.6/8.
     * The benefit is that now the loop never decrements beyond the first element of the array
     * (which would be undefined behavior, see 6.5.6/9!) nor is there a need for an extra check
     * to avoid this. */

    /* Deviation MISRAC2012-1 <+2> */
    dst2 += len2;
    src2 += len2;

    for (len2 = len; len2 != USIZE_C(0); len2--)
    {
      dst2--;
      src2--;
      *dst2 = *src2;
    }
  }

  /* ... otherwise the pointers are equal and there is no need to copy. */
  else
  {
    /* MISRA */
  }
}

#define BASE_STOP_SEC_CODE
#include <Base_MemMap.h>
