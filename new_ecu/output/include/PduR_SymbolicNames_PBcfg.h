/**
 * \file
 *
 * \brief AUTOSAR PduR
 *
 * This file contains the implementation of the AUTOSAR
 * module PduR.
 *
 * \version 6.0.5
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2025 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef PDUR_SYMBOLIC_NAMES_PBCFG_H
#define PDUR_SYMBOLIC_NAMES_PBCFG_H

/*==================[includes]==============================================*/

/*==================[macros]================================================*/
/* -------------------- Routing path: 0 PduR_Route_RadarRight */
#if (defined PduRConf_PduRSrcPdu_BSD_Radar_Right_PDU)
#error PduRConf_PduRSrcPdu_BSD_Radar_Right_PDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_BSD_Radar_Right_PDU 1U /* SRC CanIf-LO-IF */


#if (defined PduRConf_PduRDestPdu_Com_BSD_Radar_Right_PDU)
#error PduRConf_PduRDestPdu_Com_BSD_Radar_Right_PDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Com_BSD_Radar_Right_PDU 1U /* DEST Com-UP-IF Direct */


/* -------------------- Routing path: 1 PduR_Route_RadarLeft */
#if (defined PduRConf_PduRSrcPdu_BSD_Radar_Left_PDU)
#error PduRConf_PduRSrcPdu_BSD_Radar_Left_PDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_BSD_Radar_Left_PDU 0U /* SRC CanIf-LO-IF */


#if (defined PduRConf_PduRDestPdu_Com_BSD_Radar_Left_PDU)
#error PduRConf_PduRDestPdu_Com_BSD_Radar_Left_PDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Com_BSD_Radar_Left_PDU 0U /* DEST Com-UP-IF Direct */


/* -------------------- Routing path: 2 PduR_Route_Speed */
#if (defined PduRConf_PduRSrcPdu_BSD_Speed_PDU)
#error PduRConf_PduRSrcPdu_BSD_Speed_PDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_BSD_Speed_PDU 2U /* SRC CanIf-LO-IF */


#if (defined PduRConf_PduRDestPdu_Com_BSD_Speed_PDU)
#error PduRConf_PduRDestPdu_Com_BSD_Speed_PDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Com_BSD_Speed_PDU 2U /* DEST Com-UP-IF Direct */


/* -------------------- Routing path: 3 PduR_Route_TurnSignal */
#if (defined PduRConf_PduRSrcPdu_BSD_TurnSignal_PDU)
#error PduRConf_PduRSrcPdu_BSD_TurnSignal_PDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_BSD_TurnSignal_PDU 3U /* SRC CanIf-LO-IF */


#if (defined PduRConf_PduRDestPdu_Com_BSD_TurnSignal_PDU)
#error PduRConf_PduRDestPdu_Com_BSD_TurnSignal_PDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Com_BSD_TurnSignal_PDU 3U /* DEST Com-UP-IF Direct */


/* -------------------- Routing path: 4 PduR_Route_Steering */
#if (defined PduRConf_PduRSrcPdu_BSD_Steering_PDU)
#error PduRConf_PduRSrcPdu_BSD_Steering_PDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_BSD_Steering_PDU 4U /* SRC CanIf-LO-IF */


#if (defined PduRConf_PduRDestPdu_Com_BSD_Steering_PDU)
#error PduRConf_PduRDestPdu_Com_BSD_Steering_PDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Com_BSD_Steering_PDU 4U /* DEST Com-UP-IF Direct */


/* -------------------- Routing path: 5 PduR_Route_Gear */
#if (defined PduRConf_PduRSrcPdu_BSD_Gear_PDU)
#error PduRConf_PduRSrcPdu_BSD_Gear_PDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_BSD_Gear_PDU 5U /* SRC CanIf-LO-IF */


#if (defined PduRConf_PduRDestPdu_Com_BSD_Gear_PDU)
#error PduRConf_PduRDestPdu_Com_BSD_Gear_PDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Com_BSD_Gear_PDU 5U /* DEST Com-UP-IF Direct */


