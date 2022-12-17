//
// Created by Dmitry Morozov on 18/12/22.
//

#ifndef LEVELUP_CPP_MAIN_COUNTER_HPP
#define LEVELUP_CPP_MAIN_COUNTER_HPP

#include "W_Bst.hpp"
#include "Hash_Map.hpp"

#include <iostream>
#include <sstream>
#include <unordered_map>


template<class T>
class Counter {
public:
    Counter(const std::wstring &buffer) {


    }

    void count();


    void get(std::wstring &word);

private:
    T map_;
    std::wstringstream buffer_;
};

#endif //LEVELUP_CPP_MAIN_COUNTER_HPP
