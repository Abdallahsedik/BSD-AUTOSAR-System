/*
 * Scheduler.h
 *
 *  Created on: Sep 27, 2026
 *      Author: pc
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include "Cortexmx_OsPorting.h"
#include "Os_Types.h"

#define MAX_TASKS   16 /*max number of tasks*/


typedef enum {
	SVC_Activatetask,
	SVC_terminateTask,
	SVC_TaskWaitingTime,
	SVC_AquireMutex,
	SVC_ReleaseMutex,
	SVC_Schedule
}SVC_ID;

typedef enum
{
	TASK_BASIC,
	TASK_EXTENDED
} TaskClass_t;
typedef enum {
	FULL_PREEMPTIVE,
	NON_PREEMPTIVE
} SchedulingType_t;

typedef struct Task_ref{
	TaskType  TaskID;
	TaskClass_t   TaskClass;
	uint8         MaxActivations;   /* basic tasks only */
	uint8         ActivationCount;  /* running + pending activations */
	uint8 		Restarted;			/*for basic task to rebuild the task stack*/
	SchedulingType_t SchedType; 	/*pre compile config */
	uint32 Stack_Size;
	uint8 priority;
	void (*p_TaskEntry)(void); //pointer to Tack C Function
	uint8 AutoStart ;
	uint32 _S_PSP_Task ;//Not Entered by the user
	uint32 _E_PSP_Task ;//Not Entered by the user
	uint32* Current_PSP ;//Not Entered by the user
	char TaskName[30] ;
	TaskStateType TaskState;	//Not Entered by the user
	struct{
		enum{
			Enable,
			Disable
		}Blocking;
		uint32 Ticks_Count ;
	}TimingWaiting;
}Task_ref;

typedef struct {
	Task_ref* OSTasks[MAX_TASKS]; //Sch. Table
	uint32 _S_MSP_Task ;
	uint32 _E_MSP_Task ;
	uint32 PSP_Task_Locator ;
	uint32 NoOfActiveTasks ;
	Task_ref* CurrentTask ;
	Task_ref* NextTask ;
	enum{
		OSsuspend,
		OsRunning
	}OSmodeID;
}OS_Control_t;
extern OS_Control_t OS_Control;

typedef struct{
	uint8 CeilingPriority;     /*you need to define/calculate  Ceiling Priority before run os  */
	Task_ref* Owner;
	uint8 PreviousPriority;   /*owner's original periority without celing */
}Resource_t;

/*  compile-time config for tasks  */
typedef struct {
	void (*TaskEntry)(void);
	uint32 StackSize;
	uint8 Priority;
	const char* TaskName;
	uint8 AutoStart;
	TaskClass_t Class;
	uint8 MaxActivations;
	SchedulingType_t SchedType;
} TaskConfig_t;

extern const TaskConfig_t TaskConfigTable[];
extern const uint8 NumberOfConfiguredTasks;

extern Task_ref TasksPool[MAX_TASKS];
#define IDLE_Task   (&TasksPool[0])

StatusType MYRTOS_Init();
StatusType MYRTOS_Create_task(Task_ref * TRef);
void MYRTOS_Update_TasksWaitingTime(void);
void MyRTOS_StackOverflowHook(Task_ref* FaultyTask);
StatusType MyRTOS_Create_TaskStack(Task_ref* Tref);
void MYRTOS_Update_Sch_teble(void);
StatusType MYRTOS_Create_MainStack();

void MYRTOS_OS_SVC_Set(SVC_ID svc_id);

void Decide_whatNext(void);


#endif /* INC_SCHEDULER_H_ */
