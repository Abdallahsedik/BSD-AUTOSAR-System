/*
 * Os_Cfg.c
 *
 *  Created on: Oct 2, 2026
 *      Author: pc
 */

#include "Scheduler.h"
#include "Os_Cfg.h"

/* Include Application Layer SWCs */
#include "Rte/Rte.h"
#include "RadarInput_swc/RadarInput.h"
#include "VehicleSignal_swc/Rte_VehicleSignals.h"
#include "Algorithm_swc/Algorithm.h"
#include "warning_swc/Warning.h"
#include "Diagnostic_swc/Diagnostic.h"

extern void task1(void);
extern void task2(void);
extern void task3(void);
extern void MyRtos_IDLE_Task(void);

const TaskConfig_t TaskConfigTable[] ={
        { MyRtos_IDLE_Task, 300,  255, "IdleTask", 1, TASK_BASIC,    1  ,FULL_PREEMPTIVE },
        { task1,            1024, 5,   "task_1",   1, TASK_EXTENDED, 1  ,FULL_PREEMPTIVE },
        { task2,            1024, 3,   "task_2",   1, TASK_EXTENDED, 1 	,NON_PREEMPTIVE  },
        { task3,            1024, 4,   "task_3",   1, TASK_BASIC,    3  ,FULL_PREEMPTIVE },
};

const uint8 NumberOfConfiguredTasks = sizeof(TaskConfigTable) / sizeof(TaskConfig_t);
