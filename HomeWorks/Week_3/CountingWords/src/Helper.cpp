//
// Created by Dmitry Morozov on 13/12/22.
//

#include "Helper.hpp"

#include <algorithm>
#include <iostream>
#include <cctype>
#include <vector>
#include <codecvt>

std::wstring toLowerRus(std::wstring &s, const std::locale &loc) {

    {
        std::wstring result;
//        std::locale loc = std::locale("ru_RU.UTF-8");
        for (std::wstring::const_iterator it = s.begin(); it != s.end(); ++it) {
            result += std::use_facet<std::ctype<wchar_t> >(loc).tolower(*it);
        }
        return result;
    }
}

void printMap(std::unordered_map<std::wstring, int> &dict) {

    //Sort dictionary by value
    std::vector<std::pair<std::wstring, int>> vec;
    std::copy(dict.begin(), dict.end(), std::back_inserter<std::vector<std::pair<std::wstring, int>>>(vec));
    std::sort(vec.begin(), vec.end(), [](const std::pair<std::wstring, int> &a, const std::pair<std::wstring, int> &b) {
        return a.second < b.second;
    });

    for (auto &pair: vec) {
        std::wcout << pair.first << " : " << pair.second << std::endl;
    }
}

void trim_punctuation(std::wstring &str) {

    str.erase(std::remove_if(str.begin(), str.end(), ispunct), str.end());
}


std::wstring to_wstring(const std::string &str) {

    return std::wstring_convert<convert_t, wchar_t>{}.from_bytes(str);
}