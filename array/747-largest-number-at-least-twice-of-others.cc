#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
    public:
        int dominantIndex(std::vector<int> &nums) {
            int first = -1, second = -1;
            int index = 0;

            // 题目中已经说明nums[i]在[0, 99]之间
            for (int i = 0; i< nums.size(); i++) {
                if (nums[i] > first) {
                    index = i;
                    second = first;
                    first = nums[i];
                } else if (nums[i] > second) {
                    second = nums[i];
                }
            }

            return (first >= 2*second) ? index : -1;
        }
};
