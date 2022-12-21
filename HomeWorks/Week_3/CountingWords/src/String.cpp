//
// Created by Dmitry Morozov on 3/12/22.
//

#include "String.hpp"

#include <cwchar>

wString::wString() : length_(0) {

    str_ = new wchar_t[1];
    str_[0] = '\0';
}

[[maybe_unused]] wString::wString(const wchar_t *str) {

    length_ = std::wcslen(str);

    str_ = new wchar_t[length_ + 1];

    wcscpy(str_, str);
}

[[maybe_unused]] wString::wString(const wString &str) : length_(str.length_) {

    str_ = new wchar_t[length_ + 1];

    std::wcscpy(str_, str.str_);
}

[[maybe_unused]] wString::wString(wString &&str) noexcept: length_(str.length_), str_(str.str_) {

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


wchar_t &wString::operator[](size_t index) {

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

    auto *temp = new wchar_t[length_ + 1];

    std::wcscpy(temp, str_);
    std::wcscat(temp, str.str_);

    delete[] str_;

    str_ = temp;


}

void wString::append(const wchar_t *str) {

    length_ += std::wcslen(str);

    auto *temp = new wchar_t[length_ + 1];

    std::wcscpy(temp, str_);
    std::wcscat(temp, str);

    delete[] str_;

    str_ = temp;

}

void wString::push_back(wchar_t c) {

    length_++;

    auto *temp = new wchar_t[length_ + 1];

    std::wcscpy(temp, str_);
    temp[length_ - 1] = c;
    temp[length_] = '\0';

    delete[] str_;

    str_ = temp;

}


void wString::erase(size_t index, size_t count) {

    if (index >= length_) {

        return;
    }

    if (index + count > length_) {

        count = length_ - index;
    }

    length_ -= count;

    auto *temp = new wchar_t[length_ + 1];

    std::wcsncpy(temp, str_, index);
    std::wcsncpy(temp + index, str_ + index + count, length_ - index);
    temp[length_] = '\0';

    delete[] str_;

    str_ = temp;


}

void wString::setString(const wchar_t *str) {

    delete[] str_;

    length_ = std::wcslen(str);

    str_ = new wchar_t[length_ + 1];

    std::wcscpy(str_, str);


}

bool wString::operator==(const wString &rhs) const {

    return wcscmp(str_, rhs.str_) == 0;
}

bool wString::operator!=(const wString &rhs) const {

    return !(rhs == *this);
}

bool wString::operator<(const wString &rhs) const {

    return wcscmp(str_, rhs.str_) < 0;
}

bool wString::operator>(const wString &rhs) const {

    return rhs < *this;
}

bool wString::operator<=(const wString &rhs) const {

    return !(rhs < *this);
}

bool wString::operator>=(const wString &rhs) const {

    return !(*this < rhs);
}

const char *wString::c_str() {

    return reinterpret_cast<const char *>(str_);
}


wString &wString::operator+=(wString &str) {

    append(str);

    return *this;
}

wString &wString::operator+(const wchar_t *str) {

    append(str);

    return *this;
}


