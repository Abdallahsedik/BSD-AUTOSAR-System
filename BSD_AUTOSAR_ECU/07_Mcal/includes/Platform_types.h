/*************************************************************************************************************************************
@file Platform Types.h
@version 1.0.0
@brief AUTOSAR Base - Platform Types definition.
@details AUTOSAR Platform Types header file.
It contains all platform dependent types and symbols. Those types must be abstracted in order to become platform and compiler independent.
@author abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project : AUTOSAR 4.4.0 MCAL
Platform  : ARM
Peripheral : STM32F103X6
Autosar Version : 4.4.0
Vendor Release : R24-11 
Autosar Revision : ASR_REL_4_4_REV_0000
Sw Version : 1.0.0
*************************************************************************************************************************************/
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_VENDOR_ID                      43

#define PLATFORM_AR_RELEASE_MAJOR_VERSION       4
#define PLATFORM_AR_RELEASE_MINOR_VERSION       4
#define PLATFORM_AR_RELEASE_REVISION_VERSION    0

#define PLATFORM_SW_MAJOR_VERSION               1
#define PLATFORM_SW_MINOR_VERSION               0
#define PLATFORM_SW_PATCH_VERSION               0
/*==================================================================================================
*                                       TYPE DEFINITIONS
==================================================================================================*/
/*---------CPU Type------------------*/
/**
* @brief          8bit Type Processor
* @implements     CPU_TYPE_enumeration
*/
#define CPU_TYPE_8 8

/**
* @brief          16bit Type Processor
* @implements     CPU_TYPE_enumeration
*/
#define CPU_TYPE_16 16

/**
* @brief          32bit Type Processor
* @implements     CPU_TYPE_enumeration
*/
#define CPU_TYPE_32 32

/**
* @brief          64bit Type Processor
* @implements     CPU_TYPE_enumeration
*/
#define CPU_TYPE_64 64



/*---------Bit Ordering (Register)----------------*/

/**
* @brief          MSB First Processor
* @implements     CPU_BIT_ORDER_enumeration
*/
#define MSB_FIRST 0

/**
* @brief          LSB First Processor
* @implements     CPU_BIT_ORDER_enumeration
*/
#define LSB_FIRST 1


/*---------Byte Ordering (Memory)----------------*/
/**
* @brief          HIGH_BYTE_FIRST Processor
* @implements     CPU_BYTE_ORDER_enumeration
*/
#define HIGH_BYTE_FIRST 0

/** 
* @brief          LOW_BYTE_FIRST Processor
* @implements     CPU_BYTE_ORDER_enumeration
*/
#define LOW_BYTE_FIRST 1
 

/*---------Boolean----------------*/
/**
* @brief          Boolean Type Definition
* @implements     boolean_type
*/
typedef unsigned char boolean;

#ifndef TRUE
    /** 
    * @brief Boolean true value
    * @implements TRUE_FALSE_enumeration
    */
    #define TRUE 1
#endif
#ifndef FALSE
    /** 
    * @brief Boolean false value
    * @implements TRUE_FALSE_enumeration
    */
    #define FALSE 0
#endif

/*--------- Unsigned types----------------*/

/** 
* @brief Unsigned 8 bit integer with range of 0 ..+255 (0x00..0xFF) - 
*        8 bit
* @implements uint8_type
*/
typedef unsigned char uint8;

/** 
* @brief Unsigned 16 bit integer with range of 0 ..+65535 (0x0000..0xFFFF) - 
*        16 bit
* @implements uint16_type
*/
typedef unsigned short uint16;

/** 
* @brief Unsigned 32 bit integer with range of 0 ..+4294967295 (0x00000000..0xFFFFFFFF) - 
*        32 bit
* @implements uint32_type
*/
typedef unsigned long uint32;

/** 
* @brief Unsigned 64 bit integer with range of 0..18446744073709551615 (0x0000000000000000..0xFFFFFFFFFFFFFFFF)-
*        64 bit
* @implements uint64_type
*/
typedef unsigned long long uint64;



