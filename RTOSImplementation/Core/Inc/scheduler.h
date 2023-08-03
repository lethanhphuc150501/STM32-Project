/*
 * scheduler.h
 *
 *  Created on: Jul 31, 2023
 *      Author: Phuc Le
 */

#ifndef __SCHEDULER_H_
#define __SCHEDULER_H_

#include "stdint.h"
#include "main.h"
#include "global.h"

// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS		10
#define NO_TASK_ID			0

#define TICKS				10

typedef struct {
	// Pointer to the task (must be a 'void (void)' function)
	void (* pTask)(void);
	// Delay (ticks) until the function will (next) be run
	int32_t Delay;
	// Interval (ticks) between subsequent runs.
	int32_t Period;
	// Incremented (by scheduler) when task is due to execute
	int8_t RunMe;
	uint32_t TaskID;
} sTask;

extern sTask SCH_tasks_G[SCH_MAX_TASKS];
// extern unsigned char Error_code_G;

void SCH_Init(void);
void SCH_Update(void);
unsigned char SCH_Add_Task(void (* pFunction) (), unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks(void);

#endif /* INC_SCHEDULER_H_ */
