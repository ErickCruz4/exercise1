cmake_minimum_required(VERSION 3.10)
project(exercise1)

set(CMAKE_C_STANDARD 99)


include_directories(include)


add_executable(exercise1 src/main.c src/functions.c)
