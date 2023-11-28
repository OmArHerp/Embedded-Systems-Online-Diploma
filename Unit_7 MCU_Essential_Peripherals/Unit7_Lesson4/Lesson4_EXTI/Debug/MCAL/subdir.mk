################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Stm32_F103C6_EXTI_driver.c \
../MCAL/Stm32_F103C6_gpio_driver.c 

OBJS += \
./MCAL/Stm32_F103C6_EXTI_driver.o \
./MCAL/Stm32_F103C6_gpio_driver.o 

C_DEPS += \
./MCAL/Stm32_F103C6_EXTI_driver.d \
./MCAL/Stm32_F103C6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Stm32_F103C6_EXTI_driver.o: ../MCAL/Stm32_F103C6_EXTI_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Omar/Embedded System/K_S/Unit7_Workspace/Lesson4_EXTI/HAL/includes" -I"D:/Omar/Embedded System/K_S/Unit7_Workspace/Lesson4_EXTI/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32_F103C6_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32_F103C6_gpio_driver.o: ../MCAL/Stm32_F103C6_gpio_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Omar/Embedded System/K_S/Unit7_Workspace/Lesson4_EXTI/HAL/includes" -I"D:/Omar/Embedded System/K_S/Unit7_Workspace/Lesson4_EXTI/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32_F103C6_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

