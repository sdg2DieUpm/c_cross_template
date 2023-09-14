# SETUP FOR STM32F446RETx BOARDS

SET(CMAKE_TOOLCHAIN_FILE "CMake/Toolchains/arm-none-eabi-gcc.cmake")

# STM32 HAL and CMSIS
FIND_PACKAGE("STM32F4xx" REQUIRED)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -DUSE_HAL_DRIVER -DSTM32F446xx -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard")

# File extension
SET(PLATFORM_EXTENSION ".elf")
# Platform-specific source files
SET(PLATFORM_SOURCES ${STM32F4xx_SOURCES})
# Platform-specific directories with header files
SET(PLATFORM_INCLUDE_DIRS ${STM32F4xx_INCLUDE_DIRS})

SET(PLATFORM_LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/CMake/Ld/STM32F446RETx_FLASH.ld")

# OpenOCD support (only if OpenOCD is found)
FIND_PACKAGE(OpenOCD)
IF(OpenOCD_FOUND)
    SET(OPENOCD_CONFIG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/CMake/OpenOCD/stm32f4x.cfg)
    # TODO: erase hangs. Why?
    # ADD_CUSTOM_TARGET(erase COMMAND ${OPENOCD_EXECUTABLE} -f ${OPENOCD_CONFIG_FILE} -c "init; reset halt; stm32f4x mass_erase 0; exit")
ENDIF()
