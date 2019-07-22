
/*
 * Copyright (C) Jianyong Chen
 */

#include <vector>
#include <cstdio>

template<typename T>
using Matrix = std::vector<std::vector<T>>;

static void PrintArray(std::vector<int> nums) {
    for (auto c : nums) {
        printf("%d  ", c);
    }

    printf("\n");
}

class Solution {
    public:
        /*
         * tail_max[i] 表示以 nums[i] 结尾的子数组的最大乘积
         * tail_min[i] 表示以 nums[i] 结尾的子数组的最小乘积
         *
         * 当 nums[i] 为负数时，则 nums[i] 需要和 tail_min[i-1] 相乘才有可能得到最大乘积
         * 当 nums[i] 为正数时，则 nums[i] 需要和 tail_max[i-1] 相乘才有可能得到最大乘积
         */

        int maxProduct(std::vector<int>& nums) {
            int               i, max_product;
            std::vector<int>  tail_min, tail_max;

            tail_max.resize(nums.size());
            tail_min.resize(nums.size());
            tail_max[0] = nums[0];
            tail_min[0] = nums[0];
            max_product = nums[0];

            for (i = 1; i < nums.size(); i++) {
                printf("nums[%d] = %d\n", i, nums[i]);

                if (nums[i] > 0) {
                    tail_max[i] = std::max(tail_max[i-1] * nums[i], nums[i]);
                    tail_min[i] = std::min(tail_min[i-1] * nums[i], nums[i]);

                } else {
                    tail_max[i] = std::max(tail_min[i-1] * nums[i], nums[i]);
                    tail_min[i] = std::min(tail_max[i-1] * nums[i], nums[i]);
                }

                max_product = std::max(max_product, tail_max[i]);
            }

#if 0
            PrintArray(tail_max);
            PrintArray(tail_min);
#endif

            return max_product;
        }
};


int
main(int argc, char **argv)
{
    int               max_product;
    Solution          ans;
    std::vector<int>  nums;

    nums = { 2, 3, -2, 4 };
    max_product = ans.maxProduct(nums);
    printf("max product: %d\n", max_product);

    nums = { -2, 0, -1 };
    max_product = ans.maxProduct(nums);
    printf("max product: %d\n", max_product);

    nums = { -3, -4 };
    max_product = ans.maxProduct(nums);
    printf("max product: %d\n", max_product);

    return 0;
}
