//
// Created by Dmitry Morozov on 18/12/22.
//

#ifndef LEVELUP_CPP_MAIN_COUNTER_BASE_HPP
#define LEVELUP_CPP_MAIN_COUNTER_BASE_HPP

#include "Helper.hpp"
#include "String.hpp"

#include <sstream>
#include <chrono>


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

        if (!lWord.empty()) {

            adder(lWord);
            total_words_++;

        }

    }


}

template<class T>
void CounterBase<T>::load_me() {

    auto start = std::chrono::steady_clock::now();

    load();

    auto end = std::chrono::steady_clock::now();

    std::cerr << "Time to load MAP : " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;


}

template<class T>
size_t CounterBase<T>::total_words() const {

    return total_words_;

}


#endif //LEVELUP_CPP_MAIN_COUNTER_BASE_HPP
