
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <numeric>

/*
 * +, - sign divide the array into two parts: positive part(P) and negative part(N)
 *
 * sum(P) - sum(N) = S
 * sum(P) + sum(N) = sum(nums)
 * ==> sum(P) = (sum(nums) + S) / 2
 *
 * thus the problem changes: to find the number of combinations
 * which sum to `(sum(nums) + S) / 2` in `nums`
 *
 * hint: since sum(P) is an integer, (sum(nums) + S) must be an even number
 */

class Solution
{
    public:
        int findTargetSumWays(std::vector<int> &nums, int S) {
            int               i, v, sum, target;
            std::vector<int>  dp;

            sum = std::accumulate(nums.begin(), nums.end(), 0);
            if (sum < S || (sum + S) % 2) {
                return 0;
            }

            target = (sum + S) / 2;
            dp.resize(target+1, 0);

            /*
             * dp[i]: the number of combinations which sum to `i`
             */

            dp[0] = 1;
            for (i = 0; i < nums.size(); i++) {
                for (v = target; v >= nums[i]; v--) {
                    dp[v] += dp[v-nums[i]];
                }
            }

            return dp.back();
        }
};
