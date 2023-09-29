/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>
//register address
typedef volatile unsigned int vint32_t;


#define RCC_BASE	0x40021000

#define RCC_CR		*(vint32_t*) (RCC_BASE+0x0)
#define RCC_CFGR	*(vint32_t*) (RCC_BASE+0x04)
#define RCC_AHBRSTR	*(vint32_t*) (RCC_BASE+0x28)






int main(void)
{
	//Adjusting Prescaler AHB
	RCC_CFGR |= (0b0000 << 4); // -> NO Prescaler

	//Adjusting Prescaler APB1
	RCC_CFGR |= (0b100 << 8); // ->  Prescaler/2



	//Adjusting Prescaler APB2
	RCC_CFGR |= (0b101 << 11); // ->  Prescaler/2

	//Setting Internal Oscillator ON (8MHz) to be SYSCLK
	RCC_CR |= (1 << 0) ; // -> HSI ON
	RCC_CFGR |= (0b00 << 0); // -> HSI Selected


	while(1)
	{

	}

	return 0;
}