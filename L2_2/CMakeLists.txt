cmake_minimum_required(VERSION 3.0.0)
project(Lab2Extra VERSION 0.1.0)
message(STATUS "BUILD ${PROJECT_NAME}" )

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} )

target_include_directories( ${PROJECT_NAME}  PRIVATE "${PROJECT_SOURCE_DIR}/headers")


enable_testing()

add_executable(tester "${PROJECT_SOURCE_DIR}/tests/tester.cpp")
add_test(Test1 tester 2 2)
add_test(Test2 tester 4 4)
add_test(Test3 tester 6 6 6)

set_tests_properties( Test1 Test2 Test3 PROPERTIES TIMEOUT 1)

set_tests_properties( Test1 PROPERTIES
PASS_REGULAR_EXPRESSION "2 - 2"
FAIL_REGULAR_EXPRESSION "ERROR!")

set_tests_properties( Test2 PROPERTIES
PASS_REGULAR_EXPRESSION "4 - 4"
FAIL_REGULAR_EXPRESSION "ERROR!")

set_tests_properties( Test3 PROPERTIES
PASS_REGULAR_EXPRESSION "ERROR!")