//
// Created by Dmitry Morozov on 7/1/23.
//

#include "Counter_Dhash.hpp"
#include "String.hpp"

void Counter_dhash::adder(wString &word) {

    map_.Insert(word);

}

int Counter_dhash::get(wString &word) {

    return map_.Get(word);

}

int Counter_dhash::get(std::wstring &word) {

    wString temp_wS(word.c_str());

    return map_.Get(temp_wS);

}


