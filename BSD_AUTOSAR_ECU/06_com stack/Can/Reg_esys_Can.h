/*************************************************************************************************************************************
@file           Reg_eSys_Can.h
@version        1.0.0
@brief          Register Definitions for CAN (STM32F103X6).
@details        Provides register abstraction layer definitions for the CAN peripheral on
                the STM32F103X6 MCU. Contains base addresses, register offset definitions,
                bit mapping and bit-field masks used by the CAN driver to access the hardware
                registers in a hardware-independent manner.
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Module          : Reg_eSys_Can
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/

#ifndef CAN_REG_ESYS_H_
#define CAN_REG_ESYS_H_

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define REG_ESYS_CAN_VENDOR_ID              43U      /* fake id number */
#define REG_ESYS_CAN_MODULE_ID              121U

#define REG_ESYS_CAN_SW_MAJOR_VERSION       1U
#define REG_ESYS_CAN_SW_MINOR_VERSION       0U
#define REG_ESYS_CAN_SW_PATCH_VERSION       0U

/*register definitions*/
/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/
#include "..\Platform_types.h"

/*==================================================================================================*
 *                                       Base addresses for APB Peripheral
 *==================================================================================================*/

#define CAN_BASE_ADDRESS    0x40006400
typedef struct
{
	volatile uint32 FR1;
	volatile uint32 FR2;
} CAN_FilterRegister_t;

typedef struct
{
	volatile uint32 TIR;
	volatile uint32 TDTR;
	volatile uint32 TDLR;
	volatile uint32 TDHR;
} CAN_TxMailBox_t;

typedef struct
{
	volatile uint32 RIR;
	volatile uint32 RDTR;
	volatile uint32 RDLR;
	volatile uint32 RDHR;
} CAN_RxMailBox_t;

typedef struct
{
	volatile uint32  CAN_MCR;
	volatile uint32  CAN_MSR;
	volatile uint32  CAN_TSR;
	volatile uint32  CAN_RF0R;
	volatile uint32  CAN_RF1R;
	volatile uint32  CAN_IER;
	volatile uint32  CAN_ESR;
	volatile uint32  CAN_BTR;
	volatile uint32  RESERVED0[88];        /* x020-0x17F */

	CAN_TxMailBox_t  sTxMailBox[3];
	CAN_RxMailBox_t  sFIFOMailBox[2];       /*x180-0x1CC  */

	volatile uint32  RESERVED1[12];        /* x1D0-0x1FF */

	volatile uint32  CAN_FMR;
	volatile uint32  CAN_FM1R;
	volatile uint32  RESERVED2;
	volatile uint32  CAN_FS1R;
	volatile uint32  RESERVED3;
	volatile uint32  CAN_FFA1R;
	volatile uint32  RESERVED4;
	volatile uint32  CAN_FA1R;              /* x200-0x21C */

	volatile uint32  RESERVED5[8];          /*  x220-0x23F */

	CAN_FilterRegister_t sFilterRegister[28];   /* x240  */

} CAN_RegisterType;


#define CAN_REG                ((CAN_RegisterType *)CAN_BASE_ADDRESS)

#define CAN_MCR_Reset                       (0x1UL <<  (15U) )
#define CAN_MCR_Sleep   (1u<<1)
#define CAN_TIMEOUT     100000u
#define CAN_MSR_SLAK    (1u<<1)
#define CAN_INRQ_BIT    0
#define CAN_INAK_BIT    0
#define CAN_TIR_TXRQ   (1u << 0)
#define CAN_TIR_RTR    (1u << 1)
#define CAN_TIR_IDE    (1u << 2)
#define TSR_TME0 (1<<26)
#define TSR_TME1 (1<<27)
#define TSR_TME2 (1<<28)
#define TIXR_TXRQ (1<<0)

#define CAN_BTR_LBKM    (1u<<30)
#define CAN_BTR_SILM    (1u<<31)
#define CAN_RIR_IDE   ((uint32)0x00000004) /* Bit 2 */
#endif /* CAN_REG_ESYS_H_ */


