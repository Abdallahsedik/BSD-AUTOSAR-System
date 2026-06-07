/*
 * File: BSD_Diagnostic_SWC.h
 *
 * Code generated for Simulink model 'BSD_Diagnostic_SWC'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Jun  7 05:19:55 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef BSD_Diagnostic_SWC_h_
#define BSD_Diagnostic_SWC_h_
#ifndef BSD_Diagnostic_SWC_COMMON_INCLUDES_
#define BSD_Diagnostic_SWC_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_BSD_Diagnostic_SWC.h"
#endif                                 /* BSD_Diagnostic_SWC_COMMON_INCLUDES_ */

#include "BSD_Diagnostic_SWC_types.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  uint8 DTC_Active_Count;              /* '<S1>/BSD_Diagnostic_SWC_Chart' */
  uint8 Counter_L;                     /* '<S1>/BSD_Diagnostic_SWC_Chart' */
  uint8 Counter_R;                     /* '<S1>/BSD_Diagnostic_SWC_Chart' */
  uint8 Counter_Speed;                 /* '<S1>/BSD_Diagnostic_SWC_Chart' */
  uint8 DTC_L_Active;                  /* '<S1>/BSD_Diagnostic_SWC_Chart' */
  uint8 DTC_R_Active;                  /* '<S1>/BSD_Diagnostic_SWC_Chart' */
  uint8 DTC_Speed_Active;              /* '<S1>/BSD_Diagnostic_SWC_Chart' */
  uint8 is_active_c3_BSD_Diagnostic_SWC;/* '<S1>/BSD_Diagnostic_SWC_Chart' */
  uint8 is_c3_BSD_Diagnostic_SWC;      /* '<S1>/BSD_Diagnostic_SWC_Chart' */
} ARID_DEF_BSD_Diagnostic_SWC_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_BSD_Diagnostic_SWC_T BSD_Diagnostic_SWC_ARID_DEF;/* '<S1>/BSD_Diagnostic_SWC_Chart' */

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
 * '<Root>' : 'BSD_Diagnostic_SWC'
 * '<S1>'   : 'BSD_Diagnostic_SWC/BSD_Diagnostic_SWC'
 * '<S2>'   : 'BSD_Diagnostic_SWC/BSD_Diagnostic_SWC/BSD_Diagnostic_SWC_Chart'
 */
#endif                                 /* BSD_Diagnostic_SWC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
