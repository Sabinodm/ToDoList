cmake_minimum_required(VERSION 3.26)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES runAllTest.cpp CategoryFixture.cpp
        TxtFileFixture.cpp
        TimeDateFixture.cpp)
add_executable(runUnitTests ${SOURCE_FILES})
target_link_libraries(runUnitTests ${GTEST_BOTH_LIBRARIES} core)
enable_testing()