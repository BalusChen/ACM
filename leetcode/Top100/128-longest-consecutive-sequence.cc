
/*
 * Copyright (C) Jianyong Chen
 */

#include <vector>

class Solution {
    public:
        int longestConsecutive(std::vector<int>& nums) {
            int  prev, max_len, cur_len, i;

            if (nums.size() < 2) {
                return nums.size();
            }

            std::sort(nums.begin(), nums.end());

            prev = nums[0];
            cur_len = 1;
            max_len = 0;
            for (i = 1; i < nums.size(); i++) {
                if (prev == nums[i]) {
                    continue;
                }

                if (prev + 1 == nums[i]) {
                    prev = nums[i];
                    cur_len++;

                } else {
                    max_len = std::max(cur_len, max_len);
                    prev = nums[i];
                    cur_len = 1;
                }

            }

            return std::max(cur_len, max_len);
        }
};
