#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
    public:
        int pivotIndex(std::vector<int> &nums) {
            int sum = std::accumulate(nums.begin(), nums.end(), 0);
            int res = sum;
            int index = 0;
            
            for ( ; index < nums.size(); index++) {
                res -= nums[index];
                if (2*res == sum-nums[index])
                    return index;
            }

            return -1;
        }
};
