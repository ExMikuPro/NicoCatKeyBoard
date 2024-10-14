/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ws2812/ws2812.h"
#include "u8g2/u8g2.h"
#include "usart.h"
#include "crc.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

int button_pin[] = {A1_Pin, A2_Pin, A3_Pin, A4_Pin, B1_Pin, B2_Pin, B3_Pin, B4_Pin, C1_Pin, C2_Pin, C3_Pin, C4_Pin,
                    D1_Pin, D2_Pin, D3_Pin, D4_Pin};
GPIO_TypeDef *button_port[] = {A1_GPIO_Port, A2_GPIO_Port, A3_GPIO_Port, A4_GPIO_Port, B1_GPIO_Port, B2_GPIO_Port,
                               B3_GPIO_Port, B4_GPIO_Port,
                               C1_GPIO_Port, C2_GPIO_Port, C3_GPIO_Port, C4_GPIO_Port, D1_GPIO_Port, D2_GPIO_Port,
                               D3_GPIO_Port, D4_GPIO_Port};

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId Button_StateHandle;
osThreadId Line1Handle;
osThreadId Line2Handle;
osThreadId Line3Handle;
osThreadId Line4Handle;
osThreadId displayHandle;
osThreadId usartHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const *argument);

void State(void const *argument);

void Line1_RGB(void const *argument);

void Line2_RGB(void const *argument);

void Line3_RGB(void const *argument);

void Line4_RGB(void const *argument);

void Display(void const *argument);

void Usart_Content(void const *argument);

