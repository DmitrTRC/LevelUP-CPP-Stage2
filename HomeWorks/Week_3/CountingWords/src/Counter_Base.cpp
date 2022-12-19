//
// Created by Dmitry Morozov on 18/12/22.
//

#include "Counter_Base.hpp"
#include "Helper.hpp"

#include <chrono>
#include <iostream>


//CounterBase::CounterBase(const std::wstring &buffer) : total_words_(0) {
//
//    buffer_ = new std::wistringstream(buffer);
//
//}



void CounterBase::load_me() {

    auto start = std::chrono::steady_clock::now();

    load();

    auto end = std::chrono::steady_clock::now();

    std::cerr << "Time to load MAP : " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;


}


size_t CounterBase::total_words() const {

    return total_words_;
}



