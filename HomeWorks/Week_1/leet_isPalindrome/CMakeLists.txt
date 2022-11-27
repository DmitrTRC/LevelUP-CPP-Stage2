cmake_minimum_required(VERSION 3.20)

project(is_palindrome)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${is_palindrome_SOURCE_DIR}/bin)
message(STATUS "is_palindrome Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        is_palindrome
        src/main.cpp
)

