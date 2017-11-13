project(fillit C)

file(GLOB_RECURSE fillit_HDRS ${fillit_HDRS} src/include/*.h)
file(GLOB fillit_SRCS ${fillit_SRCS} src/src/*.c)

add_executable(fillit ${fillit_HDRS} ${fillit_SRCS})
add_dependencies(fillit ft)
target_include_directories(fillit PUBLIC src/include)
target_link_libraries(fillit ft)
target_compile_options(fillit
  PRIVATE -fomit-frame-pointer -ansi
  PRIVATE -O3)

file(GLOB fillit_tests_SRCS ${fillit_tests_SRCS} ${CMAKE_CURRENT_LIST_DIR}/test_*.c)
foreach (fillit_tests_SRC ${fillit_tests_SRCS})
  get_filename_component(fillit_test_NAME ${fillit_tests_SRC} NAME_WE)
  set(test ${fillit_test_NAME})
  add_executable(${test} ${fillit_tests_SRC})
  add_dependencies(${test} fillit)
  add_dependencies(check ${test})
  target_link_libraries(${test} fillit ft)
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
