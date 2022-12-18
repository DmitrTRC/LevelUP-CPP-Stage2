//
// Created by Dmitry Morozov on 18/12/22.
//

#ifndef LEVELUP_CPP_MAIN_COUNTER_HPP
#define LEVELUP_CPP_MAIN_COUNTER_HPP

#include "Counter_Base.hpp"
#include "Helper.hpp"
#include "W_Bst.hpp"
#include "Hash_Map.hpp"

#include <iostream>
#include <sstream>
#include <unordered_map>


template<class T>
class Counter : public CounterBase {
public:
    explicit Counter(const std::wstring &buffer) : CounterBase(buffer) {}

    void load() override;

    int get(std::wstring &word) override;

private:
    T map_;

    void adder(std::wstring &word) override;

};

template<class T>
void Counter<T>::load() {

    std::locale loc = std::locale("ru_RU.UTF-8");


    std::wstring word;
    while (*buffer_ >> word) {
        trim_punctuation(word);

        auto lWord = toLowerRus(word, loc);

        if (!word.empty()) {
            adder(word);
        }

    }


}

//Adder for Hash_Map

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

// Getter for Hash_Map
template<>
int Counter<HashMap>::get(std::wstring &word) {

    return map_[word];

}

// Getter for BinarySearchTree
template<>
int Counter<wBST>::get(std::wstring &word) {

    return map_.Search(word);
}

// Getter for std::unordered_map
template<>
int Counter<std::unordered_map<std::wstring, int>>::get(std::wstring &word) {

    return map_[word];

}

#endif //LEVELUP_CPP_MAIN_COUNTER_HPP
