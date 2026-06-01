#ifndef COM_SYMBOLIC_NAMES_PB_CFG_H
#define COM_SYMBOLIC_NAMES_PB_CFG_H

/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \version 7.0.4
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2025 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[includes]==============================================*/

/*==================[macros]================================================*/

/* IPDU group ID defines */
/* External Rx IPdus defines */
#if (defined ComConf_ComIPdu_ComIPdu_Radar_Left) /* To prevent double declaration */
#error ComConf_ComIPdu_ComIPdu_Radar_Left already defined
#endif /* #if (defined ComConf_ComIPdu_ComIPdu_Radar_Left) */

#define ComConf_ComIPdu_ComIPdu_Radar_Left 0U


#if (defined ComConf_ComIPdu_ComIPdu_Radar_Right) /* To prevent double declaration */
#error ComConf_ComIPdu_ComIPdu_Radar_Right already defined
#endif /* #if (defined ComConf_ComIPdu_ComIPdu_Radar_Right) */

#define ComConf_ComIPdu_ComIPdu_Radar_Right 1U


#if (defined ComConf_ComIPdu_ComIPdu_Speed) /* To prevent double declaration */
#error ComConf_ComIPdu_ComIPdu_Speed already defined
#endif /* #if (defined ComConf_ComIPdu_ComIPdu_Speed) */

#define ComConf_ComIPdu_ComIPdu_Speed 2U


#if (defined ComConf_ComIPdu_ComIPdu_TurnSignal) /* To prevent double declaration */
#error ComConf_ComIPdu_ComIPdu_TurnSignal already defined
#endif /* #if (defined ComConf_ComIPdu_ComIPdu_TurnSignal) */

#define ComConf_ComIPdu_ComIPdu_TurnSignal 3U


#if (defined ComConf_ComIPdu_ComIPdu_Steering) /* To prevent double declaration */
#error ComConf_ComIPdu_ComIPdu_Steering already defined
#endif /* #if (defined ComConf_ComIPdu_ComIPdu_Steering) */

#define ComConf_ComIPdu_ComIPdu_Steering 4U


#if (defined ComConf_ComIPdu_ComIPdu_Gear) /* To prevent double declaration */
#error ComConf_ComIPdu_ComIPdu_Gear already defined
#endif /* #if (defined ComConf_ComIPdu_ComIPdu_Gear) */

#define ComConf_ComIPdu_ComIPdu_Gear 5U


/* External Tx IPdu defines */
#if (defined ComConf_ComIPdu_ComIPdu_LED_Tx) /* To prevent double declaration */
#error ComConf_ComIPdu_ComIPdu_LED_Tx already defined
#endif /* #if (defined ComConf_ComIPdu_ComIPdu_LED_Tx) */

#define ComConf_ComIPdu_ComIPdu_LED_Tx 0U


#if (defined ComConf_ComIPdu_ComIPdu_Warning_Tx) /* To prevent double declaration */
#error ComConf_ComIPdu_ComIPdu_Warning_Tx already defined
#endif /* #if (defined ComConf_ComIPdu_ComIPdu_Warning_Tx) */

#define ComConf_ComIPdu_ComIPdu_Warning_Tx 1U


/* External Rx Signal IDs (no group signals) defines */
#if (defined ComConf_ComSignal_S_Radar_Left_Distance) /* To prevent double declaration */
#error ComConf_ComSignal_S_Radar_Left_Distance already defined
#endif /* #if (defined ComConf_ComSignal_S_Radar_Left_Distance) */

#define ComConf_ComSignal_S_Radar_Left_Distance 0U


#if (defined ComConf_ComSignal_S_Radar_Left_ObjectDetected) /* To prevent double declaration */
#error ComConf_ComSignal_S_Radar_Left_ObjectDetected already defined
#endif /* #if (defined ComConf_ComSignal_S_Radar_Left_ObjectDetected) */

#define ComConf_ComSignal_S_Radar_Left_ObjectDetected 1U


#if (defined ComConf_ComSignal_S_Radar_Right_Distance) /* To prevent double declaration */
#error ComConf_ComSignal_S_Radar_Right_Distance already defined
#endif /* #if (defined ComConf_ComSignal_S_Radar_Right_Distance) */

#define ComConf_ComSignal_S_Radar_Right_Distance 2U


#if (defined ComConf_ComSignal_S_Radar_Right_ObjectDetected) /* To prevent double declaration */
#error ComConf_ComSignal_S_Radar_Right_ObjectDetected already defined
#endif /* #if (defined ComConf_ComSignal_S_Radar_Right_ObjectDetected) */

