/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "RadarInput"
   ARXML schema: "R22-11"
   File generated on: "Sun Oct 11 22:55:26 2026"  */

#ifndef Rte_RadarInput_h
#define Rte_RadarInput_h
#include "Rte_Type.h"
#include "Compiler.h"

/* Data access functions */
#define Rte_Read_RPort_RadarLeft_Distance_Raw Rte_Read_RadarInput_RPort_RadarLeft_Distance_Raw

Std_ReturnType Rte_Read_RPort_RadarLeft_Distance_Raw(uint16* u);

#define Rte_Read_RPort_RadarRight_Distance_Raw Rte_Read_RadarInput_RPort_RadarRight_Distance_Raw

Std_ReturnType Rte_Read_RPort_RadarRight_Distance_Raw(uint16* u);

#define Rte_Read_RPort_RadarLeft_Status_Raw Rte_Read_RadarInput_RPort_RadarLeft_Status_Raw

Std_ReturnType Rte_Read_RPort_RadarLeft_Status_Raw(uint8* u);

#define Rte_Read_RPort_RadarRight_Status_Raw Rte_Read_RadarInput_RPort_RadarRight_Status_Raw

Std_ReturnType Rte_Read_RPort_RadarRight_Status_Raw(uint8* u);

#define Rte_Write_PPort_RadarData_Left_Status Rte_Write_RadarInput_PPort_RadarData_Left_Status

Std_ReturnType Rte_Write_PPort_RadarData_Left_Status(RadarStatus_T u);

#define Rte_Invalidate_PPort_RadarData_Left_Status Rte_Invalidate_RadarInput_PPort_RadarData_Left_Status

Std_ReturnType Rte_Invalidate_PPort_RadarData_Left_Status(void);

#define Rte_Write_PPort_RadarData_Left_Distance Rte_Write_RadarInput_PPort_RadarData_Left_Distance

Std_ReturnType Rte_Write_PPort_RadarData_Left_Distance(float32 u);

#define Rte_Invalidate_PPort_RadarData_Left_Distance Rte_Invalidate_RadarInput_PPort_RadarData_Left_Distance

Std_ReturnType Rte_Invalidate_PPort_RadarData_Left_Distance(void);

#define Rte_Write_PPort_RadarData_Right_Status Rte_Write_RadarInput_PPort_RadarData_Right_Status

Std_ReturnType Rte_Write_PPort_RadarData_Right_Status(RadarStatus_T u);

#define Rte_Invalidate_PPort_RadarData_Right_Status Rte_Invalidate_RadarInput_PPort_RadarData_Right_Status

Std_ReturnType Rte_Invalidate_PPort_RadarData_Right_Status(void);

#define Rte_Write_PPort_RadarData_Right_Distance Rte_Write_RadarInput_PPort_RadarData_Right_Distance

Std_ReturnType Rte_Write_PPort_RadarData_Right_Distance(float32 u);

#define Rte_Invalidate_PPort_RadarData_Right_Distance Rte_Invalidate_RadarInput_PPort_RadarData_Right_Distance

Std_ReturnType Rte_Invalidate_PPort_RadarData_Right_Distance(void);

/* Entry point functions */
extern FUNC(void, RadarInput_CODE) RadarInput_Init(void);
extern FUNC(void, RadarInput_CODE) RE_RadarInput_Run(void);

#endif
