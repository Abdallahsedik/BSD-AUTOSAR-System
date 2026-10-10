/*
 * Scheduler.c
 *
 *  Created on: Sep 27, 2026
 *      Author: pc
 */


#include "Scheduler.h"
#include "MyRtos_FIFO.h"
#include "OS.h"

OS_Control_t OS_Control;



FIFO_Buf_t READY_QUEUE ;
Task_ref * READY_QUEUE_FIFO[MAX_TASKS];

uint8 Idle_task_LED=0;

volatile Task_ref* LastOverflowedTask = NULL_PTR;


void MyRtos_IDLE_Task(void)
{
	while(1)
	{
		__asm("wfe");
		Idle_task_LED^=1;

	}
}


static void Os_TaskExit(void)
{
	TerminateTask();
	while (1);
}

StatusType MYRTOS_Create_MainStack()
{
	StatusType Error_Status=E_OK;

	OS_Control._S_MSP_Task= ((uint32)&_estack);
	OS_Control._E_MSP_Task=(OS_Control._S_MSP_Task -MainStackSize);
	//allign 8 bytes space btw main task , psp tasks
	OS_Control.PSP_Task_Locator=(OS_Control._E_MSP_Task -8);

	if (OS_Control._E_MSP_Task < ((uint32)(&_end) + RESERVED_HEAP_STACK))
	{
		return E_OS_STACKFAULT;
	}
	else
	{

	}

	return Error_Status;


}

StatusType MyRTOS_Create_TaskStack(Task_ref* Tref)
{
	/*Task Frame
	 * ======
	 * XPSR
	 * PC (Next Task Instruction which should be Run)
	 * LR (return register which is saved in CPU while TASk1 running before TaskSwitching)
	 * r12
	 * r4
	 * r3
	 * r2
	 * r1
	 * r0
	 *====
	 *r5, r6 , r7 ,r8 ,r9, r10,r11 (Saved/Restore)Manual
	 */

	if(Tref == NULL_PTR)
	{
		return E_OS_ID;
	}
	/*check if excedded of max number os tasks*/
	if (OS_Control.NoOfActiveTasks >= MAX_TASKS)
	{
		return E_OS_LIMIT;
	}
	Tref->Current_PSP =(uint32 *) Tref->_S_PSP_Task ;

	Tref->Current_PSP-- ;
	if(Tref->Current_PSP < (uint32*)Tref->_E_PSP_Task )
	{
		return E_OS_STACKFAULT;
	}
	else
	{
		*(Tref->Current_PSP) = 0x01000000;         //DUMMY_XPSR should T =1 to avoid BUS fault;//0x01000000
		Tref->Current_PSP-- ;
		if(Tref->Current_PSP < (uint32*)Tref->_E_PSP_Task)
		{
			return E_OS_STACKFAULT;

		}
		else
		{
			*(Tref->Current_PSP) = (unsigned int)Tref->p_TaskEntry ; //PC
			Tref->Current_PSP-- ; //LR = 0xFFFFFFFD (EXC_RETURN)Return to thread with PSP
			if(Tref->Current_PSP <  (uint32*)Tref->_E_PSP_Task)
			{
				return E_OS_STACKFAULT;

			}
			else
			{
				*(Tref->Current_PSP) = (unsigned int)Os_TaskExit;   /* 0xFFFFFFFD */

			}

		}

	}




	for (int  j=0 ; j< 13 ; j++ )
	{
		Tref->Current_PSP-- ;
		if(Tref->Current_PSP < (uint32*)Tref->_E_PSP_Task)
		{
			return E_OS_STACKFAULT;
		}
		else
		{
			*(Tref->Current_PSP)  = 0 ;

		}

	}

	return E_OK;
}


