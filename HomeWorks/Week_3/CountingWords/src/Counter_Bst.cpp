//
// Created by Dmitry Morozov on 18/12/22.
//


#include "Counter_Bst.hpp"
#include "String.hpp"

int CounterBST::get(wString &word) {

    return map_.Search(word);
}

void CounterBST::adder(wString &word) {

    map_.Add(word);

}

