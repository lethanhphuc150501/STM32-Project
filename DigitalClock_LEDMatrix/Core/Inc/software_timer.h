/*
 * software_timer.h
 *
 *  Created on: 16 Jul 2023
 *      Author: HP
 */

#ifndef __SOFTWARE_TIMER_H_
#define __SOFTWARE_TIMER_H_

void setTimer0 (int duration);
void setTimer1 (int duration);
void setTimer2 (int duration);
void setTimer3 (int duration);
void timer_run();
int getTimer0Flag();
int getTimer1Flag();
int getTimer2Flag();
int getTimer3Flag();

#endif /* INC_SOFTWARE_TIMER_H_ */
