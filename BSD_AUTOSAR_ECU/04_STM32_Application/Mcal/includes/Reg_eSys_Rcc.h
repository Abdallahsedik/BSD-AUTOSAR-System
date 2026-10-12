/*************************************************************************************************************************************
@file           Reg_eSys_Rcc.h
@version        1.0.0
@brief          RCC Register Definitions for STM32F103X6 (LQFP48).
@details        Memory-mapped register structures and base addresses for the RCC peripheral.
                This file provides the hardware abstraction layer for the RCC unit,
                used by the AUTOSAR MCU module for clock initialization and configuration,
                and referenced by the PORT module to enable GPIO/AFIO peripheral clocks.
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Peripheral      : RCC
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/


#ifndef REG_ESYS_RCC_H_
#define REG_ESYS_RCC_H_

/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/

#include "Platform_types.h"

/*==================================================================================================*
 *                                       Base addresses for AHB Peripheral
 *==================================================================================================*/

#define RCC_BASE_ADDRESS										( 0x40021000UL )

/*==================================================================================================*
 *                                       Peripheral registers
 *==================================================================================================*/

typedef struct
{
	volatile uint32 CR;
	volatile uint32 CFGR;
	volatile uint32 CIR;
	volatile uint32 APB2RSTR;
	volatile uint32 APB1RSTR;
	volatile uint32 AHBENR;
	volatile uint32 APB2ENR;
	volatile uint32 APB1ENR;
	volatile uint32 BDCR;
	volatile uint32 CSR;
} RCC_RegisterType;


/*==================================================================================================*
 *                                       Peripheral Instants
 *==================================================================================================*/

#define RCC_REG 				((RCC_RegisterType  *)RCC_BASE_ADDRESS  )
/*==================================================================================================*
 *                                       Bits Configuration
 *==================================================================================================*/

/* RCC->CR bit positions */
#define HSION                    0u
#define HSEON                    16u
#define PLLON                    24u
#define HSEBYP                   18u

#define HSIRDY                   1u
#define HSERDY                   17u
#define PLLRDY                   25u

/*CFGR  BITS*/
#define SW0                     0
#define SW1                     1
#define SWS_MASK 				0x3uL
#define SWS_POS   				2uL

/* RCC->CFGR bit positions */
#define PLLSRC     16u
#define PLLXTPRE   17u
#define PLLMUL_pos 18u
#define PLLMUL_MASK (0xFuL << PLLMUL_pos)

#define SWS_MASK 			0x3uL
#define SWS_POS   			2uL


/*Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
Set and cleared by software to control the division factor of the APB high-speed clock (PCLK2).
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16*/

/*
 *
 *
Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
Set and cleared by software to control the division factor of the APB low-speed clock
(PCLK1).
Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16
*/

/*
Bits 7:4 HPRE: AHB prescaler
Set and cleared by software to control the division factor of the AHB clock.
0xxx: SYSCLK not divided
1000: SYSCLK divided by 2
1001: SYSCLK divided by 4
1010: SYSCLK divided by 8
1011: SYSCLK divided by 16
1100: SYSCLK divided by 64
1101: SYSCLK divided by 128
1110: SYSCLK divided by 256
1111: SYSCLK divided by 512*/

#define RCC_CFGR_HPRE_POS    4uL
#define RCC_CFGR_HPRE_MASK  (0xFuL << RCC_CFGR_HPRE_POS)
#define RCC_CFGR_PPRE1_POS   8uL
#define RCC_CFGR_PPRE1_MASK (0x7uL << RCC_CFGR_PPRE1_POS)
#define RCC_CFGR_PPRE2_POS  11uL
#define RCC_CFGR_PPRE2_MASK (0x7uL << RCC_CFGR_PPRE2_POS)

#define RCC_APB1ENR_TIM2EN 0
#define RCC_APB1ENR_TIM3EN 1
#define RCC_APB2ENR_TIM1EN 1


#define RCC_APB1ENR_CAN1ENABLE                   (0x1UL << 25U)            /*!< CAN1 clock enable */
#define RCC_APB2ENR_AFIOENABLE                  	(0x1UL <<0U)

#endif /* REG_ESYS_RCC_H_ */
