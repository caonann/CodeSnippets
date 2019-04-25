cmake_minimum_required(VERSION 2.8)
project(cpp11_demo C CXX)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(mulity_thread)
add_subdirectory(stability)
