/*
 * Rte.c
 * Runtime Environment implementation for STM32
 * This file connects the AUTOSAR COM/PduR stack to the Simulink-generated SWCs.
 */

#include "Std_Types.h"
#include "com/Com.h"
#include "Rte.h"

/* ========================================================================== */
/* 1. INTER-SWC GLOBAL VARIABLES (RTE Sender-Receiver Buffers)                */
/* ========================================================================== */

/* RadarInput -> Algorithm/Diagnostic */
static float32        g_RadarLeft_Distance;
static RadarStatus_T  g_RadarLeft_Status;
static float32        g_RadarRight_Distance;
static RadarStatus_T  g_RadarRight_Status;

/* VehicleSignals -> Algorithm/Diagnostic */
static float32        g_Vehicle_Speed;
static SignalStatus_T g_Speed_Status;
static float32        g_Steering_Angle;
static SignalStatus_T g_Steering_Status;
static Gear_T         g_Gear;
static SignalStatus_T g_Gear_Status;
static TurnSignal_T   g_TurnSignal;
static SignalStatus_T g_TurnSignal_Status;

/* Algorithm -> Warning */
static BSDState_T     g_BSD_State_Left;
static BSDState_T     g_BSD_State_Right;

/* Diagnostic -> DEM (Placeholders) */
static DiagEventStatus_T g_Diag_RadarLeft_Event;
static DiagEventStatus_T g_Diag_RadarRight_Event;
static DiagEventStatus_T g_Diag_Speed_Event;
static DiagEventStatus_T g_Diag_Steering_Event;
static DiagEventStatus_T g_Diag_Gear_Event;
static DiagEventStatus_T g_Diag_TurnSignal_Event;


/* ========================================================================== */
/* 2. RADARINPUT SWC IMPLEMENTATIONS                                          */
/* ========================================================================== */

/* Reads raw data from CAN via COM module */
Std_ReturnType Rte_Read_RadarInput_RPort_RadarLeft_Distance_Raw(uint16* u) {
    return Com_ReceiveSignal(COM_SIG_RADAR_LEFT_DIST, (void*)u);
}
Std_ReturnType Rte_Read_RadarInput_RPort_RadarLeft_Status_Raw(uint8* u) {
    return Com_ReceiveSignal(COM_SIG_RADAR_LEFT_STATUS, (void*)u);
}
Std_ReturnType Rte_Read_RadarInput_RPort_RadarRight_Distance_Raw(uint16* u) {
    return Com_ReceiveSignal(COM_SIG_RADAR_RIGHT_DIST, (void*)u);
}
Std_ReturnType Rte_Read_RadarInput_RPort_RadarRight_Status_Raw(uint8* u) {
    return Com_ReceiveSignal(COM_SIG_RADAR_RIGHT_STATUS, (void*)u);
}

/* Writes processed data to Inter-SWC Buffers */
Std_ReturnType Rte_Write_RadarInput_PPort_RadarData_Left_Distance(float32 u) {
    g_RadarLeft_Distance = u; return E_OK;
}
Std_ReturnType Rte_Write_RadarInput_PPort_RadarData_Left_Status(RadarStatus_T u) {
    g_RadarLeft_Status = u; return E_OK;
}
Std_ReturnType Rte_Write_RadarInput_PPort_RadarData_Right_Distance(float32 u) {
    g_RadarRight_Distance = u; return E_OK;
}
Std_ReturnType Rte_Write_RadarInput_PPort_RadarData_Right_Status(RadarStatus_T u) {
    g_RadarRight_Status = u; return E_OK;
}

/* Invalidate functions (not strictly needed for this architecture, but required to link) */
Std_ReturnType Rte_Invalidate_RadarInput_PPort_RadarData_Left_Status(void) { return E_OK; }
Std_ReturnType Rte_Invalidate_RadarInput_PPort_RadarData_Left_Distance(void) { return E_OK; }
Std_ReturnType Rte_Invalidate_RadarInput_PPort_RadarData_Right_Status(void) { return E_OK; }
Std_ReturnType Rte_Invalidate_RadarInput_PPort_RadarData_Right_Distance(void) { return E_OK; }


/* ========================================================================== */
/* 3. VEHICLESIGNALS SWC IMPLEMENTATIONS                                      */
/* ========================================================================== */

