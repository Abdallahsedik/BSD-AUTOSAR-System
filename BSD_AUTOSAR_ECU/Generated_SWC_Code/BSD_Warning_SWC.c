/*
 * File: BSD_Warning_SWC.c
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

#include "BSD_Warning_SWC.h"
#include "Platform_Types.h"

/* Named constants for Chart: '<S1>/BSD_Warning_SWC_Chart' */
#define BSD_Warning_SWC_IN_OUTPUT_ALERT ((uint8)1U)
#define BSD_Warning_SWC_IN_OUTPUT_OFF  ((uint8)2U)
#define BSD_Warning_S_IN_OUTPUT_WARNING ((uint8)3U)

/* PublicStructure Variables for Internal Data */
VAR(ARID_DEF_BSD_Warning_SWC_T, BSD_Warning_SWC_VAR_INIT)
  BSD_Warning_SWC_ARID_DEF;

/* '<S1>/BSD_Warning_SWC_Chart' */

/* Model step function */
FUNC(void, BSD_Warning_SWC_CODE) Warning_Run(void)
{
  sint32 tmp;
  uint8 rtb_Buzzer_Active;
  uint8 rtb_HMI_Display;

  /* Outputs for Atomic SubSystem: '<Root>/BSD_Warning_SWC' */
  /* Chart: '<S1>/BSD_Warning_SWC_Chart' incorporates:
   *  Inport: '<Root>/Warning_Status'
   */
  if (BSD_Warning_SWC_ARID_DEF.is_active_c3_BSD_Warning_SWC == 0U) {
    BSD_Warning_SWC_ARID_DEF.is_active_c3_BSD_Warning_SWC = 1U;
    BSD_Warning_SWC_ARID_DEF.is_c3_BSD_Warning_SWC =
      BSD_Warning_SWC_IN_OUTPUT_OFF;
    BSD_Warning_SWC_ARID_DEF.LED_Left = 0U;
    BSD_Warning_SWC_ARID_DEF.LED_Right = 0U;
    rtb_Buzzer_Active = 0U;
    rtb_HMI_Display = 0U;
  } else {
    switch (BSD_Warning_SWC_ARID_DEF.is_c3_BSD_Warning_SWC) {
     case BSD_Warning_SWC_IN_OUTPUT_ALERT:
      rtb_Buzzer_Active = 1U;
      rtb_HMI_Display = 2U;
      switch (Rte_IRead_Warning_Run_RPort_WarningData_Warning_Status()) {
       case 1:
        BSD_Warning_SWC_ARID_DEF.is_c3_BSD_Warning_SWC =
          BSD_Warning_S_IN_OUTPUT_WARNING;
        BSD_Warning_SWC_ARID_DEF.LED_Left = 1U;
        BSD_Warning_SWC_ARID_DEF.LED_Right = 1U;
        rtb_Buzzer_Active = 0U;
        rtb_HMI_Display = 1U;
        break;

       case 0:
        BSD_Warning_SWC_ARID_DEF.is_c3_BSD_Warning_SWC =
          BSD_Warning_SWC_IN_OUTPUT_OFF;
        BSD_Warning_SWC_ARID_DEF.LED_Left = 0U;
        BSD_Warning_SWC_ARID_DEF.LED_Right = 0U;
        rtb_Buzzer_Active = 0U;
        rtb_HMI_Display = 0U;
        break;

       default:
        tmp = (sint32)(BSD_Warning_SWC_ARID_DEF.Flash_Counter + 1U);
        if (BSD_Warning_SWC_ARID_DEF.Flash_Counter + 1U > 255U) {
          tmp = 255;
        }

        BSD_Warning_SWC_ARID_DEF.Flash_Counter = (uint8)tmp;
        if (BSD_Warning_SWC_ARID_DEF.Flash_Counter >= 5) {
          BSD_Warning_SWC_ARID_DEF.LED_Left = 1U;
          BSD_Warning_SWC_ARID_DEF.LED_Right = 1U;
        }

        if (BSD_Warning_SWC_ARID_DEF.Flash_Counter >= 10) {
          BSD_Warning_SWC_ARID_DEF.LED_Left = 0U;
          BSD_Warning_SWC_ARID_DEF.LED_Right = 0U;
          BSD_Warning_SWC_ARID_DEF.Flash_Counter = 0U;
        }
        break;
      }
      break;

     case BSD_Warning_SWC_IN_OUTPUT_OFF:
      rtb_Buzzer_Active = 0U;
      rtb_HMI_Display = 0U;
      if (Rte_IRead_Warning_Run_RPort_WarningData_Warning_Status() == 1) {
        BSD_Warning_SWC_ARID_DEF.is_c3_BSD_Warning_SWC =
          BSD_Warning_S_IN_OUTPUT_WARNING;
        BSD_Warning_SWC_ARID_DEF.LED_Left = 1U;
        BSD_Warning_SWC_ARID_DEF.LED_Right = 1U;
        rtb_HMI_Display = 1U;
      }
      break;

     default:
      /* case IN_OUTPUT_WARNING: */
      rtb_Buzzer_Active = 0U;
      rtb_HMI_Display = 1U;
      switch (Rte_IRead_Warning_Run_RPort_WarningData_Warning_Status()) {
       case 0:
        BSD_Warning_SWC_ARID_DEF.is_c3_BSD_Warning_SWC =
          BSD_Warning_SWC_IN_OUTPUT_OFF;
        BSD_Warning_SWC_ARID_DEF.LED_Left = 0U;
        BSD_Warning_SWC_ARID_DEF.LED_Right = 0U;
        rtb_HMI_Display = 0U;
        break;

       case 2:
        BSD_Warning_SWC_ARID_DEF.is_c3_BSD_Warning_SWC =
          BSD_Warning_SWC_IN_OUTPUT_ALERT;
        rtb_Buzzer_Active = 1U;
        rtb_HMI_Display = 2U;
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/BSD_Warning_SWC_Chart' */
  /* End of Outputs for SubSystem: '<Root>/BSD_Warning_SWC' */

  /* Outport: '<Root>/LED_Left' */
  Rte_IWrite_Warning_Run_PPort_LED_Control_LED_Left
    (BSD_Warning_SWC_ARID_DEF.LED_Left);

  /* Outport: '<Root>/LED_Right' */
  Rte_IWrite_Warning_Run_PPort_LED_Control_LED_Right
    (BSD_Warning_SWC_ARID_DEF.LED_Right);

  /* Outport: '<Root>/Buzzer_Active' */
  Rte_IWrite_Warning_Run_PPort_LED_Control_Buzzer_Active(rtb_Buzzer_Active);

  /* Outport: '<Root>/HMI_Display' */
  Rte_IWrite_Warning_Run_PPort_HMI_Warning_HMI_Display(rtb_HMI_Display);
}

/* Model initialize function */
FUNC(void, BSD_Warning_SWC_CODE) BSD_Warning_SWC_Step(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
