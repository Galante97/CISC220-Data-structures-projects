################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LinkedListProblems2/DLL.cpp \
../LinkedListProblems2/DNode.cpp \
../LinkedListProblems2/SLL.cpp \
../LinkedListProblems2/SNode.cpp \
../LinkedListProblems2/lab3main.cpp 

OBJS += \
./LinkedListProblems2/DLL.o \
./LinkedListProblems2/DNode.o \
./LinkedListProblems2/SLL.o \
./LinkedListProblems2/SNode.o \
./LinkedListProblems2/lab3main.o 

CPP_DEPS += \
./LinkedListProblems2/DLL.d \
./LinkedListProblems2/DNode.d \
./LinkedListProblems2/SLL.d \
./LinkedListProblems2/SNode.d \
./LinkedListProblems2/lab3main.d 


# Each subdirectory must supply rules for building sources it contributes
LinkedListProblems2/%.o: ../LinkedListProblems2/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


