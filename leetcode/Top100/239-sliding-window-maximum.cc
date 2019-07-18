
/*
 * Copyright (C) Jianyong Chen
 */

#include <queue>


class Solution {
    public:
        std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
            int               i;
            std::vector<int>  output(nums.size()-k+1);

            if (nums.empty()) {
                return std::vector<int>();
            }

            auto it = nums.begin();
            for (i = 0; i < output.size(); i++) {
                std::priority_queue<int>  pq(it+i, it+i+k);
                output[i] = pq.top();
            }

            return output;
        }
};
