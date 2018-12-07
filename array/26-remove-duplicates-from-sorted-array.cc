#include <vector>
#include <stdio.h>

class Solution {
    public:
        int removeDuplicates2(std::vector<int> &nums) {
            auto duplicate_begin = std::unique(nums.begin(), nums.end());
            return duplicate_begin-nums.begin();
        }

        int removeDuplicates(std::vector<int> &nums) {
            int hole = 1;
            int save;
            int count = 0;

            if (nums.size() < 2)
                return nums.size();
            save = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == save) {
                    ++count;
                } else {
                    save = nums[i];
                    nums[hole] = nums[i];
                    ++hole;
                }
            }

            return nums.size()-count;
        }
};
