cmake_minimum_required(VERSION 3.20)

project(LeetCode2)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${LeetCode2_SOURCE_DIR}/bin)
message(STATUS "LeetCode1 directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
#add_library(leet_lib STATIC
#
#            )
#
#add_executable(main src/main.cpp)
#
#target_link_libraries(main leet_lib)
#
#
