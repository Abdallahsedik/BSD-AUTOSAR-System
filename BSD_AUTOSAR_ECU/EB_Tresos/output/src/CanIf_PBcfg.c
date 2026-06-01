


/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
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

#include <CanIf_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_NAME CanIf_ConfigLayout
#define TS_PB_CFG_LAYOUT_TYPE CanIf_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3, MISRAC2012-4 <START> */
CanIf_ConstConfigLayoutType CanIf_ConfigLayout = {
    { /* RootCfg */
        UINT32_C( 2147485970 ), /* PlatformSignature */
        UINT32_C( 2034454346 ), /* LcfgSignature */
        UINT32_C( 1416607236 ), /* CfgSignature */
        UINT32_C( 2372725615 ), /* PublicInfoSignature */
        TS_MAKEREF2CFG( txLPduConfig[0] ), /* txLPduConfigPtr */
        TS_MAKEREF2CFG( rxLPduConfig[0] ), /* rxLPduConfigPtr */
        TS_MAKEREF2CFG( sortedRxLPduConfig[0] ), /* sortedRxLPduConfigPtr */
        TS_MAKEREF2CFG( canDriverConfig[0] ), /* driverConfigPtr */
        UINT16_C( 2 ), /* nrOfStaticTxLPdus */
        UINT16_C( 2 ), /* nrOfTxLPdus */
        UINT16_C( 6 ) /* nrOfRxLPdus */
    },
    { /* txLPduConfig */
        { /* txLPduConfig[0] */
            UINT32_C( 768 ), /* canId */
            UINT16_C( 7 ), /* hth */
            UINT16_C( 0 ), /* sourcePduId_UL */
            UINT8_C( 3 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 2 ), /* PduLength */
            UINT8_C( 0 ) /* truncateOptions */
        },
        { /* txLPduConfig[1] */
            UINT32_C( 769 ), /* canId */
            UINT16_C( 8 ), /* hth */
            UINT16_C( 1 ), /* sourcePduId_UL */
            UINT8_C( 3 ), /* userType */
            UINT8_C( 0 ), /* intCtrlIdx */
            UINT16_C( 2 ), /* PduLength */
            UINT8_C( 0 ) /* truncateOptions */
        }
    },
    { /* rxLPduConfig */
        { /* rxLPduConfig[0] */
            UINT16_C( 0 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 3 ), /* userType */
            UINT8_C( 8 ), /* dlc */
            UINT16_C( 0 ), /* hrh */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* rxLPduConfig[1] */
            UINT16_C( 1 ), /* targetPduId */
            UINT8_C( 8 ), /* limitedPduLength */
            UINT8_C( 3 ), /* userType */
            UINT8_C( 8 ), /* dlc */
            UINT16_C( 1 ), /* hrh */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* rxLPduConfig[2] */
            UINT16_C( 2 ), /* targetPduId */
            UINT8_C( 2 ), /* limitedPduLength */
            UINT8_C( 3 ), /* userType */
            UINT8_C( 2 ), /* dlc */
            UINT16_C( 2 ), /* hrh */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* rxLPduConfig[3] */
            UINT16_C( 3 ), /* targetPduId */
            UINT8_C( 1 ), /* limitedPduLength */
            UINT8_C( 3 ), /* userType */
            UINT8_C( 1 ), /* dlc */
            UINT16_C( 3 ), /* hrh */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* rxLPduConfig[4] */
            UINT16_C( 4 ), /* targetPduId */
            UINT8_C( 2 ), /* limitedPduLength */
            UINT8_C( 3 ), /* userType */
            UINT8_C( 2 ), /* dlc */
            UINT16_C( 4 ), /* hrh */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* rxLPduConfig[5] */
            UINT16_C( 5 ), /* targetPduId */
            UINT8_C( 1 ), /* limitedPduLength */
            UINT8_C( 3 ), /* userType */
            UINT8_C( 1 ), /* dlc */
            UINT16_C( 5 ), /* hrh */
            UINT8_C( 0 ) /* intCtrlIdx */
        }
    },
    { /* driverHthConfig */
        { /* driverHthConfig[0] */
            UINT16_C( 0 ), /* firstIndex */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHthConfig[1] */
            UINT16_C( 0 ), /* firstIndex */
            UINT8_C( 0 ) /* intCtrlIdx */
        }
    },
    { /* driverHrhConfig */
        { /* driverHrhConfig[0] */
            UINT16_C( 0 ), /* firstIndex */
            UINT16_C( 1 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[1] */
            UINT16_C( 2 ), /* firstIndex */
            UINT16_C( 3 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[2] */
            UINT16_C( 4 ), /* firstIndex */
            UINT16_C( 5 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[3] */
            UINT16_C( 6 ), /* firstIndex */
            UINT16_C( 7 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[4] */
            UINT16_C( 8 ), /* firstIndex */
            UINT16_C( 9 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        },
        { /* driverHrhConfig[5] */
            UINT16_C( 10 ), /* firstIndex */
            UINT16_C( 11 ), /* lastIndex */
            UINT8_C( 0 ), /* swFiltering */
            UINT8_C( 0 ) /* intCtrlIdx */
        }
    },
    { /* hohIdToCanIfIdx */
        UINT16_C( 0 ), /* hohIdToCanIfIdx[0] */
        UINT16_C( 1 ), /* hohIdToCanIfIdx[1] */
        UINT16_C( 2 ), /* hohIdToCanIfIdx[2] */
        UINT16_C( 3 ), /* hohIdToCanIfIdx[3] */
        UINT16_C( 4 ), /* hohIdToCanIfIdx[4] */
        UINT16_C( 5 ), /* hohIdToCanIfIdx[5] */
        UINT16_C( 65535 ), /* hohIdToCanIfIdx[6] */
        UINT16_C( 0 ), /* hohIdToCanIfIdx[7] */
        UINT16_C( 1 ) /* hohIdToCanIfIdx[8] */
    },
    { /* canControllerConfig */
        { /* canControllerConfig[0] */
            UINT8_C( 0 ) /* controllerId */
        }
    },
    { /* canDriverConfig */
        { /* canDriverConfig[0] */
            TS_MAKEREF2CFG( canControllerConfig[0] ), /* ctrlConfigPtr */
            TS_MAKEREF2CFG( hohIdToCanIfIdx[0] ), /* hohIdToCanIfIdxPtr */
            TS_MAKEREF2CFG( driverHthConfig[0] ), /* hthConfigPtr */
            TS_MAKEREF2CFG( driverHrhConfig[0] ), /* hrhConfigPtr */
            UINT8_C( 1 ) /* nrOfControllers */
        }
    },
    { /* sortedRxLPduConfig */
        { /* sortedRxLPduConfig[0] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 512 ), /* canId */
            UINT16_C( 0 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[1] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742336 ), /* canId */
            UINT16_C( 0 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[2] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 513 ), /* canId */
            UINT16_C( 1 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[3] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742337 ), /* canId */
            UINT16_C( 1 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[4] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 256 ), /* canId */
            UINT16_C( 2 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[5] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742080 ), /* canId */
            UINT16_C( 2 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[6] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 928 ), /* canId */
            UINT16_C( 3 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[7] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742752 ), /* canId */
            UINT16_C( 3 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[8] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 736 ), /* canId */
            UINT16_C( 4 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[9] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742560 ), /* canId */
            UINT16_C( 4 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[10] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 416 ), /* canId */
            UINT16_C( 5 ) /* rxLPduIndex */
        },
        { /* sortedRxLPduConfig[11] */
            UINT32_C( 4294967295 ), /* upperRangeCanId */
            UINT32_C( 1073742240 ), /* canId */
            UINT16_C( 5 ) /* rxLPduIndex */
        }
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3, MISRAC2012-4 <STOP> */

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

