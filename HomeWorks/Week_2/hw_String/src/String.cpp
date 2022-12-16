//
// Created by Dmitry Morozov on 3/12/22.
//

#include "String.hpp"

#include <cstring>

String::String() : length_(0) {

    str_ = new char[1];
    str_[0] = '\0';
}

String::String(const char *str) {

    length_ = std::strlen(str);

    str_ = new char[length_ + 1];

    strcpy(str_, str);
}

String::String(const String &str) : length_(str.length_) {

    str_ = new char[length_ + 1];

    std::strcpy(str_, str.str_);
}

String::String(String &&str) noexcept: length_(str.length_), str_(str.str_) {

    str.length_ = 0;
    str.str_ = nullptr;
}

String::~String() {

    delete[] str_;
}

const char *String::c_str() {

    return str_;
}

template<typename T>
String &String::operator=(T &&str) {

    if (this == &str) {

        return *this;
    }

    delete[] str_;

    length_ = str.length();

    str_ = new char[length_ + 1];

    std::strcpy(str_, str.c_str());

    return *this;
}


char &String::operator[](int index) {

    return str_[index];
}


void String::clear() {

    delete[] str_;

    length_ = 0;
    str_ = new char[1];
    str_[0] = '\0';

}

String &String::operator=(const String &str) {

    if (this == &str) {

        return *this;
    }

    delete[] str_;

    length_ = std::strlen(str.str_);

    str_ = new char[length_ + 1];

    std::strcpy(str_, str.str_);

    return *this;
}

String &String::operator=(const char *str) {

    if (this == static_cast<const void *>(str)) {

        return *this;
    }

    delete[] str_;

    length_ = std::strlen(str);

    str_ = new char[length_ + 1];

    std::strcpy(str_, str);

    return *this;
}


void String::append(const String &str) {

    length_ += str.length_;

    char *temp = new char[length_ + 1];

    std::strcpy(temp, this->str_);
    std::strcat(temp, str.str_);

    delete[] str_;

    str_ = temp;


}

void String::append(const char *str) {

    length_ += std::strlen(str);

    char *temp = new char[length_ + 1];

    std::strcpy(temp, str_);
    std::strcat(temp, str);

    delete[] str_;

    str_ = temp;

}


template<typename T>
String &String::operator+=(T &str) {

    append(str);

    return *this;
}











