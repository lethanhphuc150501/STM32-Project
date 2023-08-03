################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := FlowControl_ErrorControl_inCommunication
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
FlowControl_ErrorControl_inCommunication.elf \

MAP_FILES += \
FlowControl_ErrorControl_inCommunication.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
FlowControl_ErrorControl_inCommunication.list \

OBJCOPY_HEX += \
FlowControl_ErrorControl_inCommunication.hex \


# All Target
all: main-build

# Main-build Target
main-build: FlowControl_ErrorControl_inCommunication.elf secondary-outputs

# Tool invocations
FlowControl_ErrorControl_inCommunication.elf FlowControl_ErrorControl_inCommunication.map: $(OBJS) $(USER_OBJS) E:\Embedded\CO3009\STM32-Project\FlowControl_ErrorControl_inCommunication\STM32F103C6TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "FlowControl_ErrorControl_inCommunication.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"E:\Embedded\CO3009\STM32-Project\FlowControl_ErrorControl_inCommunication\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="FlowControl_ErrorControl_inCommunication.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

FlowControl_ErrorControl_inCommunication.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "FlowControl_ErrorControl_inCommunication.list"
	@echo 'Finished building: $@'
	@echo ' '

FlowControl_ErrorControl_inCommunication.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "FlowControl_ErrorControl_inCommunication.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) FlowControl_ErrorControl_inCommunication.elf FlowControl_ErrorControl_inCommunication.hex FlowControl_ErrorControl_inCommunication.list FlowControl_ErrorControl_inCommunication.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
