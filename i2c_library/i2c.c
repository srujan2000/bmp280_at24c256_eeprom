/*
 * i2c.c
 *
 *  Created on: Jun 27, 2022
 *      Author: SRUJAN
 */


#include "i2c.h"

void config_clk(void){
	RCC_AHB1_ENR |= (1<<1);  //enable GPIOB
	RCC_APB1_ENR |= (1<<21); //enable I2C1
}


void config_gpio(){
    GPIOB_MODER  |= (2<<18) | (2<<16); //alternate mode for pin 9 and 8
//    GPIOB_MODER= ~((1<<9)|(1<<8));

    GPIOB_OTYPER |= (1<<9) | (1<<8); //open drain

    GPIOB_OSPEED |= (3<<18) | (3<<16); // high speed

    GPIOB_PUDR   |= (1<<18) | (1<<16); //pull-up

    GPIOB_AFRH = 0x00000044UL;
}

void config_i2c(){
	 I2C_CR1 |=  (1<<15); //reset
     I2C_CR1 &= ~(1<<15);

     I2C_CR2 |= (16<<0); //f_clk 16Mhz
     //CCR Calculation
     //CCR = (fclk/2)*SCL
     //CCR = (16Mhz/2*100khz)=80

     I2C_CCR |= 80<<0; //i2c-100khz
     I2C_TRISE = 17;

     I2C_CR1 |= (1<<0); // I2C enable
}

void i2c_start(){
    I2C_CR1 |= (1<<8); //i2c start
    while(!(I2C_SR1 & (1<<0))); //wait till start bit is set
}

void i2c_stop(){
   I2C_CR1 |= (1<<9);//i2c stop
}

void i2c_address(uint8_t addr){
    I2C_DR = addr;
    while(!(I2C_SR1 & (1<<1))); //wait till address bit is set
    uint32_t temp = I2C_SR1 | I2C_SR2;
}

void i2c_write(uint8_t data){
	while(!(I2C_SR1 & (1<<7)));//wait till data register is empty
	I2C_DR = data;
	while(!(I2C_SR1 & (1<<2)));//wait till byte transfer is complete
}
