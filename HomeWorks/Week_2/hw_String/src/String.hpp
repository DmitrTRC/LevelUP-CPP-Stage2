//
// Created by Dmitry Morozov on 3/12/22.
//

#ifndef LEVELUP_CPP_MAIN_STRING_HPP
#define LEVELUP_CPP_MAIN_STRING_HPP

#include <iostream>

class String {

public:

    /**
     * Default constructor
     */
    String();

    /**
     * Constructor with char*
     * @param str
     */
    explicit String(const char *str);

    /**
     * Copy constructor
     * @param str
     */
    String(const String &str);

    /**
     * Move constructor
     * @param str
     */
    String(String &&str) noexcept;

    /**
     * Destructor
     */
    ~String();


    /**
     * Returns the length of the string
     * @return
     */
    [[nodiscard]] inline size_t length() const { return _length; }

    /**
     * Returns the char* of the string
     * @return
     */
    [[nodiscard]] const char *c_str();


    [[nodiscard]] inline bool empty() const { return _length == 0; }



    template<typename T>
    String &operator=(T &&str);


    String &operator=(const String &str);


    String &operator=(const char *str);

    template<typename T>
    String &operator+=(T &str);

    template<typename T, typename Y>
    friend String operator+(T &lhs_str, Y &rhs_str) {

        String result(lhs_str);
        result += rhs_str;
        return result;
    }

    auto operator<=>(const String &) const = default;


    char &operator[](int index);

    void append(const String &str);

    void append(const char *str);


    friend std::ostream &operator<<(std::ostream &os, const String &str) {

        os << str._str;
        return os;
    };

    void clear();


private:
    char *_str;
    size_t _length;

};


#endif //LEVELUP_CPP_MAIN_STRING_HPP
