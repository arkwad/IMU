################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/delay.c \
../src/lsm303d.c \
../src/main.c \
../src/syscalls.c \
../src/system_stm32f10x.c 

OBJS += \
./src/delay.o \
./src/lsm303d.o \
./src/main.o \
./src/syscalls.o \
./src/system_stm32f10x.o 

C_DEPS += \
./src/delay.d \
./src/lsm303d.d \
./src/main.d \
./src/syscalls.d \
./src/system_stm32f10x.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -I"C:/STM_WORKSPACE/IMU/inc" -I"C:/STM_WORKSPACE/IMU/CMSIS/core" -I"C:/STM_WORKSPACE/IMU/CMSIS/device" -I"C:/STM_WORKSPACE/IMU/StdPeriph_Driver/inc" -I"C:/STM_WORKSPACE/IMU/Utilities/STM32F1xx-Nucleo" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


