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