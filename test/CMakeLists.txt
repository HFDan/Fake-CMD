enable_testing()

add_executable(module_test moduleTest.cpp)

target_link_libraries(module_test gtest_main gtest modules)
target_include_directories(module_test PUBLIC ${CMAKE_SOURCE_DIR}/src/modules)

include(GoogleTest)
gtest_discover_tests(module_test)