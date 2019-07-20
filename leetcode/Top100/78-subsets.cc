
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <cmath>


class Solution {
    template<typename T>
    using Matrix = std::vector<std::vector<T>>;

    public:
        Matrix<int> subsets(std::vector<int>& nums) {
            int           i, j;
            Matrix<int>   ret(std::pow(2, nums.size()));

            for (i = 0; i < ret.size(); i++) {
                for (j = 0; j < nums.size(); j++) {
                    if ((i >> j) & 1) {
                        ret[i].push_back(nums[j]);
                    }
                }
            }

            return ret;
        }
};
