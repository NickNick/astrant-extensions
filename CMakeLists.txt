cmake_minimum_required(VERSION 2.8.12)

project(astrant-extensions)

file(GLOB headers "*.hpp")
file(GLOB sources "*.cpp")
add_library(astrant-extensions SHARED ${sources} ${headers})
target_include_directories(astrant-extensions
	INTERFACE
		$<BUILD_INTERFACE:"..">
)
set_target_properties(astrant-extensions PROPERTIES LINKER_LANGUAGE CXX)

find_package(wubwubcmake)
if(wubwubcmake_DIR)
	include(sane_install)
	sane_install(TARGETS astrant-extensions HEADERS ${headers})
endif()
