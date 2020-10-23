cmake_minimum_required(VERSION 3.0.0)
project(Lab8 VERSION 0.1.0)
message(STATUS "BUILD ${PROJECT_NAME}" )

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES} )


set_property(TARGET Lab8 PROPERTY CXX_STANDARD 17)
target_include_directories( ${PROJECT_NAME}  PRIVATE "${PROJECT_SOURCE_DIR}/headers")

find_package( CURL REQUIRED )
 target_link_libraries( ${PROJECT_NAME} CURL::libcurl )

if(CURL_FOUND)
  include_directories(${CURL_INCLUDE_DIR})
  target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARY})
else(CURL_FOUND)
  message(FATAL_ERROR "CURL library not found")
endif(CURL_FOUND)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)