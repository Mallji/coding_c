cmake_minimum_required(VERSION 3.26)
project(coding)

set(CMAKE_CXX_STANDARD 17)

add_executable(coding main.cpp)

add_executable(main main.cpp)

add_executable(GridFetchNumber lougu/GridFetchNumber.cpp)
