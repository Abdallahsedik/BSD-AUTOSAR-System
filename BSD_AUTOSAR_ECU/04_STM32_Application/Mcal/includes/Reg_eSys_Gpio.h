/*************************************************************************************************************************************
@file           Reg_eSys_Gpio.h
@version        1.0.0
@brief          GPIO Register Definitions for STM32F103X6 (LQFP48).
@details        Memory-mapped register structures and base addresses for GPIO ports (A-D).
                This file provides the hardware abstraction layer for the GPIO unit,
                used by the AUTOSAR PORT module for pin initialization and mode configuration,
                and by the AUTOSAR DIO module for pin read/write operations.
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Peripheral      : GPIO (Port A, B, C, D)
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/

#ifndef REG_ESYS_GPIO_H_
#define REG_ESYS_GPIO_H_

/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/
#include "Std_Types.h"


/*==================================================================================================*
 *                                       Base addresses for GPIO
 *==================================================================================================*/

//A,B fully included in LQFP48 Package
#define GPIOA_BASE_ADDRESS										( 0x40010800UL )
#define GPIOB_BASE_ADDRESS										( 0x40010C00UL )
//C,D Partial  included in LQFP48 Package
#define GPIOC_BASE_ADDRESS										( 0x40011000UL )
#define GPIOD_BASE_ADDRESS										( 0x40011400UL )

/*==================================================================================================*
 *                                       Peripheral register
 *==================================================================================================*/

/*---------   * GPIO registers * ------------------*/
typedef struct
{
	volatile uint32 CRL;
	volatile uint32 CRH;
	volatile uint32 IDR;
	volatile uint32 ODR;
	volatile uint32 BSRR;
	volatile uint32 BRR;
	volatile uint32 LCKR;
} Gpio_RegisterType;

/*==================================================================================================*
 *                                       Peripheral Instants
 *==================================================================================================*/

/*---------   * GPIO Instants * ------------------*/

#define GPIOA_REG               ((Gpio_RegisterType *)GPIOA_BASE_ADDRESS)
#define GPIOB_REG               ((Gpio_RegisterType *)GPIOB_BASE_ADDRESS)
#define GPIOC_REG               ((Gpio_RegisterType *)GPIOC_BASE_ADDRESS)
#define GPIOD_REG               ((Gpio_RegisterType *)GPIOD_BASE_ADDRESS)


/*---------   * GPIO Instants * ------------------*/
extern Gpio_RegisterType* const Gpio_PortLuk[4];

#endif /* REG_ESYS_GPIO_H_ */
