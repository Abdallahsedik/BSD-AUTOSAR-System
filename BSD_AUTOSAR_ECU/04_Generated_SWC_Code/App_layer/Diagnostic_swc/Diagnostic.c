/*
 * File: Diagnostic.c
 *
 * Code generated for Simulink model 'Diagnostic'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Oct 11 22:50:44 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Diagnostic.h"
#include "Rte_Type.h"
#include "Platform_Types.h"

/* PublicStructure Variables for Internal Data */
ARID_DEF_Diagnostic_T Diagnostic_ARID_DEF;/* '<S3>/Counter_Prev' */

/* Model step function */
void RE_Diagnostic_Run(void)
{
  DiagEventStatus_T tmp;

  /* Outputs for Atomic SubSystem: '<Root>/RE_Diagnostic_Run' */
  /* Switch: '<S3>/switch_counter_check' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S3>/Constant4'
   *  Inport generated from: '<Root>/Bus Element In1'
   *  RelationalOperator: '<S10>/Compare'
   *  Saturate: '<S3>/Saturation'
   *  UnitDelay: '<S3>/Counter_Prev'
   */
  if (Rte_IRead_RE_Diagnostic_Run_RPort_RadarDataLeft_Status() != RADAR_OK) {
    /* Saturate: '<S3>/Saturation' incorporates:
     *  Constant: '<S3>/Constant'
     *  Sum: '<S3>/Add'
     *  UnitDelay: '<S3>/Counter_Prev'
     */
    if ((uint8)(Diagnostic_ARID_DEF.Counter_Prev_DSTATE + 1) <= 1) {
      Diagnostic_ARID_DEF.Counter_Prev_DSTATE++;
    } else {
      Diagnostic_ARID_DEF.Counter_Prev_DSTATE = 1U;
    }
  } else {
    Diagnostic_ARID_DEF.Counter_Prev_DSTATE = 0U;
  }

  /* End of Switch: '<S3>/switch_counter_check' */

  /* Switch: '<S4>/switch_counter_check' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S4>/Constant4'
   *  Inport generated from: '<Root>/Bus Element In2'
   *  RelationalOperator: '<S12>/Compare'
   *  Saturate: '<S4>/Saturation'
   *  UnitDelay: '<S4>/Counter_Prev'
   */
  if (Rte_IRead_RE_Diagnostic_Run_RPort_RadarData_Right_Status() != RADAR_OK) {
    /* Saturate: '<S4>/Saturation' incorporates:
     *  Constant: '<S4>/Constant'
     *  Sum: '<S4>/Add'
     *  UnitDelay: '<S4>/Counter_Prev'
     */
    if ((uint8)(Diagnostic_ARID_DEF.Counter_Prev_DSTATE_g + 1) <= 1) {
      Diagnostic_ARID_DEF.Counter_Prev_DSTATE_g++;
    } else {
      Diagnostic_ARID_DEF.Counter_Prev_DSTATE_g = 1U;
    }
  } else {
    Diagnostic_ARID_DEF.Counter_Prev_DSTATE_g = 0U;
  }

  /* End of Switch: '<S4>/switch_counter_check' */

  /* Switch: '<S5>/switch_counter_check' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S5>/Constant4'
   *  Inport generated from: '<Root>/Bus Element In10'
   *  RelationalOperator: '<S14>/Compare'
   *  Saturate: '<S5>/Saturation'
   *  UnitDelay: '<S5>/Counter_Prev'
   */
  if (Rte_IRead_RE_Diagnostic_Run_RPort_VehicleData_Speed_Status() != SIGNAL_OK)
  {
    /* Saturate: '<S5>/Saturation' incorporates:
     *  Constant: '<S5>/Constant'
     *  Sum: '<S5>/Add'
     *  UnitDelay: '<S5>/Counter_Prev'
     */
    if ((uint8)(Diagnostic_ARID_DEF.Counter_Prev_DSTATE_o + 1) <= 1) {
      Diagnostic_ARID_DEF.Counter_Prev_DSTATE_o++;
    } else {
      Diagnostic_ARID_DEF.Counter_Prev_DSTATE_o = 1U;
    }
  } else {
    Diagnostic_ARID_DEF.Counter_Prev_DSTATE_o = 0U;
  }

  /* End of Switch: '<S5>/switch_counter_check' */

  /* Switch: '<S7>/switch_counter_check' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S7>/Constant4'
   *  Inport generated from: '<Root>/Bus Element In7'
   *  RelationalOperator: '<S18>/Compare'
   *  Saturate: '<S7>/Saturation'
   *  UnitDelay: '<S7>/Counter_Prev'
   */
  if (Rte_IRead_RE_Diagnostic_Run_RPort_VehicleData_TurnSignal_Status() !=
      SIGNAL_OK) {
    /* Saturate: '<S7>/Saturation' incorporates:
     *  Constant: '<S7>/Constant'
     *  Sum: '<S7>/Add'
     *  UnitDelay: '<S7>/Counter_Prev'
     */
    if ((uint8)(Diagnostic_ARID_DEF.Counter_Prev_DSTATE_n + 1) <= 1) {
      Diagnostic_ARID_DEF.Counter_Prev_DSTATE_n++;
    } else {
      Diagnostic_ARID_DEF.Counter_Prev_DSTATE_n = 1U;
    }
  } else {
    Diagnostic_ARID_DEF.Counter_Prev_DSTATE_n = 0U;
  }

  /* End of Switch: '<S7>/switch_counter_check' */

  /* Switch: '<S2>/switch_counter_check' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S8>/Constant'
   *  Inport generated from: '<Root>/Bus Element In5'
   *  RelationalOperator: '<S8>/Compare'
   *  Saturate: '<S2>/Saturation'
   *  UnitDelay: '<S2>/Counter_Prev'
   */
  if (Rte_IRead_RE_Diagnostic_Run_RPort_VehicleData_Gear_Status() != SIGNAL_OK)
  {
    /* Saturate: '<S2>/Saturation' incorporates:
     *  Constant: '<S2>/Constant'
     *  Sum: '<S2>/Add'
     *  UnitDelay: '<S2>/Counter_Prev'
     */
    if ((uint8)(Diagnostic_ARID_DEF.Counter_Prev_DSTATE_j + 1) <= 1) {
      Diagnostic_ARID_DEF.Counter_Prev_DSTATE_j++;
    } else {
      Diagnostic_ARID_DEF.Counter_Prev_DSTATE_j = 1U;
    }
  } else {
    Diagnostic_ARID_DEF.Counter_Prev_DSTATE_j = 0U;
  }

  /* End of Switch: '<S2>/switch_counter_check' */

  /* Switch: '<S6>/switch_counter_check' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S6>/Constant4'
   *  Inport generated from: '<Root>/Bus Element In3'
   *  RelationalOperator: '<S16>/Compare'
   *  Saturate: '<S6>/Saturation'
   *  UnitDelay: '<S6>/Counter_Prev'
   */
  if (Rte_IRead_RE_Diagnostic_Run_RPort_VehicleData_Steering_Status() !=
      SIGNAL_OK) {
    /* Saturate: '<S6>/Saturation' incorporates:
     *  Constant: '<S6>/Constant'
     *  Sum: '<S6>/Add'
     *  UnitDelay: '<S6>/Counter_Prev'
     */
    if ((uint8)(Diagnostic_ARID_DEF.Counter_Prev_DSTATE_f + 1) <= 1) {
      Diagnostic_ARID_DEF.Counter_Prev_DSTATE_f++;
    } else {
      Diagnostic_ARID_DEF.Counter_Prev_DSTATE_f = 1U;
    }
  } else {
    Diagnostic_ARID_DEF.Counter_Prev_DSTATE_f = 0U;
  }

  /* End of Switch: '<S6>/switch_counter_check' */

  /* Switch: '<S6>/Evt_Mux' incorporates:
   *  Constant: '<S17>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   *  RelationalOperator: '<S17>/Compare'
   *  UnitDelay: '<S6>/Counter_Prev'
   */
  if (Diagnostic_ARID_DEF.Counter_Prev_DSTATE_f >= 1) {
    tmp = DIAG_EVT_FAILED;
  } else {
    tmp = DIAG_EVT_PASSED;
  }

  /* Outport generated from: '<Root>/Bus Element Out1' incorporates:
   *  Switch: '<S6>/Evt_Mux'
   */
  Rte_IWrite_RE_Diagnostic_Run_PPort_DiagStatus_Steering_Event(tmp);

  /* Switch: '<S3>/Evt_Mux' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  RelationalOperator: '<S11>/Compare'
   *  UnitDelay: '<S3>/Counter_Prev'
   */
  if (Diagnostic_ARID_DEF.Counter_Prev_DSTATE >= 1) {
    tmp = DIAG_EVT_FAILED;
  } else {
    tmp = DIAG_EVT_PASSED;
  }

  /* Outport generated from: '<Root>/Bus Element Out2' incorporates:
   *  Switch: '<S3>/Evt_Mux'
   */
  Rte_IWrite_RE_Diagnostic_Run_PPort_DiagStatus_Radar_Left_Event(tmp);

  /* Switch: '<S4>/Evt_Mux' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   *  RelationalOperator: '<S13>/Compare'
   *  UnitDelay: '<S4>/Counter_Prev'
   */
  if (Diagnostic_ARID_DEF.Counter_Prev_DSTATE_g >= 1) {
    tmp = DIAG_EVT_FAILED;
  } else {
    tmp = DIAG_EVT_PASSED;
  }

  /* Outport generated from: '<Root>/Bus Element Out3' incorporates:
   *  Switch: '<S4>/Evt_Mux'
   */
  Rte_IWrite_RE_Diagnostic_Run_PPort_DiagStatus_Radar_Right_Event(tmp);

  /* Switch: '<S5>/Evt_Mux' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant2'
   *  RelationalOperator: '<S15>/Compare'
   *  UnitDelay: '<S5>/Counter_Prev'
   */
  if (Diagnostic_ARID_DEF.Counter_Prev_DSTATE_o >= 1) {
    tmp = DIAG_EVT_FAILED;
  } else {
    tmp = DIAG_EVT_PASSED;
  }

  /* Outport generated from: '<Root>/Bus Element Out4' incorporates:
   *  Switch: '<S5>/Evt_Mux'
   */
  Rte_IWrite_RE_Diagnostic_Run_PPort_DiagStatus_Speed_Event(tmp);

  /* Switch: '<S7>/Evt_Mux' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant2'
   *  RelationalOperator: '<S19>/Compare'
   *  UnitDelay: '<S7>/Counter_Prev'
   */
  if (Diagnostic_ARID_DEF.Counter_Prev_DSTATE_n >= 1) {
    tmp = DIAG_EVT_FAILED;
  } else {
    tmp = DIAG_EVT_PASSED;
  }

  /* Outport generated from: '<Root>/Bus Element Out5' incorporates:
   *  Switch: '<S7>/Evt_Mux'
   */
  Rte_IWrite_RE_Diagnostic_Run_PPort_DiagStatus_TurnSignal_Event(tmp);

  /* Switch: '<S2>/Evt_Mux' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S9>/Compare'
   *  UnitDelay: '<S2>/Counter_Prev'
   */
  if (Diagnostic_ARID_DEF.Counter_Prev_DSTATE_j >= 1) {
    tmp = DIAG_EVT_FAILED;
  } else {
    tmp = DIAG_EVT_PASSED;
  }

  /* Outport generated from: '<Root>/Bus Element Out6' incorporates:
   *  Switch: '<S2>/Evt_Mux'
   */
  Rte_IWrite_RE_Diagnostic_Run_PPort_DiagStatus_Gear_Event(tmp);

  /* End of Outputs for SubSystem: '<Root>/RE_Diagnostic_Run' */
}

/* Model initialize function */
void Diagnostic_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
