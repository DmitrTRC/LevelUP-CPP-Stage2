cmake_minimum_required(VERSION 3.20)

project(String_Demo)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${String_Demo_SOURCE_DIR}/bin)
message(STATUS "String_Lib Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable( String_Demo
        src/String.cpp
        src/main.cpp
)

