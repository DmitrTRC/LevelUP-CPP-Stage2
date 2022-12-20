cmake_minimum_required(VERSION 3.16)

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
        src/W_Bst.cpp
        src/String.cpp
        src/Hash_Map.cpp
        src/Vector.cpp
        src/Counter.cpp
        src/Counter_Base.cpp
        #        src/Counter_Hash_Map.cpp
        #        src/Counter_Bst.cpp
)
