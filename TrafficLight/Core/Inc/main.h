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
#define LED7_0_Pin GPIO_PIN_0
#define LED7_0_GPIO_Port GPIOB
#define LED7_1_Pin GPIO_PIN_1
#define LED7_1_GPIO_Port GPIOB
#define LED7_2_Pin GPIO_PIN_2
#define LED7_2_GPIO_Port GPIOB
#define LED7_EN0_Pin GPIO_PIN_10
#define LED7_EN0_GPIO_Port GPIOB
#define LED7_EN1_Pin GPIO_PIN_11
#define LED7_EN1_GPIO_Port GPIOB
#define LED7_EN2_Pin GPIO_PIN_12
#define LED7_EN2_GPIO_Port GPIOB
#define LED7_EN3_Pin GPIO_PIN_13
#define LED7_EN3_GPIO_Port GPIOB
#define R1_Pin GPIO_PIN_10
#define R1_GPIO_Port GPIOA
#define Y1_Pin GPIO_PIN_11
#define Y1_GPIO_Port GPIOA
#define G1_Pin GPIO_PIN_12
#define G1_GPIO_Port GPIOA
#define R2_Pin GPIO_PIN_13
#define R2_GPIO_Port GPIOA
#define Y2_Pin GPIO_PIN_14
#define Y2_GPIO_Port GPIOA
#define G2_Pin GPIO_PIN_15
#define G2_GPIO_Port GPIOA
#define LED7_3_Pin GPIO_PIN_3
#define LED7_3_GPIO_Port GPIOB
#define LED7_4_Pin GPIO_PIN_4
#define LED7_4_GPIO_Port GPIOB
#define LED7_5_Pin GPIO_PIN_5
#define LED7_5_GPIO_Port GPIOB
#define LED7_6_Pin GPIO_PIN_6
#define LED7_6_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
