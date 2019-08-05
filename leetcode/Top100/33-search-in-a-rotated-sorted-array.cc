
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>


class Solution {
    public:
        int search(std::vector<int>& nums, int target) {
            int  i;

            for (i = 0; i < nums.size(); i++) {
                if (nums[i] == target) {
                    return i;
                }
            }

            return -1;
        }
};

class Solution2 {
    public:
        int search(std::vector<int> &nums, int target) {
            int  left, right, middle;

            left = 0;
            right = nums.size()-1;
            while (left <= right) {
                middle = (left + right) / 2;
                printf("left:%d, right:%d middle:%d\n", left, right, middle);

                if (target < nums[middle]) {

                    if (nums[right] < nums[left]) {

                        /*
                         *  1. [middle] 太大，所以得往小的地方找
                         *  2. [left, right] 之间不是有序的，中间 rotate 了
                         *          1. [left] < [middle]，说明 rotate 的点在 [middle, right]
                         *             所以 [left, middle-1] 和 [middle+1, right] 都是需要考虑的
                         *             但是这两部分也是有相对大小的，[left, middle-1] > [middle+1, right]
                         *             如果 [left] > target，那么只能在 [middle+1, right] 里面找，所以 left = middle + 1;
                         *             否则只能在 [left, middle-1] 找，所以 right = middle -1;
                         *          2. [left] == [middle]，由于不包含重复元素，所以就是 left == middle
                         *             那么说明 rotate 的点就是 left/middle，所以需要在 [middle+1, right]找，
                         *             也就是 left = middle+1
                         *          3. [middle] < [left]，说明 rotate 的点在 [left, middle]，而 [middle, right] 是递增的
                         *             比 [middle] 小的，只能出现在 [left+1, middle-1] 里面，所以 left++; right = middle - 1;
                         */

                        if (nums[left] < nums[middle]) {

                            if (target < nums[left]) {
                                left = middle + 1;

                            } else {
                                right = middle - 1;
                            }

                        } else if (nums[middle] == nums[left])  {
                            left = middle + 1;

                        } else {    /* nums[middle] < nums[left] */
                            left++;
                            right = middle - 1;
                        }

                    } else {
                        right = middle - 1;
                    }

                } else if (nums[middle] < target) {

                    if (nums[right] < nums[left]) {

                        /*
                         *  1. [middle] 过小，需要往大的地方找
                         *  2. [left, right] 之间有地方 rotate 了
                         *      1. [left] < [middle]，说明 [left, middle] 是有序的，所以只能在[middle+1, right] 之间找
                         *         也就是 left = middle + 1;
                         *      2. [left] == [middle],也就是 left == middle，只能在[middle+1, right] 之间找，
                         *         也就是 left = middle + 1;
                         *      3. [middle] < [left]，说明转折点在 [left, middle]，那么此时 [middle, left-1] 和
                         *         [middle + 1, right] 之间都有可能找到，但是这两部分是有相对大小的 [middle, left-1]
                         *
                         */

                        if (nums[left] < nums[middle]) {
                            left = middle + 1;

                        } else {

                            if (nums[right] < target) {
                                right = middle - 1;

                            } else {
                                left = middle + 1;
                            }
                        }

                    } else {
                        left = middle + 1;
                    }

                } else {
                    return middle;
                }
            }

            return -1;
        }
};
