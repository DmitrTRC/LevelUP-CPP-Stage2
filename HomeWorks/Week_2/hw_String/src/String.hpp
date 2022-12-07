//
// Created by Dmitry Morozov on 3/12/22.
//

#ifndef LEVELUP_CPP_MAIN_STRING_HPP
#define LEVELUP_CPP_MAIN_STRING_HPP

#include <iostream>

class String {

public:
    String();

    explicit String(const char *str);

    String(const String &str);

    String(String &&str) noexcept;

    ~String();


    // Capacity
    [[nodiscard]] inline size_t length() const { return _length; }


    [[nodiscard]] inline bool empty() const { return _length == 0; }

    bool operator==(const String &str);

    template<typename T>
    String &operator=(T &&str);

    String &operator=(const String &str);

    String &operator=(const char *str);

    template<typename T>
    String &operator+=(T &str);

    template<typename T>
    String &operator+(T &str);

    template<typename T>
    bool operator  <=>(T &str);


    char &operator[](int index);

    void append(const String &str);

    void append(const char *str);


    friend std::ostream &operator<<(std::ostream &os, const String &str);

    void clear();

    const char *c_str();

private:
    char *_str;
    size_t _length;

};

inline std::ostream &operator<<(std::ostream &os, const String &str) {

    os << str._str;
    return os;
}


#endif //LEVELUP_CPP_MAIN_STRING_HPP
