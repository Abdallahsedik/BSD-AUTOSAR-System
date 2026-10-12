/*
 * File: Diagnostic.h
 *
 * Code generated for Simulink model 'Diagnostic'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Oct 11 22:50:44 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Diagnostic_h_
#define Diagnostic_h_
#ifndef Diagnostic_COMMON_INCLUDES_
#define Diagnostic_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_Diagnostic.h"
#endif                                 /* Diagnostic_COMMON_INCLUDES_ */

#include "Diagnostic_types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  uint8 Counter_Prev_DSTATE;           /* '<S3>/Counter_Prev' */
  uint8 Counter_Prev_DSTATE_g;         /* '<S4>/Counter_Prev' */
  uint8 Counter_Prev_DSTATE_o;         /* '<S5>/Counter_Prev' */
  uint8 Counter_Prev_DSTATE_n;         /* '<S7>/Counter_Prev' */
  uint8 Counter_Prev_DSTATE_j;         /* '<S2>/Counter_Prev' */
  uint8 Counter_Prev_DSTATE_f;         /* '<S6>/Counter_Prev' */
} ARID_DEF_Diagnostic_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_Diagnostic_T Diagnostic_ARID_DEF;/* '<S3>/Counter_Prev' */

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
 * '<Root>' : 'Diagnostic'
 * '<S1>'   : 'Diagnostic/RE_Diagnostic_Run'
 * '<S2>'   : 'Diagnostic/RE_Diagnostic_Run/Debounce_Gear'
 * '<S3>'   : 'Diagnostic/RE_Diagnostic_Run/Debounce_RadarL'
 * '<S4>'   : 'Diagnostic/RE_Diagnostic_Run/Debounce_RadarLR'
 * '<S5>'   : 'Diagnostic/RE_Diagnostic_Run/Debounce_Speed'
 * '<S6>'   : 'Diagnostic/RE_Diagnostic_Run/Debounce_Steering'
 * '<S7>'   : 'Diagnostic/RE_Diagnostic_Run/Debounce_TurnSignal'
 * '<S8>'   : 'Diagnostic/RE_Diagnostic_Run/Debounce_Gear/Compare To Constant'
 * '<S9>'   : 'Diagnostic/RE_Diagnostic_Run/Debounce_Gear/IS_Reached'
 * '<S10>'  : 'Diagnostic/RE_Diagnostic_Run/Debounce_RadarL/Compare To Constant'
 * '<S11>'  : 'Diagnostic/RE_Diagnostic_Run/Debounce_RadarL/IS_Reached'
 * '<S12>'  : 'Diagnostic/RE_Diagnostic_Run/Debounce_RadarLR/Compare To Constant'
 * '<S13>'  : 'Diagnostic/RE_Diagnostic_Run/Debounce_RadarLR/IS_Reached'
 * '<S14>'  : 'Diagnostic/RE_Diagnostic_Run/Debounce_Speed/Compare To Constant'
 * '<S15>'  : 'Diagnostic/RE_Diagnostic_Run/Debounce_Speed/IS_Reached'
 * '<S16>'  : 'Diagnostic/RE_Diagnostic_Run/Debounce_Steering/Compare To Constant'
 * '<S17>'  : 'Diagnostic/RE_Diagnostic_Run/Debounce_Steering/IS_Reached'
 * '<S18>'  : 'Diagnostic/RE_Diagnostic_Run/Debounce_TurnSignal/Compare To Constant'
 * '<S19>'  : 'Diagnostic/RE_Diagnostic_Run/Debounce_TurnSignal/IS_Reached'
 */
#endif                                 /* Diagnostic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
