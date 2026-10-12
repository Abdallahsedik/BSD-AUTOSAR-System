/*
 * Systick.h
 *
 *  Created on: Sep 17, 2026
 *      Author: pc
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "Reg_eSys_Systick.h"
#include "Std_Types.h"
#include "stm32f103x6.h"


/*
 * 2 CLKSOURCE: Clock source selection Selects the clock source.
 *0: AHB/8
 *1: Processor clock (AHB)*/
typedef enum
{
	AHB_DIV_8,
	CPU_CLK_AHB
}STK_ClkSource_Type;

Std_ReturnType STK_voidInit(STK_ClkSource_Type STK_CLK_SRC );
Std_ReturnType STK_voidSetBusyWait(uint32 Copy_u32Ticks);
Std_ReturnType Systick_Config(uint32 ticks);
Std_ReturnType Systick_Stop(void);


#endif /* SYSTICK_H_ */
