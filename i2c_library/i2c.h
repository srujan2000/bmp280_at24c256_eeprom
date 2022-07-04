/*
 * i2c.h
 *
 *  Created on: Jun 27, 2022
 *      Author: SRUJAN
 */

#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>

#define RCC_AHB1_ENR *((volatile uint32_t*)0x40023830)
#define RCC_APB1_ENR *((volatile uint32_t*)0x40023840)

#define GPIOB_MODER   *((volatile uint32_t*)0x40020400)
#define GPIOB_OTYPER  *((volatile uint32_t*)0x40020404)
#define GPIOB_OSPEED  *((volatile uint32_t*)0x40020408)
#define GPIOB_PUDR    *((volatile uint32_t*)0x4002040C)
#define GPIOB_AFRH    *((volatile uint32_t*)0x40020424)

#define I2C_CR1    *((volatile uint32_t*)0x40005400)
#define I2C_CR2    *((volatile uint32_t*)0x40005404)
#define I2C_DR     *((volatile uint32_t*)0x40005410)
#define I2C_SR1    *((volatile uint32_t*)0x40005414)
#define I2C_SR2    *((volatile uint32_t*)0x40005418)
#define I2C_CCR    *((volatile uint32_t*)0x4000541C)
#define I2C_TRISE  *((volatile uint32_t*)0x40005420)


void config_clk(void);
void config_gpio(void);
void config_i2c(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_address(uint8_t);
void i2c_write(uint8_t);


#endif /* I2C_H_ */
