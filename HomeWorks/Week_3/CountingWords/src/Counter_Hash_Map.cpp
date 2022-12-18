//
// Created by Dmitry Morozov on 18/12/22.
//

#include "Counter_Hash_Map.hpp"

void CounterHashMap::adder(std::wstring &word) {

    map_[word]++;

}

int CounterHashMap::get(std::wstring &word) {

    return map_[word];
}
