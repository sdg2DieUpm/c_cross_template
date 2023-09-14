SET(PROJECT_NAME project) # Set project name here

# If you don't know what you are doing... DO **NOT** EDIT BELOW THIS LINE
SET(DRIVERS_ROOT_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../../drivers)

# Add the 'Modules' folder to the search path for CMake/Modules/FindXXX.cmake files
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/Modules)

# Parse target platform from command line. If not specified, default to native
IF (NOT PLATFORM)
    SET(PLATFORM "native")
ENDIF()

# Load platform-specific setup configuration in CMake/<PLATFORM>.cmake (e.g., toolchain and libraries)
INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/CMake/Setup/${PLATFORM}.cmake)

PROJECT(${PROJECT_NAME} C ASM)
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
SET(CMAKE_C_STANDARD 11)
SET(BINARY_NAME ${PROJECT_NAME}${PLATFORM_EXTENSION})
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Add platform-agnostic flags
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Wno-unused-parameter")

# Build type-specific flags
IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Debug)
ENDIF()
SET(CMAKE_C_FLAGS_DEBUG "-g -O0")
SET(CMAKE_C_FLAGS_RELEASE "-O3")

# Include directories with header files
SET(PROJECT_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/project/common/include            # project library (common)
    ${CMAKE_CURRENT_SOURCE_DIR}/project/port/${PLATFORM}/include) # project library (port)
INCLUDE_DIRECTORIES(${PROJECT_INCLUDE_DIRS} ${PLATFORM_INCLUDE_DIRS})

# Source files
FILE(GLOB PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/project/common/src/*.c             # project library (common)
    ${CMAKE_CURRENT_SOURCE_DIR}/project/port/${PLATFORM}/src/*.c)  # project library (port)
FILE(GLOB PROJECT_MAIN ${CMAKE_CURRENT_SOURCE_DIR}/project/main.c) # main routine

# Create executable
ADD_EXECUTABLE(${BINARY_NAME} ${PROJECT_MAIN} ${PROJECT_SOURCES} ${PLATFORM_SOURCES})

# Platform-specific target configuration (e.g., linker script)
INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/CMake/Target/${PLATFORM}.cmake)

# Flash target (only if OpenOCD configuration file is specified)
IF(DEFINED OPENOCD_CONFIG_FILE)
    ADD_CUSTOM_TARGET(${PROJECT_NAME}-flash
        DEPENDS ${BINARY_NAME}
        COMMAND ${OPENOCD_EXECUTABLE} -f ${OPENOCD_CONFIG_FILE} -c "program ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${BINARY_NAME} verify reset exit"
        COMMENT "Flashing ${BINARY_NAME} to target")
ENDIF()

# Unit tests (only for native platform)
IF(PLATFORM STREQUAL "native")
    ADD_LIBRARY(unity ${PROJECT_SOURCE_DIR}/unity/src/unity.c)
    INCLUDE(CTest)
    ENABLE_TESTING()
    ADD_SUBDIRECTORY(test)
ENDIF()
