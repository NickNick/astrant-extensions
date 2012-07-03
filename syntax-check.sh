#!/bin/bash

for i in *.hpp; do
	g++-fsf-4.6 -fsyntax-only "${i}"
done
