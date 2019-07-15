

/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>

class Solution
{
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            int               i, j;
            std::vector<int>  ans(2, 0);

            for (i = 0; i < nums.size()-1; i++) {
                for (j = i+1; j < nums.size(); j++) {
                    if (nums[i] + nums[j] == target) {
                        ans[0] = i;
                        ans[1] = j;
                        break;
                    }
                }
            }

            return ans;
        }
};
