#include <vector>
#include <iostream>

class Solution {
    public:
        int findLengthOfLCIS(std::vector<int> &nums) {
            int next = 1;
            int len = 1;
            int max = 0;

            if (nums.size() < 2)
                return nums.size();

            for ( ; next != nums.size(); next++) {
                if (nums[next] > nums[next-1])
                    ++len;
                else {
                    max = (len > max) ? len : max;
                    len = 1;
                }
            }

            // 如果LCIS(longest continuous increasing subsequence)在数组的末尾
            // 则返回的应该是len
            return std::max(len, max);
        }
};
