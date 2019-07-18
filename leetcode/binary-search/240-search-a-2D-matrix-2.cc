
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>

class Solution {
	public:
		bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
			for (auto &v : matrix) {
				if (bsearch(v, target)) {
					return true;
				}
			}

			return false;
		}

		bool bsearch(std::vector<int> &nums, int target) {
			int  lo, hi, mid;

			lo = 0;
			hi = nums.size()-1;
			while (lo <= hi) {
				mid = lo + (hi - lo) / 2;

				if (target < nums[mid]) {
					hi = mid - 1;

				} else if (target > nums[mid]) {
					lo = mid + 1;

				} else {
					return true;
				}
			}

			return false;
		}
};
