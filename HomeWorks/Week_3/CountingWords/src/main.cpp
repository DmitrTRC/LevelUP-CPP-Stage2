//
// Created by Dmitry Morozov on 20/9/22.
//

//#define DEBUG_

#include "main.hpp"


#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <locale>

#define MEASURE_TIME

//TODO: Remove from this place to Helper.hpp



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

    std::wcout << std::endl;

    CounterBase *counter;

    if (strcmp(method, "-hash") == 0) { // use HashMap

//        std::wcout << "Using HashMap" << std::endl;
//        counter = new CounterHashMap(data);
//        --argc;

    } else if (strcmp(method, "-bst") == 0) { // use BinarySearchTree

        throw std::runtime_error("Not implemented yet");
//
//        std::wcout << "Using BinarySearchTree" << std::endl;
//        counter = new CounterBST(data);
//        --argc;

    } else { // use std::unordered_map

        std::wcout << "Using std::unordered_map" << std::endl;
        counter = new Counter(data);

    }


#ifdef MEASURE_TIME
    counter->load_me();
#else
    counter->load();
#endif

    std::wcout << std::endl << "Total words: " << counter->total_words() << std::endl << std::endl;

    if (argc > 2) {

        std::wstring word_to_search;

        for (size_t i = 2; i < argc; ++i) {

            word_to_search = to_wstring(argv[i]);

            std::wcout << "Searching for word: " << word_to_search << std::endl << std::endl;


            int frequency = counter->get(word_to_search);

            std::wcout << word_to_search << " : " << frequency << " times" << std::endl << std::endl;

        }

    } else {

        std::cerr << "No word to search for!" << std::endl;

    }


    return 0;
}