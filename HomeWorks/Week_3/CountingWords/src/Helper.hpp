//
// Created by Dmitry Morozov on 13/12/22.
//

#ifndef LEVELUP_CPP_MAIN_HELPER_HPP
#define LEVELUP_CPP_MAIN_HELPER_HPP

#include "String.hpp"

#include <codecvt>
#include <iostream>
#include <unordered_map>

wString toLowerRus(wString &, const std::locale &);

void printMap(std::unordered_map<wString, int> &);

void trim_punctuation(wString &);

using convert_t = std::codecvt_utf8<wchar_t>;


wString to_wstring(const std::string &);

#endif //LEVELUP_CPP_MAIN_HELPER_HPP
