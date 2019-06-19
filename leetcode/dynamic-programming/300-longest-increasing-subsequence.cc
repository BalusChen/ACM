
/*
 * Copyright (C) Jianyong Chen
 */

#include <cstdio>
#include <vector>

class Solution
{
    public:
        int lengthOfLIS(std::vector<int> &nums) {
            int  i, max;

            if (nums.size() <= 1) {
                return nums.empty() ? 0 : 1;
            }

            this->nums = &nums;
            this->dp = std::vector<int>(nums.size(), 0);
            this->dp.back() = 1;

            aux(0);

            max = 0;
            for (i = 0; i < dp.size(); i++) {
                if (max < dp[i]) {
                    max = dp[i];
                }
            }

            return max;
        }

        int aux(int beg) {
            int  i, max, next;

            if (dp[beg] != 0) {
                return dp[beg];
            }

            max = 0;
            for (i = dp.size()-1; i > beg; i--) {
                next = aux(i);
                if ((*nums)[i] > (*nums)[beg] && next > max) {
                    max = next;
                }
            }

            dp[beg] = max + 1;
            return dp[beg];
        }

    private:
        std::vector<int>   dp;
        std::vector<int>  *nums;
};

int
main(int argc, char **argv)
{
    Solution          ans;
    std::vector<int>  nums;

    nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
    printf("len: %d\n", ans.lengthOfLIS(nums));

    return 0;
}
