/*
 * OS.h
 *
 *  Created on: Oct 2, 2026
 *      Author: pc
 */

#ifndef INC_OS_H_
#define INC_OS_H_
#include "Os_Types.h"
#include "Scheduler.h"

#include "Os_Cfg.h"


StatusType ActivateTask(TaskType);
StatusType TerminateTask(void);
StatusType Start_OS(void);
StatusType TaskWait(TaskType TaskID, uint32 NoTicks);
StatusType Os_Delay(uint32 NoTicks);
StatusType Schedule(void);

StatusType GetResource(Resource_t* Res);
StatusType ReleaseResource(Resource_t* Res);
void ShutdownOS(StatusType Error);

StatusType GetTaskState(TaskType   TaskID,TaskStateRefType State );


#endif /* INC_OS_H_ */
