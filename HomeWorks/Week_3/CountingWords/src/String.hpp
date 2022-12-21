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
    [[maybe_unused]] explicit wString(const wchar_t *str);

    /**
     * Copy constructor
     * @param str
     */
    [[maybe_unused]] wString(const wString &str);


    /**
     * Move constructor
     * @param str
     */
    [[maybe_unused]] wString(wString &&str) noexcept;

    /**
     * Destructor
     */
    ~wString();


    /**
     * Returns the length of the string
     * @return
     */
    [[nodiscard]] inline size_t length() const { return length_; }

    void setString(const wchar_t *str);

    [[nodiscard]] const wchar_t *c_str();


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

    //auto operator<=>(const wString &) const = default;
    bool operator==(const wString &rhs) const;

    bool operator!=(const wString &rhs) const;

    bool operator<(const wString &rhs) const;

    bool operator>(const wString &rhs) const;

    bool operator<=(const wString &rhs) const;

    bool operator>=(const wString &rhs) const;

    wchar_t &operator[](size_t index);

    void append(const wString &str);

    void append(const wchar_t *str);

    void push_back(wchar_t c);

    friend std::wostream &operator<<(std::wostream &wos, const wString &str) {

        wos << str.str_;
        return wos;
    };

    // operator >>

    friend std::wistream &operator>>(std::wistream &wos, wString &str) {

        std::wstring temp;
        wos >> temp;
        str.setString(temp.c_str());


        return wos;
    };


    void clear();

    class Iterator {
    public:
        explicit Iterator(wchar_t *ptr) : ptr_(ptr) {

        }


        Iterator &operator++() {

            ++ptr_;
            return *this;
        }


        Iterator &operator--() {

            --ptr_;
            return *this;

        }


        auto operator-(const Iterator &rhs) const {

            return ptr_ - rhs.ptr_;

        }

        auto operator-(const wchar_t *str) const {

            return ptr_ - str;
        }

        wchar_t &operator*() const { return *ptr_; }

        wchar_t *operator->() const { return ptr_; }

        bool operator==(const Iterator &rhs) const { return ptr_ == rhs.ptr_; }

        bool operator!=(const Iterator &rhs) const { return ptr_ != rhs.ptr_; }

        bool operator<(const Iterator &rhs) const { return ptr_ < rhs.ptr_; }

        bool operator>(const Iterator &rhs) const { return ptr_ > rhs.ptr_; }


    private:
        wchar_t *ptr_;

    };

    [[nodiscard]] Iterator begin() const { return Iterator(str_); }

    // Return iterator to end of string
    [[nodiscard]] Iterator end() const { return Iterator(str_ + length_); }

    // Erase()
    void erase(size_t index, size_t count = 1);


private:
    wchar_t *str_;
    size_t length_;

};


#endif //LEVELUP_CPP_MAIN_STRING_HPP
