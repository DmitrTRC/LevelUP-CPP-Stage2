//
// Created by Dmitry Morozov on 20/9/22.
//

#include <iostream>

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


    return 0;
}