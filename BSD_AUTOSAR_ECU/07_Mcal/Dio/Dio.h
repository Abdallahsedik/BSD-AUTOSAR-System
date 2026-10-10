/*************************************************************************************************************************************
@file           Dio.h
@version        1.0.0
@brief          AUTOSAR DIO Driver  (STM32F103X6).
@details        AUTOSAR 4.4.0 DIO module interface. Provides APIs for reading and writing
                individual pins, ports, and channel groups, built on top of the PORT module's
                pin configuration.
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
 *                                    DIO DRIVER REQUIREMENTS
 *==================================================================================================
 * General:
 *   The Dio SWS shall define functions allowing Port-based, Channel-based, and
 *   Channel-group-based read and write access to the internal general purpose I/O ports.
 *
 * [SWS_Dio_00051] (SRS_Dio_12003, SRS_Dio_12004, SRS_Dio_12005, SRS_Dio_12006,
 *                   SRS_Dio_12007, SRS_Dio_12008)
 *   The Dio module shall not buffer data when providing read and write services.
 *   The Dio SWS shall define synchronous read/write services.
 *
 * [SWS_Dio_00005] (SRS_Dio_12424)
 *   The Dio module's read and write services shall ensure, for all services, that
 *   the data is consistent (interruptible read-modify-write sequences are not allowed).
 *
 * [SWS_Dio_00089] (SRS_Dio_12003, SRS_Dio_12004, SRS_Dio_12005, SRS_Dio_12006,
 *                   SRS_Dio_12007, SRS_Dio_12008)
 *   Values used by the DIO Driver for the software level of Channels are either
 *   STD_HIGH or STD_LOW.
 *
 * [SWS_Dio_00128] (SRS_Dio_12005, SRS_Dio_12008)
 *   A general-purpose digital IO pin represents a DIO channel.
 *
 * [SWS_Dio_00127] (SRS_Dio_12005, SRS_Dio_12008)
 *   The Port module shall configure a DIO channel as input or output
 *   ([SWS_Dio_00001] and [SWS_Dio_00002]).
 *
 * [SWS_Dio_00053] (SRS_Dio_12003, SRS_Dio_12006)
 *   In the DIO Driver, it shall be possible to group several DIO channels by
 *   hardware (typically controlled by one hardware register) to represent a
 *   DIO port.
 *   Note: The single DIO channel levels inside a DIO port represent a bit in
 *   the DIO port value, depending on their position inside the port.
 *
 * [SWS_Dio_00056] (SRS_Dio_12004, SRS_Dio_12007)
 *   A channel group is a formal logical combination of several adjoining DIO
 *   channels within a DIO port.
 *
 *==================================================================================================
 *                                  7.2  DIO SERVICES
 *==================================================================================================
 * [SWS_Dio_00060] (SRS_Dio_12424)
 *   All read and write functions of the Dio module shall be re-entrant.
 *   Reason: The DIO Driver may be accessed by different upper layer handlers
 *   or drivers. These upper layer modules may access the driver concurrently.
 *
 * [SWS_Dio_00026] (SRS_Dio_12355)
 *   The configuration process for the Dio module shall provide symbolic names
 *   for each configured DIO channel, port, and group.
 *==================================================================================================*/


#ifndef DIO_H_
#define DIO_H_

/*==================================================================================================
 *                                       INCLUDES
 *==================================================================================================*/
#include "Std_Types.h"
#include "Reg_eSys_Gpio.h"
#include "Dio_Cfg.h"
/*==================================================================================================
 *                                       LOCAL MACROS AND DEFINITIONS
 * ==================================================================================================*/

/********************************************************************
*@Name       : Dio_ChannelType
*@Kind       : uint8
*@Range      : 0 - 15
*@Description: Data type for Numeric ID of a DIO channel.
********************************************************************/
typedef uint8 Dio_ChannelType;

/********************************************************************
*@Name       : Dio_PortType
*@Kind       : uint8
*@Range      : 0 - 3
*@Description: Data type for Numeric ID of a DIO port.
********************************************************************/
typedef uint8 Dio_PortType;

/********************************************************************
*@Name       : Dio_PortType
*@Kind       : uint8
*@Range      : STD_LOW 0x00  Physical state 0V
*              STD_HIGH 0x01 Physical state 5V or 3.3V
*@Description: These are the possible levels a DIO channel can have (input or output).
********************************************************************/
typedef  uint8  Dio_LevelType;

/********************************************************************
*@Name       : Dio_PortLevelType
*@Kind       : uint16
*@Range      : 0x0000 - 0xFFFF
*@Description: Dio_PortLevelType inherits the size of the largest port.
********************************************************************/
typedef  uint16  Dio_PortLevelType;

typedef struct {
   uint8 mask;
   uint8 offset;
   Dio_PortType port;
}Dio_ChannelGroupType;




/*==================================================================================================
 *                                      function Prototypes
==================================================================================================*/
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
Dio_LevelType Dio_ReadChannel(Dio_PortType PortId, Dio_ChannelType ChannelId);


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

void Dio_WriteChannel ( Dio_PortType PortId, Dio_ChannelType ChannelId, Dio_LevelType Level );

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
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);




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
void Dio_WritePort ( Dio_PortType PortId , Dio_PortLevelType Level);


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
Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr );


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
void Dio_WriteChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);

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
void Dio_GetVersionInfo(Std_VersionInfoType* versioninfo);
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
Dio_LevelType Dio_FlipChannel (Dio_PortType PortId , Dio_ChannelType ChannelId );

/*
@Name              :Dio_MaskedWritePort
@Service_ID [hex]  :0x13
@Sync/Async        :Synchronous
@Reentrancy        :Reentrant
@Parameters (in)   :PortId ID of DIO Port , Level Value to be written ,Mask Channels to be masked in the port
@Parameters (inout):None
@Parameters (out)  :None
@Return value      :Dio_LevelType ( STD_HIGH -STD_LOW)
@Description       :Service to set the value of a given port with required mask.
*/
void Dio_MaskedWritePort (Dio_PortType PortId, Dio_PortLevelType Level,Dio_PortLevelType Mask);


#endif /* DIO_H_ */
