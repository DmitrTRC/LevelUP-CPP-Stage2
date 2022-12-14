cmake_minimum_required(VERSION 3.20)

project(Words)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Words_SOURCE_DIR}/bin)
message(STATUS "Words Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(
        Words
        src/main.cpp
        src/Helper.cpp

)
