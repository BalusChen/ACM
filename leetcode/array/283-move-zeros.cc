#include <vector>
#include <iostream>

class Solution {
    public:
        void moveZeros(std::vector<int> &nums) {
            int hole = -1;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0 && hole < 0) hole = i;
                if (hole >= 0 && nums[i] != 0) nums[hole++] = nums[i];
            }
            if (hole >= 0) {
                for (; hole < nums.size(); hole++)
                    nums[hole] = 0;
            }
        }
};
