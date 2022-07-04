/*
 * uart.c
 *
 *  Created on: 30-Jun-2022
 *      Author: SRUJAN
 */


#include <string.h>
#include "uart.h"

void uart2_config(void){
	RCC_APB1ENR |= (1<<17); //Enable UART clk
	RCC_AHB1ENR |= (1<<0);  //Enable GPIO A

	GPIOA_MODER |= (2<<4); //Alternate function for PA2
	GPIOA_MODER |= (2<<6); //Alternate function for PA3

	GPIOA_OSPEEDR |= (3<<4) | (3<<6); //High speed for pin2 and 3;

	GPIOA_AFRL |= (7<<8); //Alternate AF7(usart2) for pin2
	GPIOA_AFRL |= (7<<12); //Alternate AF8(usart2) for pin2

	USART2_CR1 = 0x00;
	USART2_CR1 |= (1<<13); //usart enable
	USART2_CR1 &= ~(1<<12); //8-bit word length
	USART2_BRR = (3<<0) | (104<<4); //baud rate of 9600 at 16Mhz

	USART2_CR1 |= (1<<2); //rx enable
	USART2_CR1 |= (1<<3); //tx enable
}

void send_char(uint8_t data){
	USART2_DR = data;
	while(!(USART2_SR & (1<<6))); //Wait for tx complete
}


void send_string(char *str){
	for(int i=0;i<strlen(str);i++){
		send_char(str[i]);
	}
}

uint8_t get_char(){
	uint8_t temp;
	while(!(USART2_SR &(1<<5)));
	temp = USART2_DR;
	return temp;
}
