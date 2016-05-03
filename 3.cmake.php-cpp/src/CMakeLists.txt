# Configuration
cmake_minimum_required (VERSION 2.6)
project (TypoScript)
set (TypoScript_VERSION_MAJOR 0)
set (TypoScript_VERSION_MINOR 1)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Add -undefined dynamic_lookup flag for OS X
if(APPLE)
    message(STATUS "Adding fix for OS X")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -undefined dynamic_lookup")
endif()

# Check if compiler supports C++11 and add -std=c++11 flag
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has C++11 support. Moving on.")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(CMAKE_SHARED_LINKER_FLAGS "-lphpcpp")

add_library(typoscript SHARED typoscript.cpp)

install(TARGETS typoscript DESTINATION /Users/ElmarHinz/Homebrew/Cellar/php56/5.6.21/lib/php/extensions/no-debug-non-zts-20131226/)

