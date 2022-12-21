//
// Created by Dmitry Morozov on 18/12/22.
//

#include "Counter.hpp"


void Counter::adder(std::wstring &word) {

    map_[word]++;

}


int Counter::get(std::wstring &word) {

    return map_[word];
}

void Counter::load() {

    std::locale loc = std::locale("ru_RU.UTF-8");

    std::wstring word;

    while (*buffer_ >> word) {
        trim_punctuation(word);

        auto lWord = toLowerRus(word, loc);

        if (!lWord.empty()) {

            adder(lWord);
            total_words_++;

        }

    }


}
