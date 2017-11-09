project(libft C)

add_subdirectory(src)

file(GLOB libft_tests_SRCS ${libft_tests_SRCS} ${CMAKE_CURRENT_LIST_DIR}/test_*.c)
foreach (libft_tests_SRC ${libft_tests_SRCS})
  get_filename_component(libft_test_NAME ${libft_tests_SRC} NAME_WE)
  set(test ${libft_test_NAME})
  add_executable(${test} ${libft_tests_SRC})
  add_dependencies(${test} ft)
  add_dependencies(check ${test})
  target_link_libraries(${test} ft)
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
