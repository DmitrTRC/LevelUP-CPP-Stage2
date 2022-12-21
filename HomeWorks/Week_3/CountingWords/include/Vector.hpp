//
// Created by Dmitry Morozov on 17/12/22.
//

#ifndef LEVELUP_CPP_MAIN_VECTOR_HPP
#define LEVELUP_CPP_MAIN_VECTOR_HPP


#include <cstddef>


const size_t INITIAL_CAPACITY = 10;

template<typename T>
class Vector {
public:

    Vector() : size_(0), capacity_(INITIAL_CAPACITY) {

        data_ = new T[capacity_];

    }

    ~Vector() {

        delete[] data_;

    }

    void push_back(T value) {

        if (size_ == capacity_) {

            extend();
        }

        data_[size_++] = value;

    }


    void resize(size_t new_size) {

        if (new_size > capacity_) {

            capacity_ = new_size;

            T *new_data = new T[capacity_];

            for (size_t i = 0; i < size_; ++i) {

                new_data[i] = data_[i];
            }

            delete[] data_;

            data_ = new_data;

        }

        size_ = new_size;

    }

    T operator[](size_t index) const {

        return data_[index];
    }


    T &operator[](size_t index) {

        return data_[index];
    }

    [[nodiscard]] size_t size() const {

        return size_;
    }

private:
    void extend() {

        capacity_ *= 2;

        T *new_data = new T[capacity_];

        for (size_t i = 0; i < size_; ++i) {

            new_data[i] = data_[i];
        }

        delete[] data_;

        data_ = new_data;

    }

    T *data_;
    size_t size_;
    size_t capacity_;
};


#endif //LEVELUP_CPP_MAIN_VECTOR_HPP
