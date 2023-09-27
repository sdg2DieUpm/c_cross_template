include_directories(${PROJECT_INCLUDE_DIRS} ${PLATFORM_INCLUDE_DIRS})

# Unit tests
FILE(GLOB TestSources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ./test_*.c)
foreach (testSrc ${TestSources})
    get_filename_component(testName ${testSrc} NAME_WE)
    add_executable(${testName} ${testSrc} ${PROJECT_SOURCES} ${PLATFORM_SOURCES})
    target_link_libraries(${testName} unity)
    add_test(NAME ${testName} COMMAND ${testName} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin-${CMAKE_BUILD_TYPE}/${PLATFORM})
endforeach (testSrc)
