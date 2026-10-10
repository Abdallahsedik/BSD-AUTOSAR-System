#ifndef CANIF_CANIF_H_
#define CANIF_CANIF_H_

#include "Std_Types.h"
#include "../Can/Can_GeneralTypes.h"
#include "../Can/Can.h"
#include "CanIf_Cfg.h"

/* CanIf Controller Modes  */
typedef enum {
    CANIF_CS_UNINIT = 0,
    CANIF_CS_STOPPED,
    CANIF_CS_STARTED
} CanIf_ControllerModeType;

/* Initialization */
void CanIf_Init(void);

/* Mode Control */
Std_ReturnType CanIf_SetControllerMode(uint8 ControllerId, CanIf_ControllerModeType ControllerMode);
Std_ReturnType CanIf_GetControllerMode(uint8 ControllerId, CanIf_ControllerModeType* ControllerModePtr);

/* Transmit */
Std_ReturnType CanIf_Transmit(PduIdType CanTxPduId, const PduInfoType* PduInfoPtr);

/* Callbacks from Can Driver */
void CanIf_RxIndication(uint32 CanId, uint8* Data, uint8 DLC);

#endif /* CANIF_CANIF_H_ */
