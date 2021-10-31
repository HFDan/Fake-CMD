cmake_minimum_required(VERSION 3.14)
enable_testing()
project(fake-CMD)
set(CMAKE_CXX_STANDARD 20)

# CPM
include(cmake/CPM.cmake)
include(packages.cmake)

# Compile-time Modules
add_subdirectory(src/modules)

# GTEST
add_subdirectory(lib/googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Unit tests
add_subdirectory(test)

# Other stuff
# TODO: Move from a library to the main program.
add_subdirectory(lib/utility)

# Threading support
find_package(Threads REQUIRED)

add_executable(fake_cmd src/main.cpp) # Main Executable
target_link_libraries(fake_cmd PUBLIC Threads::Threads PRIVATE libmodules PRIVATE utility PRIVATE yaml-cpp)
target_include_directories(fake_cmd PUBLIC ${CMAKE_SOURCE_DIR}/lib)

if(WIN32) # Windows definitions
	add_compile_definitions(WIN32)
endif()