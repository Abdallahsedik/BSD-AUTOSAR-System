/*************************************************************************************************************************************
@file           Can.h
@version        1.0.0
@brief          AUTOSAR CAN Driver (STM32F103X6).
@details        AUTOSAR 4.4.0 CAN module header. Declares the public API of the CAN driver
                including initialization, de-initialization, write, read, cancel, main
                function and callback notification services, together with the
                configuration types used by the upper layers (CanIf).
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Module          : Can
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/
#ifndef CAN_H_
#define CAN_H_

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_VENDOR_ID               43U      /* fake id number */
#define CAN_MODULE_ID               122U

#define CAN_SW_MAJOR_VERSION        1U
#define CAN_SW_MINOR_VERSION        0U
#define CAN_SW_PATCH_VERSION        0U
/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/


#include "Std_Types.h"
#include "Can_GeneralTypes.h"




void Can_Init (const Can_ConfigType* Config);
void Can_DeInit(void);
Std_ReturnType Can_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition);
Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType* PduInfo);
Std_ReturnType Can_SetBaudrate(uint8 Controller, uint16 BaudRateConfigID);
void Can_DisableControllerInterrupts(uint8 Controller);
void Can_EnableControllerInterrupts(uint8 Controller);
void Can_MainFunction_Read(void);


//Std_ReturnType Can_CheckBaudrate( uint8 Controller,const uint16 Baudrate);

#endif /* CAN_CAN_H_ */
