/*************************************************************************************************************************************
@file           Can.c
@version        1.0.0
@brief          AUTOSAR CAN Driver (STM32F103X6).
@details        AUTOSAR 4.4.0 CAN module implementation. Implements the CAN driver services
                for initialization, transmission, reception, cancellation, controller mode
                control, baud-rate switching and the cyclic main function, using the
                configuration established by the CAN configuration tool at startup.
                Hardware access is performed through the Reg_eSys_Can register abstraction
                layer.
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
/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_VENDOR_ID               43U      /* fake */
#define CAN_MODULE_ID               122U

#define CAN_SW_MAJOR_VERSION        1U
#define CAN_SW_MINOR_VERSION        0U
#define CAN_SW_PATCH_VERSION        0U
/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/


#include "can.h"
#include "../Reg_eSys_Rcc.h"
#include "Reg_esys_Can.h"
#include "Can_Cfg.h"
#include "stm32f103x6.h"



#define     MAX_TS2 0x07
#define     MAX_TS1 0x0F
#define     MAX_SJW 0x03
#define     MAX_PRE 1023



/* Can_IdType frame type bits */
#define CAN_ID_EXT_MASK   ((Can_IdType)0x80000000u) /* extended ID flag          */
#define CAN_ID_FD_MASK    ((Can_IdType)0x40000000u) /* CAN FD frame flag        */
#define CAN_ID_VALUE_MASK ((Can_IdType)0x1FFFFFFFu) /* 29-bit ID value          */

/* The 3 transmit mailboxes form ONE transmit HOH (Hth = 0) */
#define CAN_TX_HOH_COUNT   1u
#define CAN_NUM_TX_MAILBOX 3u

/* swPduHandle per mailbox, used for confirmation later */
static boolean   Can_TxPending[CAN_NUM_TX_MAILBOX];
static PduIdType Can_TxSwPduHandle[CAN_NUM_TX_MAILBOX];


Can_ControllerStateType Can_CurrentState = CAN_CS_UNINIT;
/* Declaration of the upper layer function */
extern void CanIf_RxIndication(uint32 CanId, uint8* Data, uint8 DLC);


