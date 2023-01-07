//
// Created by Dmitry Morozov on 7/1/23.
//

#ifndef LEVELUP_CPP_MAIN_COUNTER_DHASH_HPP
#define LEVELUP_CPP_MAIN_COUNTER_DHASH_HPP

#include "Counter_Base.hpp"
#include "D_Hash.hpp"
#include "String.hpp"

#include <iostream>

class Counter_dhash : public CounterBase {

public:
    explicit Counter_dhash(const std::wstring &buffer) : CounterBase(buffer) {}

    int get(wString &) override;

    int get(std::wstring &) override;

private:

    DHash<wString> map_;

    void adder(wString &) override;
};

#endif //LEVELUP_CPP_MAIN_COUNTER_DHASH_HPP
