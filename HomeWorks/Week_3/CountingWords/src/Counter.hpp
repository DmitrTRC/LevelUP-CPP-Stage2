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
    explicit Counter(const std::wstring &buffer) {

        buffer_ = new std::wistringstream(buffer);

    }

    void load();


    void get(std::wstring &word);

private:
    T map_;

    void adder(std::wstring &word);

    std::wistringstream *buffer_;
};

template<class T>
void Counter<T>::load() {

    std::wstring word;
    while (*buffer_ >> word) {
        adder(word);
    }


}

#endif //LEVELUP_CPP_MAIN_COUNTER_HPP
