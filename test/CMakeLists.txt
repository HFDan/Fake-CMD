include(GoogleTest)

add_executable(MonolithicTest monolithicTest.cpp)
target_link_libraries(MonolithicTest gtest_main gtest modules)
target_include_directories(MonolithicTest PUBLIC ${CMAKE_SOURCE_DIR}/src/modules)
gtest_discover_tests(MonolithicTest)
add_test(NAME MonolithicTest COMMAND MonolithicTest)