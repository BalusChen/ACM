#include <vector>
#include <iostream>

class Solution {
    public:
        int findMaxConsecutiveOnes(std::vector<int> &nums) {
            int max = 0;
            int part = 0;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 1) {
                    part++;
                    if (part > max) max = part;
                } else {
                    part = 0;
                }
            }

            return max;
        }
};
