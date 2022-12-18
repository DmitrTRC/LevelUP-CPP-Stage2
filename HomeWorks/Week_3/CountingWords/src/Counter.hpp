//
// Created by Dmitry Morozov on 18/12/22.
//

#ifndef LEVELUP_CPP_MAIN_COUNTER_HPP
#define LEVELUP_CPP_MAIN_COUNTER_HPP

#include "Helper.hpp"
#include "W_Bst.hpp"
#include "Hash_Map.hpp"

#include <iostream>
#include <sstream>
#include <unordered_map>

#define MEASURE_TIME

template<class T>
class Counter {
public:
    explicit Counter(const std::wstring &buffer) {

        buffer_ = new std::wistringstream(buffer);

    }

    void load();


    void get(std::wstring &word);

private:
    T map_;

    void adder(std::wstring &word);

    std::wistringstream *buffer_;
};

template<class T>
void Counter<T>::load() {

#ifdef MEASURE_TIME
    auto start = std::chrono::steady_clock::now();
#endif

    std::wstring word;
    while (*buffer_ >> word) {
        trim_punctuation(word);

        auto lWord = toLowerRus(word, loc);

        if (!word.empty()) {
            adder(word);
        }

    }

#ifdef MEASURE_TIME
    auto end = std::chrono::steady_clock::now();
    std::cerr << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms"
              << std::endl;
#endif
}

//Adder for Hash_Map
template<>
void Counter<HashMap>::adder(std::wstring &word) {

    map_[word]++;

}

//Adder for W_Bst
template<>
void Counter<wBST>::adder(std::wstring &word) {

    map_.Add(word);

}

//Adder for std::unordered_map
template<>
void Counter<std::unordered_map<std::wstring, int>>::adder(std::wstring &word) {

    map_[word]++;

}

#endif //LEVELUP_CPP_MAIN_COUNTER_HPP
