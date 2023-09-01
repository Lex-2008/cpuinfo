cmake_minimum_required(VERSION 3.27)
project(cpuinfo)

find_package(cpuid CONFIG REQUIRED)

add_library(cpuinfo cpuinfo.cxx)
add_executable(cpu-info main.cxx)

target_link_libraries(cpu-info cpuinfo)
target_link_libraries(cpuinfo cpuid::cpuid)
