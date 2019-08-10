
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>


class Solution {
    public:
        bool Find(int target, std::vector<std::vector<int>> array)
        {
            int lo, hi, mid;
            int val;

            for (int i = 0; i < array.size(); i++) {
                lo = 0;
                hi = array[i].size() - 1;

                while (lo <= hi) {
                    mid = lo + (hi - lo) / 2;
                    val = array[i][mid];

                    if (val < target) {
                        lo = mid + 1;

                    } else if (val > target) {
                        hi = mid - 1;

                    } else {
                        return true;
                    }
                }
            }

            return false;
        }
};
