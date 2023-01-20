cmake_minimum_required(VERSION 3.20)
project(TestPrj VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(THIRD_PARTY "${PROJECT_SOURCE_DIR}/third_party")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -Wall -fPIC -D_GNU_SOURCE")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g -ggdb")#Debug模式下的编译指令
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3")#Release模式下的编译指令

add_subdirectory(testexe)
add_subdirectory(testlib)
add_subdirectory(testlib2)