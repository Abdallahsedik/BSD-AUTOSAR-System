#include "Com.h"
#include "../PduR/PduR.h"
#include <string.h>

/* TX and RX I-PDU Buffers (Array of 8-byte buffers for each PDU) */
static uint8 Com_TxIpduBuffer[COM_NUM_TX_PDUS][8];
static uint8 Com_RxIpduBuffer[COM_NUM_RX_PDUS][8];

/* Configuration Table based on SRS CAN Matrix */
/* BitPos is calculated as (Byte_Index * 8) + Bit_Offset */
const Com_SignalConfigType Com_SignalConfig[COM_NUM_SIGNALS] =
{
    /* --- TX Signals --- */
    /* SignalId,                    PduId,                  BitPos, BitLen, IsTx  */
    { COM_SIG_WARNING_STATE_LEFT,   COM_IPDU_TX_WARNING,    0,      8,      TRUE  }, /* 0x300 Byte 0 */
    { COM_SIG_WARNING_STATE_RIGHT,  COM_IPDU_TX_WARNING,    8,      8,      TRUE  }, /* 0x300 Byte 1 */
    { COM_SIG_LED_LEFT,             COM_IPDU_TX_LED,        0,      8,      TRUE  }, /* 0x301 Byte 0 */
    { COM_SIG_LED_RIGHT,            COM_IPDU_TX_LED,        8,      8,      TRUE  }, /* 0x301 Byte 1 */

    /* --- RX Signals --- */
    { COM_SIG_VEHICLE_SPEED,        COM_IPDU_RX_ABS,        0,      16,     FALSE }, /* 0x100 Byte 0-1 */
    { COM_SIG_RADAR_LEFT_DIST,      COM_IPDU_RX_RADAR_L,    0,      16,     FALSE }, /* 0x200 Byte 0-1 */
    { COM_SIG_RADAR_LEFT_STATUS,    COM_IPDU_RX_RADAR_L,    16,     8,      FALSE }, /* 0x200 Byte 2   */
    { COM_SIG_RADAR_RIGHT_DIST,     COM_IPDU_RX_RADAR_R,    0,      16,     FALSE }, /* 0x201 Byte 0-1 */
    { COM_SIG_RADAR_RIGHT_STATUS,   COM_IPDU_RX_RADAR_R,    16,     8,      FALSE }, /* 0x201 Byte 2   */
    { COM_SIG_TURN_SIGNAL,          COM_IPDU_RX_BCM,        0,      8,      FALSE }, /* 0x3A0 Byte 0   */
    { COM_SIG_STEERING_ANGLE,       COM_IPDU_RX_EPS,        0,      16,     FALSE }, /* 0x2E0 Byte 0-1 */
    { COM_SIG_GEAR,                 COM_IPDU_RX_TCU,        0,      8,      FALSE }  /* 0x1A0 Byte 0   */
};

void Com_Init(void)
{
    memset(Com_TxIpduBuffer, 0, sizeof(Com_TxIpduBuffer));
    memset(Com_RxIpduBuffer, 0, sizeof(Com_RxIpduBuffer));
}

uint8 Com_SendSignal(uint16 SignalId, const void* SignalDataPtr)
{
    if (SignalId >= COM_NUM_SIGNALS) return E_NOT_OK;

    const Com_SignalConfigType* cfg = &Com_SignalConfig[SignalId];
    uint8 byte_idx = cfg->BitPosition / 8;

    /* Pack signal into the correct TX PDU buffer */
    if (cfg->BitLength == 8)
    {
        uint8 value = *(const uint8*)SignalDataPtr;
        Com_TxIpduBuffer[cfg->PduId][byte_idx] = value;
    }
    else if (cfg->BitLength == 16)
    {
        uint16 value = *(const uint16*)SignalDataPtr;
        Com_TxIpduBuffer[cfg->PduId][byte_idx]     = (uint8)(value & 0xFF);         /* Low byte */
        Com_TxIpduBuffer[cfg->PduId][byte_idx + 1] = (uint8)((value >> 8) & 0xFF);  /* High byte */
    }

    /* Prepare PduInfo for PduR */
    PduInfoType pduInfo;
    pduInfo.SduDataPtr = Com_TxIpduBuffer[cfg->PduId];
    pduInfo.SduLength = 8;

    /* Request transmission */
    return PduR_ComTransmit(cfg->PduId, &pduInfo);
}

uint8 Com_ReceiveSignal(uint16 SignalId, void* SignalDataPtr)
{
    if (SignalId >= COM_NUM_SIGNALS) return E_NOT_OK;

    const Com_SignalConfigType* cfg = &Com_SignalConfig[SignalId];
    uint8 byte_idx = cfg->BitPosition / 8;

    /* Unpack signal from the correct RX PDU buffer */
    if (cfg->BitLength == 8)
    {
        uint8* value = (uint8*)SignalDataPtr;
        *value = Com_RxIpduBuffer[cfg->PduId][byte_idx];
    }
    else if (cfg->BitLength == 16)
    {
        uint16* value = (uint16*)SignalDataPtr;
        *value = (uint16)Com_RxIpduBuffer[cfg->PduId][byte_idx];
        *value |= ((uint16)Com_RxIpduBuffer[cfg->PduId][byte_idx + 1] << 8);
    }

    return E_OK;
}

/* Called by PduR when a CAN message is received */
void Com_RxIndication(PduIdType RxPduId, uint8* Data, uint8 DLC)
{
    uint8 i;
    (void)DLC;

    if (RxPduId < COM_NUM_RX_PDUS)
    {
        /* Copy received data into the specific RX PDU buffer */
        for (i = 0; i < 8; i++)
        {
            Com_RxIpduBuffer[RxPduId][i] = Data[i];
        }
    }
}
