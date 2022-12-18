//
// Created by Dmitry Morozov on 20/9/22.
//

//#define DEBUG_

#include "Counter_Base.hpp"
#include "Hash_Map.hpp"
#include "Helper.hpp"
#include "W_Bst.hpp"
#include "Counter.hpp"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <locale>
#include <unordered_map>


int main(int argc, char *argv[]) {

    if (argc < 2) { // no file name

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

    if (!file.is_open()) {  // check if file is open normally

        std::cerr << "Failed to open file: " << argv[1] << std::endl;

        return 1;
    }

    std::wstring data;


    getline(file, data, std::wstring::traits_type::to_char_type( // read file to data until EOF
            std::wstring::traits_type::eof()));


    auto method = argv[argc - 1]; // get method from command line

    CounterBase *counter;

    if (strcmp(method, "-hash") == 0) { // use HashMap

        std::wcout << "Using HashMap" << std::endl;
        counter = new Counter<HashMap>(data);
        --argc;

    } else if (strcmp(method, "-bst") == 0) { // use BinarySearchTree

        std::wcout << "Using BinarySearchTree" << std::endl;
        counter = new Counter<wBST>(data);
        --argc;

    } else { // use std::unordered_map

        std::wcout << "Using std::unordered_map" << std::endl;
        counter = new Counter<std::unordered_map<std::wstring, int>>(data);

    }

    counter->load();

    if (argc > 2) {

        std::wstring word_to_search;

        for (size_t i = 2; i < argc; ++i) {

            word_to_search = to_wstring(argv[i]);

            std::wcout << "Searching for word: " << word_to_search << std::endl;

            int frequency = counter->get(word_to_search);

            std::wcout << word_to_search << " : " << frequency << " times" << std::endl;

        }

    } else {

        std::cerr << "No word to search for!" << std::endl;

    }


    return 0;
}