#define ComConf_ComSignal_S_Radar_Right_ObjectDetected 3U


#if (defined ComConf_ComSignal_S_Vehicle_Speed) /* To prevent double declaration */
#error ComConf_ComSignal_S_Vehicle_Speed already defined
#endif /* #if (defined ComConf_ComSignal_S_Vehicle_Speed) */

#define ComConf_ComSignal_S_Vehicle_Speed 4U


#if (defined ComConf_ComSignal_S_TurnSignal_State) /* To prevent double declaration */
#error ComConf_ComSignal_S_TurnSignal_State already defined
#endif /* #if (defined ComConf_ComSignal_S_TurnSignal_State) */

#define ComConf_ComSignal_S_TurnSignal_State 5U


#if (defined ComConf_ComSignal_S_Steering_Angle) /* To prevent double declaration */
#error ComConf_ComSignal_S_Steering_Angle already defined
#endif /* #if (defined ComConf_ComSignal_S_Steering_Angle) */

#define ComConf_ComSignal_S_Steering_Angle 6U


#if (defined ComConf_ComSignal_S_Current_Gear) /* To prevent double declaration */
#error ComConf_ComSignal_S_Current_Gear already defined
#endif /* #if (defined ComConf_ComSignal_S_Current_Gear) */

#define ComConf_ComSignal_S_Current_Gear 7U


/* External Tx Signal IDs (no group signals) defines */
#if (defined ComConf_ComSignal_S_Warning_State) /* To prevent double declaration */
#error ComConf_ComSignal_S_Warning_State already defined
#endif /* #if (defined ComConf_ComSignal_S_Warning_State) */

#define ComConf_ComSignal_S_Warning_State 0U


#if (defined ComConf_ComSignal_S_Buzzer_Frequency) /* To prevent double declaration */
#error ComConf_ComSignal_S_Buzzer_Frequency already defined
#endif /* #if (defined ComConf_ComSignal_S_Buzzer_Frequency) */

#define ComConf_ComSignal_S_Buzzer_Frequency 1U


#if (defined ComConf_ComSignal_S_LED_Intensity) /* To prevent double declaration */
#error ComConf_ComSignal_S_LED_Intensity already defined
#endif /* #if (defined ComConf_ComSignal_S_LED_Intensity) */

#define ComConf_ComSignal_S_LED_Intensity 2U


/* External Rx Group Signal IDs defines */
/* External Tx Group Signal IDs defines */
/* External Rx Signal Group IDs defines */
/* External Tx Signal Group IDs defines */

/*------------------[symbols without prefix for backward compatibility]-----*/
#if (defined COM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

/* IPDU group ID defines */
/* External Rx IPdus defines */
#if (defined Com_ComIPdu_Radar_Left) /* To prevent double declaration */
#error Com_ComIPdu_Radar_Left already defined
#endif /* #if (defined Com_ComIPdu_Radar_Left) */

#define Com_ComIPdu_Radar_Left ComConf_ComIPdu_ComIPdu_Radar_Left


#if (defined Com_ComIPdu_Radar_Right) /* To prevent double declaration */
#error Com_ComIPdu_Radar_Right already defined
#endif /* #if (defined Com_ComIPdu_Radar_Right) */

#define Com_ComIPdu_Radar_Right ComConf_ComIPdu_ComIPdu_Radar_Right


#if (defined Com_ComIPdu_Speed) /* To prevent double declaration */
#error Com_ComIPdu_Speed already defined
#endif /* #if (defined Com_ComIPdu_Speed) */

#define Com_ComIPdu_Speed ComConf_ComIPdu_ComIPdu_Speed


#if (defined Com_ComIPdu_TurnSignal) /* To prevent double declaration */
#error Com_ComIPdu_TurnSignal already defined
#endif /* #if (defined Com_ComIPdu_TurnSignal) */

#define Com_ComIPdu_TurnSignal ComConf_ComIPdu_ComIPdu_TurnSignal


#if (defined Com_ComIPdu_Steering) /* To prevent double declaration */
#error Com_ComIPdu_Steering already defined
#endif /* #if (defined Com_ComIPdu_Steering) */

#define Com_ComIPdu_Steering ComConf_ComIPdu_ComIPdu_Steering


#if (defined Com_ComIPdu_Gear) /* To prevent double declaration */
#error Com_ComIPdu_Gear already defined
#endif /* #if (defined Com_ComIPdu_Gear) */

#define Com_ComIPdu_Gear ComConf_ComIPdu_ComIPdu_Gear


