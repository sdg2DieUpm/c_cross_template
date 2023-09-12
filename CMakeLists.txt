CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

# Definitions
SET(PROJECT_NAME project)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
PROJECT(${PROJECT_NAME})
SET(CMAKE_C_STANDARD 11)

# Create third-party libraries
ADD_LIBRARY(unity ${PROJECT_SOURCE_DIR}/unity/src/unity.c)

# Include directories with header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/project/include)

#  projectlibrary and main routine
file(GLOB MAIN ${CMAKE_CURRENT_SOURCE_DIR}/project/main.c)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/project/src/*.c ${CMAKE_CURRENT_SOURCE_DIR}/project/src/*/*.c)

add_executable(main ${MAIN} ${SOURCES})

# Unit tests
include(CTest)
ENABLE_TESTING()
ADD_SUBDIRECTORY(test)
