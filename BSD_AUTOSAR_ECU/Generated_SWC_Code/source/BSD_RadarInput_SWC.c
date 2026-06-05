/*
 * File: BSD_RadarInput_SWC.c
 *
 * Code generated for Simulink model 'BSD_RadarInput_SWC'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Jun  4 19:24:54 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (32-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 *    4. MISRA C:2012 guidelines
 *    5. Safety precaution
 *    6. Debugging
 *    7. Traceability
 * Validation result: Passed (32), Warnings (2), Error (0)
 */

#include "BSD_RadarInput_SWC.h"
#include "Platform_Types.h"

/* Model step function */
FUNC(void, BSD_RadarInput_SWC_CODE) BSD_RadarInput_Run(void)
{
  float32 rtb_Gain;
  float32 rtb_Gain_n;
  uint8 rtb_Switch1;
  uint8 rtb_Switch2;

  /* Outputs for Atomic SubSystem: '<Root>/BSD_RadarInput_SWC' */
  /* Gain: '<S2>/Gain' incorporates:
   *  Inport: '<Root>/RPort_RadarLeft_Distance_Raw'
   */
  rtb_Gain = 0.01F * ((float32)
                      Rte_IRead_BSD_RadarInput_Run_RPort_Raw_Distance_Left_Raw_Distance
                      ());

  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Inport: '<Root>/RPort_Raw_Status_Left'
   *  Switch: '<S2>/Switch1'
   */
  rtb_Switch1 = Rte_IRead_BSD_RadarInput_Run_RPort_Raw_Status_Left_Raw_Status();

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S5>/Constant'
   *  Inport: '<Root>/RPort_Raw_Status_Left'
   *  RelationalOperator: '<S5>/Compare'
   */
  if (rtb_Switch1 == 0ULL) {
    /* Switch: '<S2>/Switch1' incorporates:
     *  Constant: '<S4>/Constant'
     *  RelationalOperator: '<S4>/Compare'
     */
    rtb_Switch1 = (uint8)((rtb_Gain > 50.0F) ? ((sint32)1) : ((sint32)0));
  }

  /* Gain: '<S3>/Gain' incorporates:
   *  Inport: '<Root>/RPort_RadarRight_Distance_Raw'
   */
  rtb_Gain_n = 0.01F * ((float32)
                        Rte_IRead_BSD_RadarInput_Run_RPort_Raw_Distance_Right_Raw_Distance
                        ());

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Inport: '<Root>/RPort_Raw_Status_Right'
   *  Switch: '<S3>/Switch2'
   */
  rtb_Switch2 = Rte_IRead_BSD_RadarInput_Run_RPort_Raw_Status_Right_Raw_Status();

  /* Switch: '<S3>/Switch2' incorporates:
   *  Constant: '<S7>/Constant'
   *  Inport: '<Root>/RPort_Raw_Status_Right'
   *  RelationalOperator: '<S7>/Compare'
   */
  if (rtb_Switch2 == 0ULL) {
    /* Switch: '<S3>/Switch2' incorporates:
     *  Constant: '<S6>/Constant'
     *  RelationalOperator: '<S6>/Compare'
     */
    rtb_Switch2 = (uint8)((rtb_Gain_n > 50.0F) ? ((sint32)1) : ((sint32)0));
  }

  /* End of Outputs for SubSystem: '<Root>/BSD_RadarInput_SWC' */

  /* Outport: '<Root>/PPort_RadarData_Distance_Left' */
  Rte_IWrite_BSD_RadarInput_Run_PPort_RadarData_Distance_Left_Distance(rtb_Gain);

  /* Outport: '<Root>/PPort_RadarData_Distance_Right' */
  Rte_IWrite_BSD_RadarInput_Run_PPort_RadarData_Distance_Right_Distance
    (rtb_Gain_n);

  /* Outport: '<Root>/PPort_RadarData_Status_Left' */
  Rte_IWrite_BSD_RadarInput_Run_PPort_RadarData_Status_Left_Status(rtb_Switch1);

  /* Outport: '<Root>/PPort_RadarData_Status_Right' */
  Rte_IWrite_BSD_RadarInput_Run_PPort_RadarData_Status_Right_Status(rtb_Switch2);
}

/* Model initialize function */
FUNC(void, BSD_RadarInput_SWC_CODE) BSD_RadarInput_SWC_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