static uint16 Can_BuildStdId16(uint32 StdId)
{
    /* put 11-bit std id in the right position, IDE=0 and RTR=0 by default */
    return (uint16)((StdId & 0x7FFu) << 5);
}
static uint32 Can_BuildExtId32(uint32 ExtId)
{
    /* put 29-bit ext id in the right position and set IDE bit */
    return (uint32)(((ExtId & 0x1FFFFFFFu) << 3) | (1u << 2));
}
Std_ReturnType Can_ConfigFilter(const Can_FilterConfigType* FilterCfg)
{
    uint32 FR1 = 0u, FR2 = 0u;

    /* check filter bank pointer and range */
    if (FilterCfg == NULL_PTR || FilterCfg->FilterBank > 13u)
    {
        return E_NOT_OK;
    }

    /* check 2: extended id must use 32-bit scale */
    if ((FilterCfg->ExtendedId == TRUE) && (FilterCfg->Scale == CAN_FILTER_SCALE_16BIT))
    {
        return E_NOT_OK;
    }

    CAN_REG->CAN_FMR |= (1u << 0);   /* enter filter init mode */
    CAN_REG->CAN_FA1R &= ~(1u << FilterCfg->FilterBank);

    /* set the filter scale (16 or 32 bit) */
    if (FilterCfg->Scale == CAN_FILTER_SCALE_32BIT)
    {
        CAN_REG->CAN_FS1R |= (1u << FilterCfg->FilterBank);
    }
    else
    {
        CAN_REG->CAN_FS1R &= ~(1u << FilterCfg->FilterBank);
    }

    /* set the filter mode (list or mask) */
    if (FilterCfg->Mode == CAN_FILTER_MODE_LIST)
    {
        CAN_REG->CAN_FM1R |= (1u << FilterCfg->FilterBank);
    }
    else
    {
        CAN_REG->CAN_FM1R &= ~(1u << FilterCfg->FilterBank);
    }

    /* fill FR1 and FR2 depending on scale and mode */
    if (FilterCfg->Scale == CAN_FILTER_SCALE_32BIT)
    {
        if (FilterCfg->Mode == CAN_FILTER_MODE_LIST)
        {
            /* 32-bit list mode: FR1 = first id, FR2 = second id */
            FR1 = Can_BuildExtId32(FilterCfg->Id1);
            FR2 = Can_BuildExtId32(FilterCfg->Id2);
        }
        else /* mask mode */
        {
            /* 32-bit mask mode: FR1 = id, FR2 = mask (same alignment as id) */
            FR1 = Can_BuildExtId32(FilterCfg->Id1);
            FR2 = (FilterCfg->Id2 << 3) | (1u << 2);
        }
    }
    else /* 16-bit scale */
    {
        if (FilterCfg->Mode == CAN_FILTER_MODE_LIST)
        {
            /* 16-bit list mode: 4 ids, two ids per register */
            FR1 = ((uint32)Can_BuildStdId16((uint16)FilterCfg->Id2) << 16) |
                   (uint32)Can_BuildStdId16((uint16)FilterCfg->Id1);
            FR2 = ((uint32)Can_BuildStdId16((uint16)FilterCfg->Id4) << 16) |
                   (uint32)Can_BuildStdId16((uint16)FilterCfg->Id3);
        }
        else /* mask mode */
        {
            /* 16-bit mask mode: two pairs of [id + mask] */
            FR1 = ((uint32)Can_BuildStdId16((uint16)FilterCfg->Id2) << 16) |
                   (uint32)Can_BuildStdId16((uint16)FilterCfg->Id1);
            FR2 = ((uint32)((FilterCfg->Id4 & 0x7FFu) << 5) << 16) |
                   (uint32)((FilterCfg->Id2 & 0x7FFu) << 5);
        }
    }

    CAN_REG->sFilterRegister[FilterCfg->FilterBank].FR1 = FR1;
    CAN_REG->sFilterRegister[FilterCfg->FilterBank].FR2 = FR2;

    CAN_REG->CAN_FFA1R &= ~(1u << FilterCfg->FilterBank);   /* assign to FIFO 0 */
    CAN_REG->CAN_FA1R  |= (1u << FilterCfg->FilterBank);    /* activate the filter */

    CAN_REG->CAN_FMR &= ~(1u << 0);   /* exit filter init mode */

    return E_OK;
}


void Can_Init(const Can_ConfigType* Config)
{
    uint8 i;

    /* check config pointer and baudrate fields are valid */
    if ((Config == NULL_PTR) ||
        (Config->BaudrateConfig.TS2 > MAX_TS2) ||
        (Config->BaudrateConfig.TS1 > MAX_TS1) ||
        (Config->BaudrateConfig.SJW > MAX_SJW) ||
        (Config->BaudrateConfig.Prescaler == 0u) ||
        (Config->BaudrateConfig.Prescaler > MAX_PRE))
    {
        Can_CurrentState = CAN_CS_UNINIT;
        return;
    }

    /* enable CAN clock from RCC */
    RCC_REG->APB1ENR |= RCC_APB1ENR_CAN1ENABLE;

    /* wake up from sleep mode */
    CAN_REG->CAN_MCR &= ~CAN_MCR_Sleep;
    Can_CurrentState = CAN_CS_SLEEP;

    /* wait until sleep mode is left */
    uint32 t = CAN_TIMEOUT;
    while ((CAN_REG->CAN_MSR & CAN_MSR_SLAK) && --t);
    if (t == 0u)
    {
        Can_CurrentState = CAN_CS_UNINIT;
        return;
    }

    /* request init mode */
    CAN_REG->CAN_MCR |= (1u << CAN_INRQ_BIT);
    t = CAN_TIMEOUT;
    while (!(CAN_REG->CAN_MSR & (1u << CAN_INAK_BIT)) && --t);
    if (t == 0u)
    {
        Can_CurrentState = CAN_CS_UNINIT;
        return;
    }

    /* configure baudrate register */
    CAN_REG->CAN_BTR = ((uint32)Config->BaudrateConfig.SJW << 24) |
                        ((uint32)Config->BaudrateConfig.TS2 << 20) |
                        ((uint32)Config->BaudrateConfig.TS1 << 16) |
                        (uint32)(Config->BaudrateConfig.Prescaler - 1u) |
                        (Config->BaudrateConfig.LoopBack ? CAN_BTR_LBKM : 0u) |
                        (Config->BaudrateConfig.Silent   ? CAN_BTR_SILM : 0u);

    /* apply all filters from the config, like real AUTOSAR does */
    for (i = 0u; i < NUM_FILTERS; i++)
    {
        (void)Can_ConfigFilter(&Config->FilterConfig[i]);
    }

    Can_CurrentState = CAN_CS_STOPPED;
}


