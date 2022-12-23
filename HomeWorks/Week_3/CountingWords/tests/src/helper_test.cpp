//
// Created by Dmitry Morozov on 23/12/22.
//

#include "gtest/gtest.h"

#include "Helper.hpp"

#include <string>
#include <locale>

TEST(Helper, tolowerrus) {


    auto loc = std::locale("ru_RU.UTF-8");

    std::wstring str = L"ПРИВЕТ";

    auto res_str = toLowerRus(str, loc);

    EXPECT_EQ(res_str, L"привет");

}

TEST(Helper, toLowerRus2) {

    auto loc = std::locale("ru_RU.UTF-8");

    wString str(L"ПРИВЕТ");

    auto res_str = toLowerRus(str, loc);

    EXPECT_EQ(res_str, L"привет");

}

TEST(Helper, trim_punctuation) {

    wString str(L"привет, как дела?");

    trim_punctuation(str);

    EXPECT_EQ(str, L"привет как дела");

}

TEST(Helper, trim_punctuation2) {

    std::wstring str(L"привет, как дела?");

    trim_punctuation(str);

    EXPECT_EQ(str, L"привет как дела");

}

TEST(Helper, to_wstring) {

    std::string str = "привет";

    std::wstring res_str = to_wstring(str);

    EXPECT_EQ(res_str, L"привет");

}