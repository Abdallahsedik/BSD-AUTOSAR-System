#ifndef Rte_Type_h
#define Rte_Type_h


#include "Std_Types.h"

/* AUTOSAR RTE Status Types */
#ifndef RTE_E_OK
#define RTE_E_OK                       (0x00U)
#endif

#ifndef RTE_E_LOST_DATA
#define RTE_E_LOST_DATA                (0x40U)
#endif

/* --- Application Physical Data Types --- */
typedef float32 Distance_m_T;
typedef float32 Vehicle_Speed_T;
typedef float32 Steering_Angle_T;

/* --- Raw Data Types --- */
typedef uint16 Distance_Raw_T;
typedef uint16 Speed_Raw_T;
typedef sint16 Steering_Raw_T;
typedef uint8 Gear_Raw_T;
typedef uint8 TurnSignal_Raw_T;
typedef uint8 Status_Raw_T;

/* --- AUTOSAR Enumeration Types --- */
typedef uint8 BSDState_T;

#ifndef BSD_CLEAR
#define BSD_CLEAR                      (0U)
#endif

#ifndef BSD_WARNING
#define BSD_WARNING                    (1U)
#endif

#ifndef BSD_ALERT
#define BSD_ALERT                      (2U)
#endif

typedef uint8 LedState_T;

#ifndef LED_OFF
#define LED_OFF                        (0U)
#endif

#ifndef LED_ON
#define LED_ON                         (1U)
#endif

typedef uint8 Gear_T;

#ifndef GEAR_PARK
#define GEAR_PARK                      (0U)
#endif

#ifndef GEAR_REVERSE
#define GEAR_REVERSE                   (1U)
#endif

#ifndef GEAR_NEUTRAL
#define GEAR_NEUTRAL                   (2U)
#endif

#ifndef GEAR_DRIVE
#define GEAR_DRIVE                     (3U)
#endif

typedef uint8 SignalStatus_T;

#ifndef SIGNAL_OK
#define SIGNAL_OK                      (0U)
#endif

#ifndef SIGNAL_FAIL
#define SIGNAL_FAIL                    (1U)
#endif

typedef uint8 TurnSignal_T;

#ifndef TURN_OFF
#define TURN_OFF                       (0U)
#endif

#ifndef TURN_LEFT
#define TURN_LEFT                      (1U)
#endif

#ifndef TURN_RIGHT
#define TURN_RIGHT                     (2U)
#endif

typedef uint8 RadarStatus_T;

#ifndef RADAR_OK
#define RADAR_OK                       (0U)
#endif

#ifndef RADAR_FAIL
#define RADAR_FAIL                     (1U)
#endif

typedef uint8 DiagEventStatus_T;

#ifndef DIAG_EVT_PASSED
#define DIAG_EVT_PASSED                (0U)
#endif

#ifndef DIAG_EVT_FAILED
#define DIAG_EVT_FAILED                (1U)
#endif

typedef void* Rte_Instance;

#endif /* Rte_Type_h */
