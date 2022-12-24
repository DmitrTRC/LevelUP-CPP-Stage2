//
// Created by Dmitry Morozov on 24/12/22.
//

#include "gtest/gtest.h"

#include "Counter.hpp"

TEST(Counter, DefaultConstructor) {

    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    std::wstring TEXT = L"Hello, world!";

    Counter counter(TEXT);

    counter.load();

    std::wstring word = L"hello";

    EXPECT_EQ(counter.get(word), 1);

}

TEST(Counter, get) {

    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    std::wstring TEXT = L"Hello, world!";

    Counter counter(TEXT);

    counter.load();

    std::wstring word = L"hello";

    EXPECT_EQ(counter.get(word), 1);

}