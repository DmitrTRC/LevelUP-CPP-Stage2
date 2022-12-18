//
// Created by Dmitry Morozov on 20/9/22.
//

//#define DEBUG_

#include "Hash_Map.hpp"
#include "Helper.hpp"
#include "W_Bst.hpp"
#include "Counter.hpp"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <unordered_map>


int main(int argc, char *argv[]) {

    if (argc < 2) {

        std::cerr << "Usage: " << argv[0] << " <file_name> <word_to_search> < -options >" << std::endl;
        std::cerr << "Options: -hash : use HashMap , -bst : use BinarySearch, no-option : use std::unordered_map"
                  << std::endl;

        return 1;
    }

    std::string file_name = argv[1]; // get file name from command line

    //Set locale to Russian
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    std::wifstream file(argv[1]);

    if (!file.is_open()) {

        std::cerr << "Failed to open file: " << argv[1] << std::endl;

        return 1;
    }

    std::wstring data;

    std::locale loc = std::locale("ru_RU.UTF-8"); // TODO : Move to Helper.cpp

    getline(file, data, std::wstring::traits_type::to_char_type(
            std::wstring::traits_type::eof()));


    auto method = argv[argc - 1];

    if (strcmp(method, "-hash") == 0) {

        Counter<HashMap> counter(data);
        --argc;

    } else if (strcmp(method, "-bst") == 0) {

        Counter<wBST> counter(data);
        --argc;

    } else {

        Counter<std::unordered_map<std::wstring, int>> counter(data);

    }

    if (argc > 2) {

        std::wstring word_to_search;

        for (size_t i = 2; i < argc; ++i) {

            word_to_search = to_wstring(argv[i]);
            std::wcout << "Searching for word: " << word_to_search << std::endl;

        }

    } else {

        std::cerr << "No word to search for!" << std::endl;

    }


    return 0;
}