cmake_minimum_required(VERSION 3.0.0)
project(Lab8 VERSION 0.1.0)
message(STATUS "BUILD ${PROJECT_NAME}" )

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES} )


set_property(TARGET Lab8 PROPERTY CXX_STANDARD 17)
target_include_directories( ${PROJECT_NAME}  PRIVATE "${PROJECT_SOURCE_DIR}/headers")

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic

    -Wcast-align
    -Wcast-qual
    -Wconversion
    -Wctor-dtor-privacy
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-conversion
    -Wsign-promo
)

#CURL LUBRARY
find_package( CURL REQUIRED )
target_link_libraries( ${PROJECT_NAME} CURL::libcurl )
if(CURL_FOUND)
  include_directories(${CURL_INCLUDE_DIR})
else(CURL_FOUND)
  message(FATAL_ERROR "CURL library not found")
endif(CURL_FOUND)

#JSON LIBRARY
find_package(nlohmann_json 3.2.0 REQUIRED)
target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
if(nlohmann_json_FOUND)
  include_directories(${nlohmann_json_INCLUDE_DIR})
else(nlohmann_json_FOUND)
  message(FATAL_ERROR "nlohman_json library not found")
endif(nlohmann_json_FOUND)