/* Reads raw data from CAN via COM module */
uint8 Rte_IRead_VehicleSignals_VehicleSignals_Step_RPort_Gear_Raw_Gear_Raw(void) {
    uint8 val = 0; Com_ReceiveSignal(COM_SIG_GEAR, (void*)&val); return val;
}
sint16 Rte_IRead_VehicleSignals_VehicleSignals_Step_RPort_Steering_Raw_Raw_steering(void) {
    sint16 val = 0; Com_ReceiveSignal(COM_SIG_STEERING_ANGLE, (void*)&val); return val;
}
uint8 Rte_IRead_VehicleSignals_VehicleSignals_Step_RPort_TurnSignal_Raw_Raw_turn_sig(void) {
    uint8 val = 0; Com_ReceiveSignal(COM_SIG_TURN_SIGNAL, (void*)&val); return val;
}
uint16 Rte_IRead_VehicleSignals_VehicleSignals_Step_RPort_Vehicle_Speed_Raw_Vehicle_Speed_Raw(void) {
    uint16 val = 0; Com_ReceiveSignal(COM_SIG_VEHICLE_SPEED, (void*)&val); return val;
}

/* Writes processed data to Inter-SWC Buffers */
void Rte_IWrite_VehicleSignals_VehicleSignals_Step_PPort_VehicleData_Steering_Status(SignalStatus_T u) {
    g_Steering_Status = u;
}
void Rte_IWrite_VehicleSignals_VehicleSignals_Step_PPort_VehicleData_Steering_Angle(float32 u) {
    g_Steering_Angle = u;
}
void Rte_IWrite_VehicleSignals_VehicleSignals_Step_PPort_VehicleData_Gear_Status(SignalStatus_T u) {
    g_Gear_Status = u;
}
void Rte_IWrite_VehicleSignals_VehicleSignals_Step_PPort_VehicleData_Gear(Gear_T u) {
    g_Gear = u;
}
void Rte_IWrite_VehicleSignals_VehicleSignals_Step_PPort_VehicleData_TurnSignal_Status(SignalStatus_T u) {
    g_TurnSignal_Status = u;
}
void Rte_IWrite_VehicleSignals_VehicleSignals_Step_PPort_VehicleData_TurnSignal(TurnSignal_T u) {
    g_TurnSignal = u;
}
void Rte_IWrite_VehicleSignals_VehicleSignals_Step_PPort_VehicleData_Vehicle_Speed(float32 u) {
    g_Vehicle_Speed = u;
}
void Rte_IWrite_VehicleSignals_VehicleSignals_Step_PPort_VehicleData_Speed_Status(SignalStatus_T u) {
    g_Speed_Status = u;
}


/* ========================================================================== */
/* 4. ALGORITHM SWC IMPLEMENTATIONS                                           */
/* ========================================================================== */

/* Reads processed data from Inter-SWC Buffers */
RadarStatus_T Rte_IRead_Algorithm_RE_Algorithm_Run_RPort_RadarData_Right_Status(void) {
    return g_RadarRight_Status;
}
SignalStatus_T Rte_IRead_Algorithm_RE_Algorithm_Run_RPort_VehicleData_Speed_Status(void) {
    return g_Speed_Status;
}
float32 Rte_IRead_Algorithm_RE_Algorithm_Run_RPort_RadarData_Right_Distance(void) {
    return g_RadarRight_Distance;
}
float32 Rte_IRead_Algorithm_RE_Algorithm_Run_RPort_RadarData_Left_Distance(void) {
    return g_RadarLeft_Distance;
}
RadarStatus_T Rte_IRead_Algorithm_RE_Algorithm_Run_RPort_RadarData_Left_Status(void) {
    return g_RadarLeft_Status;
}
float32 Rte_IRead_Algorithm_RE_Algorithm_Run_RPort_VehicleData_Vehicle_Speed(void) {
    return g_Vehicle_Speed;
}

/* Writes Algorithm state to Inter-SWC Buffers */
void Rte_IWrite_Algorithm_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Right(BSDState_T u) {
    g_BSD_State_Right = u;
}
void Rte_IWrite_Algorithm_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Left(BSDState_T u) {
    g_BSD_State_Left = u;
}


