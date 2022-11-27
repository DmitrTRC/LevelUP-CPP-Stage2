//
// Created by Dmitry Morozov on 27/11/22.
//

#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {

        int result = 0;

        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int num: nums) {
                sum += (num >> i) & 1;
                sum %= 3;
            }
            if (sum) {
                result |= sum << i;
            }
        }

        return result;

    }
};