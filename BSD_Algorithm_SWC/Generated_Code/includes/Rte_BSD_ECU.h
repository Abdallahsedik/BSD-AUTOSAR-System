/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "BSD_ECU"
   ARXML schema: "4.4"
   File generated on: "Sat May 30 09:36:50 2026"  */

#ifndef Rte_BSD_ECU_h
#define Rte_BSD_ECU_h
#include "Rte_Type.h"
#include "Compiler.h"

/* Data access functions */
#define Rte_IRead_BSD_Algorithm_Run_RPort_Distance_Distance Rte_IRead_BSD_ECU_BSD_Algorithm_Run_RPort_Distance_Distance

float32 Rte_IRead_BSD_Algorithm_Run_RPort_Distance_Distance(void);

#define Rte_IRead_BSD_Algorithm_Run_RPort_TurnSignal_TurnSignal Rte_IRead_BSD_ECU_BSD_Algorithm_Run_RPort_TurnSignal_TurnSignal

uint8 Rte_IRead_BSD_Algorithm_Run_RPort_TurnSignal_TurnSignal (void);

#define Rte_IRead_BSD_Algorithm_Run_RPort_VehicleSpeed_VehicleSpeed Rte_IRead_BSD_ECU_BSD_Algorithm_Run_RPort_VehicleSpeed_VehicleSpeed

float32 Rte_IRead_BSD_Algorithm_Run_RPort_VehicleSpeed_VehicleSpeed(void);

#define Rte_IWrite_BSD_Algorithm_Run_PPort_WarningStatus_WarningStatus Rte_IWrite_BSD_ECU_BSD_Algorithm_Run_PPort_WarningStatus_WarningStatus

void Rte_IWrite_BSD_Algorithm_Run_PPort_WarningStatus_WarningStatus(uint8 u);

#define Rte_IWriteRef_BSD_Algorithm_Run_PPort_WarningStatus_WarningStatus Rte_IWriteRef_BSD_ECU_BSD_Algorithm_Run_PPort_WarningStatus_WarningStatus

uint8* Rte_IWriteRef_BSD_Algorithm_Run_PPort_WarningStatus_WarningStatus(void);

#define Rte_IWrite_BSD_Algorithm_Run_PPort_LED_Output_LED_Output Rte_IWrite_BSD_ECU_BSD_Algorithm_Run_PPort_LED_Output_LED_Output

void Rte_IWrite_BSD_Algorithm_Run_PPort_LED_Output_LED_Output(uint8 u);

#define Rte_IWriteRef_BSD_Algorithm_Run_PPort_LED_Output_LED_Output Rte_IWriteRef_BSD_ECU_BSD_Algorithm_Run_PPort_LED_Output_LED_Output

uint8* Rte_IWriteRef_BSD_Algorithm_Run_PPort_LED_Output_LED_Output(void);

/* Entry point functions */
extern FUNC(void, BSD_ECU_CODE) BSD_System_Init(void);
extern FUNC(void, BSD_ECU_CODE) BSD_Algorithm_Run(void);

#endif
