
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <cmath>
#include <numeric>


class Solution {
    public:
        int countNumbersWithUniqueDigits(int n) {
            int  i, count;

            if (n < 2) {
                return std::pow(10, n);
            }

            /*
             * if `n` == 0; then 1 is the only only in [0, 2^0],
             * and it has been calculated in previous `if` statement
             *
             * if `n` > 0; then 1 can be in dp[0] and dp[1];
             * so it will be an error if we do not handle this case.
             * to avoid calculate twice, we simply set dp[0] = 0;
             */

            count = 10;
            for (i = 2; i <= n; i++) {
                count += countUniqueOfLengthK(i);
            }

            return count;
        }

        int countUniqueOfLengthK(int k) {
            int  count, i;

            /* k >= 2 */
            count = 9;
            for (i = 2; i <= k; i++) {
                count *= (9 - i + 2);
            }

            return count;
        }
};
