/*
 * File: BSD_System.c
 *
 * Code generated for Simulink model 'BSD_System'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Jun  7 00:49:51 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BSD_System.h"
#include "Platform_Types.h"
#include <math.h>

/* Named constants for Chart: '<S1>/BSD_Algorithm_SWC_Chart' */
#define BSD_System_IN_ALERT            ((uint8)1U)
#define BSD_System_IN_CLEAR            ((uint8)2U)
#define BSD_System_IN_WARNING          ((uint8)3U)

/* PublicStructure Variables for Internal Data */
ARID_DEF_BSD_System_T BSD_System_ARID_DEF;/* '<S1>/BSD_Algorithm_SWC_Chart' */

/* Model step function */
void BSD_Algorithm_Run(void)
{
  float32 tmp;
  float32 tmp_0;
  sint32 Sensor_L_Fault_tmp;
  sint32 Sensor_R_Fault_tmp;
  uint8 rtb_LED_Output;
  uint8 rtb_Warning_Status;

  /* Chart: '<S1>/BSD_Algorithm_SWC_Chart' incorporates:
   *  Inport: '<Root>/Distance_Left'
   *  Inport: '<Root>/Distance_Right'
   *  Inport: '<Root>/Gear_Position'
   *  Inport: '<Root>/Status_Left'
   *  Inport: '<Root>/Status_Right'
   *  Inport: '<Root>/Steering_Angle'
   *  Inport: '<Root>/Turn_Signal'
   *  Inport: '<Root>/Vehicle_Speed'
   */
  if (BSD_System_ARID_DEF.is_active_c3_BSD_System == 0U) {
    BSD_System_ARID_DEF.is_active_c3_BSD_System = 1U;
    BSD_System_ARID_DEF.is_c3_BSD_System = BSD_System_IN_CLEAR;
    rtb_Warning_Status = 0U;
    rtb_LED_Output = 0U;
  } else {
    switch (BSD_System_ARID_DEF.is_c3_BSD_System) {
     case BSD_System_IN_ALERT:
      rtb_Warning_Status = 2U;
      rtb_LED_Output = 1U;
      if ((Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Turn_Signal() == 0) &&
          (fabsf(Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Steering_Angle())
           <= 15.0F)) {
        BSD_System_ARID_DEF.is_c3_BSD_System = BSD_System_IN_WARNING;
        rtb_Warning_Status = 1U;
      } else if ((BSD_System_ARID_DEF.effective_dist >= 3.0F) ||
                 (Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Vehicle_Speed() <=
                  10.0F) ||
                 (Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Gear_Position()
                  != 3)) {
        BSD_System_ARID_DEF.is_c3_BSD_System = BSD_System_IN_CLEAR;
        rtb_Warning_Status = 0U;
        rtb_LED_Output = 0U;
      } else {
        Sensor_L_Fault_tmp =
          Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Status_Left();
        BSD_System_ARID_DEF.Sensor_L_Fault = (uint8)(Sensor_L_Fault_tmp != 0);
        Sensor_R_Fault_tmp =
          Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Status_Right();
        BSD_System_ARID_DEF.Sensor_R_Fault = (uint8)(Sensor_R_Fault_tmp != 0);
        if ((Sensor_L_Fault_tmp != 0) && (Sensor_R_Fault_tmp != 0)) {
          BSD_System_ARID_DEF.effective_dist = 99.0F;
        } else if (Sensor_L_Fault_tmp != 0) {
          BSD_System_ARID_DEF.effective_dist =
            Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Distance_Right();
        } else if (Sensor_R_Fault_tmp != 0) {
          BSD_System_ARID_DEF.effective_dist =
            Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Distance_Left();
        } else {
          BSD_System_ARID_DEF.effective_dist = fminf
            (Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Distance_Left(),
             Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Distance_Right());
        }
      }
      break;

     case BSD_System_IN_CLEAR:
      rtb_Warning_Status = 0U;
      rtb_LED_Output = 0U;
      if ((BSD_System_ARID_DEF.effective_dist < 3.0F) &&
          (Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Vehicle_Speed() > 10.0F)
          && (Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Gear_Position() == 3)
          && (fabsf(Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Steering_Angle
                    ()) < 45.0F)) {
        BSD_System_ARID_DEF.is_c3_BSD_System = BSD_System_IN_WARNING;
        rtb_Warning_Status = 1U;
        rtb_LED_Output = 1U;
      } else {
        Sensor_L_Fault_tmp =
          Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Status_Left();
        BSD_System_ARID_DEF.Sensor_L_Fault = (uint8)(Sensor_L_Fault_tmp != 0);
        Sensor_R_Fault_tmp =
          Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Status_Right();
        BSD_System_ARID_DEF.Sensor_R_Fault = (uint8)(Sensor_R_Fault_tmp != 0);
        if ((Sensor_L_Fault_tmp != 0) && (Sensor_R_Fault_tmp != 0)) {
          BSD_System_ARID_DEF.effective_dist = 99.0F;
        } else if (Sensor_L_Fault_tmp != 0) {
          BSD_System_ARID_DEF.effective_dist =
            Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Distance_Right();
        } else if (Sensor_R_Fault_tmp != 0) {
          BSD_System_ARID_DEF.effective_dist =
            Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Distance_Left();
        } else {
          BSD_System_ARID_DEF.effective_dist = fminf
            (Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Distance_Left(),
             Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Distance_Right());
        }
      }
      break;

     default:
      /* case IN_WARNING: */
      rtb_Warning_Status = 1U;
      rtb_LED_Output = 1U;
      tmp = Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Vehicle_Speed();
      tmp_0 = fabsf(Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Steering_Angle
                    ());
      if ((BSD_System_ARID_DEF.effective_dist >= 3.0F) || (tmp <= 10.0F) ||
          (Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Gear_Position() != 3) ||
          (tmp_0 >= 45.0F)) {
        BSD_System_ARID_DEF.is_c3_BSD_System = BSD_System_IN_CLEAR;
        rtb_Warning_Status = 0U;
        rtb_LED_Output = 0U;
      } else if ((BSD_System_ARID_DEF.effective_dist < 3.0F) && (tmp > 10.0F) &&
                 (Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Turn_Signal() >
                  0) && (tmp_0 > 15.0F)) {
        BSD_System_ARID_DEF.is_c3_BSD_System = BSD_System_IN_ALERT;
        rtb_Warning_Status = 2U;
      } else {
        Sensor_L_Fault_tmp =
          Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Status_Left();
        BSD_System_ARID_DEF.Sensor_L_Fault = (uint8)(Sensor_L_Fault_tmp != 0);
        Sensor_R_Fault_tmp =
          Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Status_Right();
        BSD_System_ARID_DEF.Sensor_R_Fault = (uint8)(Sensor_R_Fault_tmp != 0);
        if ((Sensor_L_Fault_tmp != 0) && (Sensor_R_Fault_tmp != 0)) {
          BSD_System_ARID_DEF.effective_dist = 99.0F;
        } else if (Sensor_L_Fault_tmp != 0) {
          BSD_System_ARID_DEF.effective_dist =
            Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Distance_Right();
        } else if (Sensor_R_Fault_tmp != 0) {
          BSD_System_ARID_DEF.effective_dist =
            Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Distance_Left();
        } else {
          BSD_System_ARID_DEF.effective_dist = fminf
            (Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Distance_Left(),
             Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Distance_Right());
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/BSD_Algorithm_SWC_Chart' */

  /* Outport: '<Root>/PPort_WarningStatus' */
  Rte_IWrite_BSD_Algorithm_Run_PPort_WarningOutput_Warning_Status
    (rtb_Warning_Status);

  /* Outport: '<Root>/PPort_Led_Output' */
  Rte_IWrite_BSD_Algorithm_Run_PPort_WarningOutput_LED_Output(rtb_LED_Output);

  /* Outport: '<Root>/Sensor_L_Fault' */
  Rte_IWrite_BSD_Algorithm_Run_PPort_FaultStatus_Sensor_L_Fault
    (BSD_System_ARID_DEF.Sensor_L_Fault);

  /* Outport: '<Root>/Sensor_R_Fault' */
  Rte_IWrite_BSD_Algorithm_Run_PPort_FaultStatus_Sensor_R_Fault
    (BSD_System_ARID_DEF.Sensor_R_Fault);
}

/* Model initialize function */
void BSD_System_Init(void)
{
  /* SystemInitialize for Chart: '<S1>/BSD_Algorithm_SWC_Chart' */
  BSD_System_ARID_DEF.effective_dist = 99.0F;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
