/*
 * input_reading.h
 *
 *  Created on: Jul 25, 2023
 *      Author: Phuc Le
 */

#ifndef __INPUT_READING_H_
#define __INPUT_READING_H_

#include "main.h"
#include "timer.h"

void init_buffer();
void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);
unsigned char is_button_held(unsigned char index);
void reset_flagForButtonHold(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
