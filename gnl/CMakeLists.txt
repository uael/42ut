cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 OLD)
cmake_policy(SET CMP0045 OLD)

project(gnl C)

set(BUILD_SHARED_LIBS OFF)

set(gnl_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(gnl_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)

set(CMAKE_C_FLAGS "")
set(CMAKE_C_FLAGS_DEBUG "")
set(CMAKE_C_FLAGS_RELEASE "")

add_library(gnl ${gnl_SRC_DIR}/get_next_line.c ${gnl_INC_DIR}/get_next_line.h)
set_property(TARGET gnl PROPERTY C_STANDARD 90)
target_include_directories(gnl PUBLIC ${gnl_INC_DIR})
target_link_libraries(gnl PUBLIC ft)

target_compile_definitions(gnl
        PRIVATE $<$<CONFIG:Debug>:DEBUG>$<$<CONFIG:Release>:NDEBUG>
        PRIVATE API_COMPILE)
if (MSVC)
  target_compile_options(gnl
          PRIVATE /MT$<$<CONFIG:Debug>:d> /Oy /W3
          PRIVATE /D_CRT_SECURE_NO_WARNINGS /Dinline=__inline
          PRIVATE /O$<$<CONFIG:Debug>:d>$<$<CONFIG:Release>:x>)
else ()
  target_compile_options(gnl
          PRIVATE -Wall -Werror -Wextra -fomit-frame-pointer -ansi
          PRIVATE -Wno-missing-field-initializers -Wno-missing-braces
          PRIVATE -O$<$<CONFIG:Debug>:0 -g3>$<$<CONFIG:Release>:3>)
endif ()

file(GLOB gnl_tests_SRCS ${gnl_tests_SRCS} ${CMAKE_CURRENT_LIST_DIR}/test_*.c)
foreach (gnl_tests_SRC ${gnl_tests_SRCS})
  get_filename_component(gnl_test_NAME ${gnl_tests_SRC} NAME_WE)
  set(test ${gnl_test_NAME})
  add_executable(${test} ${gnl_tests_SRC})
  add_dependencies(${test} gnl)
  add_dependencies(check ${test})
  target_link_libraries(${test} gnl ft)
  target_compile_definitions(${test}
    PRIVATE $<$<CONFIG:Debug>:DEBUG>$<$<CONFIG:Release>:NDEBUG>)
  add_test(${test} ${test} WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
  if (MSVC)
    target_compile_options(${test}
      PRIVATE /MTd /Oy /W3
      PRIVATE /D_CRT_SECURE_NO_WARNINGS
      PRIVATE /Od)
  else ()
    target_compile_options(${test}
      PRIVATE -fomit-frame-pointer -ansi
      PRIVATE -O0 -g3)
  endif ()
endforeach ()
