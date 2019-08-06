
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <stack>


class Solution
{
    public:
        int findUnsortedSubarray(std::vector<int>& nums) {
            int              i, idx, start_idx, end_idx, prev_max;
            std::stack<int>  stk;

            if (nums.empty()) {
                return 0;
            }

            prev_max = INT_MIN;
            start_idx = INT_MAX;
            for (i = 0; i < nums.size(); i++) {

                if (stk.empty() || nums[i] >= prev_max) {
                    prev_max = nums[i];
                    stk.push(i);

                } else {
                    end_idx = i;

                    while (!stk.empty() && nums[i] < nums[stk.top()]) {
                        idx = stk.top();
                        if (idx < start_idx) {
                            start_idx = idx;
                        }

                        stk.pop();
                    }

                    stk.push(i);
                }
            }

            return start_idx == INT_MAX ? 0 : end_idx - start_idx + 1;
        }

        int findUnsortedSubarray2(std::vector<int>& nums) {
            int  i, j, max_seen, min_seen, left, right;

            max_seen = INT_MIN;
            min_seen = INT_MAX;
            left = 0;
            right = 0;
            for (i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
                max_seen = std::max(max_seen, nums[i]);
                if (max_seen > nums[i]) {
                    right = i;
                }

                min_seen = std::min(min_seen, nums[j]);
                if (min_seen < nums[j]) {
                    left = j;
                }
            }

            return left == right ? 0 : right - left + 1;
        }
};
