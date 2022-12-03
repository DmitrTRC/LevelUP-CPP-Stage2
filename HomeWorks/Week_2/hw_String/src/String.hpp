//
// Created by Dmitry Morozov on 3/12/22.
//

#ifndef LEVELUP_CPP_MAIN_STRING_HPP
#define LEVELUP_CPP_MAIN_STRING_HPP


class String {

public:
    String();

    String(const char *str);

    String(const String &str);

    String(String &&str) noexcept;

    ~String();

    String &operator=(const String &str);

    String &operator=(const char *str);

    String &operator+=(const String &str);

    String &operator+=(const char *str);

    String operator+(const String &str);

    String operator+(const char *str);

    bool operator==(const String &str);

    bool operator==(const char *str);

    bool operator!=(const String &str);

    bool operator!=(const char *str);

    char &operator[](int index);

    int length();

    void clear();

    const char *c_str();

private:
    char *_str;
    int _length;

};




#endif //LEVELUP_CPP_MAIN_STRING_HPP
