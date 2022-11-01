################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/app_main.c \
../Sources/bb_memory.c \
../Sources/bootloader_app.c \
../Sources/can.c \
../Sources/clock.c \
../Sources/core_main.c \
../Sources/gpio.c \
../Sources/internal_flash.c \
../Sources/internal_flash_app.c \
../Sources/main.c \
../Sources/nvic.c \
../Sources/timer.c \
../Sources/uart.c \
../Sources/uart_state_machine.c 

OBJS += \
./Sources/app_main.o \
./Sources/bb_memory.o \
./Sources/bootloader_app.o \
./Sources/can.o \
./Sources/clock.o \
./Sources/core_main.o \
./Sources/gpio.o \
./Sources/internal_flash.o \
./Sources/internal_flash_app.o \
./Sources/main.o \
./Sources/nvic.o \
./Sources/timer.o \
./Sources/uart.o \
./Sources/uart_state_machine.o 

C_DEPS += \
./Sources/app_main.d \
./Sources/bb_memory.d \
./Sources/bootloader_app.d \
./Sources/can.d \
./Sources/clock.d \
./Sources/core_main.d \
./Sources/gpio.d \
./Sources/internal_flash.d \
./Sources/internal_flash_app.d \
./Sources/main.d \
./Sources/nvic.d \
./Sources/timer.d \
./Sources/uart.d \
./Sources/uart_state_machine.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/app_main.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


