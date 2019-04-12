#include <vector>
#include <stdio.h>

class Solution {
    public:
        std::vector<int> searchRange(std::vector<int>& nums, int target) {
            std::vector<int>  range(2, 0);
            int               s, e;
            int               lo, hi, mid;

            s = e = -1;

            // 找出第一次出现
            lo = 0;
            hi = nums.size() - 1;
            while (lo <= hi) {
                mid = lo + (hi - lo) / 2;

                if (nums[mid] < target) {
                    lo = mid + 1;

                } else if (nums[mid] > target) {
                    hi = mid - 1;

                } else {
                    s = mid;
                    hi = mid - 1;
                }
            }

            // 找出最后一个 <= target的下标值
            lo = 0;
            hi = nums.size() - 1;
            while (lo <= hi) {
                mid = lo + (hi - lo) / 2;
                printf("lo: %d\thi: %d\tmid: %d\n", lo, hi, mid);

                if (nums[mid] < target) {
                    lo = mid + 1;

                } else if (nums[mid] > target) {
                    hi = mid - 1;

                } else {
                    e = mid;
                    lo = mid + 1;
                }
            }

            range[0] = s;
            range[1] = e;

            return range;
        }
};

int
main(int argc, char **argv)
{
    std::vector<int>  nums, range;
    Solution          solution;

    nums = { 5, 7, 7, 8, 8, 10 };

    nums = { 1 };

    nums = { 2, 2 };

    range = solution.searchRange(nums, 2);

    printf("start: %d\tend: %d\n", range[0], range[1]);
}
