# IF YOU DON'T KNOW WHAT YOU ARE DOING, DO **NOT** EDIT THIS FILE

# Project name
SET(PROJECT_NAME project)

# Path to drivers directory
SET(WORKSPACE_ROOT_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../..)

# Load platform-specific setup configuration (e.g., toolchain and libraries)
INCLUDE(${WORKSPACE_ROOT_DIR}/CMakeLists.txt)

CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
PROJECT(${PROJECT_NAME} C ASM)
SET(CMAKE_C_STANDARD 11)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${PLATFORM})

# Add platform-agnostic flags
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Wno-unused-parameter")

# Build type-specific flags
IF(NOT CMAKE_BUILD_TYPE)
    MESSAGE(STATUS "No build type selected, default to Debug")
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

# Create project executable
ADD_EXECUTABLE(${PROJECT_NAME} ${PROJECT_MAIN} ${PROJECT_SOURCES})
IF(DEFINED PLATFORM_EXTENSION)
    SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES SUFFIX ${PLATFORM_EXTENSION})
ENDIF()
# Link project executable with all the libraries required
TARGET_LINK_LIBRARIES(${PROJECT_NAME} fsm)

# Flash project to target (only if OpenOCD configuration file is specified)
IF(DEFINED OPENOCD_CONFIG_FILE)
    ADD_CUSTOM_TARGET(${PROJECT_NAME}-flash
        DEPENDS ${PROJECT_NAME}
        COMMAND ${OPENOCD_EXECUTABLE} -f ${OPENOCD_CONFIG_FILE} -c "program ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}${PLATFORM_EXTENSION} verify reset exit"
        COMMENT "Flashing ${PROJECT_NAME} to target")
ENDIF()

# Create hardware test executables (one for each test file)
FILE(GLOB HW_TEST RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} hw_test/*.c)
FOREACH(TEST_MAIN ${HW_TEST})
    GET_FILENAME_COMPONENT(TEST_NAME ${TEST_MAIN} NAME_WE)
    ADD_EXECUTABLE(${TEST_NAME} ${TEST_MAIN} ${PROJECT_SOURCES})
    IF(DEFINED PLATFORM_EXTENSION)
        SET_TARGET_PROPERTIES(${TEST_NAME} PROPERTIES SUFFIX ${PLATFORM_EXTENSION})
    ENDIF()
    # Link test executable with all the libraries required
    TARGET_LINK_LIBRARIES(${TEST_NAME} fsm)

    # Flash hardware test to target (only if OpenOCD configuration file is specified)
    IF(DEFINED OPENOCD_CONFIG_FILE)
        ADD_CUSTOM_TARGET(${TEST_NAME}-flash
            DEPENDS ${TEST_NAME}
            COMMAND ${OPENOCD_EXECUTABLE} -f ${OPENOCD_CONFIG_FILE} -c "program ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_NAME}${PLATFORM_EXTENSION} verify reset exit"
            COMMENT "Flashing ${TEST_NAME} to target")
    ENDIF()
ENDFOREACH(TEST_MAIN)

# Unit tests (only for native platform)
IF(PLATFORM STREQUAL "native")
    INCLUDE(CTest)
    ENABLE_TESTING()
    ADD_SUBDIRECTORY(test)
ENDIF()