/* ========================================================================== */
/* 5. WARNING SWC IMPLEMENTATIONS                                             */
/* ========================================================================== */

/* Reads Algorithm state from Inter-SWC Buffers */
BSDState_T Rte_IRead_Warning_RE_Warning_Run_RPort_AlgorithmState_BSD_State_Right(void) {
    return g_BSD_State_Right;
}
BSDState_T Rte_IRead_Warning_RE_Warning_Run_RPort_AlgorithmState_BSD_State_Left(void) {
    return g_BSD_State_Left;
}

/* Writes Warning outputs to CAN via COM module */
void Rte_IWrite_Warning_RE_Warning_Run_PPort_WarningOutput_LED_Right(LedState_T u) {
    uint8 val = (uint8)u; Com_SendSignal(COM_SIG_LED_RIGHT, (void*)&val);
}
void Rte_IWrite_Warning_RE_Warning_Run_PPort_WarningOutput_LED_Left(LedState_T u) {
    uint8 val = (uint8)u; Com_SendSignal(COM_SIG_LED_LEFT, (void*)&val);
}
void Rte_IWrite_Warning_RE_Warning_Run_PPort_WarningOutput_Warning_State_Left(BSDState_T u) {
    uint8 val = (uint8)u; Com_SendSignal(COM_SIG_WARNING_STATE_LEFT, (void*)&val);
}
void Rte_IWrite_Warning_RE_Warning_Run_PPort_WarningOutput_Warning_State_Right(BSDState_T u) {
    uint8 val = (uint8)u; Com_SendSignal(COM_SIG_WARNING_STATE_RIGHT, (void*)&val);
}


/* ========================================================================== */
/* 6. DIAGNOSTIC SWC IMPLEMENTATIONS                                          */
/* ========================================================================== */

/* Reads statuses from Inter-SWC Buffers */
RadarStatus_T Rte_IRead_Diagnostic_RE_Diagnostic_Run_RPort_RadarDataLeft_Status(void) {
    return g_RadarLeft_Status;
}
SignalStatus_T Rte_IRead_Diagnostic_RE_Diagnostic_Run_RPort_VehicleData_Speed_Status(void) {
    return g_Speed_Status;
}
RadarStatus_T Rte_IRead_Diagnostic_RE_Diagnostic_Run_RPort_RadarData_Right_Status(void) {
    return g_RadarRight_Status;
}
SignalStatus_T Rte_IRead_Diagnostic_RE_Diagnostic_Run_RPort_VehicleData_Steering_Status(void) {
    return g_Steering_Status;
}
SignalStatus_T Rte_IRead_Diagnostic_RE_Diagnostic_Run_RPort_VehicleData_Gear_Status(void) {
    return g_Gear_Status;
}
SignalStatus_T Rte_IRead_Diagnostic_RE_Diagnostic_Run_RPort_VehicleData_TurnSignal_Status(void) {
    return g_TurnSignal_Status;
}

/* Writes Diagnostic Events to DEM (Placeholder variables for now) */
void Rte_IWrite_Diagnostic_RE_Diagnostic_Run_PPort_DiagStatus_Steering_Event(DiagEventStatus_T u) {
    g_Diag_Steering_Event = u;
}
void Rte_IWrite_Diagnostic_RE_Diagnostic_Run_PPort_DiagStatus_Radar_Left_Event(DiagEventStatus_T u) {
    g_Diag_RadarLeft_Event = u;
}
void Rte_IWrite_Diagnostic_RE_Diagnostic_Run_PPort_DiagStatus_Radar_Right_Event(DiagEventStatus_T u) {
    g_Diag_RadarRight_Event = u;
}
void Rte_IWrite_Diagnostic_RE_Diagnostic_Run_PPort_DiagStatus_Speed_Event(DiagEventStatus_T u) {
    g_Diag_Speed_Event = u;
}
void Rte_IWrite_Diagnostic_RE_Diagnostic_Run_PPort_DiagStatus_TurnSignal_Event(DiagEventStatus_T u) {
    g_Diag_TurnSignal_Event = u;
}
void Rte_IWrite_Diagnostic_RE_Diagnostic_Run_PPort_DiagStatus_Gear_Event(DiagEventStatus_T u) {
    g_Diag_Gear_Event = u;
}
