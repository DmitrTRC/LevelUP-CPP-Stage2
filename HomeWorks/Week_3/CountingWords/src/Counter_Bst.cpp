//
// Created by Dmitry Morozov on 18/12/22.
//


#include "Counter_Bst.hpp"
#include "String.hpp"

int CounterBST::get(wString &word) {

    std::cout << "CounterBST::get<wString>" << std::endl;
    return map_.Search(word);
}

void CounterBST::adder(wString &word) {

    map_.Add(word);

}

int CounterBST::get(std::wstring &word) {

    std::cout << "CounterBST::get<wstring>" << std::endl;
    wString temp_wS(word.c_str());

    auto result = map_.Search(temp_wS);
    return result;
}

