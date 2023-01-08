//
// Created by Dmitry Morozov on 8/1/23.
//

#ifndef LEVELUP_CPP_MAIN_HASHF_HPP
#define LEVELUP_CPP_MAIN_HASHF_HPP

#include "String.hpp"

[[nodiscard]] int dHashFunction(const wString &, int, int);

struct hashFunc_1 {
    int operator()(const wString &word, int size) const {

        return dHashFunction(word, size, size - 1);
    }
};

struct hashFunc_2 {
    int operator()(const wString &word, int size) const {

        return dHashFunction(word, size, size + 1);
    }
};

#endif //LEVELUP_CPP_MAIN_HASHF_HPP
