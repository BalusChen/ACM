#include <vector>

class Solution {
    public:
        int arrayPairSum(std::vector<int> &sum) {
            int ret = 0;

            std::sort(sum.begin(), sum.end());
            for (int i = 0; i < sum.size(); i += 2) {
                ret += sum[i];
            }

            return ret;
        }
};
