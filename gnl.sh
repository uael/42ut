#!/usr/bin/env bash

source 'lib.sh'

PROJECT_PATH=$1

function donorm {
  local pids=""
  norm_file ${PROJECT_PATH}/get_next_line.h &
  pids="$pids $!"
  norm_file ${PROJECT_PATH}/get_next_line.c &
  pids="$pids $!"
  wait ${pids}
  out=$(cat ${NORM_OUT})
  if [[ ! -z ${out} ]]; then
    echo -e "\n$out"
    exit 1
  fi
  exit 0
}

function dotest {
  local test=$1
  clang -Wall -Wextra -Werror -I ${PROJECT_PATH}/libft/includes -oout/gnl/$(basename "${test%.*}").o -c ${test}
  clang -oout/gnl/$(basename "${test%.*}") out/gnl/$(basename "${test%.*}").o out/gnl/get_next_line.o -I ${PROJECT_PATH}/libft/includes -L ${PROJECT_PATH}/libft/ -lft
  ./out/gnl/$(basename "${test%.*}")
}

mkdir -p out/gnl
job "Make" "make libft all" "make -C${PROJECT_PATH}/libft"
job "Make" "compile" "clang -Wall -Wextra -Werror -I ${PROJECT_PATH}/libft/includes -o out/gnl/get_next_line.o -c ${PROJECT_PATH}/get_next_line.c"
for test in ./gnl/test_*.c; do
  job "Test" "$(basename "${test%.*}")" "dotest ${test}"
done
job "Norm" "all" "donorm"

rm ${OUT}
rm ${NORM_OUT}
