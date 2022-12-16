//
// Created by Dmitry Morozov on 17/12/22.
//

#include "Hash_Map.hpp"

HashMap::HashMap() {

    table_.resize(HASH_MAP_SIZE);
}


void HashMap::insert(const std::wstring &key, int value) {

    int hash = hashFunction(key);
    auto *newNode = new HashMapNode{key, value, table_[hash]};
    table_[hash] = newNode;
}

int &HashMap::find_key(const std::wstring &key) {

    int hash = hashFunction(key);
    HashMapNode *node = table_[hash];
    while (node != nullptr) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return const_cast<int &>(NO_KEY);
    // Return a sentinel value to indicate that the key was not found
}

bool HashMap::contains(const std::wstring &key) {

    int hash = hashFunction(key);
    HashMapNode *node = table_[hash];
    while (node != nullptr) {
        if (node->key == key) {
            return true;
        }
        node = node->next;
    }
    return false;
}

int HashMap::hashFunction(const std::wstring &key) {
    // Implement a simple hash function that maps keys to indexes in the table
    int hash = 0;
    for (const wchar_t &c: key) {
        hash += c;
    }
    return hash % HASH_MAP_SIZE;
}

int &HashMap::operator[](const std::wstring &key) {

    int hash = hashFunction(key);
    HashMapNode *node = table_[hash];
    while (node != nullptr) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    insert(key, 0);
    return find_key(key);
}
