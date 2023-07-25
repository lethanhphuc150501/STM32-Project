/*
 * timer.c
 *
 *  Created on: Jul 25, 2023
 *      Author: Phuc Le
 */

#include "timer.h"
#include "main.h"
#include "input_reading.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  
  if (htim->Instance == htim2)
  {
    button_reading();
  }
}
