
/*
 * Copyright (C) Jianyong Chen
 */

#include <cstdio>
#include <vector>


class Solution
{
    public:
        bool canJump(std::vector<int> &nums) {
            int  j, last;

            if (nums.size() <= 1) {
                return true;
            }

            last = nums.size()-1;
            for (j = nums.size()-2; j >= 0; j--) {

                if (nums[j] >= (last - j)) {
                    last = j;
                }
            }

            if (last != 0) {
                return false;
            }

            return true;
        }
};


int
main(int argc, char **argv)
{
    Solution          ans;
    std::vector<int>  nums;


    nums = { 2, 3, 1, 1, 4 };
    printf("canJump: %d\n", ans.canJump(nums));

    nums = { 3, 2, 1, 0, 4 };
    printf("canJump: %d\n", ans.canJump(nums));

    nums = { 0, 1 };
    printf("canJump: %d\n", ans.canJump(nums));

    nums = { 1, 2 };
    printf("canJump: %d\n", ans.canJump(nums));
}
