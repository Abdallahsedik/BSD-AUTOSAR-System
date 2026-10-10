/*************************************************************************************************************************************
@file           Reg_eSys_Exti.h
@version        1.0.0
@brief          EXTI Register Definitions for STM32F103X6 (LQFP48).
@details        Memory-mapped register structures and base addresses for the EXTI peripheral.
                This file provides the hardware abstraction layer for the EXTI unit,
                used by the AUTOSAR PORT module for external interrupt line configuration
                and routing via AFIO_EXTICR registers.
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Peripheral      : EXTI
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/

#ifndef REG_ESYS_EXTI_H_
#define REG_ESYS_EXTI_H_


/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/
#include "Platform_types.h"

/*==================================================================================================*
 *                                       Base addresses for APB2 Peripheral
 *==================================================================================================*/


#define EXTI_BASE										( 0x40010400UL )


/*==================================================================================================*
 *                                       Peripheral register
 *==================================================================================================*/

typedef struct
{
	volatile uint32 IMR;
	volatile uint32 EMR;
	volatile uint32 RTSR;
	volatile uint32 FTSR;
	volatile uint32 SWIER;
	volatile uint32 PR;
} EXTI_RegisterType;



/*==================================================================================================*
 *                                       Peripheral Instants
 *==================================================================================================*/

#define EXTI_REG				((EXTI_RegisterType *)EXTI_BASE)



#endif /* REG_ESYS_EXTI_H_ */
