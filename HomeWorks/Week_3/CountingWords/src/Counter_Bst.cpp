//
// Created by Dmitry Morozov on 18/12/22.
//

#include "Counter_Bst.hpp"

int CounterBST::get(std::wstring &word) {

    return map_.Search(word);
}

void CounterBST::adder(std::wstring &word) {

    map_.Add(word);

}
