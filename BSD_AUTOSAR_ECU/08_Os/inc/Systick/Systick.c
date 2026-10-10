/*
 * Systick.c
 *
 *  Created on: Sep 17, 2026
 *      Author: pc
 */
#include "Systick.h"


Std_ReturnType STK_voidInit(STK_ClkSource_Type STK_CLK_SRC )
{
	Std_ReturnType ret=E_OK;
	/*1- Disable SysTick*/
	STK_REG->STK_CTRL &=~(1<<STK_EN_BIT);
	/*2- Disable SysTick INT*/
	STK_REG->STK_CTRL &=~(1<<STK_TICKINT_BIT);
	/*3- Select SysTick Clock Source*/
	if (STK_CLK_SRC == AHB_DIV_8)
	{
		STK_REG->STK_CTRL &=~(1<<STK_CLKSOURCE_BIT);
	}
	else if (STK_CLK_SRC == CPU_CLK_AHB)
	{
		STK_REG->STK_CTRL |=(1<<STK_CLKSOURCE_BIT);
	}
	else
	{
		ret=E_NOT_OK;
	}

	return ret;


}

Std_ReturnType Systick_Config(uint32 ticks)
{
	Std_ReturnType ret=E_OK;

	if((ticks-1)>SysTick_LOAD_RELOAD_Msk)
	{
		return (E_NOT_OK);
	}
	SysTick->LOAD =(uint32)(ticks- 1UL);
	__NVIC_SetPriority(SysTick_IRQn,(1UL << __NVIC_PRIO_BITS)-1UL);
	SysTick->VAL =0UL;
	SysTick->CTRL= SysTick_CTRL_CLKSOURCE_Msk |
					SysTick_CTRL_TICKINT_Msk  |
					SysTick_CTRL_ENABLE_Msk;
	return(ret);


}
/*Tick Time = 1 microsecond that means 1000 = 1 milli second*/

Std_ReturnType STK_voidSetBusyWait(uint32 Copy_u32Ticks)
{
	Std_ReturnType ret=E_OK;
	/* SysTick is a 24-bit timer */
	if (Copy_u32Ticks > 0x00FFFFFFUL || Copy_u32Ticks == 0)
	{
		return E_NOT_OK;
	}

	/*1- Reload The value in the LOAD*/
	STK_REG->STK_LOAD=Copy_u32Ticks -1;

	STK_REG->STK_VAL = 0;


	/*2- Start Timer*/
	STK_REG->STK_CTRL |=(1<<STK_EN_BIT);

	/*3- Wait until the flag is raised*/
	while((	STK_REG->STK_CTRL &(1<<16))==0 );
	/*4- Stop Timer*/
	STK_REG->STK_CTRL &=~(1<<STK_EN_BIT);

	STK_REG->STK_LOAD = 0;
	STK_REG->STK_VAL = 0;
	return ret;
}

Std_ReturnType Systick_Stop(void)
{
    Std_ReturnType ret = E_OK;

    /*1- Stop the counter */
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

    /*2- Disable the SysTick interrupt  */
    SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;

    /*3- Clear COUNTFLAG + reload counter*/
    SysTick->VAL  = 0UL;
    SysTick->LOAD = 0UL;


    SCB->ICSR = SCB_ICSR_PENDSTCLR_Msk;

    return ret;
}

