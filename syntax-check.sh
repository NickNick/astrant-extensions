#!/bin/bash

for i in *.hpp; do
	g++-fsf-4.8 -std=c++11 -fsyntax-only "${i}"
done
