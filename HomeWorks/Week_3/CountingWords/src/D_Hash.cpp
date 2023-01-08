//
// Created by Dmitry Morozov on 27/12/22.
//

#include "D_Hash.hpp"
#include "String.hpp"

#include <algorithm>

int DHash::Get(wString &value) const {

    int hash1{hashFunc_1(value)};
    int hash2{hashFunc_2(value)};

    int i{0};

    while (table_[hash1] != nullptr && i < buffer_size_) {

        if (table_[hash1]->value_ == value && table_[hash1]->state_) {
            return table_[hash1]->count_;
        }

        hash1 = (hash1 + hash2) % table_size_;
        ++i;
    }


    return 0;
}


void DHash::Insert(wString &value) {

    if (table_size_ + 1 > rehash_factor * buffer_size_) {
        resize();
    } else if (size_of_non_empty_cells_ > 2 * table_size_) {
        rehash();
    }

    int hash1 = hashFunc_1(value);
    int hash2 = hashFunc_2(value);

    int i = 0;
    int first_deleted = -1;

    while (table_[hash1] != nullptr && i < buffer_size_) {

        if (table_[hash1]->value_ == value && table_[hash1]->state_) {
            table_[hash1]->count_++;
            return;
        }

        if (!table_[hash1]->state_ && first_deleted == -1) {
            first_deleted = hash1;
        }

        hash1 = (hash1 + hash2) % buffer_size_;
        i++;
    }

    if (first_deleted != -1) {
        table_[hash1] = new Node(value);
        ++size_of_non_empty_cells_;

    } else {
        table_[first_deleted]->value_ = value;
        table_[first_deleted]->count_ = 1;
        table_[first_deleted]->state_ = true;
    }

    ++table_size_;
}


DHash::DHash() : table_size_(0), buffer_size_(default_size), size_of_non_empty_cells_(0) {

    table_ = new Node *[table_size_];

    std::fill(table_, table_ + table_size_, nullptr);

}


DHash::~DHash() {

    std::for_each(table_, table_ + table_size_, [](Node *node) {
        delete node;
    });

    delete[] table_;

}


void DHash::resize() {

    int last_buffer_size = buffer_size_;

    buffer_size_ *= 2;
    size_of_non_empty_cells_ = 0;
    table_size_ = 0;

    Node **new_table = new Node *[buffer_size_];

    std::fill(new_table, new_table + buffer_size_, nullptr);

    std::swap(table_, new_table);

    std::for_each(new_table, new_table + last_buffer_size, [this](Node *node) {
        if (node != nullptr && node->state_) {
            Insert(node->value_);
        }
    });

    std::for_each(new_table, new_table + last_buffer_size, [](Node *node) {
        delete node;
    });

    delete[] new_table;

}


int DHash::hashFunc_1(wString &key) const {

    return dHashFunction(key, table_size_ - 1);

}


int DHash::hashFunc_2(wString &key) const {

    return dHashFunction(key, table_size_ + 1);

}

//Horner's method for string hashing

int DHash::dHashFunction(const wString &obj, const int key) const {

    int hash_result = 0;

    std::for_each(obj.begin(), obj.end(), [&hash_result, &key, this](const auto &i) {

        hash_result = (key * hash_result + i) % table_size_;

    });

    hash_result = (hash_result * 2 + 1) % table_size_;

    return hash_result;
}


void DHash::rehash() {

    size_of_non_empty_cells_ = 0;
    table_size_ = 0;

    Node **new_table = new Node *[buffer_size_];

    std::fill(new_table, new_table + buffer_size_, nullptr);

    std::swap(table_, new_table);

    std::for_each(new_table, new_table + buffer_size_, [this](Node *node) {
        if (node && node->state_) {
            Insert(node->value_);
        }
    });


    std::for_each(new_table, new_table + buffer_size_, [](Node *node) {
        delete node;
    });

    delete[] new_table;

}
