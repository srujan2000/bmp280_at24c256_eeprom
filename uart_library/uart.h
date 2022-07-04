/*
 * uart.h
 *
 *  Created on: 30-Jun-2022
 *      Author: SRUJAN
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>

#define RCC_AHB1ENR   *((volatile uint32_t*)0x40023830)
#define RCC_APB1ENR   *((volatile uint32_t*)0x40023840)

#define GPIOA_MODER	  *((volatile uint32_t*)0x40020000)
#define GPIOA_OSPEEDR *((volatile uint32_t*)0x40020008)
#define GPIOA_AFRL	  *((volatile uint32_t*)0x40020020)

#define USART2_CR1    *((volatile uint32_t*)0x4000440C)
#define USART2_BRR	  *((volatile uint32_t*)0x40004408)
#define USART2_SR     *((volatile uint32_t*)0x40004400)
#define USART2_DR     *((volatile uint32_t*)0x40004404)

void uart2_config(void);
void send_char(uint8_t);
void send_string(char*);
uint8_t get_char(void);


#endif /* UART_H_ */
