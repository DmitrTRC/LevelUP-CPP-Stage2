//
// Created by Dmitry Morozov on 24/12/22.
//

#include "gtest/gtest.h"

#include "Counter_Bst.hpp"

TEST(CounterBST, DefaultConstructor) {

    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    std::wstring TEXT = L"Hello, world!";

    CounterBST counter(TEXT);

    counter.load();

    EXPECT_EQ(counter.get((std::wstring &) L"hello"), 1);

}

TEST(CounterBST, get) {

    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    std::wstring TEXT = L"Hello, world!";

    CounterBST counter(TEXT);

    counter.load();

    EXPECT_EQ(counter.get((std::wstring &) L"hello"), 1);

}