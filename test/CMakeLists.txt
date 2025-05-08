enable_testing()

# Use system-installed GTest
find_package(GTest REQUIRED)

# Add test executable
add_executable(runTests Test.cpp ../PA4.cpp)

# Include headers from parent directory (for PA4.h)
target_include_directories(runTests PRIVATE ../)

# Link your main library and GTest
target_link_libraries(runTests pa_library GTest::GTest GTest::Main pthread)

# Register the test with CMake
add_test(NAME AllTests COMMAND runTests)
