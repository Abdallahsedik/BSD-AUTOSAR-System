/*
 * OS.c
 *
 *  Created on: Oct 2, 2026
 *      Author: pc
 */

#include "OS.h"
#include "MyRtos_FIFO.h"

Task_ref TasksPool[MAX_TASKS];
extern FIFO_Buf_t READY_QUEUE ;
extern Task_ref * READY_QUEUE_FIFO[];

/* internal helper: TaskType -> TCB */
static Task_ref* Os_GetTask(TaskType TaskID)
{
	uint8 i;
	if (TaskID == INVALID_TASK)
	{
		return NULL_PTR;
	}
	for (i = 0; i < OS_Control.NoOfActiveTasks; i++)
	{
		if (OS_Control.OSTasks[i]->TaskID == TaskID)
			return OS_Control.OSTasks[i];   /* pointer moves, ID travels with it */
	}
	return NULL_PTR;
}

StatusType ActivateTask(TaskType TaskID)
{

	Task_ref * Task =Os_GetTask(TaskID);
	/*  NULL check */
	if (Task == NULL_PTR)
	{
		return E_OS_ID;
	}

	else if (Task->TaskState != SUSPENDED)
	{
		if (Task->TaskClass == TASK_BASIC && Task->ActivationCount < Task->MaxActivations)
		{
			Task->ActivationCount++;      /* remember it, runs again after it terminates */
			return E_OK;
		}
		return E_OS_LIMIT;	}
	else
	{
		if(MyRTOS_Create_TaskStack(Task) !=E_OK)
		{
			return E_OS_STACKFAULT;
		}
		else
		{
			Task->ActivationCount = 1;  /* first activation */
		}
	}
	Task->TaskState = READY;

	if(__get_IPSR() !=0u)
	{		/*handler mode*/
		/*we are in Handler mode/privileged  */
		MYRTOS_Update_Sch_teble();

		if (OS_Control.OSmodeID == OsRunning)
		{
			Decide_whatNext();
			trigger_OS_PendSV();   /*now we will trigger pendsv */
		}


	}
	else
	{		/*thread mode */
		/*update sch. table
		 * svc interrupt/ handler (update ready queue)
		 * set pendsv (decide what next (dequeue) ,then switch context)
		 * */
		MYRTOS_OS_SVC_Set(SVC_Activatetask);
	}


	return E_OK;
}

StatusType TerminateTask(void)
{
	Task_ref* Task = OS_Control.CurrentTask;

	if (__get_IPSR() != 0u)        /* task level only, not from an ISR */
	{
		return E_OS_CALLEVEL;
	}
	else if (Task == NULL_PTR)
	{		return E_OS_STATE;
	}
	//	if (T->HeldRes != NULL_PTR)    /*  may not terminate holding a resource */
	//		return E_OS_RESOURCE;

	Task->TaskState = SUSPENDED;
	MYRTOS_OS_SVC_Set(SVC_terminateTask);

	/* ===== OSEK: this point is unreachable on success =====
	 * (next activation gets a fresh stack frame). If we get here,
	 * no context switch happened = kernel bug. Fail loudly: */
	//    ErrorHook(E_OS_ILLEGAL);
	__disable_irq();
	while (1);
}



StatusType TaskWait(TaskType TaskID, uint32 NoTicks)
{
	Task_ref* Task = Os_GetTask(TaskID);

	/* unknown task ID  */
	if (Task == NULL_PTR)
	{
		return E_OS_ID;
	}else if (__get_IPSR() != 0u)
	{
		/* an ISR can never block — there is no task context to suspend */
		return E_OS_CALLEVEL;
	}
	else if (OS_Control.OSmodeID != OsRunning)
	{
		/* services are only valid between StartOS and ShutdownOS */
		return E_OS_CALLEVEL;
	}
	else if (NoTicks == 0u)
	{
		/* parameter out of range */
		return E_OS_VALUE;
	}
	else if(Task ==IDLE_Task)
	{
		/* the idle task must NEVER wait */
		return E_OS_STATE;
	}
	else if (Task->TaskClass != TASK_EXTENDED)
	{
		return E_OS_ACCESS;
	}



	if (Task == OS_Control.CurrentTask)
	{
		/*========== branch 1: block MYSELF ==========*/
		Task->TimingWaiting.Blocking    = Enable;
		Task->TimingWaiting.Ticks_Count = NoTicks;
		Task->TaskState = WAITING;                 /* freeze */

		MYRTOS_OS_SVC_Set(SVC_terminateTask);   /* switch away immediately */

		return E_OK;
	}

	/*========== branch 2: block ANOTHER task ==========*/
	if (Task->TaskState != READY)
	{
		return E_OS_STATE;   /* must sit in the queue */
	}
	else
	{
		Task->TimingWaiting.Blocking    = Enable;
		// Task Should be blocked
		Task->TimingWaiting.Ticks_Count = NoTicks;
		Task->TaskState = WAITING;
	}
	/* rebuild ready queue via syscall (drops the task we just blocked).
	 * No context switch needed — the RUNNING task keeps the CPU. */
	MYRTOS_OS_SVC_Set(SVC_TaskWaitingTime);

	return E_OK;
}

