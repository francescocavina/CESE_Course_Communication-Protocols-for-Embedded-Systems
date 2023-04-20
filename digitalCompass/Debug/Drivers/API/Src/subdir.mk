################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Src/API_debounce.c \
../Drivers/API/Src/API_delay.c \
../Drivers/API/Src/API_displayOLED.c \
../Drivers/API/Src/API_magnetometer.c \
../Drivers/API/Src/API_system.c 

OBJS += \
./Drivers/API/Src/API_debounce.o \
./Drivers/API/Src/API_delay.o \
./Drivers/API/Src/API_displayOLED.o \
./Drivers/API/Src/API_magnetometer.o \
./Drivers/API/Src/API_system.o 

C_DEPS += \
./Drivers/API/Src/API_debounce.d \
./Drivers/API/Src/API_delay.d \
./Drivers/API/Src/API_displayOLED.d \
./Drivers/API/Src/API_magnetometer.d \
./Drivers/API/Src/API_system.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Src/%.o Drivers/API/Src/%.su: ../Drivers/API/Src/%.c Drivers/API/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/media/francesco/Data/Francesco/PdCeSE_workspace/digitalCompass/Drivers/SSD1306/Src" -I"/media/francesco/Data/Francesco/PdCeSE_workspace/digitalCompass/Drivers/SSD1306/Inc" -I"/media/francesco/Data/Francesco/PdCeSE_workspace/digitalCompass/Drivers/API/Inc" -I"/media/francesco/Data/Francesco/PdCeSE_workspace/digitalCompass/Drivers/API/Src" -I"/media/francesco/Data/Francesco/PdCeSE_workspace/digitalCompass/Drivers/BSP" -I"/media/francesco/Data/Francesco/PdCeSE_workspace/digitalCompass/Drivers/BSP/STM32F4xx_Nucleo_144" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Src

clean-Drivers-2f-API-2f-Src:
	-$(RM) ./Drivers/API/Src/API_debounce.d ./Drivers/API/Src/API_debounce.o ./Drivers/API/Src/API_debounce.su ./Drivers/API/Src/API_delay.d ./Drivers/API/Src/API_delay.o ./Drivers/API/Src/API_delay.su ./Drivers/API/Src/API_displayOLED.d ./Drivers/API/Src/API_displayOLED.o ./Drivers/API/Src/API_displayOLED.su ./Drivers/API/Src/API_magnetometer.d ./Drivers/API/Src/API_magnetometer.o ./Drivers/API/Src/API_magnetometer.su ./Drivers/API/Src/API_system.d ./Drivers/API/Src/API_system.o ./Drivers/API/Src/API_system.su

.PHONY: clean-Drivers-2f-API-2f-Src

