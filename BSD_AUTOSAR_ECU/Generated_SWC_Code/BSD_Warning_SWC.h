/*
 * File: BSD_Warning_SWC.h
 *
 * Code generated for Simulink model 'BSD_Warning_SWC'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Jun  7 03:46:20 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef BSD_Warning_SWC_h_
#define BSD_Warning_SWC_h_
#ifndef BSD_Warning_SWC_COMMON_INCLUDES_
#define BSD_Warning_SWC_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_BSD_Warning_SWC.h"
#endif                                 /* BSD_Warning_SWC_COMMON_INCLUDES_ */

#include "BSD_Warning_SWC_types.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  uint8 LED_Left;                      /* '<S1>/BSD_Warning_SWC_Chart' */
  uint8 LED_Right;                     /* '<S1>/BSD_Warning_SWC_Chart' */
  uint8 Flash_Counter;                 /* '<S1>/BSD_Warning_SWC_Chart' */
  uint8 is_active_c3_BSD_Warning_SWC;  /* '<S1>/BSD_Warning_SWC_Chart' */
  uint8 is_c3_BSD_Warning_SWC;         /* '<S1>/BSD_Warning_SWC_Chart' */
} ARID_DEF_BSD_Warning_SWC_T;

/* PublicStructure Variables for Internal Data */
extern VAR(ARID_DEF_BSD_Warning_SWC_T, BSD_Warning_SWC_VAR_INIT)
  BSD_Warning_SWC_ARID_DEF;

/* '<S1>/BSD_Warning_SWC_Chart' */

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
 * '<Root>' : 'BSD_Warning_SWC'
 * '<S1>'   : 'BSD_Warning_SWC/BSD_Warning_SWC'
 * '<S2>'   : 'BSD_Warning_SWC/BSD_Warning_SWC/BSD_Warning_SWC_Chart'
 */
#endif                                 /* BSD_Warning_SWC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