extern void MX_USB_DEVICE_Init(void);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer,
                                   uint32_t *pulIdleTaskStackSize);

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer,
                                   uint32_t *pulIdleTaskStackSize) {
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of Button_State */
  osThreadDef(Button_State, State, osPriorityIdle, 0, 128);
  Button_StateHandle = osThreadCreate(osThread(Button_State), NULL);

  /* definition and creation of Line1 */
  osThreadDef(Line1, Line1_RGB, osPriorityIdle, 0, 128);
  Line1Handle = osThreadCreate(osThread(Line1), NULL);

  /* definition and creation of Line2 */
  osThreadDef(Line2, Line2_RGB, osPriorityIdle, 0, 128);
  Line2Handle = osThreadCreate(osThread(Line2), NULL);

  /* definition and creation of Line3 */
  osThreadDef(Line3, Line3_RGB, osPriorityIdle, 0, 128);
  Line3Handle = osThreadCreate(osThread(Line3), NULL);

  /* definition and creation of Line4 */
  osThreadDef(Line4, Line4_RGB, osPriorityIdle, 0, 128);
  Line4Handle = osThreadCreate(osThread(Line4), NULL);

  /* definition and creation of display */
  osThreadDef(display, Display, osPriorityIdle, 0, 128);
  displayHandle = osThreadCreate(osThread(display), NULL);

  /* definition and creation of usart */
  osThreadDef(usart, Usart_Content, osPriorityIdle, 0, 128);
  usartHandle = osThreadCreate(osThread(usart), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const *argument) {
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for (;;) {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_State */
/**
* @brief Function implementing the Button_State thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_State */
__weak void State(void const *argument) {
  /* USER CODE BEGIN State */
  /* Infinite loop */
  for (;;) {

  }
  /* USER CODE END State */
}

/* USER CODE BEGIN Header_Line1_RGB */
/**
* @brief Function implementing the Line1 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Line1_RGB */
__weak void Line1_RGB(void const *argument) {
  /* USER CODE BEGIN Line1_RGB */
  /* Infinite loop */
  for (;;) {
    if (HAL_GPIO_ReadPin(A1_GPIO_Port, A1_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(3, 0xFF, 0x86, 0x86);
      HAL_UART_Transmit(&huart1, (const uint8_t *) 0xA1, 8, 0xFFFF);
    } else {
      WS2812B_User_Task(3, 0x00, 0x00, 0x00);
    }
    if (HAL_GPIO_ReadPin(A2_GPIO_Port, A2_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(2, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(2, 0x00, 0x00, 0x00);
    }
    if (HAL_GPIO_ReadPin(A3_GPIO_Port, A3_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(1, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(1, 0x00, 0x00, 0x00);
    }
    if (HAL_GPIO_ReadPin(A4_GPIO_Port, A4_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(0, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(0, 0x00, 0x00, 0x00);
    }
    WS2812_Send_Data();
  }
  /* USER CODE END Line1_RGB */
}

/* USER CODE BEGIN Header_Line2_RGB */
/**
* @brief Function implementing the Line2 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Line2_RGB */
__weak void Line2_RGB(void const *argument) {
  /* USER CODE BEGIN Line2_RGB */
  /* Infinite loop */
  for (;;) {
    if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(7, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(7, 0x00, 0x00, 0x00);
    }
    if (HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(6, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(6, 0x00, 0x00, 0x00);
    }
    if (HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(5, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(5, 0x00, 0x00, 0x00);
    }
    if (HAL_GPIO_ReadPin(B4_GPIO_Port, B4_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(4, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(4, 0x00, 0x00, 0x00);
    }
    WS2812_Send_Data();
  }
  /* USER CODE END Line2_RGB */
}

/* USER CODE BEGIN Header_Line3_RGB */
/**
* @brief Function implementing the Line3 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Line3_RGB */
__weak void Line3_RGB(void const *argument) {
  /* USER CODE BEGIN Line3_RGB */
  /* Infinite loop */
  for (;;) {
    if (HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(11, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(11, 0x00, 0x00, 0x00);
    }
    if (HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(10, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(10, 0x00, 0x00, 0x00);
    }
    if (HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(9, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(9, 0x00, 0x00, 0x00);
    }
    if (HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(8, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(8, 0x00, 0x00, 0x00);
    }
    WS2812_Send_Data();
  }
  /* USER CODE END Line3_RGB */
}

/* USER CODE BEGIN Header_Line4_RGB */
/**
* @brief Function implementing the Line4 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Line4_RGB */
__weak void Line4_RGB(void const *argument) {
  /* USER CODE BEGIN Line4_RGB */
  /* Infinite loop */
  for (;;) {
    if (HAL_GPIO_ReadPin(D1_GPIO_Port, D1_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(15, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(15, 0x00, 0x00, 0x00);
    }
    if (HAL_GPIO_ReadPin(D2_GPIO_Port, D2_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(14, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(14, 0x00, 0x00, 0x00);
    }
    if (HAL_GPIO_ReadPin(D3_GPIO_Port, D3_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(13, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(13, 0x00, 0x00, 0x00);
    }
    if (HAL_GPIO_ReadPin(D4_GPIO_Port, D4_Pin) == GPIO_PIN_RESET) {
      WS2812B_User_Task(12, 0xFF, 0x86, 0x86);
    } else {
      WS2812B_User_Task(12, 0x00, 0x00, 0x00);
    }
    WS2812_Send_Data();
  }

  /* USER CODE END Line4_RGB */
}

/* USER CODE BEGIN Header_Display */
/**
* @brief Function implementing the display thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Display */
__weak void Display(void const *argument) {
  /* USER CODE BEGIN Display */
  static u8g2_t u8g2;
  u8g2Init(&u8g2);
  u8g2_SetFont(&u8g2, u8g2_font_10x20_me);
  u8g2_DrawStr(&u8g2, 30, 70, "NicoCat");
  u8g2_SendBuffer(&u8g2);

  /* Infinite loop */
  for (;;) {
    osDelay(1);
  }
  /* USER CODE END Display */
}

/* USER CODE BEGIN Header_Usart_Content */
/**
* @brief Function implementing the usart thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Usart_Content */
__weak void Usart_Content(void const *argument) {
  /* USER CODE BEGIN Usart_Content */
  /* Infinite loop */
  for (;;) {
    uint8_t data[10] = {0xff, 0x01, 0xac, 0xfe};
//    HAL_UART_Transmit(&huart1, data, sizeof data, 0xFFFF);
    osDelay(500);
  }
  /* USER CODE END Usart_Content */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
