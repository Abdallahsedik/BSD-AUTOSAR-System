/*
 * File: BSD_System.c
 *
 * Code generated for Simulink model 'BSD_System'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 30 04:40:43 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BSD_System.h"
#include "Platform_Types.h"

/* Named constants for Chart: '<S1>/Chart' */
#define BSD_System_IN_ALERT            ((uint8)1U)
#define BSD_System_IN_CLEAR            ((uint8)2U)
#define BSD_System_IN_WARNING          ((uint8)3U)

/* PublicStructure Variables for Internal Data */
ARID_DEF_BSD_System_T BSD_System_ARID_DEF;/* '<S1>/Chart' */

/* Model step function */
void BSD_Algorithm_Run(void)
{
  float32 tmp;
  uint8 rtb_LED_Output;
  uint8 rtb_WarningStatus;

  /* Chart: '<S1>/Chart' incorporates:
   *  Inport: '<Root>/RPort_Distance'
   *  Inport: '<Root>/RPort_TurnSignal'
   *  Inport: '<Root>/RPort_VehicleSpeed'
   */
  if (BSD_System_ARID_DEF.is_active_c3_BSD_System == 0U) {
    BSD_System_ARID_DEF.is_active_c3_BSD_System = 1U;
    BSD_System_ARID_DEF.is_c3_BSD_System = BSD_System_IN_CLEAR;
    rtb_WarningStatus = 0U;
    rtb_LED_Output = 0U;
  } else {
    switch (BSD_System_ARID_DEF.is_c3_BSD_System) {
     case BSD_System_IN_ALERT:
      rtb_WarningStatus = 2U;
      rtb_LED_Output = 1U;
      if (Rte_IRead_BSD_Algorithm_Run_RPort_TurnSignal_TurnSignal () == 0) {
        BSD_System_ARID_DEF.is_c3_BSD_System = BSD_System_IN_WARNING;
        rtb_WarningStatus = 1U;
      } else if (Rte_IRead_BSD_Algorithm_Run_RPort_Distance_Distance() >= 3.2) {
        BSD_System_ARID_DEF.is_c3_BSD_System = BSD_System_IN_CLEAR;
        rtb_WarningStatus = 0U;
        rtb_LED_Output = 0U;
      }
      break;

     case BSD_System_IN_CLEAR:
      rtb_WarningStatus = 0U;
      rtb_LED_Output = 0U;
      if ((Rte_IRead_BSD_Algorithm_Run_RPort_Distance_Distance() < 3.0F) &&
          (Rte_IRead_BSD_Algorithm_Run_RPort_VehicleSpeed_VehicleSpeed() > 10.0F))
      {
        BSD_System_ARID_DEF.is_c3_BSD_System = BSD_System_IN_WARNING;
        rtb_WarningStatus = 1U;
        rtb_LED_Output = 1U;
      }
      break;

     default:
      /* case IN_WARNING: */
      rtb_WarningStatus = 1U;
      rtb_LED_Output = 1U;
      tmp = Rte_IRead_BSD_Algorithm_Run_RPort_Distance_Distance();
      if (tmp >= 3.2) {
        BSD_System_ARID_DEF.is_c3_BSD_System = BSD_System_IN_CLEAR;
        rtb_WarningStatus = 0U;
        rtb_LED_Output = 0U;
      } else if ((tmp < 3.0F) &&
                 (Rte_IRead_BSD_Algorithm_Run_RPort_TurnSignal_TurnSignal () > 0))
      {
        BSD_System_ARID_DEF.is_c3_BSD_System = BSD_System_IN_ALERT;
        rtb_WarningStatus = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* Outport: '<Root>/PPort_WarningStatus' */
  Rte_IWrite_BSD_Algorithm_Run_PPort_WarningStatus_WarningStatus
    (rtb_WarningStatus);

  /* Outport: '<Root>/PPort_Led_Output' */
  Rte_IWrite_BSD_Algorithm_Run_PPort_LED_Output_LED_Output(rtb_LED_Output);
}

/* Model initialize function */
void BSD_System_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
