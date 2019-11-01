cmake_minimum_required(VERSION 2.8)

project(OOP_2)

set(SOURCE_EXE 2.cpp)

set(SOURCE_LIB Rectangle.cpp)

add_library(Rectangle STATIC ${SOURCE_LIB})

add_executable(2 ${SOURCE_EXE})

target_link_libraries(2 Rectangle)