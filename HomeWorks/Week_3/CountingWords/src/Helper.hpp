//
// Created by Dmitry Morozov on 13/12/22.
//

#ifndef LEVELUP_CPP_MAIN_HELPER_HPP
#define LEVELUP_CPP_MAIN_HELPER_HPP

#include "String.hpp"

#include <codecvt>
#include <iostream>
#include <unordered_map>

std::wstring toLowerRus(std::wstring &, const std::locale &);

[[maybe_unused]] void printMap(std::unordered_map<std::wstring, int> &);

void trim_punctuation(std::wstring &);

[[maybe_unused]] void strip_punctuation_left_right(std::wstring &str);

using convert_t = std::codecvt_utf8<wchar_t>;


std::wstring to_wstring(const std::string &);

#endif //LEVELUP_CPP_MAIN_HELPER_HPP
