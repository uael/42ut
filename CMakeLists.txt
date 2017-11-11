cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 OLD)
cmake_policy(SET CMP0045 OLD)

project(42ut C)
get_directory_property(42ut_PARENT PARENT_DIRECTORY)

set(BUILD_SHARED_LIBS OFF)

enable_testing()
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})

add_subdirectory(libft)
add_subdirectory(gnl)
add_subdirectory(fillit)
