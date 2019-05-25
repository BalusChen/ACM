#include <vector>

class Solution {
    public:
        int rob(std::vector<int>& nums) {
            int               i;
            std::vector<int>  dp(nums.size());

            if (nums.size() < 2) {
                return nums.size() == 1 ? nums[0] : 0;
            }

            dp[0] = nums[0];
            dp[1] = std::max(nums[0], nums[1]);
            for (i = 2; i < dp.size(); i++) {
                dp[i] = std::max(dp[i-1], nums[i] + dp[i-2]);
            }

            return *(std::end(dp)-1);
        }
};



int
main(int argc, char **argv)
{
    int               ans;
    Solution          solution;
    std::vector<int>  nums;

    nums = { 1, 2, 3, 1 };
    nums = { 2, 7, 9, 3, 1 };
    nums = { 1, 3, 1 };
    nums = { 4, 1, 2, 7, 5, 3, 1 };
    ans = solution.rob(nums);

    printf("ans = %d\n", ans);
}
