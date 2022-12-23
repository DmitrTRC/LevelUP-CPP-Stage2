
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(${Words_SOURCE_DIR}/include)

add_executable(Words_Tests_run
               src/wString_test.cpp
               src/wBst_test.cpp
               src/vector_test.cpp
               )

target_link_libraries(Words_Tests_run
                      gtest_main
                      cw_string::lib
                      )

include(GoogleTest)
gtest_discover_tests(Words_Tests_run)