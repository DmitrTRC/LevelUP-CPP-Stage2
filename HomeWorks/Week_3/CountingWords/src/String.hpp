//
// Created by Dmitry Morozov on 3/12/22.
//

#ifndef LEVELUP_CPP_MAIN_STRING_HPP
#define LEVELUP_CPP_MAIN_STRING_HPP

#include <iostream>

class wString {

public:

    /**
     * Default constructor
     */
    wString();

    /**
     * Constructor with char*
     * @param str
     */
    explicit wString(const wchar_t *str);

    /**
     * Copy constructor
     * @param str
     */
    wString(const wString &str);

    /**
     * Move constructor
     * @param str
     */
    wString(wString &&str) noexcept;

    /**
     * Destructor
     */
    ~wString();


    /**
     * Returns the length of the string
     * @return
     */
    [[nodiscard]] inline size_t length() const { return length_; }

    /**
     * Returns the char* of the string
     * @return
     */
    [[nodiscard]] const wchar_t *wc_str();


    [[nodiscard]] inline bool empty() const { return length_ == 0; }

    template<typename T>
    wString &operator=(T &&str);

    wString &operator=(const wString &str);

    wString &operator=(const wchar_t *str);

    template<typename T>
    wString &operator+=(T &str);

    template<typename T, typename Y>
    friend wString operator+(T &lhs_str, Y &rhs_str) {

        wString result(lhs_str);
        result += rhs_str;
        return result;
    }

    auto operator<=>(const wString &) const = default;

    wchar_t &operator[](int index);

    void append(const wString &str);

    void append(const wchar_t *str);

    friend std::wostream &operator<<(std::wostream &wos, const wString &str) {

        wos << str.str_;
        return wos;
    };

    void clear();

    class Iterator {
    public:
        explicit Iterator(wchar_t *ptr) : ptr_(ptr) {}

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

        wchar_t &operator*() const { return *ptr_; }

        wchar_t *operator->() const { return ptr_; }

        bool operator==(const Iterator &rhs) const { return ptr_ == rhs.ptr_; }

        bool operator!=(const Iterator &rhs) const { return ptr_ != rhs.ptr_; }

    private:
        wchar_t *ptr_;
    };

    Iterator begin() { return Iterator(str_); }

    // Return iterator to end of string
    Iterator end() { return Iterator(str_ + length_); }

private:
    wchar_t *str_;
    size_t length_;

};


#endif //LEVELUP_CPP_MAIN_STRING_HPP
