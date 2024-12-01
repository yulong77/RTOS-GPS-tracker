################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../common/ThirdParty/SEGGER/Rec/segger_uart.c 

OBJS += \
./common/ThirdParty/SEGGER/Rec/segger_uart.o 

C_DEPS += \
./common/ThirdParty/SEGGER/Rec/segger_uart.d 


# Each subdirectory must supply rules for building sources it contributes
common/ThirdParty/SEGGER/Rec/%.o common/ThirdParty/SEGGER/Rec/%.su common/ThirdParty/SEGGER/Rec/%.cyclo: ../common/ThirdParty/SEGGER/Rec/%.c common/ThirdParty/SEGGER/Rec/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I"/Users/yulong/code/RTOS_GPS_project/RTOS_workspace/LCD_GPS_Tasks_004/common/ThirdParty/SEGGER/Config" -I"/Users/yulong/code/RTOS_GPS_project/RTOS_workspace/LCD_GPS_Tasks_004/common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"/Users/yulong/code/RTOS_GPS_project/RTOS_workspace/LCD_GPS_Tasks_004/common/ThirdParty/FreeRTOS/include" -I"/Users/yulong/code/RTOS_GPS_project/RTOS_workspace/LCD_GPS_Tasks_004/common/ThirdParty/SEGGER/OS" -I"/Users/yulong/code/RTOS_GPS_project/RTOS_workspace/LCD_GPS_Tasks_004/common/ThirdParty/SEGGER/SEGGER" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common-2f-ThirdParty-2f-SEGGER-2f-Rec

clean-common-2f-ThirdParty-2f-SEGGER-2f-Rec:
	-$(RM) ./common/ThirdParty/SEGGER/Rec/segger_uart.cyclo ./common/ThirdParty/SEGGER/Rec/segger_uart.d ./common/ThirdParty/SEGGER/Rec/segger_uart.o ./common/ThirdParty/SEGGER/Rec/segger_uart.su

.PHONY: clean-common-2f-ThirdParty-2f-SEGGER-2f-Rec

