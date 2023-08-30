cmake_minimum_required(VERSION 3.27)
project(cpuinfo)

find_package(cpuid CONFIG REQUIRED)

add_executable(hello_world hello.cxx)
