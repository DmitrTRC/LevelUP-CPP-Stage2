
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(${Words_SOURCE_DIR}/src/)

add_executable(Words_Tests_run
               wString_test.cpp
               )

target_link_libraries(Words_Tests_run
                      gtest_main
                      )

include(GoogleTest)
gtest_discover_tests(Words_Tests_run)