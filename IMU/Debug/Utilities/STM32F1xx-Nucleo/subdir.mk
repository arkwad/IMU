################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/STM32F1xx-Nucleo/stm32f1xx_nucleo.c 

OBJS += \
./Utilities/STM32F1xx-Nucleo/stm32f1xx_nucleo.o 

C_DEPS += \
./Utilities/STM32F1xx-Nucleo/stm32f1xx_nucleo.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/STM32F1xx-Nucleo/%.o: ../Utilities/STM32F1xx-Nucleo/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -I"C:/STM_WORKSPACE/IMU/inc" -I"C:/STM_WORKSPACE/IMU/CMSIS/core" -I"C:/STM_WORKSPACE/IMU/CMSIS/device" -I"C:/STM_WORKSPACE/IMU/StdPeriph_Driver/inc" -I"C:/STM_WORKSPACE/IMU/Utilities/STM32F1xx-Nucleo" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


