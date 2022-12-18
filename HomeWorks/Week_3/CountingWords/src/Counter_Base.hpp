//
// Created by Dmitry Morozov on 18/12/22.
//

#ifndef LEVELUP_CPP_MAIN_COUNTER_BASE_HPP
#define LEVELUP_CPP_MAIN_COUNTER_BASE_HPP

#include <sstream>
#include <chrono>

class CounterBase {
public:

    explicit CounterBase(const std::wstring &buffer);

    ~CounterBase();

    void load();

    [[nodiscard]] size_t total_words() const;

    void load_me();

    virtual int get(std::wstring &word) = 0;

protected:

    std::wistringstream *buffer_;

    virtual void adder(std::wstring &word) = 0;

private:
    size_t total_words_;

};


#endif //LEVELUP_CPP_MAIN_COUNTER_BASE_HPP
