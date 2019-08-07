
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <cmath>


class Solution
{
    public:
        int numSquares(int n) {
            int               i,  sqrt;
            std::vector<int>  squares, dp(n+1, n+1);

            if (n < 0) {
                return 0;
            }

            sqrt = std::sqrt(n);
            squares.resize(sqrt);
            for (i = 1; i <= sqrt; i++) {
                squares[i-1] = std::pow(i, 2);
            }

            /*
             * the same as leetcode-322 coin change
             */

            dp[0] = 0;
            for (i = 1; i <= n; i++) {
                for (auto s : squares) {
                    if (s <= i) {
                        dp[i] = std::min(dp[i], dp[i-s]+1);
                    }
                }
            }

            return dp[n];
        }
};
