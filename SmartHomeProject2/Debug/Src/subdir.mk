################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Blutooth.c \
../Src/HLED_prc.c \
../Src/MDIO_prc.c \
../Src/UART_prc.c \
../Src/main.c 

OBJS += \
./Src/Blutooth.o \
./Src/HLED_prc.o \
./Src/MDIO_prc.o \
./Src/UART_prc.o \
./Src/main.o 

C_DEPS += \
./Src/Blutooth.d \
./Src/HLED_prc.d \
./Src/MDIO_prc.d \
./Src/UART_prc.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


