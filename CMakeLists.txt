cmake_minimum_required(VERSION 3.0.0)
project(EpamLab VERSION 0.1.0)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules
                      ${CMAKE_MODULE_PATH})


find_package(CppCheck)

set(ALL_ANALYSIS_TARGETS)

add_subdirectory(L1)
add_subdirectory(L2)
add_subdirectory(L2_2)
add_subdirectory(L3)
#add_subdirectory(L4)
#add_subdirectory(L5)
add_subdirectory(L6_Templates)

# Add the "make analysis" target
if( CPPCHECK_FOUND )
    add_custom_target(analysis)
    ADD_DEPENDENCIES(analysis ${ALL_ANALYSIS_TARGETS})
    set_target_properties(analysis PROPERTIES EXCLUDE_FROM_ALL TRUE)
    message("analysis analysis targets are ${ALL_ANALYSIS_TARGETS}")
endif()