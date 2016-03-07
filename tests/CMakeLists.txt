cmake_minimum_required(VERSION 2.8.12)
project(tests)
find_package(astrant-extensions REQUIRED)

add_definitions("-std=c++11")

add_executable(checker check.cpp map_merge.cpp)
add_custom_target(check
	DEPENDS checker
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
	COMMAND tests/checker
)
add_test(NAME check WORKING_DIRECTORY ${CMAKE_BINARY_DIR} COMMAND checker)
