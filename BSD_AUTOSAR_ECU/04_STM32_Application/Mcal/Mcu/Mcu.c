/*************************************************************************************************************************************
@file           Mcu.c
@version        1.0.0
@brief          AUTOSAR MCU Driver (STM32F103X6).
@details        AUTOSAR 4.4.0 MCU module implementation. Provides initialization and 
                control of the microcontroller clock, PLL configuration, reset handling, 
                and low power mode transitions.
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
/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/
#include "Mcu.h"


#define CLK_READY_TIMEOUT   100000uL



const Mcu_ClockSettingConfigType Mcu_ClockSetting_HSI=
{
		HSI ,
		MCU_AHB_DIV_1,
		MCU_APB_DIV_1,
		MCU_APB_DIV_1,
		NOT_BYPASSED,
		MCU_PLL_SRC_HSE,
		MCU_HSE_DIV_2,
		MCU_PLL_MUL_9
};
const Mcu_ClockSettingConfigType Mcu_ClockSetting_HSE=
{
		HSE ,
		MCU_AHB_DIV_1,
		MCU_APB_DIV_1,
		MCU_APB_DIV_1,
		BYPASSED,
		MCU_PLL_SRC_HSE,
		MCU_HSE_DIV_2,
		MCU_PLL_MUL_9
};
const Mcu_ClockSettingConfigType Mcu_ClockSetting_PLL=
{
		PLL,
		MCU_AHB_DIV_1,
		MCU_APB_DIV_1,
		MCU_APB_DIV_1,
		NOT_BYPASSED,
		MCU_PLL_SRC_HSE,
		MCU_HSE_DIV_2,
		MCU_PLL_MUL_9    /* 8 MHz HSE x9 = 72 MHz */
};
const Mcu_ClockSettingConfigType Mcu_Config[]=
{
		Mcu_ClockSetting_HSI,
		Mcu_ClockSetting_HSE,
		Mcu_ClockSetting_PLL


};

