
/*
 * Copyright (C) Jianyong Chen
 */

#include <cstdio>
#include <vector>
#include <numeric>


class Solution
{
    public:
        bool canPartitionKSubsets(std::vector<int> &nums, int k) {
            int  sum;

            sum = std::accumulate(nums.begin(), nums.end(), 0);
            if (sum % k != 0) {
                return false;
            }

            std::sort(nums.begin(), nums.end());
            if (nums.back() > sum) {
                return false;
            }

            this->k = k;
            this->sum_of_per_subset = sum / k;
            this->nums = &nums;
            this->buckets.resize(k, sum_of_per_subset);

            if (nums.back() > sum_of_per_subset) {
                return false;
            }

            return dfs(nums.size()-1);
        }

        bool dfs(int idx) {
            int  i;

            if (idx < 0) {
                return true;
            }

            for (i = 0; i < k; i++) {

                /*
                 * 如果：
                 *      1. 恰好能放下当前的数
                 *      2. 放下了还有多，并且可以前面还有数放到这个桶里面去(idx > 0)
                 * 那么：
                 *      1. 首先将该数放到每个桶中都放一遍。对于每个桶，放完一遍后
                 *         就递归调用本函数放下一个数，如果可以放，那么返回 true。
                 *         如果放的不行，那么就把它取出来，尝试着放入下一个桶中
                 *      2. 当所有的数字都放完了，也就是 idx < 0 时(我们是从后往前放) 时，
                 *         说明问题有解
                 */

                if (buckets[i] == (*nums)[idx]
                    || (idx > 0 && (buckets[i] - (*nums)[idx] >= nums->front())))
                {
                    buckets[i] -= (*nums)[idx];

                    if (dfs(idx-1)) {
                        return true;
                    }

                    buckets[i] += (*nums)[idx];
                }
            }

            return false;
        }

    private:
        int  k, sum_of_per_subset;
        std::vector<int>  *nums;
        std::vector<int>   buckets;
};



int
main(int argc, char **argv)
{
    int               k;
    Solution          ans;
    std::vector<int>  nums;


    nums = { 4, 3, 2, 3, 5, 2, 1 };
    k = 4;
    printf("can: %d\n", ans.canPartitionKSubsets(nums, k));

    nums = { 2, 2, 2, 2, 3, 4, 5 };
    k = 4;
    printf("can: %d\n", ans.canPartitionKSubsets(nums, k));

    exit(0);
}
