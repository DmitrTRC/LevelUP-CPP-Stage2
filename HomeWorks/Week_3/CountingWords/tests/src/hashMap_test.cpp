//
// Created by Dmitry Morozov on 23/12/22.
//

#include "gtest/gtest.h"

#include "Hash_Map.hpp"


TEST(HashMap, HashMapNode) {

    HashMapNode<std::string> node{"key", 3, nullptr};

    EXPECT_EQ(node.key, "key");
    EXPECT_EQ(node.value, 3);
    EXPECT_EQ(node.next, nullptr);

}

TEST(HashMap, Constructor) {

    HashMap<std::string> map;

    EXPECT_EQ(map.size(), HASH_MAP_SIZE);
    EXPECT_EQ(map.capacity(), HASH_MAP_SIZE); //TODO: check if it is correct
//    EXPECT_EQ(map.load_factor(), 0);
//    EXPECT_EQ(map.max_load_factor(), 0.75);

}

