#include <stdio.h>
#include <vector>

class Solution {
public:
    int jumpFloorII(int number) {
        dp.resize(number+1, -1);

        dp[0] = 1;
        dp[1] = 1;

        aux(number);

        return dp[number];
    }

    int aux(int n) {
        int sum;

        if (dp[n] != -1) {
            return dp[n];
        }

        sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += aux(n-i);
        }

        dp[n] = sum;

        return dp[n];
    }

    std::vector<int>  dp;
};
