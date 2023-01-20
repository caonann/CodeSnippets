#!/bin/bash
TARGET=' -DCMAKE_EXPORT_COMPILE_COMMANDS=1 '



echo "${TARGET}" 

mkdir -p ./build

cd ./build || exit 
rm -rf *
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 "${TARGET}" ../; make;
