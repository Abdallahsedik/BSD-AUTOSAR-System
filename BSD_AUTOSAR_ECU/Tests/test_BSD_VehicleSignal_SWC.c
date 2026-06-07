#include "../Tests/unity_src/src/unity.h"
#include "Platform_Types.h"

/* * If Platform_Types.h doesn't define the standard AUTOSAR types in your test 
 * environment, we map them to standard C types here for the compiler.
 */
#ifndef _PLATFORM_TYPES_H_
#include <stdint.h>
typedef float    float32;
typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef int16_t  sint16;
#endif

/* ── MOCK RTE INPUT DATA (Raw CAN signals) ── */
static uint16 mock_raw_speed    = 0U;
static sint16 mock_raw_steering = 0;
static uint8  mock_raw_turn     = 0U;
static uint8  mock_raw_gear     = 0U;

/* ── MOCK RTE OUTPUT DATA (Conditioned signals) ── */
static float32 result_speed    = 0.0f;
static float32 result_steering = 0.0f;
static uint8   result_turn     = 0U;
static uint8   result_gear     = 0U;

/* ── DECLARE THE RUNNABLE UNDER TEST ── */
extern void VehicleSignal_Run(void);
extern void BSD_VehicleSignal_SWC_Init(void);

/* ── MOCK RTE READ APIS ── */
uint16 Rte_IRead_VehicleSignal_Run_RPort_Vehicle_Speed_Raw_Raw_Vehicle_Speed(void) { return mock_raw_speed; }
sint16 Rte_IRead_VehicleSignal_Run_RPort_Steering_Raw_Raw_Steering_Angle(void) { return mock_raw_steering; }
uint8  Rte_IRead_VehicleSignal_Run_RPort_TurnSignal_Raw_Raw_Turn_Signal(void) { return mock_raw_turn; }
uint8  Rte_IRead_VehicleSignal_Run_RPort_Gear_Raw_Raw_Gear_Position(void) { return mock_raw_gear; }

/* ── MOCK RTE WRITE APIS ── */
void Rte_IWrite_VehicleSignal_Run_PPort_Vehicle_Data_Vehicle_Speed(float32 data) { result_speed = data; }
void Rte_IWrite_VehicleSignal_Run_PPort_Vehicle_Data_Steering_Angle(float32 data) { result_steering = data; }
void Rte_IWrite_VehicleSignal_Run_PPort_Vehicle_Data_Turn_Signal(uint8 data) { result_turn = data; }
void Rte_IWrite_VehicleSignal_Run_PPort_Vehicle_Data_Gear_Position(uint8 data) { result_gear = data; }


/* ── TEST LIFECYCLE ── */
void setUp(void)
{
    /* Reset all inputs to safe defaults */
    mock_raw_speed    = 0U;
    mock_raw_steering = 0;
    mock_raw_turn     = 0U;
    mock_raw_gear     = 0U;
    
    /* Clear output buffers */
    result_speed    = 0.0f;
    result_steering = 0.0f;
    result_turn     = 0U;
    result_gear     = 0U;
}

void tearDown(void) {}

/* ── TEST CASES: VEHICLE SPEED ── */

void test_Speed_Normal_Scaling(void)
{
    /* Input: 8000 (Expected: 80.0 km/h) */
    mock_raw_speed = 8000U;
    VehicleSignal_Run();
    
    /* Using FLOAT_WITHIN to handle Simulink's 0.00999999F exact precision */
    TEST_ASSERT_FLOAT_WITHIN(0.01f, 80.0f, result_speed);
}

void test_Speed_Upper_Saturation(void)
{
    /* Input: 35000 (Expected: 350.0 km/h -> Clamped to 300.0 km/h) */
    mock_raw_speed = 35000U;
    VehicleSignal_Run();
    
    TEST_ASSERT_FLOAT_WITHIN(0.001f, 300.0f, result_speed);
}

/* ── TEST CASES: STEERING ANGLE ── */

void test_Steering_Positive_Scaling(void)
{
    /* Input: 450 (Expected: 45.0 degrees) */
    mock_raw_steering = 450;
    VehicleSignal_Run();
    
    TEST_ASSERT_FLOAT_WITHIN(0.01f, 45.0f, result_steering);
}

void test_Steering_Negative_Scaling(void)
{
    /* Input: -450 (Expected: -45.0 degrees) */
    mock_raw_steering = -450;
    VehicleSignal_Run();
    
    TEST_ASSERT_FLOAT_WITHIN(0.01f, -45.0f, result_steering);
}

void test_Steering_Upper_Saturation(void)
{
    /* Input: 10000 (Expected: 1000.0 deg -> Clamped to 900.0 deg) */
    mock_raw_steering = 10000;
    VehicleSignal_Run();
    
    TEST_ASSERT_FLOAT_WITHIN(0.001f, 900.0f, result_steering);
}

void test_Steering_Lower_Saturation(void)
{
    /* Input: -10000 (Expected: -1000.0 deg -> Clamped to -900.0 deg) */
    mock_raw_steering = -10000;
    VehicleSignal_Run();
    
    TEST_ASSERT_FLOAT_WITHIN(0.001f, -900.0f, result_steering);
}

/* ── TEST CASES: TURN SIGNAL VALIDATION ── */

void test_TurnSignal_Valid_Input(void)
{
    /* Input: 2 (Right Turn) */
    mock_raw_turn = 2U;
    VehicleSignal_Run();
    
    TEST_ASSERT_EQUAL_UINT8(2U, result_turn);
}

void test_TurnSignal_Invalid_Input_Forces_Zero(void)
{
    /* Input: 5 (Invalid Enum) -> Must output 0 (OFF) */
    mock_raw_turn = 5U;
    VehicleSignal_Run();
    
    TEST_ASSERT_EQUAL_UINT8(0U, result_turn);
}

/* ── TEST CASES: GEAR POSITION VALIDATION ── */

void test_GearPosition_Valid_Input(void)
{
    /* Input: 3 (Drive) */
    mock_raw_gear = 3U;
    VehicleSignal_Run();
    
    TEST_ASSERT_EQUAL_UINT8(3U, result_gear);
}

void test_GearPosition_Invalid_Input_Forces_Zero(void)
{
    /* Input: 6 (Invalid Enum) -> Must output 0 (Park) */
    mock_raw_gear = 6U;
    VehicleSignal_Run();
    
    TEST_ASSERT_EQUAL_UINT8(0U, result_gear);
}

/* ── MAIN RUNNER ── */
int main(void)
{
    UNITY_BEGIN();
    
    /* Speed Tests */
    RUN_TEST(test_Speed_Normal_Scaling);
    RUN_TEST(test_Speed_Upper_Saturation);
    
    /* Steering Tests */
    RUN_TEST(test_Steering_Positive_Scaling);
    RUN_TEST(test_Steering_Negative_Scaling);
    RUN_TEST(test_Steering_Upper_Saturation);
    RUN_TEST(test_Steering_Lower_Saturation);
    
    /* Enum Validation Tests */
    RUN_TEST(test_TurnSignal_Valid_Input);
    RUN_TEST(test_TurnSignal_Invalid_Input_Forces_Zero);
    RUN_TEST(test_GearPosition_Valid_Input);
    RUN_TEST(test_GearPosition_Invalid_Input_Forces_Zero);
    
    return UNITY_END();
}