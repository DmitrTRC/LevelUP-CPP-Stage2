//
// Created by Dmitry Morozov on 14/12/22.
//

#ifndef LEVELUP_CPP_MAIN_W_BST_HPP
#define LEVELUP_CPP_MAIN_W_BST_HPP

#include "String.hpp"


class wBST {
public:

    wBST();

    ~wBST();

    void Add(wString &word);

    int Search(wString &word);

    [[nodiscard]] size_t size() const;


private:
    struct Node {
        wString word;
        int count;
        Node *left;
        Node *right;

        explicit Node(wString &word) : word(word), count(1), left(nullptr), right(nullptr) {}

    };

    Node *root;

    void AddWord(Node *node, wString &word);

    int SearchWord(Node *node, wString &word);

    void DeleteTree(Node *node);

    size_t size_;

};


#endif //LEVELUP_CPP_MAIN_W_BST_HPP
