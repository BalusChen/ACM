
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>


class Solution
{
    public:
        int maxProfit(std::vector<int> &prices) {
            int               i;
            std::vector<int>  buy, sell;

            if (prices.size() < 2) {
                return 0;
            }

            buy.resize(prices.size());
            sell.resize(prices.size());
            buy[0] = -prices[0];
            sell[0] = 0;
            for (i = 1; i < prices.size(); i++) {
                sell[i] = std::max(sell[i-1], buy[i-1] + prices[i]);
                buy[i] = std::max(buy[i-1], (i >= 2 ? sell[i-2] : 0) - prices[i]);
            }

            return sell.back();
        }
};
