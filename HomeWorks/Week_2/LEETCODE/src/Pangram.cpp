//
// Created by Dmitry Morozov on 7/12/22.
//

#include <set>
#include <string>

class Solution {
public:
    bool checkIfPangram(std::string sentence) {

        auto pan = std::set(sentence.begin(), sentence.end());

        return pan.size() == 26;

    }
};