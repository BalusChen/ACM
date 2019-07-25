
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <numeric>


class Solution {
    public:
        bool canPatition(std::vector<int> &nums) {
            int  sum;
            std::vector<int>  buckets;

            if (nums.size() < 2) {
                return false;
            }

            sum = std::accumulate(nums.begin(), nums.end(), 0);
            if (sum % 2 != 0) {
                return false;
            }

            sum /= 2;
            buckets.resize(2, sum);
            std::sort(nums.begin(), nums.end());

            return dfs(nums.size()-1, nums, buckets);
        }

        bool dfs(int idx, std::vector<int> &nums, std::vector<int> &buckets) {
            int  i;

            if (idx < 0) {
                return true;
            }

            for (i = 0; i < 2; i++) {
                if (buckets[i] == nums[idx]
                    || (idx > 0
                        && (buckets[i] - nums[idx] >= nums[0])))
                {
                    buckets[i] -= nums[idx];

                    if (dfs(idx-1, nums, buckets)) {
                        return true;
                    }

                    buckets[i] += nums[idx];
                }
            }

            return false;
        }
};
