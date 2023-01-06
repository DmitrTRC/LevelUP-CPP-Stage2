//
// Created by Dmitry Morozov on 27/12/22.
//

#ifndef LEVELUP_CPP_MAIN_D_HASH_HPP
#define LEVELUP_CPP_MAIN_D_HASH_HPP

#include <algorithm>
#include <cstdlib>


template<class T>
class DHash {

public:

    DHash();

    // explicit DHash(int);

    ~DHash();

    void Insert(const T &);

    int Get(const T &) const;

private:

    constexpr static int default_size = 8;
    constexpr static double rehash_factor = 0.75;
    int table_size_; // Actual size of table
    int buffer_size_; // Size of buffer (Memory allocated for table)
    int size_of_non_empty_cells_; // Number of non-empty cells in table

    struct Node {
        T value_;
        size_t count_;
        bool state_;

        explicit Node(const T &value) : value_(value), count_{1}, state_(true) {} // Check the count!
    };

    Node **table_;

    int dHashFunction(const T &, int) const;

    int hashFunc_1(T &) const;

    int hashFunc_2(T &) const;

    void resize();

    void rehash();

};

template<class T>
int DHash<T>::Get(const T &value) const {

    int hash1 = hashFunc_1(value);
    int hash2 = hashFunc_2(value);

    int i = 0;

    while (table_[hash1] != nullptr && i < buffer_size_) {

        if (table_[hash1]->value_ == value && table_[hash1]->state_) {
            return table_[hash1]->count_;
        }

        hash1 = (hash1 + hash2) % table_size_;
        ++i;
    }


    return 0;
}

template<class T>
void DHash<T>::Insert(const T &value) {

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


template<class T>
DHash<T>::DHash() : table_size_(0), buffer_size_(default_size), size_of_non_empty_cells_(0) {

    table_ = new Node *[table_size_];

    std::fill(table_, table_ + table_size_, nullptr);

}

//Destructor
template<class T>
DHash<T>::~DHash() {

    for_each(table_, table_ + table_size_, [](Node *node) {
        delete node;
    });

    delete[] table_;

}


template<class T>
void DHash<T>::resize() {


}


template<class T>
int DHash<T>::hashFunc_1(T &key) const {

    return dHashFunction(key, table_size_ - 1);

}

template<class T>
int DHash<T>::hashFunc_2(T &key) const {

    return dHashFunction(key, table_size_ + 1);

}

//Horner's method for string hashing
template<class T>
int DHash<T>::dHashFunction(const T &obj, const int key) const {

    int hash_result = 0;

    for_each(obj.begin(), obj.end(), [&hash_result, &key, this](const auto &i) {

        hash_result = (key * hash_result + i) % table_size_;

    });

    hash_result = (hash_result * 2 + 1) % table_size_;

    return hash_result;
}

template<class T>
void DHash<T>::rehash() {

    size_of_non_empty_cells_ = 0;
    table_size_ = 0;

    Node **new_table = new Node *[buffer_size_];

    for (int i = 0; i < buffer_size_; ++i) {
        new_table[i] = nullptr;
    }

    std::swap(table_, new_table);

    for (int i = 0; i < buffer_size_; ++i) {
        if (new_table[i] && new_table[i]->state)
            Insert(new_table[i]->value);
    }

    for (int i = 0; i < buffer_size_; ++i) {

        if (new_table[i]) {
            delete new_table[i];
        }
    }

    delete[] new_table;

}

#endif //LEVELUP_CPP_MAIN_D_HASH_HPP
