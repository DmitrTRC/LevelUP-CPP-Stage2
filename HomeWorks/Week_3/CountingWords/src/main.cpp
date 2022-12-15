//
// Created by Dmitry Morozov on 20/9/22.
//
#include "Helper.hpp"
#include "W_Bst.hpp"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
// #include <unordered_map>


int main(int argc, char *argv[]) {

    auto start = std::chrono::steady_clock::now();


    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file_name> <word_to_search>" << std::endl;
        return 1;
    }

    std::string file_name = argv[1]; // get file name from command line

    std::wstring word_to_search;

    //Set locale to Russian
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    std::wifstream file(argv[1]);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << argv[1] << std::endl;
        return 1;
    }

    std::wstring word;

    std::wstring data;
    //std::unordered_map<std::wstring, int> words;
    wBST words;

    std::locale loc = std::locale("ru_RU.UTF-8");

    getline(file, data, std::wstring::traits_type::to_char_type(
            std::wstring::traits_type::eof()));

    auto ss = std::wstringstream(data);

    while (ss >> word) {
        trim_punctuation(word);

        auto lWord = toLowerRus(word, loc);

        if (!word.empty()) {
            //  words[lWord]++;
            words.Add(lWord);
        }
    }


    std::wcout << "Total words found: " << words.size() << std::endl;

    if (argc > 2) {

        for (size_t i = 2; i < argc; ++i) {
            word_to_search = to_wstring(argv[i]);
            std::wcout << "Searching for word: " << word_to_search << std::endl;
            //  std::wcout << "Word " << word_to_search << " found " << words[word_to_search] << " times" << std::endl;
            std::wcout << "Word " << word_to_search << " found " << words.Search(word_to_search) << " times"
                       << std::endl;
        }

    } else {
        std::wcout << "No word to search for" << std::endl;
    }

    //Get execution time in ms
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Execution time: " << elapsed.count() << " ms" << std::endl;

    return 0;
}