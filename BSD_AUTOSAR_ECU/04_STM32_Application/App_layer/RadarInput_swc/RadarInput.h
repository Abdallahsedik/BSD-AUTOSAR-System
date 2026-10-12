/*
 * File: RadarInput.h
 *
 * Code generated for Simulink model 'RadarInput'.
 *
 * Model version                  : 1.78
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Oct 11 22:51:06 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RadarInput_h_
#define RadarInput_h_
#ifndef RadarInput_COMMON_INCLUDES_
#define RadarInput_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_RadarInput.h"
#endif                                 /* RadarInput_COMMON_INCLUDES_ */

#include "RadarInput_types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  uint8 Counter_Prev_DSTATE;           /* '<S3>/Counter_Prev' */
  uint8 Counter_Prev_DSTATE_m;         /* '<S4>/Counter_Prev' */
} ARID_DEF_RadarInput_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_RadarInput_T RadarInput_ARID_DEF;/* '<S3>/Counter_Prev' */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Constant' : Unused code path elimination
 */

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
 * '<Root>' : 'RadarInput'
 * '<S1>'   : 'RadarInput/RE_RadarInput_Init'
 * '<S2>'   : 'RadarInput/RE_RadarInput_Run'
 * '<S3>'   : 'RadarInput/RE_RadarInput_Run/Process_Left_Radar'
 * '<S4>'   : 'RadarInput/RE_RadarInput_Run/Process_Right_Radar'
 * '<S5>'   : 'RadarInput/RE_RadarInput_Run/Process_Left_Radar/IS_counter_'
 * '<S6>'   : 'RadarInput/RE_RadarInput_Run/Process_Left_Radar/Is_Radar_Raw_Below_Min'
 * '<S7>'   : 'RadarInput/RE_RadarInput_Run/Process_Left_Radar/Is_Radar_Raw_Exceed_Max'
 * '<S8>'   : 'RadarInput/RE_RadarInput_Run/Process_Left_Radar/Is_Radar_Status_Code_Valid'
 * '<S9>'   : 'RadarInput/RE_RadarInput_Run/Process_Right_Radar/IS_counter_'
 * '<S10>'  : 'RadarInput/RE_RadarInput_Run/Process_Right_Radar/Is_Radar_Raw_Below_Min'
 * '<S11>'  : 'RadarInput/RE_RadarInput_Run/Process_Right_Radar/Is_Radar_Raw_Exceed_Max'
 * '<S12>'  : 'RadarInput/RE_RadarInput_Run/Process_Right_Radar/Is_Radar_Status_Code_Valid'
 */
#endif                                 /* RadarInput_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
