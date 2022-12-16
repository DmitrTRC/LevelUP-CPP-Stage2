//
// Created by Dmitry Morozov on 17/12/22.
//

#include "Vector.hpp"

Vector::Vector() {

    data_ = new int[INITIAL_CAPACITY];
    capacity_ = INITIAL_CAPACITY;
    size_ = 0;
}

Vector::~Vector() {

    delete[] data_;
}

void Vector::push_back(int value) {

    if (size_ == capacity_) {
        extend();
    }
    data_[size_] = value;
    ++size_;
}

int Vector::operator[](size_t index) const {

    return data_[index];
}

int &Vector::operator[](size_t index) {

    return data_[index];
}

[[nodiscard]] size_t Vector::size() const {

    return size_;
}

void Vector::extend() {

    int *new_data = new int[capacity_ * 2];
    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ *= 2;
}

void Vector::resize(size_t new_size) {

    if (new_size > capacity_) {
        int *new_data = new int[new_size];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_size;
    }
    size_ = new_size;

}
