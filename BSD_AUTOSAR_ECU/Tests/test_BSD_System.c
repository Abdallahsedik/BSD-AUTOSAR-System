#include "../Tests/unity_src/src/unity.h"
#include "BSD_System.h" 
#include <string.h> /* For memset */

/* ── MOCK RTE INPUT DATA ── */
static float32 mock_distance_L      = 5.0f;
static float32 mock_distance_R      = 5.0f;
static uint8   mock_status_L        = 0U;
static uint8   mock_status_R        = 0U;
static float32 mock_vehicle_speed   = 80.0f;
static uint8   mock_turn_signal     = 0U;
static float32 mock_steering_angle  = 0.0f;
static uint8   mock_gear_position   = 3U;

/* ── MOCK RTE OUTPUT DATA ── */
static uint8   result_warning_status = 0U;
static uint8   result_led_output     = 0U;
static uint8   result_sensor_l_fault = 0U;
static uint8   result_sensor_r_fault = 0U;

/* ── MOCK RTE READ APIS ── */
float32 Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Distance_Left(void) { return mock_distance_L; }
float32 Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Distance_Right(void) { return mock_distance_R; }
uint8   Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Status_Left(void) { return mock_status_L; }
uint8   Rte_IRead_BSD_Algorithm_Run_RPort_RadarData_Status_Right(void) { return mock_status_R; }
float32 Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Vehicle_Speed(void) { return mock_vehicle_speed; }
uint8   Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Turn_Signal(void) { return mock_turn_signal; }
float32 Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Steering_Angle(void) { return mock_steering_angle; }
uint8   Rte_IRead_BSD_Algorithm_Run_RPort_VehicleData_Gear_Position(void) { return mock_gear_position; }

/* ── MOCK RTE WRITE APIS ── */
void Rte_IWrite_BSD_Algorithm_Run_PPort_WarningOutput_Warning_Status(uint8 data) { result_warning_status = data; }
void Rte_IWrite_BSD_Algorithm_Run_PPort_WarningOutput_LED_Output(uint8 data) { result_led_output = data; }
void Rte_IWrite_BSD_Algorithm_Run_PPort_FaultStatus_Sensor_L_Fault(uint8 data) { result_sensor_l_fault = data; }
void Rte_IWrite_BSD_Algorithm_Run_PPort_FaultStatus_Sensor_R_Fault(uint8 data) { result_sensor_r_fault = data; }

/* ── EXTERN STATEFLOW STRUCTURE ── */
extern ARID_DEF_BSD_System_T BSD_System_ARID_DEF;

/* ── TEST LIFECYCLE ── */
void setUp(void)
{
    /* Reset state machine memory so tests don't affect each other */
    memset(&BSD_System_ARID_DEF, 0, sizeof(BSD_System_ARID_DEF));
    BSD_System_Init();

    /* Reset inputs to default driving straight without objects */
    mock_distance_L     = 5.0f;
    mock_distance_R     = 5.0f;
    mock_status_L       = 0U;
    mock_status_R       = 0U;
    mock_vehicle_speed  = 80.0f;
    mock_turn_signal    = 0U;
    mock_steering_angle = 0.0f;
    mock_gear_position  = 3U;
    
    /* Clear output buffers */
    result_warning_status = 0U;
    result_led_output     = 0U;
}

void tearDown(void) {}

/* ── TEST CASES ── */

void test_Initialization_Enters_Clear_State(void)
{
    /* Step 1: Initialize chart */
    BSD_Algorithm_Run(); 
    
    TEST_ASSERT_EQUAL_UINT8(0U, result_warning_status);
    TEST_ASSERT_EQUAL_UINT8(0U, result_led_output);
}

void test_WARNING_Triggered_By_Close_Object(void)
{
    /* Step 1: Initialize chart to CLEAR */
    BSD_Algorithm_Run(); 

    /* Step 2: Inject target and run cycle */
    mock_distance_L = 2.0f;
    BSD_Algorithm_Run(); 

    TEST_ASSERT_EQUAL_UINT8(1U, result_warning_status);
    TEST_ASSERT_EQUAL_UINT8(1U, result_led_output);
}

void test_ALERT_Requires_Both_TurnSignal_And_Steering(void)
{
    /* Step 1: Initialize chart to CLEAR */
    BSD_Algorithm_Run(); 

    /* Step 2: Move to WARNING state */
    mock_distance_L = 2.0f;
    BSD_Algorithm_Run(); 

    /* Step 3: Trigger ALERT using the generated AND logic */
    mock_turn_signal = 1U;
    mock_steering_angle = 20.0f;
    BSD_Algorithm_Run(); 

    TEST_ASSERT_EQUAL_UINT8(2U, result_warning_status);
}

void test_CLEAR_Maintained_During_Sharp_Turn(void)
{
    /* Step 1: Initialize chart to CLEAR */
    BSD_Algorithm_Run(); 

    /* Step 2: Inject close target but sharp steering angle */
    mock_distance_L = 2.0f;
    mock_steering_angle = 50.0f; 
    BSD_Algorithm_Run(); 

    /* Should remain CLEAR due to curve suppression */
    TEST_ASSERT_EQUAL_UINT8(0U, result_warning_status);
    TEST_ASSERT_EQUAL_UINT8(0U, result_led_output);
}

void test_CLEAR_Maintained_When_Speed_Low(void)
{
    /* Step 1: Initialize chart to CLEAR */
    BSD_Algorithm_Run(); 

    /* Step 2: Inject close target but drop speed */
    mock_distance_L = 2.0f;
    mock_vehicle_speed = 5.0f; 
    BSD_Algorithm_Run(); 

    TEST_ASSERT_EQUAL_UINT8(0U, result_warning_status);
}

void test_Fault_Outputs_Mapped_Correctly(void)
{
    /* Step 1: Initialize */
    BSD_Algorithm_Run(); 
    
    /* Step 2: Inject Left Sensor Fault */
    mock_status_L = 1U;
    BSD_Algorithm_Run();
    
    TEST_ASSERT_EQUAL_UINT8(1U, result_sensor_l_fault);
    TEST_ASSERT_EQUAL_UINT8(0U, result_sensor_r_fault);
}

/* ── MAIN RUNNER ── */
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_Initialization_Enters_Clear_State);
    RUN_TEST(test_WARNING_Triggered_By_Close_Object);
    RUN_TEST(test_ALERT_Requires_Both_TurnSignal_And_Steering);
    RUN_TEST(test_CLEAR_Maintained_During_Sharp_Turn);
    RUN_TEST(test_CLEAR_Maintained_When_Speed_Low);
    RUN_TEST(test_Fault_Outputs_Mapped_Correctly);
    return UNITY_END();
}