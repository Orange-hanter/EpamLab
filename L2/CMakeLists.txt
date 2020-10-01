#comment 
cmake_minimum_required(VERSION 3.0.0)

project(Lab2 VERSION 0.1.0)


file(GLOB SOURCES "${CMAKE_HOME_DIRECTORY}/src/*.cpp")

add_definitions(-Wall -O0)

add_executable(${PROJECT_NAME} ${SOURCES} )

target_include_directories( ${PROJECT_NAME}  PRIVATE "${PROJECT_SOURCE_DIR}/headers")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
