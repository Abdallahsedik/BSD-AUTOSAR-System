/*************************************************************************************************************************************
@file           Can_GeneralTypes.h
@version        1.0.0
@brief          AUTOSAR CAN General Types (STM32F103X6).
@details        AUTOSAR 4.4.0 CAN General Types header. Defines the common type definitions
                shared between the CAN driver, CAN interface (CanIf), CAN configuration tool
                and the AUTOSAR environment, such as Can_HandleType, Can_HwHandleType,
                Can_IdType, Can_DlcType, Can_DataType, Can_PduType and the various
                controller-state and mode enumerations.
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Module          : Can_GeneralTypes
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/
#ifndef Can_GeneralTypes_H_
#define Can_GeneralTypes_H_

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_GENERAL_TYPES_VENDOR_ID               43U      /* fake id number */
#define CAN_GENERAL_TYPES_MODULE_ID               123U

#define CAN_GENERAL_TYPES_SW_MAJOR_VERSION        1U
#define CAN_GENERAL_TYPES_SW_MINOR_VERSION       0U
#define CAN_GENERAL_TYPES_SW_PATCH_VERSION       0U
/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/

#include "Std_Types.h"
#include "../PduR/PduR_Types.h"


#define NUM_FILTERS 2u
#define CAN_BUSY 0x02


/*
*@name       : Can_IdType
*@Description: Represents the Identifier of an L-PDU.
*               The two most significant bits specify the frame type: 00 CAN message with Standard CAN ID 
*               01 CAN FD frame with Standard CAN ID 10 CAN message
*               with Extended CAN ID 11 CAN FD frame with Extended CAN ID)           
*@Available via: Can_GeneralTypes.h
 */

typedef uint32 Can_IdType;

/*
*@name       : Can_HwHandleType
*@Description: Represents the hardware object handles of a CAN hardware unit.
*                For CAN hardware units with more than 255 HW objects use extended range
*@range       :Standard (0->0x0FF) |Extended(0->0xFFFF)
*@Available via: Can_GeneralTypes.h
*/

typedef uint32 Can_HwHandleType;

/*
*@name       : Can_PduType
*@Description:  This type unites PduId (swPduHandle)
*              , SduLength (length), SduData (sdu),
*                and CanId (id) for any CAN L-SDU.
*@Available via: Can_GeneralTypes.h
 */


typedef struct {
PduIdType   swPduHandle;
uint8       length;
Can_IdType  id;
uint8*      sdu;
}Can_PduType;



/*
*@name       : Can_HwType
*@Description:  This type defines a data structure which clearly provides an Hardware Object Handle including its
*               corresponding CAN Controller and therefore CanDrv as well as the specific CanId.
*@Available via: Can_GeneralTypes.h
 */

typedef struct {
Can_IdType   CanId; /*Standard/Extended CAN ID of CAN L-PDU */
Can_HwHandleType Hoh;/**ID of the corresponding Hardware Object Range */
uint8  ControllerId;/**ControllerId provided by CanIf clearly identify the corresponding controller */
}Can_HwType;


/*
*@name       : Can_ErrorStateType
*@Description:Error states of a CAN controller.
*@Available via: Can_GeneralTypes.h
 */
typedef enum{
    CAN_ERRORSTATE_ACTIVE,/**The CAN controller takes fully part in communication */
    CAN_ERRORSTATE_PASSIVE,/*The CAN controller takes part in communication, but does not send active error frames*/
    CAN_ERRORSTATE_BUSOFF /*The CAN controller does not take part in communication*/
}Can_ErrorStateType;

/*
*@name       : Can_ControllerStateType
*@Description:States that are used by the several ControllerMode functions
*@Available via: Can_GeneralTypes.h
 */
typedef enum{
    CAN_CS_UNINIT,/**CAN controller state UNINIT. */
    CAN_CS_STARTED,/*CAN controller state STARTED */
    CAN_CS_STOPPED ,/*CAN controller state STOPPED*/
    CAN_CS_SLEEP    /**CAN controller state SLEEP */
}Can_ControllerStateType;


typedef enum {
    CAN_FILTER_SCALE_16BIT = 0,
    CAN_FILTER_SCALE_32BIT = 1
} Can_FilterScaleType;

typedef enum {
    CAN_FILTER_MODE_MASK = 0,
    CAN_FILTER_MODE_LIST = 1
} Can_FilterModeType;

typedef struct {
    uint8               FilterBank;     /* filter bank number 0..13 or 0..27 */
    Can_FilterScaleType Scale;          /* 16-bit or 32-bit scale */
    Can_FilterModeType  Mode;           /* mask or list mode */
    boolean             ExtendedId;     /* TRUE if the id is extended */
    uint32              Id1;            /* first id (list) or base id (mask) */
    uint32              Id2;            /* second id (list) or mask (mask mode) */
    uint32              Id3;            /* third id (only in 16-bit list mode) */
    uint32              Id4;            /* fourth id (only in 16-bit list mode) */
} Can_FilterConfigType;



typedef struct {
    uint8   TS2;         /* Time Segment 2       (0..7)   */
    uint8   TS1;         /* Time Segment 1       (0..15)  */
    uint8   SJW;         /* Sync Jump Width      (0..3)   */
    uint16  Prescaler;   /* Baud prescaler       (1..1023)*/
    boolean LoopBack;    /* TRUE -> loop-back mode         */
    boolean Silent;      /* TRUE -> silent mode           */
} Can_ControllerBaudrateConfigType;



typedef struct {
    Can_ControllerBaudrateConfigType BaudrateConfig;
    Can_FilterConfigType           FilterConfig[NUM_FILTERS];
} Can_ConfigType;


#endif /* Can_GeneralTypes_H_ */
