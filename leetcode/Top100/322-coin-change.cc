
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <algorithm>

/* ATTENTION: NOT WORK ! */
class Solution {
    public:
        int coinChange(std::vector<int>& coins, int amount) {
            int               i, rest, last;
            std::vector<int>  indices;

            std::sort(coins.begin(), coins.end(), std::greater<int>());

            last = 0;
            rest = amount;
            while (rest != 0) {
                i = findFirstLessOrEqual(coins, last, coins.size()-1, rest);
                printf("last:%d\ti:%d\n", last, i);
                if (i == -1) {
                    /*
                     * backtrack
                     */
                    while (!indices.empty() && indices.back() == coins.size()-1) {
                        indices.pop_back();
                        rest += coins.back();
                    }

                    if (indices.empty()) {
                        return -1;
                    }

                    last = indices.back();
                    indices.pop_back();
                    rest += coins[last];
                    last++; /* 上一个硬币太大了，从下一个位置开始搜索起*/

                } else {
                    rest -= coins[i];
                    indices.push_back(i);

                    last = i;   /* 下一轮还可以从这个硬币开始兑换，所以不是 last = i + 1 */
                }

                for (auto idx : indices) {
                    printf("%d  ", idx);
                }
                printf("\n");
            }

            return indices.size();
        }

        /*
         * 注意 nums 数组是从大到小
         */
        int findFirstLessOrEqual(std::vector<int> &nums, int left, int right, int target) {
            int  lo, hi, mid, last;

            last = -1;
            lo = left;
            hi = right;
            while (lo <= hi) {
                mid = (lo + hi) / 2;

                if (target < nums[mid]) {
                    lo = mid + 1;

                } else {
                    last = mid;
                    hi = mid - 1;
                }
            }

            return last;
        }
};


/* WORKS WELL */
class Solution2 {
    public:
        int coinChange(std::vector<int> &coins, int amount) {
            int               m;
            std::vector<int>  dp(amount+1, amount+1);

            /*
             * dp[i] 为凑成总金额 i 的最小硬币个数
             */
            dp[0] = 0;
            for (m = 1; m <= amount; m++) {
                for (auto coin : coins) {
                    if (coin <= m) {
                        dp[m] = std::min(dp[m], dp[m-coin]+1);
                    }
                }
            }

            return dp[amount] > amount ? -1 : dp[amount];
        }
};


int
main(int argc, char **argv)
{
    int               amount;
    Solution2         ans;
    std::vector<int>  coins;

    coins = { 186, 419, 83, 408 };
    amount = 6249;
    printf("answer: %d\n", ans.coinChange(coins, amount));

    return 0;
}