/*---------  signed types----------------*/

/** 
* @brief Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F) - 
*        7 bit + 1 sign bit 
* @implements sint8_type
*/
typedef signed char sint8;


/** 
* @brief Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF) - 
*        15 bit + 1 sign bit 
* @implements sint16_type
*/
typedef signed short sint16;

/** 
* @brief Signed 32 bit integer with range of -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF) - 
*        31 bit + 1 sign bit 
* @implements sint32_type
*/
typedef signed long sint32;

/** 
* @brief Signed 64 bit integer with range of -9223372036854775808..9223372036854775807 (0x8000000000000000..0x7FFFFFFFFFFFFFFF )- 
*        63 bit + 1 sign bit 
* @implements sint64_type
*/
typedef signed long long sint64;


/*--------- Unsigned least types----------------*/

/** 
* @brief Unsigned integer at least 8 bit long. Range of at least 0 ..+255 (0x00..0xFF) - 
*        8 bit
* @implements uint8_least_type
*/
typedef unsigned char  uint8_least;

/** 
* @brief  Unsigned integer at least 16 bit long. Range of at least 0 ..+65535 (0x0000..0xFFFF) - 
*         16 bit
* @implements uint16_least_type
*/
typedef unsigned short uint16_least;

/** 
* @brief Unsigned integer at least 32 bit long. Range of at least 0 ..+4294967295 
*       (0x00000000..0xFFFFFFFF) - 32 bit
* @implements uint32_least_type
*/
typedef unsigned long uint32_least;

/*--------- signed least types----------------*/

/** 
* @brief Signed integer at least 8 bit long. Range - at least -128 ..+127. 
*        At least 7 bit + 1 bit sign
* @implements sint8_least_type
*/
typedef signed char sint8_least;

/** 
* @brief Signed integer at least 16 bit long. Range - at least -32768 ..+32767. 
*        At least 15 bit + 1 bit sign
* @implements sint16_least_type
*/
typedef signed short sint16_least;

/** 
* @brief Signed integer at least 32 bit long. Range - at least -2147483648.. +2147483647. 
*       At least 31 bit + 1 bit sign
* @implements sint32_least_type
*/
typedef signed long sint32_least;


/*--------- float types----------------*/

/** 
* @brief 32bit long floating point data type
* @implements float32_type
*/
typedef float float32;

/** 
* @brief 64bit long floating point data type
* @implements float64_type
*/
typedef double float64;

/*---------Pointer Types----------------*/

/**
* @brief          This standard AUTOSAR type shall be a void pointer
* @implements     VoidPtr_type
*/
typedef void* VoidPtr;

/**
* @brief          This standard AUTOSAR type shall be a void pointer to const
* @implements     ConstVoidPtr_type
*/
typedef const void* ConstVoidPtr;

/*==================================================================================================
*                                        Symbol definitions
==================================================================================================*/
/**
 * @brief       For each platform the register width of the CPU used shall
 *              be indicated by defining CPU_TYPE.
 * @implements  CPU_TYPE_enumeration
 * 
 */
#define CPU_TYPE      CPU_TYPE_32  // (CPU_TYPE_8, CPU_TYPE_16 , CPU_TYPE_32 or CPU_TYPE_64)

 
/** 
* @brief          Bit order on register level.
* @implements     CPU_BIT_ORDER_enumeration
*/
#define CPU_BIT_ORDER  (LSB_FIRST)  //(LSB_FIRST  , MSB_FIRST  )

/** 
* @brief The byte order on memory level shall be indicated in the platform types header file using 
*        the symbol CPU_BYTE_ORDER.
* @implements     CPU_BYTE_ORDER_enumeration
*/
#define CPU_BYTE_ORDER (LOW_BYTE_FIRST) // (LOW_BYTE_FIRST  , HIGH_BYTE_FIRST  )



#endif /* PlatformTypes.h*/
