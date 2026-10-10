/*************************************************************************************************************************************
@file           Can_Cfg.h
@version        1.0.0
@brief          AUTOSAR CAN Driver Configuration Header (STM32F103X6).
@details        Declares the configuration structures and constants for the CAN driver.
                This file contains the post-build configuration parameters.
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

#ifndef CAN_CFG_H_
#define CAN_CFG_H_

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_CFG_VENDOR_ID               43U
#define CAN_CFG_MODULE_ID               124U

#define CAN_CFG_SW_MAJOR_VERSION        1U
#define CAN_CFG_SW_MINOR_VERSION        0U
#define CAN_CFG_SW_PATCH_VERSION        0U

/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/
#include "Can_GeneralTypes.h"

/*==================================================================================================
 *                                CONFIGURATION CONSTANTS
==================================================================================================*/

/* Number of filters used in this configuration */
#define NUM_FILTERS                     2u

/* Number of available baudrate configurations */
#define CAN_NUM_BAUDRATE_CONFIGS        3u

/*==================================================================================================
 *                                EXTERNAL DECLARATIONS
==================================================================================================*/

/* Baudrate table */
extern const Can_ControllerBaudrateConfigType Can_BaudrateTable[CAN_NUM_BAUDRATE_CONFIGS];

/* Main CAN configuration structure */
extern const Can_ConfigType Can_Config;

#endif /* CAN_CFG_H_ */
