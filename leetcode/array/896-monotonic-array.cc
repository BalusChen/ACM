#include <vector>
#include <iostream>

class Solution {
    public:
        bool isMonotonic(std::vector<int>& A) {
            bool is_gt = false, is_lt = false;

            if (A.size() <= 2) return true;
            for (int i = 1; i < A.size(); i++) {
                if (A[i] > A[i-1])
                    is_gt = true;
                else if (A[i] < A[i-1])
                    is_lt = true;

                if (is_lt && is_gt)
                    return false;
            }

            return true;
        }
};
