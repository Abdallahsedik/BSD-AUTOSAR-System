/*************************************************************************************************************************************
@file           Dio_Cfg.h
@version        1.0.0
@brief          AUTOSAR DIO Driver Configuration Header (STM32F103X6).
@details        AUTOSAR 4.4.0 DIO module pre-compile configuration file. Defines:
                   - Configuration class selection (Channel / Port / Channel Group)
                   - Port IDs and Channel IDs mapped to STM32F103X6 (LQFP48) GPIOs
                   - Pre-configured Channel Groups
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Module          : DIO
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/

#ifndef DIO_CFG_H_
#define DIO_CFG_H_

/*************************************************************************************************************************************
 *                                                            INCLUDES
 ************************************************************************************************************************************/
#include "Std_Types.h"

/*************************************************************************************************************************************
 *                                             GENERAL CONFIGURATION
 ************************************************************************************************************************************/
 #define DIO_VERSION_INFO_API                 STD_ON

/*************************************************************************************************************************************
 *                                                          PORT IDs
 *  Used by Dio_ReadPort() / Dio_WritePort() / Dio_MaskedWritePort() /
 *  Dio_ReadChannelGroup() / Dio_WriteChannelGroup()
 ************************************************************************************************************************************/

//Gpio_RegisterType* const Gpio_PortLuk[4] =
//{
//    GPIOA_REG, GPIOB_REG, GPIOC_REG, GPIOD_REG
//};
#define GPIOA_ID            0
#define GPIOB_ID            1
#define GPIOC_ID            2
#define GPIOD_ID            3

/**************************************************************************************************************************************
 *                                                         CHANNEL IDs
 *  Used by Dio_ReadChannel() / Dio_WriteChannel()
 ************************************************************************************************************************************/
#define DIO_CHANNEL_P0               ((Dio_ChannelType)0U)
#define DIO_CHANNEL_P1               ((Dio_ChannelType)1U)
#define DIO_CHANNEL_P2               ((Dio_ChannelType)2U)
#define DIO_CHANNEL_P3               ((Dio_ChannelType)3U)
#define DIO_CHANNEL_P4               ((Dio_ChannelType)4U)
#define DIO_CHANNEL_P5               ((Dio_ChannelType)5U)
#define DIO_CHANNEL_P6               ((Dio_ChannelType)6U)
#define DIO_CHANNEL_P7               ((Dio_ChannelType)7U)
#define DIO_CHANNEL_P8               ((Dio_ChannelType)8U)
#define DIO_CHANNEL_P9               ((Dio_ChannelType)9U)
#define DIO_CHANNEL_P10              ((Dio_ChannelType)10U)
#define DIO_CHANNEL_P11              ((Dio_ChannelType)11U)
#define DIO_CHANNEL_P12              ((Dio_ChannelType)12U)
#define DIO_CHANNEL_P13              ((Dio_ChannelType)13U)
#define DIO_CHANNEL_P14              ((Dio_ChannelType)14U)
#define DIO_CHANNEL_P15              ((Dio_ChannelType)15U)


#define IDR_MASK 			0xFFFFu


#endif /* DIO_CFG_H_ */
