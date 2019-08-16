
/*
 * Copyright (C) Jianyong Chen
 */


#include <cstdio>
#include <vector>


class Solution
{
    public:
        int climbStairs(int n) {
            dp.resize(n+1, -1);

            return aux(n);
        }


        void showDP() const {
            for (auto c : dp) {
                printf("%d  ", c);
            }

            printf("\n");
        }

    private:

        int aux(int i) {
            if (dp[i] != -1) {
                return dp[i];
            }

            if (i == 1 || i == 2) {
                dp[i] = (i == 1) ? 1 : 2;
                return dp[i];
            }

            dp[i] = aux(i-1) + aux(i-2);

            return dp[i];
        }

        std::vector<int>  dp;
};


class Solution2 {
    public:
        int climbStairs(int n) {
            std::vector<int> dp(n+1);
            int sum = 0;

            dp[0] = 1;
            dp[1] = 1;
            for (std::size_t i = 2; i <= n; ++i) {
                sum = dp[0] + dp[1];
                dp[(i-1) % 2] = sum;
            }

            return dp[(n-1) % 2];
        }
};


int
main(int argc, char **argv)
{
    int        nstairs;
    Solution   ans;
    Solution2  ans2;

    nstairs = 2;
    printf("sum(2): %d\n", ans.climbStairs(nstairs));

    nstairs = 3;
    printf("sum(3): %d\n", ans.climbStairs(nstairs));

    nstairs = 7;
    printf("sum(7): %d\n", ans2.climbStairs(nstairs));

    return 0;
}
