/*
 * File: BSD_VehicleSignal_SWC.c
 *
 * Code generated for Simulink model 'BSD_VehicleSignal_SWC'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Jun  7 03:07:06 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BSD_VehicleSignal_SWC.h"
#include "Platform_Types.h"
#include "BSD_VehicleSignal_SWC_private.h"

/* Model step function */
void VehicleSignal_Run(void)
{
  float32 u0;
  uint8 tmp;

  /* Outputs for Atomic SubSystem: '<Root>/BSD_VehicleSignal_SWC' */
  /* Gain: '<S1>/Gain' incorporates:
   *  Inport: '<Root>/Vehicle_Speed_Raw'
   */
  u0 = 0.00999999F * (float32)
    Rte_IRead_VehicleSignal_Run_RPort_Vehicle_Speed_Raw_Raw_Vehicle_Speed();

  /* Saturate: '<S1>/Saturation' */
  if (u0 > 300.0F) {
    u0 = 300.0F;
  }

  /* Outport: '<Root>/Vehicle_Speed' incorporates:
   *  Saturate: '<S1>/Saturation'
   */
  Rte_IWrite_VehicleSignal_Run_PPort_Vehicle_Data_Vehicle_Speed(u0);

  /* Gain: '<S1>/Gain1' incorporates:
   *  Inport: '<Root>/Steering_Raw'
   */
  u0 = 0.0999984741F * (float32)
    Rte_IRead_VehicleSignal_Run_RPort_Steering_Raw_Raw_Steering_Angle();

  /* Saturate: '<S1>/Saturation1' */
  if (u0 > 900.0F) {
    u0 = 900.0F;
  } else if (u0 < -900.0F) {
    u0 = -900.0F;
  }

  /* Outport: '<Root>/Steering_Angle' incorporates:
   *  Saturate: '<S1>/Saturation1'
   */
  Rte_IWrite_VehicleSignal_Run_PPort_Vehicle_Data_Steering_Angle(u0);

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Inport: '<Root>/TurnSignal_Raw'
   *  Switch: '<S1>/Switch'
   */
  tmp = Rte_IRead_VehicleSignal_Run_RPort_TurnSignal_Raw_Raw_Turn_Signal();

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  Inport: '<Root>/TurnSignal_Raw'
   *  RelationalOperator: '<S2>/Compare'
   */
  if (tmp > 2) {
    tmp = 0U;
  }

  /* Outport: '<Root>/TurnSignal' incorporates:
   *  Switch: '<S1>/Switch'
   */
  Rte_IWrite_VehicleSignal_Run_PPort_Vehicle_Data_Turn_Signal(tmp);

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Inport: '<Root>/Gear_Raw'
   *  Switch: '<S1>/Switch1'
   */
  tmp = Rte_IRead_VehicleSignal_Run_RPort_Gear_Raw_Raw_Gear_Position();

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/Gear_Raw'
   *  RelationalOperator: '<S3>/Compare'
   */
  if (tmp > 3) {
    tmp = 0U;
  }

  /* Outport: '<Root>/Gear_position' incorporates:
   *  Switch: '<S1>/Switch1'
   */
  Rte_IWrite_VehicleSignal_Run_PPort_Vehicle_Data_Gear_Position(tmp);

  /* End of Outputs for SubSystem: '<Root>/BSD_VehicleSignal_SWC' */
}

/* Model initialize function */
void BSD_VehicleSignal_SWC_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
