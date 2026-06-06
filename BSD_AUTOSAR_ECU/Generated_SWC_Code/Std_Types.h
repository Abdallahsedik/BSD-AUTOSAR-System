/*************************************************************************************************************************************
@file Std Types.h
@version 1.0.0
@brief AUTOSAR Base - Standard types definition.
@details AUTOSAR standard types header file.
It contains all types that are used across several modules of the basic software and that are platform and compiler independent
@author abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project : AUTOSAR 4.4.0 MCAL
Platform  : ARM
Peripheral : STM32F407
Autosar Version : 4.4.0
Autosar Revision : ASR_REL_4_0_REV_0000
Sw Version : 1.0.0
*************************************************************************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** 
@brief Include Platform abstraction
*/ 
# include "Platform_Types.h"
/**
* @brief Include Compiler abstraction
*/
#include "Compiler.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief Parameters that shall be published within the standard types header file and also in the
*        module's description file
*/
#define STD_VENDOR_ID                     43
#define STD_AR_RELEASE_MAJOR_VERSION      4
#define STD_AR_RELEASE_MINOR_VERSION      4
#define STD_AR_RELEASE_REVISION_VERSION   0

#define STD_SW_MAJOR_VERSION              1
#define STD_SW_MINOR_VERSION              0
#define STD_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Platform_Types header file are of the same Autosar version */
#if ((STD_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
    (STD_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Std_Types.h and Platform_Types.h are different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Compiler header file are of the same Autosar version */
#if ((STD_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION) || \
    (STD_AR_RELEASE_MINOR_VERSION != COMPILER_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Std_Types.h and Compiler.h are different"
#endif
#endif

/*****************************************************************
 *                                    CONSTANTS
 ******************************************************************/
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
* @brief Logical state idle
* @implements Symbol Definitions Enumeration
*/ 
#define STD_IDLE    0x00u 

/** 
* @brief Logical state active
* @implements Symbol Definitions Enumeration
*/ 
#define STD_ACTIVE   0x01u 

/** 
* @brief OFF State
* @implements Symbol Definitions Enumeration
*/ 
#define STD_OFF      0x00u

/** 
* @brief ON State
* @implements Symbol Definitions Enumeration
*/ 
#define STD_ON       0x01u 


/** 
* @brief This type can be used as standard API return type which is shared between the RTE and the BSW modules.
* @implements STD_ReturnType_Type
*/ 
typedef uint8 Std_ReturnType;

/** 
* @brief This type shall be used to request the version of a BSW module using the <Module name>_GetVersionInfo() function.
* @implements Std_VersionInfoType_Structure
*/ 
typedef struct
{
    uint16 vendorID;
    uint16 moduleID;
    uint8 sw_major_version;
    uint8 sw_minor_version;
    uint8 sw_patch_version;
}Std_VersionInfoType;

#endif /* STD_TYPES_H */
