cmake_minimum_required(VERSION 3.0)

project(astrant-extensions)

add_library(astrant-extensions INTERFACE)
target_include_directories(astrant-extensions INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..> )

find_package(wubwubcmake 1)
if(wubwubcmake_DIR)
	include(wubwubcmake/sane_install)
	file(GLOB headers "*.hpp")
	sane_install(TARGETS astrant-extensions HEADERS ${headers})
endif()
