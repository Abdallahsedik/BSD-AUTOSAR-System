/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
 *
 * \version 7.0.11
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2025 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef CANIF_CAN_H
#define CANIF_CAN_H

/*==================[inclusions]=============================================*/
#include <ComStack_Types.h>     /* AUTOSAR COM types */
#include <Can_GeneralTypes.h>   /* AUTOSAR CAN general types */
#include <CanIf_Types.h>        /* AUTOSAR CanIf types */
/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

#define CANIF_START_SEC_CODE
#include <CanIf_MemMap.h>

/** \brief Transmit confirmation callback function
 **
 ** This is the transmit confirmation callback function. It gets the PDU
 ** handle for the transmitted L-PDU, translates it for the upper layer and
 ** then calls the upper layer callback function configured for this handle.
 ** It furthermore starts the next transmission for the used HTH if there
 ** are other messages pending for transmission.
 **
 ** Preconditions:
 ** - The CAN interface must already be initialized by CanIf_Init()
 ** - The parameter \p CanTxPduId must be a valid Tx L-PDU
 **
 ** \param[in] CanTxPduId Tx L-PDU handle
 **
 ** \ServiceID{0x13}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC( void, CANIF_CODE ) CanIf_TxConfirmation( PduIdType CanTxPduId );

/** \brief Receive indication callback function
 **
 ** This is the receive indication callback function. It calls the
 ** corresponding upper layer receive indication callback function and
 ** stores the received message if the read PDU data API is enabled.
 **

 ** Preconditions:
 ** - The CAN interface must already be initialized by CanIf_Init()
 ** - The parameter \p Mailbox must be a valid HRH and a valid CAN ID
 ** - The parameter \p PduInfoPtr must be a valid pointer
 **
 ** \param[in] Mailbox identifier of the HRH and its corresponding CAN Controller
 ** \param[in] PduInfoPtr Pointer to the received data
 **
 ** \ServiceID{0x14}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC( void, CANIF_CODE ) CanIf_RxIndication
(
  P2CONST( Can_HwType, AUTOMATIC, CANIF_APPL_DATA ) Mailbox,
  P2CONST( PduInfoType, AUTOMATIC, CANIF_APPL_DATA ) PduInfoPtr
);


/** \brief Bus-off callback function
 **
 ** This is the bus-off callback function. It changes the mode of the given
 ** controller \p Controller to STOPPED and clears the Tx buffers if
 ** necessary.
 **
 ** Preconditions:
 ** - The CAN interface must already be initialized by CanIf_Init()
 ** - The parameter \p Controller must be a valid pointer
 **
 ** \param[in] Controller Controller which went bus-off
 **
 ** \ServiceID{0x16}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC( void, CANIF_CODE ) CanIf_ControllerBusOff
(
  uint8 Controller
);

/** \brief Controller mode indication callback function
 **
 ** This is the controller mode indication callback function.
 **
 ** Preconditions:
 ** - The parameter \p controller must be a valid CanIf controller ID
 **
 ** \param[in] ControllerId Controller for which the mode is indicated
 ** \param[in] ControllerMode Mode to which the controller switched
 **
 ** \ServiceID{0x17}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC( void, CANIF_CODE ) CanIf_ControllerModeIndication
(
  uint8 ControllerId,
  Can_ControllerStateType ControllerMode
);




/*node:existsAndTrue(CanIfPublicCfg/CanIfEnableSecurityEventReporting)*/

#define CANIF_STOP_SEC_CODE
#include <CanIf_MemMap.h>

#endif /* ifndef CANIF_CAN_H */
