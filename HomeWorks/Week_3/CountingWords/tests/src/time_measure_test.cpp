//
// Created by Dmitry Morozov on 25/12/22.
//

#include "gtest/gtest.h"

#include "T_Measure.hpp"

#include <functional>


TEST(TMeasure, Measure_Time) {

    std::function<int(int)> fibonacci = [&fibonacci](int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);
    };

    auto dt = measure_time(fibonacci, 30);

    EXPECT_GT(dt, 0);
}

