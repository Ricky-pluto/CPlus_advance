cmake_minimum_required(VERSION 3.15)
project(effectivedemo)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -fno-elide-constructors)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(一、类型推导)
add_subdirectory(二、auto)
add_subdirectory(三、移步现代C++)
add_subdirectory(四、智能指针)

