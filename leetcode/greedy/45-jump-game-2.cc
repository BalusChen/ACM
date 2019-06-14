
/*
 * Copyright (C) Jianyong Chen
 */

#include <cstdio>
#include <vector>


class Solution
{
    public:
        int jump(std::vector<int> &nums) {
            int  j, idx, dst, jumps;

            if (nums.size() <= 1) {
                return 0;
            }

            jumps = 1;
            dst = nums.size()-1;
            idx = nums.size()-1;
            for ( ;; ) {

                for (j = dst-1; j >= 0; j--) {
                    if (nums[j] >= (dst - j)) {
                        idx = j;
                    }
                }

                if (idx == 0) {
                    break;
                }

                dst = idx;
                jumps++;
            }

            return jumps;
        }

        int jump2(std::vector<int> &nums) {
            int  i, cur_max, pre_max, jumps;

            if (nums.size() <= 1) {
                return 0;
            }

            cur_max = nums[0];
            pre_max = nums[0];
            jumps = 1;
            for (i = 0; i < nums.size(); i++) {

                /*
                 * cur_max 表示从数组开头经过当前 jumps 步能到达的最远位置
                 * pre_max 表示当前位置前每个位置所能跳跃到的最大位置的最大值
                 *
                 * cur_max < i，说明从数组开头经 jumps 步到达不了这个位置
                 * 所以中间必须还需要一次跳跃，
                 *
                 * nums[i]+i: 表示从位置 i 处能到达的最远位置
                 * pre_max < nums[i]+i: 说明
                 */

                if (cur_max < i) {
                    cur_max = pre_max;
                    jumps++;
                }

                if (pre_max < nums[i]+i) {
                    pre_max = nums[i] + i;
                }
            }

            return jumps;
        }
};


int
main(int argc, char **argv)
{
    Solution          ans;
    std::vector<int>  nums;

    nums = { 2, 3, 1, 1, 4 };
    printf("min jumps: %d\n", ans.jump2(nums));

    nums = { 2, 2, 1, 1, 4 };
    printf("min jumps: %d\n", ans.jump2(nums));

    nums = { 1, 1, 1, 1, 1 };
    printf("min jumps: %d\n", ans.jump2(nums));

    nums = { 7, 4, 1, 2, 3 };
    printf("min jumps: %d\n", ans.jump2(nums));

    exit(0);
}
