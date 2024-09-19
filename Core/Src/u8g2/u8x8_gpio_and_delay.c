#include "u8g2.h"
#include "stm32f4xx_hal.h"

extern SPI_HandleTypeDef hspi1;

uint8_t u8x8_byte_4wire_hw_spi(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int,
                               void *arg_ptr)
{
  switch (msg)
  {
    case U8X8_MSG_BYTE_SEND:
      HAL_SPI_Transmit(&hspi1, (uint8_t *) arg_ptr, arg_int, 10000);
      break;
    case U8X8_MSG_BYTE_INIT:
      break;
    case U8X8_MSG_BYTE_SET_DC:
      HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, arg_int);
      break;
    case U8X8_MSG_BYTE_START_TRANSFER:
      break;
    case U8X8_MSG_BYTE_END_TRANSFER:
      break;
    default:
      return 0;
  }
  return 1;
}

uint8_t u8x8_stm32_gpio_and_delay(U8X8_UNUSED u8x8_t *u8x8,
                                  U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int,
                                  U8X8_UNUSED void *arg_ptr)
{
  switch (msg)
  {
    case U8X8_MSG_GPIO_AND_DELAY_INIT:
      HAL_Delay(1);
      break;
    case U8X8_MSG_DELAY_MILLI:
      HAL_Delay(arg_int);
      break;
    case U8X8_MSG_GPIO_DC:
      HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, arg_int);
      break;
    case U8X8_MSG_GPIO_RESET:
      HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, arg_int);
      break;
  }
  return 1;
}

