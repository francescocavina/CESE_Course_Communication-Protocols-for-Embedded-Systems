################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/SSD1306/Src/fonts.c \
../Drivers/SSD1306/Src/ssd1306.c \
../Drivers/SSD1306/Src/ssd1306_port.c 

OBJS += \
./Drivers/SSD1306/Src/fonts.o \
./Drivers/SSD1306/Src/ssd1306.o \
./Drivers/SSD1306/Src/ssd1306_port.o 

C_DEPS += \
./Drivers/SSD1306/Src/fonts.d \
./Drivers/SSD1306/Src/ssd1306.d \
./Drivers/SSD1306/Src/ssd1306_port.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/SSD1306/Src/%.o Drivers/SSD1306/Src/%.su: ../Drivers/SSD1306/Src/%.c Drivers/SSD1306/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/media/francesco/Data/Francesco/PdCeSE_workspace/digitalCompass/Drivers/SSD1306/Src" -I"/media/francesco/Data/Francesco/PdCeSE_workspace/digitalCompass/Drivers/SSD1306/Inc" -I"/media/francesco/Data/Francesco/PdCeSE_workspace/digitalCompass/Drivers/API/Inc" -I"/media/francesco/Data/Francesco/PdCeSE_workspace/digitalCompass/Drivers/API/Src" -I"/media/francesco/Data/Francesco/PdCeSE_workspace/digitalCompass/Drivers/BSP" -I"/media/francesco/Data/Francesco/PdCeSE_workspace/digitalCompass/Drivers/BSP/STM32F4xx_Nucleo_144" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-SSD1306-2f-Src

clean-Drivers-2f-SSD1306-2f-Src:
	-$(RM) ./Drivers/SSD1306/Src/fonts.d ./Drivers/SSD1306/Src/fonts.o ./Drivers/SSD1306/Src/fonts.su ./Drivers/SSD1306/Src/ssd1306.d ./Drivers/SSD1306/Src/ssd1306.o ./Drivers/SSD1306/Src/ssd1306.su ./Drivers/SSD1306/Src/ssd1306_port.d ./Drivers/SSD1306/Src/ssd1306_port.o ./Drivers/SSD1306/Src/ssd1306_port.su

.PHONY: clean-Drivers-2f-SSD1306-2f-Src

