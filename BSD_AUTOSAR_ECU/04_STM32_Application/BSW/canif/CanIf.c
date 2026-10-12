#include "CanIf.h"
#include "../Can/Can_Cfg.h" /* Include this to access Can_Config */

/* Extern callback to the upper layer (PduR) */
extern void PduR_CanIfRxIndication(PduIdType RxPduId, uint8* Data, uint8 DLC);

/* Simple state variable */
static CanIf_ControllerModeType CanIf_CurrentMode = CANIF_CS_UNINIT;

/* Simple lookup function to find RxPduId from CanId */
static uint8 CanIf_LookupRxPdu(uint32 CanId)
{
    uint8 i;
    for (i = 0u; i < CANIF_RX_PDU_COUNT; i++)
    {
        if (CanIf_RxPduConfig[i].CanId == CanId)
        {
            return CanIf_RxPduConfig[i].RxPduId;
        }
    }
    return 0xFFu; /* Not found */
}

/* Initialize CanIf and the CAN Driver */
void CanIf_Init(void)
{
    /* Initialize the CAN Driver with the generated configuration */
    Can_Init(&Can_Config);

    /* Set CanIf state to STOPPED after successful init */
    CanIf_CurrentMode = CANIF_CS_STOPPED;
}

/* Set Controller Mode */
Std_ReturnType CanIf_SetControllerMode(uint8 ControllerId, CanIf_ControllerModeType ControllerMode)
{
    (void)ControllerId; /* Only 1 controller in this project */

    Can_ControllerStateType Can_Mode;

    if (ControllerMode == CANIF_CS_STARTED)
    {
        Can_Mode = CAN_CS_STARTED;
    }
    else if (ControllerMode == CANIF_CS_STOPPED)
    {
        Can_Mode = CAN_CS_STOPPED;
    }
    else
    {
        return E_NOT_OK;
    }

    if (Can_SetControllerMode(0u, Can_Mode) == E_OK)
    {
        CanIf_CurrentMode = ControllerMode;
        return E_OK;
    }
    return E_NOT_OK;
}

/* Transmit a PDU */
Std_ReturnType CanIf_Transmit(PduIdType CanTxPduId, const PduInfoType* PduInfoPtr)
{
    Can_PduType CanPdu;

    /* Check if module is initialized and started */
    if (CanIf_CurrentMode != CANIF_CS_STARTED)
    {
        return E_NOT_OK;
    }

    /* Check parameters */
    if ((CanTxPduId >= CANIF_TX_PDU_COUNT) || (PduInfoPtr == NULL_PTR))
    {
        return E_NOT_OK;
    }

    /* Fill the Can_PduType structure */
    CanPdu.swPduHandle = CanTxPduId;
    CanPdu.id          = CanIf_TxPduConfig[CanTxPduId].CanId;
    CanPdu.length      = PduInfoPtr->SduLength;
    CanPdu.sdu         = PduInfoPtr->SduDataPtr;

    /* Call Can_Write (Hth = 0) */
    return Can_Write(0u, &CanPdu);
}

/* Rx Indication callback from Can Driver */
void CanIf_RxIndication(uint32 CanId, uint8* Data, uint8 DLC)
{
    PduIdType RxPduId;

    /* Only process if started */
    if (CanIf_CurrentMode != CANIF_CS_STARTED)
    {
        return;
    }

    /* Find which upper layer PDU this belongs to */
    RxPduId = CanIf_LookupRxPdu(CanId);

    if (RxPduId != 0xFFu)
    {
        /* Send to upper layer */
        PduR_CanIfRxIndication(RxPduId, Data, DLC);
    }
}


