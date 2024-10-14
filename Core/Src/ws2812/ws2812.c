//
// Created by Hatsune Miku on 2024/10/12.
//

#include "ws2812.h"
#include "spi.h"

//灯条显存SPI数据缓存
uint8_t gWs2812bDat_SPI[WS2812B_AMOUNT * 24] = {0};
//灯条显存
tWs2812bCache_TypeDef gWs2812bDat[WS2812B_AMOUNT] = {
//R    G      B
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
    0X00, 0X00, 0X00,  //0
};

void WS2812b_Set(uint16_t Ws2b812b_NUM, uint8_t r, uint8_t g, uint8_t b) {
  uint8_t *pR = &gWs2812bDat_SPI[(Ws2b812b_NUM) * 24 + 8];
  uint8_t *pG = &gWs2812bDat_SPI[(Ws2b812b_NUM) * 24];
  uint8_t *pB = &gWs2812bDat_SPI[(Ws2b812b_NUM) * 24 + 16];

  for (uint8_t i = 0; i < 8; i++) {
    if (g & 0x80) {
      *pG = CODE_1;
    } else {
      *pG = CODE_0;
    }
    if (r & 0x80) {
      *pR = CODE_1;
    } else {
      *pR = CODE_0;
    }
    if (b & 0x80) {
      *pB = CODE_1;
    } else {
      *pB = CODE_0;
    }
    r <<= 1;
    g <<= 1;
    b <<= 1;
    pR++;
    pG++;
    pB++;
  }
}

void WS2812B_Task(void) {
  uint8_t dat = 0;

  //将gWs2812bDat数据解析成SPI数据
  for (uint8_t iLED = 0; iLED < WS2812B_AMOUNT; iLED++) {
    WS2812b_Set(iLED, gWs2812bDat[iLED].R, gWs2812bDat[iLED].G, gWs2812bDat[iLED].B);
  }
  //总线输出数据
  HAL_SPI_Transmit(&hspi2, gWs2812bDat_SPI, sizeof(gWs2812bDat_SPI), 0XFFFF);
  //使总线输出低电平
  HAL_SPI_Transmit(&hspi2, &dat, 1, 0XFFFF);
  //帧信号：一个大于50us的低电平
  HAL_Delay(1);
}

void WS2812B_User_Task(uint16_t Ws2b812b_NUM, uint8_t r, uint8_t g, uint8_t b) {
  //将gWs2812bDat数据解析成SPI数据
  WS2812b_Set(Ws2b812b_NUM, r, g, b);
}

void WS2812_Send_Data() {
  uint8_t dat = 0;
  HAL_SPI_Transmit(&hspi2, gWs2812bDat_SPI, sizeof(gWs2812bDat_SPI), 0XFFFF);
  //使总线输出低电平
  HAL_SPI_Transmit(&hspi2, &dat, 1, 0XFFFF);
  //帧信号：一个大于50us的低电平
  HAL_Delay(1);
}


