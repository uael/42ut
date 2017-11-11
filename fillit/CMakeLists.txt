add_subdirectory(src)

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