StatusType MYRTOS_Create_task(Task_ref * TRef)
{

	if(TRef==NULL_PTR)
	{
		return E_OS_ID;

	}
	else if(OS_Control.NoOfActiveTasks>= MAX_TASKS)
	{
		return E_OS_LIMIT  ;
	}
	else
	{

	}
	StatusType Error_Status=E_OK;
	TRef->TimingWaiting.Blocking = Disable;
	/*create psp stack for the task
	 *chack stack size not exceeded the psp stack */
	TRef->TaskID =(TaskType)OS_Control.NoOfActiveTasks;
	TRef->_S_PSP_Task=OS_Control.PSP_Task_Locator;
	TRef->_E_PSP_Task= (TRef->_S_PSP_Task - TRef->Stack_Size);
	if (TRef->_E_PSP_Task < ((uint32)(&_end) + RESERVED_HEAP_STACK))
	{
		return E_OS_STACKFAULT;
	}
	/*alligned 8 bytes*/
	OS_Control.PSP_Task_Locator = (TRef->_E_PSP_Task - 8);
	/*Init psp task stack */
	Error_Status= MyRTOS_Create_TaskStack(TRef);

	/*update sch table and no of active tasks */
	//	OS_Control.OSTasks[OS_Control.NoOfActiveTasks]=TRef;
	//	OS_Control.NoOfActiveTasks++;
	/*task state update -> suspended */
	if(Error_Status ==E_OK)
	{

		OS_Control.OSTasks[OS_Control.NoOfActiveTasks] = TRef;
		OS_Control.NoOfActiveTasks++;
		TRef->TaskState=SUSPENDED;
	}
	else
	{

	}

	return Error_Status;

}
/*this function used when stack  overflow */
/*in nextversion  i will add terminate the task */
void MyRTOS_StackOverflowHook(Task_ref* FaultyTask)
{
	__disable_irq();

	/*save the fucdtion in variable */
	LastOverflowedTask = FaultyTask;

	while(1);/*stuck in this point */
}



void MYRTOS_OS_SVC_Set(SVC_ID svc_id)
{
	switch (svc_id) {
	case SVC_Activatetask:/*activate task*/
		__asm("svc #0x00");
		break;
	case SVC_terminateTask:/*terminate task*/
		__asm("svc #0x01");
		break;
	case SVC_TaskWaitingTime:/* task waiting time*/
		__asm("svc #0x02");
		break;
	case SVC_AquireMutex:/* task Aquire Mutex*/
		__asm("svc #0x03");
		break;
	case SVC_ReleaseMutex:/* task Release Mutex*/
		__asm("svc #0x04");
		break;
	case SVC_Schedule:/* task Release Mutex*/
		__asm("svc #0x05");
		break;




	}
}


StatusType MYRTOS_Init(void)
{
	StatusType Error_Status=E_OK;
	//update os mode
	OS_Control.OSmodeID=OSsuspend;

	//specify the main stack for os
	Error_Status=MYRTOS_Create_MainStack();
	//create os ready queue
	if(FIFO_init(&READY_QUEUE, READY_QUEUE_FIFO, MAX_TASKS)!= FIFO_NO_ERROR)
	{
		/*fatal karnel inveriant broken -> shutdown */
		__disable_irq();
		//		ShutdownOS(E_OS_ILLEGAL);
		//		Error_Status+=E_OS_ILLEGAL;
		while(1);
	}
	//cofig idle task

	strcpy(IDLE_Task->TaskName, "IdleTask");
	IDLE_Task->priority=255;
	IDLE_Task->p_TaskEntry=MyRtos_IDLE_Task;
	IDLE_Task->Stack_Size=300;

	Error_Status = MYRTOS_Create_task(IDLE_Task);
	if (Error_Status != E_OK)
	{
		return Error_Status;   /* stop here  */
	}

	return Error_Status;
}
//StatusType Activate_task(Task_ref * TRef)

//StatusType Terminate_task(void)
//{
//	if (OS_Control.CurrentTask == NULL_PTR)
//		return E_OS_ID;
//
//	OS_Control.CurrentTask->TaskState = SUSPENDED;
//	MYRTOS_OS_SVC_Set(SVC_terminateTask);
//	return E_OK;
//}

//void MYRTOS_TaskWait(unsigned int NoTICKS,Task_ref* SelfTref)
//{
//	SelfTref->TimingWaiting.Blocking = Enable ;
//	SelfTref->TimingWaiting.Ticks_Count = NoTICKS ;
//	// Task Should be blocked
//	SelfTref->TaskState = WAITING ;
//	//to be SUSPENDED immediately
//	MYRTOS_OS_SVC_Set(SVC_terminateTask);
//
//}

