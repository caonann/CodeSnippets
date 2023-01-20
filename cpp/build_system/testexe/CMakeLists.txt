add_executable(testexe)
target_sources(testexe PRIVATE main.cpp)
target_link_libraries(testexe PRIVATE testlib)