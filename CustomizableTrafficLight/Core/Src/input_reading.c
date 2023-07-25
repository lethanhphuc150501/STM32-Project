/*
 * input_reading.c
 *
 *  Created on: Jul 25, 2023
 *      Author: Phuc Le
 */

#include "input_reading.h"
#include "main.h"

#define NO_OF_BUTTONS					1

#define DURATION_FOR_AUTO_INCREASING	100
#define BUTTON_IS_PRESSED				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED				GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBufer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBufer2[NO_OF_BUTTONS];
static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
static uint16_t conuterForButtonPress1s[NO_OF_BUTTONS];

void button_reading(void)
{
	for (char i = 0; i < NO_OF_BUTTONS; i++)
	{
		debounceButtonBufer2[i] = debounceButtonBufer1[i];
		debounceButtonBufer1[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);

		if (debounceButtonBufer1[i] == debounceButtonBufer2[i])
			buttonBuffer[i] = debounceButtonBufer1[i];
		if (buttonBuffer[i] == BUTTON_IS_PRESSED)
		{

		}
	}
}
