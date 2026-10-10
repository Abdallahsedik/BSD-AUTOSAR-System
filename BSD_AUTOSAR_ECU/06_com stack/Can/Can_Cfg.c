/*************************************************************************************************************************************
@file           Can_Cfg.c
@version        1.0.0
@brief          AUTOSAR CAN Driver Configuration Source (STM32F103X6).
@details        Contains the static configuration data for the CAN driver.
@author         abdallah mohamed sedik
 *************************************************************************************************************************************/

#include "Can_Cfg.h"

/*==================================================================================================
 *                                BAUDRATE CONFIGURATION
==================================================================================================*/


/* Baudrate table defined at compile time */
const Can_ControllerBaudrateConfigType Can_BaudrateTable[CAN_NUM_BAUDRATE_CONFIGS] =
{
		/* ID=0: ~125k baudrate */
		{ .TS2 = 1, .TS1 = 	6, .SJW = 1, .Prescaler = 1, .LoopBack = FALSE, .Silent = FALSE },

		/* ID=1: ~250k baudrate */
		{ .TS2 = 2, .TS1 = 7, .SJW = 1, .Prescaler = 9,  .LoopBack = FALSE, .Silent = FALSE },

		/* ID=2: ~500k baudrate */
		{ .TS2 = 2, .TS1 = 7, .SJW = 1, .Prescaler = 4,  .LoopBack = FALSE, .Silent = FALSE }
};

/*==================================================================================================
 *                                MAIN CONFIGURATION STRUCTURE
==================================================================================================*/

/* Main configuration structure passed to Can_Init */
const Can_ConfigType Can_Config =
{
		/* BaudrateConfig: Default baudrate is set to 250k (Index 1) */
		.BaudrateConfig =
		{
				.TS2       = 1,
				.TS1       = 6,
				.SJW       = 1,
				.Prescaler = 1,
				.LoopBack  = FALSE,
				.Silent    = FALSE
		},

		/* FilterConfig: Array of filter configurations directly initialized */
		.FilterConfig =
		{
				/* Filter 0: 16-bit List mode (Standard IDs) */
				{
						.FilterBank = 0,
						.Scale      = CAN_FILTER_SCALE_16BIT,
						.Mode       = CAN_FILTER_MODE_LIST,
						.ExtendedId = FALSE,
						.Id1        = 0x100,  /* ABS ECU */
						.Id2        = 0x1A0,  /* TCU */
						.Id3        = 0x200,  /* Radar Left */
						.Id4        = 0x201   /* Radar Right */
				},
				/* Filter 1: 16-bit List mode (Standard IDs) */
				{
						.FilterBank = 1,
						.Scale      = CAN_FILTER_SCALE_16BIT,
						.Mode       = CAN_FILTER_MODE_LIST,
						.ExtendedId = FALSE,
						.Id1        = 0x3A0,  /* BCM */
						.Id2        = 0x2E0,  /* EPS ECU */
						.Id3 		= 0x3A0,
						.Id4 		= 0x2E0,
				}
		}
};
