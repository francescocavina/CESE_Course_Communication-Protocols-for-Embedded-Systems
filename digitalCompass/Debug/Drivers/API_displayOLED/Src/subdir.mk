################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API_displayOLED/Src/API_displayOLED.c 

OBJS += \
./Drivers/API_displayOLED/Src/API_displayOLED.o 

C_DEPS += \
./Drivers/API_displayOLED/Src/API_displayOLED.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API_displayOLED/Src/%.o Drivers/API_displayOLED/Src/%.su: ../Drivers/API_displayOLED/Src/%.c Drivers/API_displayOLED/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/media/francesco/Data/Francesco/PdCeSE/digitalCompass/Drivers/SSD1306" -I"/media/francesco/Data/Francesco/PdCeSE/digitalCompass/Drivers/SSD1306/Src" -I"/media/francesco/Data/Francesco/PdCeSE/digitalCompass/Drivers/SSD1306/Inc" -I"/media/francesco/Data/Francesco/PdCeSE/digitalCompass/Drivers/API_displayOLED/Inc" -I"/media/francesco/Data/Francesco/PdCeSE/digitalCompass/Drivers/API_displayOLED/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API_displayOLED-2f-Src

clean-Drivers-2f-API_displayOLED-2f-Src:
	-$(RM) ./Drivers/API_displayOLED/Src/API_displayOLED.d ./Drivers/API_displayOLED/Src/API_displayOLED.o ./Drivers/API_displayOLED/Src/API_displayOLED.su

.PHONY: clean-Drivers-2f-API_displayOLED-2f-Src

