cmake_minimum_required( VERSION 3.1 )


#if cmake is called with no arguments, default to release mode CMAKE_BUILD_TYPE
if(NOT CMAKE_BUILD_TYPE) 
  set(CMAKE_BUILD_TYPE Release)
endif()


set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -pedantic -Wall -Wextra")
endif(CMAKE_COMPILER_IS_GNUCXX)

project( tiny_renderer )


add_subdirectory( src )

file(GLOB SOURCES "src/*.cpp")

add_executable(tiny_renderer_execute ${SOURCES})