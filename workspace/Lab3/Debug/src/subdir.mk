################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LLHuff.cpp \
../src/LLNode.cpp \
../src/LLPQ.cpp \
../src/Lab3.cpp 

OBJS += \
./src/LLHuff.o \
./src/LLNode.o \
./src/LLPQ.o \
./src/Lab3.o 

CPP_DEPS += \
./src/LLHuff.d \
./src/LLNode.d \
./src/LLPQ.d \
./src/Lab3.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


