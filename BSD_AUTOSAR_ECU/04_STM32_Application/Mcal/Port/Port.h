/*************************************************************************************************************************************
@file           Port.h
@version        1.0.0
@brief          AUTOSAR PORT Driver Header (STM32F103X6).
@details        AUTOSAR 4.4.0 PORT module interface. Provides pin initialization,
                mode configuration, and alternate function selection for all GPIO ports.
                This module owns the GPIO and AFIO peripheral initialization at startup.
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Module          : PORT
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/

#ifndef PORT_H_
#define PORT_H_

/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/

#include "Std_Types.h"


#define PORT_NO_REMAP           0xFF
#define PORT_REMAP_USART1       0x00    /* bit 2 */
#define PORT_REMAP_SPI1         0x01    /* bit 0 */
#define PORT_REMAP_CAN1_PB89    0x02    /* bits 14:13 = 10  */

/********************************************************************
*@Name       : Port_PinDirectionType
*@Kind       : Enumeration
*@Range      : PORT_PIN_IN 0x00 Sets port pin as input ,PORT_PIN_OUT 0x01 Sets port pin as output.
*@Description: Possible directions of a port pin.
********************************************************************/
typedef enum
{
    PORT_PIN_IN = 0,
    PORT_PIN_OUT
} Port_PinDirectionType;


/********************************************************************
*@Name       : Port_PinType
*@Kind       : uint8
*@Range      : 0 - 15
*@Description: Data type for the symbolic name of a port pin.
********************************************************************/
typedef uint8  Port_PinType;


/********************************************************************
*@Name       : Port_PinModeType
*@Kind       : uint8
*@Range      :
*@Description: Different port pin modes.
********************************************************************/
typedef uint8  Port_PinModeType;

/********************************************************************
*@Name       : Port_ConfigPinType
*@Description: Describes the full static configuration for ONE pin --
*              which port, which pin, direction, mode, and (for
*              output pins) the level it should power up in.
********************************************************************/
typedef struct
{
    uint8                   Port_Num;      /* GPIOA_ID .. GPIOD_ID            */
    Port_PinType             Pin_Num;       /* PIN0 .. PIN15                    */
    Port_PinDirectionType    Direction;     /* PORT_PIN_IN / PORT_PIN_OUT       */
    Port_PinModeType         Mode;          /* PORT_PIN_MODE_*                  */
    uint8                   InitialValue;  /* STD_HIGH / STD_LOW (OUT pins only)*/
    uint8                   AfioRemapID;
} Port_ConfigPinType;

/********************************************************************
*@Name       : Port_ConfigType
*@Description: AUTOSAR-style top-level config type consumed by Port_Init.
*              Wraps a pointer + count so the table can live anywhere
*              (e.g. Port_Cfg.c) without Port.c knowing its size.
********************************************************************/
typedef struct
{
    const Port_ConfigPinType* Pins;
    uint8                      NumberOfPins;
} Port_ConfigType;




#ifndef PORT_SET_PIN_DIRECTION_API
#define PORT_SET_PIN_DIRECTION_API  STD_ON
#endif

#ifndef PORT_SET_PIN_MODE_API
#define PORT_SET_PIN_MODE_API  STD_ON
#endif

#ifndef PORT_VERSION_INFO_API
#define PORT_VERSION_INFO_API  STD_ON
#endif


#define GPIO_FIELD_MASK_2BIT   0x3u

#define GPIOA_ID            0
#define GPIOB_ID            1
#define GPIOC_ID            2
#define GPIOD_ID            3

#define PIN0                0U
#define PIN1                1U
#define PIN2                2U
#define PIN3                3U
#define PIN4                4U
#define PIN5                5U
#define PIN6                6U
#define PIN7                7U
#define PIN8                8U
#define PIN9                9U
#define PIN10               10U
#define PIN11               11U
#define PIN12               12U
#define PIN13               13U
#define PIN14               14U
#define PIN15               15U

#define PORT_PIN_MODE_ANALOG      	(Port_PinModeType)0
#define PORT_PIN_MODE_INPUT_FLOAT  	(Port_PinModeType)1
#define PORT_PIN_MODE_INPUT_PU_PD  	(Port_PinModeType)2
#define PORT_PIN_MODE_OUTPUT_PP   	(Port_PinModeType)0
#define PORT_PIN_MODE_OUTPUT_OD   	(Port_PinModeType)1
#define PORT_PIN_MODE_AF_PP       	(Port_PinModeType)2
#define PORT_PIN_MODE_AF_OD       	(Port_PinModeType)3

/*==================================================================================================
 *                                      function Prototypes
==================================================================================================*/
/*
 * Service name: Port_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr Pointer to configuration set.
 * Parameters(inout):None
 * Parameters (out): None
 * Return value:     None
 * Description: Initializes the Port Driver module.
*/
extern void Port_Init(const Port_ConfigType* ConfigPtr);

/*
 * Service name: Port_SetPinDirection
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Pin       -> Port Pin ID number
                    Direction -> Port Pin Direction
 * Parameters (inout): None
 * Parameters (out):   None
 * Return value:       None
 * Description: Sets the port pin direction
*/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
extern void Port_SetPinDirection(uint8 Gpiox, Port_PinType PinNum ,Port_PinDirectionType dir);
#endif

/*
 * Service name: Port_SetPinMode
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in):     Pin  ->  Port Pin ID number
                        Mode -> New Port Pin mode to be set on port pin.
 * Parameters (inout):  None
 * Parameters (out):    None
 * Return value:        None
 * Description: Sets the port pin mode.
*/
#if (PORT_SET_PIN_MODE_API == STD_ON)
extern void Port_SetPinMode		(uint8 Gpiox, Port_PinType PinNum ,Port_PinModeType Mode);
#endif


/*
 * Service name: Port_GetVersionInfo
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in):     None
 * Parameters (inout):  None
 * Parameters (out): versioninfo Pointer to where to store the version information of this module.
 * Return value:        None
 * Description: Returns the version information of this module.
*/
#if (PORT_VERSION_INFO_API == STD_ON)
extern void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif
#endif /* PORT_H_ */
