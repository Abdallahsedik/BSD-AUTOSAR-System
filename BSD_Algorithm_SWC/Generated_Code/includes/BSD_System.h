/*
 * File: BSD_System.h
 *
 * Code generated for Simulink model 'BSD_System'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 30 09:36:33 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef BSD_System_h_
#define BSD_System_h_
#ifndef BSD_System_COMMON_INCLUDES_
#define BSD_System_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_BSD_ECU.h"
#endif                                 /* BSD_System_COMMON_INCLUDES_ */

#include "BSD_System_types.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  uint8 is_active_c3_BSD_System;       /* '<S1>/Chart' */
  uint8 is_c3_BSD_System;              /* '<S1>/Chart' */
} ARID_DEF_BSD_System_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_BSD_System_T BSD_System_ARID_DEF;/* '<S1>/Chart' */

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
 * '<Root>' : 'BSD_System'
 * '<S1>'   : 'BSD_System/BSD_Algorithm_swc'
 * '<S2>'   : 'BSD_System/BSD_Algorithm_swc/Chart'
 */
#endif                                 /* BSD_System_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
