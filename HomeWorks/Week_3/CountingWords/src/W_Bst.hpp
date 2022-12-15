//
// Created by Dmitry Morozov on 14/12/22.
//

#ifndef LEVELUP_CPP_MAIN_W_BST_HPP
#define LEVELUP_CPP_MAIN_W_BST_HPP

#include <string>


class wBST {
public:

    wBST();

    ~wBST();

    void Add(std::wstring &word);

    int Search(std::wstring &word);

    [[nodiscard]] size_t size() const;

private:
    struct Node {
        std::wstring word;
        int count;
        Node *left;
        Node *right;

        explicit Node(std::wstring &word) : word(word), count(1), left(nullptr), right(nullptr) {}

    };

    Node *root;

    void AddWord(Node *node, std::wstring &word);

    int SearchWord(Node *node, std::wstring &word);

    void DeleteTree(Node *node);

    size_t size_;

};


#endif //LEVELUP_CPP_MAIN_W_BST_HPP
