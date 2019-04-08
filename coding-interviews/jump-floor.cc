#include <vector>

class Solution {
public:
    int jumpFloor(int number) {
        if (number == 0) {
            return 0;
        }

        dp.resize(number+1, -1);
        dp[0] = 1;
        dp[1] = 1;

        aux(number);

        return dp[number];
    }

    int aux(int n) {
        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] =  aux(n-1)+aux(n-2);

        return dp[n];
    }

    std::vector<int>  dp;
};
