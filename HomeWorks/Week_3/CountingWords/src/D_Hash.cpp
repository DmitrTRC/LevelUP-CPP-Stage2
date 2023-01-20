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

    if (r_size_ + 1 > static_cast<int>(rehash_factor * buffer_size_)) {
        resize();
    }

    auto hf1 = hashFunc_1();
    auto hf2 = hashFunc_2();

    int hash1 = hf1(value, buffer_size_);
    int hash2 = hf2(value, buffer_size_);

    int i{0};

    while (table_[hash1] != nullptr && i < buffer_size_) {

        if (table_[hash1]->value_ == value) {
            table_[hash1]->count_ += count;

            return;
        }

        hash1 = (hash1 + hash2) % buffer_size_;
        i++;
    }

    table_[hash1] = new Node(value, count);
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

    int past_buffer_size = buffer_size_;
    buffer_size_ *= 2;
    r_size_ = 0;

    Node **arr2 = new Node *[buffer_size_];

    for (int i = 0; i < buffer_size_; ++i) {
        arr2[i] = nullptr;
    }

    std::swap(table_, arr2);


    std::for_each(arr2, arr2 + past_buffer_size, [this](Node *node) {
        if (node) {
            Insert(node->value_, node->count_);
            delete node;
        }
    });

    delete[] arr2;

}

#pragma clang diagnostic pop