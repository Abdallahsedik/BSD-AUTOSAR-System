#ifndef COM_H_
#define COM_H_

#include "Std_Types.h"
#include "../PduR/PduR_Types.h"
#include "Com_Cfg.h"


/* Initialize the COM module */
void Com_Init(void);

/* Send a signal (Application -> COM -> PduR -> CanIf) */
uint8 Com_SendSignal(uint16 SignalId, const void* SignalDataPtr);

/* Receive a signal (CanIf -> PduR -> COM -> Application) */
uint8 Com_ReceiveSignal(uint16 SignalId, void* SignalDataPtr);

/* Callback from PduR when a new I-PDU is received */
void Com_RxIndication(PduIdType RxPduId, uint8* Data, uint8 DLC);

#endif /* COM_H_ */
