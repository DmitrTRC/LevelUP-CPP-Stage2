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

wString toLowerRus(wString &, const std::locale &);


void trim_punctuation(std::wstring &);

void trim_punctuation(wString &);


void strip_punctuation_left_right(std::wstring &str);

void strip_punctuation_left_right(wString &str);


using convert_t = std::codecvt_utf8<wchar_t>;


std::wstring to_wstring(const std::string &);

#endif //LEVELUP_CPP_MAIN_HELPER_HPP
