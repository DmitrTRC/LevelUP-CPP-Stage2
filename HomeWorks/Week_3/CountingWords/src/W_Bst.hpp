//
// Created by Dmitry Morozov on 14/12/22.
//

#ifndef LEVELUP_CPP_MAIN_W_BST_HPP
#define LEVELUP_CPP_MAIN_W_BST_HPP

#include <string>

// Class Binary Search Tree for counting the words in the text
class wBST {
public:

    wBST();

    ~wBST();

    void AddWord(std::wstring &word);

private:
    struct Node {
        std::wstring word;
        int count;
        Node *left;
        Node *right;

        Node(std::wstring &word) : word(word), count(1), left(nullptr), right(nullptr) {}
    };

};


#endif //LEVELUP_CPP_MAIN_W_BST_HPP
