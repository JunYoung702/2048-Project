cmake_minimum_required(VERSION 3.15)
project(2048 C)

set(CMAKE_C_STANDARD 11)

add_executable(2048-Project ./2048main.c lib-cross.c mainfeatures.c)
