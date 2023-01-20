add_library(testlib STATIC)
target_sources(testlib PRIVATE testlib.cpp)
target_include_directories(testlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(testlib PUBLIC testlib2)