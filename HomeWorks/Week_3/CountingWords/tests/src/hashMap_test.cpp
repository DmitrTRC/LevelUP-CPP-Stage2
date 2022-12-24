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
    EXPECT_EQ(map.capacity(), 0); //TODO: check if it is correct
    EXPECT_EQ(map.load_factor(), 0);

}

TEST(HashMap, MaxLoadFactor) {

    HashMap<std::string> map;

    EXPECT_EQ(map.max_load_factor(), 0.75);

}

TEST(HashMap, Insert) {

    HashMap<std::string> map;

    std::string key = "key";

    map.insert(key, 3);

    EXPECT_EQ(map.capacity(), 1);
    //   EXPECT_EQ(map.load_factor(), 1.0 / HASH_MAP_SIZE);

}

TEST(HashMap, FindKey) {

    HashMap<std::string> map;

    std::string key = "key";

    map.insert(key, 3);

    EXPECT_EQ(map.find_key(key), 3);

}

TEST(HashMap, Contains) {

    HashMap<std::string> map;

    std::string key = "key";

    map.insert(key, 3);

    EXPECT_TRUE(map.contains(key));

}

TEST(HashMap, Operator_index) {

    HashMap<std::string> map;

    std::string key = "key";

    map.insert(key, 3);

    EXPECT_EQ(map[key], 3);

}

