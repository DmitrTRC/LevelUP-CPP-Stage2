//
// Created by Dmitry Morozov on 13/12/22.
//

#include "Helper.hpp"
#include "String.hpp"


#include <algorithm>
#include <cctype>
#include <codecvt>
#include <iostream>
#include <vector>


std::wstring toLowerRus(std::wstring &s, const std::locale &loc) {

    std::wstring result;

    std::transform(s.begin(), s.end(), std::back_inserter(result), [&loc](wchar_t c) {
        return std::tolower(c, loc);
    });


    return result;
}

wString toLowerRus(wString &s, const std::locale &loc) {

    wString result;

    for (auto &c: s) {
        result.push_back(std::tolower(c, loc));

    }

    return result;
}


/**
 * It removes all punctuation from a string
 *
 * @param str The string to be trimmed.
 */
void trim_punctuation(std::wstring &str) {

    str.erase(std::remove_if(str.begin(), str.end(), [](wchar_t c) {
        return std::ispunct(c);
    }), str.end());


}

void trim_punctuation(wString &str) { // Non STL

    for (size_t i = 0; i < str.length(); i++) {
        if (std::ispunct(str[i])) {
            str.erase(i, 1);
            i--;
        }
    }

}


std::wstring to_wstring(const std::string &str) {

    return std::wstring_convert<convert_t, wchar_t>{}.from_bytes(str);
}