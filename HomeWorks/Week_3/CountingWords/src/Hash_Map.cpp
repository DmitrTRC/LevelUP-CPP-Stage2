//
// Created by Dmitry Morozov on 17/12/22.
//

#include "Hash_Map.hpp"

HashMap::HashMap() {

    table_.resize(HASH_MAP_SIZE);
}

void HashMap::insert(const std::wstring &key, int value) {

    int hash = hashFunction(key);
    HashMapNode *newNode = new HashMapNode{key, value, table_[hash]};
    table_[hash] = newNode;
}

int HashMap::retrieve(const std::wstring &key) {

    int hash = hashFunction(key);
    HashMapNode *node = table_[hash];
    while (node != nullptr) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return -1;  // Return a sentinel value to indicate that the key was not found
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