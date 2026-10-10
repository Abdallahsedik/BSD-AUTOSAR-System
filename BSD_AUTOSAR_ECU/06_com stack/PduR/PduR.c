#include "PduR.h"
#include "../CanIf/CanIf.h"
#include "../Com/Com.h"

void PduR_Init(void) {}

/* CanIf -> PduR -> Com */
void PduR_CanIfRxIndication(PduIdType RxPduId, uint8* Data, uint8 DLC)
{
    /* Forward the received data to the COM module */
    Com_RxIndication(RxPduId, Data, DLC);
}

/* Com -> PduR -> CanIf */
Std_ReturnType PduR_ComTransmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr)
{
    /* Forward the transmit request to CanIf */
    return CanIf_Transmit(TxPduId, PduInfoPtr);
}
