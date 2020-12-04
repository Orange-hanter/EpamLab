cmake_minimum_required(VERSION 3.13.0)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} VERSION 0.1.0)
message( STATUS "BUILD ${PROJECT_NAME}")

SET( SORCE ./Descriptor.cpp)

SET( HEADERS ./Descriptor.h 
                ./Array.hpp
)

add_executable( ${PROJECT_NAME} app.cpp ${SORCE} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/../)
target_precompile_headers(${PROJECT_NAME} PRIVATE ../PCH.h)
message("${CMAKE_BUILD_TYPE}")
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    set_directory_properties(PROPERTIES COMPILE_DEFINITIONS "_DEBUG")
else ()
    set_directory_properties(PROPERTIES COMPILE_DEFINITIONS "NDEBUG")
endif ()