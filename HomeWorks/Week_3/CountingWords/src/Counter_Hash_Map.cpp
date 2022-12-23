//
// Created by Dmitry Morozov on 18/12/22.
//

#include "Counter_Hash_Map.hpp"
#include "String.hpp"


void CounterHashMap::adder(wString &word) {

    map_[word]++;

}

int CounterHashMap::get(wString &word) {

    return map_[word];
}

int CounterHashMap::get(std::wstring &word) { // Fixme: wstring -> wString

    wString temp_wS(word.c_str());

    return map_[temp_wS];
}
