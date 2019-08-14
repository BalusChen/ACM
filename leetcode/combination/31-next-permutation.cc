
/*
 * Copyright (C) Jianyong Chen
 */


#include "../include/print.h"


class Solution
{
    public:
        void nextPermutation(std::vector<int> &nums) {
            int               i, j;
            std::vector<int>  next;

            if (nums.size() < 2) {
                return;
            }

            for (i = nums.size() - 1; i > 0; i--) {
                if (nums[i] > nums[i-1]) {
                    break;
                }
            }

            if (i > 0) {
                i--;
                for (j = nums.size() - 1; j >= 0; j--) {
                    if (nums[j] > nums[i]) {
                        break;
                    }
                }

                std::swap(nums[i], nums[j]);
                i++;
            }

            std::reverse(nums.begin() + i, nums.end());
        }
};


int
main(int argc, char **argv)
{
    Solution          ans;
    std::vector<int>  nums;

    nums = { 1, 2, 3 };
    printf("nums:  ");
    PrintVector(nums);
    ans.nextPermutation(nums);
    printf("next:  ");
    PrintVector(nums);

    nums = { 3, 2, 1 };
    printf("nums:  ");
    PrintVector(nums);
    ans.nextPermutation(nums);
    printf("next:  ");
    PrintVector(nums);

    return 0;
}
