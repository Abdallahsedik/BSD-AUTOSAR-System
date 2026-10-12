/*************************************************************************************************************************************
@file           Reg_eSys_Afio.h
@version        1.0.0
@brief          AFIO Register Definitions for STM32F103X6 (LQFP48).
@details        Memory-mapped register structures and base addresses for AFIO peripheral.
                This file provides the hardware abstraction layer for the AFIO unit,
                used by the AUTOSAR PORT module for pin remap and alternate function selection.
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Peripheral      : AFIO
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/

#ifndef REG_ESYS_AFIO_H_
#define REG_ESYS_AFIO_H_


/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/
#include "Platform_types.h"

/*==================================================================================================*
 *                                       Base addresses for APB2 Peripherals
 *==================================================================================================*/

/*---------   * AFIO * ------------------*/
#define AFIO_BASE										( 0x40010000UL )

/*==================================================================================================*
 *                                       Peripheral register
 *==================================================================================================*/
/*---------   * AFIO registers * ------------------*/

typedef struct
{
	volatile uint32 EVCR;
	volatile uint32 MAPR;
	volatile uint32 EXTICR[4];
	volatile uint32 RESERVED0;
	volatile uint32 MAPR2;
} AFIO_RegisterType;
/*==================================================================================================*
 *                                       Peripheral Instants
 *==================================================================================================*/
#define AFIO_REG                ((AFIO_RegisterType *)AFIO_BASE)



#endif /* REG_ESYS_AFIO_H_ */
