#include "../Tests/unity_src/src/unity.h"
#include "BSD_Diagnostic_SWC.h"
#include <string.h>

/* ── MOCK RTE INPUTS ── */
static uint8   mock_gear_pos     = 3U;
static uint8   mock_status_left  = 0U;
static uint8   mock_status_right = 0U;
static float32 mock_speed        = 80.0f;
static uint8   mock_warning_stat = 0U;

/* ── MOCK RTE OUTPUTS ── */
static uint8 result_dtc_count   = 0U;
static uint8 result_sys_health  = 0U;
static uint8 result_bsd_avail   = 1U;

/* ── MOCK RTE API IMPLEMENTATIONS ── */
uint8   Rte_IRead_Diagnostic_Run_RPort_VehicleStatus_Gear_Position(void) { return mock_gear_pos; }
uint8   Rte_IRead_Diagnostic_Run_RPort_SensorStatus_Status_Left(void)    { return mock_status_left; }
uint8   Rte_IRead_Diagnostic_Run_RPort_SensorStatus_Status_Right(void)   { return mock_status_right; }
float32 Rte_IRead_Diagnostic_Run_RPort_VehicleStatus_Vehicle_Speed(void) { return mock_speed; }
uint8   Rte_IRead_Diagnostic_Run_RPort_WarningStatus_Warning_Status(void) { return mock_warning_stat; }

void Rte_IWrite_Diagnostic_Run_PPort_DiagnosticStatus_DTC_Active_Count(uint8 u) { result_dtc_count = u; }
void Rte_IWrite_Diagnostic_Run_PPort_DiagnosticStatus_System_Health(uint8 u)    { result_sys_health = u; }
void Rte_IWrite_Diagnostic_Run_PPort_DiagnosticStatus_BSD_Available(uint8 u)    { result_bsd_avail = u; }

/* ── TEST LIFECYCLE ── */
void setUp(void)
{
    memset(&BSD_Diagnostic_SWC_ARID_DEF, 0, sizeof(BSD_Diagnostic_SWC_ARID_DEF));
    mock_gear_pos     = 3U;
    mock_status_left  = 0U;
    mock_status_right = 0U;
    mock_speed        = 80.0f;
    mock_warning_stat = 0U;
}

void tearDown(void) {}

/* ── TEST CASES ── */

void test_Normal_Operation(void)
{
    Diagnostic_Run();
    TEST_ASSERT_EQUAL_UINT8(0U, result_sys_health);
    TEST_ASSERT_EQUAL_UINT8(1U, result_bsd_avail);
}


void test_Left_Sensor_Debounce_Triggers_Degraded(void)
{
    mock_status_left = 1U;
    
    // 1. Initial run to activate the chart
    Diagnostic_Run(); 
    
    // 2. Run enough cycles (e.g., 10) to ensure the Stateflow
    //    debounce logic and state transitions have time to settle.
    for(int i = 0; i < 10; i++) { 
        Diagnostic_Run(); 
    }
    
    TEST_ASSERT_EQUAL_UINT8(1U, result_sys_health);
    TEST_ASSERT_EQUAL_UINT8(1U, result_dtc_count);
}
void test_Both_Sensors_Trigger_System_Fail(void)
{
    mock_status_left  = 1U;
    mock_status_right = 1U;
    
    
  // Run enough cycles to trigger both debounce counters
    for(int i = 0; i < 7; i++) { 
        Diagnostic_Run(); 
    }    
    TEST_ASSERT_EQUAL_UINT8(2U, result_sys_health); // FAIL
    TEST_ASSERT_EQUAL_UINT8(0U, result_bsd_avail);  // Disabled
}


void test_Speed_Signal_Loss_Debounce(void)
{
    mock_speed    = 0.0f;
    mock_gear_pos = 3U;
    
    Diagnostic_Run(); // Init
    
    // Speed debounce threshold is 10. Run 15 times to be certain.
    for(int i = 0; i < 15; i++) { 
        Diagnostic_Run(); 
    }
    
    TEST_ASSERT_EQUAL_UINT8(1U, result_dtc_count);
    TEST_ASSERT_EQUAL_UINT8(1U, result_sys_health);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_Normal_Operation);
    RUN_TEST(test_Left_Sensor_Debounce_Triggers_Degraded);
    RUN_TEST(test_Both_Sensors_Trigger_System_Fail);
    RUN_TEST(test_Speed_Signal_Loss_Debounce);
    return UNITY_END();
}