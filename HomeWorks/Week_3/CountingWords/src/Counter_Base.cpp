//
// Created by Dmitry Morozov on 18/12/22.
//

#include "Counter_Base.hpp"


CounterBase::~CounterBase() {

    delete buffer_;

}

  void CounterBase::load() {

      std::locale loc = std::locale("ru_RU.UTF-8");

      wString word;

      while (*buffer_ >> word) {
          trim_punctuation(word);

          auto lWord = toLowerRus(word, loc);

        if (!lWord.empty()) {

            adder(lWord);
            total_words_++;

        }

    }


}

void CounterBase::load_me() {

    auto start = std::chrono::steady_clock::now();

    load();

    auto end = std::chrono::steady_clock::now();

    std::cerr << "Time to load MAP : " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;


}


size_t CounterBase::total_words() const {

    return total_words_;

}





