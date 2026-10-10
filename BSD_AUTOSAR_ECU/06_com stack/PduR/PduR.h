#ifndef PduR_H_
#define PduR_H_

#include "Std_Types.h"
#include "../can/Can_GeneralTypes.h"
#include "PduR_Types.h"

/* Initialize (empty for now) */
void PduR_Init(void);

/* Called by CanIf when a message is received */
void PduR_CanIfRxIndication(PduIdType RxPduId, uint8* Data, uint8 DLC);

/* Called by Com to request a transmission */
Std_ReturnType PduR_ComTransmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr);

#endif /* PduR_H_ */
