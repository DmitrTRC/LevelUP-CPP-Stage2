//
// Created by Dmitry Morozov on 18/12/22.
//

#ifndef LEVELUP_CPP_MAIN_COUNTER_BASE_HPP
#define LEVELUP_CPP_MAIN_COUNTER_BASE_HPP

#include "Helper.hpp"
#include "String.hpp"

#include <sstream>
#include <chrono>


class CounterBase {
public:

    explicit CounterBase(const std::wstring &buffer) : total_words_(0) {

        buffer_ = new std::wistringstream(buffer);

    }


    ~CounterBase();

    void load();

    [[nodiscard]] size_t total_words() const;

    void load_me();

    virtual int get(wString &word) {

        throw std::runtime_error("Not implemented");
    };

    virtual int get(std::wstring &word) {

        throw std::runtime_error("Not implemented");
    }

protected:

    std::wistringstream *buffer_;

    virtual void adder(wString &word) {

        throw std::runtime_error("Not implemented");


    }

    virtual void adder(std::wstring &word) {

        throw std::runtime_error("Not implemented");
    }

private:
    size_t total_words_;


};




#endif //LEVELUP_CPP_MAIN_COUNTER_BASE_HPP
