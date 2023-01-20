add_library(testlib2 STATIC)
target_sources(testlib2 PRIVATE testlib2.cpp)
target_include_directories(testlib2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})