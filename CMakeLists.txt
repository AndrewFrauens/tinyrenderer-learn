cmake_minimum_required( VERSION 3.1 )

project( tiny_renderer )


add_subdirectory( src )

file(GLOB SOURCES "src/*.cpp")

add_executable(tiny_renderer_execute ${SOURCES})