/* -------------------- Routing path: 6 PduR_Route_Warning */
#if (defined PduRConf_PduRSrcPdu_Com_BSD_Warning_TxPDU)
#error PduRConf_PduRSrcPdu_Com_BSD_Warning_TxPDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Com_BSD_Warning_TxPDU 0U /* SRC Com-UP-IF */


#if (defined PduRConf_PduRDestPdu_BSD_Warning_TxPDU)
#error PduRConf_PduRDestPdu_BSD_Warning_TxPDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_BSD_Warning_TxPDU 0U /* DEST CanIf-LO-IF Direct */


/* -------------------- Routing path: 7 PduR_Route_LED */
#if (defined PduRConf_PduRSrcPdu_Com_BSD_LED_TxPDU)
#error PduRConf_PduRSrcPdu_Com_BSD_LED_TxPDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Com_BSD_LED_TxPDU 1U /* SRC Com-UP-IF */


#if (defined PduRConf_PduRDestPdu_BSD_LED_TxPDU)
#error PduRConf_PduRDestPdu_BSD_LED_TxPDU is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_BSD_LED_TxPDU 1U /* DEST CanIf-LO-IF Direct */



/* Define vendor specific destination PDU IDs of adjacent modules */
#if (defined PDUR_PROVIDE_ADJACENT_MODULE_VENDOR_SYMBOLIC_NAMES)

/* -------------------- Routing path: 0 PduR_Route_RadarRight */
/* PDURSA_Pdu_Radar_Right   SRC CanIf-LO-IF Not defined since the configuration does not supply this ID */
#define PDURDA_Pdu_Radar_Right 1U /* DEST Com-UP-IF DIRECT */

/* -------------------- Routing path: 1 PduR_Route_RadarLeft */
/* PDURSA_Pdu_Radar_Left   SRC CanIf-LO-IF Not defined since the configuration does not supply this ID */
#define PDURDA_Pdu_Radar_Left 0U /* DEST Com-UP-IF DIRECT */

/* -------------------- Routing path: 2 PduR_Route_Speed */
/* PDURSA_Pdu_Speed   SRC CanIf-LO-IF Not defined since the configuration does not supply this ID */
#define PDURDA_Pdu_Speed 2U /* DEST Com-UP-IF DIRECT */

/* -------------------- Routing path: 3 PduR_Route_TurnSignal */
/* PDURSA_Pdu_TurnSignal   SRC CanIf-LO-IF Not defined since the configuration does not supply this ID */
#define PDURDA_Pdu_TurnSignal 3U /* DEST Com-UP-IF DIRECT */

/* -------------------- Routing path: 4 PduR_Route_Steering */
/* PDURSA_Pdu_Steering   SRC CanIf-LO-IF Not defined since the configuration does not supply this ID */
#define PDURDA_Pdu_Steering 4U /* DEST Com-UP-IF DIRECT */

/* -------------------- Routing path: 5 PduR_Route_Gear */
/* PDURSA_Pdu_Gear   SRC CanIf-LO-IF Not defined since the configuration does not supply this ID */
#define PDURDA_Pdu_Gear 5U /* DEST Com-UP-IF DIRECT */

/* -------------------- Routing path: 6 PduR_Route_Warning */
#define PDURSA_Pdu_Warning_Tx 1U /* SRC Com-UP-IF */
#define PDURDA_Pdu_Warning_Tx 0U /* DEST CanIf-LO-IF DIRECT */

/* -------------------- Routing path: 7 PduR_Route_LED */
#define PDURSA_Pdu_LED_Tx 0U /* SRC Com-UP-IF */
#define PDURDA_Pdu_LED_Tx 1U /* DEST CanIf-LO-IF DIRECT */

#endif /* defined PDUR_PROVIDE_ADJACENT_MODULE_VENDOR_SYMBOLIC_NAMES */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef PDUR_SYMBOLIC_NAMES_PBCFG_H  */
/*==================[end of file]===========================================*/
