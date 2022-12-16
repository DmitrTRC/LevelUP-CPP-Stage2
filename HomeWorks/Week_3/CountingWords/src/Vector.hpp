//
// Created by Dmitry Morozov on 17/12/22.
//

#ifndef LEVELUP_CPP_MAIN_VECTOR_HPP
#define LEVELUP_CPP_MAIN_VECTOR_HPP


#include <cstddef>

const int INITIAL_CAPACITY = 8;

class Vector {
public:

    Vector();

    ~Vector();

    void push_back(int value);

    void resize(size_t new_size);

    int operator[](size_t index) const;

    int &operator[](size_t index);

    [[nodiscard]] size_t size() const;

private:
    void extend();

    int *data_;
    size_t size_;
    size_t capacity_;
};


#endif //LEVELUP_CPP_MAIN_VECTOR_HPP
