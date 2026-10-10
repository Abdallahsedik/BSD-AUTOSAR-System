/*************************************************************************************************************************************
@file           Dio.c
@version        1.0.0
@brief          AUTOSAR DIO Driver  (STM32F103X6).
@details        AUTOSAR 4.4.0 DIO module implementation. Implements pin/port/channel-group
                level read and write services, using the pin configuration established by
                the PORT module at startup.
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
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DIO_VENDOR_ID               43U      /* fake id number */
#define DIO_MODULE_ID               120U

#define DIO_SW_MAJOR_VERSION        1U
#define DIO_SW_MINOR_VERSION        0U
#define DIO_SW_PATCH_VERSION        0U
/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/

#include "Dio.h"

Gpio_RegisterType* const Gpio_DioLuk[4] =
{
    GPIOA_REG, GPIOB_REG, GPIOC_REG, GPIOD_REG
};


/*
@Name              :Dio_WriteChannel
@Service_ID [hex]  :0x01
@Sync/Async        :Synchronous
@Reentrancy        :Reentrant
@Parameters (in)   :ChannelId ID of DIO channel Level Value to be written
@Parameters (inout):None
@Parameters (out)  :None
@Return value      :None
@Description       :Service to set a level of a channel
*/

void Dio_WriteChannel ( Dio_PortType PortId, Dio_ChannelType ChannelId, Dio_LevelType Level )
{
    if ((PortId > GPIOD_ID) || (ChannelId > DIO_CHANNEL_P15) || (Level > STD_HIGH ))
	    {
            return ;
	    }
    Gpio_RegisterType* port = Gpio_DioLuk[PortId];

    if (Level == STD_HIGH)
        {
            port->BSRR = (uint32)(1UL << ChannelId);          /* atomic set */
        }
        else
        {
            port->BSRR = (uint32)(1UL << (ChannelId + 16u));  /* atomic reset */
        }

}


/*
@Name              :Dio_ReadChannel
@Service_ID [hex]  :0x00
@Sync/Async        :Synchronous
@Reentrancy        :Reentrant
@Parameters (in)   :ChannelId ID of DIO channel
@Parameters (inout):None
@Parameters (out)  :None
@Return value      :Dio_LevelType STD_HIGH The physical level of the corresponding Pin is STD_HIGH
*                   STD_LOW The physical level of the corresponding Pin is STD_LOW
@Description       :Returns the value of the specified DIO channel.
*/
Dio_LevelType Dio_ReadChannel(Dio_PortType PortId, Dio_ChannelType ChannelId)
{
    if ((PortId > GPIOD_ID) || (ChannelId > DIO_CHANNEL_P15) )
	    {
            return STD_LOW;
	    }
    Gpio_RegisterType* port = Gpio_DioLuk[PortId];

    return  (Dio_LevelType)((port->IDR >> ChannelId) & 0x1u);
}


/*
@Name              :Dio_ReadPort
@Service_ID [hex]  :0x02
@Sync/Async        :Synchronous
@Reentrancy        :Reentrant
@Parameters (in)   :PortId ID of DIO Port
@Parameters (inout):None
@Parameters (out)  :None
@Return value      :Dio_PortLevelType Level of all channels of that port
@Description       :Returns the level of all channels of that port.
*/
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId){
    if ((PortId > GPIOD_ID) )
	    {
            return STD_LOW;
	    }
    Gpio_RegisterType* port = Gpio_DioLuk[PortId];

    return  (Dio_LevelType)(port->IDR & IDR_MASK);
}


/*
@Name              :Dio_WritePort
@Service_ID [hex]  :0x03
@Sync/Async        :Synchronous
@Reentrancy        :Reentrant
@Parameters (in)   :PortId ID of DIO Port , Level Value to be written
@Parameters (inout):None
@Parameters (out)  :None
@Return value      :None
@Description       :Service to set a value of the port.
*/
void Dio_WritePort ( Dio_PortType PortId , Dio_PortLevelType Level)
{
     if ((PortId > GPIOD_ID) )
	    {
            return ;
	    }
    Gpio_RegisterType* port = Gpio_DioLuk[PortId];

    port->BSRR = (uint32)Level | (uint32)((~Level & 0xFFFFu) << 16u);
}

