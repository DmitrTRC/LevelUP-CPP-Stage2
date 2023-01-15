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

        if (table_[hash1]->value_ == value && table_[hash1]->state_) {
            return table_[hash1]->count_;
        }

        hash1 = (hash1 + hash2) % buffer_size_;
        ++i;
    }


    return 0;
}


void DHash::Insert(wString &value, int count) {

    if (r_size_ + 1 > rehash_factor * buffer_size_) {
        resize();
    } else if (size_of_non_empty_cells_ > 2 * r_size_) {
        rehash();
    }

    auto hf1 = hashFunc_1();
    auto hf2 = hashFunc_2();
    int hash1 = hf1(value, buffer_size_);
    int hash2 = hf2(value, buffer_size_);

    int i = 0;
    int first_deleted = -1;

    while (table_[hash1] != nullptr && i < buffer_size_) {

        if (table_[hash1]->value_ == value && table_[hash1]->state_) {
            table_[hash1]->count_ += count;
//            table_[hash1]->count_ = count;
            return;
        }

        if (!table_[hash1]->state_ && first_deleted == -1) {
            first_deleted = hash1;
        }

        hash1 = (hash1 + hash2) % buffer_size_;
        i++;
    }

    if (first_deleted == -1) {
        //table_[hash1] = new Node(value);
        table_[hash1] = new Node(value, count);
        ++size_of_non_empty_cells_;

    } else {
        table_[first_deleted]->value_ = value;
        table_[first_deleted]->count_ = 1;
        table_[first_deleted]->state_ = true;
    }

    ++r_size_;
}


DHash::DHash() : r_size_(0), buffer_size_(default_size), size_of_non_empty_cells_(0) {

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
    size_of_non_empty_cells_ = 0;
    r_size_ = 0;
    Node **arr2 = new Node *[buffer_size_];
    for (int i = 0; i < buffer_size_; ++i)
        arr2[i] = nullptr;
    std::swap(table_, arr2);
    for (int i = 0; i < past_buffer_size; ++i) {
        if (arr2[i] && arr2[i]->state_)
            Insert(arr2[i]->value_);
    }
    for (int i = 0; i < past_buffer_size; ++i)
        if (arr2[i])
            delete arr2[i];
    delete[] arr2;
//    int last_buffer_size = buffer_size_;
//
//    buffer_size_ *= 2;
//    size_of_non_empty_cells_ = 0;
//    r_size_ = 0;
//
//    Node **new_table = new Node *[buffer_size_];
//
//    std::fill(new_table, new_table + buffer_size_, nullptr);
//
//    std::swap(table_, new_table);
//
//    std::for_each(new_table, new_table + last_buffer_size, [this](Node *node) {
//        if (node != nullptr && node->state_) {
//            Insert(node->value_, node->count_);
//        }
//    });
//
//    std::for_each(new_table, new_table + last_buffer_size, [](Node *node) {
//        delete node;
//    });
//
//    delete[] new_table;

}




void DHash::rehash() {

    size_of_non_empty_cells_ = 0;
    r_size_ = 0;
    Node **arr2 = new Node *[buffer_size_];
    for (int i = 0; i < buffer_size_; ++i)
        arr2[i] = nullptr;
    std::swap(table_, arr2);
    for (int i = 0; i < buffer_size_; ++i) {
        if (arr2[i] && arr2[i]->state_)
            Insert(arr2[i]->value_);
    }
    for (int i = 0; i < buffer_size_; ++i)
        if (arr2[i])
            delete arr2[i];
    delete[] arr2;
//    size_of_non_empty_cells_ = 0;
//    r_size_ = 0;
//
//    Node **new_table = new Node *[buffer_size_];
//
//    std::fill(new_table, new_table + buffer_size_, nullptr);
//
//    std::swap(table_, new_table);
//
//    std::for_each(new_table, new_table + buffer_size_, [this](Node *node) {
//        if (node && node->state_) {
//            Insert(node->value_, node->count_); // ???
//        }
//    });
//
//
//    std::for_each(new_table, new_table + buffer_size_, [](Node *node) {
//        delete node;
//    });
//
//    delete[] new_table;

}
