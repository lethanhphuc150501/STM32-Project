/*
 * timer.h
 *
 *  Created on: Aug 3, 2023
 *      Author: Phuc Le
 */

#ifndef __TIMER_H_
#define __TIMER_H_

#define TIMER_CYCLE		10
extern unsigned char timer0_flag;

void setTimer0(int duration);
void timer_run();

#endif /* INC_TIMER_H_ */