//StatusType MyRTOS_GetTaskState(Task_ref* TRef, uint8* State)
//{
//	if (TRef == NULL_PTR || State == NULL_PTR)
//	{
//		return E_OS_ID;
//	}
//
//	*State = TRef->TaskState;
//	return E_OK;
//}
/*handler */
void bubbleSort()
{
	unsigned int i, j , n;
	Task_ref* temp ;
	n = OS_Control.NoOfActiveTasks ;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (OS_Control.OSTasks[j]->priority > OS_Control.OSTasks[j + 1]->priority)
			{
				temp = OS_Control.OSTasks[j] ;
				OS_Control.OSTasks[j] = OS_Control.OSTasks[j + 1 ] ;
				OS_Control.OSTasks[j + 1] = temp ;
			}

}

void MYRTOS_Update_Sch_teble(void)
{
	Task_ref * temp =NULL_PTR;
	Task_ref* Ptask =NULL_PTR ;
	uint8 TopPriority = 255;     /* idle task = 255*/
	uint8 iterator=0;
	/*1-buble sort sch_table ->OS_Control->OSTasks[ ]
	 * periority high then low
	 * 2-free ready queue
	 * 3-update ready queue
	 * */
	bubbleSort();
	while(FIFO_dequeue(&READY_QUEUE ,&temp)!=FIFO_EMPTY); /* empty the queue */

	/* 1- find the best task priority  from  (READY or RUNNING) */
	for (iterator = 0; iterator < OS_Control.NoOfActiveTasks; iterator++)
	{
		Ptask = OS_Control.OSTasks[iterator];
		if ((Ptask->TaskState == READY || Ptask->TaskState == RUNNING) &&
				(Ptask->priority < TopPriority))
		{
			TopPriority = Ptask->priority;
		}
	}

	/* 2- enqueue only READY tasks with that priority.
	 */
	for (iterator = 0; iterator < OS_Control.NoOfActiveTasks; iterator++)
	{
		Ptask = OS_Control.OSTasks[iterator];
		if (Ptask->TaskState == READY && Ptask->priority == TopPriority)
		{
			FIFO_enqueue(&READY_QUEUE, Ptask);
		}
	}


}



void Decide_whatNext(void)
{
	Task_ref* Cur = OS_Control.CurrentTask;
	uint8 SwitchNeeded = 0;
	Task_ref* Pick = NULL_PTR;


	__disable_irq();

	/* a decision is already waiting for PendSV*/
	if (OS_Control.NextTask != NULL_PTR)
	{
		__enable_irq();
		return;
	}

	/* 1) Non-preemptive RUNNING task keeps the CPU unless it blocked/terminated */
	if (Cur->SchedType == NON_PREEMPTIVE && Cur->TaskState == RUNNING)
	{
		__enable_irq();
		return;
	}

	/* 2) Current task is  (SUSPENDED/WAITING) or a higher-priority
	 *    task is waiting in the ready queue -> must switch.               */

	if (Cur->TaskState != RUNNING)
	{
		SwitchNeeded = 1;
	}
	else if ((READY_QUEUE.counter != 0) && ((*READY_QUEUE.head)->priority < Cur->priority))
	{
		SwitchNeeded = 1;
	}

	if (SwitchNeeded && FIFO_dequeue(&READY_QUEUE, &Pick) == FIFO_NO_ERROR)
	{
		Pick->TaskState = RUNNING;
		if (Cur->TaskState == RUNNING)
		{
			Cur->TaskState = READY;
		}
		OS_Control.NextTask = Pick;

	}


	__enable_irq();
}

/*to execute specific os service
 * handler mode */
