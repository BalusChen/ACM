#include <vector>


class Solution {
    public:
        int singleNumber(std::vector<int> &nums) {
            int  ret;

            ret = 0;
            for (auto c : nums) {
                ret ^= c;
            }

            return ret;
        }
};
