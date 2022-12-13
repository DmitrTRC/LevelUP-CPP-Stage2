//
// Created by Dmitry Morozov on 20/9/22.
//
#include "Helper.hpp"


#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <fstream>
#include <locale>


int main(int argc, char *argv[]) {

    auto start = std::chrono::steady_clock::now();


    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file_name> <word_to_search>" << std::endl;
        return 1;
    }

    std::string file_name = argv[1];

    std::wstring word_to_search;



    //Set locale to Russian
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    if (argc > 2) {
        word_to_search = to_wstring(argv[2]);
        std::wcout << "Searching for word: " << word_to_search << std::endl;
    }
    std::wifstream file(argv[1]);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << argv[1] << std::endl;
        return 1;
    }

    std::wstring word;
    std::map<std::wstring, int> words;


    while (file >> word) {
        trim_punctuation(word);

        auto lWord = toLowerRus(word);

        if (!word.empty()) {
            words[lWord]++;
        }
    }

    if (!word_to_search.empty()) {
        std::wcout << "Word " << word_to_search << " found " << words[word_to_search] << " times" << std::endl;
    } else {
        printMap(words);
    }

    //Get execution time in ms
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Execution time: " << elapsed.count() << " ms" << std::endl;

    return 0;
}