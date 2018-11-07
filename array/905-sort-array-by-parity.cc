#include <vector>
#include "../include/print.h"

class Solution {
    public:
        std::vector<int> sortArrayByParity(std::vector<int> &A) {
            std::vector<int> ret(A.size());
            int beg = 0, end = A.size()-1;
            for (int i = 0; i < A.size(); i++) {
                if (A[i] % 2 == 0)
                    ret[beg++] = A[i];
                else
                    ret[end--] = A[i];
            }

            return ret;
        }
};