Std_ReturnType Can_SetBaudrate(uint8 Controller, uint16 BaudRateConfigID)
{
    uint32 t;

    (void)Controller;   /* only one controller in this driver */

    /* check baudrate id is in range */
    if (BaudRateConfigID >= CAN_NUM_BAUDRATE_CONFIGS)
    {
        return E_NOT_OK;
    }

    /* AUTOSAR says controller must be STOPPED before changing baudrate */
    if (Can_CurrentState != CAN_CS_STOPPED)
    {
        return E_NOT_OK;
    }

    const Can_ControllerBaudrateConfigType* NewConfig = &Can_BaudrateTable[BaudRateConfigID];

    /* validate new baudrate config values */
    if ((NewConfig->TS2 > MAX_TS2) || (NewConfig->TS1 > MAX_TS1) ||
        (NewConfig->SJW > MAX_SJW) || (NewConfig->Prescaler == 0u) ||
        (NewConfig->Prescaler > MAX_PRE))
    {
        return E_NOT_OK;
    }

    /* need to enter init mode again to modify BTR */
    CAN_REG->CAN_MCR |= (1u << CAN_INRQ_BIT);
    t = CAN_TIMEOUT;
    while (!(CAN_REG->CAN_MSR & (1u << CAN_INAK_BIT)) && --t);
    if (t == 0u) return E_NOT_OK;

    CAN_REG->CAN_BTR = ((uint32)NewConfig->SJW << 24) | ((uint32)NewConfig->TS2 << 20) |
                        ((uint32)NewConfig->TS1 << 16) | (uint32)(NewConfig->Prescaler - 1u) |
                        (NewConfig->LoopBack ? CAN_BTR_LBKM : 0u) |
                        (NewConfig->Silent   ? CAN_BTR_SILM : 0u);

    return E_OK;
}
Std_ReturnType Can_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition)
{
    uint32 t;
    (void)Controller;

    switch (Transition)
    {
    case CAN_CS_STARTED:
        /* can only start from STOPPED state */
        if (Can_CurrentState != CAN_CS_STOPPED)
        {
            return E_NOT_OK;
        }

        /* leave init mode to start the controller */
        CAN_REG->CAN_MCR &= ~(1u << CAN_INRQ_BIT);
        t = CAN_TIMEOUT;
        while ((CAN_REG->CAN_MSR & (1u << CAN_INAK_BIT)) && --t);

        if (t == 0u)
        {
            return E_NOT_OK;
        }

        Can_CurrentState = CAN_CS_STARTED;
        return E_OK;

    case CAN_CS_STOPPED:
        /* can only stop from STARTED state */
        if (Can_CurrentState != CAN_CS_STARTED)
        {
            return E_NOT_OK;
        }

        /* enter init mode to stop the controller */
        CAN_REG->CAN_MCR |= (1u << CAN_INRQ_BIT);
        t = CAN_TIMEOUT;
        while (!(CAN_REG->CAN_MSR & (1u << CAN_INAK_BIT)) && --t);

        if (t == 0u)
        {
            return E_NOT_OK;
        }

        Can_CurrentState = CAN_CS_STOPPED;
        return E_OK;

    default:
        /* sleep transition is not handled here yet */
        return E_NOT_OK;
    }
}
void Can_DisableControllerInterrupts(uint8 Controller)
{
    (void)Controller;
    NVIC_DisableIRQ(CAN1_RX0_IRQn);
    NVIC_DisableIRQ(CAN1_TX_IRQn);
}

