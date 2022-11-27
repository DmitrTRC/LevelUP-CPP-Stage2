//
// Created by Dmitry Morozov on 27/11/22.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int xor_result = 0;
        for (auto num : nums) {
            xor_result ^= num;
        }

        int mask = 1;
        while ((xor_result & mask) == 0) {
            mask <<= 1;
        }

        int first = 0;
        int second = 0;
        for (auto num : nums) {
            if ((num & mask) == 0) {
                first ^= num;
            } else {
                second ^= num;
            }
        }

        return {first, second};

    }

};