//
// Created by Dmitry Morozov on 20/9/22.
//
#include "Helper.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <fstream>
#include <cwctype>
#include <locale>


void printMap(std::map<std::wstring, int> &map) {
    for (auto &item : map) {
        std::wcout << item.first << L" - " << item.second << std::endl;
    }
}



void trim_punctuation(std::wstring &str) {

    str.erase(std::remove_if(str.begin(), str.end(), ispunct), str.end());
}

/**
 * @brief Program reads a given file and counts word occurrences in it
 * @param argc
 * @param argv
 * @return 0 if success
 */
int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_name>" << std::endl;
        return 1;
    }

    //Set locale to Russian
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    std::wifstream file(argv[1]);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << argv[1] << std::endl;
        return 1;
    }

    std::wstring word;
    std::map<std::wstring, int> words;
   // printASCII();

    while (file >> word) {
        trim_punctuation(word);

        auto lWord = toLowerRus(word);

        if (!word.empty()) {
            words[lWord]++;
        }
    }

    printMap(words);

    return 0;
}