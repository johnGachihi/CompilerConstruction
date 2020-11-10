cmake_minimum_required(VERSION 3.17)
project(CompilerConstruction)

set(CMAKE_CXX_STANDARD 20)

add_executable(CompilerConstruction main.cpp lexer.cpp lexer.h exceptions.h)

add_subdirectory(Google_tests)