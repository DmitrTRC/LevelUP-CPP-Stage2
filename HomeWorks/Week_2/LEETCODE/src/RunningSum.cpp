//
// Created by Dmitry Morozov on 7/12/22.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {

        vector<int> runningNums;
        int tmp = 0;
        for (int num : nums) {
            tmp += num;
            runningNums.push_back(tmp);
        }

        return runningNums; //Right way just return runningNums. Ok

    }
};

