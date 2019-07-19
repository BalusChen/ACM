
/*
 * Copyright (C) Jianyong Chen
 */

#include <queue>
#include <deque>


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


/*
 * 第二种解法比较巧妙，使用到了单调队列
 *
 * 首先维护一个队列，队列里面存储的是元素的下标
 * 新元素我们 push_front()，但是从 back 到 front 必须是递减的(递减不是根据索引的大小，而是根据该索引处的值)
 *
 * 为了维护递减性质(准确来说是非递增)，我们在 push_front 之前首先把和 front 比较，如果 front 更大，就需要 pop_front
 * 以此达到非递增的性质
 *
 * 然后如果需要保持队列中的数据不超过一个窗口，如果超出了一个窗口大小，那么我们得把最先加入的(也就是 back)给 pop 掉
 *
 * 最后我们需要获得所需要的解(即每个窗口中的最大元素)，由于从 back 到 front 是非递增的，所以 back 肯定是最大的
 */

class Solution2 {
    public:
        std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
            int               i;
            std::deque<int>   indices;
            std::vector<int>  output;

            for (i = 0; i < nums.size(); i++) {
                while (!indices.empty() && nums[i] > nums[indices.front()]) {
                    indices.pop_front();
                }

                indices.push_front(i);
                if (i - indices.back() >= k) {
                    indices.pop_back();
                }
                if (i >= k-1) {
                    output.push_back(nums[indices.back()]);
                }
#if 0
                /* debug */
                for (auto c : indices) {
                    printf("%d  ", c);
                }
                printf("\n");
#endif
            }

            return output;
        }
};
