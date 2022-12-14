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
    [[nodiscard]] inline size_t length() const { return length_; }

    /**
     * Returns the char* of the string
     * @return
     */
    [[nodiscard]] const char *c_str();


    [[nodiscard]] inline bool empty() const { return length_ == 0; }

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

        os << str.str_;
        return os;
    };

    void clear();

    class Iterator {
    public:
        explicit Iterator(char *ptr) : ptr_(ptr) {}

        Iterator &operator++() {

            ++ptr_;
            return *this;
        }

        const Iterator operator++(int) {

            Iterator tmp(*this);
            operator++();
            return tmp;
        }

        Iterator &operator--() {

            --ptr_;
            return *this;
        }

        const Iterator operator--(int) {

            Iterator tmp(*this);
            operator--();
            return tmp;
        }

        char &operator*() const { return *ptr_; }

        char *operator->() const { return ptr_; }

        bool operator==(const Iterator &rhs) const { return ptr_ == rhs.ptr_; }

        bool operator!=(const Iterator &rhs) const { return ptr_ != rhs.ptr_; }

    private:
        char *ptr_;
    };

    Iterator begin() { return Iterator(str_); }

    // Return iterator to end of string
    Iterator end() { return Iterator(str_ + length_); }

private:
    char *str_;
    size_t length_;

};


#endif //LEVELUP_CPP_MAIN_STRING_HPP
