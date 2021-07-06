cmake_minimum_required(VERSION 3.12)

project(fake-CMD)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src/modules)

add_executable(fake_cmd src/main.cpp)
target_link_libraries(fake_cmd PUBLIC modules)