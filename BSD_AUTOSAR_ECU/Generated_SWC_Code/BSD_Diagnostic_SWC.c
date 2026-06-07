/*
 * File: BSD_Diagnostic_SWC.c
 *
 * Code generated for Simulink model 'BSD_Diagnostic_SWC'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Jun  7 05:19:55 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BSD_Diagnostic_SWC.h"
#include "Platform_Types.h"

/* Named constants for Chart: '<S1>/BSD_Diagnostic_SWC_Chart' */
#define BSD_Diagnost_IN_SYSTEM_DEGRADED ((uint8)1U)
#define BSD_Diagnostic_SWC_IN_SYSTEM_OK ((uint8)3U)
#define BSD_Diagnostic_S_IN_SYSTEM_FAIL ((uint8)2U)

/* PublicStructure Variables for Internal Data */
ARID_DEF_BSD_Diagnostic_SWC_T BSD_Diagnostic_SWC_ARID_DEF;/* '<S1>/BSD_Diagnostic_SWC_Chart' */

/* Model step function */
void Diagnostic_Run(void)
{
  sint32 tmp;
  sint32 tmp_0;
  sint32 tmp_1;
  uint8 BSD_Available;
  uint8 rtb_System_Health;

  /* Chart: '<S1>/BSD_Diagnostic_SWC_Chart' incorporates:
   *  Inport: '<Root>/Gear_Position'
   *  Inport: '<Root>/Status_Left'
   *  Inport: '<Root>/Status_Right'
   *  Inport: '<Root>/Vehicle_Speed'
   *  Inport: '<Root>/Warning_Status'
   */
  if (BSD_Diagnostic_SWC_ARID_DEF.is_active_c3_BSD_Diagnostic_SWC == 0U) {
    BSD_Diagnostic_SWC_ARID_DEF.is_active_c3_BSD_Diagnostic_SWC = 1U;
    BSD_Diagnostic_SWC_ARID_DEF.is_c3_BSD_Diagnostic_SWC =
      BSD_Diagnostic_SWC_IN_SYSTEM_OK;
    rtb_System_Health = 0U;
    BSD_Available = 1U;
  } else {
    switch (BSD_Diagnostic_SWC_ARID_DEF.is_c3_BSD_Diagnostic_SWC) {
     case BSD_Diagnost_IN_SYSTEM_DEGRADED:
      rtb_System_Health = 1U;
      BSD_Available = 1U;
      if (BSD_Diagnostic_SWC_ARID_DEF.DTC_Active_Count == 0) {
        BSD_Diagnostic_SWC_ARID_DEF.is_c3_BSD_Diagnostic_SWC =
          BSD_Diagnostic_SWC_IN_SYSTEM_OK;
        rtb_System_Health = 0U;
      } else if ((BSD_Diagnostic_SWC_ARID_DEF.DTC_L_Active == 1) &&
                 (BSD_Diagnostic_SWC_ARID_DEF.DTC_R_Active == 1)) {
        BSD_Diagnostic_SWC_ARID_DEF.is_c3_BSD_Diagnostic_SWC =
          BSD_Diagnostic_S_IN_SYSTEM_FAIL;
        rtb_System_Health = 2U;
        BSD_Available = 0U;
      } else {
        tmp_1 = Rte_IRead_Diagnostic_Run_RPort_SensorStatus_Status_Left();
        if (tmp_1 != 0) {
          tmp_0 = (sint32)(BSD_Diagnostic_SWC_ARID_DEF.Counter_L + 1U);
          if (BSD_Diagnostic_SWC_ARID_DEF.Counter_L + 1U > 255U) {
            tmp_0 = 255;
          }

          BSD_Diagnostic_SWC_ARID_DEF.Counter_L = (uint8)tmp_0;
        } else {
          BSD_Diagnostic_SWC_ARID_DEF.Counter_L = 0U;
          BSD_Diagnostic_SWC_ARID_DEF.DTC_L_Active = 0U;
        }

        if (BSD_Diagnostic_SWC_ARID_DEF.Counter_L >= 5) {
          BSD_Diagnostic_SWC_ARID_DEF.DTC_L_Active = 1U;
          BSD_Diagnostic_SWC_ARID_DEF.Counter_L = 5U;
        }

        tmp_0 = Rte_IRead_Diagnostic_Run_RPort_SensorStatus_Status_Right();
        if (tmp_0 != 0) {
          tmp = (sint32)(BSD_Diagnostic_SWC_ARID_DEF.Counter_R + 1U);
          if (BSD_Diagnostic_SWC_ARID_DEF.Counter_R + 1U > 255U) {
            tmp = 255;
          }

          BSD_Diagnostic_SWC_ARID_DEF.Counter_R = (uint8)tmp;
        } else {
          BSD_Diagnostic_SWC_ARID_DEF.Counter_R = 0U;
          BSD_Diagnostic_SWC_ARID_DEF.DTC_R_Active = 0U;
        }

        if (BSD_Diagnostic_SWC_ARID_DEF.Counter_R >= 5) {
          BSD_Diagnostic_SWC_ARID_DEF.DTC_R_Active = 1U;
          BSD_Diagnostic_SWC_ARID_DEF.Counter_R = 5U;
        }

        if ((Rte_IRead_Diagnostic_Run_RPort_VehicleStatus_Vehicle_Speed() <=
             0.5F) &&
            (Rte_IRead_Diagnostic_Run_RPort_VehicleStatus_Gear_Position() == 3))
        {
          tmp = (sint32)(BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed + 1U);
          if (BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed + 1U > 255U) {
            tmp = 255;
          }

          BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed = (uint8)tmp;
        } else {
          BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed = 0U;
          BSD_Diagnostic_SWC_ARID_DEF.DTC_Speed_Active = 0U;
        }

        if (BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed >= 10) {
          BSD_Diagnostic_SWC_ARID_DEF.DTC_Speed_Active = 1U;
          BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed = 10U;
        }

        tmp = (sint32)((uint32)BSD_Diagnostic_SWC_ARID_DEF.DTC_L_Active +
                       BSD_Diagnostic_SWC_ARID_DEF.DTC_R_Active);
        if ((uint32)tmp > 255U) {
          tmp = 255;
        }

        tmp = (sint32)((uint32)tmp +
                       BSD_Diagnostic_SWC_ARID_DEF.DTC_Speed_Active);
        if ((uint32)tmp > 255U) {
          tmp = 255;
        }

        tmp_1 = (sint32)((uint32)
                         ((Rte_IRead_Diagnostic_Run_RPort_WarningStatus_Warning_Status
                           () > 0) && ((tmp_1 == 3) || (tmp_0 == 3))) + (uint32)
                         tmp);
        if ((uint32)tmp_1 > 255U) {
          tmp_1 = 255;
        }

        BSD_Diagnostic_SWC_ARID_DEF.DTC_Active_Count = (uint8)tmp_1;
      }
      break;

     case BSD_Diagnostic_S_IN_SYSTEM_FAIL:
      rtb_System_Health = 2U;
      BSD_Available = 0U;
      if (BSD_Diagnostic_SWC_ARID_DEF.DTC_Active_Count == 0) {
        BSD_Diagnostic_SWC_ARID_DEF.is_c3_BSD_Diagnostic_SWC =
          BSD_Diagnostic_SWC_IN_SYSTEM_OK;
        rtb_System_Health = 0U;
        BSD_Available = 1U;
      } else if ((BSD_Diagnostic_SWC_ARID_DEF.DTC_L_Active != 1) ||
                 (BSD_Diagnostic_SWC_ARID_DEF.DTC_R_Active != 1)) {
        BSD_Diagnostic_SWC_ARID_DEF.is_c3_BSD_Diagnostic_SWC =
          BSD_Diagnost_IN_SYSTEM_DEGRADED;
        rtb_System_Health = 1U;
        BSD_Available = 1U;
      } else {
        tmp_1 = Rte_IRead_Diagnostic_Run_RPort_SensorStatus_Status_Left();
        if (tmp_1 != 0) {
          tmp_0 = (sint32)(BSD_Diagnostic_SWC_ARID_DEF.Counter_L + 1U);
          if (BSD_Diagnostic_SWC_ARID_DEF.Counter_L + 1U > 255U) {
            tmp_0 = 255;
          }

          BSD_Diagnostic_SWC_ARID_DEF.Counter_L = (uint8)tmp_0;
        } else {
          BSD_Diagnostic_SWC_ARID_DEF.Counter_L = 0U;
          BSD_Diagnostic_SWC_ARID_DEF.DTC_L_Active = 0U;
        }

        if (BSD_Diagnostic_SWC_ARID_DEF.Counter_L >= 5) {
          BSD_Diagnostic_SWC_ARID_DEF.DTC_L_Active = 1U;
          BSD_Diagnostic_SWC_ARID_DEF.Counter_L = 5U;
        }

        tmp_0 = Rte_IRead_Diagnostic_Run_RPort_SensorStatus_Status_Right();
        if (tmp_0 != 0) {
          tmp = (sint32)(BSD_Diagnostic_SWC_ARID_DEF.Counter_R + 1U);
          if (BSD_Diagnostic_SWC_ARID_DEF.Counter_R + 1U > 255U) {
            tmp = 255;
          }

          BSD_Diagnostic_SWC_ARID_DEF.Counter_R = (uint8)tmp;
        } else {
          BSD_Diagnostic_SWC_ARID_DEF.Counter_R = 0U;
          BSD_Diagnostic_SWC_ARID_DEF.DTC_R_Active = 0U;
        }

        if (BSD_Diagnostic_SWC_ARID_DEF.Counter_R >= 5) {
          BSD_Diagnostic_SWC_ARID_DEF.DTC_R_Active = 1U;
          BSD_Diagnostic_SWC_ARID_DEF.Counter_R = 5U;
        }

        if ((Rte_IRead_Diagnostic_Run_RPort_VehicleStatus_Vehicle_Speed() <=
             0.5F) &&
            (Rte_IRead_Diagnostic_Run_RPort_VehicleStatus_Gear_Position() == 3))
        {
          tmp = (sint32)(BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed + 1U);
          if (BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed + 1U > 255U) {
            tmp = 255;
          }

          BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed = (uint8)tmp;
        } else {
          BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed = 0U;
          BSD_Diagnostic_SWC_ARID_DEF.DTC_Speed_Active = 0U;
        }

        if (BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed >= 10) {
          BSD_Diagnostic_SWC_ARID_DEF.DTC_Speed_Active = 1U;
          BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed = 10U;
        }

        tmp = (sint32)(((uint32)BSD_Diagnostic_SWC_ARID_DEF.DTC_L_Active +
                        BSD_Diagnostic_SWC_ARID_DEF.DTC_R_Active) +
                       BSD_Diagnostic_SWC_ARID_DEF.DTC_Speed_Active);
        if ((uint32)tmp > 255U) {
          tmp = 255;
        }

        tmp_1 = (sint32)((uint32)
                         ((Rte_IRead_Diagnostic_Run_RPort_WarningStatus_Warning_Status
                           () > 0) && ((tmp_1 == 3) || (tmp_0 == 3))) + (uint32)
                         tmp);
        if ((uint32)tmp_1 > 255U) {
          tmp_1 = 255;
        }

        BSD_Diagnostic_SWC_ARID_DEF.DTC_Active_Count = (uint8)tmp_1;
      }
      break;

     default:
      /* case IN_SYSTEM_OK: */
      rtb_System_Health = 0U;
      BSD_Available = 1U;
      if ((BSD_Diagnostic_SWC_ARID_DEF.DTC_Active_Count > 0) &&
          ((BSD_Diagnostic_SWC_ARID_DEF.DTC_L_Active != 1) ||
           (BSD_Diagnostic_SWC_ARID_DEF.DTC_R_Active != 1))) {
        BSD_Diagnostic_SWC_ARID_DEF.is_c3_BSD_Diagnostic_SWC =
          BSD_Diagnost_IN_SYSTEM_DEGRADED;
        rtb_System_Health = 1U;
      } else if ((BSD_Diagnostic_SWC_ARID_DEF.DTC_L_Active == 1) &&
                 (BSD_Diagnostic_SWC_ARID_DEF.DTC_R_Active == 1)) {
        BSD_Diagnostic_SWC_ARID_DEF.is_c3_BSD_Diagnostic_SWC =
          BSD_Diagnostic_S_IN_SYSTEM_FAIL;
        rtb_System_Health = 2U;
        BSD_Available = 0U;
      } else {
        tmp_1 = Rte_IRead_Diagnostic_Run_RPort_SensorStatus_Status_Left();
        if (tmp_1 != 0) {
          tmp_0 = (sint32)(BSD_Diagnostic_SWC_ARID_DEF.Counter_L + 1U);
          if (BSD_Diagnostic_SWC_ARID_DEF.Counter_L + 1U > 255U) {
            tmp_0 = 255;
          }

          BSD_Diagnostic_SWC_ARID_DEF.Counter_L = (uint8)tmp_0;
        } else {
          BSD_Diagnostic_SWC_ARID_DEF.Counter_L = 0U;
          BSD_Diagnostic_SWC_ARID_DEF.DTC_L_Active = 0U;
        }

        if (BSD_Diagnostic_SWC_ARID_DEF.Counter_L >= 5) {
          BSD_Diagnostic_SWC_ARID_DEF.DTC_L_Active = 1U;
          BSD_Diagnostic_SWC_ARID_DEF.Counter_L = 5U;
        }

        tmp_0 = Rte_IRead_Diagnostic_Run_RPort_SensorStatus_Status_Right();
        if (tmp_0 != 0) {
          tmp = (sint32)(BSD_Diagnostic_SWC_ARID_DEF.Counter_R + 1U);
          if (BSD_Diagnostic_SWC_ARID_DEF.Counter_R + 1U > 255U) {
            tmp = 255;
          }

          BSD_Diagnostic_SWC_ARID_DEF.Counter_R = (uint8)tmp;
        } else {
          BSD_Diagnostic_SWC_ARID_DEF.Counter_R = 0U;
          BSD_Diagnostic_SWC_ARID_DEF.DTC_R_Active = 0U;
        }

        if (BSD_Diagnostic_SWC_ARID_DEF.Counter_R >= 5) {
          BSD_Diagnostic_SWC_ARID_DEF.DTC_R_Active = 1U;
          BSD_Diagnostic_SWC_ARID_DEF.Counter_R = 5U;
        }

        if ((Rte_IRead_Diagnostic_Run_RPort_VehicleStatus_Vehicle_Speed() <=
             0.5F) &&
            (Rte_IRead_Diagnostic_Run_RPort_VehicleStatus_Gear_Position() == 3))
        {
          tmp = (sint32)(BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed + 1U);
          if (BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed + 1U > 255U) {
            tmp = 255;
          }

          BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed = (uint8)tmp;
        } else {
          BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed = 0U;
          BSD_Diagnostic_SWC_ARID_DEF.DTC_Speed_Active = 0U;
        }

        if (BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed >= 10) {
          BSD_Diagnostic_SWC_ARID_DEF.DTC_Speed_Active = 1U;
          BSD_Diagnostic_SWC_ARID_DEF.Counter_Speed = 10U;
        }

        tmp = (sint32)((uint32)BSD_Diagnostic_SWC_ARID_DEF.DTC_L_Active +
                       BSD_Diagnostic_SWC_ARID_DEF.DTC_R_Active);
        if ((uint32)tmp > 255U) {
          tmp = 255;
        }

        tmp = (sint32)((uint32)tmp +
                       BSD_Diagnostic_SWC_ARID_DEF.DTC_Speed_Active);
        if ((uint32)tmp > 255U) {
          tmp = 255;
        }

        tmp_1 = (sint32)((uint32)
                         ((Rte_IRead_Diagnostic_Run_RPort_WarningStatus_Warning_Status
                           () > 0) && ((tmp_1 == 3) || (tmp_0 == 3))) + (uint32)
                         tmp);
        if ((uint32)tmp_1 > 255U) {
          tmp_1 = 255;
        }

        BSD_Diagnostic_SWC_ARID_DEF.DTC_Active_Count = (uint8)tmp_1;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/BSD_Diagnostic_SWC_Chart' */

  /* Outport: '<Root>/DTC_Active_Count' */
  Rte_IWrite_Diagnostic_Run_PPort_DiagnosticStatus_DTC_Active_Count
    (BSD_Diagnostic_SWC_ARID_DEF.DTC_Active_Count);

  /* Outport: '<Root>/System_Health' */
  Rte_IWrite_Diagnostic_Run_PPort_DiagnosticStatus_System_Health
    (rtb_System_Health);

  /* Outport: '<Root>/BSD_Available' */
  Rte_IWrite_Diagnostic_Run_PPort_DiagnosticStatus_BSD_Available(BSD_Available);
}

/* Model initialize function */
void Diag_init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
