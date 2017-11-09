#!/usr/bin/env bash

source 'lib.sh'

PROJECT_PATH=$1

function donorm {
    local pids=""
    norm_file ${PROJECT_PATH}/libft.h &
    pids="$pids $!"
    for file in ${PROJECT_PATH}/ft_*.c; do
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
    mkdir -p out/libft
    gcc ${test} -L${PROJECT_PATH} -lft -I${PROJECT_PATH} -oout/libft/$(basename "${test%.*}")
    ./out/libft/$(basename "${test%.*}")
}

job "Make" "make all" "make -C${PROJECT_PATH} all"
job "Make" "make clean" "make -C${PROJECT_PATH} clean"
for test in ./libft/test_*.c; do
    job "Test" "$(basename "${test%.*}")" "dotest ${test}"
done
job "Norm" "all" "donorm"

rm ${OUT}
rm ${NORM_OUT}
