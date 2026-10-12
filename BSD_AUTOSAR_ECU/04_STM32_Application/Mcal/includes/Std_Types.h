/*************************************************************************************************************************************
@file Std Types.h
@version 1.0.0
@brief AUTOSAR Base - Standard types definition.
@details AUTOSAR standard types header file.
It contains all types that are used across several modules of the basic software and that are platform and compiler independent
@author abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Autosar Version : 4.4.0
Vendor  Release : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include "Platform_types.h"

#ifndef STD_ON
#define STD_ON   1u
#endif

#ifndef STD_OFF
#define STD_OFF  0u
#endif

#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif

/**
* @brief Physical state 0V
* @implements Symbol Definitions Enumeration
*/
#define STD_LOW      0x00u       /* Physical state 0V          */


/**
* @brief Physical state 5V or 3.3V
* @implements Symbol Definitions Enumeration
*/
#define STD_HIGH     0x01u

/**
* @brief Return Code ok
* @implements Symbol Definitions Enumeration
*/
#ifndef STATUSTYPEDEFINED
    #define STATUSTYPEDEFINED
    /**
     * @brief Success return code
     */
    #define E_OK 0x00u
     /**
     * @brief this type is defined for OSEK compliance
     */
    typedef unsigned char StatusType;
 #endif

/**
* @brief Return Code Failure /error
* @implements Symbol Definitions Enumeration
*/
#define E_NOT_OK    0x01u




/**
* @brief This type can be used as standard API return type which is shared between the RTE and the BSW modules.
* @implements STD_ReturnType_Type
*/
typedef uint8 Std_ReturnType;

typedef struct
{
    uint16 vendorID;
    uint16 moduleID;
    uint8  sw_major_version;
    uint8  sw_minor_version;
    uint8  sw_patch_version;
} Std_VersionInfoType;
#endif /* STD_TYPES_H_ */
