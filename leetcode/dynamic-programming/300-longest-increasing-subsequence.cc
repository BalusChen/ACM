
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

class Solution2
{
    public:
        int lengthOfLIS(std::vector<int> &nums) {

            if (nums.size() < 2) {
                return nums.size();
            }

            int  i, j, next, max_len;
            int  dp[nums.size()];

            dp[nums.size()-1] = 1;
            max_len = 1;
            for (i = nums.size()-2; i >= 0; i--) {
                next = 0;
                for (j = i+1; j < nums.size(); j++) {
                    if (nums[j] > nums[i] && dp[j] > next) {
                        next = dp[j];
                    }
                }

                dp[i] = next + 1;
                if (dp[i] > max_len) {
                    max_len = dp[i];
                }
            }

            return max_len;
        }
};


int
main(int argc, char **argv)
{
    Solution          ans;
    Solution2         ans2;
    std::vector<int>  nums;

    nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
    printf("len: %d\n", ans2.lengthOfLIS(nums));

    return 0;
}
