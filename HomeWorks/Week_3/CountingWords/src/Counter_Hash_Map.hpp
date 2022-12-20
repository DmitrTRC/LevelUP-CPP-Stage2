//
// Created by Dmitry Morozov on 18/12/22.
//

#ifndef LEVELUP_CPP_MAIN_COUNTER_HASH_MAP_HPP
#define LEVELUP_CPP_MAIN_COUNTER_HASH_MAP_HPP

#include "Counter_Base.hpp"
#include "Hash_Map.hpp"

#include <sstream>


class CounterHashMap : public CounterBase<std::wstring> {


public:
    explicit CounterHashMap(const std::wstring &buffer) : CounterBase(buffer) {}


    int get(std::wstring &word) override;

private:
    HashMap map_;

    void adder(std::wstring &word) override;

};


#endif //LEVELUP_CPP_MAIN_COUNTER_HASH_MAP_HPP
