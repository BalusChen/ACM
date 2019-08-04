
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>


class Solution {
    public:
        int search(std::vector<int>& nums, int target) {
            int  i;

            for (i = 0; i < nums.size(); i++) {
                if (nums[i] == target) {
                    return i;
                }
            }

            return -1;
        }
};
