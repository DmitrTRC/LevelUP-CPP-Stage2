//
// Created by Dmitry Morozov on 8/1/23.
//

#include "hashf.hpp"
#include "String.hpp"


[[nodiscard]] int dHashFunction(const wString &word, int size, const int key) {

    int hash = 0;

    for (auto &c: word) {

        hash = (key * hash + c) % size;

    }

    hash = (hash * 2 + 1) % size;


    return hash;
}