//
// Created by Dmitry Morozov on 21/12/22.
//

#include "gtest/gtest.h"

#include "String.hpp"


TEST(String, DefaultConstructor) {

    wString str;

    EXPECT_EQ(str.length(), 0);

    EXPECT_STREQ(reinterpret_cast<const char *>(str.c_str()), "");

}