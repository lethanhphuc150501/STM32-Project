/*
 * scheduler.c
 *
 *  Created on: Jul 31, 2023
 *      Author: Phuc Le
 */

#include "scheduler.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];

unsigned char cur_no_tasks = 0;


//unsigned char Error_code_G = 0;

unsigned char SCH_Delete_Task(const unsigned char TASK_INDEX) {
	unsigned char Return_code = 0;
	if (SCH_tasks_G[TASK_INDEX].pTask == 0) {
		// No task at this location...
		// Set the global error variable
		// Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
		// ...also return an error code
		Return_code = 1;
	} else {
		Return_code = 0;
	}
	for (int i = TASK_INDEX + 1; i < SCH_MAX_TASKS; i++) {
		if (!(SCH_tasks_G[i].pTask)) break;
		SCH_tasks_G[i-1] = SCH_tasks_G[i];
	}
	cur_no_tasks--;
	SCH_tasks_G[cur_no_tasks].pTask = 0x0000;
	SCH_tasks_G[cur_no_tasks].Delay = 0;
	SCH_tasks_G[cur_no_tasks].Period = 0;
	SCH_tasks_G[cur_no_tasks].RunMe = 0;
	//SCH_tasks_G[TASK_INDEX].Offset = 0;

	return Return_code;	// return status
}

void SCH_Init(void) {
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASKS; i++) {
		SCH_Delete_Task(i);
	}
	cur_no_tasks = 0;
	// Reset the global error variable
	// - SCH_Delete_Task() will generate an error code,
	// (because the task array is empty)
	//Error_code_G = 0;
	//Timer_init();
	//Watchdog_init();
}

void SCH_Update(void) {
	if (SCH_tasks_G[0].pTask) {
		// Not yet ready to run: just decrement the delay
		SCH_tasks_G[0].Delay -= 1;
		// Check if there is a task at this location
		if (SCH_tasks_G[0].Delay <= 0) { // || SCH_tasks_G[0].Delay <= SCH_tasks_G[0].Offset) {
			// The task is due to run
			// Increase the 'RunMe' flag
			SCH_tasks_G[0].RunMe += 1;
			//SCH_tasks_G[0].Offset = 0;
			if (SCH_tasks_G[0].Period) {
				// Schedule periodic tasks to run again
				SCH_tasks_G[0].Delay = SCH_tasks_G[0].Period;
			}
		}
	}

	/*
	unsigned char Index;
	// NOTE: calculations are in *TICKS* (not milliseconds)
	for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
		// Check if there is a task at this location
		if (SCH_tasks_G[Index].pTask) {
			if (SCH_tasks_G[Index].Delay <= 0) {
				// The task is due to run
				// Increase the 'RunMe' flag
				SCH_tasks_G[Index].RunMe += 1;
				if (SCH_tasks_G[Index].Period) {
					// Schedule periodic tasks to run again
					SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
				}
			} else {
				// Not yet ready to run: just decrement the delay
				SCH_tasks_G[Index].Delay -= 1;
			}
		}
	}
	*/
}

/* SCH_Add_Task() function
 * @brief	Causes a task (function) to be executed at regular intervals
 * 			or after a user-defined delay
 * @param	pFunction - the name of the task that user wish to schedule
 * @param	DELAY - the delay (in ticks) before task is first executed
 * @param	PERIOD - the interval (in ticks) between repeated executions
 * 			of the task
 * @retval	TaskID
 */
unsigned char SCH_Add_Task(void (* pFunction) (), unsigned int DELAY, unsigned int PERIOD) {
	// Task structure is overload
	if (cur_no_tasks >= SCH_MAX_TASKS) {
		return SCH_MAX_TASKS;
	}

	unsigned int DELAY_CNT = DELAY / TICKS;
	unsigned int PERIOD_CNT = PERIOD / TICKS;

	// Task structure is available
	unsigned char Index = 0;
	unsigned int sum_delay = 0;
	for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if (!(SCH_tasks_G[Index].pTask)) break;
		if (sum_delay + SCH_tasks_G[Index].Delay > DELAY_CNT) break;
		sum_delay += SCH_tasks_G[Index].Delay;
	}
	// Index - the position want to add

	// Shift other position after Index
	for (int i = SCH_MAX_TASKS - 2; i >= 0; i--) {
		if (i < Index) break;
		if (!(SCH_tasks_G[Index].pTask)) continue;
		SCH_tasks_G[i+1] = SCH_tasks_G[i];
	}
	//if (DELAY_CNT == sum_delay) SCH_tasks_G[Index+1].Offset += 1;
	//else SCH_tasks_G[Index+1].Delay -= (DELAY_CNT - sum_delay);
	SCH_tasks_G[Index+1].Delay -= (DELAY_CNT - sum_delay);
	// Assign Index position
	SCH_tasks_G[Index].pTask = pFunction;
	SCH_tasks_G[Index].Delay = DELAY_CNT - sum_delay;
	SCH_tasks_G[Index].Period = PERIOD_CNT;
	SCH_tasks_G[Index].RunMe = 0;

	// Increase number of tasks
	cur_no_tasks++;
	return Index;
	/*
	unsigned char Index = 0;
	//First find a gap in the array (if there is one)
	while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)) {
		Index++;
	}
	// Have we reached the end of the list?
	if (Index == SCH_MAX_TASKS) {
		// Task list is full
		// Set the global error variable
		// Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		// Also return an error code
		return SCH_MAX_TASKS;
	}
	// If we're here, there is a space in task array
	SCH_tasks_G[Index].pTask = pFunction;
	SCH_tasks_G[Index].Delay = DELAY / TICKS;
	SCH_tasks_G[Index].Period = PERIOD / TICKS;
	SCH_tasks_G[Index].RunMe = 0;
	// return position of task (to allow later deletion)
	return Index;
	*/
}