StatusType Os_Delay(uint32 NoTicks)
{
	if (OS_Control.CurrentTask == NULL_PTR)
	{
		return E_OS_STATE;
	}
	return TaskWait(OS_Control.CurrentTask->TaskID, NoTicks);
}


StatusType GetTaskState(TaskType  TaskID, TaskStateRefType State)
{
	Task_ref* Task = Os_GetTask(TaskID);
	/* unknown task ID  */
	if (Task == NULL_PTR || State == NULL)
	{
		return E_OS_ID;
	}
	else
	{
		* State = Task->TaskState;
		return E_OK;

	}

}

StatusType Start_OS(void)
{

	uint8 iterator=0;
	StatusType Error_Status = E_OK;
	/*os init */
	OS_Control.OSmodeID = OSsuspend;
	Error_Status = MYRTOS_Create_MainStack();
	if (Error_Status != E_OK)
	{
		return Error_Status;
	}

	if (FIFO_init(&READY_QUEUE, READY_QUEUE_FIFO, MAX_TASKS) != FIFO_NO_ERROR)
	{
		__disable_irq();
		while(1);
	}

	/*create tasks from config table in os_cfg*/
	for (iterator = 0; iterator < NumberOfConfiguredTasks; iterator++)
	{
		Task_ref* NewTask = &TasksPool[iterator];

		strcpy(NewTask->TaskName, TaskConfigTable[iterator].TaskName);
		NewTask->priority    = TaskConfigTable[iterator].Priority;
		NewTask->p_TaskEntry = TaskConfigTable[iterator].TaskEntry;
		NewTask->Stack_Size  = TaskConfigTable[iterator].StackSize;
		NewTask->TaskClass 	 = TaskConfigTable[iterator].Class;
		NewTask->SchedType   = TaskConfigTable[iterator].SchedType;
		if(NewTask->TaskClass ==TASK_BASIC)
		{
			NewTask->MaxActivations= TaskConfigTable[iterator].MaxActivations;
		}
		else
		{
			/*extended task 1 activation */
			NewTask->MaxActivations= 1;

		}



		Error_Status = MYRTOS_Create_task(NewTask);
		if (Error_Status != E_OK)
		{
			return Error_Status;
		}

		if (TaskConfigTable[iterator].AutoStart)
		{
			ActivateTask(NewTask->TaskID);
		}


	}
	/*----------------------------------------------------------------------*/
	/*start os sequence  */
	OS_Control.OSmodeID=OsRunning;
	/*set default task (current task =idle task*/
	OS_Control.CurrentTask = IDLE_Task;
	OS_Control.CurrentTask->TaskState = RUNNING;

	MYRTOS_Update_Sch_teble();   /* build the  Ready Queue */
	Decide_whatNext();
	if (OS_Control.NextTask != NULL_PTR)
	{
		OS_Control.CurrentTask = OS_Control.NextTask;
		OS_Control.NextTask = NULL_PTR;
	}

	/*start ticker 1 ms*/
	HW_Init();/*privilage*/
	Start_Ticker();/*privilage*/

	OS_SET_PSP(OS_Control.CurrentTask->Current_PSP);
	/*switch thread mode sp from msp to psp  */
	OS_SWITCH_SP_TO_PSP;

	OS_SWITCH_TO_UNPRIVILEGED;

	OS_Control.CurrentTask->p_TaskEntry();

	return E_OK;
}




StatusType GetResource(Resource_t* Res)
{
	if (Res == NULL_PTR || OS_Control.CurrentTask == NULL_PTR)
		return E_OS_ID;


	/*check if the task is the owner of the resource */
	if (Res->Owner == OS_Control.CurrentTask)
	{
		return E_OS_STATE;
	}


	if (Res->Owner != NULL_PTR)
	{
		return E_OS_STATE;
	}

	/*Ceiling Priority*/
	Res->Owner = OS_Control.CurrentTask;
	Res->PreviousPriority = OS_Control.CurrentTask->priority;

	if (OS_Control.CurrentTask->priority > Res->CeilingPriority)
	{
		OS_Control.CurrentTask->priority = Res->CeilingPriority;
	}

	return E_OK;
}
StatusType ReleaseResource(Resource_t* Res)
{
	if (Res == NULL_PTR || Res->Owner != OS_Control.CurrentTask)
		return E_OS_STATE;

	/* recovre the orignal priority for the task */
	OS_Control.CurrentTask->priority = Res->PreviousPriority;
	Res->Owner = NULL_PTR;


	MYRTOS_OS_SVC_Set(SVC_ReleaseMutex);

	return E_OK;
}



void ShutdownOS(StatusType Error)
{
	OS_Control.OSmodeID=OSsuspend;
	Stop_Ticker();
	__disable_irq();
	while(1);

}
StatusType Schedule(void)
{
	if (__get_IPSR() != 0u)
	{
		return E_OS_CALLEVEL;   /* cant called from ISR */
	}

	if (OS_Control.CurrentTask->SchedType != NON_PREEMPTIVE)
	{
		return E_OS_CALLEVEL;   /*  API for  Non-Preemptive tasks only  */
	}

	MYRTOS_OS_SVC_Set(SVC_Schedule);

	return E_OK;
}



