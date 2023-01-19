//
// Created by Dmitry Morozov on 27/12/22.
//

#ifndef LEVELUP_CPP_MAIN_D_HASH_HPP
#define LEVELUP_CPP_MAIN_D_HASH_HPP

#include "hashf.hpp"
#include "String.hpp"

#include <cstdlib>
#include <utility>


class DHash {

public:

    DHash();

    ~DHash();

    void Insert(wString &, int = 1);

    int Get(wString &) const;

private:

    constexpr static int default_size = 8;
    constexpr static double rehash_factor = 0.75;

    int r_size_; // Actual size of table
    int buffer_size_; // Size of buffer (Memory allocated for table)


    struct Node {
        wString value_;
        int count_;

        explicit Node(wString value) : value_(std::move(value)), count_{1} {} // Check the count!

        Node(wString value, int count) : value_(std::move(value)), count_(count) {}

        //Copy constructor
        Node(const Node &other) : value_(other.value_), count_(other.count_) {}
    };

    Node **table_;


    void resize();

};


#endif //LEVELUP_CPP_MAIN_D_HASH_HPP
