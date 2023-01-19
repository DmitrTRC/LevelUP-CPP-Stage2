#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
//
// Created by Dmitry Morozov on 27/12/22.
//

#include "D_Hash.hpp"
#include "hashf.hpp"
#include "String.hpp"

#include <algorithm>

int DHash::Get(wString &value) const {

    auto hf1 = hashFunc_1();
    auto hf2 = hashFunc_2();

    int hash1 = hf1(value, buffer_size_);
    int hash2 = hf2(value, buffer_size_);

    int i{0};

    while (table_[hash1] != nullptr && i < buffer_size_) {

        if (table_[hash1]->value_ == value) {
            return table_[hash1]->count_;
        }

        hash1 = (hash1 + hash2) % buffer_size_;
        ++i;
    }


    return 0;
}


void DHash::Insert(wString &value, int count) {

    if (r_size_ + 1 > int(rehash_factor * buffer_size_)) { //FIXME: cast to int is necessary
        resize();
    }

    auto hf1 = hashFunc_1();
    auto hf2 = hashFunc_2();
    int hash1 = hf1(value, buffer_size_);
    int hash2 = hf2(value, buffer_size_);

    int i = 0;


    while (table_[hash1] != nullptr && i < buffer_size_) {

        if (table_[hash1]->value_ == value) {
            table_[hash1]->count_ += count;
//            table_[hash1]->count_ = count;
            return;
        }


        hash1 = (hash1 + hash2) % buffer_size_;
        i++;
    }


    ++r_size_;
}


DHash::DHash() : r_size_(0), buffer_size_(default_size) {

    table_ = new Node *[buffer_size_];

    std::fill(table_, table_ + buffer_size_, nullptr);

}


DHash::~DHash() {

    std::for_each(table_, table_ + buffer_size_, [](Node *node) {
        delete node;
    });

    delete[] table_;

}


void DHash::resize() {

    std::cerr << "Resize started" << std::endl;

    int past_buffer_size = buffer_size_;
    buffer_size_ *= 2;

    r_size_ = 0;

    Node **arr2 = new Node *[buffer_size_];

    for (int i = 0; i < buffer_size_; ++i) {
        arr2[i] = nullptr;
    }

    std::swap(table_, arr2);

    for (int i = 0; i < past_buffer_size; ++i) {
        if (arr2[i])
            Insert(arr2[i]->value_);
    }

    for (int i = 0; i < past_buffer_size; ++i)
        if (arr2[i])
            delete arr2[i];
    delete[] arr2;

    std::cerr << "Resize finished" << std::endl;

}


#pragma clang diagnostic pop