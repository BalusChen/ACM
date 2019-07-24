
/*
 * Copyright (C) Jianyong Chen
 */

#include <vector>
#include <unordered_set>

class Solution {
    public:
        int subarraySum(std::vector<int>& nums, int k) {
            int                           i, sum, count;
            std::unordered_multiset<int>  hash = { 0 };

            sum = 0;
            count = 0;
            for (i = 0; i < nums.size(); i++) {
                sum += nums[i];
                count += hash.count(sum - k);
                hash.insert(sum);
            }

            return count;
        }
};
