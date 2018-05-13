################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Document.cpp \
../src/LLSE.cpp \
../src/Lab5.cpp \
../src/Node.cpp \
../src/SEMain.cpp 

OBJS += \
./src/Document.o \
./src/LLSE.o \
./src/Lab5.o \
./src/Node.o \
./src/SEMain.o 

CPP_DEPS += \
./src/Document.d \
./src/LLSE.d \
./src/Lab5.d \
./src/Node.d \
./src/SEMain.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


