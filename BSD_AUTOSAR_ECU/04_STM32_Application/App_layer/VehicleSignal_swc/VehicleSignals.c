/*
 * File: VehicleSignals.c
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

#include "VehicleSignals.h"
#include "Platform_Types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data */
ARID_DEF_VehicleSignals_T VehicleSignals_ARID_DEF;/* '<S12>/Counter_Prev' */

/* Model step function */
void VehicleSignals_Step(void)
{
  float32 tmp_2;
  sint16 tmp_0;
  uint16 tmp;
  Gear_T rtb_Sw_is_sample_valid;
  SignalStatus_T tmp_1;
  TurnSignal_T rtb_TurnSignal;

  /* Outputs for Atomic SubSystem: '<Root>/RE_VehicleSignals_Run' */
  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   *  Inport generated from: '<Root>/In Bus Element3'
   *  RelationalOperator: '<S11>/Compare'
   *  Switch: '<S4>/Sw_Is_sample_Valid_check'
   */
  tmp = Rte_IRead_VehicleSignals_Step_RPort_Vehicle_Speed_Raw_Vehicle_Speed_Raw();

  /* Switch: '<S12>/switch_counter_check' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant4'
   *  Logic: '<S4>/sw_Speed_Sample_Valid_check'
   *  RelationalOperator: '<S11>/Compare'
   *  Saturate: '<S12>/Saturation'
   *  UnitDelay: '<S12>/Counter_Prev'
   */
  if (tmp <= 30000) {
    /* Saturate: '<S12>/Saturation' incorporates:
     *  Constant: '<S12>/Constant'
     *  Sum: '<S12>/Add'
     *  UnitDelay: '<S12>/Counter_Prev'
     */
    if ((uint8)(VehicleSignals_ARID_DEF.Counter_Prev_DSTATE + 1) <= 3) {
      VehicleSignals_ARID_DEF.Counter_Prev_DSTATE++;
    } else {
      VehicleSignals_ARID_DEF.Counter_Prev_DSTATE = 3U;
    }
  } else {
    VehicleSignals_ARID_DEF.Counter_Prev_DSTATE = 0U;
  }

  /* End of Switch: '<S12>/switch_counter_check' */

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Inport generated from: '<Root>/In Bus Element1'
   *  RelationalOperator: '<S15>/Compare'
   *  Switch: '<S5>/sw_is_sampeld_valed'
   */
  tmp_0 = Rte_IRead_VehicleSignals_Step_RPort_Steering_Raw_Raw_steering();

  /* Switch: '<S16>/switch_counter_check' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S16>/Constant4'
   *  Inport generated from: '<Root>/In Bus Element1'
   *  Logic: '<S5>/Is_STEERING_Valid '
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S15>/Compare'
   *  Saturate: '<S16>/Saturation'
   *  UnitDelay: '<S16>/Counter_Prev'
   */
  if ((tmp_0 >= -9000) && (tmp_0 <= 9000)) {
    /* Saturate: '<S16>/Saturation' incorporates:
     *  Constant: '<S16>/Constant'
     *  Sum: '<S16>/Add'
     *  UnitDelay: '<S16>/Counter_Prev'
     */
    if ((uint8)(VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_a + 1) <= 3) {
      VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_a++;
    } else {
      VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_a = 3U;
    }
  } else {
    VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_a = 0U;
  }

  /* End of Switch: '<S16>/switch_counter_check' */

  /* Switch: '<S8>/switch_counter_check' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant4'
   *  Inport generated from: '<Root>/In Bus Element'
   *  Logic: '<S3>/NOT'
   *  RelationalOperator: '<S7>/Compare'
   *  Saturate: '<S8>/Saturation'
   *  UnitDelay: '<S8>/Counter_Prev'
   */
  if (Rte_IRead_VehicleSignals_Step_RPort_Gear_Raw_Gear_Raw() <= 3) {
    /* Saturate: '<S8>/Saturation' incorporates:
     *  Constant: '<S8>/Constant'
     *  Sum: '<S8>/Add'
     *  UnitDelay: '<S8>/Counter_Prev'
     */
    if ((uint8)(VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_e + 1) <= 3) {
      VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_e++;
    } else {
      VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_e = 3U;
    }
  } else {
    VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_e = 0U;
  }

  /* End of Switch: '<S8>/switch_counter_check' */

  /* Switch: '<S3>/Sw_is_sample_valid' incorporates:
   *  UnitDelay: '<S8>/Counter_Prev'
   */
  if (VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_e != 0) {
    /* MultiPortSwitch: '<S3>/Sw_gear_position_check' incorporates:
     *  Inport generated from: '<Root>/In Bus Element'
     */
    switch (Rte_IRead_VehicleSignals_Step_RPort_Gear_Raw_Gear_Raw()) {
     case 0:
      /* Switch: '<S3>/Sw_is_sample_valid' incorporates:
       *  Constant: '<S3>/GEAR_PARK'
       *  MultiPortSwitch: '<S3>/Sw_gear_position_check'
       */
      rtb_Sw_is_sample_valid = GEAR_PARK;
      break;

     case 1:
      /* Switch: '<S3>/Sw_is_sample_valid' incorporates:
       *  Constant: '<S3>/GEAR_REVERSE'
       *  MultiPortSwitch: '<S3>/Sw_gear_position_check'
       */
      rtb_Sw_is_sample_valid = GEAR_REVERSE;
      break;

     case 2:
      /* Switch: '<S3>/Sw_is_sample_valid' incorporates:
       *  Constant: '<S3>/GEAR_NEUTRAL'
       *  MultiPortSwitch: '<S3>/Sw_gear_position_check'
       */
      rtb_Sw_is_sample_valid = GEAR_NEUTRAL;
      break;

     case 3:
      /* Switch: '<S3>/Sw_is_sample_valid' incorporates:
       *  Constant: '<S3>/GEAR_DRIVE'
       *  MultiPortSwitch: '<S3>/Sw_gear_position_check'
       */
      rtb_Sw_is_sample_valid = GEAR_DRIVE;
      break;

     default:
      /* Switch: '<S3>/Sw_is_sample_valid' incorporates:
       *  Constant: '<S3>/GEAR_PARK'
       *  MultiPortSwitch: '<S3>/Sw_gear_position_check'
       */
      rtb_Sw_is_sample_valid = GEAR_PARK;
      break;
    }

    /* End of MultiPortSwitch: '<S3>/Sw_gear_position_check' */
  } else {
    /* Switch: '<S3>/Sw_is_sample_valid' incorporates:
     *  Constant: '<S3>/STEER_FAILSAFE_DEG'
     */
    rtb_Sw_is_sample_valid = GEAR_PARK;
  }

  /* End of Switch: '<S3>/Sw_is_sample_valid' */

  /* Switch: '<S19>/switch_counter_check' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S19>/Constant4'
   *  Inport generated from: '<Root>/In Bus Element2'
   *  Logic: '<S6>/NOT'
   *  RelationalOperator: '<S18>/Compare'
   *  Saturate: '<S19>/Saturation'
   *  UnitDelay: '<S19>/Counter_Prev'
   */
  if (Rte_IRead_VehicleSignals_Step_RPort_TurnSignal_Raw_Raw_turn_sig() <= 2) {
    /* Saturate: '<S19>/Saturation' incorporates:
     *  Constant: '<S19>/Constant'
     *  Sum: '<S19>/Add'
     *  UnitDelay: '<S19>/Counter_Prev'
     */
    if ((uint8)(VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_k + 1) <= 3) {
      VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_k++;
    } else {
      VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_k = 3U;
    }
  } else {
    VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_k = 0U;
  }

  /* End of Switch: '<S19>/switch_counter_check' */

  /* Switch: '<S6>/sw_is_sampel_valid' incorporates:
   *  UnitDelay: '<S19>/Counter_Prev'
   */
  if (VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_k != 0) {
    /* MultiPortSwitch: '<S6>/Sw_TurnSignal_Pos' incorporates:
     *  Inport generated from: '<Root>/In Bus Element2'
     */
    switch (Rte_IRead_VehicleSignals_Step_RPort_TurnSignal_Raw_Raw_turn_sig()) {
     case 0:
      /* Switch: '<S6>/sw_is_sampel_valid' incorporates:
       *  Constant: '<S6>/TURN_OFF'
       *  MultiPortSwitch: '<S6>/Sw_TurnSignal_Pos'
       */
      rtb_TurnSignal = TURN_OFF;
      break;

     case 1:
      /* Switch: '<S6>/sw_is_sampel_valid' incorporates:
       *  Constant: '<S6>/TURN_LEFT'
       *  MultiPortSwitch: '<S6>/Sw_TurnSignal_Pos'
       */
      rtb_TurnSignal = TURN_LEFT;
      break;

     case 2:
      /* Switch: '<S6>/sw_is_sampel_valid' incorporates:
       *  Constant: '<S6>/TURN_RIGHT'
       *  MultiPortSwitch: '<S6>/Sw_TurnSignal_Pos'
       */
      rtb_TurnSignal = TURN_RIGHT;
      break;

     default:
      /* Switch: '<S6>/sw_is_sampel_valid' incorporates:
       *  Constant: '<S6>/TURN_OFF'
       *  MultiPortSwitch: '<S6>/Sw_TurnSignal_Pos'
       */
      rtb_TurnSignal = TURN_OFF;
      break;
    }

    /* End of MultiPortSwitch: '<S6>/Sw_TurnSignal_Pos' */
  } else {
    /* Switch: '<S6>/sw_is_sampel_valid' incorporates:
     *  Constant: '<S6>/TurnSignal_FAILSAFE_DEG'
     */
    rtb_TurnSignal = TURN_OFF;
  }

  /* End of Switch: '<S6>/sw_is_sampel_valid' */

  /* Switch: '<S16>/switch_recovered_counter_check' incorporates:
   *  Constant: '<S16>/Constant1'
   *  Constant: '<S16>/Constant2'
   *  Constant: '<S17>/Constant'
   *  RelationalOperator: '<S17>/Compare'
   *  UnitDelay: '<S16>/Counter_Prev'
   */
  if (VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_a >= 3) {
    tmp_1 = SIGNAL_OK;
  } else {
    tmp_1 = SIGNAL_FAIL;
  }

  /* Outport generated from: '<Root>/Out Bus Element5' incorporates:
   *  Switch: '<S16>/switch_recovered_counter_check'
   */
  Rte_IWrite_VehicleSignals_Step_PPort_VehicleData_Steering_Status(tmp_1);

  /* Switch: '<S5>/sw_is_sampeld_valed' incorporates:
   *  Constant: '<S5>/STEER_FAILSAFE_DEG'
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Gain: '<S5>/Steering_scale'
   *  UnitDelay: '<S16>/Counter_Prev'
   */
  if (VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_a != 0) {
    tmp_2 = 0.1F * (float32)tmp_0;
  } else {
    tmp_2 = 0.0F;
  }

  /* Outport generated from: '<Root>/Out Bus Element4' incorporates:
   *  Switch: '<S5>/sw_is_sampeld_valed'
   */
  Rte_IWrite_VehicleSignals_Step_PPort_VehicleData_Steering_Angle(tmp_2);

  /* Switch: '<S8>/switch_recovered_counter_check' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S9>/Compare'
   *  UnitDelay: '<S8>/Counter_Prev'
   */
  if (VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_e >= 3) {
    tmp_1 = SIGNAL_OK;
  } else {
    tmp_1 = SIGNAL_FAIL;
  }

  /* Outport generated from: '<Root>/Out Bus Element7' incorporates:
   *  Switch: '<S8>/switch_recovered_counter_check'
   */
  Rte_IWrite_VehicleSignals_Step_PPort_VehicleData_Gear_Status(tmp_1);

  /* End of Outputs for SubSystem: '<Root>/RE_VehicleSignals_Run' */

  /* Outport generated from: '<Root>/Out Bus Element6' */
  Rte_IWrite_VehicleSignals_Step_PPort_VehicleData_Gear(rtb_Sw_is_sample_valid);

  /* Outputs for Atomic SubSystem: '<Root>/RE_VehicleSignals_Run' */
  /* Switch: '<S19>/switch_recovered_counter_check' incorporates:
   *  Constant: '<S19>/Constant1'
   *  Constant: '<S19>/Constant2'
   *  Constant: '<S20>/Constant'
   *  RelationalOperator: '<S20>/Compare'
   *  UnitDelay: '<S19>/Counter_Prev'
   */
  if (VehicleSignals_ARID_DEF.Counter_Prev_DSTATE_k >= 3) {
    tmp_1 = SIGNAL_OK;
  } else {
    tmp_1 = SIGNAL_FAIL;
  }

  /* Outport generated from: '<Root>/Out Bus Element3' incorporates:
   *  Switch: '<S19>/switch_recovered_counter_check'
   */
  Rte_IWrite_VehicleSignals_Step_PPort_VehicleData_TurnSignal_Status(tmp_1);

  /* End of Outputs for SubSystem: '<Root>/RE_VehicleSignals_Run' */

  /* Outport generated from: '<Root>/Out Bus Element2' */
  Rte_IWrite_VehicleSignals_Step_PPort_VehicleData_TurnSignal(rtb_TurnSignal);

  /* Outputs for Atomic SubSystem: '<Root>/RE_VehicleSignals_Run' */
  /* Switch: '<S4>/Sw_Is_sample_Valid_check' incorporates:
   *  Constant: '<S4>/VSPD_FAILSAFE_KMH'
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   *  Gain: '<S4>/Speed_scale'
   *  UnitDelay: '<S12>/Counter_Prev'
   */
  if (VehicleSignals_ARID_DEF.Counter_Prev_DSTATE != 0) {
    tmp_2 = 0.01F * (float32)tmp;
  } else {
    tmp_2 = 0.0F;
  }

  /* Outport generated from: '<Root>/Out Bus Element' incorporates:
   *  Switch: '<S4>/Sw_Is_sample_Valid_check'
   */
  Rte_IWrite_VehicleSignals_Step_PPort_VehicleData_Vehicle_Speed(tmp_2);

  /* Switch: '<S12>/switch_recovered_counter_check' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S12>/Constant2'
   *  Constant: '<S13>/Constant'
   *  RelationalOperator: '<S13>/Compare'
   *  UnitDelay: '<S12>/Counter_Prev'
   */
  if (VehicleSignals_ARID_DEF.Counter_Prev_DSTATE >= 3) {
    tmp_1 = SIGNAL_OK;
  } else {
    tmp_1 = SIGNAL_FAIL;
  }

  /* Outport generated from: '<Root>/Out Bus Element1' incorporates:
   *  Switch: '<S12>/switch_recovered_counter_check'
   */
  Rte_IWrite_VehicleSignals_Step_PPort_VehicleData_Speed_Status(tmp_1);

  /* End of Outputs for SubSystem: '<Root>/RE_VehicleSignals_Run' */
}

/* Model initialize function */
void VehicleSignals_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
