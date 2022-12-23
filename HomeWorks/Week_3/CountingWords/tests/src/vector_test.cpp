//
// Created by Dmitry Morozov on 23/12/22.
//

#include "gtest/gtest.h"

#include "Vector.hpp"


TEST(Vector, Constructor) {

    Vector<int> vector;

    EXPECT_EQ(vector.size(), 0);

}

TEST(Vector, PushBack) {

    Vector<int> vector;

    vector.push_back(1);

    EXPECT_EQ(vector.size(), 1);

    vector.push_back(2);

    EXPECT_EQ(vector.size(), 2);

}

TEST(Vector, PushBack2) {

    Vector<wchar_t> vector;

    vector.push_back(L'1');

    EXPECT_EQ(vector.size(), 1);

    vector.push_back(L'2');

    EXPECT_EQ(vector.size(), 2);

}

TEST(Vector, Resize) {

    Vector<int> vector;

    vector.resize(10);

    EXPECT_EQ(vector.size(), 10);

}

TEST(Vector, size) {

    Vector<int> vector;

    vector.resize(10);

    EXPECT_EQ(vector.size(), 10);

    vector.resize(5);

    EXPECT_EQ(vector.size(), 5);

    vector.push_back(1);

    EXPECT_EQ(vector.size(), 6);

}

TEST(Vector, brackets_operator) {

    Vector<int> vector;

    vector.resize(10);

    vector[0] = 1;

    vector[1] = 2;

    vector[2] = 3;

    vector[3] = 4;

    vector[4] = 5;

    vector[5] = 6;

    vector[6] = 7;

    vector[7] = 8;

    vector[8] = 9;

    vector[9] = 10;

    EXPECT_EQ(vector[0], 1);

    EXPECT_EQ(vector[1], 2);

    EXPECT_EQ(vector[2], 3);

    EXPECT_EQ(vector[3], 4);

    EXPECT_EQ(vector[4], 5);

    EXPECT_EQ(vector[5], 6);

    EXPECT_EQ(vector[6], 7);

    EXPECT_EQ(vector[7], 8);

    EXPECT_EQ(vector[8], 9);

    EXPECT_EQ(vector[9], 10);

}