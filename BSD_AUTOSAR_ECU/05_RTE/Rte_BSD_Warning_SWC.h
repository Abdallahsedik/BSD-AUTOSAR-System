/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "BSD_Warning_SWC"
   ARXML schema: "4.4"
   File generated on: "Sun Jun 07 03:46:27 2026"  */

#ifndef Rte_BSD_Warning_SWC_h
#define Rte_BSD_Warning_SWC_h
#include "Rte_Type.h"
#include "Compiler.h"

/* Data access functions */
#define Rte_IRead_Warning_Run_RPort_WarningData_Warning_Status Rte_IRead_BSD_Warning_SWC_Warning_Run_RPort_WarningData_Warning_Status

uint8 Rte_IRead_Warning_Run_RPort_WarningData_Warning_Status(void);

#define Rte_IWrite_Warning_Run_PPort_LED_Control_LED_Left Rte_IWrite_BSD_Warning_SWC_Warning_Run_PPort_LED_Control_LED_Left

void Rte_IWrite_Warning_Run_PPort_LED_Control_LED_Left(uint8 u);

#define Rte_IWriteRef_Warning_Run_PPort_LED_Control_LED_Left Rte_IWriteRef_BSD_Warning_SWC_Warning_Run_PPort_LED_Control_LED_Left

uint8* Rte_IWriteRef_Warning_Run_PPort_LED_Control_LED_Left(void);

#define Rte_IWrite_Warning_Run_PPort_LED_Control_LED_Right Rte_IWrite_BSD_Warning_SWC_Warning_Run_PPort_LED_Control_LED_Right

void Rte_IWrite_Warning_Run_PPort_LED_Control_LED_Right(uint8 u);

#define Rte_IWriteRef_Warning_Run_PPort_LED_Control_LED_Right Rte_IWriteRef_BSD_Warning_SWC_Warning_Run_PPort_LED_Control_LED_Right

uint8* Rte_IWriteRef_Warning_Run_PPort_LED_Control_LED_Right(void);

#define Rte_IWrite_Warning_Run_PPort_LED_Control_Buzzer_Active Rte_IWrite_BSD_Warning_SWC_Warning_Run_PPort_LED_Control_Buzzer_Active

void Rte_IWrite_Warning_Run_PPort_LED_Control_Buzzer_Active(uint8 u);

#define Rte_IWriteRef_Warning_Run_PPort_LED_Control_Buzzer_Active Rte_IWriteRef_BSD_Warning_SWC_Warning_Run_PPort_LED_Control_Buzzer_Active

uint8* Rte_IWriteRef_Warning_Run_PPort_LED_Control_Buzzer_Active(void);

#define Rte_IWrite_Warning_Run_PPort_HMI_Warning_HMI_Display Rte_IWrite_BSD_Warning_SWC_Warning_Run_PPort_HMI_Warning_HMI_Display

void Rte_IWrite_Warning_Run_PPort_HMI_Warning_HMI_Display(uint8 u);

#define Rte_IWriteRef_Warning_Run_PPort_HMI_Warning_HMI_Display Rte_IWriteRef_BSD_Warning_SWC_Warning_Run_PPort_HMI_Warning_HMI_Display

uint8* Rte_IWriteRef_Warning_Run_PPort_HMI_Warning_HMI_Display(void);

/* Entry point functions */
extern FUNC(void, BSD_Warning_SWC_CODE) BSD_Warning_SWC_Step(void);
extern FUNC(void, BSD_Warning_SWC_CODE) Warning_Run(void);

#endif
