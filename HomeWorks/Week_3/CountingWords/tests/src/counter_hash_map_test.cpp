//
// Created by Dmitry Morozov on 24/12/22.
//

#include "gtest/gtest.h"

#include "Counter_Hash_Map.hpp"


TEST(CounterHashMap, DefaultConstructor) {

    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    std::wstring TEXT = L"Привет, мир!";

    CounterHashMap counter(TEXT);
//FIXME: Crash on this line

//    counter.load();
//
//    EXPECT_EQ(counter.get((std::wstring &) L"Hello"), 1);

}