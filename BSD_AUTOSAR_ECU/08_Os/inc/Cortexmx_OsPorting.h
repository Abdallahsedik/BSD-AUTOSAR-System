/*
 * Cortexmx_OsPorting.h
 *
 *  Created on: Sep 27, 2026
 *      Author: pc
 */

#ifndef INC_CORTEXMX_OSPORTING_H_
#define INC_CORTEXMX_OSPORTING_H_
#include "stm32f103x6.h"
#include <string.h>
#include "Std_Types.h"
#include "Systick.h"


extern int _estack ;
extern int  _end  ;/*_end == _eheap*/
#define RESERVED_HEAP_STACK   (0x200 + 0x400)   // _Min_Heap_Size + _Min_Stack_Size


#define MainStackSize 	3072



#define OS_SET_PSP(add)       __asm volatile("mov r0,%0   \n\t msr PSP ,r0 " :: "r"(add))
#define OS_GET_PSP(add) 	  __asm volatile("mrs %0, PSP" : "=r"(add))

#define OS_SWITCH_SP_TO_PSP  __asm volatile("mrs r0,control  \n\t mov r1 ,#0x02 \n\t orr r0,r0 ,r1 \n\t msr control ,r0 ")
#define OS_SWITCH_SP_TO_MSP  __asm volatile("mrs r0,control  \n\t mov r1 ,#0x05 \n\t and r0,r0 ,r1 \n\t msr control ,r0 ")

//clear bit 0 in control register
#define OS_SWITCH_TO_PRIVILEGED  __asm volatile(" mrs r3,control  \n\t"\
										"lsr r3 ,r3,#0x01 \n\t "\
										"lsl r3 ,r3,#0x01 \n\t "\
										"msr control ,r3 ");
//set bit 0 in control register
#define OS_SWITCH_TO_UNPRIVILEGED  __asm volatile(" mrs r3,control  \n\t"\
										"orr r3 ,r3,#0x01 \n\t "\
										"msr control ,r3 ");



void trigger_OS_PendSV(void);
void HW_Init();
void Start_Ticker();
void Stop_Ticker(void);



#endif /* INC_CORTEXMX_OSPORTING_H_ */
