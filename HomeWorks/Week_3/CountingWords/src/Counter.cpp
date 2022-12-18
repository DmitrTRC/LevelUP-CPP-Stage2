//
// Created by Dmitry Morozov on 18/12/22.
//

#include "Counter.hpp"


void Counter::adder(std::wstring &word) {

    map_[word]++;

}

int Counter::get(std::wstring &word) {

    return map_[word];
}
