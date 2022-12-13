//
// Created by Dmitry Morozov on 13/12/22.
//

#include "Helper.hpp"

#include <algorithm>
#include <cctype>
#include <codecvt>
#include <iostream>
#include <vector>
#include <map>


std::wstring toLowerRus(std::wstring &s, const std::locale &loc) {


    {
        std::wstring result;


        std::transform(s.begin(), s.end(), std::back_inserter(result), [&loc](wchar_t c) {
            return std::tolower(c, loc);
        });

        return result;
    }
}


void printMap(std::unordered_map<std::wstring, int> &dict) {

    //Sort dictionary by value in descending order( Debug purpose only )
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