cmake_minimum_required(VERSION 3.16.0)
project(ttmathengine)

#headers
include_directories(include)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
	add_subdirectory(tests)
endif()

#source files
set(SOURCES src/ttmathengine.cpp)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
	set(TESTS tests/vectortests.cpp)
endif()

file(GLOB SOURCES src/*.cpp)

add_library(ttmathengine STATIC ${SOURCES})
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
	add_executable(tests ${TESTS})

	target_link_libraries(tests ttmathengine)
	#Set's Visual Studios "Startup Project" (default project to run) to test
	set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT tests)
endif()