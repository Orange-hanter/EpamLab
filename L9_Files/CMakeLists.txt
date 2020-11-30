cmake_minimum_required(VERSION 3.0.0)

project(L9_Files VERSION 0.1.0)
message( STATUS "BUILD ${PROJECT_NAME}")

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable( ${PROJECT_NAME} ${SOURCES} )

target_include_directories( ${PROJECT_NAME}  PUBLIC "${PROJECT_SOURCE_DIR}/headers")
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/../)
target_precompile_headers(${PROJECT_NAME} PUBLIC ../PCH.h)

find_package(Catch2 REQUIRED)
file(GLOB TESTS "${PROJECT_SOURCE_DIR}/test/*.cpp")
add_executable(${PROJECT_NAME}_test ${TESTS})
target_link_libraries(${PROJECT_NAME}_test Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(${PROJECT_NAME}_test)