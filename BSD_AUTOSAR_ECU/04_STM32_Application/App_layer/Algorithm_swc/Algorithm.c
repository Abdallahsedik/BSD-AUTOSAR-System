/*
 * File: Algorithm.c
 *
 * Code generated for Simulink model 'Algorithm'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Oct 12 14:48:46 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Algorithm.h"
#include "Rte_Type.h"

/* Model step function */
void RE_Algorithm_Run(void)
{
  BSDState_T UnitDelay_DSTATE;
  BSDState_T UnitDelay_DSTATE_n;

  /* Outputs for Atomic SubSystem: '<Root>/RE_Algorithm_Run' */
  /* Switch: '<S2>/Sw_Is_suppress' incorporates:
   *  Constant: '<S2>/BSD_CLEAR2'
   *  Constant: '<S3>/BSD_CLEAR2'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S9>/Constant'
   *  Inport generated from: '<Root>/Bus Element In12'
   *  Inport generated from: '<Root>/Bus Element In2'
   *  Inport generated from: '<Root>/Bus Element In10'
   *  Inport generated from: '<Root>/Bus Element In9'
   *  Logic: '<S2>/In_zone_L'
   *  Logic: '<S2>/Is_suppress'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S5>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   *  Switch: '<S2>/Sw_B_In_zone_L'
   *  Switch: '<S3>/Sw_Is_suppress'
   *  UnitDelay: '<S2>/Unit Delay'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  if ((Rte_IRead_RE_Algorithm_Run_RPort_VehicleData_Vehicle_Speed() > 100.0F) ||
      (Rte_IRead_RE_Algorithm_Run_RPort_VehicleData_Speed_Status() == SIGNAL_OK))
  {
    UnitDelay_DSTATE = BSD_WARNING;
    UnitDelay_DSTATE_n = BSD_WARNING;
  } else {
    if ((Rte_IRead_RE_Algorithm_Run_RPort_RadarData_Left_Distance() < 3.0F) &&
        (Rte_IRead_RE_Algorithm_Run_RPort_RadarData_Left_Status() == RADAR_FAIL))
    {
      /* Switch: '<S2>/Sw_B_In_zone_L' incorporates:
       *  Constant: '<S2>/BSD_CLEAR1'
       *  UnitDelay: '<S2>/Unit Delay'
       */
      UnitDelay_DSTATE = BSD_CLEAR;
    } else {
      /* UnitDelay: '<S2>/Unit Delay' incorporates:
       *  Constant: '<S2>/BSD_WARNING1'
       *  Switch: '<S2>/Sw_B_In_zone_L'
       *  Switch: '<S2>/Sw_was_clear'
       */
      UnitDelay_DSTATE = BSD_WARNING;
    }

    /* Switch: '<S3>/Sw_B_In_zone_R' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S16>/Constant'
     *  Inport generated from: '<Root>/Bus Element In11'
     *  Inport generated from: '<Root>/Bus Element In1'
     *  Logic: '<S3>/In_zone_R'
     *  RelationalOperator: '<S11>/Compare'
     *  RelationalOperator: '<S16>/Compare'
     */
    if ((Rte_IRead_RE_Algorithm_Run_RPort_RadarData_Right_Distance() < 3.0F) &&
        (Rte_IRead_RE_Algorithm_Run_RPort_RadarData_Right_Status() == RADAR_FAIL))
    {
      /* UnitDelay: '<S3>/Unit Delay' incorporates:
       *  Constant: '<S3>/BSD_CLEAR1'
       *  Switch: '<S3>/Sw_B_In_zone_R'
       */
      UnitDelay_DSTATE_n = BSD_CLEAR;
    } else {
      /* UnitDelay: '<S3>/Unit Delay' incorporates:
       *  Constant: '<S3>/BSD_WARNING1'
       *  Switch: '<S3>/Sw_B_In_zone_R'
       *  Switch: '<S3>/Sw_was_clear'
       */
      UnitDelay_DSTATE_n = BSD_WARNING;
    }

    /* End of Switch: '<S3>/Sw_B_In_zone_R' */
  }

  /* End of Switch: '<S2>/Sw_Is_suppress' */
  /* End of Outputs for SubSystem: '<Root>/RE_Algorithm_Run' */

  /* Outport generated from: '<Root>/Bus Element Out2' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  Rte_IWrite_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Right
    (UnitDelay_DSTATE_n);

  /* Outport generated from: '<Root>/Bus Element Out3' incorporates:
   *  UnitDelay: '<S2>/Unit Delay'
   */
  Rte_IWrite_RE_Algorithm_Run_PPort_AlgorithmState_BSD_State_Left
    (UnitDelay_DSTATE);
}

/* Model initialize function */
void Algorithm_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
