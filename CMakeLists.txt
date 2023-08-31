cmake_minimum_required(VERSION 3.27)
project(cpuinfo)

find_package(cpuid CONFIG REQUIRED)

add_executable(cpuinfo cpuinfo.cxx)
target_link_libraries(cpuinfo PRIVATE cpuid::cpuid)
