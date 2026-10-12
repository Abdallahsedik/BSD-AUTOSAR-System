/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "Algorithm"
   ARXML schema: "R22-11"
   File generated on: "Mon Oct 12 14:48:54 2026"  */

#ifndef Rte_Algorithm_h
#define Rte_Algorithm_h
#include "Rte_Type.h"
#include "Compiler.h"

/* Data access functions */
#define Rte_IRead_RE_Algorithm_Run_RPort_RadarData_Right_Status Rte_IRead_Algorithm_RE_Algorithm_Run_RPort_RadarData_Right_Status

RadarStatus_T Rte_IRead_RE_Algorithm_Run_RPort_RadarData_Right_Status(void);

#define Rte_IRead_RE_Algorithm_Run_RPort_VehicleData_Speed_Status Rte_IRead_Algorithm_RE_Algorithm_Run_RPort_VehicleData_Speed_Status

SignalStatus_T Rte_IRead_RE_Algorithm_Run_RPort_VehicleData_Speed_Status(void);

#define Rte_IRead_RE_Algorithm_Run_RPort_RadarData_Right_Distance Rte_IRead_Algorithm_RE_Algorithm_Run_RPort_RadarData_Right_Distance

float32 Rte_IRead_RE_Algorithm_Run_RPort_RadarData_Right_Distance(void);

#define Rte_IRead_RE_Algorithm_Run_RPort_RadarData_Left_Distance Rte_IRead_Algorithm_RE_Algorithm_Run_RPort_RadarData_Left_Distance

float32 Rte_IRead_RE_Algorithm_Run_RPort_RadarData_Left_Distance(void);

#define Rte_IRead_RE_Algorithm_Run_RPort_RadarData_Left_Status Rte_IRead_Algorithm_RE_Algorithm_Run_RPort_RadarData_Left_Status

RadarStatus_T Rte_IRead_RE_Algorithm_Run_RPort_RadarData_Left_Status(void);

#define Rte_IRead_RE_Algorithm_Run_RPort_VehicleData_Vehicle_Speed Rte_IRead_Algorithm_RE_Algorithm_Run_RPort_VehicleData_Vehicle_Speed

float32 Rte_IRead_RE_Algorithm_Run_RPort_VehicleData_Vehicle_Speed(void);

#define Rte_IWrite_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Right Rte_IWrite_Algorithm_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Right

void Rte_IWrite_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Right(BSDState_T
  u);

#define Rte_IWriteRef_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Right Rte_IWriteRef_Algorithm_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Right

BSDState_T* Rte_IWriteRef_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Right
  (void);

#define Rte_IWrite_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Left Rte_IWrite_Algorithm_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Left

void Rte_IWrite_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Left(BSDState_T
  u);

#define Rte_IWriteRef_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Left Rte_IWriteRef_Algorithm_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Left

BSDState_T* Rte_IWriteRef_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Left
  (void);

/* Entry point functions */
extern FUNC(void, Algorithm_CODE) Algorithm_Init(void);
extern FUNC(void, Algorithm_CODE) RE_Algorithm_Run(void);

#endif
