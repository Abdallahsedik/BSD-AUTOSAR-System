/*
 * File: VehicleSignals.h
 *
 * Code generated for Simulink model 'VehicleSignals'.
 *
 * Model version                  : 1.56
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Oct 11 22:51:27 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef VehicleSignals_h_
#define VehicleSignals_h_
#ifndef VehicleSignals_COMMON_INCLUDES_
#define VehicleSignals_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_VehicleSignals.h"
#endif                                 /* VehicleSignals_COMMON_INCLUDES_ */

#include "VehicleSignals_types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  uint8 Counter_Prev_DSTATE;           /* '<S12>/Counter_Prev' */
  uint8 Counter_Prev_DSTATE_a;         /* '<S16>/Counter_Prev' */
  uint8 Counter_Prev_DSTATE_e;         /* '<S8>/Counter_Prev' */
  uint8 Counter_Prev_DSTATE_k;         /* '<S19>/Counter_Prev' */
} ARID_DEF_VehicleSignals_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_VehicleSignals_T VehicleSignals_ARID_DEF;/* '<S12>/Counter_Prev' */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'VehicleSignals'
 * '<S1>'   : 'VehicleSignals/RE_VehicleSignals_Run'
 * '<S2>'   : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run'
 * '<S3>'   : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Gear'
 * '<S4>'   : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Speed'
 * '<S5>'   : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Steering'
 * '<S6>'   : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Turn_Sig'
 * '<S7>'   : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Gear/Is_Code_Invalid'
 * '<S8>'   : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Gear/hysteresis'
 * '<S9>'   : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Gear/hysteresis/IS_counter_'
 * '<S10>'  : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Speed/Is_Speed_Raw_Below_Min'
 * '<S11>'  : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Speed/Is_Speed_Raw_Exceed_Max'
 * '<S12>'  : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Speed/hysteresis'
 * '<S13>'  : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Speed/hysteresis/IS_counter_Recoverd'
 * '<S14>'  : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Steering/Is_Steering_Below_Min'
 * '<S15>'  : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Steering/Is_Steering_Exceed_Max'
 * '<S16>'  : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Steering/hysteresis'
 * '<S17>'  : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Steering/hysteresis/IS_counter_'
 * '<S18>'  : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Turn_Sig/Is_Code_Invalid'
 * '<S19>'  : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Turn_Sig/hysteresis1'
 * '<S20>'  : 'VehicleSignals/RE_VehicleSignals_Run/RE_VehicleSignals_Run/Turn_Sig/hysteresis1/IS_counter_'
 */
#endif                                 /* VehicleSignals_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
