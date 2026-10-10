/*************************************************************************************************************************************
@file           Mcu.h
@version        1.0.0
@brief          AUTOSAR MCU Driver Header (STM32F103X6).
@details        AUTOSAR 4.4.0 MCU module public interface. Contains the external 
                API declarations, data types, and macros required to use the MCU 
                clock, reset, and power management services.
@author         abdallah mohamed sedik
 *************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Module          : MCU
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
 *************************************************************************************************************************************/
#ifndef MCU_H_
#define MCU_H_


/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/
#include "Reg_eSys_Rcc.h"
#include "Std_Types.h"
#include "Mcu_Cfg.h"
/*==================================================================================================
 *                                       Private Macros
==================================================================================================*/
//
//#define HSI                      0
//#define HSE                      1
//#define PLL                      2

/* Symbolic names for clock setting IDs (= McuClockSettingId, 0..255) */
typedef uint8 Mcu_ClockType;


#define MCU_CLOCKSETTING_HSI    ((Mcu_ClockType)0u)
#define MCU_CLOCKSETTING_HSE    ((Mcu_ClockType)1u)
#define MCU_CLOCKSETTING_PLL    ((Mcu_ClockType)2u)
#define MCU_CLOCKSETTING_COUNT  3u
typedef enum
{
	HSI,
	HSE,
	PLL
}Mcu_Clk_Src_type;

typedef enum
{
	NOT_BYPASSED,
	BYPASSED
}Hse_Bypassed_type;

typedef enum
{
	MCU_PLL_SRC_HSI_DIV2,
	MCU_PLL_SRC_HSE
}Mcu_PllSrc_type;

typedef enum
{
	MCU_PLL_MUL_2  = 0x0uL,
	MCU_PLL_MUL_3  = 0x1uL,
	MCU_PLL_MUL_4  = 0x2uL,
	MCU_PLL_MUL_5  = 0x3uL,
	MCU_PLL_MUL_6  = 0x4uL,
	MCU_PLL_MUL_7  = 0x5uL,
	MCU_PLL_MUL_8  = 0x6uL,
	MCU_PLL_MUL_9  = 0x7uL,
	MCU_PLL_MUL_10 = 0x8uL,
	MCU_PLL_MUL_11 = 0x9uL,
	MCU_PLL_MUL_12 = 0xAuL,
	MCU_PLL_MUL_13 = 0xBuL,
	MCU_PLL_MUL_14 = 0xCuL,
	MCU_PLL_MUL_15 = 0xDuL,
	MCU_PLL_MUL_16 = 0xEuL
}Mcu_PllMul_type;


typedef enum
{
	MCU_HSE_NOT_DIV,
	MCU_HSE_DIV_2
}Mcu_PLLXTPRE_type;

typedef enum
{
	MCU_APB_DIV_1 = 0x0uL,
	MCU_APB_DIV_2 = 0x4uL,
	MCU_APB_DIV_4 = 0x5uL,
	MCU_APB_DIV_8 = 0x6uL,
	MCU_APB_DIV_16= 0x7uL
}Mcu_APB_Pre_type;

typedef enum
{
	MCU_AHB_DIV_1  = 0x0uL,
	MCU_AHB_DIV_2  = 0x8uL,
	MCU_AHB_DIV_4  = 0x9uL,
	MCU_AHB_DIV_8  = 0xAuL,
	MCU_AHB_DIV_16 = 0xBuL,
	MCU_AHB_DIV_64 = 0xCuL,
	MCU_AHB_DIV_128= 0xDuL,
	MCU_AHB_DIV_256= 0xEuL,
	MCU_AHB_DIV_512= 0xFuL
}Mcu_AHB_Pre_type;


typedef struct
{
	Mcu_Clk_Src_type clk_src;
	Mcu_AHB_Pre_type  AHB_Prescaler;
	Mcu_APB_Pre_type APB1_Prescaler;
	Mcu_APB_Pre_type APB2_Prescaler;
	Hse_Bypassed_type HseBypass;
	Mcu_PllSrc_type    PllSrc;
	Mcu_PllMul_type    PllMul;
	Mcu_PLLXTPRE_type  PllXtPre;
}Mcu_ClockSettingConfigType;


Std_ReturnType Mcu_InitClock (const Mcu_ClockType  ClockSetting );

#endif /* MCU_H_ */
