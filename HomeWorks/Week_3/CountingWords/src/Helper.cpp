//
// Created by Dmitry Morozov on 13/12/22.
//

#include "Helper.hpp"

#include <iostream>
#include <cctype>

std::wstring toLowerRus(std::wstring &s) {
    {
        std::wstring result;
        std::locale loc = std::locale("ru_RU.UTF-8");
        for (std::wstring::const_iterator it = s.begin() ; it != s.end() ; ++it)
        {
            result += std::use_facet< std::ctype<wchar_t> >(loc).tolower( *it ) ;
        }
        return result;
    }
}

