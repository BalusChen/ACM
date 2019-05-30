#include <vector>

class NumArray {
    public:
        NumArray(std::vector<int>& nums) {
            this->nums = nums;
        }

        int sumRange(int i, int j) {
            int  k, sum;

            sum = 0;
            for (k = i; k <= j; k++) {
                sum += nums[k];
            }

            return sum;
        }

    private:
        std::vector<int>  nums;
};
