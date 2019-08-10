
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>


class Solution {
	public:
		int rectCover(int number) {
			int               i;
			std::vector<int>  dp(number+1, 0);

			if (number < 3) {
				return number < 0 ? 0 : number;

			}

			dp[0] = 0;
			dp[1] = 1;
			dp[2] = 2;
			for (i = 3; i <= number; i++) {
				dp[i] = dp[i-2] + dp[i-1];

			}

			return dp[number];
		}
};