/* External Tx IPdu defines */
#if (defined Com_ComIPdu_LED_Tx) /* To prevent double declaration */
#error Com_ComIPdu_LED_Tx already defined
#endif /* #if (defined Com_ComIPdu_LED_Tx) */

#define Com_ComIPdu_LED_Tx ComConf_ComIPdu_ComIPdu_LED_Tx


#if (defined Com_ComIPdu_Warning_Tx) /* To prevent double declaration */
#error Com_ComIPdu_Warning_Tx already defined
#endif /* #if (defined Com_ComIPdu_Warning_Tx) */

#define Com_ComIPdu_Warning_Tx ComConf_ComIPdu_ComIPdu_Warning_Tx


/* External Rx Signal IDs (no group signals) defines */
#if (defined Com_S_Radar_Left_Distance) /* To prevent double declaration */
#error Com_S_Radar_Left_Distance already defined
#endif /* #if (defined Com_S_Radar_Left_Distance) */

#define Com_S_Radar_Left_Distance ComConf_ComSignal_S_Radar_Left_Distance


#if (defined Com_S_Radar_Left_ObjectDetected) /* To prevent double declaration */
#error Com_S_Radar_Left_ObjectDetected already defined
#endif /* #if (defined Com_S_Radar_Left_ObjectDetected) */

#define Com_S_Radar_Left_ObjectDetected ComConf_ComSignal_S_Radar_Left_ObjectDetected


#if (defined Com_S_Radar_Right_Distance) /* To prevent double declaration */
#error Com_S_Radar_Right_Distance already defined
#endif /* #if (defined Com_S_Radar_Right_Distance) */

#define Com_S_Radar_Right_Distance ComConf_ComSignal_S_Radar_Right_Distance


#if (defined Com_S_Radar_Right_ObjectDetected) /* To prevent double declaration */
#error Com_S_Radar_Right_ObjectDetected already defined
#endif /* #if (defined Com_S_Radar_Right_ObjectDetected) */

#define Com_S_Radar_Right_ObjectDetected ComConf_ComSignal_S_Radar_Right_ObjectDetected


#if (defined Com_S_Vehicle_Speed) /* To prevent double declaration */
#error Com_S_Vehicle_Speed already defined
#endif /* #if (defined Com_S_Vehicle_Speed) */

#define Com_S_Vehicle_Speed ComConf_ComSignal_S_Vehicle_Speed


#if (defined Com_S_TurnSignal_State) /* To prevent double declaration */
#error Com_S_TurnSignal_State already defined
#endif /* #if (defined Com_S_TurnSignal_State) */

#define Com_S_TurnSignal_State ComConf_ComSignal_S_TurnSignal_State


#if (defined Com_S_Steering_Angle) /* To prevent double declaration */
#error Com_S_Steering_Angle already defined
#endif /* #if (defined Com_S_Steering_Angle) */

#define Com_S_Steering_Angle ComConf_ComSignal_S_Steering_Angle


#if (defined Com_S_Current_Gear) /* To prevent double declaration */
#error Com_S_Current_Gear already defined
#endif /* #if (defined Com_S_Current_Gear) */

#define Com_S_Current_Gear ComConf_ComSignal_S_Current_Gear


/* External Tx Signal IDs (no group signals) defines */
#if (defined Com_S_Warning_State) /* To prevent double declaration */
#error Com_S_Warning_State already defined
#endif /* #if (defined Com_S_Warning_State) */

#define Com_S_Warning_State ComConf_ComSignal_S_Warning_State


#if (defined Com_S_Buzzer_Frequency) /* To prevent double declaration */
#error Com_S_Buzzer_Frequency already defined
#endif /* #if (defined Com_S_Buzzer_Frequency) */

#define Com_S_Buzzer_Frequency ComConf_ComSignal_S_Buzzer_Frequency


#if (defined Com_S_LED_Intensity) /* To prevent double declaration */
#error Com_S_LED_Intensity already defined
#endif /* #if (defined Com_S_LED_Intensity) */

#define Com_S_LED_Intensity ComConf_ComSignal_S_LED_Intensity


/* External Rx Group Signal IDs defines */
/* External Tx Group Signal IDs defines */
/* External Rx Signal Group IDs defines */
/* External Tx Signal Group IDs defines */
#endif /* (defined COM_PROVIDE_LEGACY_SYMBOLIC_NAMES) */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef COM_SYMBOLIC_NAMES_PB_CFG_H  */
/*==================[end of file]===========================================*/
