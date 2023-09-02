cmake_minimum_required(VERSION 3.27)
project(cpuinfo)

find_package(cpuid CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_library(cpuinfo cpuinfo.cxx)
add_executable(cpu-info main.cxx)
add_executable(tests tests.cxx)
add_executable(numbertests numbertests.cxx)

target_link_libraries(cpu-info cpuinfo)
target_link_libraries(tests cpuinfo)
target_link_libraries(numbertests cpuinfo)
target_link_libraries(cpuinfo cpuid::cpuid)
target_link_libraries(cpuinfo fmt::fmt)

enable_testing()
add_test(NAME smoke COMMAND cpu-info)
add_test(NAME negative COMMAND tests)
add_test(NAME number COMMAND numbertests)
