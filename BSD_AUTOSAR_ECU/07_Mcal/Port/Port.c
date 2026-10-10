/*************************************************************************************************************************************
@file           Port.c
@version        1.0.0
@brief          AUTOSAR PORT Driver  (STM32F103X6).
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

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PORT_VENDOR_ID              43U      /* fake id number   */
#define PORT_MODULE_ID              124U

#define PORT_SW_MAJOR_VERSION       1U
#define PORT_SW_MINOR_VERSION       0U
#define PORT_SW_PATCH_VERSION       0U
/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/
#include "Reg_eSys_Gpio.h"
#include "Reg_eSys_Afio.h"

#include "Port.h"

Gpio_RegisterType * const Gpio_PortLuk[4] =
{
    GPIOA_REG, GPIOB_REG, GPIOC_REG, GPIOD_REG
};

static void Port_SetAlternateFunction(uint8 RemapID)
{
	if (RemapID == PORT_NO_REMAP)
	{
		return;
	}


	switch (RemapID)
	{
	case PORT_REMAP_USART1:
		AFIO_REG->MAPR |= (1 << 2);
		break;
	case PORT_REMAP_SPI1:
		AFIO_REG->MAPR |= (1 << 0);
		break;
	case PORT_REMAP_CAN1_PB89:
		AFIO_REG->MAPR &= ~(0x3 << 13);
		AFIO_REG->MAPR |= (0x2 << 13);
		break;
	default:
		break;
	}
}
/*==================================================================================================
 *                                       GLOBAL FUNCTION DEFINITIONS
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
void Port_Init(const Port_ConfigType* ConfigPtr)
{
    uint8 i;

    if (ConfigPtr == NULL_PTR)
    {
        return;
    }

    for (i = 0u; i < ConfigPtr->NumberOfPins; i++)
    {
        const Port_ConfigPinType* pinCfg = &ConfigPtr->Pins[i];
        Port_SetAlternateFunction(pinCfg->AfioRemapID);
        Port_SetPinMode(pinCfg->Port_Num, pinCfg->Pin_Num, pinCfg->Mode);
        Port_SetPinDirection(pinCfg->Port_Num, pinCfg->Pin_Num, pinCfg->Direction);

        Gpio_RegisterType* port = Gpio_PortLuk[pinCfg->Port_Num];

        if (pinCfg->Direction == PORT_PIN_OUT)
        {

            if (pinCfg->InitialValue == STD_HIGH)
            {
                port->BSRR = (uint32)(1UL << pinCfg->Pin_Num);          /* atomic set */
            }
            else
            {
                port->BSRR = (uint32)(1UL << (pinCfg->Pin_Num + 16u));  /* atomic reset */
            }
        }

        if (pinCfg->Mode == PORT_PIN_MODE_INPUT_PU_PD)
        {

            if (pinCfg->InitialValue == STD_HIGH)
                port->BSRR = (uint32)(1UL << pinCfg->Pin_Num);            /* ODR=1 → pull-up   */
            else
                port->BSRR = (uint32)(1UL << (pinCfg->Pin_Num + 16u));    /* ODR=0 → pull-down */
        }
    }
}


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
void Port_SetPinDirection(uint8 Gpiox, Port_PinType PinNum, Port_PinDirectionType dir)
{
	if ((Gpiox > GPIOD_ID) || (PinNum > PIN15) || (dir > PORT_PIN_OUT))
	    {
	        return;
	    }
	Gpio_RegisterType* port= Gpio_PortLuk[Gpiox];
    volatile uint32* reg =NULL_PTR;
    uint8 shift =0;

    if (PinNum < PIN8)
    {
        reg   = &port->CRL;
        shift = (uint8)(PinNum * 4u);
    }
    else
    {
        reg   = &port->CRH;
        shift = (uint8)((PinNum - 8u) * 4u);
    }
    if (reg == NULL_PTR)
       {
           return;
       }
    *reg = (uint32)((*reg & ~(GPIO_FIELD_MASK_2BIT << shift))
                     | (((uint32)dir & GPIO_FIELD_MASK_2BIT) << shift));
}
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
void Port_SetPinMode(uint8 Gpiox, Port_PinType PinNum, Port_PinModeType Mode)
{
	 if ((Gpiox > GPIOD_ID) || (PinNum > PIN15) || (Mode > PORT_PIN_MODE_AF_OD))
	    {
	        return;
	    }

    Gpio_RegisterType* port      =  Gpio_PortLuk[Gpiox];
    volatile uint32* reg    = NULL_PTR;
    uint8 shift=0;


    if (PinNum < PIN8)
    {
        reg   = &port->CRL;
        shift = (uint8)((PinNum * 4u) + 2u);
    }
    else
    {
        reg   = &port->CRH;
        shift = (uint8)(((PinNum - 8u) * 4u) + 2u);
    }

    if (reg == NULL_PTR)
    {
        return;
    }

    *reg = (uint32)((*reg & ~(GPIO_FIELD_MASK_2BIT << shift))
                     | (((uint32)Mode & GPIO_FIELD_MASK_2BIT) << shift));
}
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
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
    if (versioninfo != NULL_PTR)
    {
        versioninfo->vendorID         = PORT_VENDOR_ID;
        versioninfo->moduleID         = PORT_MODULE_ID;
        versioninfo->sw_major_version = PORT_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = PORT_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = PORT_SW_PATCH_VERSION;
    }
}
#endif

