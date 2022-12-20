//
// Created by Dmitry Morozov on 14/12/22.
//

#include "W_Bst.hpp"


wBST::wBST() {

    root = nullptr;
    size_ = 0;

}

wBST::~wBST() {

    DeleteTree(root);
    root = nullptr;

}

void wBST::Add(wString &word) {

    if (root == nullptr) {

        root = new Node(word);

    } else {

        AddWord(root, word);

    }

    ++size_;

}

void wBST::AddWord(wBST::Node *node, wString &word) {

    if (word == node->word) {

        node->count++;

    } else if (word < node->word) {

        if (node->left == nullptr) {

            node->left = new Node(word);

        } else {

            AddWord(node->left, word);

        }

    } else {

        if (node->right == nullptr) {

            node->right = new Node(word);

        } else {

            AddWord(node->right, word);

        }

    }


}

void wBST::DeleteTree(wBST::Node *node) {

    if (node != nullptr) {

        DeleteTree(node->left);

        DeleteTree(node->right);

        delete node;

    }

}

int wBST::Search(wString &word) {

    if (root == nullptr) {

        return 0;

    } else {

        return SearchWord(root, word);

    }

}

int wBST::SearchWord(wBST::Node *node, wString &word) {

    if (word == node->word) {

        return node->count;

    } else if (word < node->word) {

        if (node->left == nullptr) {

            return 0;

        } else {

            return SearchWord(node->left, word);

        }

    } else {

        if (node->right == nullptr) {

            return 0;

        } else {

            return SearchWord(node->right, word);

        }

    }

}

size_t wBST::size() const {

    return size_;

}

