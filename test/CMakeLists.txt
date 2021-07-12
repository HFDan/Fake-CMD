include(GoogleTest)

add_executable(MonolithicTest monolithicTest.cpp)
target_link_libraries(MonolithicTest gtest_main gtest modules utility)
target_include_directories(MonolithicTest PUBLIC ${CMAKE_SOURCE_DIR}/src/modules ${CMAKE_SOURCE_DIR}/lib)
gtest_discover_tests(MonolithicTest)