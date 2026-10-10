/*
 * File: RadarInput.c
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

#include "RadarInput.h"
#include "Platform_Types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data */
ARID_DEF_RadarInput_T RadarInput_ARID_DEF;/* '<S3>/Counter_Prev' */

/* Model step function */
void RE_RadarInput_Run(void)
{
  float32 rtb_Distance_Out;
  uint16 rtb_TmpSignalConversionAtRPor_h;
  uint16 rtb_TmpSignalConversionAtRPort_;
  uint8 tmpRead;
  uint8 tmpRead_0;
  boolean rtb_Compare_l;
  RadarStatus_T rtb_RadarStatus;

  /* Inport generated from: '<Root>/Status_Raw_Left' */
  (void)Rte_Read_RPort_RadarLeft_Status_Raw(&tmpRead_0);

  /* SignalConversion generated from: '<Root>/Distance_Raw_Right' */
  (void)Rte_Read_RPort_RadarRight_Distance_Raw(&rtb_TmpSignalConversionAtRPort_);

  /* SignalConversion generated from: '<Root>/Distance_Raw_Left' */
  (void)Rte_Read_RPort_RadarLeft_Distance_Raw(&rtb_TmpSignalConversionAtRPor_h);

  /* Outputs for Atomic SubSystem: '<Root>/RE_RadarInput_Run' */
  /* Switch: '<S3>/switch_counter_check' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Logic: '<S3>/Is_sample_valid'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  Saturate: '<S3>/Saturation'
   *  UnitDelay: '<S3>/Counter_Prev'
   */
  if ((rtb_TmpSignalConversionAtRPor_h <= 500) &&
      (rtb_TmpSignalConversionAtRPor_h >= 50) && (tmpRead_0 == 0)) {
    /* Saturate: '<S3>/Saturation' incorporates:
     *  Constant: '<S3>/Constant'
     *  Sum: '<S3>/Add'
     *  UnitDelay: '<S3>/Counter_Prev'
     */
    if ((uint8)(RadarInput_ARID_DEF.Counter_Prev_DSTATE + 1) <= 3) {
      RadarInput_ARID_DEF.Counter_Prev_DSTATE++;
    } else {
      RadarInput_ARID_DEF.Counter_Prev_DSTATE = 3U;
    }
  } else {
    RadarInput_ARID_DEF.Counter_Prev_DSTATE = 0U;
  }

  /* End of Switch: '<S3>/switch_counter_check' */

  /* Switch: '<S3>/switch_counter_check_2' incorporates:
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S5>/Compare'
   *  Switch: '<S3>/switch_recovered_counter_check'
   *  UnitDelay: '<S3>/Counter_Prev'
   */
  if (RadarInput_ARID_DEF.Counter_Prev_DSTATE >= 3) {
    /* Switch: '<S3>/switch_counter_check_2' incorporates:
     *  Gain: '<S3>/Distance_scaled'
     */
    rtb_Distance_Out = 0.01F * (float32)rtb_TmpSignalConversionAtRPor_h;

    /* Switch: '<S3>/switch_recovered_counter_check' incorporates:
     *  Constant: '<S3>/Constant6'
     */
    rtb_RadarStatus = RADAR_OK;
  } else {
    /* Switch: '<S3>/switch_counter_check_2' incorporates:
     *  Constant: '<S3>/RADAR_DIST_FAILSAFE_M'
     */
    rtb_Distance_Out = 10.0F;

    /* Switch: '<S3>/switch_recovered_counter_check' incorporates:
     *  Constant: '<S3>/Constant5'
     */
    rtb_RadarStatus = RADAR_FAIL;
  }

  /* End of Switch: '<S3>/switch_counter_check_2' */
  /* End of Outputs for SubSystem: '<Root>/RE_RadarInput_Run' */

  /* Inport generated from: '<Root>/Status_Raw_Right' */
  (void)Rte_Read_RPort_RadarRight_Status_Raw(&tmpRead);

  /* Outputs for Atomic SubSystem: '<Root>/RE_RadarInput_Run' */
  /* Switch: '<S4>/switch_counter_check' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Logic: '<S4>/Is_sample_valid'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S12>/Compare'
   *  Saturate: '<S4>/Saturation'
   *  UnitDelay: '<S4>/Counter_Prev'
   */
  if ((rtb_TmpSignalConversionAtRPort_ <= 500) &&
      (rtb_TmpSignalConversionAtRPort_ >= 50) && (tmpRead == 0)) {
    /* Saturate: '<S4>/Saturation' incorporates:
     *  Constant: '<S4>/Constant'
     *  Sum: '<S4>/Add'
     *  UnitDelay: '<S4>/Counter_Prev'
     */
    if ((uint8)(RadarInput_ARID_DEF.Counter_Prev_DSTATE_m + 1) <= 3) {
      RadarInput_ARID_DEF.Counter_Prev_DSTATE_m++;
    } else {
      RadarInput_ARID_DEF.Counter_Prev_DSTATE_m = 3U;
    }
  } else {
    RadarInput_ARID_DEF.Counter_Prev_DSTATE_m = 0U;
  }

  /* End of Switch: '<S4>/switch_counter_check' */

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   *  UnitDelay: '<S4>/Counter_Prev'
   */
  rtb_Compare_l = (RadarInput_ARID_DEF.Counter_Prev_DSTATE_m >= 3);

  /* End of Outputs for SubSystem: '<Root>/RE_RadarInput_Run' */

  /* Outport generated from: '<Root>/Status_Left0' */
  (void)Rte_Write_PPort_RadarData_Left_Status(rtb_RadarStatus);

  /* Outport generated from: '<Root>/Distance_Right' */
  (void)Rte_Write_PPort_RadarData_Left_Distance(rtb_Distance_Out);

  /* Outputs for Atomic SubSystem: '<Root>/RE_RadarInput_Run' */
  /* Switch: '<S4>/switch_recovered_counter_check' incorporates:
   *  Constant: '<S4>/Constant5'
   *  Constant: '<S4>/Constant6'
   */
  if (rtb_Compare_l) {
    rtb_RadarStatus = RADAR_OK;
  } else {
    rtb_RadarStatus = RADAR_FAIL;
  }

  /* Outport generated from: '<Root>/Status_Right' incorporates:
   *  Switch: '<S4>/switch_recovered_counter_check'
   */
  (void)Rte_Write_PPort_RadarData_Right_Status(rtb_RadarStatus);

  /* Switch: '<S4>/switch_counter_check_2' incorporates:
   *  Constant: '<S4>/RADAR_DIST_FAILSAFE_M'
   *  Gain: '<S4>/Distance_scaled'
   */
  if (rtb_Compare_l) {
    rtb_Distance_Out = 0.01F * (float32)rtb_TmpSignalConversionAtRPort_;
  } else {
    rtb_Distance_Out = 10.0F;
  }

  /* Outport generated from: '<Root>/Distance_Left' incorporates:
   *  Switch: '<S4>/switch_counter_check_2'
   */
  (void)Rte_Write_PPort_RadarData_Right_Distance(rtb_Distance_Out);

  /* End of Outputs for SubSystem: '<Root>/RE_RadarInput_Run' */
}

/* Model initialize function */
void RadarInput_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
