//
// Created by Dmitry Morozov on 24/12/22.
//

#include "gtest/gtest.h"

#include "Counter_Base.hpp"


TEST(CounterBase, DefaultConstructor) {

    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    std::wstring TEXT = L"Hello, world!";

    CounterBase counter(TEXT);


    EXPECT_THROW(counter.get((std::wstring &) L"hello"), std::runtime_error);

}

TEST(CounterBase, get) {

    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    std::wstring TEXT = L"Hello, world!";

    CounterBase counter(TEXT);

    EXPECT_THROW(counter.get((wString &) L"hello"), std::runtime_error);

}

TEST(CounterBase, total_words) {

    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    std::wstring TEXT = L"Hello, world!";

    CounterBase counter(TEXT);

    EXPECT_EQ(counter.total_words(), 0);


}