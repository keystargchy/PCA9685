#include "rgb.h"
#include "math.h"



uint8_t empty = 0x0;


// num为通道数(0-15个通道)
// on固定从0开始即可
// off为占空比调节量(0-4095)
void PcaSetpwm(uint8_t num, uint32_t on, uint32_t off)
{
	uint8_t on_l = on;
	uint8_t on_h = on>>8;
	uint8_t off_l = off;
	uint8_t off_h = off>>8;
	HAL_I2C_Mem_Write(&hi2c1,PCA_ADDR_W,LED0_ON_L+4*num,I2C_MEMADD_SIZE_8BIT,&on_l,1,0xffff);
	HAL_I2C_Mem_Write(&hi2c1,PCA_ADDR_W,LED0_ON_H+4*num,I2C_MEMADD_SIZE_8BIT,&on_h,1,0xffff);
	HAL_I2C_Mem_Write(&hi2c1,PCA_ADDR_W,LED0_OFF_L+4*num,I2C_MEMADD_SIZE_8BIT,&off_l,1,0xffff);
	HAL_I2C_Mem_Write(&hi2c1,PCA_ADDR_W,LED0_OFF_H+4*num,I2C_MEMADD_SIZE_8BIT,&off_h,1,0xffff);
}

uint8_t prescale,oldmode,newmode;
float prescaleval,freq;
void PcaSetFreq(void)
{

	
	freq = 70.f;   //灯亮的频率，70HZ就已经闪的肉眼分辨不出来了
	prescaleval = 25000000.f;
	prescaleval /= 4096.f;
	prescaleval /= freq;
	prescaleval -= 1;
	prescale = floor(prescaleval + 0.5f);
	
	HAL_I2C_Mem_Read(&hi2c1,PCA_ADDR_R,PCA_MODE1,I2C_MEMADD_SIZE_8BIT,&oldmode,1,0xffff);
	
	newmode = (oldmode&0x7f) | 0x10;
	HAL_I2C_Mem_Write(&hi2c1,PCA_ADDR_W,PCA_MODE1,I2C_MEMADD_SIZE_8BIT,&newmode,1,0xffff);
	HAL_I2C_Mem_Write(&hi2c1,PCA_ADDR_W,PCA_PRE,I2C_MEMADD_SIZE_8BIT,&prescale,1,0xffff);
	HAL_I2C_Mem_Write(&hi2c1,PCA_ADDR_W,PCA_MODE1,I2C_MEMADD_SIZE_8BIT,&oldmode,1,0xffff);
	HAL_Delay(2);
	oldmode = oldmode | 0xa1;
	HAL_I2C_Mem_Write(&hi2c1,PCA_ADDR_W,PCA_MODE1,I2C_MEMADD_SIZE_8BIT,&oldmode,1,0xffff);
	
}

void RgbInit(void)
{
	HAL_I2C_Mem_Write(&hi2c1,PCA_ADDR_W,PCA_MODE1,I2C_MEMADD_SIZE_8BIT,&empty,1,0xffff);
	PcaSetFreq();
	PcaSetpwm(1,0,2048);
	PcaSetpwm(2,0,0);
	PcaSetpwm(3,0,0);
	PcaSetpwm(4,0,0);
	PcaSetpwm(5,0,0);
	PcaSetpwm(6,0,0);
	PcaSetpwm(7,0,0);
	PcaSetpwm(8,0,0);
	PcaSetpwm(9,0,0);
	PcaSetpwm(10,0,0);
	PcaSetpwm(11,0,0);
	PcaSetpwm(12,0,0);
	PcaSetpwm(13,0,0);
	PcaSetpwm(14,0,0);
	PcaSetpwm(15,0,0);
	HAL_Delay(500);
	
	
	
}
















