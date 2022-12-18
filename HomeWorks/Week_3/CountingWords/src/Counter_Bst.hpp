//
// Created by Dmitry Morozov on 18/12/22.
//

#ifndef LEVELUP_CPP_MAIN_COUNTER_BST_HPP
#define LEVELUP_CPP_MAIN_COUNTER_BST_HPP

#include "Counter_Base.hpp"
#include "W_Bst.hpp"

#include <sstream>


class CounterBST : public CounterBase {


public:
    explicit CounterBST(const std::wstring &buffer) : CounterBase(buffer) {}


    int get(std::wstring &word) override;

private:
    wBST map_;

    void adder(std::wstring &word) override;

};


#endif //LEVELUP_CPP_MAIN_COUNTER_BST_HPP