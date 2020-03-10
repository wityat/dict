cmake_minimum_required(VERSION 3.15)
project(dict C)

set(CMAKE_C_STANDARD 11)

add_executable(dict main.c dict.h dict.c value.h)