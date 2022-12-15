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


wString toLowerRus(wString &s, const std::locale &loc) {

    wString result;

//    std::transform(s.begin(), s.end(), std::back_inserter(result), [&loc](wchar_t c) {
//        return std::tolower(c, loc);
//    });

    for (auto c: s) {
        result.push_back(std::tolower(c, loc));
    }

    return result;
}


void printMap(std::unordered_map<std::wstring, int> &dict) {

    //Sort dictionary by value in descending order( Debug purpose only )
//    std::vector<std::pair<std::wstring, int>> vec;
//    std::copy(dict.begin(), dict.end(), std::back_inserter<std::vector<std::pair<std::wstring, int>>>(vec));
//    std::sort(vec.begin(), vec.end(), [](const std::pair<std::wstring, int> &a, const std::pair<std::wstring, int> &b) {
//        return a.second < b.second;
//    });
//
//    for (auto &pair: vec) {
//        std::wcout << pair.first << " : " << pair.second << std::endl;
//    }
}

/**
 * It removes all punctuation from a string
 *
 * @param str The string to be trimmed.
 */
void trim_punctuation(wString &str) {

    str.erase(std::remove_if(str.begin(), str.end(), [](wchar_t c) {
        return std::ispunct(c);
    }), str.end());


}


/**
 * It strips punctuation from the left and right of a string.
 *
 * @param str The string to strip punctuation from.
 */
void strip_punctuation_left_right(wString &str) {

    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
        return !std::ispunct(ch);
    }));

    str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
        return !std::ispunct(ch);
    }).base(), str.end());
}


std::wstring to_wstring(const std::string &str) {

    return std::wstring_convert<convert_t, wchar_t>{}.from_bytes(str);
}