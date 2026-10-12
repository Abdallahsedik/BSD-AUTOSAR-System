#include "CanIf_Cfg.h"




/* TX Configuration Table */
const CanIf_TxPduCfgType CanIf_TxPduConfig[CANIF_TX_PDU_COUNT] =
{
		{ 0x300u, 2u }, /* Instrument Cluster */
		{ 0x301u, 1u }  /* BCM */
};

/* RX Configuration Table */
const CanIf_RxPduCfgType CanIf_RxPduConfig[CANIF_RX_PDU_COUNT] =
{
    /* [0] */ { 0x200u, 8u, CANIF_RX_PDU_RADAR_L }, /* Radar Left */
    /* [1] */ { 0x201u, 8u, CANIF_RX_PDU_RADAR_R }, /* Radar Right */
    /* [2] */ { 0x100u, 2u, CANIF_RX_PDU_ABS     }, /* ABS */
    /* [3] */ { 0x3A0u, 1u, CANIF_RX_PDU_BCM     }, /* BCM */
    /* [4] */ { 0x2E0u, 2u, CANIF_RX_PDU_EPS     }, /* EPS */
    /* [5] */ { 0x1A0u, 1u, CANIF_RX_PDU_TCU     }  /* TCU */
};