/*
@Name              :Dio_ReadChannelGroup
@Service_ID [hex]  :0x04
@Sync/Async        :Synchronous
@Reentrancy        :Reentrant
@Parameters (in)   :ChannelGroupIdPtr Pointer to ChannelGroup
@Parameters (inout):None
@Parameters (out)  :None
@Return value      :Dio_PortLevelType Level of a subset of the adjoining bits of a port
@Description       :This Service reads a subset of the adjoining bits of a port.
*/
Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr )
{
    if ((ChannelGroupIdPtr == NULL_PTR) || (ChannelGroupIdPtr->port > GPIOD_ID))
    {
        return (Dio_PortLevelType)0u;
    }

    Gpio_RegisterType* port = Gpio_DioLuk[ChannelGroupIdPtr->port];
    return(Dio_PortLevelType)((port->IDR >>ChannelGroupIdPtr->offset)&ChannelGroupIdPtr->mask);
}

/*
@Name              :Dio_WriteChannelGroup
@Service_ID [hex]  :0x05
@Sync/Async        :Synchronous
@Reentrancy        :Reentrant
@Parameters (in)   :ChannelGroupIdPtr Pointer to ChannelGroup ,Level Value to be written
@Parameters (inout):None
@Parameters (out)  :None
@Return value      :None
@Description       :Service to set a subset of the adjoining bits of a port to a specified level
*/
void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level)
{
     if ((ChannelGroupIdPtr == NULL_PTR) || (ChannelGroupIdPtr->port > GPIOD_ID) ||( Level > ChannelGroupIdPtr->mask ))
    {
        return ;
    }

    Gpio_RegisterType* port = Gpio_DioLuk[ChannelGroupIdPtr->port];

    uint32 shiftedValue = ((uint32)Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr->mask;
    uint32 setMask   = shiftedValue;
    uint32 resetMask = (uint32)(ChannelGroupIdPtr->mask & ~shiftedValue);
    port->BSRR = setMask | (resetMask << 16u);
}


/*
 * Service name: Dio_GetVersionInfo
 * Service ID[hex]: 0x12
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in):     None
 * Parameters (inout):  None
 * Parameters (out): versioninfo Pointer to where to store the version information of this module.
 * Return value:        None
 * Description: Returns the version information of this module.
*/
#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
    if (versioninfo != NULL_PTR)
    {
        versioninfo->vendorID         = DIO_VENDOR_ID;
        versioninfo->moduleID         = DIO_MODULE_ID;
        versioninfo->sw_major_version = DIO_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = DIO_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = DIO_SW_PATCH_VERSION;
    }
}
#endif


/*
@Name              :Dio_FlipChannel
@Service_ID [hex]  :0x11
@Sync/Async        :Synchronous
@Reentrancy        :Reentrant
@Parameters (in)   :PortId ,ChannelId ID of DIO channel
@Parameters (inout):None
@Parameters (out)  :None
@Return value      :Dio_LevelType ( STD_HIGH -STD_LOW)
@Description       :Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip.
*/
Dio_LevelType Dio_FlipChannel (Dio_PortType PortId , Dio_ChannelType ChannelId )
{
    if ((PortId > GPIOD_ID) || (ChannelId > DIO_CHANNEL_P15))
	    {
            return STD_LOW;
	    }
    Gpio_RegisterType* port = Gpio_DioLuk[PortId];
    if((port->ODR&(1U<<ChannelId))!=0)
    {
        //reset ->0
        port->BSRR = (uint32)(1UL << (ChannelId + 16u));
        return STD_LOW;
    }
    else
    {
        //set ->1
        port->BSRR = (uint32)(1UL << ChannelId);
        return STD_HIGH;
    }
}
/*
@Name              :Dio_MaskedWritePort
@Service_ID [hex]  :0x13
@Sync/Async        :Synchronous.
@Reentrancy        :Reentrant.
@Parameters (in)   :PortId ID of DIO Port , Level Value to be written ,Mask Channels to be masked in the port
@Parameters (inout):None.
@Parameters (out)  :None.
@Return value      :None.
@Description       :Service to set the value of a given port with required mask.
*/
void Dio_MaskedWritePort (Dio_PortType PortId, Dio_PortLevelType Level,Dio_PortLevelType Mask)
{
     if ((PortId > GPIOD_ID) )
	 {
        return;
	 }
        Gpio_RegisterType* port = Gpio_DioLuk[PortId];
   //create masks
    uint32 setMask   = (uint32)Level & (uint32)Mask;
    uint32 resetMask = (uint32)(~Level) & (uint32)Mask;

    port->BSRR = setMask | (resetMask << 16u);

}
