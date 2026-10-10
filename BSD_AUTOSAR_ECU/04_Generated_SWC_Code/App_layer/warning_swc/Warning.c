/*
 * File: Warning.c
 *
 * Code generated for Simulink model 'Warning'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Oct 11 22:51:46 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Warning.h"
#include "Rte_Type.h"

/* Model step function */
void Warning_Step(void)
{
  BSDState_T rtb_BSD_State_Left;
  BSDState_T rtb_BSD_State_Right;
  LedState_T tmp;

  /* Outputs for Atomic SubSystem: '<Root>/RE_Warning_Run' */
  /* SignalConversion generated from: '<S1>/BSD_State_Left' incorporates:
   *  Inport generated from: '<Root>/Bus Element In2'
   */
  rtb_BSD_State_Left =
    Rte_IRead_RE_Warning_Run_RPort_AlgorithmState_BSD_State_Left();

  /* SignalConversion generated from: '<S1>/BSD_State_Right' incorporates:
   *  Inport generated from: '<Root>/Bus Element In1'
   */
  rtb_BSD_State_Right =
    Rte_IRead_RE_Warning_Run_RPort_AlgorithmState_BSD_State_Right();

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/LED_OFF'
   *  Constant: '<S3>/LED_ON'
   *  RelationalOperator: '<S3>/Relational Operator'
   */
  if (rtb_BSD_State_Right == BSD_WARNING) {
    tmp = LED_ON;
  } else {
    tmp = LED_OFF;
  }

  /* Outport generated from: '<Root>/Bus Element Out1' incorporates:
   *  Switch: '<S3>/Switch'
   */
  Rte_IWrite_RE_Warning_Run_PPort_WarningOutput_LED_Right(tmp);

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/LED_OFF'
   *  Constant: '<S2>/LED_ON'
   *  RelationalOperator: '<S2>/Relational Operator'
   */
  if (rtb_BSD_State_Left == BSD_WARNING) {
    tmp = LED_ON;
  } else {
    tmp = LED_OFF;
  }

  /* Outport generated from: '<Root>/Bus Element Out2' incorporates:
   *  Switch: '<S2>/Switch'
   */
  Rte_IWrite_RE_Warning_Run_PPort_WarningOutput_LED_Left(tmp);

  /* End of Outputs for SubSystem: '<Root>/RE_Warning_Run' */

  /* Outport generated from: '<Root>/Bus Element Out3' */
  Rte_IWrite_RE_Warning_Run_PPort_WarningOutput_Warning_State_Left
    (rtb_BSD_State_Left);

  /* Outport generated from: '<Root>/Bus Element Out4' */
  Rte_IWrite_RE_Warning_Run_PPort_WarningOutput_Warning_State_Right
    (rtb_BSD_State_Right);
}

/* Model initialize function */
void Warning_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
