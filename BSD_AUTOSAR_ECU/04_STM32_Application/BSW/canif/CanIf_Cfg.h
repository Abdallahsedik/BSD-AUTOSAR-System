#ifndef CANIF_CFG_H_
#define CANIF_CFG_H_

#include "Std_Types.h"

/* TX PDU IDs (Used by upper layer to send) */
#define CANIF_TX_PDU_WARNING        0u  /* 0x300 -> Instrument Cluster */
#define CANIF_TX_PDU_LED            1u  /* 0x301 -> BCM */
#define CANIF_TX_PDU_COUNT          2u

/* RX PDU IDs (Used by upper layer to receive) */
#define CANIF_RX_PDU_RADAR_L        0u  /* 0x200 */
#define CANIF_RX_PDU_RADAR_R        1u  /* 0x201 */
#define CANIF_RX_PDU_ABS            2u  /* 0x100 */
#define CANIF_RX_PDU_BCM            3u  /* 0x3A0 */
#define CANIF_RX_PDU_EPS            4u  /* 0x2E0 */
#define CANIF_RX_PDU_TCU            5u  /* 0x1A0 */
#define CANIF_RX_PDU_COUNT          6u


/* Configuration Types */
typedef struct {
    uint32 CanId;
    uint8  DLC;
} CanIf_TxPduCfgType;

typedef struct {
    uint32 CanId;
    uint8  DLC;
    uint8  RxPduId;
} CanIf_RxPduCfgType;

/* Extern declarations for configuration tables */
extern const CanIf_TxPduCfgType CanIf_TxPduConfig[CANIF_TX_PDU_COUNT];
extern const CanIf_RxPduCfgType CanIf_RxPduConfig[CANIF_RX_PDU_COUNT];

#endif /* CANIF_CFG_H_ */
