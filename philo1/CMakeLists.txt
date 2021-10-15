cmake_minimum_required(VERSION 3.19)
project(philo C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-I../includes/")

file(GLOB SRC srcs/*.c)

add_executable(philo ${SRC})