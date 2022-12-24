#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(${Words_SOURCE_DIR}/include)

add_executable(Words_Tests_run
               src/wString_test.cpp
               src/wBst_test.cpp
               src/vector_test.cpp
               src/helper_test.cpp
               src/hashMap_test.cpp
               src/counter_hash_map_test.cpp
               src/counter_bst_test.cpp
               src/counter_base_test.cpp
               src/counter_test.cpp
               )

target_link_libraries(Words_Tests_run
                      gtest_main
                      cw_string::lib
                      )

include(GoogleTest)
gtest_discover_tests(Words_Tests_run)