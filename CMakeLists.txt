cmake_minimum_required(VERSION 3.10)
project(PA4Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(pa_library PA4.cpp PA4.h)

add_executable(runPA4 Main.cpp)
target_link_libraries(runPA4 pa_library)

add_subdirectory(test)
