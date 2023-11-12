cmake_minimum_required(VERSION 3.26)
project(ToDoList)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILE Activity.cpp Activity.h Category.cpp Category.h TimeDate.cpp TimeDate.h TimeDateException.cpp TimeDateException.h TxtFile.cpp TxtFile.h UserInterface.cpp UserInterface.h)
add_executable(ToDoList main.cpp)
add_library(core ${SOURCE_FILE})
target_link_libraries(ToDoList core)