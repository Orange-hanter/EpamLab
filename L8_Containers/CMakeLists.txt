cmake_minimum_required(VERSION 3.0.0)
project(Lab8 VERSION 0.1.0)
message(STATUS "BUILD ${PROJECT_NAME}" )

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES} )




set_property(TARGET Lab8 PROPERTY CXX_STANDARD 17)
target_include_directories( ${PROJECT_NAME}  PRIVATE "${PROJECT_SOURCE_DIR}/headers")