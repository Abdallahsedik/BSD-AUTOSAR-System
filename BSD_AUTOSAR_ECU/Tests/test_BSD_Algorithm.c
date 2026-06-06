#include "../Tests/unity_src/src/unity.h"
#include <stdint.h>

/* ── Mock RTE ── */
static float    mock_dist_L    = 5.0f;
static float    mock_dist_R    = 5.0f;
static uint8_t  mock_status_L  = 0u;
static uint8_t  mock_status_R  = 0u;
static float    mock_speed     = 80.0f;
static uint8_t  mock_turn      = 0u;
static uint8_t  mock_gear      = 3u;
static uint8_t  result_warning = 0u;
static uint8_t  result_led     = 0u;

/* ── Simple BSD Algorithm (matches your Stateflow logic) ── */
void run_algorithm(void)
{
    float eff_dist;

    if (mock_status_L != 0u && mock_status_R != 0u)
        eff_dist = 99.0f;
    else if (mock_status_L != 0u)
        eff_dist = mock_dist_R;
    else if (mock_status_R != 0u)
        eff_dist = mock_dist_L;
    else
        eff_dist = (mock_dist_L < mock_dist_R) ? mock_dist_L : mock_dist_R;

    if (eff_dist < 3.0f && mock_speed > 10.0f && mock_gear == 3u)
    {
        if (mock_turn > 0u)
            result_warning = 2u;
        else
            result_warning = 1u;
        result_led = 1u;
    }
    else
    {
        result_warning = 0u;
        result_led     = 0u;
    }
}

/* ── Test Setup ── */
void setUp(void)
{
    mock_dist_L   = 5.0f;
    mock_dist_R   = 5.0f;
    mock_status_L = 0u;
    mock_status_R = 0u;
    mock_speed    = 80.0f;
    mock_turn     = 0u;
    mock_gear     = 3u;
}

void tearDown(void) {}

/* ── Test Cases ── */
void test_CLEAR_no_object(void)
{
    mock_dist_L = 5.0f;
    run_algorithm();
    TEST_ASSERT_EQUAL_UINT8(0u, result_warning);
    TEST_ASSERT_EQUAL_UINT8(0u, result_led);
}

void test_WARNING_object_detected(void)
{
    mock_dist_L = 2.0f;
    run_algorithm();
    TEST_ASSERT_EQUAL_UINT8(1u, result_warning);
    TEST_ASSERT_EQUAL_UINT8(1u, result_led);
}

void test_ALERT_object_and_turn_signal(void)
{
    mock_dist_L = 2.0f;
    mock_turn   = 1u;
    run_algorithm();
    TEST_ASSERT_EQUAL_UINT8(2u, result_warning);
    TEST_ASSERT_EQUAL_UINT8(1u, result_led);
}

void test_CLEAR_low_speed(void)
{
    mock_dist_L = 2.0f;
    mock_speed  = 5.0f;
    run_algorithm();
    TEST_ASSERT_EQUAL_UINT8(0u, result_warning);
}

void test_CLEAR_not_in_drive(void)
{
    mock_dist_L = 2.0f;
    mock_gear   = 1u;
    run_algorithm();
    TEST_ASSERT_EQUAL_UINT8(0u, result_warning);
}

void test_CLEAR_both_sensors_fail(void)
{
    mock_dist_L   = 2.0f;
    mock_status_L = 1u;
    mock_status_R = 1u;
    run_algorithm();
    TEST_ASSERT_EQUAL_UINT8(0u, result_warning);
}

void test_WARNING_left_sensor_fail_right_ok(void)
{
    mock_dist_L   = 2.0f;
    mock_dist_R   = 1.5f;
    mock_status_L = 1u;
    run_algorithm();
    TEST_ASSERT_EQUAL_UINT8(1u, result_warning);
}

/* ── Main ── */
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_CLEAR_no_object);
    RUN_TEST(test_WARNING_object_detected);
    RUN_TEST(test_ALERT_object_and_turn_signal);
    RUN_TEST(test_CLEAR_low_speed);
    RUN_TEST(test_CLEAR_not_in_drive);
    RUN_TEST(test_CLEAR_both_sensors_fail);
    RUN_TEST(test_WARNING_left_sensor_fail_right_ok);
    return UNITY_END();
}