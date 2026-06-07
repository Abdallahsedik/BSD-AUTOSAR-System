#include "../Tests/unity_src/src/unity.h"
#include "Platform_Types.h"
#include "BSD_Warning_SWC.h"
#include <string.h>

/* ── MOCK RTE INPUT DATA ── */
static uint8 mock_warning_status = 0U;

/* ── MOCK RTE OUTPUT DATA ── */
static uint8 result_led_left   = 0U;
static uint8 result_led_right  = 0U;
static uint8 result_buzzer     = 0U;
static uint8 result_hmi        = 0U;

/* ── EXTERN STATEFLOW STRUCTURE ── */
/* This is defined in your BSD_Warning_SWC.h and .c files */
extern ARID_DEF_BSD_Warning_SWC_T BSD_Warning_SWC_ARID_DEF;

/* ── DECLARE RUNNABLE ── */
extern void Warning_Run(void);

/* ── MOCK RTE READ APIS ── 
 * Note: Simulink's RTE header mapped the generic names to these specific 
 * component-prefixed names. We must mock the exact names the linker expects.
 */
uint8 Rte_IRead_BSD_Warning_SWC_Warning_Run_RPort_WarningData_Warning_Status(void) 
{ 
    return mock_warning_status; 
}

/* ── MOCK RTE WRITE APIS ── */
void Rte_IWrite_BSD_Warning_SWC_Warning_Run_PPort_LED_Control_LED_Left(uint8 u) 
{ 
    result_led_left = u; 
}
void Rte_IWrite_BSD_Warning_SWC_Warning_Run_PPort_LED_Control_LED_Right(uint8 u) 
{ 
    result_led_right = u; 
}
void Rte_IWrite_BSD_Warning_SWC_Warning_Run_PPort_LED_Control_Buzzer_Active(uint8 u) 
{ 
    result_buzzer = u; 
}
void Rte_IWrite_BSD_Warning_SWC_Warning_Run_PPort_HMI_Warning_HMI_Display(uint8 u) 
{ 
    result_hmi = u; 
}

/* ── TEST LIFECYCLE ── */
void setUp(void)
{
    /* Completely reset the state machine memory before each test */
    memset(&BSD_Warning_SWC_ARID_DEF, 0, sizeof(BSD_Warning_SWC_ARID_DEF));
    
    mock_warning_status = 0U;
    
    result_led_left  = 0U;
    result_led_right = 0U;
    result_buzzer    = 0U;
    result_hmi       = 0U;
}

void tearDown(void) {}

/* ── TEST CASES ── */

void test_Initialization_Enters_Off_State(void)
{
    /* Step 1: Run chart initialization */
    Warning_Run();
    
    TEST_ASSERT_EQUAL_UINT8(0U, result_led_left);
    TEST_ASSERT_EQUAL_UINT8(0U, result_led_right);
    TEST_ASSERT_EQUAL_UINT8(0U, result_buzzer);
    TEST_ASSERT_EQUAL_UINT8(0U, result_hmi);
}

void test_Transition_To_Warning_State(void)
{
    Warning_Run(); /* Init to OFF */
    
    /* Trigger WARNING */
    mock_warning_status = 1U;
    Warning_Run(); 
    
    /* Expect solid LEDs and HMI = 1, but NO buzzer */
    TEST_ASSERT_EQUAL_UINT8(1U, result_led_left);
    TEST_ASSERT_EQUAL_UINT8(1U, result_led_right);
    TEST_ASSERT_EQUAL_UINT8(0U, result_buzzer);
    TEST_ASSERT_EQUAL_UINT8(1U, result_hmi);
}

void test_Transition_To_Alert_State(void)
{
    Warning_Run(); /* Init to OFF */
    
    /* Transition OFF -> WARNING */
    mock_warning_status = 1U;
    Warning_Run(); 
    
    /* Transition WARNING -> ALERT */
    mock_warning_status = 2U;
    Warning_Run();
    
    /* Expect Buzzer active and HMI upgraded to 2 */
    TEST_ASSERT_EQUAL_UINT8(1U, result_buzzer);
    TEST_ASSERT_EQUAL_UINT8(2U, result_hmi);
}

void test_Alert_State_Flashing_Logic(void)
{
    int i;
    
    Warning_Run(); /* Init to OFF */
    
    mock_warning_status = 1U;
    Warning_Run(); /* Transition to WARNING */
    
    mock_warning_status = 2U;
    Warning_Run(); /* Transition to ALERT (Flash_Counter = 0) */
    
    /* At this point, we remain in ALERT. 
       Let's simulate 9 more cycles to watch the counter tick up. */
    for(i = 1; i <= 9; i++) {
        Warning_Run();
        
        if(i < 5) {
            /* Before 5 ticks, it retains the previous LED state (ON from WARNING state) */
            /* Do nothing */
        } else if (i >= 5 && i < 10) {
            /* From tick 5 to 9, code explicitly commands LEDs to 1 */
            TEST_ASSERT_EQUAL_UINT8(1U, result_led_left);
        }
    }
    
    /* On the 10th tick, the LEDs should be commanded to 0 (Turn OFF) */
    Warning_Run();
    TEST_ASSERT_EQUAL_UINT8(0U, result_led_left);
    TEST_ASSERT_EQUAL_UINT8(0U, result_led_right);
}

void test_Transition_Alert_Back_To_Off(void)
{
    Warning_Run(); /* Init */
    
    mock_warning_status = 1U;
    Warning_Run(); /* To WARNING */
    
    mock_warning_status = 2U;
    Warning_Run(); /* To ALERT */
    
    /* Target clears (Status goes to 0) */
    mock_warning_status = 0U;
    Warning_Run(); /* Should jump back to OFF */
    
    TEST_ASSERT_EQUAL_UINT8(0U, result_led_left);
    TEST_ASSERT_EQUAL_UINT8(0U, result_buzzer);
    TEST_ASSERT_EQUAL_UINT8(0U, result_hmi);
}


/* ── MAIN RUNNER ── */
int main(void)
{
    UNITY_BEGIN();
    
    RUN_TEST(test_Initialization_Enters_Off_State);
    RUN_TEST(test_Transition_To_Warning_State);
    RUN_TEST(test_Transition_To_Alert_State);
    RUN_TEST(test_Alert_State_Flashing_Logic);
    RUN_TEST(test_Transition_Alert_Back_To_Off);

    return UNITY_END();
}