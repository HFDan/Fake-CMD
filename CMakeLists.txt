cmake_minimum_required(VERSION 3.14)
enable_testing()
project(fake-CMD)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src/modules)

add_subdirectory(lib/googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(test)

add_executable(fake_cmd src/main.cpp) # Main Executable
target_link_libraries(fake_cmd PUBLIC modules)