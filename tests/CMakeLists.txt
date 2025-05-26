enable_testing()

add_executable(bridge_tests test_bridge.cpp)
target_link_libraries(bridge_tests PRIVATE bridge GTest::gtest_main)
target_include_directories(bridge_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

add_test(NAME BridgeTests COMMAND bridge_tests)
