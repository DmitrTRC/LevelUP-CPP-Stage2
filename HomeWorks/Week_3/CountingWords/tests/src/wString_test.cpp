//
// Created by Dmitry Morozov on 21/12/22.
//

#include "gtest/gtest.h"

#include "String.hpp"


TEST(String, DefaultConstructor) {

    wString str;

    EXPECT_EQ(str.length(), 0);

    EXPECT_STREQ(reinterpret_cast<const char *>(str.wc_str()), "");

}

TEST(String, Constructor) {

    wString str(L"Hello");

    EXPECT_EQ(str.length(), 5);

    EXPECT_STREQ(str.wc_str(), L"Hello");

}

TEST(String, CopyConstructor) {

    wString str(L"Hello");

    wString str2(str);

    EXPECT_EQ(str2.length(), 5);

    EXPECT_STREQ(str2.wc_str(), L"Hello");

}

TEST(String, MoveConstructor) {

    wString str(L"Hello");

    wString str2(std::move(str));

    EXPECT_EQ(str2.length(), 5);

    EXPECT_STREQ(str2.wc_str(), L"Hello");

}

TEST(String, CopyAssignment) {

    wString str(L"Hello");

    wString str2 = str;

    EXPECT_EQ(str2.length(), 5);

    EXPECT_STREQ(str2.wc_str(), L"Hello");

}

TEST(String, MoveAssignment) {

    wString str(L"Hello");

    wString str2 = std::move(str);

    EXPECT_EQ(str2.length(), 5);

    EXPECT_STREQ(str2.wc_str(), L"Hello");

}

TEST(String, Concatenation) {

    wString str(L"Hello");

    wString str2(L"World");

    wString str3 = str + str2;

    EXPECT_EQ(str3.length(), 10);

    EXPECT_STREQ(str3.wc_str(), L"HelloWorld");

}

TEST(String, ConcatenationAssignment) {

    wString str(L"Hello");

    wString str2(L"World");

    str += str2;

    EXPECT_EQ(str.length(), 10);

    EXPECT_STREQ(str.wc_str(), L"HelloWorld");

}


TEST(String, ConcatenationWithCharPointer) {

    wString str(L"Hello");

    wString str2 = str + L"World";

    EXPECT_EQ(str2.length(), 10);

    EXPECT_STREQ(str2.wc_str(), L"HelloWorld");

}

TEST(String, PushBack) {

    wString str(L"Hello");

    str.push_back(L'W');

    EXPECT_EQ(str.length(), 6);

    EXPECT_STREQ(str.wc_str(), L"HelloW");

}

TEST(String, LE) {

    wString str(L"Hello");

    wString str2(L"World");

    EXPECT_TRUE(str <= str2);

}

TEST(String, GE) {

    wString str(L"Hello");

    wString str2(L"World");

    EXPECT_TRUE(str2 >= str);

}

TEST(String, EQ) {

    wString str(L"Hello");

    wString str2(L"World");

    EXPECT_FALSE(str == str2);

}

TEST(String, NE) {

    wString str(L"Hello");

    wString str2(L"World");

    EXPECT_TRUE(str != str2);

}

TEST(String, LT) {

    wString str(L"Hello");

    wString str2(L"World");

    EXPECT_TRUE(str < str2);

}

TEST(String, GT) {

    wString str(L"Hello");

    wString str2(L"World");

    EXPECT_TRUE(str2 > str);

}

TEST(String, Iterator) {

    wString str(L"Hello");

    for (auto c: str) {
        EXPECT_TRUE(c == L'H' || c == L'e' || c == L'l' || c == L'l' || c == L'o');
    }

}

TEST(String, ConstIterator) {

    const wString str(L"Hello");

    for (auto c: str) {
        EXPECT_TRUE(c == L'H' || c == L'e' || c == L'l' || c == L'l' || c == L'o');
    }

}

TEST(String, Empty) {

    wString str;

    EXPECT_TRUE(str.empty());

}

TEST(String, Erase) {

    wString str(L"Hello");

    str.erase(0, 1);

    EXPECT_EQ(str.length(), 4);

    EXPECT_STREQ(str.wc_str(), L"ello");

}

TEST(String, Erase2) {

    wString str(L"Hello");

    str.erase(0, 2);

    EXPECT_EQ(str.length(), 3);

    EXPECT_STREQ(str.wc_str(), L"llo");

}


TEST(String, Length) {

    wString str(L"Hello");

    EXPECT_EQ(str.length(), 5);

}

TEST(String, setString) {

    wString str(L"Hello");

    str.setString(L"World");

    EXPECT_EQ(str.length(), 5);

    EXPECT_STREQ(str.wc_str(), L"World");

}

TEST(String, wc_str) {

    wString str(L"Hello");

    EXPECT_STREQ(str.wc_str(), L"Hello");

}

TEST(String, wostrem_output) {

    wString str(L"Hello");

    std::wstringstream ss;

    ss << str;

    EXPECT_STREQ(ss.str().c_str(), L"Hello");

}

TEST(String, wistream_input) {

    wString str;

    std::wstringstream ss(L"Hello");

    ss >> str;

    EXPECT_STREQ(str.wc_str(), L"Hello");

}

TEST(String, Clear) {

    wString str(L"Hello");

    str.clear();

    EXPECT_EQ(str.length(), 0);

    EXPECT_STREQ(str.wc_str(), L"");

}