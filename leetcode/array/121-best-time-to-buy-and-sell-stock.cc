
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>


class Solution {
    public:
        int maxProfit(std::vector<int>& prices) {

            if (prices.size() < 2) {
                return 0;
            }

            std::vector<int> diff(prices.size() - 1);

            for (int i = 1; i < prices.size(); ++i) {
                diff[i-1] = prices[i] - prices[i-1];
            }

            return maxSubArray(diff);
        }

    private:
        int maxSubArray(const std::vector<int> &ivec) {
            int this_sum, max_sum;

            this_sum = 0;
            max_sum = 0;
            for (int i = 0; i < ivec.size(); ++i) {
                this_sum += ivec[i];

                if (this_sum > max_sum) {
                    max_sum = this_sum;

                } else if (this_sum < 0) {
                    this_sum = 0;
                }
            }

            return max_sum;
        }
};
