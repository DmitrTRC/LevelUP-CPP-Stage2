//
// Created by Dmitry Morozov on 25/12/22.
//

#ifndef LEVELUP_CPP_MAIN_T_MEASURE_HPP
#define LEVELUP_CPP_MAIN_T_MEASURE_HPP

#include <chrono>


template<typename Func, typename... Args>
long long measure_time(Func func, Args... args) {
    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();

    // Call function
    func(args...);

    // Stop measuring time
    auto stop = std::chrono::high_resolution_clock::now();

    // Calculate elapsed time
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    return duration.count();
}


#endif //LEVELUP_CPP_MAIN_T_MEASURE_HPP
