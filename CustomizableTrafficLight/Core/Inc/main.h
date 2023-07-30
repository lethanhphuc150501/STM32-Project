/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SEG0_Pin GPIO_PIN_0
#define SEG0_GPIO_Port GPIOA
#define SEG1_Pin GPIO_PIN_1
#define SEG1_GPIO_Port GPIOA
#define SEG2_Pin GPIO_PIN_2
#define SEG2_GPIO_Port GPIOA
#define SEG3_Pin GPIO_PIN_3
#define SEG3_GPIO_Port GPIOA
#define SEG4_Pin GPIO_PIN_4
#define SEG4_GPIO_Port GPIOA
#define SEG5_Pin GPIO_PIN_5
#define SEG5_GPIO_Port GPIOA
#define SEG6_Pin GPIO_PIN_6
#define SEG6_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_7
#define LED_RED_GPIO_Port GPIOA
#define BUTTON_1_Pin GPIO_PIN_0
#define BUTTON_1_GPIO_Port GPIOB
#define BUTTON_2_Pin GPIO_PIN_1
#define BUTTON_2_GPIO_Port GPIOB
#define BUTTON_3_Pin GPIO_PIN_2
#define BUTTON_3_GPIO_Port GPIOB
#define G1_Pin GPIO_PIN_10
#define G1_GPIO_Port GPIOB
#define R2_Pin GPIO_PIN_11
#define R2_GPIO_Port GPIOB
#define Y2_Pin GPIO_PIN_12
#define Y2_GPIO_Port GPIOB
#define G2_Pin GPIO_PIN_13
#define G2_GPIO_Port GPIOB
#define EN0_Pin GPIO_PIN_8
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_9
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_10
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_11
#define EN3_GPIO_Port GPIOA
#define MODE_Pin GPIO_PIN_12
#define MODE_GPIO_Port GPIOA
#define R1_Pin GPIO_PIN_8
#define R1_GPIO_Port GPIOB
#define Y1_Pin GPIO_PIN_9
#define Y1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
