
/*
 * Copyright (C) Jianyong Chen
 */

#include <vector>
#include <unordered_set>

class Solution {
    public:
        int longestConsecutive(std::vector<int>& nums) {
            int  prev, max_len, cur_len, i;

            if (nums.size() < 2) {
                return nums.size();
            }

            std::sort(nums.begin(), nums.end());

            prev = nums[0];
            cur_len = 1;
            max_len = 0;
            for (i = 1; i < nums.size(); i++) {
                if (prev == nums[i]) {
                    continue;
                }

                if (prev + 1 == nums[i]) {
                    prev = nums[i];
                    cur_len++;

                } else {
                    max_len = std::max(cur_len, max_len);
                    prev = nums[i];
                    cur_len = 1;
                }

            }

            return std::max(cur_len, max_len);
        }
};

class Solution2 {
    int longestConsecutive(std::vector<int>& nums) {
        int                      cur_len, max_len, cur_num;
        std::unordered_set<int>  uiset;

        for (auto c : nums) {
            uiset.insert(c);
        }

        max_len = 0;
        for (auto num : uiset) {
            cur_num = num;
            cur_len = 1;

            while (uiset.find(cur_num+1) != uiset.end()) {
                cur_len++;
                cur_num++;
            }

            max_len = std::max(cur_len, max_len);
        }

        return max_len;
    }
};
