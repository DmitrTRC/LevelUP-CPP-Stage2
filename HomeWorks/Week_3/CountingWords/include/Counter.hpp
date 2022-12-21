//
// Created by Dmitry Morozov on 18/12/22.
//

#ifndef LEVELUP_CPP_MAIN_COUNTER_HPP
#define LEVELUP_CPP_MAIN_COUNTER_HPP

#include "Counter_Base.hpp"


#include <sstream>
#include <unordered_map>


class Counter : public CounterBase {
public:
    explicit Counter(const std::wstring &buffer) : CounterBase(buffer) {}

    void load() override;

    int get(std::wstring &word) override;

private:
    std::unordered_map<std::wstring, int> map_;

    void adder(std::wstring &word) override;

};


#endif //LEVELUP_CPP_MAIN_COUNTER_HPP
