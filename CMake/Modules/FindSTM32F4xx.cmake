# Find the STM32 CMSIS and StdPeriph libraries

set(STM32F4xx_LIBRARY_ROOT_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../drivers/stm32f4xx)

set(STM32F4xx_INCLUDE_DIRS
    ${STM32F4xx_LIBRARY_ROOT_DIR}/CMSIS/Include
    ${STM32F4xx_LIBRARY_ROOT_DIR}/CMSIS/Device/ST/STM32F4xx/Include
    ${STM32F4xx_LIBRARY_ROOT_DIR}/STM32F4xx_HAL_Driver/Inc)

set(STM32F4xx_HAL_SRC ${STM32F4xx_LIBRARY_ROOT_DIR}/STM32F4xx_HAL_Driver/Src)

file(GLOB STM32F4xx_SOURCES
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_tim.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_tim_ex.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_uart.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_i2c.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_i2c_ex.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_rcc.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_rcc_ex.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_flash.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_flash_ex.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_flash_ramfunc.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_gpio.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_dma.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_dma_ex.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_pwr.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_pwr_ex.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_cortex.c
    ${STM32F4xx_HAL_SRC}/stm32f4xx_hal_exti.c

    ${STM32F4xx_LIBRARY_ROOT_DIR}/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc/startup_stm32f446xx.s
)

find_package(PackageHandleStandardArgs)
find_package_handle_standard_args(STM32F4xx DEFAULT_MSG
    STM32F4xx_INCLUDE_DIRS
    STM32F4xx_SOURCES)
