# SETUP FOR STM32F446RETx BOARDS

SET(CMAKE_TOOLCHAIN_FILE "CMake/Toolchains/arm-none-eabi-gcc.cmake")

# STM32 HAL and CMSIS
FIND_PACKAGE("STM32F4xx" REQUIRED)

# STM32 ST-Link Utility
# FIND_PACKAGE(STLinkUtility)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -DUSE_HAL_DRIVER -DSTM32F446xx -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard")

# File extension
set(PLATFORM_EXTENSION ".elf")
# Platform-specific source files
set(PLATFORM_SOURCES ${STM32F4xx_SOURCES})
# Platform-specific directories with header files
set(PLATFORM_INCLUDE_DIRS ${STM32F4xx_INCLUDE_DIRS})
