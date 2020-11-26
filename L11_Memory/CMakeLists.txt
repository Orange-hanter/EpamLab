cmake_minimum_required(VERSION 3.13.0)
project(Lab11 VERSION 0.1.0)
message( STATUS "BUIOD ${PROJECT_NAME}")

add_executable( ${PROJECT_NAME} app.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/../)
target_precompile_headers(${PROJECT_NAME} PRIVATE ../PCH.h)