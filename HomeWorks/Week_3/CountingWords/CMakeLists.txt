cmake_minimum_required(VERSION 3.16)

project(Words_Lib)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Words_Lib_SOURCE_DIR}/bin)
message(STATUS "Words Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")


############################################################
# Create a library
############################################################

#Generate the shared library from the library sources

add_library(Words_Lib SHARED
            src/Helper.cpp
            src/W_Bst.cpp
            src/String.cpp
            src/Hash_Map.cpp
            src/Vector.cpp
            src/Counter.cpp
            src/Counter_Base.cpp
            src/Counter_Hash_Map.cpp
            src/Counter_Bst.cpp
            )

add_library(cw_string::lib ALIAS Words_Lib)

target_include_directories(Words_Lib
                           PUBLIC
                           ${PROJECT_SOURCE_DIR}/include
                           )

############################################################
# Create an executable
############################################################

# Add an executable with the above sources

add_executable(Words src/main.cpp)

# link the new hello_library target with the hello_binary target

target_link_libraries(Words PRIVATE
                      cw_string::lib
                      )

# Tests
add_subdirectory(tests)
