# TARGET CONFIG FOR CROSS COMPILATION (STM32F446RETx MCU)

# Linker configuration
target_link_options(${PROJECT_NAME}${PLATFORM_EXTENSION} PRIVATE
    -T${CMAKE_CURRENT_SOURCE_DIR}/CMake/Ld/STM32F446RETx_FLASH.ld
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -specs=nano.specs
    -lc
    -lm
    -lnosys
    -Wl,-Map=${PROJECT_NAME}.map,--cref
    -Wl,--gc-sections
)

# Print executable size
add_custom_command(TARGET ${BINARY_NAME}
        POST_BUILD
        COMMAND arm-none-eabi-size ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BINARY_NAME}
)

# Create hex file
add_custom_command(TARGET ${BINARY_NAME}
        POST_BUILD
        COMMAND arm-none-eabi-objcopy -O ihex ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BINARY_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/bin/${PROJECT_NAME}.hex
        COMMAND arm-none-eabi-objcopy -O binary ${CMAKE_CURRENT_SOURCE_DIR}/bin/${BINARY_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/bin/${PROJECT_NAME}.bin
)
