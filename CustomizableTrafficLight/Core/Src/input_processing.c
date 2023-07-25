/*
 * input_processing.c
 *
 *  Created on: Jul 25, 2023
 *      Author: Phuc Le
 */

#include "input_processing.h"
#include "main.h"
#include "input_reading.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState buttonState = BUTTON_RELEASED;

void fsm_for_input_processing(void)
{
  switch(buttonState)
  {
    case BUTTON_RELEASED:
      if (is_button_pressed(0))
      {
        buttonState = BUTTON_PRESSED;
      }
      break;
    case BUTTON_PRESSED:
      if (!is_button_pressed(0))
      {
        buttonState = BUTTON_RELEASED;
      }
      else
      {
        if (is_button_pressed_1s(0))
        {
          buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND;
        }
      }
      break;
    case BUTTON_PRESSED_MORE_THAN_1_SECOND:
      if (!is_button_pressed(0))
      {
        buttonState = BUTTON_RELEASED;
      }
      break;
  }
}
