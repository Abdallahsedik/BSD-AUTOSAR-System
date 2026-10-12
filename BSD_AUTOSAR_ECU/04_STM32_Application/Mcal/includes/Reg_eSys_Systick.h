/*
 * Reg_eSys_Systick.h
 *
 *  Created on: Sep 17, 2026
 *      Author: pc
 */

#ifndef REG_ESYS_SYSTICK_H_
#define REG_ESYS_SYSTICK_H_
/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/

#include "Platform_types.h"


/*==================================================================================================*
 *                                       Base addresses for systick Peripheral
 *==================================================================================================*/
#define STK_BASE										( 0xE000E010UL )


/*==================================================================================================*
 *                                       Peripheral registers
 *==================================================================================================*/
typedef struct
{
	volatile uint32	STK_CTRL;
	volatile uint32 STK_LOAD;
	volatile uint32 STK_VAL;
	volatile uint32 STK_CALIB;
}STK_RegisterType;

/*==================================================================================================*
 *                                       Peripheral Instants
 *==================================================================================================*/

#define STK_REG 	((STK_RegisterType *) STK_BASE)

#define STK_EN_BIT					(0u)
#define STK_TICKINT_BIT				(1u)
#define STK_CLKSOURCE_BIT			(2u)



#endif /* REG_ESYS_SYSTICK_H_ */
