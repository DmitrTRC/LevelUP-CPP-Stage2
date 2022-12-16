//
// Created by Dmitry Morozov on 17/12/22.
//

#ifndef LEVELUP_CPP_MAIN_HASH_MAP_HPP
#define LEVELUP_CPP_MAIN_HASH_MAP_HPP


#include "Vector.hpp"

#include <string>

const int HASH_MAP_SIZE = 100;

struct HashMapNode {
    std::wstring key;
    int value;
    HashMapNode *next;
};

class HashMap {
public:
    HashMap();

    void insert(const std::wstring &, int);

    int &find_key(const std::wstring &);

    bool contains(const std::wstring &);

    int &operator[](const std::wstring &);

private:
    Vector<HashMapNode *> table_;

    static int hashFunction(const std::wstring &key);

    constexpr static const int NO_KEY = -1;
};


#endif //LEVELUP_CPP_MAIN_HASH_MAP_HPP