void Can_EnableControllerInterrupts(uint8 Controller)
{
    (void)Controller;
    NVIC_EnableIRQ(CAN1_RX0_IRQn);
    NVIC_EnableIRQ(CAN1_TX_IRQn);
}

void Can_DeInit(void)
{
    uint32 t;

    /* nothing to do if not initialized */
    if (Can_CurrentState == CAN_CS_UNINIT)
    {
        return;
    }

    /* controller should be in STOPPED state before de-init */
    if (Can_CurrentState != CAN_CS_STOPPED)
    {
        /* could force stop here by entering init mode */
    }

    /* enter init mode to take controller off the bus */
    CAN_REG->CAN_MCR |= (1u << CAN_INRQ_BIT);
    t = CAN_TIMEOUT;
    while (!(CAN_REG->CAN_MSR & (1u << CAN_INAK_BIT)) && --t);

    /* request software reset, this will reset all registers */
    CAN_REG->CAN_MCR |= CAN_MCR_Reset;

    /* wait until reset is done */
    t = CAN_TIMEOUT;
    while ((CAN_REG->CAN_MCR & CAN_MCR_Reset) && --t);

    /* disable CAN clock */
    RCC_REG->APB1ENR &= ~RCC_APB1ENR_CAN1ENABLE;

    Can_CurrentState = CAN_CS_UNINIT;
}



/* Service ID [hex]: 0x11, Sync/Async: Synchronous, Reentrancy: Non Reentrant */
Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType* PduInfo)
{
    uint8   Mailbox;
    uint32  tsr;
    uint32  tdlr = 0u;
    uint32  tdhr = 0u;
    uint32  idValue;
    boolean extId;
    uint8   i;

    /* --- input checks --- */
    if (Can_CurrentState != CAN_CS_STARTED)          /* must be STARTED       */
    {
        return E_NOT_OK;
    }
    if ((Hth >= CAN_TX_HOH_COUNT) || (PduInfo == NULL_PTR))
    {
        return E_NOT_OK;
    }
    if (PduInfo->length > 8u)                        /* classic CAN: 0..8     */
    {
        return E_NOT_OK;
    }
    if ((PduInfo->length > 0u) && (PduInfo->sdu == NULL_PTR))
    {
        return E_NOT_OK;
    }
    if ((PduInfo->id & CAN_ID_FD_MASK) != 0u)        /* bxCAN does not support CAN FD */
    {
        return E_NOT_OK;
    }

    extId   = ((PduInfo->id & CAN_ID_EXT_MASK) != 0u);
    idValue = (uint32)(PduInfo->id & CAN_ID_VALUE_MASK);
    if ((extId == FALSE) && (idValue > 0x7FFu))      /* std id is 11-bit only */
    {
        return E_NOT_OK;
    }

    /* --- find a free transmit mailbox --- */
    tsr = CAN_REG->CAN_TSR;
    if      (tsr & TSR_TME0) Mailbox = 0u;
    else if (tsr & TSR_TME1) Mailbox = 1u;
    else if (tsr & TSR_TME2) Mailbox = 2u;
    else                     return CAN_BUSY;        /* no free mailbox       */

    /* --- copy exactly DLC bytes into TDLR and TDHR --- */
    for (i = 0u; (i < PduInfo->length) && (i < 4u); i++)
    {
        tdlr |= ((uint32)PduInfo->sdu[i]) << (8u * i);
    }
    for (; (i < PduInfo->length) && (i < 8u); i++)
    {
        tdhr |= ((uint32)PduInfo->sdu[i]) << (8u * (i - 4u));
    }

    /* --- save swPduHandle for the later Tx confirmation --- */
    Can_TxPending[Mailbox]     = TRUE;
    Can_TxSwPduHandle[Mailbox] = PduInfo->swPduHandle;

    /* --- fill the mailbox registers --- */
    if (extId != FALSE)
    {
        /* extended: EXID[28:0] -> TIR[31:3], IDE = 1 */
        CAN_REG->sTxMailBox[Mailbox].TIR = (idValue << 3) | CAN_TIR_IDE;
    }
    else
    {
        /* standard: STID[10:0] -> TIR[31:21], IDE = 0 */
        CAN_REG->sTxMailBox[Mailbox].TIR = (idValue << 21);
    }

    CAN_REG->sTxMailBox[Mailbox].TDTR = ((uint32)PduInfo->length & 0x0Fu);
    CAN_REG->sTxMailBox[Mailbox].TDLR = tdlr;
    CAN_REG->sTxMailBox[Mailbox].TDHR = tdhr;

    /* set TXRQ bit to start transmission */
    CAN_REG->sTxMailBox[Mailbox].TIR |= CAN_TIR_TXRQ;

    return E_OK;
}



