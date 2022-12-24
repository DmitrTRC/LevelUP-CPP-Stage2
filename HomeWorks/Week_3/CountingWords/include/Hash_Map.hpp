//
// Created by Dmitry Morozov on 17/12/22.
//

#ifndef LEVELUP_CPP_MAIN_HASH_MAP_HPP
#define LEVELUP_CPP_MAIN_HASH_MAP_HPP


#include "Vector.hpp"

#include <string>

constexpr int HASH_MAP_SIZE = 26 + 33; // 26 English letters + 33 Russian letters

template<class T>
struct HashMapNode {
    T key;
    int value;
    HashMapNode *next;
};

template<class T>
class HashMap {
public:
    HashMap();

    void insert(T &, int);

    int &find_key(T &);

    bool contains(T &);

    int &operator[](T &);

    [[nodiscard]] size_t size() const;

    [[nodiscard]] size_t capacity() const;

    [[maybe_unused]] [[nodiscard]] double load_factor() const;

    double max_load_factor() const;

private:
    Vector<HashMapNode<T> *> table_;
    constexpr static const int NO_KEY = -1;
    size_t capacity_ = 0;

    int hashFunction(T &key);

};

template<class T>
double HashMap<T>::max_load_factor() const {

    return 0.75; //TODO: check if it is correct

}

template<class T>
[[maybe_unused]] double HashMap<T>::load_factor() const {

    return (double) capacity() / size();

}

template<class T>
size_t HashMap<T>::capacity() const {

    return capacity_;

}

template<class T>
size_t HashMap<T>::size() const {

    return table_.size();

}


template<class T>
HashMap<T>::HashMap() {

    table_.resize(HASH_MAP_SIZE);

}

template<class T>
void HashMap<T>::insert(T &key, int value) {

    int hash = hashFunction(key);
    auto *newNode = new HashMapNode<T>{key, value, table_[hash]};
    table_[hash] = newNode;

    ++capacity_;

}

template<class T>
int &HashMap<T>::find_key(T &key) {

    int hash = hashFunction(key);
    HashMapNode<T> *node = table_[hash];

    while (node != nullptr) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }


    return const_cast<int &>(NO_KEY);
}

template<class T>
bool HashMap<T>::contains(T &key) {

    int hash = hashFunction(key);
    HashMapNode<T> *node = table_[hash];

    while (node != nullptr) {
        if (node->key == key) {
            return true;
        }
        node = node->next;
    }

    return false;
}

template<class T>
int HashMap<T>::hashFunction(T &key) {

    int hash = 0;

    for (const wchar_t &c: key) {
        hash += c;
    }
    return hash % HASH_MAP_SIZE;
}

template<class T>
int &HashMap<T>::operator[](T &key) {

    int hash = hashFunction(key);
    HashMapNode<T> *node = table_[hash];

    while (node != nullptr) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }

    insert(key, 0);

    return find_key(key);
}


#endif //LEVELUP_CPP_MAIN_HASH_MAP_HPP
