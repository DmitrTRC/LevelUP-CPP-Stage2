//
// Created by Dmitry Morozov on 3/12/22.
//

#include "String.hpp"

#include <cwctype>
#include <cwchar>

wString::wString() : length_(0) {

    str_ = new wchar_t[1];
    str_[0] = '\0';
}

wString::wString(const wchar_t *str) {

    length_ = std::wcslen(str);

    str_ = new wchar_t[length_ + 1];

    wcscpy(str_, str);
}

wString::wString(const wString &str) : length_(str.length_) {

    str_ = new wchar_t[length_ + 1];

    std::wcscpy(str_, str.str_);
}

wString::wString(wString &&str) noexcept: length_(str.length_), str_(str.str_) {

    str.length_ = 0;
    str.str_ = nullptr;
}

wString::~wString() {

    delete[] str_;
}

const wchar_t *wString::wc_str() {

    return str_;
}

template<typename T>
wString &wString::operator=(T &&str) {

    if (this == &str) {

        return *this;
    }

    delete[] str_;

    length_ = str.length();

    str_ = new wchar_t[length_ + 1];

    std::wcscpy(str_, str.wc_str());

    return *this;
}


wchar_t &wString::operator[](int index) {

    return str_[index];
}


void wString::clear() {

    delete[] str_;

    length_ = 0;
    str_ = new wchar_t[1];
    str_[0] = '\0';

}

wString &wString::operator=(const wString &str) {

    if (this == &str) {

        return *this;
    }

    delete[] str_;

    length_ = std::wcslen(str.str_);

    str_ = new wchar_t[length_ + 1];

    std::wcscpy(str_, str.str_);

    return *this;
}

wString &wString::operator=(const wchar_t *str) {

    if (this == static_cast<const void *>(str)) {

        return *this;
    }

    delete[] str_;

    length_ = std::wcslen(str);

    str_ = new wchar_t[length_ + 1];

    std::wcscpy(str_, str);

    return *this;
}


void wString::append(const wString &str) {

    length_ += str.length_;

    wchar_t *temp = new wchar_t[length_ + 1];

    std::wcscpy(temp, str_);
    std::wcscat(temp, str.str_);

    delete[] str_;

    str_ = temp;


}

void wString::append(const wchar_t *str) {

    length_ += std::wcslen(str);

    wchar_t *temp = new wchar_t[length_ + 1];

    std::wcscpy(temp, str_);
    std::wcscat(temp, str);

    delete[] str_;

    str_ = temp;

}


template<typename T>
wString &wString::operator+=(T &str) {

    append(str);

    return *this;
}











