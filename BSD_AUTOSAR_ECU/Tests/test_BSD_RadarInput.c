/* ============================================================
 * Unit Tests — BSD_RadarInput_SWC
 * Tests actual Simulink generated code via RTE Mocks
 * ============================================================ */

#include "unity.h"
#include "Platform_Types.h"
#include "BSD_RadarInput_SWC.h"

/* ── Constants ── */
#define SENSOR_OK        0u
#define SENSOR_FAIL      1u
#define SENSOR_BLOCKED   2u
#define SENSOR_DEGRADED  3u

/* ── Mock RTE State Variables ── */
static uint16 mock_raw_dist_L  = 0u;
static uint16 mock_raw_dist_R  = 0u;
static uint8  mock_hw_status_L = SENSOR_OK;
static uint8  mock_hw_status_R = SENSOR_OK;

static float32 result_dist_L   = 0.0f;
static float32 result_dist_R   = 0.0f;
static uint8   result_status_L = SENSOR_OK;
static uint8   result_status_R = SENSOR_OK;

/* ════════════════════════════════════════
 * MOCK RTE API FUNCTIONS
 * ════════════════════════════════════════ */

/* Inputs to the SWC */
uint16 Rte_IRead_BSD_RadarInput_Run_RPort_Raw_Distance_Left_Raw_Distance(void) {
    return mock_raw_dist_L;
}
uint16 Rte_IRead_BSD_RadarInput_Run_RPort_Raw_Distance_Right_Raw_Distance(void) {
    return mock_raw_dist_R;
}
uint8 Rte_IRead_BSD_RadarInput_Run_RPort_Raw_Status_Left_Raw_Status(void) {
    return mock_hw_status_L;
}
uint8 Rte_IRead_BSD_RadarInput_Run_RPort_Raw_Status_Right_Raw_Status(void) {
    return mock_hw_status_R;
}

/* Outputs from the SWC */
void Rte_IWrite_BSD_RadarInput_Run_PPort_RadarData_Distance_Left_Distance(float32 u) {
    result_dist_L = u;
}
void Rte_IWrite_BSD_RadarInput_Run_PPort_RadarData_Distance_Right_Distance(float32 u) {
    result_dist_R = u;
}
void Rte_IWrite_BSD_RadarInput_Run_PPort_RadarData_Status_Left_Status(uint8 u) {
    result_status_L = u;
}
void Rte_IWrite_BSD_RadarInput_Run_PPort_RadarData_Status_Right_Status(uint8 u) {
    result_status_R = u;
}

/* ── Setup / Teardown ── */
void setUp(void)
{
    mock_raw_dist_L  = 0u;
    mock_raw_dist_R  = 0u;
    mock_hw_status_L = SENSOR_OK;
    mock_hw_status_R = SENSOR_OK;
    result_dist_L    = 0.0f;
    result_dist_R    = 0.0f;
    result_status_L  = SENSOR_OK;
    result_status_R  = SENSOR_OK;
}

void tearDown(void) {}

/* ════════════════════════════════════════
 * TEST CASES
 * ════════════════════════════════════════ */

void test_Scale_Zero_Distance(void)
{
    mock_raw_dist_L = 0u;
    BSD_RadarInput_Run();
    TEST_ASSERT_FLOAT_WITHIN(0.001f, 0.0f, result_dist_L);
}

void test_Scale_Normal_Distance_2m(void)
{
    mock_raw_dist_L = 200u;
    BSD_RadarInput_Run();
    TEST_ASSERT_FLOAT_WITHIN(0.001f, 2.0f, result_dist_L);
}

void test_Range_OutOfRange_High_Sets_Status_Fail(void)
{
    /* raw=6000 → 60.0m > 50m → SENSOR_FAIL (1) */
    mock_raw_dist_L = 6000u;
    BSD_RadarInput_Run();
    TEST_ASSERT_EQUAL_UINT8(1u, result_status_L);
}

void test_HW_Status_Fail_Overrides_SW_OK(void)
{
    /* Distance in range BUT HW says FAIL → output FAIL (1) */
    mock_raw_dist_L  = 200u;         
    mock_hw_status_L = SENSOR_FAIL;  
    BSD_RadarInput_Run();
    TEST_ASSERT_EQUAL_UINT8(1u, result_status_L);
}

/* ── Main ── */
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_Scale_Zero_Distance);
    RUN_TEST(test_Scale_Normal_Distance_2m);
    RUN_TEST(test_Range_OutOfRange_High_Sets_Status_Fail);
    RUN_TEST(test_HW_Status_Fail_Overrides_SW_OK);
    return UNITY_END();
}