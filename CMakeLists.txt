cmake_minimum_required(VERSION 3.0.0)
project(EpamLab VERSION 0.1.0)

add_subdirectory(L1)
add_subdirectory(L2)
add_subdirectory(L2_2)
add_subdirectory(L3)


#include(CTest)
#enable_testing()

#add_executable(tester "${PROJECT_SOURCE_DIR}/L2_2/tests/tester.cpp")
#add_test(Test1 tester 2 2)
#add_test(Test2 tester 4 4)
#add_test(Test3 tester 6 6 6)

#set_tests_properties( Test1 Test2 Test3 PROPERTIES TIMEOUT 1)

#set_tests_properties( Test1 PROPERTIES
#PASS_REGULAR_EXPRESSION "2 - 2"
#FAIL_REGULAR_EXPRESSION "ERROR!")

#set_tests_properties( Test2 PROPERTIES
#PASS_REGULAR_EXPRESSION "4 - 4"
#FAIL_REGULAR_EXPRESSION "ERROR!")
#
#set_tests_properties( Test3 PROPERTIES
#PASS_REGULAR_EXPRESSION "ERROR!")