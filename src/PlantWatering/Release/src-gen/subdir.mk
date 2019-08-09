################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
..\src-gen\PlantWatering.c 

C_DEPS += \
.\src-gen\PlantWatering.c.d 

LINK_OBJ += \
.\src-gen\PlantWatering.c.o 


# Each subdirectory must supply rules for building sources it contributes
src-gen\PlantWatering.c.o: ..\src-gen\PlantWatering.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"D:\yakindu-sct\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"D:\yakindu-sct\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"D:\yakindu-sct\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\standard" -I"D:\yakindu-sct\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"D:\yakindu-sct\arduinoPlugin\libraries\Servo\1.1.3\src" -I"D:\yakindu-sct\arduinoPlugin\libraries\DHT_sensor_library\1.3.4" -I"D:\yakindu-sct\arduinoPlugin\libraries\Adafruit_Unified_Sensor\1.0.2" -I"D:\yakindu-sct\arduinoPlugin\libraries\LM35_Sensor\1.0.0\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


