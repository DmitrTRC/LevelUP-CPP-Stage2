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

    explicit DHash(int);

    ~DHash();

private:

    constexpr static int default_size = 8;
    constexpr static double rehash_factor = 0.75;
    int table_size_;
    int buffer_size_;
    int size_of_non_empty_cells_;

    struct Node {
        T value_;
        size_t count_;
        bool state_;

        explicit Node(const T &value) : value_(value), count_{0}, state_(true) {}
    };

    Node **table_;

    int dHashFunction(const T &, int) const;

    int hashFunc_1(T &) const;

    int hashFunc_2(T &) const;

    void resize();

    void rehash();

};

template<class T>
DHash<T>::DHash() : table_size_(default_size), buffer_size_(default_size), size_of_non_empty_cells_(0) {

    table_ = new Node *[table_size_];

    std::fill(table_, table_ + table_size_, nullptr);

}

//Destructor
template<class T>
DHash<T>::~DHash() {

    for_each(table_, table_ + table_size_, [](Node *node) {

        if (node != nullptr) {
            delete node;
        }

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
            Add(new_table[i]->value);
    }

    for (int i = 0; i < buffer_size_; ++i) {
        if (new_table[i]) {
            delete new_table[i];
        }
    }

    delete[] new_table;

}

#endif //LEVELUP_CPP_MAIN_D_HASH_HPP
