
/*
 * Copyright (C) Jianyong Chen
 */

#include <cstdio>
#include <vector>

/*
 * slowly
 */

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


/*
 * fast
 */

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

                /*
                 * dp[i] 存放的是从 i 到 nums.size()-1 的 LIS 的长度
                 * 如何得到 dp[i] 呢？nums[i] 只能和后面比它大的组成 IS
                 * 要想找到 LIS，则必须和 nums[i] 后面的最大的 LIS 组成更长的 LIS
                 *
                 * 一开始 nums.back() 的 dp 值为 1，然后从后往前推
                 */

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


/*
 * medium
 */

class Solution3
{
    public:
        int lengthOfLIS(std::vector<int> &nums) {
            if (nums.size() < 2) {
                return nums.size();
            }

            int               i, j, max_len;
            std::vector<int>  dp(nums.size(), 1);

            for (i = 1; i < nums.size(); i++) {
                for (j = 0; j < i; j++) {
                    if (nums[i] > nums[j]) {
                        dp[i] = std::max(dp[i], dp[j]+1);
                    }
                }
            }

            max_len = 1;
            for (i = 0; i < nums.size(); i++) {
                if (dp[i] > max_len) {
                    max_len = dp[i];
                }
            }

            return max_len;
        }
};


class Solution4
{
    public:
        int lengthOfLIS(std::vector<int> &nums) {
            if (nums.size() < 2) {
                return nums.size();
            }

            int               i, left, right, middle, target;
            std::vector<int>  tail;
            for (i = 0; i < nums.size(); i++) {
                target = nums[i];
                left = 0;
                right = tail.size();

                /*
                 * 找到第一个 >= target 的下标
                 */
                while (left < right) {
                    middle = left + (right - left) / 2;

                    if (tail[middle] < target) {

                        /*
                         * 由于需要的是 >= target 的，所以小于的都不要(包括 middle)
                         */
                        left = middle + 1;

                    } else {
                        right = middle;
                    }
                }

                if (right == tail.size()) {
                    tail.push_back(target);

                } else {
                    tail[right] = target;
                }
            }

            return tail.size();
        }
};

int
main(int argc, char **argv)
{
    Solution          ans;
    Solution2         ans2;
    Solution3         ans3;
    Solution4         ans4;
    std::vector<int>  nums;

    nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
    printf("len: %d\n", ans4.lengthOfLIS(nums));

    return 0;
}