void OS_SVC(uint32 * Stack_Frame)
{
	//r0,r1,r3,r12, lr , return address(pc) and xpsr
	uint8 SVC_Number=0;
	SVC_Number= *((uint8 *)(((uint8 *)Stack_Frame[6])-2));
	switch(SVC_Number)
	{
	case SVC_Activatetask:
	case SVC_terminateTask:
	{
		Task_ref* Cur = OS_Control.CurrentTask;

		if (SVC_Number == SVC_terminateTask && Cur->TaskState == SUSPENDED)
		{
			if (Cur->ActivationCount > 0)
			{
				Cur->ActivationCount--;
			}

			if (Cur->ActivationCount > 0)       /* an activation is still pending */
			{
				MyRTOS_Create_TaskStack(Cur);   /* new  frame*/
				Cur->TaskState = READY;
				Cur->Restarted = 1;
			}
		}

		MYRTOS_Update_Sch_teble();
		if (OS_Control.OSmodeID == OsRunning)
		{
			if (strcmp(OS_Control.CurrentTask->TaskName, "IdleTask") != 0)
			{
				Decide_whatNext();
				trigger_OS_PendSV();
			}
		}
		break;
	}
	case SVC_TaskWaitingTime:/* task waiting time*/
		MYRTOS_Update_Sch_teble();
		break;
	case SVC_AquireMutex:/* task Aquire Mutex*/
		break;
	case SVC_ReleaseMutex:/* task Release Mutex*/
		MYRTOS_Update_Sch_teble();
		if (OS_Control.OSmodeID == OsRunning)
		{
			if (strcmp(OS_Control.CurrentTask->TaskName, "IdleTask") != 0)
			{
				Decide_whatNext();
				trigger_OS_PendSV();
			}
		}
		break;
	case SVC_Schedule:
		MYRTOS_Update_Sch_teble();
		if (OS_Control.OSmodeID == OsRunning)
		{	/*1- we must change SchedType from non_PREEMPTIVE to FULL_PREEMPTIVE
		 *2-decide what next
		 *3-restore SchedType to non_PREEMPTIVE */
			Task_ref* Cur = OS_Control.CurrentTask;
			SchedulingType_t Saved = Cur->SchedType;   /* copy the value */
			Cur->SchedType = FULL_PREEMPTIVE;
			Decide_whatNext();
			Cur->SchedType = Saved;
			trigger_OS_PendSV();
		}
		break;
	}

}
/*this function must be assembly to be compatable with optimezation levels -01, -02,-03
 *  */
__attribute__  ((naked))void PendSV_Handler()
{

	//====================================
	//Save the Context of the Current Task
	//====================================
	if (OS_Control.CurrentTask->Restarted)
	{
		/* stack was just rebuilt in OS_SVC, clear  flag */
		OS_Control.CurrentTask->Restarted = 0;
	}
	else
	{
		//Get the Current Task "Current PSP from CPU register" as CPU Push XPSR,.....,R0
		OS_GET_PSP(OS_Control.CurrentTask->Current_PSP);

		//using this Current_PSP (Pointer) tp store (R4 to R11)
		OS_Control.CurrentTask->Current_PSP-- ;
		__asm volatile("mov %0,r4 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP-- ;
		__asm volatile("mov %0,r5 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP-- ;
		__asm volatile("mov %0,r6 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP-- ;
		__asm volatile("mov %0,r7 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP-- ;
		__asm volatile("mov %0,r8 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP-- ;
		__asm volatile("mov %0,r9 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP-- ;
		__asm volatile("mov %0,r10 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
		OS_Control.CurrentTask->Current_PSP-- ;
		__asm volatile("mov %0,r11 " : "=r" (*(OS_Control.CurrentTask->Current_PSP))  );
	}
	//save the current Value of PSP
	//already saved in Current_PSP



	//====================================
	//Restore the Context of the Next Task
	//====================================
	if (OS_Control.NextTask != NULL){
		OS_Control.CurrentTask = OS_Control.NextTask ;
		OS_Control.NextTask = NULL ;
	}

	__asm volatile("mov r11,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r10,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r9,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r8,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r7,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r6,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r5,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r4,%0 " : : "r" (*(OS_Control.CurrentTask->Current_PSP))  );
	OS_Control.CurrentTask->Current_PSP++ ;

	//update PSP and exit
	OS_SET_PSP(OS_Control.CurrentTask->Current_PSP);
	__asm volatile("BX LR");

}



void MYRTOS_Update_TasksWaitingTime(void)
{
	for (int i = 0; i < OS_Control.NoOfActiveTasks; i++) {
		if (OS_Control.OSTasks[i]->TaskState == WAITING &&
				OS_Control.OSTasks[i]->TimingWaiting.Blocking == Enable) //it is blocking until meet the time line
		{
			OS_Control.OSTasks[i]->TimingWaiting.Ticks_Count-- ;
			if (OS_Control.OSTasks[i]->TimingWaiting.Ticks_Count == 0) {
				OS_Control.OSTasks[i]->TimingWaiting.Blocking = Disable;
				OS_Control.OSTasks[i]->TaskState = READY;
			}
		}
	}

	MYRTOS_Update_Sch_teble();          // rebuild ready queue

	if (OS_Control.OSmodeID == OsRunning)
	{
		Decide_whatNext();
		if (OS_Control.NextTask != NULL_PTR)
			trigger_OS_PendSV();
	}
}
