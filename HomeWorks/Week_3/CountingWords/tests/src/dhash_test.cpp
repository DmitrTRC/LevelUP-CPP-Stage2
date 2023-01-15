//
// Created by Dmitry Morozov on 16/1/23.
//
#include "gtest/gtest.h"

#include "D_Hash.hpp"

TEST(DHashTest, Insert) {

    DHash hash;

    wString str1(L"Hello");
    wString str2(L"World");
    wString str3(L"!");

    hash.Insert(str1, 1);
    hash.Insert(str2, 2);
    hash.Insert(str3, 3);

    EXPECT_EQ(hash.Get(str1), 1);
    EXPECT_EQ(hash.Get(str2), 2);
    EXPECT_EQ(hash.Get(str3), 3);

}

TEST(DHashTest, Get) {

    DHash hash;

    wString str1(L"Hello");
    wString str2(L"World");
    wString str3(L"!");

    hash.Insert(str1, 1);
    hash.Insert(str2, 2);
    hash.Insert(str3, 3);

    EXPECT_EQ(hash.Get(str1), 1);
    EXPECT_EQ(hash.Get(str2), 2);
    EXPECT_EQ(hash.Get(str3), 3);

}

TEST(DHashTest, GetNonExisting) {

    DHash hash;

    wString str1(L"Hello");
    wString str2(L"World");
    wString str3(L"!");

    hash.Insert(str1, 1);
    hash.Insert(str2, 2);
    hash.Insert(str3, 3);

    wString str4(L"Hello World!");

    EXPECT_EQ(hash.Get(str4), 0);

}

//Test resize
TEST(DHashTest, Resize) {

    DHash hash;

    wString str1(L"Hello");
    wString str2(L"World");
    wString str3(L"!");
    wString str4(L"String4");
    wString str5(L"String5");
    wString str6(L"String6");
    wString str7(L"String7");
    wString str8(L"String8");
    wString str9(L"String9");
    wString str10(L"String10");
    wString str11(L"String11");
    wString str12(L"String12");


    hash.Insert(str1, 1);
    hash.Insert(str2, 2);
    hash.Insert(str3, 3);
    hash.Insert(str4, 4);
    hash.Insert(str5, 5);
    hash.Insert(str6, 6);
    hash.Insert(str7, 7);
    hash.Insert(str8, 8);
    hash.Insert(str9, 9);
    hash.Insert(str10, 10);
    hash.Insert(str11, 11);
    hash.Insert(str12, 12);


    EXPECT_EQ(hash.Get(str1), 1);
    EXPECT_EQ(hash.Get(str2), 2);
    EXPECT_EQ(hash.Get(str3), 3);
    EXPECT_EQ(hash.Get(str4), 4);
    EXPECT_EQ(hash.Get(str5), 5);
    EXPECT_EQ(hash.Get(str6), 6);
    EXPECT_EQ(hash.Get(str7), 7);
    EXPECT_EQ(hash.Get(str8), 8);
    EXPECT_EQ(hash.Get(str9), 9);
    EXPECT_EQ(hash.Get(str10), 10);
    EXPECT_EQ(hash.Get(str11), 11);
    EXPECT_EQ(hash.Get(str12), 12);

    hash.Insert(str12);
    hash.Insert(str11);

    EXPECT_EQ(hash.Get(str12), 13);
    EXPECT_EQ(hash.Get(str11), 12);


}

