/*
 * sw_timer.h
 *
 *  Created on: Aug 6, 2023
 *      Author: HP
 */

#ifndef __SW_TIMER_H_
#define __SW_TIMER_H_

#define TIMER_CYCLE		10

void timer_run();
void setTimer0(int duration);
unsigned char getTimer0Flag();

void setTimer1(int duration);
unsigned char getTimer1Flag();

#endif /* INC_SW_TIMER_H_ */
