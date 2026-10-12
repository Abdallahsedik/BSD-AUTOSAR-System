/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "Warning"
   ARXML schema: "R22-11"
   File generated on: "Sun Oct 11 22:51:52 2026"  */

#ifndef Rte_Warning_h
#define Rte_Warning_h
#include "Rte_Type.h"
#include "Compiler.h"

/* Data access functions */
#define Rte_IRead_RE_Warning_Run_RPort_AlgorithmState_BSD_State_Right Rte_IRead_Warning_RE_Warning_Run_RPort_AlgorithmState_BSD_State_Right

BSDState_T Rte_IRead_RE_Warning_Run_RPort_AlgorithmState_BSD_State_Right(void);

#define Rte_IRead_RE_Warning_Run_RPort_AlgorithmState_BSD_State_Left Rte_IRead_Warning_RE_Warning_Run_RPort_AlgorithmState_BSD_State_Left

BSDState_T Rte_IRead_RE_Warning_Run_RPort_AlgorithmState_BSD_State_Left(void);

#define Rte_IWrite_RE_Warning_Run_PPort_WarningOutput_LED_Right Rte_IWrite_Warning_RE_Warning_Run_PPort_WarningOutput_LED_Right

void Rte_IWrite_RE_Warning_Run_PPort_WarningOutput_LED_Right(LedState_T u);

#define Rte_IWriteRef_RE_Warning_Run_PPort_WarningOutput_LED_Right Rte_IWriteRef_Warning_RE_Warning_Run_PPort_WarningOutput_LED_Right

LedState_T* Rte_IWriteRef_RE_Warning_Run_PPort_WarningOutput_LED_Right(void);

#define Rte_IWrite_RE_Warning_Run_PPort_WarningOutput_LED_Left Rte_IWrite_Warning_RE_Warning_Run_PPort_WarningOutput_LED_Left

void Rte_IWrite_RE_Warning_Run_PPort_WarningOutput_LED_Left(LedState_T u);

#define Rte_IWriteRef_RE_Warning_Run_PPort_WarningOutput_LED_Left Rte_IWriteRef_Warning_RE_Warning_Run_PPort_WarningOutput_LED_Left

LedState_T* Rte_IWriteRef_RE_Warning_Run_PPort_WarningOutput_LED_Left(void);

#define Rte_IWrite_RE_Warning_Run_PPort_WarningOutput_Warning_State_Left Rte_IWrite_Warning_RE_Warning_Run_PPort_WarningOutput_Warning_State_Left

void Rte_IWrite_RE_Warning_Run_PPort_WarningOutput_Warning_State_Left(BSDState_T
  u);

#define Rte_IWriteRef_RE_Warning_Run_PPort_WarningOutput_Warning_State_Left Rte_IWriteRef_Warning_RE_Warning_Run_PPort_WarningOutput_Warning_State_Left

BSDState_T* Rte_IWriteRef_RE_Warning_Run_PPort_WarningOutput_Warning_State_Left
  (void);

#define Rte_IWrite_RE_Warning_Run_PPort_WarningOutput_Warning_State_Right Rte_IWrite_Warning_RE_Warning_Run_PPort_WarningOutput_Warning_State_Right

void Rte_IWrite_RE_Warning_Run_PPort_WarningOutput_Warning_State_Right
  (BSDState_T u);

#define Rte_IWriteRef_RE_Warning_Run_PPort_WarningOutput_Warning_State_Right Rte_IWriteRef_Warning_RE_Warning_Run_PPort_WarningOutput_Warning_State_Right

BSDState_T* Rte_IWriteRef_RE_Warning_Run_PPort_WarningOutput_Warning_State_Right
  (void);

/* Entry point functions */
extern FUNC(void, Warning_CODE) Warning_Init(void);
extern FUNC(void, Warning_CODE) Warning_Step(void);

#endif
