# note: following this post for setting up CMake
# https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html

cmake_minimum_required(VERSION 3.5...4.0)
project(PA3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

# Add root directory as include path
include_directories(${CMAKE_SOURCE_DIR})

# Main executable
add_executable(runPA3 Main.cpp PA3.cpp)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

# Unit test executable
add_executable(testPA3 test/test_PA3.cpp PA3.cpp)
target_link_libraries(testPA3 gtest_main)
include(GoogleTest)
gtest_discover_tests(testPA3)