void Can_MainFunction_Read(void)
{
    uint32 CanId;
    uint8  DLC;
    static uint8 RxData[8];
    boolean extId;

    /* do nothing if controller is not started */
    if (Can_CurrentState != CAN_CS_STARTED)
    {
        return;
    }

    /* check if there is a message in FIFO 0 */
    if (!(CAN_REG->CAN_RF0R & CAN_RF0R_FMP0))
    {
        return;
    }

    /* check if the received id is extended or standard */
    extId = (CAN_REG->sFIFOMailBox[0].RIR & CAN_RIR_IDE) != 0u;

    if (extId)
    {
        /* extended id: shift right by 3 and set the ext mask bit */
        CanId = ((CAN_REG->sFIFOMailBox[0].RIR >> 3) & 0x1FFFFFFFu) | CAN_ID_EXT_MASK;
    }
    else
    {
        /* standard id: shift right by 21 */
        CanId = (CAN_REG->sFIFOMailBox[0].RIR >> 21) & 0x7FFu;
    }

    /* read DLC from RDTR low bits */
    DLC = (uint8)(CAN_REG->sFIFOMailBox[0].RDTR & 0x0Fu);

    /* copy data bytes from RDLR and RDHR */
    RxData[0] = (uint8)(CAN_REG->sFIFOMailBox[0].RDLR >> 0);
    RxData[1] = (uint8)(CAN_REG->sFIFOMailBox[0].RDLR >> 8);
    RxData[2] = (uint8)(CAN_REG->sFIFOMailBox[0].RDLR >> 16);
    RxData[3] = (uint8)(CAN_REG->sFIFOMailBox[0].RDLR >> 24);
    RxData[4] = (uint8)(CAN_REG->sFIFOMailBox[0].RDHR >> 0);
    RxData[5] = (uint8)(CAN_REG->sFIFOMailBox[0].RDHR >> 8);
    RxData[6] = (uint8)(CAN_REG->sFIFOMailBox[0].RDHR >> 16);
    RxData[7] = (uint8)(CAN_REG->sFIFOMailBox[0].RDHR >> 24);

    /* release the FIFO 0 mailbox so the next message can come */
    CAN_REG->CAN_RF0R |= CAN_RF0R_RFOM0;

    /* Call the CanIf function with the custom signature */
    CanIf_RxIndication(CanId, RxData, DLC);
}
