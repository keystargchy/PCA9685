#ifndef __RGB_H
#define __RGB_H
#include "stm32f4xx_hal.h"
#include "i2c.h"

#define PCA_ADDR_W 0xaa  //Ð¾Æ¬Ð´µØÖ·Îª 1010 1010
#define PCA_ADDR_R 0xab  //Ð¾Æ¬¶ÁµØÖ·Îª 1010 1011


#define PCA_MODE1 0x00
#define PCA_PRE  0xfe


#define LED0_ON_L 0x6
#define LED0_ON_H 0x7
#define LED0_OFF_L 0x8
#define LED0_OFF_H 0x9


void RgbInit(void);
void PcaSetFreq(void);
void PcaSetpwm(uint8_t num, uint32_t on, uint32_t off);













#endif




