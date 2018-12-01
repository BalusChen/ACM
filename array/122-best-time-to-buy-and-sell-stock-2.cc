#include <vector>
#include <iostream>
#include <stdio.h>

class Solution {
    public:
        int maxProfit(std::vector<int> &prices) {
            int profit = 0;
            int buy, i;

            if (prices.size() < 2)
                return 0;
            buy  = 0;

            for (i = 1; i < prices.size(); i++) {
                if (prices[i] < prices[i-1]) {
                    profit += (prices[i-1] - prices[buy]);
                    buy = i;
                }
            }

            if (i == prices.size())
                profit += (prices[i-1] - prices[buy]);

            return profit;
        }
};
