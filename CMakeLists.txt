cmake_minimum_required(VERSION 3.15)
project(effectivedemo)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -fno-elide-constructors)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")

add_subdirectory(一、类型推导)