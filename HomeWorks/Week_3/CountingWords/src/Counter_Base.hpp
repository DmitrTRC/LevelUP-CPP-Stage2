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


CounterBase::~CounterBase() {

    delete buffer_;

}

void CounterBase::load() {

    std::locale loc = std::locale("ru_RU.UTF-8");

    wString word;

    while (*buffer_ >> word) {
        trim_punctuation(word);

        auto lWord = toLowerRus(word, loc);

        if (!lWord.empty()) {

            adder(lWord);
            total_words_++;

        }

    }


}

void CounterBase::load_me() {

    auto start = std::chrono::steady_clock::now();

    load();

    auto end = std::chrono::steady_clock::now();

    std::cerr << "Time to load MAP : " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;


}


size_t CounterBase::total_words() const {

    return total_words_;

}


#endif //LEVELUP_CPP_MAIN_COUNTER_BASE_HPP
