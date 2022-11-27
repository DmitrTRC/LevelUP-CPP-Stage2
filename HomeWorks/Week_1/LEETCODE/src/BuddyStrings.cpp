//
// Created by Dmitry Morozov on 27/11/22.
//


#include <iostream>
#include <set>

using namespace std;


class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if (s.length() != goal.length()) return false;

        if (s == goal) {
            set<char> s_set;
            for (char c: s) {
                s_set.insert(c);
            }
            return s_set.size() < s.length();
        }

        int first = -1;
        int second = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                if (first == -1) {
                    first = i;
                } else if (second == -1) {
                    second = i;
                } else {
                    return false;
                }
            }
        }
        return (second != -1) && (s[first] == goal[second]) && (s[second] == goal[first]);
    }
};
