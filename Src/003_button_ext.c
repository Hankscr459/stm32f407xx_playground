/*
 * 002_button.c
 *
 *  Created on: 2026年4月5日
 *      Author: Hank
 */

#include "stm32f407xx.h"

#define HIGH 1
#define LOW 0
#define BTN_PRESSED LOW

void delay(void)
{
	for(uint32_t i = 0; i < 500000/2; i++);
}

int main(void)
{
	return 0;
}

