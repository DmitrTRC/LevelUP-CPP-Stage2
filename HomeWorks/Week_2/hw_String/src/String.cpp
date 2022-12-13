//
// Created by Dmitry Morozov on 3/12/22.
//

#include "String.hpp"

#include <cstring>

String::String() : _length(0) {

    _str = new char[1];
    _str[0] = '\0';
}

String::String(const char *str) {

    _length = std::strlen(str);

    _str = new char[_length + 1];

    strcpy(_str, str);
}

String::String(const String &str) : _length(str._length) {

    _str = new char[_length + 1];

    std::strcpy(_str, str._str);
}

String::String(String &&str) noexcept: _length(str._length), _str(str._str) {

    str._length = 0;
    str._str = nullptr;
}

String::~String() {

    delete[] _str;
}

const char *String::c_str() {

    return _str;
}

template<typename T>
String &String::operator=(T &&str) {

    if (this == &str) {

        return *this;
    }

    delete[] _str;

    _length = str.length();

    _str = new char[_length + 1];

    std::strcpy(_str, str.c_str());

    return *this;
}


char &String::operator[](int index) {

    return _str[index];
}


void String::clear() {

    delete[] _str;

    _length = 0;
    _str = new char[1];
    _str[0] = '\0';

}

String &String::operator=(const String &str) {

    if (this == &str) {

        return *this;
    }

    delete[] _str;

    _length = std::strlen(str._str);

    _str = new char[_length + 1];

    std::strcpy(_str, str._str);

    return *this;
}

String &String::operator=(const char *str) {

    if (this == static_cast<const void *>(str)) {

        return *this;
    }

    delete[] _str;

    _length = std::strlen(str);

    _str = new char[_length + 1];

    std::strcpy(_str, str);

    return *this;
}


void String::append(const String &str) {

    _length += str._length;

    char *temp = new char[_length + 1];

    std::strcpy(temp, _str);
    std::strcat(temp, str._str);

    delete[] _str;

    _str = temp;


}

void String::append(const char *str) {

    _length += std::strlen(str);

    char *temp = new char[_length + 1];

    std::strcpy(temp, _str);
    std::strcat(temp, str);

    delete[] _str;

    _str = temp;

}


template<typename T>
String &String::operator+=(T &str) {

    append(str);

    return *this;
}











