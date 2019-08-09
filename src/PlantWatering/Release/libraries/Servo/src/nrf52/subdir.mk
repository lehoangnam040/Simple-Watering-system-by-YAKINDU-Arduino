################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
D:\yakindu-sct\arduinoPlugin\libraries\Servo\1.1.3\src\nrf52\Servo.cpp 

LINK_OBJ += \
.\libraries\Servo\src\nrf52\Servo.cpp.o 

CPP_DEPS += \
.\libraries\Servo\src\nrf52\Servo.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\Servo\src\nrf52\Servo.cpp.o: D:\yakindu-sct\arduinoPlugin\libraries\Servo\1.1.3\src\nrf52\Servo.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\yakindu-sct\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"D:\yakindu-sct\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"D:\yakindu-sct\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\standard" -I"D:\yakindu-sct\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"D:\yakindu-sct\arduinoPlugin\libraries\Servo\1.1.3\src" -I"D:\yakindu-sct\arduinoPlugin\libraries\DHT_sensor_library\1.3.4" -I"D:\yakindu-sct\arduinoPlugin\libraries\Adafruit_Unified_Sensor\1.0.2" -I"D:\yakindu-sct\arduinoPlugin\libraries\LM35_Sensor\1.0.0\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


