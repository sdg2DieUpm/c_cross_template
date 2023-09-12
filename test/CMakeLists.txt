include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../project/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../unity/src)

# Unit tests
FILE(GLOB TestSources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ./test_*.c)
foreach (testSrc ${TestSources})
    get_filename_component(testName ${testSrc} NAME_WE)
    add_executable(${testName} ${testSrc} ${SOURCES})
    target_link_libraries(${testName} unity)
    add_test(NAME ${testName} COMMAND ${testName} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
endforeach (testSrc)
