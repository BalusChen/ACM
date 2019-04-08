#include <vector>

class Solution {
public:
    int Fibonacci(int n) {
        if (n < 2) {
            return n;
        }

        dp = std::vector<int>(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;

        return aux(n);
    }

    int aux(int n) {
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    std::vector<int> dp;
};
