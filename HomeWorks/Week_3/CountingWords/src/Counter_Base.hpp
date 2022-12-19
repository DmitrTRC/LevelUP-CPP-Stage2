//
// Created by Dmitry Morozov on 18/12/22.
//

#ifndef LEVELUP_CPP_MAIN_COUNTER_BASE_HPP
#define LEVELUP_CPP_MAIN_COUNTER_BASE_HPP

#include "String.hpp"

#include <sstream>
#include <chrono>
#include <variant>

template<class T>
class CounterBase {
public:

    explicit CounterBase(const T &buffer) : total_words_(0) {

        buffer_ = new std::wistringstream(buffer);

    }


    ~CounterBase();

    void load();

    [[nodiscard]] size_t total_words() const;

    void load_me();

    virtual int get(T &word) = 0;

protected:

    std::wistringstream *buffer_;

    virtual void adder(T &word) = 0;

private:
    size_t total_words_;

};

//Destructor

template<class T>
CounterBase<T>::~CounterBase() {

    delete buffer_;

}

template<class T>
void CounterBase<T>::load() {

    std::locale loc = std::locale("ru_RU.UTF-8");

    T word;

    while (*buffer_ >> word) {
        trim_punctuation(word);

        auto lWord = toLowerRus(word, loc);

        if (!word.empty()) {

            adder(word);
            total_words_++;

        }

    }


}


#endif //LEVELUP_CPP_MAIN_COUNTER_BASE_HPP
