cmake_minimum_required(VERSION 3.0.0)
project(Catch2_example VERSION 0.1.0)
message(STATUS "BUILD ${PROJECT_NAME}" )

find_package(Catch2 REQUIRED)
file(GLOB TESTS "${PROJECT_SOURCE_DIR}/test/*.cpp")
add_executable(${PROJECT_NAME}_test ${TESTS})
target_link_libraries(${PROJECT_NAME}_test Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(${PROJECT_NAME}_test)