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


  #ifndef CANIF_SYMBOLICNAMES_PBCFG_H
#define CANIF_SYMBOLICNAMES_PBCFG_H

/*==================[includes]===============================================*/
/*==================[macros]=================================================*/

/*------------------[symbolic name values]----------------------------------*/

/** \brief Export symbolic name values for CanIfTxPduIds */


#if (defined CanIfConf_CanIfTxPduCfg_BSD_Warning_TxPDU)
#error CanIfConf_CanIfTxPduCfg_BSD_Warning_TxPDU already defined!
#endif /* #if( defined CanIfConf_CanIfTxPduCfg_BSD_Warning_TxPDU)*/
#define CanIfConf_CanIfTxPduCfg_BSD_Warning_TxPDU 0U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_BSD_Warning_TxPDU)
#error CanIf_BSD_Warning_TxPDU already defined!
#endif /* #if( defined CanIf_BSD_Warning_TxPDU)*/
#define CanIf_BSD_Warning_TxPDU 0U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined CanIfConf_CanIfTxPduCfg_BSD_LED_TxPDU)
#error CanIfConf_CanIfTxPduCfg_BSD_LED_TxPDU already defined!
#endif /* #if( defined CanIfConf_CanIfTxPduCfg_BSD_LED_TxPDU)*/
#define CanIfConf_CanIfTxPduCfg_BSD_LED_TxPDU 1U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_BSD_LED_TxPDU)
#error CanIf_BSD_LED_TxPDU already defined!
#endif /* #if( defined CanIf_BSD_LED_TxPDU)*/
#define CanIf_BSD_LED_TxPDU 1U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/** \brief Export symbolic name values for CanIfRxPduIds */


#if (defined CanIfConf_CanIfRxPduCfg_BSD_Radar_Left_PDU)
#error CanIfConf_CanIfRxPduCfg_BSD_Radar_Left_PDU already defined!
#endif /* #if( defined CanIfConf_CanIfRxPduCfg_BSD_Radar_Left_PDU)*/
#define CanIfConf_CanIfRxPduCfg_BSD_Radar_Left_PDU 0U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_BSD_Radar_Left_PDU)
#error CanIf_BSD_Radar_Left_PDU already defined!
#endif /* #if( defined CanIf_BSD_Radar_Left_PDU)*/
#define CanIf_BSD_Radar_Left_PDU 0U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined CanIfConf_CanIfRxPduCfg_BSD_Radar_Right_PDU)
#error CanIfConf_CanIfRxPduCfg_BSD_Radar_Right_PDU already defined!
#endif /* #if( defined CanIfConf_CanIfRxPduCfg_BSD_Radar_Right_PDU)*/
#define CanIfConf_CanIfRxPduCfg_BSD_Radar_Right_PDU 1U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_BSD_Radar_Right_PDU)
#error CanIf_BSD_Radar_Right_PDU already defined!
#endif /* #if( defined CanIf_BSD_Radar_Right_PDU)*/
#define CanIf_BSD_Radar_Right_PDU 1U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined CanIfConf_CanIfRxPduCfg_BSD_Speed_PDU)
#error CanIfConf_CanIfRxPduCfg_BSD_Speed_PDU already defined!
#endif /* #if( defined CanIfConf_CanIfRxPduCfg_BSD_Speed_PDU)*/
#define CanIfConf_CanIfRxPduCfg_BSD_Speed_PDU 2U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_BSD_Speed_PDU)
#error CanIf_BSD_Speed_PDU already defined!
#endif /* #if( defined CanIf_BSD_Speed_PDU)*/
#define CanIf_BSD_Speed_PDU 2U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined CanIfConf_CanIfRxPduCfg_BSD_TurnSignal_PDU)
#error CanIfConf_CanIfRxPduCfg_BSD_TurnSignal_PDU already defined!
#endif /* #if( defined CanIfConf_CanIfRxPduCfg_BSD_TurnSignal_PDU)*/
#define CanIfConf_CanIfRxPduCfg_BSD_TurnSignal_PDU 3U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_BSD_TurnSignal_PDU)
#error CanIf_BSD_TurnSignal_PDU already defined!
#endif /* #if( defined CanIf_BSD_TurnSignal_PDU)*/
#define CanIf_BSD_TurnSignal_PDU 3U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined CanIfConf_CanIfRxPduCfg_BSD_Steering_PDU)
#error CanIfConf_CanIfRxPduCfg_BSD_Steering_PDU already defined!
#endif /* #if( defined CanIfConf_CanIfRxPduCfg_BSD_Steering_PDU)*/
#define CanIfConf_CanIfRxPduCfg_BSD_Steering_PDU 4U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_BSD_Steering_PDU)
#error CanIf_BSD_Steering_PDU already defined!
#endif /* #if( defined CanIf_BSD_Steering_PDU)*/
#define CanIf_BSD_Steering_PDU 4U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined CanIfConf_CanIfRxPduCfg_BSD_Gear_PDU)
#error CanIfConf_CanIfRxPduCfg_BSD_Gear_PDU already defined!
#endif /* #if( defined CanIfConf_CanIfRxPduCfg_BSD_Gear_PDU)*/
#define CanIfConf_CanIfRxPduCfg_BSD_Gear_PDU 5U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_BSD_Gear_PDU)
#error CanIf_BSD_Gear_PDU already defined!
#endif /* #if( defined CanIf_BSD_Gear_PDU)*/
#define CanIf_BSD_Gear_PDU 5U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/** \brief Export symbolic name values for CanIfCtrlIds */


#if (defined CanIfConf_BSD_CanIfCtrlDrv_CanIfCtrlCfg_0)
#error CanIfConf_BSD_CanIfCtrlDrv_CanIfCtrlCfg_0 already defined!
#endif /* #if( defined CanIfConf_BSD_CanIfCtrlDrv_CanIfCtrlCfg_0)*/
#define CanIfConf_BSD_CanIfCtrlDrv_CanIfCtrlCfg_0 0U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_BSD_CanIfCtrlDrv_CanIfCtrlCfg_0)
#error CanIf_BSD_CanIfCtrlDrv_CanIfCtrlCfg_0 already defined!
#endif /* #if( defined CanIf_BSD_CanIfCtrlDrv_CanIfCtrlCfg_0)*/
#define CanIf_BSD_CanIfCtrlDrv_CanIfCtrlCfg_0 0U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/** \brief Export symbolic name values for CanIfTrcvIds */


/** \brief Export symbolic name values for CanIfRxPduTargetPduID */

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef CANIF_SYMBOLICNAMES_PBCFG_H */
/*==================[end of file]============================================*/
