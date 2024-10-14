/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define A1_Pin GPIO_PIN_0
#define A1_GPIO_Port GPIOC
#define A2_Pin GPIO_PIN_1
#define A2_GPIO_Port GPIOC
#define A4_Pin GPIO_PIN_2
#define A4_GPIO_Port GPIOC
#define A3_Pin GPIO_PIN_3
#define A3_GPIO_Port GPIOC
#define B1_Pin GPIO_PIN_1
#define B1_GPIO_Port GPIOA
#define RST_Pin GPIO_PIN_2
#define RST_GPIO_Port GPIOA
#define DC_Pin GPIO_PIN_3
#define DC_GPIO_Port GPIOA
#define B2_Pin GPIO_PIN_4
#define B2_GPIO_Port GPIOC
#define B3_Pin GPIO_PIN_5
#define B3_GPIO_Port GPIOC
#define B4_Pin GPIO_PIN_0
#define B4_GPIO_Port GPIOB
#define C1_Pin GPIO_PIN_1
#define C1_GPIO_Port GPIOB
#define C2_Pin GPIO_PIN_2
#define C2_GPIO_Port GPIOB
#define DECODE2_CLK_Pin GPIO_PIN_6
#define DECODE2_CLK_GPIO_Port GPIOC
#define DECODE2_DT_Pin GPIO_PIN_7
#define DECODE2_DT_GPIO_Port GPIOC
#define DECODE_2_WS_Pin GPIO_PIN_8
#define DECODE_2_WS_GPIO_Port GPIOC
#define DECODE_1_WS_Pin GPIO_PIN_9
#define DECODE_1_WS_GPIO_Port GPIOC
#define DECODE1_CLK_Pin GPIO_PIN_8
#define DECODE1_CLK_GPIO_Port GPIOA
#define DECODE1_DT_Pin GPIO_PIN_9
#define DECODE1_DT_GPIO_Port GPIOA
#define C3_Pin GPIO_PIN_12
#define C3_GPIO_Port GPIOC
#define C4_Pin GPIO_PIN_2
#define C4_GPIO_Port GPIOD
#define D1_Pin GPIO_PIN_3
#define D1_GPIO_Port GPIOB
#define D2_Pin GPIO_PIN_4
#define D2_GPIO_Port GPIOB
#define D3_Pin GPIO_PIN_5
#define D3_GPIO_Port GPIOB
#define D4_Pin GPIO_PIN_9
#define D4_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
