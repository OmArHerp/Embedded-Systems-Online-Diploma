/**
 ******************************************************************************
 * @file           : main.c
 * @author         : OmArHerp
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


#include "Stm32f103x6.h"
#include "Stm32_F103C6_gpio_driver.h"



void Clock_init();
void GPIO_init();

int main(void)
{
	unsigned volatile  int i = 0 ;


	Clock_init();
	GPIO_init();


	while(1)
	{
		//PA1 >> PUR (connected to vcc)
		if( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN1) == 0 ) // press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN1);
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN1) == 0 ); //Single Press
		}

		//PA13 >> PDR (connected to ground)
		if(  MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN13) == 1 ) // press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN13); // Multi Press

		}
	}

	for(i ; i <5000 ; i++);

	return 0;
}
void Clock_init()
{
	//Enable clock GPIOA
	RCC_GPIOA_CLCK_EN() ;

	//Enable clock GPIOB
	RCC_GPIOB_CLCK_EN() ;

}
void GPIO_init()
{
	GPIO_PinConfig_t PinCfg ;


	//PA1 input HighZ (Floaing input (reset state))
	PinCfg.GPIO_PinNumber = GPIO_PIN1 ;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(GPIOA, &PinCfg) ;

	//PA13 input HighZ
	PinCfg.GPIO_PinNumber = GPIO_PIN13 ;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(GPIOA, &PinCfg) ;

	//PB1 Output push pull mode
	PinCfg.GPIO_PinNumber = GPIO_PIN1 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(GPIOB, &PinCfg) ;

	//PB13 Output push pull mode
	PinCfg.GPIO_PinNumber = GPIO_PIN13 ;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(GPIOB, &PinCfg) ;

}