void SCH_Dispatch_Tasks(void) {
	if (SCH_tasks_G[0].RunMe > 0 || SCH_tasks_G[0].Delay <= 0) {
		int diff = time_stamp;
		(* SCH_tasks_G[0].pTask)();	// Run the task

		if (SCH_tasks_G[0].RunMe > 0) SCH_tasks_G[0].RunMe -= 1;	// Reset/reduce RunMe flag
		// Periodic tasks will automatically run again
		// - if this is a 'one shot' task, remove it from the array
		if (SCH_tasks_G[0].Period == 0) {
			SCH_Delete_Task(0);
		} else if (SCH_tasks_G[0].RunMe <= 0 && cur_no_tasks > 1) {
			SCH_tasks_G[0].Delay = SCH_tasks_G[0].Period;
			sTask expired_task = SCH_tasks_G[0];
			for (int i = 1; i < SCH_MAX_TASKS; i++) {
				if (!(SCH_tasks_G[i].pTask)) {
					//sbSCH_tasks_G[i].Offset += 1;
					break;
				}
				if (expired_task.Delay >= SCH_tasks_G[i].Delay) {
					expired_task.Delay -= SCH_tasks_G[i].Delay;
					//if (SCH_tasks_G[i].Delay == 0) expired_task.Offset += 1;
					SCH_tasks_G[i-1] = SCH_tasks_G[i];
					SCH_tasks_G[i] = expired_task;
				} else {
					SCH_tasks_G[i].Delay -= expired_task.Delay;
					//if (expired_task.Delay == 0) SCH_tasks_G[i].Offset += 1;
					break;
				}
			}
		}
		diff = time_stamp - diff;
		time_offset += diff;
		if (SCH_tasks_G[0].Delay - time_offset > 0) {
			SCH_tasks_G[0].Delay -= time_offset;
			time_offset = 0;
		} else {
			time_offset -= SCH_tasks_G[0].Delay;
			SCH_tasks_G[0].Delay = 0;
		}
	}
	/*
	for (int i = 0; i < SCH_MAX_TASKS; i++) {
		if (!(SCH_tasks_G[i].pTask)) break;
		HAL_UART_Transmit(&huart2, (uint8_t *)data, sprintf(data, "Task array: %ld - Runme: %d\r\n", SCH_tasks_G[i].Delay, SCH_tasks_G[i].RunMe), 1000);
	}
	*/
	/*
	unsigned char Index;
	// Dispatches (runs) the next task (if one is ready)
	for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if (SCH_tasks_G[Index].RunMe > 0) {
			(* SCH_tasks_G[Index].pTask)();	// Run the task
			SCH_tasks_G[Index].RunMe -= 1;	// Reset/reduce RunMe flag
			// Peridic tasks will automatically run again
			// - if this is a 'one shot' task, remove it from the array
			if (SCH_tasks_G[Index].Period == 0) {
				SCH_Delete_Task(Index);
			}
		}
	}
	// Report system status
	//SCH_Report_Status();
	// The scheduler enters idle mode at this point
	//SCH_Go_To_Sleep();
	*/
}

/*
void SCH_Go_To_Sleep() {
	// TO DO: Optional
}

void SCH_Report_Status(void) {
#ifdef SCH_REPORT_ERRORS
	// ONLY APPLIES IF WE ARE REPORTING ERRORS
	// Check for a new error code
	if (Error_code_G != Last_error_code_G)) {
		Error_port = 255 - Error_code_G;
		if (Error_code_G != 0) {
			Error_tick_count_G = 60000;
		} else {
			Error_tick_count_G = 0;
		}
	} else {
		if (Error_tick_count_G != 0) {
			if (--Error_tick_count_G == 0) {
				Error_code_G = 0;	// Reset error code
			}
		}
	}
#endif
}
*/