Std_ReturnType Mcu_InitClock (const Mcu_ClockType  ClockSetting )
{
	Std_ReturnType ret    = E_OK;
	uint32         timeout= CLK_READY_TIMEOUT;
	const Mcu_ClockSettingConfigType * ConfigPtr;
	if (ClockSetting >= MCU_CLOCKSETTING_COUNT)
	{
		return E_NOT_OK;
	}
	ConfigPtr = &Mcu_Config[ClockSetting];

	if((ConfigPtr->clk_src)> PLL )
	{
		return E_NOT_OK;
	}
	else
	{
		/*
		 *Bits 7:4 HPRE: AHB prescaler Set and cleared by software to control the division factor of the AHB clock.
		 *0xxx: SYSCLK not divided
		 *1000: SYSCLK divided by 2
		 *1001: SYSCLK divided by 4
		 * */
		RCC_REG->CFGR &= ~RCC_CFGR_HPRE_MASK;
		RCC_REG->CFGR|=((ConfigPtr->AHB_Prescaler)<<RCC_CFGR_HPRE_POS) ;

		/*Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
		 * Set and cleared by software to control the division factor of the APB low-speed clock(PCLK1).
		 *Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
		 *0xx: HCLK not divided
		 *100: HCLK divided by 2
		 *101: HCLK divided by 4
		 *110: HCLK divided by 8
		 *111: HCLK divided by 16*/
		RCC_REG->CFGR &= ~RCC_CFGR_PPRE1_MASK;
		RCC_REG->CFGR|=((ConfigPtr->APB1_Prescaler)<<RCC_CFGR_PPRE1_POS) ;

		/*Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
		 *Set and cleared by software to control the division factor of the APB high-speed clock(PCLK2).
		 *0xx: HCLK not divided
		 *100: HCLK divided by 2
		 *101: HCLK divided by 4
		 *110: HCLK divided by 8
		 *111: HCLK divided by 16*/
		RCC_REG->CFGR &= ~RCC_CFGR_PPRE2_MASK;
		RCC_REG->CFGR|=((ConfigPtr->APB2_Prescaler)<<RCC_CFGR_PPRE2_POS) ;
		switch (ConfigPtr->clk_src)
		{
		case HSI:
			/* 1- Enable HSI */
			RCC_REG->CR |= (1UL << HSION);
			/* 2- Wait for HSIRDY  */
			while( ((RCC_REG->CR & (1UL << HSIRDY)) == 0u) && (timeout > 0u) )
			{
				timeout--;
			}
			if(timeout == 0u)
			{
				ret = E_NOT_OK;
			}
			else
			{
				/* 3- Select HSI as system clock: SW = 00 */
				RCC_REG->CFGR &= ~((1UL << SW0) | (1UL << SW1));
			}
			break;
		case HSE:
			/* 1- Configure bypass BEFORE enabling */

			if(ConfigPtr->HseBypass == BYPASSED)
			{
				RCC_REG->CR |= (1UL << HSEBYP);

			}
			else
			{
				RCC_REG->CR &= ~(1UL << HSEBYP);
			}

			/* 2- Enable HSE */
			RCC_REG->CR |= (1UL << HSEON);

			/* 3- Wait for HSERDY  */
			while( ((RCC_REG->CR & (1UL << HSERDY)) == 0u) && (timeout > 0u) )
			{
				timeout--;
			}

			if(timeout == 0u)
			{
				ret = E_NOT_OK;
			}
			else
			{
				/* 4- Select HSE as system clock: SW = 01 */
				RCC_REG->CFGR |=  (1UL << SW0);
				RCC_REG->CFGR &= ~(1UL << SW1);
			}

			break;
		case PLL:
			/* PLLSRC / PLLXTPRE / PLLMUL are only writable while PLLON = 0 */
			RCC_REG->CR &= ~(1UL << PLLON);
			while( (RCC_REG->CR & (1UL << PLLRDY)) != 0u );

			if(ConfigPtr->PllSrc == MCU_PLL_SRC_HSE)
			{
				RCC_REG->CFGR |= (1UL << PLLSRC);

				if(ConfigPtr->HseBypass == BYPASSED) { RCC_REG->CR |= (1UL << HSEBYP); }
				else                                 { RCC_REG->CR &= ~(1UL << HSEBYP); }

				RCC_REG->CR |= (1UL << HSEON);
				while( ((RCC_REG->CR & (1UL << HSERDY)) == 0u) && (timeout > 0u) )
				{
					timeout--;
				}

				if(timeout != 0u)
				{
					if(ConfigPtr->PllXtPre == MCU_HSE_DIV_2)
					{
						RCC_REG->CFGR |= (1UL << PLLXTPRE);
					}
					else
					{
						RCC_REG->CFGR &= ~(1UL << PLLXTPRE);
					}
				}
			}
			else
			{
				RCC_REG->CFGR &= ~(1UL << PLLSRC); /* HSI/2 */
			}

			if(timeout == 0u)
			{
				ret = E_NOT_OK;
				break;
			}

			RCC_REG->CFGR &= ~PLLMUL_MASK;
			RCC_REG->CFGR |= ((ConfigPtr->PllMul) << PLLMUL_pos);

			RCC_REG->CR |= (1UL << PLLON);
			timeout = CLK_READY_TIMEOUT;
			while( ((RCC_REG->CR & (1UL << PLLRDY)) == 0u) && (timeout > 0u) )
			{
				timeout--;
			}

			if(timeout == 0u)
			{
				ret = E_NOT_OK;
			}
			else
			{
				RCC_REG->CFGR |=  (1UL << SW1);
				RCC_REG->CFGR &= ~(1UL << SW0);
			}
			break;

		default:
			ret = E_NOT_OK;
			break;
		}
	}
	if (ret == E_OK)
	{
		timeout = CLK_READY_TIMEOUT;
		/*SWS: System clock switch status */
		/* check which source is selected */
		while ( (((RCC_REG->CFGR >> SWS_POS) & SWS_MASK) != (uint32)ConfigPtr->clk_src)
				&& (timeout > 0u) )
		{
			timeout--;
		}
		if (timeout == 0u)
		{
			ret = E_NOT_OK;
		}
	}

	return ret;
}








