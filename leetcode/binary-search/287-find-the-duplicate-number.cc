#include <vector>
#include <stdio.h>

class Solution {
    public:
        int findDuplicate(std::vector<int>& nums) {
            int  lo, hi, mid;

            // 首先从小到大排序
            std::sort(nums.begin(), nums.end());

            lo = 0;
            hi = nums.size() - 1;
            while (lo <= hi) {
                mid = lo + (hi - lo) / 2;

                // 索引值为 mid 处的元素应该为 mid+1(如果没有重复的话)
                if (nums[mid] < mid+1) {
                    // 如果 mid 处的元素小于 mid+1
                    // 说明重复元素在[lo .. mid]之间
                    hi = mid - 1;
                } else {
                    // 如果 mid 处的元素等于 mid+1
                    // 说明 [lo .. mid]中没有重复
                    // 所以重复元素必定存在于[mid+1 .. hi]之中
                    lo = mid + 1;
                }
            }

            return nums[hi];
        }
};

int
main(int argc, char **argv)
{
    int               duplicate;
    Solution          solution;
    std::vector<int>  nums;

    nums = { 1, 1, 2, 3, 4, 5, 6, 7 };
    nums = { 1, 2, 3, 4, 5, 6, 7, 7 };
    nums = { 1, 1 };
    nums = { 1, 2, 3, 4, 4, 5, 6, 7 };
    duplicate = solution.findDuplicate(nums);

    printf("duplicate: %d\n", duplicate);
}
