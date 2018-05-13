################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BSTB.cpp \
../src/Game.cpp \
../src/Main.cpp \
../src/NodeTB.cpp 

OBJS += \
./src/BSTB.o \
./src/Game.o \
./src/Main.o \
./src/NodeTB.o 

CPP_DEPS += \
./src/BSTB.d \
./src/Game.d \
./src/Main.d \
./src/NodeTB.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


