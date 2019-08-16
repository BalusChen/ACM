
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>


class Solution {
    public:
        int rob(std::vector<int>& nums) {
            int               i;
            std::vector<int>  dp1, dp2;

            if (nums.size() < 2) {
                return nums.empty() ? 0 : nums[0];
            }

            if (nums.size() == 2) {
                return std::max(nums[0], nums[1]);
            }


            /* rob from house-0 to house-n-1 */

            dp1.resize(nums.size() - 1);
            dp1[0] = nums[0];
            dp1[1] = std::max(nums[0], nums[1]);
            for (i = 2; i < dp1.size(); i++) {
                dp1[i] = std::max(dp1[i-1], dp1[i-2] + nums[i]);
            }

            /* rob from house-1 to house-n */

            dp2.resize(nums.size() - 1);
            dp2[0] = nums[1];
            dp2[1] = std::max(nums[1], nums[2]);
            for (i = 2; i < dp2.size(); i++) {
                dp2[i] = std::max(dp2[i-1], dp2[i-2] + nums[i+1]);
            }

            return std::max(dp1.back(), dp2.back());
        }
};


int
main(int argc, char **argv)
{
    Solution          ans;
    std::vector<int>  nums;

    nums = { 2, 3, 2 };
    printf("ans: %d\n", ans.rob(nums));

    nums = { 1, 2, 3, 1 };
    printf("ans: %d\n", ans.rob(nums));

    nums = { 3, 2, 1, 7, 4, 13, 6, 7, 3 };
    printf("ans: %d\n", ans.rob(nums));

    return 0;
}
