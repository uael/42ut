#!/usr/bin/env bash

source 'lib.sh'

PROJECT_PATH=$1

function donorm {
  local pids=""
  for file in ${PROJECT_PATH}/include/*.h; do
    norm_file ${file} &
    pids="$pids $!"
  done
  for file in ${PROJECT_PATH}/src/*.c; do
    norm_file ${file} &
    pids="$pids $!"
  done
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
  local test_out="./out/fillit/$(basename "${test%.*}").out"
  local test_expected="./fillit/$(basename "${test%.*}").expected"
  mkdir -p out/fillit
  ./${PROJECT_PATH}/fillit ${test} > ${test_out}
  diff ${test_out} ${test_expected}
}

function dotest_noarg {
  local test_out="./out/fillit/test_noarg.out"
  local test_expected="./fillit/test_noarg.expected"
  mkdir -p out/fillit
  ./${PROJECT_PATH}/fillit ${test} > ${test_out}
  diff ${test_out} ${test_expected}
}

job "Make" "make all" "make -C${PROJECT_PATH} all"
job "Make" "make clean" "make -C${PROJECT_PATH} clean"
  job "Test" "noarg" dotest_noarg
for test in ./fillit/test_*.fillit; do
  job "Test" "$(basename "${test%.*}")" "dotest ${test}"
done
job "Norm" "all" "donorm"

rm ${OUT}
rm ${NORM_OUT}
