#!/bin/bash

${CXX:=clang++}

if [[ $# -gt 0 ]]; then
	pattern="$1"
else
	pattern='*.hpp'
fi

for i in ${pattern}; do
	${CXX} -fsyntax-only -std=c++11 "${i}"
done
