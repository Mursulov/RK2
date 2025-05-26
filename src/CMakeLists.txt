add_library(bridge STATIC bridge.cpp)
target_include_directories(bridge PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(bridge_demo main.cpp)
target_link_libraries(bridge_demo bridge)
target_include_directories(bridge_demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS bridge_demo RUNTIME DESTINATION bin)
