//
// Created by Dmitry Morozov on 17/12/22.
//

#ifndef LEVELUP_CPP_MAIN_HASH_MAP_HPP
#define LEVELUP_CPP_MAIN_HASH_MAP_HPP


#include <vector>
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

    void insert(const std::wstring &key, int value);

    int retrieve(const std::wstring &);

    bool contains(const std::wstring &);


private:
    std::vector<HashMapNode *> table_;

    int hashFunction(const std::wstring &key);
};


#endif //LEVELUP_CPP_MAIN_HASH_MAP_HPP
