
/*
 * Copyright (C) Jianyong Chen
 */

#include <vector>


class Solution {
    template<typename T>
        using Matrix = std::vector<std::vector<T>>;

    public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int               i, j, k, sum;
        Matrix<int>       ans;

        if (nums.size() < 3) {
            return ans;
        }

        std::sort(nums.begin(), nums.end());

        for (i = 0; i < nums.size()-2; i++) {

            /* ATTENTION */
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }

            j = i+1;
            k = nums.size()-1;

            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    ++j;

                } else if (sum > 0) {
                    --k;

                } else {

                    ans.emplace_back(std::vector<int>{ nums[i], nums[j], nums[k] });

                    /* ATTENTION */
                    while (j < k && nums[j+1] == nums[j]) {
                        ++j;
                    }
                    while (j < k && nums[k-1] == nums[k]) {
                        --k;
                    }

                    ++j;
                    --k;
                }
            }
        }

        return ans;
    }

};
