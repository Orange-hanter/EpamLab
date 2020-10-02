cmake_minimum_required(VERSION 3.0.0)

project(Lab2 VERSION 0.1.0)
message(STATUS "BUILD ${PROJECT_NAME}" )

add_executable(${PROJECT_NAME} app.cpp )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
