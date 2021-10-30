cmake_minimum_required(VERSION 3.14)
enable_testing()
project(fake-CMD)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src/modules)

add_subdirectory(lib/googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(test)

add_subdirectory(lib/utility)

add_executable(fake_cmd src/main.cpp) # Main Executable
target_link_libraries(fake_cmd PRIVATE libmodules PRIVATE utility)
target_include_directories(fake_cmd PUBLIC ${CMAKE_SOURCE_DIR}/lib)

if(WIN32)
	add_compile_definitions(WIN32)
endif()