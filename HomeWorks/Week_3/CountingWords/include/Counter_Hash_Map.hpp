//
// Created by Dmitry Morozov on 18/12/22.
//

#ifndef LEVELUP_CPP_MAIN_COUNTER_HASH_MAP_HPP
#define LEVELUP_CPP_MAIN_COUNTER_HASH_MAP_HPP


#include "Counter_Base.hpp"
#include "Hash_Map.hpp"
#include "String.hpp"

#include <sstream>


class CounterHashMap : public CounterBase {


public:
    explicit CounterHashMap(const std::wstring &buffer) : CounterBase(buffer) {}


    int get(wString &word) override;

    int get(std::wstring &word) override;

private:
    HashMap<wString> map_;

    void adder(wString &word) override;

};


#endif //LEVELUP_CPP_MAIN_COUNTER_HASH_MAP_HPP
