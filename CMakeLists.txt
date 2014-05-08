cmake_minimum_required(VERSION 2.8.12)

project(astrant)

add_library(astrant-extensions SHARED)
target_include_directories(astrant-extensions INTERFACE "..")
set_target_properties(astrant-extensions PROPERTIES LINKER_LANGUAGE CXX)
