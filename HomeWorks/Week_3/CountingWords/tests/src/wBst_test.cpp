//
// Created by Dmitry Morozov on 22/12/22.
//

#include "gtest/gtest.h"

#include "W_Bst.hpp"


TEST(wBST, Constructor) {

    wBST tree;

    EXPECT_EQ(tree.size(), 0);


}


TEST(wBST, Add) {

    wBST tree;

    wString word(L"word");

    tree.Add(word);

    EXPECT_EQ(tree.size(), 1);

    wString word2(L"word2");

    tree.Add(word2);

    EXPECT_EQ(tree.size(), 2);

}

TEST (wBST, Search) {

    wBST tree;

    wString word(L"word");

    tree.Add(word);

    EXPECT_EQ(tree.Search(word), 1);

    wString word2(L"word2");

    tree.Add(word2);

    EXPECT_EQ(tree.Search(word2), 1);

    wString word3(L"word3");

    EXPECT_EQ(tree.Search(word3), 0);


}

TEST (wBST, size) {

    wBST tree;

    wString word(L"word");

    tree.Add(word);

    EXPECT_EQ(tree.size(), 1);

    wString word2(L"word2");

    tree.Add(word2);

    EXPECT_EQ(tree.size(), 2);

    wString word3(L"word3");

    tree.Add(word3);

    EXPECT_EQ(tree.size(), 3);


}