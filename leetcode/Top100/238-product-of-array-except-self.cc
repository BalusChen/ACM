
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>

class Solution {
    public:
        std::vector<int> productExceptSelf(std::vector<int>& nums) {
            int               i, product;
            std::vector<int>  output(nums.size());

            /*
             * product of the left part of nums[i];
             */
            product = 1;
            for (i = 0; i < nums.size(); i++) {
                output[i] = product;
                product *= nums[i];
            }

            /*
             * product the right part of nums[i] and get the final answer
             */
            product = 1;
            for (i = nums.size()-1; i >= 0; i--) {
                output[i] *= product;
                product *= nums[i];
            }

            return output;
        }
};
